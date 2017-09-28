#include "ofApp.h"
#include "Mover.h"

//--------------------------------------------------------------
void ofApp::setup(){
    xpos = 20;
    ofBackground(255,237,231);
}

//--------------------------------------------------------------
void ofApp::update(){
    myMove.pos.x = 50;
    myMove.pos.y = 200;
    myMove.zenoToPoint(mouseX, mouseY);
    
    xpos += 2;
    if(ofGetWidth()<xpos){
        xpos = 5;           
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255,0,0);
    ofDrawRectangle((ofGetWidth()*0.5)-100, 500, 200, 20);
    myMove.draw();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
