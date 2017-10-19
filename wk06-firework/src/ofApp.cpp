#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
//    gravity = ofVec2f(0,.25);
    gravity = ofVec2f(0,ofRandom(1));
    
    lastUpdateTime = ofGetElapsedTimef();
}

//--------------------------------------------------------------
void ofApp::update(){
    // time elapsed since last frame
    float timeDiff = ofGetElapsedTimef() - lastUpdateTime;
    
    // update the particle systems
    
    for (int i=0; i<systems.size(); i++)
    {
        systems[i].update(gravity, timeDiff);    // update
    }
    
    lastUpdateTime = ofGetElapsedTimef();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackgroundGradient(ofColor(0, 100, 100), ofColor(100, 0, 100));
    
    for (int i=0; i<systems.size(); i++)
    {
        systems[i].draw();
    }
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
systems.push_back( ParticleSystem(ofVec2f(x,y)) );    // construct new particle system
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
