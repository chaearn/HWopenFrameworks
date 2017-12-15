//
//  Emoji.cpp
//  emmo_final
//
//  Created by chaearn on 12/14/17.
//

#include "Emoji.hpp"

Emoji::Emoji(){
    position.y = 50;
    velocity.x = 0;
    velocity.y = 20;
    acc.y = 10;
    size = (ofRandom(70,120));
    
}

void Emoji::setup(string emojiName){

    position.x = ofRandom(0, ofGetWidth()-70);
	emoji.load(emojiName + ".png");

}

void Emoji::update(){
    
    velocity += acc;
    position += velocity;
    
    if (position.y <= size) {
        position.y = size;
        velocity.y = -.7 * velocity.y;
    }
    else if (position.y >= ofGetHeight() - size) {
        position.y = ofGetHeight() - size;
        velocity.y = -.7 * velocity.y;
    }    
    
//cout << " pos " << position.y << " velocity " << velocity.y << " acc " << acc << endl;
    
//    velocity.y *= 0.99;
//    a.update();
//    a.allocate(size, size, OF_IMAGE_COLOR);
    
}

void Emoji::draw(){
    
    ofSetColor(255,255,255);
	emoji.draw(position, size, size);

    }
