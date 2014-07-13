#include "ofApp.h"
#include "Compressor.h"
#include <vector>

//--------------------------------------------------------------
void ofApp::setup(){

	ofSetOrientation(OF_ORIENTATION_90_LEFT);
    
    nImages = DIR.listDir("images/of_logos/");

    std::vector<std::string> vec;
    for(int i = 0; i < nImages; i++){
        vec.push_back(DIR.getPath(i));
    }
    
    compressor = new Compressor(vec);

    ofBackground(255,255,255);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetHexColor(0xffffff);
    ofImage *img = compressor->getOutputImg();
    img->draw(0,0,Compressor::outputWidth,Compressor::outputHeight);
    
}

//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::touchDown(ofTouchEventArgs & touch){

}

//--------------------------------------------------------------
void ofApp::touchMoved(ofTouchEventArgs & touch){

}

//--------------------------------------------------------------
void ofApp::touchUp(ofTouchEventArgs & touch){

}

//--------------------------------------------------------------
void ofApp::touchDoubleTap(ofTouchEventArgs & touch){

}

//--------------------------------------------------------------
void ofApp::touchCancelled(ofTouchEventArgs & touch){
    
}

//--------------------------------------------------------------
void ofApp::lostFocus(){

}

//--------------------------------------------------------------
void ofApp::gotFocus(){

}

//--------------------------------------------------------------
void ofApp::gotMemoryWarning(){

}

//--------------------------------------------------------------
void ofApp::deviceOrientationChanged(int newOrientation){

}
