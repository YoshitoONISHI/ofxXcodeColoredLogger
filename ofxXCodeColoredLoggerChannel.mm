//
//  ofxXCodeColoredLoggerChannel.mm
//  ofxXCodeColoredLogger
//
//  Created by Onishi Yoshito on 8/18/13.
//
//

#include "ofxXCodeColoredLoggerChannel.h"

ofPtr<ofxXCodeColoredLoggerChannel> ofxXCodeColoredLoggerChannel::create()
{
    return ofPtr<ofxXCodeColoredLoggerChannel>(new ofxXCodeColoredLoggerChannel());
}

ofxXCodeColoredLoggerChannel::ofxXCodeColoredLoggerChannel() :
mColors(OF_LOG_SILENT+1)
{
    mColors.at(OF_LOG_VERBOSE).set(110, 110, 110);
    mColors.at(OF_LOG_NOTICE).set(110, 128, 255);
    mColors.at(OF_LOG_WARNING).set(255, 128, 0);
    mColors.at(OF_LOG_ERROR).set(255, 90, 90);
    mColors.at(OF_LOG_FATAL_ERROR).set(255, 0, 0);
    mColors.at(OF_LOG_SILENT).set(255, 255, 255);
}

void ofxXCodeColoredLoggerChannel::log(ofLogLevel logLevel,
                                       const string& module,
                                       const string& message)
{
	ostringstream out;
	out << "[";
	if(module != "OF") {
		out << module << ":";
	}
	out << ofGetLogLevelName(logLevel) << "] " << message << endl;
    
    const ofColor& color = mColors.at(logLevel);
    
    NSLog(@"\033[fg%d,%d,%d;%s\033[;", color.r, color.g, color.b, out.str().c_str());
}

ofColor ofxXCodeColoredLoggerChannel::getColor(ofLogLevel logLevel) const
{
    return mColors.at(logLevel);
}

void ofxXCodeColoredLoggerChannel::setColor(ofLogLevel logLevel, const ofColor& color)
{
    mColors.at(logLevel) = color;
}

void ofxXCodeColoredLoggerChannel::log(ofLogLevel logLevel,
                                       const string& module,
                                       const char* format, ...)
{
	va_list args;
	va_start(args, format);
	log(logLevel, module, format, args);
	va_end(args);
}

void ofxXCodeColoredLoggerChannel::log(ofLogLevel logLevel,
                                       const string& module,
                                       const char* format,
                                       va_list args)
{
    NSString* info;
    if(module != "OF") {
        info = [NSString stringWithFormat:@"[%s:%s]",
                  module.c_str(),
                  ofGetLogLevelName(logLevel).c_str()];
    }
    else {
        info = [NSString stringWithFormat:@"[%s]", ofGetLogLevelName(logLevel).c_str()];
    }
    
    const ofColor& color = mColors.at(logLevel);
    NSString* dynamicFormat = [NSString stringWithFormat:@"\033[fg%d,%d,%d;%@ %@\033[;",
                               color.r,
                               color.g,
                               color.b,
                               info,
                               @(format)];
    
    NSLogv(dynamicFormat, args);
}
