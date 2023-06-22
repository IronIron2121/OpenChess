#pragma once

#include "ofMain.h"
#include "Board.h"
#include "vector"

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
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);


		int pieceIDTicker;
		int clickerCount;
		//int& turnModulo;
		int firstClickedX;
		int firstClickedY;

		//Initialise the board
		Board boardVar;

		//Initialise empty array for square objects
		Square squares[8][8];

		//Initialise empty arrays for pieces
		Piece* pieceArray[32];


		

		


};
