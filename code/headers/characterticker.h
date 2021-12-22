#ifndef CHARACTERTICKER_H
#define CHARACTERTICKER_H

#include "idleobserver.h"
#include "physics.h"
#include <QElapsedTimer>
#include <qtimer.h>

// Klasse um unsere beiden Charaktere zu steuern
class CharacterTicker : public IdleObserver
{
public:
    //CharacterTicker(DynamicCharacter* dynamicCh, DynamicCharacterWithCam* dynaCam);

    CharacterTicker(DynamicCharacterWithCam* dynaCam);
    void doIt();

private:
    //DynamicCharacter* m_DynamicCharacter;

    DynamicCharacterWithCam* m_DynaChWithCam;
    // Timer für genaue Delta Zeitberechnung
    QElapsedTimer m_Timer;
    QTimer* a;
  
};

#endif // CHARACTERTICKER_H
