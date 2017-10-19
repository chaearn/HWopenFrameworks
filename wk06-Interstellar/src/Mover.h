//
//  Mover.h
//  wk06-Interstellar
//
//  Created by chaearn on 10/9/17.
//

//#ifndef Mover_h
//#define Mover_h
#pragma once
#include "ofMain.h"

class Mover {
    
public:
    
    Mover();
    ~Mover(){}
    
    Mover(ofVec3f _pos, float _mass);
    
    void applyForce(ofVec3f force);
    void applyDampingForce(float force);
    void checkEdges(); // keep Mover on screen
    
    void update();
    void draw();
    void keyPressed(int key);
    
    
    ofVec3f pos, vel, acc;
    float mass;
    
};

//#endif /* Mover_h */

