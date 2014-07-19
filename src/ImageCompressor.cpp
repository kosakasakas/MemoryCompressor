//
//  ImageCompressor.cpp
//  MemoryCompressor
//
//  Created by 小坂 昂大 on 2014/07/06.
//
//

#include "ImageCompressor.h"
#include <string>

ImageCompressor::ImageCompressor(std::vector<std::string> paths)
: Compressor(paths)
{
}

ImageCompressor::~ImageCompressor()
{
}

void ImageCompressor::setOutputImage() {
    if (outputImg == NULL) {
        return;
    }
    
    if (outputWidth <= renderingFrame) {
        return;
    }
    
    int frameNum = filePaths.size();
    int frameSampleNum = (frameNum > outputWidth) ? frameNum/(outputWidth - 1) : 1;
    int fragmentWidth = (frameNum > outputWidth) ? 1 : outputWidth / frameNum;
    std::string path = filePaths.at(renderingFrame*frameSampleNum);
    ofImage *image = new ofImage();
    image->loadImage(path.c_str());
    image->resize(fragmentWidth, outputHeight);
    unsigned char * inputPixels = image->getPixels();
    unsigned char * outputPixels = outputImg->getPixels();
    delete image;
    
    for (int i = 0; i < fragmentWidth; i++){
        for (int j = 0; j < outputHeight; j++){
            outputPixels[(outputWidth*j+fragmentWidth*renderingFrame+i)*3 + 0] = inputPixels[(fragmentWidth*j+i)*3 + 0]; // r
            outputPixels[(outputWidth*j+fragmentWidth*renderingFrame+i)*3 + 1] = inputPixels[(fragmentWidth*j+i)*3 + 1]; // g
            outputPixels[(outputWidth*j+fragmentWidth*renderingFrame+i)*3 + 2] = inputPixels[(fragmentWidth*j+i)*3 + 2]; // b
        }
    }
    ++renderingFrame;
    outputImg->update();
}

void ImageCompressor::setup() {
    
}

void ImageCompressor::update() {
    setOutputImage();
}
