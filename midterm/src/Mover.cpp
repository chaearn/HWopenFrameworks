//
//  Mover.cpp
//  Attraction
//
//  Created by Tyler on 10/5/17.
//
//

#include "Mover.hpp"

Mover::Mover()
{
	pos.x = ofRandom(ofGetWidth());
	pos.y = ofRandom(ofGetHeight());
	
	mass = ofRandom(2,40);
}

Mover::Mover(ofVec3f _pos, float _mass){
	pos = _pos;
	mass = _mass;
}

void Mover::applyForce(ofVec3f force)
{
	// force = mass * acceleration
	// acc = force / mass
	
    acc += force/mass*1.5;
//    acc += force;
}

void Mover::applyDampingForce(float force)
{
	acc -= vel.getNormalized() * force;
	// we use a "normalized" velocity (i.e. magnitude of 1)
	// because damping force should be constant
	// no matter what our velocity's magnitude (speed)
	
}

void Mover::update()
{
	vel += acc;
	pos += vel;
	
	acc *= 0;
}

void Mover::draw()
{
	ofPushStyle();
	float hue = ofMap(mass, 1, 10, 100, 150);
	ofSetColor( ofColor::fromHsb(hue, hue, 250) );
	
//    ofDrawLine(pos, pos+2);
//    ofDrawRectangle(pos, mass, mass);
    ofDrawCircle(pos, mass);
	
	ofPopStyle();
}





