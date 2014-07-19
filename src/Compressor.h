//
//  Compressor.h
//  MemoryCompressor
//
//  Created by 小坂 昂大 on 2014/07/06.
//
//

#ifndef __MemoryCompressor__Compressor__
#define __MemoryCompressor__Compressor__

#include <vector>
#include "ofMain.h"

class Compressor {
protected:
    ofImage* outputImg;
    std::vector<std::string> filePaths;
    int renderingFrame;
    
    virtual void setOutputImage() = 0;
    
public:
    Compressor(std::vector<std::string> paths);
    virtual ~Compressor();
    virtual void setup() = 0;
    virtual void update() = 0;
    virtual ofImage* getOutputImg();
    
    static int outputWidth;
    static int outputHeight;
};


#endif /* defined(__MemoryCompressor__Compressor__) */
