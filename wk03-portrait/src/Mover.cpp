//
//  Mover.cpp
//  wk03
//
//  Created by chaearn on 9/29/17.
//

#include <stdio.h>
#include "Mover.h"

Mover::Mover(){
    catchUpSpeed = 0.01f;
}

void Mover::draw() {
    ofSetColor(0);  // draw everything in red
    ofDrawCircle(pos.x+100, pos.y, 30);
    ofSetColor(0);  // draw everything in red
    ofDrawCircle(1024-pos.x-100, pos.y, 30);
    
}

void Mover::zenoToPoint(float catchX, float catchY){
    pos.x = catchUpSpeed * catchX + (1-catchUpSpeed) * pos.x;
    pos.y = catchUpSpeed * catchY + (1-catchUpSpeed) * pos.y;
}

