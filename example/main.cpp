#include "ofxXCodeColoredLoggerChannel.h"

//----------------------------------------------------------------------------------------
int main()
{
    // setup ofxXCodeColoredLogger
	ofSetLoggerChannel(ofxXCodeColoredLoggerChannel::create());
    ofSetLogLevel(OF_LOG_VERBOSE);
    
    // automatically colored log
    ofLogVerbose("test")  << __PRETTY_FUNCTION__  << " Verbose";
    ofLogNotice("test")   << __PRETTY_FUNCTION__  << " Notice";
    ofLogWarning("test")  << __PRETTY_FUNCTION__  << " Warning";
    ofLogError("test")    << __PRETTY_FUNCTION__  << " Error";
    
    cout << endl;
    
    ofLog(OF_LOG_VERBOSE,   "%s Verbose",   __PRETTY_FUNCTION__);
    ofLog(OF_LOG_NOTICE,    "%s Notice",    __PRETTY_FUNCTION__);
    ofLog(OF_LOG_WARNING,   "%s Warning",   __PRETTY_FUNCTION__);
    ofLog(OF_LOG_ERROR,     "%s Error",     __PRETTY_FUNCTION__);

    cout << endl;
    
    // custom color
    ofPtr<ofxXCodeColoredLoggerChannel> channel = ofxXCodeColoredLoggerChannel::create();
    channel->setColor(OF_LOG_VERBOSE, ofColor::darkTurquoise);
    channel->setColor(OF_LOG_NOTICE, ofColor::dodgerBlue);
    channel->setColor(OF_LOG_WARNING, ofColor::goldenRod);
    channel->setColor(OF_LOG_ERROR, ofColor::fireBrick);
    ofSetLoggerChannel(channel);
                    
    ofLogVerbose("test")  << __PRETTY_FUNCTION__  << " Verbose";
    ofLogNotice("test")   << __PRETTY_FUNCTION__  << " Notice";
    ofLogWarning("test")  << __PRETTY_FUNCTION__  << " Warning";
    ofLogError("test")    << __PRETTY_FUNCTION__  << " Error";
}