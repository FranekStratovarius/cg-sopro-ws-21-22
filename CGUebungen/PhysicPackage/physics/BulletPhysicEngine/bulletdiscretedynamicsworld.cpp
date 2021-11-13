#include <QtConcurrent>

#include "bulletdiscretedynamicsworld.h"
#include "../collisionpointinfo.h"
#include "bulletparallelcollisioncallback.h"
#include "bulletphysicengine.h"
#include <QThread>

BulletDiscreteDynamicsWorld::BulletDiscreteDynamicsWorld(BulletPhysicEngine* a_PhysicEngine,btDispatcher *dispatcher, btBroadphaseInterface *pairCache, btConstraintSolver *constraintSolver, btCollisionConfiguration *collisionConfiguration)
    :btDiscreteDynamicsWorld(dispatcher,pairCache,constraintSolver,collisionConfiguration)
{
    m_PhysicEngine=a_PhysicEngine;
#ifndef USE_SINGLETHREAD
    m_NumberOfThreads=QThread::idealThreadCount();
    if(m_NumberOfThreads<1)
    {
        m_NumberOfThreads=1;
    }
#else
    m_NumberOfThreads=1;
#endif
    m_ThreadPool.setMaxThreadCount(m_NumberOfThreads);
    m_NumOfManifolds=0;
    for(int i=0;i<m_NumberOfThreads;i++)
    {
        m_CallbackThreads.append(new BulletParallelCollisionCallback(m_dispatcher1,&m_NumOfManifolds,m_NumberOfThreads,i));
    }
}

BulletDiscreteDynamicsWorld::~BulletDiscreteDynamicsWorld()
{
    for(int i=0;i<m_CallbackThreads.size();i++)
    {
        delete m_CallbackThreads[i];
    }
    m_CallbackThreads.clear();
}

void BulletDiscreteDynamicsWorld::internalSingleStepSimulation(btScalar timeStep)
{
    QVector<QFuture<void>> lFuture;
    btDiscreteDynamicsWorld::internalSingleStepSimulation(timeStep);
    m_NumOfManifolds=m_dispatcher1->getNumManifolds();

    for(int i=0;i<m_NumberOfThreads;i++)
    {
        //Different parameter API since Qt 6
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
        lFuture.append(QtConcurrent::run(&m_ThreadPool, m_CallbackThreads.at(i), &BulletParallelCollisionCallback::run));
#else
        lFuture.append(QtConcurrent::run(&m_ThreadPool, &BulletParallelCollisionCallback::run, m_CallbackThreads.at(i)));
#endif
    }
    for(int i=0;i<m_NumberOfThreads;i++)
        lFuture[i].waitForFinished();
    m_PhysicEngine->updateMatrix();
    m_PhysicEngine->setTicked();
}
