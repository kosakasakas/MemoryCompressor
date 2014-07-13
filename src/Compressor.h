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
private:
    ofImage* outputImg;
    virtual void setOutputImage(std::vector<std::string> paths);
    
public:
    Compressor(std::vector<std::string> paths);
    ~Compressor();
    ofImage* getOutputImg();
    
    static int outputWidth;
    static int outputHeight;
};


#endif /* defined(__MemoryCompressor__Compressor__) */
