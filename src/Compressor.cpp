//
//  Compressor.cpp
//  MemoryCompressor
//
//  Created by 小坂 昂大 on 2014/07/06.
//
//

#include "Compressor.h"
#include <string>

int Compressor::outputWidth = 960;
int Compressor::outputHeight = 540;

Compressor::Compressor(std::vector<std::string> paths)
{
    ofPoint winSize = ofGetWindowSize();
    outputWidth = winSize.y;
    outputHeight = winSize.x;
    
    outputImg = new ofImage();
    outputImg->allocate(outputWidth, outputHeight, OF_IMAGE_COLOR);
    setOutputImage(paths);
}

Compressor::~Compressor()
{
    delete outputImg;
}

ofImage* Compressor::getOutputImg() {
    return outputImg;
}

void Compressor::setOutputImage(std::vector<std::string> paths) {
    if (outputImg == NULL) {
        return;
    }
    
    int num = paths.size();
    int fragmentWidth = outputWidth / num;
    unsigned char * inputPixels;
    unsigned char * outputPixels = outputImg->getPixels();
    int f = 0;
    for (std::vector<std::string>::iterator it = paths.begin(); it != paths.end(); ++it) {
        ofImage *image = new ofImage();
        image->loadImage(((std::string)*it).c_str());
        image->resize(fragmentWidth, outputHeight);
        inputPixels = image->getPixels();
        delete image;
        
        for (int i = 0; i < fragmentWidth; i++){
            for (int j = 0; j < outputHeight; j++){
                outputPixels[(outputWidth*j+fragmentWidth*f+i)*3 + 0] = inputPixels[(fragmentWidth*j+i)*3 + 0];	// r
                outputPixels[(outputWidth*j+fragmentWidth*f+i)*3 + 1] = inputPixels[(fragmentWidth*j+i)*3 + 1];	// g
                outputPixels[(outputWidth*j+fragmentWidth*f+i)*3 + 2] = inputPixels[(fragmentWidth*j+i)*3 + 2]; // b
            }
        }
        ++f;
    }
    outputImg->update();
}
