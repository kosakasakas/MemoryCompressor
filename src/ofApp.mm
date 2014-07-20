#include "ofApp.h"
#include "Compressor.h"
#include "MovieCompressor.h"
#include "ImageCompressor.h"
#include <vector>

//--------------------------------------------------------------
void ofApp::setup(){

	ofSetOrientation(OF_ORIENTATION_90_LEFT);
    
    nImages = DIR.listDir("images/of_logos/");
    std::vector<std::string> imageVec;
    for(int i = 0; i < nImages; i++){
        imageVec.push_back(DIR.getPath(i));
    }
    
    std::vector<std::string> movieVec;
    movieVec.push_back("movie/sample/hands.m4v");
    
    compressor = new MovieCompressor(movieVec);
    //compressor = new ImageCompressor(imageVec);
    compressor->setup();

    ofBackground(255,255,255);
}

//--------------------------------------------------------------
void ofApp::update(){
    compressor->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    compressor->getOutputImg()->draw(0, 0);
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
