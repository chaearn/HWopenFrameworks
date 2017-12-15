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
    
    anger.load("angry.png");
    disgust.load("disgust.png");
    fear.load("fear.png");
    joy.load("happy.png");
    null.load("null.png");
    sad.load("sad.png");
    surprise.load("surprise.png");
    
}

void Emoji::setup(){
    position.x = ofRandom(0, ofGetWidth()-size);
    
    
}

void Emoji::update(){
    
    
//    if( position.y < 0 || position.y >= 650){
//        velocity.y *= -1;
////        if (position.y > 650){
////        position.y = 650;
////        }
//    }
    
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
    
    
    
//    cout << " pos " << position.y << " velocity " << velocity.y << " acc " << acc << endl;
    
//    velocity.y *= 0.99;
//    a.update();
//    a.allocate(size, size, OF_IMAGE_COLOR);
    
}

void Emoji::draw(int a){
    
    if (a==0){
    ofSetColor(255, 200, 0);
    ofSetCircleResolution(255);
    ofDrawCircle((position) + (size*.5), 2);

    joy.draw(position, size, size);
    }
    
    if (a==1){
        ofSetColor(255, 200, 0);
        ofSetCircleResolution(255);
        ofDrawCircle((position) + (size*.5), 2);

        anger.draw(position, size, size);
    }
    
    if (a==5){
        ofSetColor(255, 200, 0);
        ofSetCircleResolution(255);
        ofDrawCircle((position) + (size*.5), 2);

        sad.draw(position, size, size);
    }
    
    if (a==6){
        ofSetColor(255, 200, 0);
        ofSetCircleResolution(255);
        ofDrawCircle((position) + (size*.5), (size*.5)-10);

        surprise.draw(position, size, size);
    }
    
//    if (a==1){
//        ofSetColor(255, 200, 0);
//        ofSetCircleResolution(255);
//        ofDrawCircle((position) + (size*.5), (size*.5)-10);
//
//        anger.draw(position, size, size);
//    }
//
    if (a==2){
        ofSetColor(255, 200, 0);
        ofSetCircleResolution(255);
        ofDrawCircle((position) + (size*.5), (size*.5)-10);

        disgust.draw(position, size, size);
    }

    if (a==3){
        ofSetColor(255, 200, 0);
        ofSetCircleResolution(255);
        ofDrawCircle((position) + (size*.5), (size*.5)-10);

        fear.draw(position, size, size);
    }

    if (a==4){
        ofSetColor(255, 200, 0);
        ofSetCircleResolution(255);
        ofDrawCircle((position) + (size*.5), (size*.5)-10);

        null.draw(position, size, size);
    }
//
//    if (a==5){
//        ofSetColor(255, 200, 0);
//        ofSetCircleResolution(255);
//        ofDrawCircle((position) + (size*.5), (size*.5)-10);
//
//        sad.draw(position, size, size);
//    }
//
//    if (a==6){
//        ofSetColor(255, 200, 0);
//        ofSetCircleResolution(255);
//        ofDrawCircle((position) + (size*.5), (size*.5)-10);
//
//        surprise.draw(position, size, size);
//    }
}
