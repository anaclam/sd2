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
    SMAS = smas;
}

int Activator::countSMAsOn()
{
    int smasOn=0;
    
    for (int i=0; i<SMAS.length(); i++)
    {
        if (SMAS[i] == '1') smasOn++;
    }
    return smasOn;
}

int Activator::switching()
{
    int timeToCompleteSwitching = 5000; //// this is const from config file ///GOTTA READ IN
    int numSmasOn = countSMAsOn();
    
    int timeForEachSMA = numSmasOn / timeToCompleteSwitching;
    
    return timeForEachSMA;
    //check booleans.
  ///  allSmasOff();
    // don't forget to set booealns
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
    // to actuate SMA bc of BJT
    
    // pass in full set of directions per finger
    
    int numberOfActivatedSMAs;
    
    for (int i=0; i<4 ; i++)
    {
        if (fingerString.charAt(i) == '1')
        {
            digitalWrite(directionPins[i], HIGH); //LOW
            digitalWrite(finger, LOW); //HIGH
            delay(delayTime-1);
            allSmasOff(); 
            delay(1);
            //delay(100); //To demo switching
        }
        else
        {
            digitalWrite(directionPins[i], LOW); //HIGH
            digitalWrite(finger, HIGH); //LOW
        }
    }
}

int Activator::getActivatedPins(int delayTime)
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
    
    
 /*   String thumb = SMAS.substring(0, 4);
    String index = SMAS.substring(4, 8);
    String middle= SMAS.substring(8, 12);
    String ring  = SMAS.substring(12, 16);
    String pinky = SMAS.substring(17);*/
    
    allSmasOff();
    
    activatePins(THUMB, thumb, delayTime);
    activatePins(INDEX, index, delayTime);
    activatePins(MIDDLE, middle, delayTime);
    activatePins(RING, ring, delayTime);
    activatePins(PINKY, pinky, delayTime);
    /*
    delay(delay); //// need switching
    allSmasOff(); */
}

void Activator::allSmasOff()
{
    for (int i=0; i<4; i++)
    {
        for (int j=0; j<5; j++)
        {
            digitalWrite(directionPins[i], LOW); // HIGH
            digitalWrite(fingerPins[j], HIGH); //LOW
        }
    }
}
