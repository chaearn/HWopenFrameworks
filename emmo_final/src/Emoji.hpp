//
//  Emoji.hpp
//  emmo_final
//
//  Created by chaearn on 12/14/17.
//

#pragma once
#include "ofMain.h"

class Emoji {
public:
    Emoji();
    void setup();
    void update();
    void draw(int a);
    
    ofVec2f position;
    ofVec2f velocity;
    ofVec2f acc;
    ofImage emoji;
    float size;
    
private:
    ofImage anger, disgust, fear, joy, null, sad, surprise;
};
