//
//  Mover.cpp
//  wk06-Interstellar
//
//  Created by chaearn on 10/9/17.
//

//#include <stdio.h>
#include "Mover.h"

Mover::Mover()
{
    pos.set(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
    
    mass = ofRandom(0.,1.);
}

Mover::Mover(ofVec3f _pos, float _mass){
    pos = _pos;
    mass = _mass;
}

void Mover::applyForce(ofVec3f force)
{
    // force = mass * acceleration
    // acc = force / mass
    
    acc += force*mass/2;
}

void Mover::applyDampingForce(float force)
{
    acc -= vel.getNormalized() * force;
    
}

void Mover::checkEdges() {
    // keep mover on screen
    
    if (pos.x < 0) {
        pos.x = 0;
        vel.x *= -1;
    }
    
    if (pos.x > ofGetWidth()) {
        pos.x = ofGetWidth();
        vel.x *= -1;
    }
    
    if (pos.y < 0) {
        pos.y = 0;
        vel.y *= -1;
    }
    
    if (pos.y > ofGetHeight()) {
        pos.y = ofGetHeight();
        vel.y *= -1;
    }
}

void Mover::update()
{
    vel += acc;
    pos += vel;
    
    acc *= 0;
}

void Mover::draw()
{
    ofPushMatrix();
    ofTranslate(pos);
    
    ofPushStyle();
    
    // interpolate between colors!
    ofColor cSlow    = ofColor::fromHex(0xC1D5FF);    // hex format: 0xRRGGBB
    ofColor cFast    = ofColor::fromHex(0xFF4831);
    
    float pct        = ofMap(vel.length(), 0., 7., 0., 1., true);    // mix based on speed
    ofColor cMix        = cSlow.lerp(cFast, pct);    // "lerp" == interpolate
    
    ofSetColor(cMix);
    
    ofDrawCircle(0,0, mass);
    
    ofPopStyle();
    
    ofPopMatrix();
}

void Mover::keyPressed(int key){
    if (key == OF_KEY_UP){
        mass += 0.1;
    }
    if (key == OF_KEY_DOWN){
        mass -=0.1;
    }}

