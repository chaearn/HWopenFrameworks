//
//  Mover.h
//  wk03
//
//  Created by chaearn on 9/29/17.
//

#ifndef Mover_h
#define Mover_h

#include "ofMain.h"
#include "Mover.h"

class Mover {
public:
    
    Mover();
    
    void    draw();
    void    zenoToPoint(float catchX, float catchY);
    
    ofPoint        pos;
    float        catchUpSpeed;
    
    
};


#endif /* Mover_h */
