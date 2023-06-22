#include "Board.h"
#include "ofBaseApp.h"


Board::Board() {
	
}


void Board::setup() {
	width = 8;
	height = 8;
	area = 100;
}

void Board::draw(Square squareArray[8][8]) {
	for (int i = 0; i < this->width; i++) {
		for (int j = 0; j < this->height; j++) {
			int colourVal = 255 * ((j + i + 1) % 2);
			//if the square is being hovered over by mouse, change its colour
			if(squareArray[i][j].x < ofGetAppPtr()->mouseX && ofGetAppPtr()->mouseX < squareArray[i][j].x + this->area
				&& squareArray[i][j].y < ofGetAppPtr()->mouseY && ofGetAppPtr()->mouseY < squareArray[i][j].y + this->area){

				squareArray[i][j].inRange = true;
				ofSetColor(100);
				ofFill();
				ofDrawRectangle(i*area + area, j*area + area, area, area);
				ofNoFill();
				//draw the outline - invariably black
				ofSetColor(0);
				ofDrawRectangle(i*area + area, j*area + area, area, area);
			}
			else {
				squareArray[i][j].inRange = false;
				if (squareArray[i][j].clicked == false) {
					//draw filled square in black or white, depending on where we are in loop
					ofSetColor(colourVal);
					ofFill();
					ofDrawRectangle(i*area + area, j*area + area, area, area);
					ofNoFill();
					//draw the outline - invariably black
					ofSetColor(0);
					ofDrawRectangle(i*area + area, j*area + area, area, area);
				}
				else {
					ofSetColor(255, 0, 255);
					ofFill();
					ofDrawRectangle(i*area + area, j*area + area, area, area);
				}

			}



			}

	}
	
	
/* ofSetColor(0, 255, 0);
	ofFill();
	ofDrawRectangle(100, 100, 500, 500);
*/
}

Square::Square() {
}

void Square::setup(int _x, int _y, int _squarePos) {
	x = _x; 
	y = _y;
	squarePos = _squarePos;

	occupier = 0;
	occupierTeamInt = 0;

	inRange = false;
	clicked = false;
	occupied = false;
}



void Square::check()
{
}

	//PIECE CLASSES
//Parent Class --
Piece::Piece() {

}

void Piece::setup(int _x, int _y, int _squarePos, string _team, int _pieceIDTicker) {
	pinned = false;
}

void Piece::draw() {

}
//--End of Parent Class

//Pawn Derivative --
Pawn::Pawn() {

}

void Pawn::setup(int _x, int _y, int _squarePos, string _team, int _pieceIDTicker) {
	x = _x;
	y = _y;
	squarePos = _squarePos;
	team = _team;
	pieceID = _pieceIDTicker;
	size = 20;
	moveHistory = 1;

	active = true;
	type = "pawn";
	//pinned = false;

	if (this->team == "white") {
		teamInt = 0;
	}
	else {
		teamInt = 1;
	}
}

void Pawn::draw() {
	if (this->active) {
		ofFill();
		
		if (this->team == "white") {
			ofSetColor(0);
			ofDrawCircle(this->x + 50, this->y + 50, this->size);
			ofSetColor(255);
			ofDrawCircle(this->x + 50, this->y + 50, this->size-1);
		}
		else {
			ofSetColor(255);
			ofDrawCircle(this->x + 50, this->y + 50, this->size);
			ofSetColor(0);
			ofDrawCircle(this->x + 50, this->y + 50, this->size - 1);
		}
	}
}
//--End of Pawn Derivative

//Rook Derivative --
//Constructor
Rook::Rook() {

}
//Setup Function
void Rook::setup(int _x, int _y, int _squarePos, string _team, int _pieceIDTicker) {
	x = _x;
	y = _y;
	squarePos = _squarePos;
	team = _team;
	pieceID = _pieceIDTicker;
	size = 50;
	moveHistory = 1;

	active = true;
	type = "rook";
	//pinned = false;

	if (this->team == "white") {
		teamInt = 0;
	}
	else {
		teamInt = 1;
	}
}
//Draw
void Rook::draw() {
	if (this->active) {
		ofFill();
		if (this->team == "white") {
			ofSetColor(0);
			ofDrawRectangle(this->x + 25, this->y + 25, this->size, this->size);
			ofSetColor(255);
			ofDrawRectangle(this->x + 25, this->y + 25, this->size-1, this->size-1);
		}
		else {
			ofSetColor(255);
			ofDrawRectangle(this->x + 25, this->y + 25, this->size, this->size);
			ofSetColor(0);
			ofDrawRectangle(this->x + 25, this->y + 25, this->size-1, this->size-1);
		}
	}
}
	//--End of Rook Derivative

	//Bishop Derivative--
//Constructor
Bishop::Bishop() {

}
//Setup Function
void Bishop::setup(int _x, int _y, int _squarePos, string _team, int _pieceIDTicker) {
	x = _x;
	y = _y;
	squarePos = _squarePos;
	team = _team;
	pieceID = _pieceIDTicker;
	size = 50;
	moveHistory = 1;

	active = true;
	type = "bishop";
	//pinned = false;

	if (this->team == "white") {
		teamInt = 0;
	}
	else {
		teamInt = 1;
	}
}
//Draw
void Bishop::draw() {
	if (this->active) {
		int adjuster = 20;
		ofFill();
		ofPushMatrix();
		ofTranslate(this->x+50,this->y + adjuster,0);
		ofRotateRad(PI/4);
		if (this->team == "white") {
			ofSetColor(0);
			ofDrawRectangle(0, 0, this->size, this->size);
			ofSetColor(255);
			ofDrawRectangle(5, 5, this->size - 10, this->size - 10);
		}
		else {
			ofSetColor(255);
			ofDrawRectangle(0, 0, this->size, this->size);
			ofSetColor(0);
			ofDrawRectangle(5, 5, this->size - 10, this->size - 10);
		}
		ofPopMatrix();
	}
}
//--End of Bishop Derivative

//Start of Knight Derivative--
Knight::Knight() {

}

void Knight::setup(int _x, int _y, int _squarePos, string _team, int _pieceIDTicker) {
	x = _x;
	y = _y;
	squarePos = _squarePos;
	team = _team;
	pieceID = _pieceIDTicker;
	size = 20;
	moveHistory = 1;

	active = true;
	type = "knight";
	//pinned = false;

	if (this->team == "white") {
		teamInt = 0;
	}
	else {
		teamInt = 1;
	}

}

void Knight::draw() {
	if (this->active) {
		int adjuster = 50;
		int adjuster2 = 5;
		ofFill();
		ofPushMatrix();
		ofTranslate(adjuster,adjuster,0);
		if (this->team == "white") {
			ofSetColor(0);
			ofDrawTriangle(this->x, this->y - this->size, this->x + this->size, this->y + this->size, this->x - this->size, this->y + this->size);
			ofSetColor(255);
			ofDrawTriangle(this->x, this->y - this->size + adjuster2, this->x + this->size - adjuster2, this->y + this->size - adjuster2, this->x - this->size + adjuster2, this->y + this->size - adjuster2);
		}
		else {
			ofSetColor(255);
			ofDrawTriangle(this->x, this->y - this->size, this->x + this->size, this->y + this->size, this->x - this->size, this->y + this->size);
			ofSetColor(0);
			ofDrawTriangle(this->x, this->y - this->size + adjuster2, this->x + this->size - adjuster2, this->y + this->size - adjuster2, this->x - this->size + adjuster2, this->y + this->size - adjuster2);
		}
		ofPopMatrix();
	}
}
//--End of Knight derivative

//Start of Queen derivative--
Queen::Queen() {

}

void Queen::setup(int _x, int _y, int _squarePos, string _team, int _pieceIDTicker) {
	x = _x;
	y = _y;
	squarePos = _squarePos;
	team = _team;
	pieceID = _pieceIDTicker;
	size = 40;
	moveHistory = 1;

	active = true;
	type = "queen";
	//pinned = false;

	if (this->team == "white") {
		teamInt = 0;
	}
	else {
		teamInt = 1;
	}

}

void Queen::draw() {
	if (this->active) {
		int adjuster = 50;
		int adjuster2 = 5;
		ofFill();
		ofPushMatrix();
		ofTranslate(adjuster, adjuster, 0);
		if (this->team == "white") {
			ofSetColor(220);
			ofDrawRectangle(this->x - (this->size / 2), this->y - (this->size / 4), this->size, this->size);
			ofPushMatrix();
			ofTranslate(this->x, this->y - 18);
			ofRotateRad(PI / 4);
			ofDrawRectangle(0, 0, this->size, this->size);
			ofPopMatrix();
		}
		else {
			ofSetColor(35);
			ofPushMatrix();
			ofDrawRectangle(this->x - (this->size / 2), this->y - (this->size / 4), this->size, this->size);
			ofTranslate(this->x, this->y - 18);
			ofRotateRad(PI / 4);
			ofDrawRectangle(0, 0, this->size, this->size);
			ofPopMatrix();

		}
	}
}
//--End of Queen derivative

//Start of King derivative--
King::King() {

}

void King::setup(int _x, int _y, int _squarePos, string _team, int _pieceIDTicker) {
	x = _x;
	y = _y;
	squarePos = _squarePos;
	team = _team;
	pieceID = _pieceIDTicker;
	size = 40;
	moveHistory = 1;

	active = true;
	type = "king";
	//pinned = false;

	if (this->team == "white") {
		teamInt = 0;
	}
	else {
		teamInt = 1;
	}
}

void King::draw() {
	if (this->active) {
		ofFill();

		if (this->team == "white") {
			ofSetColor(0);
			ofDrawCircle(this->x + 50, this->y + 50, this->size);
			ofSetColor(255);
			ofDrawCircle(this->x + 50, this->y + 50, this->size - 1);
		}
		else {
			ofSetColor(255);
			ofDrawCircle(this->x + 50, this->y + 50, this->size);
			ofSetColor(0);
			ofDrawCircle(this->x + 50, this->y + 50, this->size - 1);
		}
	}
}
//--End of King derivaive
