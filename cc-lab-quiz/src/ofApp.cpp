#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    
//    newBall.setup(r, colr);
//    numBall = 0;

//    for (int i=0; i<numBall; i++){
//        numBall++;
//        if (numBall <10) {
//            balls.push_back(newBall);
//        }
//
//    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for( int i =0; i< balls.size(); i++){
        balls[i].update();
        
    }
//    newBall.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255);
    for( int i =0; i< balls.size(); i++){
        balls[i].draw();
        
        if (balls[i].color.a < 10){
            balls.erase(balls.begin()+i);
        }
        
    }
//    newBall.draw();
//    ofSetColor(10, 101, 110);
//    ofDrawCircle(mouseX, mouseY, r);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    Ball newBall;
    r = ofRandom(20,60);
    colr.set(ofRandom(255), ofRandom(255), ofRandom(255));
    newBall.setup(r, colr);
    balls.push_back(newBall);
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
