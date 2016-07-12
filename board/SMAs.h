//
//  SMAs.h
//  
//
//  Created by Annie Wu on 7/11/16.
//
//

#ifndef SMAs_h
#define SMAs_h

#include <stdio.h>

class SMAs
{
public:
    const int SMA_COOLING_TIME;
    vector _SMA;
private:
    SMAs(vector SMAs_); //ZAIN can you also make sure the vector is in the right syntax or imports the right things? May need the arduino header file
    switching(); // zain: don't pass anything into this method.... just call _SMA and the SMA_COOLING_TIME;
}


#endif /* SMAs_h */
