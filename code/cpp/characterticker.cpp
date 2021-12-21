#include "characterticker.h"
#include "inputregistry.h"


/*
CharacterTicker::CharacterTicker(DynamicCharacter* dynamicCh, DynamicCharacterWithCam* dynaCam) : IdleObserver()
{
    m_DynamicCharacter = dynamicCh;
    m_DynaChWithCam = dynaCam;
    m_Timer.restart();
}
*/
CharacterTicker::CharacterTicker(DynamicCharacterWithCam* dynaCam) : IdleObserver()
{
    m_DynaChWithCam = dynaCam;
    m_Timer.restart();

    a = new QTimer();
}


void CharacterTicker::doIt()
{
    long long time = m_Timer.restart();
    // Flags sammeln in welche richtungen der Character gehen soll
    unsigned long long v_MoveFlagsDynCh = 0;
    KeyboardInput* keyIn = InputRegistry::getInstance().getKeyboardInput();

    

    // Für Charakter mit verfolgerkamera
    v_MoveFlagsDynCh = 0;
    // t f g h space zur steuerung, in dem Enum Movement flag stehen noch weitere bewegungen die der charakter machen
    // kann
    if (keyIn->isKeyPressed('w'))
    {
        v_MoveFlagsDynCh |= MovementFlag::Forward;
    }
    if (keyIn->isKeyPressed('a'))
    {
        v_MoveFlagsDynCh |= MovementFlag::TurnLeft;
    }
    if (keyIn->isKeyPressed('s'))
    {
        v_MoveFlagsDynCh |= MovementFlag::Backward;
    }
    if (keyIn->isKeyPressed('d'))
    {
        v_MoveFlagsDynCh |= MovementFlag::TurnRight;
    }
    //if (keyIn->isKeyPressed(Qt::Key_Space))
    //{
    //
    //        v_MoveFlagsDynCh |= MovementFlag::Jump;
    //
    //}
    // character in entsprechende richtungen bewegen
    m_DynaChWithCam->moveCharacter(time, v_MoveFlagsDynCh);
}




/*
void CharacterTicker::doIt()
{
    long long time = m_Timer.restart();
    // Flags sammeln in welche richtungen der Character gehen soll
    unsigned long long v_MoveFlagsDynCh = 0;
    KeyboardInput* keyIn = InputRegistry::getInstance().getKeyboardInput();

    // Bei i vorwärts, j links und l rechts
    if (keyIn->isKeyPressed('i'))
    {
        v_MoveFlagsDynCh |= MovementFlag::Forward;
    }
    if (keyIn->isKeyPressed('j'))
    {
        v_MoveFlagsDynCh |= MovementFlag::TurnLeft;
    }
    if (keyIn->isKeyPressed('l'))
    {
        v_MoveFlagsDynCh |= MovementFlag::TurnRight;
    }
    // character in die entsprechende richtung bewegen
    m_DynamicCharacter->moveCharacter(time, v_MoveFlagsDynCh);

    // Für Charakter mit verfolgerkamera
    v_MoveFlagsDynCh = 0;
    // t f g h space zur steuerung, in dem Enum Movement flag stehen noch weitere bewegungen die der charakter machen
    // kann
    if (keyIn->isKeyPressed('t'))
    {
        v_MoveFlagsDynCh |= MovementFlag::Forward;
    }
    if (keyIn->isKeyPressed('f'))
    {
        v_MoveFlagsDynCh |= MovementFlag::TurnLeft;
    }
    if (keyIn->isKeyPressed('g'))
    {
        v_MoveFlagsDynCh |= MovementFlag::Backward;
    }
    if (keyIn->isKeyPressed('h'))
    {
        v_MoveFlagsDynCh |= MovementFlag::TurnRight;
    }
    if (keyIn->isKeyPressed(Qt::Key_Space))
    {
        // momentan geht jump immer, vielleicht sollte man dort wo man springen soll einen trigger platzieren
        // und dann das movement flag setzen wenn man hineinläuft und den callback abarbeitet
        v_MoveFlagsDynCh |= MovementFlag::Jump;
    }
    // character in entsprechende richtungen bewegen
    m_DynaChWithCam->moveCharacter(time, v_MoveFlagsDynCh);
}
*/


