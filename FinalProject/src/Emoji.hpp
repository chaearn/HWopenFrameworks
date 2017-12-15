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
    void setup(string emojiName);
    void update();
    void draw();
    
    ofVec2f position;
    ofVec2f velocity;
    ofVec2f acc;
    ofImage emoji;
    float size;
    
};
