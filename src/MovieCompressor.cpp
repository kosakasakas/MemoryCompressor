//
//  MovieCompressor.cpp
//  MemoryCompressor
//
//  Created by 小坂 昂大 on 2014/07/13.
//
//

#include "MovieCompressor.h"

MovieCompressor::MovieCompressor(std::vector<std::string> paths)
: Compressor(paths)
, video(NULL)
{
}

MovieCompressor::~MovieCompressor() {
    delete video;
}

void MovieCompressor::setOutputImage() {
    if (outputImg == NULL || video == NULL || !video->isLoaded()) {
        return;
    }
    
    if (outputWidth <= renderingFrame) {
        outputImg->draw(0, 0);
        return;
    }
    
    int frameNum = video->getTotalNumFrames();
    int frameSampleNum = (frameNum > outputWidth) ? frameNum/(outputWidth - 1) : 1;
    int fragmentWidth = (frameNum > outputWidth) ? 1 : outputWidth / frameNum;
    video->setFrame(renderingFrame*frameSampleNum);
    ofImage *image = new ofImage();
    image->setFromPixels(video->getPixels(), video->getWidth(), video->getHeight(), OF_IMAGE_COLOR);
    image->resize(fragmentWidth, outputHeight);
    unsigned char* inputPixels = image->getPixels();
    unsigned char * outputPixels = outputImg->getPixels();
    for (int i = 0; i < fragmentWidth; i++){
        for (int j = 0; j < outputHeight; j++){
            outputPixels[(outputWidth*j+fragmentWidth*renderingFrame+i)*3 + 0] = inputPixels[(fragmentWidth*j+i)*3 + 0];	// r
            outputPixels[(outputWidth*j+fragmentWidth*renderingFrame+i)*3 + 1] = inputPixels[(fragmentWidth*j+i)*3 + 1];	// g
            outputPixels[(outputWidth*j+fragmentWidth*renderingFrame+i)*3 + 2] = inputPixels[(fragmentWidth*j+i)*3 + 2]; // b
        }
    }
    delete image;
    
    ++renderingFrame;
    outputImg->update();
    
}

void MovieCompressor::setup() {
    std::string path = filePaths.front();
    if (video == NULL) {
        video = new ofxiOSVideoPlayer();
    }
    video->loadMovie(path);
}

void MovieCompressor::update() {
    if (video == NULL) {
        setup();
    }
    if (!video->isLoaded()) {
        return;
    }
    video->update();
    setOutputImage();
}
