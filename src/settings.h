#ifndef SETTINGS_H
#define SETTINGS_H

#include"ofMain.h"

//命名统一规范
typedef ofPoint f2Point;
typedef ofImage f2Image;
typedef ofXml f2Xml;

inline void f2DrawRect(f2Point& upper, f2Point& lower)
{
	ofRect(upper, lower.x - upper.x, lower.y - upper.y);
}

inline void f2DrawCircle(f2Point& point, float radius)
{
	ofNoFill();
	ofSetCircleResolution(radius);
	ofCircle(point, radius);
}

inline float f2GetElapsedTime()
{
	return ofGetElapsedTimef();
}

#endif
