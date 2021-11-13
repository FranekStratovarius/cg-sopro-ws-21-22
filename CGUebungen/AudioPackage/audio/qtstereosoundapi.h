#ifndef QTSTEREOSOUNDAPI_H
#define QTSTEREOSOUNDAPI_H
#include "isoundapi.h"
#include <memory>
#include <QList>
#include <QMediaPlayer>

class QMediaContent;

class LoopableQMediaPlayer: public QMediaPlayer
{
public:
    LoopableQMediaPlayer();
    void setLooping(bool pLoop);
    bool getLooping();
    virtual ~LoopableQMediaPlayer() {}
public slots:
    void doLooping();
private:
    bool mIsLooping;
};

class QtStereoSoundAPI : public ISoundAPI
{
public:
    QtStereoSoundAPI();
    ~QtStereoSoundAPI();

    // ISoundAPI interface
public:
    void play(unsigned int soundsourceid) override;
    void pause(unsigned int soundsourceid) override;
    void stop(unsigned int soundsourceid) override;
    void setSoundSourcePosition(unsigned int soundsourceid, const QVector3D &newPos) override;
    void setListenerPosition(const QVector3D &position) override;
    void setListenerOrientation(const QVector3D &orientation, const QVector3D &up) override;
    void setListenerVelocity(const QVector3D &velocity) override;
    unsigned int createSoundSource(unsigned int soundbufferid) override;
    unsigned int createSound(QString const& filepath) override;
    void setSoundSourcePitch(unsigned int soundsourceid, const float pitch) override;
    void setSoundSourceVolume(unsigned int soundsourceid, const float volume) override;
    void setSoundSourceLooping(unsigned int soundsourceid, const bool isLooping) override;
    void setSoundSourceVelocity(unsigned int soundsourceid, const QVector3D &velocity) override;

    bool init() override;
private:

     unsigned int mNrOfActiveSounds;
     QList<LoopableQMediaPlayer *> mSounds;

     // ISoundAPI interface
public:
     void setEffectReverb(unsigned int soundSourceId, EFXEAXREVERBPROPERTIES efxReverProperty) override;
};

#endif // QTSTEREOSOUNDAPI_H
