//
//  test.h
//  
//
//  Created by Annie Wu on 7/3/16.
//
//

#ifndef test_h
#define test_h

#include "Arduino.h"
#include <stdio.h>


class Test
{
private:
    const static int _fingers[]; // holds ints for finger pins
    const static int _directions[]; // holds ints for direction pins
    const static int _fans[]; // holds ints for fan direction pins
public:
    Test();
    void off();
    void on();
    void useString(String input_);
    void useFan(int fanNumber_);
};


// to process incoming string
//String test = "1,5,1,1.8,0";
/*Thumb, 0101 = Down and Right activated, 1.8V*/


#endif /* main_hpp */
