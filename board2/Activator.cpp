//
//  Activator.cpp
//  
//
//  Created by Annie Wu on 7/16/16.
//
//

#include "Activator.h"

Activator::Activator(String smas)
{
    SMAS = smas; // Stores the constructor argument in the object

    Config set;
    directionPins[0] = set.up;
    directionPins[1] = set.down;
    directionPins[2] = set.left;
    directionPins[3] = set.right;
    
    fingerPins[0] = set.thumb;
    fingerPins[1] = set.index;
    fingerPins[2] = set.middle;
    fingerPins[3] = set.ring;
    fingerPins[4] = set.pinky;
   
    inverted = set.inverted;
    timeToCompleteSwitching = set.timeToCompleteSwitching;
    
    if (inverted)
    {
      on = '0';
      off = '1';
    }
    else
    {
      on = '1';
      off = '0';
    }
}

int Activator::countSMAsOn() // counts number of SMAS for switching method
{
    int smasOn=0;
    
    for (int i=0; i<SMAS.length(); i++)
    {
        if (SMAS[i] == on) smasOn++;
    }
    return smasOn;
}

int Activator::switching() // switches quickly between each SMA so that residual heat 
                           // does not allow SMA to expand but is able to power one wire at a time
{
    int numSmasOn = countSMAsOn();
    
    int timeForEachSMA = timeToCompleteSwitching/numSmasOn;
    
    return timeForEachSMA;
}

void Activator::activate()
{
    getActivatedPins(switching());
}

void Activator::activatePins(int finger, String fingerString, int delayTime)
// for each in array, calls sma translator and activates that sma
{
    // Need Fingers set to HIGH
    //      Direction set to LOW
    // to actuate SMA bc of transistor
    // For LED demo, fingers would be set to LOW and direction to HIGH for activation
    int numberOfActivatedSMAs;
    
    for (int i=0; i<4 ; i++)
    {
        if (fingerString.charAt(i) == on)
        {
            /*if (inverted)
            {
              digitalWrite(directionPins[i], LOW); 
              digitalWrite(finger, HIGH);
            }
            else
            {*/
              digitalWrite(directionPins[i], HIGH); 
              digitalWrite(finger, LOW); 
            //}
            if (!inverted) delay(delayTime);
            allSmasOff(); // This can be removed but works as a safety to ensure no current leakage.
        }
        else if (fingerString.charAt(i) == off)
        {
            /*if (inverted)
            {
              digitalWrite(directionPins[i], HIGH);
              digitalWrite(finger, LOW);
            }
            else
            {*/
              digitalWrite(directionPins[i], LOW); // For SMA, would be HIGH
              digitalWrite(finger, HIGH); // For SMA, would be LOW
              if (inverted) delay(delayTime);
            //}
            allSmasOff();
        }
    }
}

int Activator::getActivatedPins(int delayTime) // parses out SMA string and calls to activate pins
{
  
    // split sma info
    int spaceT = SMAS.indexOf(' ');
    int spaceI = SMAS.indexOf(' ', spaceT+1);
    int spaceM = SMAS.indexOf(' ', spaceI+1);
    int spaceR = SMAS.indexOf(' ', spaceM+1);
    
    String thumb = SMAS.substring(0, spaceT);
    String index = SMAS.substring(spaceT+1, spaceI);
    String middle= SMAS.substring(spaceI+1, spaceM);
    String ring  = SMAS.substring(spaceM+1, spaceR);
    String pinky = SMAS.substring(spaceR+1);
    
    //allSmasOff();
    
    activatePins(fingerPins[0], thumb, delayTime);
    activatePins(fingerPins[1], index, delayTime);
    activatePins(fingerPins[2], middle, delayTime);
    activatePins(fingerPins[3], ring, delayTime);
    activatePins(fingerPins[4], pinky, delayTime);
}

void Activator::allSmasOff() // turns all smas off
{
   /* if (inverted)
    {
      PORTD=PORTD | B11110000;
      PORTB=PORTB | B00011111;
    }
    else
    {
      PORTD=PORTD | B00000000;
      PORTB=PORTB | B00000000;
    }*/
    for (int j=0; j<5; j++)
    {
        for (int i=0; i<4; i++)
        {
            if (inverted)
            {
              digitalWrite(directionPins[i], HIGH); 
              digitalWrite(fingerPins[j], LOW);
            }
            else
            {
              digitalWrite(directionPins[i], LOW); // For SMA, would be HIGH
              digitalWrite(fingerPins[j], HIGH); // For SMA, would be LOW
            }
        }
    }
}
