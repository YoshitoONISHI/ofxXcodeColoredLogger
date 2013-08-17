//
//  ofxXCodeColoredLoggerChannel.h
//  ofxXCodeColoredLogger
//
//  Created by Onishi Yoshito on 8/18/13.
//
//

#ifndef __ofxXCodeColoredLogger__ofxXCodeColoredLoggerChannel__
#define __ofxXCodeColoredLogger__ofxXCodeColoredLoggerChannel__

#include "ofMain.h"

class ofxXCodeColoredLoggerChannel: public ofBaseLoggerChannel {
public:
    static ofPtr<ofxXCodeColoredLoggerChannel> create();
    
    ofxXCodeColoredLoggerChannel();
	virtual ~ofxXCodeColoredLoggerChannel() {}
	void log(ofLogLevel logLevel, const string& module, const string& message);
	void log(ofLogLevel logLevel, const string& module, const char* format, ...);
	void log(ofLogLevel logLevel, const string& module, const char* format, va_list args);

    ofColor getColor(ofLogLevel logLevel) const;
    void setColor(ofLogLevel logLevel, const ofColor& color);
    
private:
    vector<ofColor> mColors;
    
};


#endif /* defined(__ofxXCodeColoredLogger__ofxXCodeColoredLoggerChannel__) */
