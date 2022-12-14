# Avoid conflicts between MSVC and BT defines
win32 {
    QMAKE_CXXFLAGS += -D__BT_SKIP_UINT64_H
}

INCLUDEPATH+= $$PWD/BulletPhysics \
    $$PWD/physics

SOURCES += \
    $$PWD/physics/boundingbox.cpp \
    $$PWD/physics/boundingsphere.cpp \
    $$PWD/physics/dynamiccharacter.cpp \
    $$PWD/physics/dynamiccharacterwithcam.cpp \
    $$PWD/physics/physicengine.cpp \
    $$PWD/physics/physicenginemanager.cpp \
    $$PWD/physics/physicobject.cpp \
    $$PWD/physics/trigger.cpp \
    $$PWD/physics/PhysicMath/eigenvector.cpp \
    $$PWD/physics/BulletPhysicEngine/bulletcollisiondispatcher.cpp \
    $$PWD/physics/BulletPhysicEngine/bulletdebugdrawer.cpp \
    $$PWD/physics/BulletPhysicEngine/bulletdiscretedynamicsworld.cpp \
    $$PWD/physics/BulletPhysicEngine/bulletdynamiccharacter.cpp \
    $$PWD/physics/BulletPhysicEngine/bulletdynamiccharacterwithcam.cpp \
    $$PWD/physics/BulletPhysicEngine/bulletparallelcollisioncallback.cpp \
    $$PWD/physics/BulletPhysicEngine/bulletphysicengine.cpp \
    $$PWD/physics/BulletPhysicEngine/bulletphysicmatrixtogeometry.cpp \
    $$PWD/physics/BulletPhysicEngine/bulletphysicobject.cpp \
    $$PWD/physics/BulletPhysicEngine/bulletspucollisiondispatcher.cpp

SOURCES += $$PWD/BulletPhysics/BulletCollision/BroadphaseCollision/btAxisSweep3.cpp \
    $$PWD/BulletPhysics/BulletCollision/BroadphaseCollision/btBroadphaseProxy.cpp \
    $$PWD/BulletPhysics/BulletCollision/BroadphaseCollision/btCollisionAlgorithm.cpp \
    $$PWD/BulletPhysics/BulletCollision/BroadphaseCollision/btDbvt.cpp \
    $$PWD/BulletPhysics/BulletCollision/BroadphaseCollision/btDbvtBroadphase.cpp \
    $$PWD/BulletPhysics/BulletCollision/BroadphaseCollision/btDispatcher.cpp \
    $$PWD/BulletPhysics/BulletCollision/BroadphaseCollision/btMultiSapBroadphase.cpp \
    $$PWD/BulletPhysics/BulletCollision/BroadphaseCollision/btOverlappingPairCache.cpp \
    $$PWD/BulletPhysics/BulletCollision/BroadphaseCollision/btQuantizedBvh.cpp \
    $$PWD/BulletPhysics/BulletCollision/BroadphaseCollision/btSimpleBroadphase.cpp \
    $$PWD/BulletPhysics/BulletCollision/CollisionDispatch/btActivatingCollisionAlgorithm.cpp \
    $$PWD/BulletPhysics/BulletCollision/CollisionDispatch/btBox2dBox2dCollisionAlgorithm.cpp \
    $$PWD/BulletPhysics/BulletCollision/CollisionDispatch/btBoxBoxCollisionAlgorithm.cpp \
    $$PWD/BulletPhysics/BulletCollision/CollisionDispatch/btBoxBoxDetector.cpp \
    $$PWD/BulletPhysics/BulletCollision/CollisionDispatch/btCollisionDispatcher.cpp \
    $$PWD/BulletPhysics/BulletCollision/CollisionDispatch/btCollisionObject.cpp \
    $$PWD/BulletPhysics/BulletCollision/CollisionDispatch/btCollisionWorld.cpp \
    $$PWD/BulletPhysics/BulletCollision/CollisionDispatch/btCompoundCollisionAlgorithm.cpp \
    $$PWD/BulletPhysics/BulletCollision/CollisionDispatch/btConvex2dConvex2dAlgorithm.cpp \
    $$PWD/BulletPhysics/BulletCollision/CollisionDispatch/btConvexConcaveCollisionAlgorithm.cpp \
    $$PWD/BulletPhysics/BulletCollision/CollisionDispatch/btConvexConvexAlgorithm.cpp \
    $$PWD/BulletPhysics/BulletCollision/CollisionDispatch/btConvexPlaneCollisionAlgorithm.cpp \
    $$PWD/BulletPhysics/BulletCollision/CollisionDispatch/btDefaultCollisionConfiguration.cpp \
    $$PWD/BulletPhysics/BulletCollision/CollisionDispatch/btEmptyCollisionAlgorithm.cpp \
    $$PWD/BulletPhysics/BulletCollision/CollisionDispatch/btGhostObject.cpp \
    $$PWD/BulletPhysics/BulletCollision/CollisionDispatch/btInternalEdgeUtility.cpp \
    $$PWD/BulletPhysics/BulletCollision/CollisionDispatch/btManifoldResult.cpp \
    $$PWD/BulletPhysics/BulletCollision/CollisionDispatch/btSimulationIslandManager.cpp \
    $$PWD/BulletPhysics/BulletCollision/CollisionDispatch/btSphereBoxCollisionAlgorithm.cpp \
    $$PWD/BulletPhysics/BulletCollision/CollisionDispatch/btSphereSphereCollisionAlgorithm.cpp \
    $$PWD/BulletPhysics/BulletCollision/CollisionDispatch/btSphereTriangleCollisionAlgorithm.cpp \
    $$PWD/BulletPhysics/BulletCollision/CollisionDispatch/btUnionFind.cpp \
    $$PWD/BulletPhysics/BulletCollision/CollisionDispatch/SphereTriangleDetector.cpp \
    $$PWD/BulletPhysics/BulletCollision/CollisionShapes/btBox2dShape.cpp \
    $$PWD/BulletPhysics/BulletCollision/CollisionShapes/btBoxShape.cpp \
    $$PWD/BulletPhysics/BulletCollision/CollisionShapes/btBvhTriangleMeshShape.cpp \
    $$PWD/BulletPhysics/BulletCollision/CollisionShapes/btCapsuleShape.cpp \
    $$PWD/BulletPhysics/BulletCollision/CollisionShapes/btCollisionShape.cpp \
    $$PWD/BulletPhysics/BulletCollision/CollisionShapes/btCompoundShape.cpp \
    $$PWD/BulletPhysics/BulletCollision/CollisionShapes/btConcaveShape.cpp \
    $$PWD/BulletPhysics/BulletCollision/CollisionShapes/btConeShape.cpp \
    $$PWD/BulletPhysics/BulletCollision/CollisionShapes/btConvex2dShape.cpp \
    $$PWD/BulletPhysics/BulletCollision/CollisionShapes/btConvexHullShape.cpp \
    $$PWD/BulletPhysics/BulletCollision/CollisionShapes/btConvexInternalShape.cpp \
    $$PWD/BulletPhysics/BulletCollision/CollisionShapes/btConvexPointCloudShape.cpp \
    $$PWD/BulletPhysics/BulletCollision/CollisionShapes/btConvexPolyhedron.cpp \
    $$PWD/BulletPhysics/BulletCollision/CollisionShapes/btConvexShape.cpp \
    $$PWD/BulletPhysics/BulletCollision/CollisionShapes/btConvexTriangleMeshShape.cpp \
    $$PWD/BulletPhysics/BulletCollision/CollisionShapes/btCylinderShape.cpp \
    $$PWD/BulletPhysics/BulletCollision/CollisionShapes/btEmptyShape.cpp \
    $$PWD/BulletPhysics/BulletCollision/CollisionShapes/btHeightfieldTerrainShape.cpp \
    $$PWD/BulletPhysics/BulletCollision/CollisionShapes/btMinkowskiSumShape.cpp \
    $$PWD/BulletPhysics/BulletCollision/CollisionShapes/btMultimaterialTriangleMeshShape.cpp \
    $$PWD/BulletPhysics/BulletCollision/CollisionShapes/btMultiSphereShape.cpp \
    $$PWD/BulletPhysics/BulletCollision/CollisionShapes/btOptimizedBvh.cpp \
    $$PWD/BulletPhysics/BulletCollision/CollisionShapes/btPolyhedralConvexShape.cpp \
    $$PWD/BulletPhysics/BulletCollision/CollisionShapes/btScaledBvhTriangleMeshShape.cpp \
    $$PWD/BulletPhysics/BulletCollision/CollisionShapes/btShapeHull.cpp \
    $$PWD/BulletPhysics/BulletCollision/CollisionShapes/btSphereShape.cpp \
    $$PWD/BulletPhysics/BulletCollision/CollisionShapes/btStaticPlaneShape.cpp \
    $$PWD/BulletPhysics/BulletCollision/CollisionShapes/btStridingMeshInterface.cpp \
    $$PWD/BulletPhysics/BulletCollision/CollisionShapes/btTetrahedronShape.cpp \
    $$PWD/BulletPhysics/BulletCollision/CollisionShapes/btTriangleBuffer.cpp \
    $$PWD/BulletPhysics/BulletCollision/CollisionShapes/btTriangleCallback.cpp \
    $$PWD/BulletPhysics/BulletCollision/CollisionShapes/btTriangleIndexVertexArray.cpp \
    $$PWD/BulletPhysics/BulletCollision/CollisionShapes/btTriangleIndexVertexMaterialArray.cpp \
    $$PWD/BulletPhysics/BulletCollision/CollisionShapes/btTriangleMesh.cpp \
    $$PWD/BulletPhysics/BulletCollision/CollisionShapes/btTriangleMeshShape.cpp \
    $$PWD/BulletPhysics/BulletCollision/CollisionShapes/btUniformScalingShape.cpp \
    $$PWD/BulletPhysics/BulletCollision/Gimpact/btContactProcessing.cpp \
    $$PWD/BulletPhysics/BulletCollision/Gimpact/btGenericPoolAllocator.cpp \
    $$PWD/BulletPhysics/BulletCollision/Gimpact/btGImpactBvh.cpp \
    $$PWD/BulletPhysics/BulletCollision/Gimpact/btGImpactCollisionAlgorithm.cpp \
    $$PWD/BulletPhysics/BulletCollision/Gimpact/btGImpactQuantizedBvh.cpp \
    $$PWD/BulletPhysics/BulletCollision/Gimpact/btGImpactShape.cpp \
    $$PWD/BulletPhysics/BulletCollision/Gimpact/btTriangleShapeEx.cpp \
    $$PWD/BulletPhysics/BulletCollision/Gimpact/gim_box_set.cpp \
    $$PWD/BulletPhysics/BulletCollision/Gimpact/gim_contact.cpp \
    $$PWD/BulletPhysics/BulletCollision/Gimpact/gim_memory.cpp \
    $$PWD/BulletPhysics/BulletCollision/Gimpact/gim_tri_collision.cpp \
    $$PWD/BulletPhysics/BulletCollision/NarrowPhaseCollision/btContinuousConvexCollision.cpp \
    $$PWD/BulletPhysics/BulletCollision/NarrowPhaseCollision/btConvexCast.cpp \
    $$PWD/BulletPhysics/BulletCollision/NarrowPhaseCollision/btGjkConvexCast.cpp \
    $$PWD/BulletPhysics/BulletCollision/NarrowPhaseCollision/btGjkEpa2.cpp \
    $$PWD/BulletPhysics/BulletCollision/NarrowPhaseCollision/btGjkEpaPenetrationDepthSolver.cpp \
    $$PWD/BulletPhysics/BulletCollision/NarrowPhaseCollision/btGjkPairDetector.cpp \
    $$PWD/BulletPhysics/BulletCollision/NarrowPhaseCollision/btMinkowskiPenetrationDepthSolver.cpp \
    $$PWD/BulletPhysics/BulletCollision/NarrowPhaseCollision/btPersistentManifold.cpp \
    $$PWD/BulletPhysics/BulletCollision/NarrowPhaseCollision/btPolyhedralContactClipping.cpp \
    $$PWD/BulletPhysics/BulletCollision/NarrowPhaseCollision/btRaycastCallback.cpp \
    $$PWD/BulletPhysics/BulletCollision/NarrowPhaseCollision/btSubSimplexConvexCast.cpp \
    $$PWD/BulletPhysics/BulletCollision/NarrowPhaseCollision/btVoronoiSimplexSolver.cpp \
    $$PWD/BulletPhysics/BulletDynamics/Character/btKinematicCharacterController.cpp \
    $$PWD/BulletPhysics/BulletDynamics/ConstraintSolver/btConeTwistConstraint.cpp \
    $$PWD/BulletPhysics/BulletDynamics/ConstraintSolver/btContactConstraint.cpp \
    $$PWD/BulletPhysics/BulletDynamics/ConstraintSolver/btGearConstraint.cpp \
    $$PWD/BulletPhysics/BulletDynamics/ConstraintSolver/btGeneric6DofConstraint.cpp \
    $$PWD/BulletPhysics/BulletDynamics/ConstraintSolver/btGeneric6DofSpringConstraint.cpp \
    $$PWD/BulletPhysics/BulletDynamics/ConstraintSolver/btHinge2Constraint.cpp \
    $$PWD/BulletPhysics/BulletDynamics/ConstraintSolver/btHingeConstraint.cpp \
    $$PWD/BulletPhysics/BulletDynamics/ConstraintSolver/btPoint2PointConstraint.cpp \
    $$PWD/BulletPhysics/BulletDynamics/ConstraintSolver/btSequentialImpulseConstraintSolver.cpp \
    $$PWD/BulletPhysics/BulletDynamics/ConstraintSolver/btSliderConstraint.cpp \
    $$PWD/BulletPhysics/BulletDynamics/ConstraintSolver/btSolve2LinearConstraint.cpp \
    $$PWD/BulletPhysics/BulletDynamics/ConstraintSolver/btTypedConstraint.cpp \
    $$PWD/BulletPhysics/BulletDynamics/ConstraintSolver/btUniversalConstraint.cpp \
    $$PWD/BulletPhysics/BulletDynamics/Dynamics/btDiscreteDynamicsWorld.cpp \
    $$PWD/BulletPhysics/BulletDynamics/Dynamics/btRigidBody.cpp \
    $$PWD/BulletPhysics/BulletDynamics/Dynamics/btSimpleDynamicsWorld.cpp \
    $$PWD/BulletPhysics/BulletDynamics/Dynamics/Bullet-C-API.cpp \
    $$PWD/BulletPhysics/BulletDynamics/Vehicle/btRaycastVehicle.cpp \
    $$PWD/BulletPhysics/BulletDynamics/Vehicle/btWheelInfo.cpp \
    $$PWD/BulletPhysics/BulletMultiThreaded/btGpu3DGridBroadphase.cpp \
    $$PWD/BulletPhysics/BulletMultiThreaded/btParallelConstraintSolver.cpp \
    $$PWD/BulletPhysics/BulletMultiThreaded/btThreadSupportInterface.cpp \
    $$PWD/BulletPhysics/BulletMultiThreaded/PosixThreadSupport.cpp \
    $$PWD/BulletPhysics/BulletMultiThreaded/SequentialThreadSupport.cpp \
    $$PWD/BulletPhysics/BulletMultiThreaded/SpuCollisionObjectWrapper.cpp \
    $$PWD/BulletPhysics/BulletMultiThreaded/SpuCollisionTaskProcess.cpp \
    $$PWD/BulletPhysics/BulletMultiThreaded/SpuContactManifoldCollisionAlgorithm.cpp \
    $$PWD/BulletPhysics/BulletMultiThreaded/SpuFakeDma.cpp \
    $$PWD/BulletPhysics/BulletMultiThreaded/SpuGatheringCollisionDispatcher.cpp \
    $$PWD/BulletPhysics/BulletMultiThreaded/SpuLibspe2Support.cpp \
    $$PWD/BulletPhysics/BulletMultiThreaded/SpuSampleTaskProcess.cpp \
    $$PWD/BulletPhysics/BulletMultiThreaded/Win32ThreadSupport.cpp \
    $$PWD/BulletPhysics/BulletMultiThreaded/SpuNarrowPhaseCollisionTask/boxBoxDistance.cpp \
    $$PWD/BulletPhysics/BulletMultiThreaded/SpuNarrowPhaseCollisionTask/SpuCollisionShapes.cpp \
    $$PWD/BulletPhysics/BulletMultiThreaded/SpuNarrowPhaseCollisionTask/SpuContactResult.cpp \
    $$PWD/BulletPhysics/BulletMultiThreaded/SpuNarrowPhaseCollisionTask/SpuGatheringCollisionTask.cpp \
    $$PWD/BulletPhysics/BulletMultiThreaded/SpuNarrowPhaseCollisionTask/SpuMinkowskiPenetrationDepthSolver.cpp \
    $$PWD/BulletPhysics/BulletMultiThreaded/SpuSampleTask/SpuSampleTask.cpp \
    $$PWD/BulletPhysics/LinearMath/btAlignedAllocator.cpp \
    $$PWD/BulletPhysics/LinearMath/btConvexHull.cpp \
    $$PWD/BulletPhysics/LinearMath/btConvexHullComputer.cpp \
    $$PWD/BulletPhysics/LinearMath/btGeometryUtil.cpp \
    $$PWD/BulletPhysics/LinearMath/btPolarDecomposition.cpp \
    $$PWD/BulletPhysics/LinearMath/btQuickprof.cpp \
    $$PWD/BulletPhysics/LinearMath/btSerializer.cpp \
    $$PWD/BulletPhysics/LinearMath/btVector3.cpp

HEADERS += \
    $$PWD/physics/boundingbox.h \
    $$PWD/physics/boundingsphere.h \
    $$PWD/physics/collisionpointinfo.h \
    $$PWD/physics/dynamiccharacter.h \
    $$PWD/physics/dynamiccharacterwithcam.h \
    $$PWD/physics/physicengine.h \
    $$PWD/physics/physicenginemanager.h \
    $$PWD/physics/physicobject.h \
    $$PWD/physics/physics.h \
    $$PWD/physics/responseobject.h \
    $$PWD/physics/trigger.h \
    $$PWD/physics/PhysicMath/eigenvector.h \
    $$PWD/physics/BulletPhysicEngine/bulletcollisiondispatcher.h \
    $$PWD/physics/BulletPhysicEngine/bulletdebugdrawer.h \
    $$PWD/physics/BulletPhysicEngine/bulletdiscretedynamicsworld.h \
    $$PWD/physics/BulletPhysicEngine/bulletdynamiccharacter.h \
    $$PWD/physics/BulletPhysicEngine/bulletdynamiccharacterwithcam.h \
    $$PWD/physics/BulletPhysicEngine/bulletparallelcollisioncallback.h \
    $$PWD/physics/BulletPhysicEngine/bulletphysicengine.h \
    $$PWD/physics/BulletPhysicEngine/bulletphysicmatrixtogeometry.h \
    $$PWD/physics/BulletPhysicEngine/bulletphysicobject.h \
    $$PWD/physics/BulletPhysicEngine/bulletspucollisiondispatcher.h \
    $$PWD/physics/igeometryaccess.h \
    $$PWD/physics/icameraaccess.h

HEADERS += $$PWD/BulletPhysics/BulletCollision/BroadphaseCollision/btAxisSweep3.h \
    $$PWD/BulletPhysics/BulletCollision/BroadphaseCollision/btBroadphaseInterface.h \
    $$PWD/BulletPhysics/BulletCollision/BroadphaseCollision/btBroadphaseProxy.h \
    $$PWD/BulletPhysics/BulletCollision/BroadphaseCollision/btCollisionAlgorithm.h \
    $$PWD/BulletPhysics/BulletCollision/BroadphaseCollision/btDbvt.h \
    $$PWD/BulletPhysics/BulletCollision/BroadphaseCollision/btDbvtBroadphase.h \
    $$PWD/BulletPhysics/BulletCollision/BroadphaseCollision/btDispatcher.h \
    $$PWD/BulletPhysics/BulletCollision/BroadphaseCollision/btMultiSapBroadphase.h \
    $$PWD/BulletPhysics/BulletCollision/BroadphaseCollision/btOverlappingPairCache.h \
    $$PWD/BulletPhysics/BulletCollision/BroadphaseCollision/btOverlappingPairCallback.h \
    $$PWD/BulletPhysics/BulletCollision/BroadphaseCollision/btQuantizedBvh.h \
    $$PWD/BulletPhysics/BulletCollision/BroadphaseCollision/btSimpleBroadphase.h \
    $$PWD/BulletPhysics/BulletCollision/CollisionDispatch/btActivatingCollisionAlgorithm.h \
    $$PWD/BulletPhysics/BulletCollision/CollisionDispatch/btBox2dBox2dCollisionAlgorithm.h \
    $$PWD/BulletPhysics/BulletCollision/CollisionDispatch/btBoxBoxCollisionAlgorithm.h \
    $$PWD/BulletPhysics/BulletCollision/CollisionDispatch/btBoxBoxDetector.h \
    $$PWD/BulletPhysics/BulletCollision/CollisionDispatch/btCollisionConfiguration.h \
    $$PWD/BulletPhysics/BulletCollision/CollisionDispatch/btCollisionCreateFunc.h \
    $$PWD/BulletPhysics/BulletCollision/CollisionDispatch/btCollisionDispatcher.h \
    $$PWD/BulletPhysics/BulletCollision/CollisionDispatch/btCollisionObject.h \
    $$PWD/BulletPhysics/BulletCollision/CollisionDispatch/btCollisionObjectWrapper.h \
    $$PWD/BulletPhysics/BulletCollision/CollisionDispatch/btCollisionWorld.h \
    $$PWD/BulletPhysics/BulletCollision/CollisionDispatch/btCompoundCollisionAlgorithm.h \
    $$PWD/BulletPhysics/BulletCollision/CollisionDispatch/btConvex2dConvex2dAlgorithm.h \
    $$PWD/BulletPhysics/BulletCollision/CollisionDispatch/btConvexConcaveCollisionAlgorithm.h \
    $$PWD/BulletPhysics/BulletCollision/CollisionDispatch/btConvexConvexAlgorithm.h \
    $$PWD/BulletPhysics/BulletCollision/CollisionDispatch/btConvexPlaneCollisionAlgorithm.h \
    $$PWD/BulletPhysics/BulletCollision/CollisionDispatch/btDefaultCollisionConfiguration.h \
    $$PWD/BulletPhysics/BulletCollision/CollisionDispatch/btEmptyCollisionAlgorithm.h \
    $$PWD/BulletPhysics/BulletCollision/CollisionDispatch/btGhostObject.h \
    $$PWD/BulletPhysics/BulletCollision/CollisionDispatch/btInternalEdgeUtility.h \
    $$PWD/BulletPhysics/BulletCollision/CollisionDispatch/btManifoldResult.h \
    $$PWD/BulletPhysics/BulletCollision/CollisionDispatch/btSimulationIslandManager.h \
    $$PWD/BulletPhysics/BulletCollision/CollisionDispatch/btSphereBoxCollisionAlgorithm.h \
    $$PWD/BulletPhysics/BulletCollision/CollisionDispatch/btSphereSphereCollisionAlgorithm.h \
    $$PWD/BulletPhysics/BulletCollision/CollisionDispatch/btSphereTriangleCollisionAlgorithm.h \
    $$PWD/BulletPhysics/BulletCollision/CollisionDispatch/btUnionFind.h \
    $$PWD/BulletPhysics/BulletCollision/CollisionDispatch/SphereTriangleDetector.h \
    $$PWD/BulletPhysics/BulletCollision/CollisionShapes/btBox2dShape.h \
    $$PWD/BulletPhysics/BulletCollision/CollisionShapes/btBoxShape.h \
    $$PWD/BulletPhysics/BulletCollision/CollisionShapes/btBvhTriangleMeshShape.h \
    $$PWD/BulletPhysics/BulletCollision/CollisionShapes/btCapsuleShape.h \
    $$PWD/BulletPhysics/BulletCollision/CollisionShapes/btCollisionMargin.h \
    $$PWD/BulletPhysics/BulletCollision/CollisionShapes/btCollisionShape.h \
    $$PWD/BulletPhysics/BulletCollision/CollisionShapes/btCompoundShape.h \
    $$PWD/BulletPhysics/BulletCollision/CollisionShapes/btConcaveShape.h \
    $$PWD/BulletPhysics/BulletCollision/CollisionShapes/btConeShape.h \
    $$PWD/BulletPhysics/BulletCollision/CollisionShapes/btConvex2dShape.h \
    $$PWD/BulletPhysics/BulletCollision/CollisionShapes/btConvexHullShape.h \
    $$PWD/BulletPhysics/BulletCollision/CollisionShapes/btConvexInternalShape.h \
    $$PWD/BulletPhysics/BulletCollision/CollisionShapes/btConvexPointCloudShape.h \
    $$PWD/BulletPhysics/BulletCollision/CollisionShapes/btConvexPolyhedron.h \
    $$PWD/BulletPhysics/BulletCollision/CollisionShapes/btConvexShape.h \
    $$PWD/BulletPhysics/BulletCollision/CollisionShapes/btConvexTriangleMeshShape.h \
    $$PWD/BulletPhysics/BulletCollision/CollisionShapes/btCylinderShape.h \
    $$PWD/BulletPhysics/BulletCollision/CollisionShapes/btEmptyShape.h \
    $$PWD/BulletPhysics/BulletCollision/CollisionShapes/btHeightfieldTerrainShape.h \
    $$PWD/BulletPhysics/BulletCollision/CollisionShapes/btMaterial.h \
    $$PWD/BulletPhysics/BulletCollision/CollisionShapes/btMinkowskiSumShape.h \
    $$PWD/BulletPhysics/BulletCollision/CollisionShapes/btMultimaterialTriangleMeshShape.h \
    $$PWD/BulletPhysics/BulletCollision/CollisionShapes/btMultiSphereShape.h \
    $$PWD/BulletPhysics/BulletCollision/CollisionShapes/btOptimizedBvh.h \
    $$PWD/BulletPhysics/BulletCollision/CollisionShapes/btPolyhedralConvexShape.h \
    $$PWD/BulletPhysics/BulletCollision/CollisionShapes/btScaledBvhTriangleMeshShape.h \
    $$PWD/BulletPhysics/BulletCollision/CollisionShapes/btShapeHull.h \
    $$PWD/BulletPhysics/BulletCollision/CollisionShapes/btSphereShape.h \
    $$PWD/BulletPhysics/BulletCollision/CollisionShapes/btStaticPlaneShape.h \
    $$PWD/BulletPhysics/BulletCollision/CollisionShapes/btStridingMeshInterface.h \
    $$PWD/BulletPhysics/BulletCollision/CollisionShapes/btTetrahedronShape.h \
    $$PWD/BulletPhysics/BulletCollision/CollisionShapes/btTriangleBuffer.h \
    $$PWD/BulletPhysics/BulletCollision/CollisionShapes/btTriangleCallback.h \
    $$PWD/BulletPhysics/BulletCollision/CollisionShapes/btTriangleIndexVertexArray.h \
    $$PWD/BulletPhysics/BulletCollision/CollisionShapes/btTriangleIndexVertexMaterialArray.h \
    $$PWD/BulletPhysics/BulletCollision/CollisionShapes/btTriangleInfoMap.h \
    $$PWD/BulletPhysics/BulletCollision/CollisionShapes/btTriangleMesh.h \
    $$PWD/BulletPhysics/BulletCollision/CollisionShapes/btTriangleMeshShape.h \
    $$PWD/BulletPhysics/BulletCollision/CollisionShapes/btTriangleShape.h \
    $$PWD/BulletPhysics/BulletCollision/CollisionShapes/btUniformScalingShape.h \
    $$PWD/BulletPhysics/BulletCollision/Gimpact/btBoxCollision.h \
    $$PWD/BulletPhysics/BulletCollision/Gimpact/btClipPolygon.h \
    $$PWD/BulletPhysics/BulletCollision/Gimpact/btContactProcessing.h \
    $$PWD/BulletPhysics/BulletCollision/Gimpact/btGenericPoolAllocator.h \
    $$PWD/BulletPhysics/BulletCollision/Gimpact/btGeometryOperations.h \
    $$PWD/BulletPhysics/BulletCollision/Gimpact/btGImpactBvh.h \
    $$PWD/BulletPhysics/BulletCollision/Gimpact/btGImpactCollisionAlgorithm.h \
    $$PWD/BulletPhysics/BulletCollision/Gimpact/btGImpactMassUtil.h \
    $$PWD/BulletPhysics/BulletCollision/Gimpact/btGImpactQuantizedBvh.h \
    $$PWD/BulletPhysics/BulletCollision/Gimpact/btGImpactShape.h \
    $$PWD/BulletPhysics/BulletCollision/Gimpact/btQuantization.h \
    $$PWD/BulletPhysics/BulletCollision/Gimpact/btTriangleShapeEx.h \
    $$PWD/BulletPhysics/BulletCollision/Gimpact/gim_array.h \
    $$PWD/BulletPhysics/BulletCollision/Gimpact/gim_basic_geometry_operations.h \
    $$PWD/BulletPhysics/BulletCollision/Gimpact/gim_bitset.h \
    $$PWD/BulletPhysics/BulletCollision/Gimpact/gim_box_collision.h \
    $$PWD/BulletPhysics/BulletCollision/Gimpact/gim_box_set.h \
    $$PWD/BulletPhysics/BulletCollision/Gimpact/gim_clip_polygon.h \
    $$PWD/BulletPhysics/BulletCollision/Gimpact/gim_contact.h \
    $$PWD/BulletPhysics/BulletCollision/Gimpact/gim_geom_types.h \
    $$PWD/BulletPhysics/BulletCollision/Gimpact/gim_geometry.h \
    $$PWD/BulletPhysics/BulletCollision/Gimpact/gim_hash_table.h \
    $$PWD/BulletPhysics/BulletCollision/Gimpact/gim_linear_math.h \
    $$PWD/BulletPhysics/BulletCollision/Gimpact/gim_math.h \
    $$PWD/BulletPhysics/BulletCollision/Gimpact/gim_memory.h \
    $$PWD/BulletPhysics/BulletCollision/Gimpact/gim_radixsort.h \
    $$PWD/BulletPhysics/BulletCollision/Gimpact/gim_tri_collision.h \
    $$PWD/BulletPhysics/BulletCollision/NarrowPhaseCollision/btContinuousConvexCollision.h \
    $$PWD/BulletPhysics/BulletCollision/NarrowPhaseCollision/btConvexCast.h \
    $$PWD/BulletPhysics/BulletCollision/NarrowPhaseCollision/btConvexPenetrationDepthSolver.h \
    $$PWD/BulletPhysics/BulletCollision/NarrowPhaseCollision/btDiscreteCollisionDetectorInterface.h \
    $$PWD/BulletPhysics/BulletCollision/NarrowPhaseCollision/btGjkConvexCast.h \
    $$PWD/BulletPhysics/BulletCollision/NarrowPhaseCollision/btGjkEpa2.h \
    $$PWD/BulletPhysics/BulletCollision/NarrowPhaseCollision/btGjkEpaPenetrationDepthSolver.h \
    $$PWD/BulletPhysics/BulletCollision/NarrowPhaseCollision/btGjkPairDetector.h \
    $$PWD/BulletPhysics/BulletCollision/NarrowPhaseCollision/btManifoldPoint.h \
    $$PWD/BulletPhysics/BulletCollision/NarrowPhaseCollision/btMinkowskiPenetrationDepthSolver.h \
    $$PWD/BulletPhysics/BulletCollision/NarrowPhaseCollision/btPersistentManifold.h \
    $$PWD/BulletPhysics/BulletCollision/NarrowPhaseCollision/btPointCollector.h \
    $$PWD/BulletPhysics/BulletCollision/NarrowPhaseCollision/btPolyhedralContactClipping.h \
    $$PWD/BulletPhysics/BulletCollision/NarrowPhaseCollision/btRaycastCallback.h \
    $$PWD/BulletPhysics/BulletCollision/NarrowPhaseCollision/btSimplexSolverInterface.h \
    $$PWD/BulletPhysics/BulletCollision/NarrowPhaseCollision/btSubSimplexConvexCast.h \
    $$PWD/BulletPhysics/BulletCollision/NarrowPhaseCollision/btVoronoiSimplexSolver.h \
    $$PWD/BulletPhysics/BulletDynamics/Character/btCharacterControllerInterface.h \
    $$PWD/BulletPhysics/BulletDynamics/Character/btKinematicCharacterController.h \
    $$PWD/BulletPhysics/BulletDynamics/ConstraintSolver/btConeTwistConstraint.h \
    $$PWD/BulletPhysics/BulletDynamics/ConstraintSolver/btConstraintSolver.h \
    $$PWD/BulletPhysics/BulletDynamics/ConstraintSolver/btContactConstraint.h \
    $$PWD/BulletPhysics/BulletDynamics/ConstraintSolver/btContactSolverInfo.h \
    $$PWD/BulletPhysics/BulletDynamics/ConstraintSolver/btGearConstraint.h \
    $$PWD/BulletPhysics/BulletDynamics/ConstraintSolver/btGeneric6DofConstraint.h \
    $$PWD/BulletPhysics/BulletDynamics/ConstraintSolver/btGeneric6DofSpringConstraint.h \
    $$PWD/BulletPhysics/BulletDynamics/ConstraintSolver/btHinge2Constraint.h \
    $$PWD/BulletPhysics/BulletDynamics/ConstraintSolver/btHingeConstraint.h \
    $$PWD/BulletPhysics/BulletDynamics/ConstraintSolver/btJacobianEntry.h \
    $$PWD/BulletPhysics/BulletDynamics/ConstraintSolver/btPoint2PointConstraint.h \
    $$PWD/BulletPhysics/BulletDynamics/ConstraintSolver/btSequentialImpulseConstraintSolver.h \
    $$PWD/BulletPhysics/BulletDynamics/ConstraintSolver/btSliderConstraint.h \
    $$PWD/BulletPhysics/BulletDynamics/ConstraintSolver/btSolve2LinearConstraint.h \
    $$PWD/BulletPhysics/BulletDynamics/ConstraintSolver/btSolverBody.h \
    $$PWD/BulletPhysics/BulletDynamics/ConstraintSolver/btSolverConstraint.h \
    $$PWD/BulletPhysics/BulletDynamics/ConstraintSolver/btTypedConstraint.h \
    $$PWD/BulletPhysics/BulletDynamics/ConstraintSolver/btUniversalConstraint.h \
    $$PWD/BulletPhysics/BulletDynamics/Dynamics/btActionInterface.h \
    $$PWD/BulletPhysics/BulletDynamics/Dynamics/btDiscreteDynamicsWorld.h \
    $$PWD/BulletPhysics/BulletDynamics/Dynamics/btDynamicsWorld.h \
    $$PWD/BulletPhysics/BulletDynamics/Dynamics/btRigidBody.h \
    $$PWD/BulletPhysics/BulletDynamics/Dynamics/btSimpleDynamicsWorld.h \
    $$PWD/BulletPhysics/BulletDynamics/Vehicle/btRaycastVehicle.h \
    $$PWD/BulletPhysics/BulletDynamics/Vehicle/btVehicleRaycaster.h \
    $$PWD/BulletPhysics/BulletDynamics/Vehicle/btWheelInfo.h \
    $$PWD/BulletPhysics/BulletMultiThreaded/btGpu3DGridBroadphase.h \
    $$PWD/BulletPhysics/BulletMultiThreaded/btGpu3DGridBroadphaseSharedCode.h \
    $$PWD/BulletPhysics/BulletMultiThreaded/btGpu3DGridBroadphaseSharedDefs.h \
    $$PWD/BulletPhysics/BulletMultiThreaded/btGpu3DGridBroadphaseSharedTypes.h \
    $$PWD/BulletPhysics/BulletMultiThreaded/btGpuDefines.h \
    $$PWD/BulletPhysics/BulletMultiThreaded/btGpuUtilsSharedCode.h \
    $$PWD/BulletPhysics/BulletMultiThreaded/btGpuUtilsSharedDefs.h \
    $$PWD/BulletPhysics/BulletMultiThreaded/btParallelConstraintSolver.h \
    $$PWD/BulletPhysics/BulletMultiThreaded/btThreadSupportInterface.h \
    $$PWD/BulletPhysics/BulletMultiThreaded/HeapManager.h \
    $$PWD/BulletPhysics/BulletMultiThreaded/PlatformDefinitions.h \
    $$PWD/BulletPhysics/BulletMultiThreaded/PosixThreadSupport.h \
    $$PWD/BulletPhysics/BulletMultiThreaded/PpuAddressSpace.h \
    $$PWD/BulletPhysics/BulletMultiThreaded/SequentialThreadSupport.h \
    $$PWD/BulletPhysics/BulletMultiThreaded/SpuCollisionObjectWrapper.h \
    $$PWD/BulletPhysics/BulletMultiThreaded/SpuCollisionTaskProcess.h \
    $$PWD/BulletPhysics/BulletMultiThreaded/SpuContactManifoldCollisionAlgorithm.h \
    $$PWD/BulletPhysics/BulletMultiThreaded/SpuDoubleBuffer.h \
    $$PWD/BulletPhysics/BulletMultiThreaded/SpuFakeDma.h \
    $$PWD/BulletPhysics/BulletMultiThreaded/SpuGatheringCollisionDispatcher.h \
    $$PWD/BulletPhysics/BulletMultiThreaded/SpuLibspe2Support.h \
    $$PWD/BulletPhysics/BulletMultiThreaded/SpuSampleTaskProcess.h \
    $$PWD/BulletPhysics/BulletMultiThreaded/SpuSync.h \
    $$PWD/BulletPhysics/BulletMultiThreaded/TrbDynBody.h \
    $$PWD/BulletPhysics/BulletMultiThreaded/TrbStateVec.h \
    $$PWD/BulletPhysics/BulletMultiThreaded/vectormath2bullet.h \
    $$PWD/BulletPhysics/BulletMultiThreaded/Win32ThreadSupport.h \
    $$PWD/BulletPhysics/BulletMultiThreaded/SpuNarrowPhaseCollisionTask/Box.h \
    $$PWD/BulletPhysics/BulletMultiThreaded/SpuNarrowPhaseCollisionTask/boxBoxDistance.h \
    $$PWD/BulletPhysics/BulletMultiThreaded/SpuNarrowPhaseCollisionTask/SpuCollisionShapes.h \
    $$PWD/BulletPhysics/BulletMultiThreaded/SpuNarrowPhaseCollisionTask/SpuContactResult.h \
    $$PWD/BulletPhysics/BulletMultiThreaded/SpuNarrowPhaseCollisionTask/SpuConvexPenetrationDepthSolver.h \
    $$PWD/BulletPhysics/BulletMultiThreaded/SpuNarrowPhaseCollisionTask/SpuGatheringCollisionTask.h \
    $$PWD/BulletPhysics/BulletMultiThreaded/SpuNarrowPhaseCollisionTask/SpuLocalSupport.h \
    $$PWD/BulletPhysics/BulletMultiThreaded/SpuNarrowPhaseCollisionTask/SpuMinkowskiPenetrationDepthSolver.h \
    $$PWD/BulletPhysics/BulletMultiThreaded/SpuNarrowPhaseCollisionTask/SpuPreferredPenetrationDirections.h \
    $$PWD/BulletPhysics/BulletMultiThreaded/SpuSampleTask/SpuSampleTask.h \
    $$PWD/BulletPhysics/LinearMath/btAabbUtil2.h \
    $$PWD/BulletPhysics/LinearMath/btAlignedAllocator.h \
    $$PWD/BulletPhysics/LinearMath/btAlignedObjectArray.h \
    $$PWD/BulletPhysics/LinearMath/btConvexHull.h \
    $$PWD/BulletPhysics/LinearMath/btConvexHullComputer.h \
    $$PWD/BulletPhysics/LinearMath/btDefaultMotionState.h \
    $$PWD/BulletPhysics/LinearMath/btGeometryUtil.h \
    $$PWD/BulletPhysics/LinearMath/btGrahamScan2dConvexHull.h \
    $$PWD/BulletPhysics/LinearMath/btHashMap.h \
    $$PWD/BulletPhysics/LinearMath/btIDebugDraw.h \
    $$PWD/BulletPhysics/LinearMath/btList.h \
    $$PWD/BulletPhysics/LinearMath/btMatrix3x3.h \
    $$PWD/BulletPhysics/LinearMath/btMinMax.h \
    $$PWD/BulletPhysics/LinearMath/btMotionState.h \
    $$PWD/BulletPhysics/LinearMath/btPolarDecomposition.h \
    $$PWD/BulletPhysics/LinearMath/btPoolAllocator.h \
    $$PWD/BulletPhysics/LinearMath/btQuadWord.h \
    $$PWD/BulletPhysics/LinearMath/btQuaternion.h \
    $$PWD/BulletPhysics/LinearMath/btQuickprof.h \
    $$PWD/BulletPhysics/LinearMath/btRandom.h \
    $$PWD/BulletPhysics/LinearMath/btScalar.h \
    $$PWD/BulletPhysics/LinearMath/btSerializer.h \
    $$PWD/BulletPhysics/LinearMath/btStackAlloc.h \
    $$PWD/BulletPhysics/LinearMath/btTransform.h \
    $$PWD/BulletPhysics/LinearMath/btTransformUtil.h \
    $$PWD/BulletPhysics/LinearMath/btVector3.h
