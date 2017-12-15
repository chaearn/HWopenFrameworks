//
//  Ball.cpp
//  cc-lab-quiz
//
//  Created by chaearn on 11/16/17.
//

#include "Ball.hpp"

void Ball::setup(float _rad, ofColor _color){
    
    radius = _rad;
    color = _color;
    
    x =ofRandom(0, ofGetWidth());
    y =ofRandom(0, ofGetHeight());
    
    dirX = 5;
    dirY = 5;
    
}

void Ball::update(){
    
    time++;
    
    x+=dirX;
    y+=dirY;
    
    
    if (x >= ofGetWidth()-radius || x<=radius){
        dirX *=-1;
    }
    
    if (y >= ofGetHeight()-radius || y<=radius){
        dirY *= -1;
    }
    
    color.a = ofMap(time, 0, 500, 255, 0);
}

void Ball::draw(){
    
    ofSetColor(color);
    ofSetCircleResolution(255);
    ofDrawCircle(x, y, radius);
    
}
