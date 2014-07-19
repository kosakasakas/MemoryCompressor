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
: filePaths(paths)
, renderingFrame(0)
{
    ofPoint winSize = ofGetWindowSize();
    outputWidth = winSize.y;
    outputHeight = winSize.x;
    
    outputImg = new ofImage();
    outputImg->allocate(outputWidth, outputHeight, OF_IMAGE_COLOR);
}

Compressor::~Compressor()
{
    delete outputImg;
}

ofImage* Compressor::getOutputImg() {
    return outputImg;
}
