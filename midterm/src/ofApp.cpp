#include "ofApp.h"

const int nMovers = 1000;


//--------------------------------------------------------------
void ofApp::setup(){
    
    camWidth  = 320;
    camHeight = 240;

//	#ifdef _USE_LIVE_VIDEO
        vidGrabber.setVerbose(true);
        vidGrabber.setup(0,0);
  
//    #else
//        vidPlayer.load("fingers.mov");
//        vidPlayer.play();
//        vidPlayer.setLoopState(OF_LOOP_NORMAL);
//	#endif
    
    videoMirror = new unsigned char[camWidth*camHeight*3];
    mirrorTexture.allocate(camWidth, camHeight, GL_RGB);
    
    colorImg.allocate(camWidth,camHeight);
	grayImage.allocate(camWidth,camHeight);
	grayBg.allocate(camWidth,camHeight);
	grayDiff.allocate(camWidth,camHeight);

	bLearnBakground = true;
	threshold = 30;
    
    //Mover
    for(int i = 0 ; i < nMovers;i++)
    {
        Movers.push_back(Mover());
    }
    


}

//--------------------------------------------------------------
void ofApp::update(){
//    ofBackground(100,100,100);

    bool bNewFrame = false;

	#ifdef _USE_LIVE_VIDEO
       vidGrabber.update();
	   bNewFrame = vidGrabber.isFrameNew();
    #else
        vidPlayer.update();
        bNewFrame = vidPlayer.isFrameNew();
	#endif

	if (bNewFrame){

		#ifdef _USE_LIVE_VIDEO
            colorImg.setFromPixels(vidGrabber.getPixels());
	    #else
            colorImg.setFromPixels(vidPlayer.getPixels());
        #endif
        
        pixels = vidGrabber.getPixels().getData();
        
        for (int i = 0; i < camHeight; i++) {
            for (int j = 0; j < camWidth*3; j+=3) {
                
                // pixel number
                int pix1 = (i*camWidth*3) + j;
                int pix2 = (i*camWidth*3) + (j+1);
                int pix3 = (i*camWidth*3) + (j+2);
                
                // mirror pixel number
                int mir1 = (i*camWidth*3)+1 * (camWidth*3 - j-3);
                int mir2 = (i*camWidth*3)+1 * (camWidth*3 - j-2);
                int mir3 = (i*camWidth*3)+1 * (camWidth*3 - j-1);
                
                videoMirror[pix1] = pixels[mir1];
                videoMirror[pix2] = pixels[mir2];
                videoMirror[pix3] = pixels[mir3];
            
            }
        }
        
//        mirrorTexture.loadData(videoMirror, camWidth, camHeight, GL_RGB);
        
        colorImg.setFromPixels(videoMirror, camWidth, camHeight);
        
        grayImage = colorImg;
		if (bLearnBakground == true){
			grayBg = grayImage;		// the = sign copys the pixels from grayImage into grayBg (operator overloading)
			bLearnBakground = false;
		}

		// take the abs value of the difference between background and incoming and then threshold:
		grayDiff.absDiff(grayBg, grayImage);
		grayDiff.threshold(threshold);

		// find contours which are between the size of 20 pixels and 1/3 the w*h pixels.
		// also, find holes is set to true so we will get interior contours as well....
		contourFinder.findContours(grayDiff, 20, (camWidth*camHeight)/3, 10, true);	// find holes
	}
    
    //Attractors
    Att.clear();
    
    float scaleX = 1024.0/float(camWidth);
    float scaleY = 768.0/float(camHeight);
    
    
    for(int i = 0; i < contourFinder.blobs.size();i++)
    {
        
        ofVec2f blobCenter = contourFinder.blobs[i].centroid;
        blobCenter.x *= scaleX;
        blobCenter.y *= scaleY;
        
        Attractor att;
        ofVec3f iniPos;
        iniPos.x = blobCenter.x;
        iniPos.y = blobCenter.y;
        iniPos.z = 0;
        
        att.pos = iniPos;
        att.mass = ofRandom(3., 12.);
        
        Att.push_back(att);
    }
    
    //Movers
    // apply attractors' gravity forces on movers
    for (int a=0; a<contourFinder.blobs.size(); a++)
    {
        for (int m=0; m<nMovers; m++)
        {
            //calculate distance
            float Distance = ofDist(Movers[m].pos.x,Movers[m].pos.y,Att[a].pos.x,Att[a].pos.y);
            
            // calculate force
            ofVec3f force = Att[a].getForce(Movers[m]);
            // apply force
            
            
//            if(Movers[m].pos.x > 1024)
//            {
//            cout << "Value : " << Movers[m].pos << endl;
//            }
            
//            if(Movers[m].pos.y<=0 || Movers[m].pos.y>=768){
//                Movers[m].vel *= -1;
//            }
            
            if(Distance > 65)
            {
                Movers[m].applyForce(force);
            }
            else
            {
                Movers[m].applyDampingForce(0.9);
            }
            
            
        }
    }

    // update movers
    for (int m=0; m<nMovers; m++)
    {
        Movers[m].update();
        
        if(Movers[m].pos.x<=10. || Movers[m].pos.x >= 1024. || Movers[m].pos.y<=10. || Movers[m].pos.y>= 768.){
            Movers[m].vel *= -1;
        }
    }


    
}

//--------------------------------------------------------------
void ofApp::draw(){

	// draw the incoming, the grayscale, the bg and the thresholded difference
	ofSetHexColor(0xffffff);
//    colorImg.draw(0,0,1024,768);
//	grayImage.draw(360,20);
//	grayBg.draw(20,280);
//	grayDiff.draw(360,280);

	// then draw the contours:

	ofFill();
	ofSetColor(27,28,40);
    ofDrawRectangle(0,0,1024,768);
//	ofSetHexColor(0xffffff);

//    we could draw the whole contour finder
//    contourFinder.draw(0,0,1024,768);
    
    ///////////////////////
    /////////MOVERS////////
    ///////////////////////
    

    for( int i = 0; i < nMovers;i++)
    {
        Movers[i].draw();
    }
    
    
    ///////////////////////
    //////ATTRACTORS///////
    ///////////////////////
    
    
    for(int i = 0; i < contourFinder.blobs.size(); i++)
    {
        Att[i].draw();
    }
        
    
//    att.pos = initialPos;
//    att.mass = 15.0;
//
//    att.draw();
    
//    for (int i=0; i<contourFinder.blobs.size(); i++){
//        ofVec2f blobCenter = contourFinder.blobs[i].centroid;
//        blobCenter.x *= scaleX;
//        blobCenter.y *= scaleY;
//        ofSetColor(255);
//        ofDrawCircle(blobCenter, 5);
//
//
//    }

	// or, instead we can draw each blob individually from the blobs vector,
	// this is how to get access to them:
//    for (int i = 0; i < contourFinder.nBlobs; i++){
//        colorImg.draw(0,0);
//        contourFinder.blobs[i].draw(0,0);
//
//         //draw over the centroid if the blob is a hole
//        ofSetColor(255);
//        if(contourFinder.blobs[i].hole){
//            ofDrawBitmapString("hole",
//                contourFinder.blobs[i].boundingRect.getCenter().x + 1024,
//                contourFinder.blobs[i].boundingRect.getCenter().y + 768);
//        }
//    }
//    mirrorTexture.draw(camWidth, 0, camWidth, camHeight);
    
    

	// finally, a report:
	ofSetHexColor(0xffffff);
	stringstream reportStr;
	reportStr << "bg subtraction and blob detection" << endl
			  << "press ' ' to capture bg" << endl
			  << "threshold " << threshold << " (press: +/-)" << endl
			  << "num blobs found " << contourFinder.nBlobs << ", fps: " << ofGetFrameRate();
	ofDrawBitmapString(reportStr.str(), 20, 700);
    
    //mover
    

}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	switch (key){
		case ' ':
			bLearnBakground = true;
			break;
		case '+':
			threshold ++;
			if (threshold > 255) threshold = 255;
			break;
		case '-':
			threshold --;
			if (threshold < 0) threshold = 0;
			break;
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
