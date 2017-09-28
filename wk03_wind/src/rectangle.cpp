#include "rectangle.h"


//------------------------------------------------------------------
rectangle::rectangle(){
	catchUpSpeed = 0.01f;
}

//------------------------------------------------------------------
void rectangle::draw() {
	ofFill();
	ofSetRectMode(OF_RECTMODE_CENTER); // center around the position
    ofSetColor(197,180,184);
    ofRect(pos.x, pos.y, ofRandom(20,80),ofRandom(20,80));
    ofRect(pos.x+ofRandom(20,80), pos.y+ofRandom(20,80), ofRandom(20,80),ofRandom(20,80));
    ofRect(pos.x+ofRandom(20,80), pos.y+ofRandom(20,80), ofRandom(20,80),ofRandom(20,80));
    ofRect(pos.x+ofRandom(20,80), pos.y+ofRandom(20,80), ofRandom(20,80),ofRandom(20,80));
}

//------------------------------------------------------------------
void rectangle::zenoToPoint(float catchX, float catchY){
	pos.x = catchUpSpeed * catchX + (1-catchUpSpeed) * pos.x; 
	pos.y = catchUpSpeed * catchY + (1-catchUpSpeed) * pos.y; 
}
