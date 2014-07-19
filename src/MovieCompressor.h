//
//  MovieCompressor.h
//  MemoryCompressor
//
//  Created by 小坂 昂大 on 2014/07/13.
//
//

#ifndef __MemoryCompressor__MovieCompressor__
#define __MemoryCompressor__MovieCompressor__

#include <iostream>
#include "Compressor.h"

class MovieCompressor: public Compressor {
protected:
    ofxiOSVideoPlayer *video;
    
    virtual void setOutputImage();
    
public:
    MovieCompressor(std::vector<std::string> paths);
    virtual ~MovieCompressor();
    virtual void setup();
    virtual void update();
};

#endif /* defined(__MemoryCompressor__MovieCompressor__) */
