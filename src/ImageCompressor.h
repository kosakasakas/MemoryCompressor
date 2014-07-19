//
//  Compressor.h
//  ImageCompressor
//
//  Created by 小坂 昂大 on 2014/07/06.
//
//

#ifndef __ImageCompressor__Compressor__
#define __ImageCompressor__Compressor__

#include <vector>
#include "ofMain.h"
#include "Compressor.h"

class ImageCompressor : public Compressor {
protected:
    virtual void setOutputImage();
    
public:
    ImageCompressor(std::vector<std::string> paths);
    virtual ~ImageCompressor();
    virtual void setup();
    virtual void update();
};


#endif /* defined(__ImageCompressor__Compressor__) */
