#include "qtstereosoundapi.h"
#include <QList>
#include <QFileInfo>
#include <QMediaPlayer>
#include <QAudioOutput>
#include "soundsource.h"
#include "scenemanager.h"

QtStereoSoundAPI::QtStereoSoundAPI()
{
    mNrOfActiveSounds = 0;
}

QtStereoSoundAPI::~QtStereoSoundAPI()
{
}

void QtStereoSoundAPI::play(unsigned int soundsourceid)
{
    mSounds[soundsourceid-1]->play();
}

void QtStereoSoundAPI::pause(unsigned int soundsourceid)
{
    Q_UNUSED(soundsourceid);
}

void QtStereoSoundAPI::stop(unsigned int soundsourceid)
{
    mSounds[soundsourceid-1]->pause();
}

void QtStereoSoundAPI::setSoundSourcePosition(unsigned int soundsourceid, const QVector3D &newPos)
{
    Q_UNUSED(soundsourceid);
     Q_UNUSED(newPos);
}

void QtStereoSoundAPI::setListenerPosition(const QVector3D &position)
{
    Q_UNUSED(position);
}

void QtStereoSoundAPI::setListenerOrientation(const QVector3D &orientation, const QVector3D &up)
{
    Q_UNUSED(orientation);
}

void QtStereoSoundAPI::setListenerVelocity(const QVector3D &velocity)
{
    Q_UNUSED(velocity);
}

unsigned int QtStereoSoundAPI::createSoundSource(unsigned int soundbufferid)
{
    return soundbufferid;
}

unsigned int QtStereoSoundAPI::createSound(QString const& filepath)
{
    QFileInfo lFileInfo(filepath);
    if (lFileInfo.exists())
    {
        LoopableQMediaPlayer *lContent = new LoopableQMediaPlayer();
        QUrl url = QUrl::fromLocalFile(lFileInfo.absoluteFilePath());
#if QT_VERSION_MAJOR < 6
        lContent->setMedia(url);
#else
        lContent->setSource(url);
#endif

        if (lContent != nullptr)
        {
            mSounds.push_back(lContent);
            return(mSounds.length());
        }
        return(0);
    }
    else
    {
        qDebug() << "Soundmanager: " << filepath << " not found.";
        return(0);
    }
}


void QtStereoSoundAPI::setSoundSourcePitch(unsigned int soundsourceid, const float pitch)
{
    Q_UNUSED(soundsourceid);
    Q_UNUSED(pitch);
}

void QtStereoSoundAPI::setSoundSourceVolume(unsigned int soundsourceid, const float volume)
{
    mSounds[soundsourceid-1]->audioOutput()->setVolume(volume);
}

void QtStereoSoundAPI::setSoundSourceLooping(unsigned int soundsourceid, const bool isLooping)
{
    mSounds[soundsourceid-1]->setLooping(isLooping);
}

void QtStereoSoundAPI::setSoundSourceVelocity(unsigned int soundsourceid, const QVector3D &velocity)
{
}


bool QtStereoSoundAPI::init()
{
    return(true);
}


void QtStereoSoundAPI::setEffectReverb(unsigned int soundSourceId, EFXEAXREVERBPROPERTIES efxReverProperty)
{
}

LoopableQMediaPlayer::LoopableQMediaPlayer(): QMediaPlayer(SceneManager::instance()->getMainWindow())
{
    QAudioOutput *audioOutput = new QAudioOutput(SceneManager::instance()->getMainWindow());
    this->setAudioOutput(audioOutput);
    mIsLooping = false;
}

void LoopableQMediaPlayer::setLooping(bool pLoop)
{
    if (pLoop)
    {
        if (mIsLooping == false)
        {
#if QT_VERSION_MAJOR < 6
            connect(this, &QMediaPlayer::mediaStatusChanged, this, &LoopableQMediaPlayer::doLooping);
#else
            connect(this, &QMediaPlayer::playbackStateChanged, this, &LoopableQMediaPlayer::doLooping);
#endif
            mIsLooping = true;
        }
    }
    else
        if (mIsLooping == true)
        {
            disconnect(this, &QMediaPlayer::mediaStatusChanged, this, &LoopableQMediaPlayer::doLooping);
            mIsLooping = false;
        }
}

bool LoopableQMediaPlayer::getLooping()
{
    return mIsLooping;
}

void LoopableQMediaPlayer::doLooping()
{
#if QT_VERSION_MAJOR < 6
    if (this->state() == QMediaPlayer::StoppedState)
#else
    if (this->playbackState() == QMediaPlayer::PlaybackState::StoppedState)
#endif
        this->play();
}
