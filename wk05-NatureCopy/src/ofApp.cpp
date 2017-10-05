#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(212,239,255);
}

//--------------------------------------------------------------
void ofApp::update(){
    add++;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(251,255,235);
//    ofSetColor(ofRandom(212), ofRandom(239), ofRandom(255));
    
    
    ofBeginShape();
    for (int i = 0; i < 100; i++){
        add = ofNoise(sin((i/100.0)*TWO_PI), (float)30/ofGetElapsedTimef()+ofGetMouseY());  // symetrical
//        add = ofNoise(i/7.0f, ofGetElapsedTimef() * 3 * (float)mouseX / (float)ofGetWidth());
        ofVertex( (ofGetMouseX() + (200 + 100 * add) * cos((i/100.0)*TWO_PI))-ofNoise(300),
                 (ofGetMouseY()+ (200 + 100 * add) * sin((i/100.0)*TWO_PI))-ofNoise(300) );
        
    }
    ofEndShape();
    
    
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
