//
//  Ball.hpp
//  cc-lab-quiz
//
//  Created by chaearn on 11/16/17.
//

#ifndef Ball_hpp
#define Ball_hpp

#include <stdio.h>
#include "ofMain.h"

class Ball {
public:
    
    void setup(float _rad, ofColor _color);
    void update();
    void draw();
    
    ofColor color;
    float radius;
    float x,y;
    float dirX, dirY;
    
    int time;
};
#endif /* Ball_hpp */
