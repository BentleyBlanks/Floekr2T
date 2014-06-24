#pragma once

#include "ofMain.h"
#include"Floekr2T.h"

class ofApp : public ofBaseApp{

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	Floekr2T::scene scene;

	Floekr2T::animationManager animationManager;

	Floekr2T::attackerManager attackerManager;

	Floekr2T::defendorManager defendorManager;

	Floekr2T::guiManager guiManager;

	Floekr2T::skillManager skillManager;

	vector<f2Image> backgrounds;

	bool pathValid, openFile;
};
