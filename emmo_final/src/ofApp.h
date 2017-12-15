#pragma once

#include "ofMain.h"
#include "ofxHttpUtils.h"
#include "ofxJSON.h"
#include "Emoji.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
        void newResponse(ofxHttpResponse & response);
    
    ofxHttpUtils httpUtils;
    int counter;
    string responseStr;
    string requestStr;
    string action_url;
    
    ofVideoGrabber vidGrabber;
    ofPixels videoInverted;
    ofTexture videoTexture;
    int camWidth;
    int camHeight;
    
    ofImage myImage;
    ofImage savedImage;
    bool saveImage;
    bool pushButton;
    
    ofTexture mirrorTexture;
    unsigned char * videoMirror;
    unsigned char * pixels;

    ofxJSONElement json;
    
    vector<float> emotions;
    ofImage anger, disgust, fear, joy, null, sad, surprise;
    float Anger, Disgust, Fear, Joy, Neutral, Sadness, Surprise;
    float max;
    
    int icon;
    vector<Emoji> emojii;
    
    ofTrueTypeFont myfont;
    ofTrueTypeFont myfontBig;

    int fontsize;
};
