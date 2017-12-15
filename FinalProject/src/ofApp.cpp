#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    myfont.load("Montserrat-Regular.ttf", 10);
    myfontBig.load("Montserrat-Regular.ttf", 30);
    
    /////////// CAMERA ////////////
    
    camWidth = 1280;  // try to grab at this size.
    camHeight = 720;
    
    //we can now get back a list of devices.
    vector<ofVideoDevice> devices = vidGrabber.listDevices();
    
    for(int i = 0; i < devices.size(); i++){
        if(devices[i].bAvailable){
            ofLogNotice() << devices[i].id << ": " << devices[i].deviceName;
        }else{
            ofLogNotice() << devices[i].id << ": " << devices[i].deviceName << " - unavailable ";
        }
    }
    
    vidGrabber.setDeviceID(1);
    vidGrabber.setDesiredFrameRate(60);
    vidGrabber.initGrabber(camWidth, camHeight);
    
    videoMirror = new unsigned char[camWidth*camHeight];
    mirrorTexture.allocate(camWidth, camHeight, GL_RGB);
    
    videoInverted.allocate(camWidth, camHeight, OF_PIXELS_RGB);
    videoTexture.allocate(videoInverted);
    ofSetVerticalSync(true);
    
    /////////// API ////////////
    
    action_url = "https://eyeris-emovu1.p.mashape.com/api/image/";
    ofAddListener(httpUtils.newResponseEvent,this,&ofApp::newResponse);
    httpUtils.start();
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    /////////// CAMERA ////////////
    
    vidGrabber.update();
    
    if(vidGrabber.isFrameNew()){
        ofPixels & pixels = vidGrabber.getPixels();
        for(int i = 0; i < pixels.size(); i++){
            videoInverted[i] = 255 - pixels[i];
        }
        videoTexture.loadData(videoInverted);
    }
    
    //    for (int i = 0; i < emojii.size(); i++){
    //        emojii[i].update();
    //    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    /////////// CAMERA ////////////
    
    ofSetHexColor(0xffffff);
    vidGrabber.draw(0, 0);
    videoTexture.draw(camWidth, 0, camWidth, camHeight);
    //joy.draw(0,0);
    /////////// API ////////////
    
    
    ofSetColor(100);
    myfont.drawString("press spacebar to send me a face", 15, 20);
    
//    ofDrawBitmapString(requestStr,20,20);
    //    ofDrawBitmapString(responseStr,20,60);
    //    ofDrawBitmapString(json.getRawString(true), 20, 60);
    
    for (Json::ArrayIndex i = 0; i < json["FaceAnalysisResults"].size(); ++i)
    {
        Anger = json["FaceAnalysisResults"][i]["EmotionResult"]["Anger"].asFloat();
        Disgust = json["FaceAnalysisResults"][i]["EmotionResult"]["Disgust"].asFloat();
        Fear = json["FaceAnalysisResults"][i]["EmotionResult"]["Fear"].asFloat();
        Joy = json["FaceAnalysisResults"][i]["EmotionResult"]["Joy"].asFloat();
        Neutral = json["FaceAnalysisResults"][i]["EmotionResult"]["Neutral"].asFloat();
        Sadness = json["FaceAnalysisResults"][i]["EmotionResult"]["Sadness"].asFloat();
        Surprise = json["FaceAnalysisResults"][i]["EmotionResult"]["Surprise"].asFloat();
        
        std::string people = ofToString(emojii.size()) + " faces";
        std::string angerV   = "Anger : " + ofToString(Anger);
        std::string disgustV   = "Disgust : " + ofToString(Disgust);
        std::string fearV   = "Fear : " + ofToString(Fear);
        std::string joyV   = "Joy : " + ofToString(Joy);
        std::string neutralV   = "Neutral : " + ofToString(Neutral);
        std::string sadnessV   = "Sadness : " + ofToString(Sadness);
        std::string surpriseV   = "Surprise : " + ofToString(Surprise);
        
        ofSetColor(0, 30);
        ofDrawRectangle(10,30, 400/3, 170);
        
        ofSetColor(255);
        myfont.drawString(people, 20, 50);
        myfont.drawString(angerV, 20, 70);
        myfont.drawString(disgustV, 20, 90);
        myfont.drawString(fearV, 20, 110);
        myfont.drawString(joyV, 20, 130);
        myfont.drawString(neutralV, 20, 150);
        myfont.drawString(sadnessV, 20, 170);
        myfont.drawString(surpriseV, 20, 190);
        
        if (hasData)
        {
            hasData = false;
            isAnalyze = true;
        }
    }
    
    if (isAnalyze)
    {
        isAnalyze = false;
        
        string EmoResult = "You are a robot";
        //cout << "OK" << endl;
        emotions.clear();
        
        emotions.push_back(Anger);
        emotions.push_back(Disgust);
        emotions.push_back(Fear);
        emotions.push_back(Joy);
        emotions.push_back(Neutral);
        emotions.push_back(Sadness);
        emotions.push_back(Surprise);
        
        
        
        //for(int i=0; i<emotions.size(); i++)
        //{
        //if (max - emotions[i+1]<0)
        //    {
        //        max = emotions[i+1];
        //    }
        //}
        
        //sorting
        for (int i = 0; i < emotions.size(); i++)
        {
            for (int j = 0; j < emotions.size() - 1; j++)
            {
                if (emotions[j] < emotions[j + 1])
                {
                    float A, B;
                    A = emotions[j];
                    B = emotions[j + 1];
                    
                    emotions[j] = B;
                    emotions[j + 1] = A;
                }
            }
        }
        
        max = emotions[0];
        
        
        
        if (max == Joy) {
            EmoResult = "happy";
            icon = 0;
            response = "Glad to see a happy face!";
        }
        
        if (max == Anger) {
            EmoResult = "angry";
            icon = 1;
            response = "Calm down!";
        }
        
        if (max == Disgust) {
            EmoResult = "disgust";
            icon = 2;
            response = "What a face!";
        }
        
        if (max == Fear) {
            EmoResult = "fear";
            icon = 3;
            response = "Are you scared of something?";
        }
        
        if (max == Neutral) {
            EmoResult = "null";
            icon = 4;
            response = "I don't want this face. I want a smile!";
        }
        
        if (max == Sadness) {
            EmoResult = "sad";
            icon = 5;
            response = "Don't be so sad.";
        }
        
        if (max == Surprise) {
            EmoResult = "surprise";
            icon = 6;
            response = "Hahahaha I like this expression!";
        }
        
        cout << EmoResult << endl;
        
        //Create Emotion
        Emoji emj;
        emj.setup(EmoResult);
        emojii.push_back(emj);
        
    }
    
    
    
    for (int i = 0; i < emojii.size(); i++){
        emojii[i].update();
        emojii[i].draw();
    }
    
    //        cout << max << icon << endl;
    
    //        nowEmoji = MAX(Anger, Disgust);
    //        cout << nowEmoji << endl;
    
    if(response != ""){
    ofSetColor(0, 200, 255);
    myfontBig.drawString(response, 20, 250);
        
        
        if(count <= 80){
            count++;
            if (count==80){
                response = "";
                count = 0;
            }
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    /////////// CAMERA ////////////
    
    if(key == 's' || key == 'S'){
        vidGrabber.videoSettings();
    }
    
    if(key ==' '){
        myImage.grabScreen(0, 0, 1280, 720);
        myImage.save("myFace/myFace.jpg", OF_IMAGE_QUALITY_HIGH);
        pushButton = true;
        //Emoji temp;
        //temp.setup();
        //emojii.push_back(temp);
    }
    
    /////////// API ////////////
    
    ofxHttpForm form;
    form.action = action_url;
    form.addHeaderField("Content-Type","application/json");
    form.method = OFX_HTTP_POST;
    form.addHeaderField("X-Mashape-Key","2DZaeAhs1hmshe23tLOuDJTIK1flp1dEfiKjsnIaUxZ0yKV7Qy");
    form.addFile("imageFile", "myFace/myFace.jpg");
    form.addFormField("type","POST");
    httpUtils.addForm(form);
    requestStr = "message sent";
    
    
    
}

//--------------------------------------------------------------
void ofApp::newResponse(ofxHttpResponse & response){
    
    responseStr = (string)response.responseBody;
    json.parse(responseStr);
    json.save("emmo.json");
    
    std::string file = "emmo.json";
    
    // Now parse the JSON
    bool parsingSuccessful = json.open(file);
    
    if (parsingSuccessful)
    {
        hasData = true;
        //        ofLogNotice("ofApp::setup") << json.getRawString(true);
        //        string emotion = json["FaceAnalysisResult"]["EmotionResult"]["Joy"].asString();
        
        //        cout << "emotion: " << emotion << endl;
        
        //        ofLogNotice("Emotion") << emotion;
        
    } else {
        ofLogNotice("ofApp::setup") << "Failed to parse JSON.";
    }
    
    
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

