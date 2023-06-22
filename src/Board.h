#pragma once
#ifndef _BOARD
#define _BOARD

#include "ofMain.h"

//square object, for holding information about pieces
class Square {
public:
		//methods
	void check();
	void setup(int _x, int _y, int _squarePos);
		//properties
	//locational
	int x;
	int y;
	int squarePos;
	//piece interaction
	int occupier;
	int occupierTeamInt;
	//user interaction
	bool inRange;
	bool clicked;
	bool occupied;
		//constructor
	Square();
};

//chessboard object, mostly for drawing the squares out
class Board {
	public:
			//methods
		void setup();
		void draw(Square squareArray[8][8]);
			//properties
		int width;
		int height;
		int area;
			//constructor
		Board();
	private:
};

//Parent class for all pieces --
class Piece {
public:
		//methods
	//void setup(int _x, int _y, int _squarePos, string _team, int _pieceIDTicker);
	virtual void setup(int _x, int _y, int _squarePos, string _team, int _pieceIDTicker);
	virtual void draw();

		//properties
	//location properties
	int x;
	int y;
	int pieceID;
	int squarePos;
	int moveHistory;

	//team attributes; white/0 or black/1
	string team;
	int teamInt;
	//size of pieces
	int size;

	//status properties
	string type;
	bool pinned;
	bool active;

	Piece();
private:

};
//--End of Parent Class

//Pawn Class--
class Pawn: public Piece {

public:
		//methods
	void draw();
	void setup(int _x, int _y, int _squarePos, string _team, int _pieceIDTicker);
		//properties
	//positional/movement related variables. Stores current square, previous square, and maximum moves allowed for the piece
		//constructor
	Pawn();
	private:

};
//--End of Pawn Class

//Rook Class --
class Rook : public Piece {
public:
		//methods
	void draw();
	void setup(int _x, int _y, int _squarePos, string _team, int _pieceIDTicker);
		//constructor
	Rook();
};
//--End of Rook Class

//Bishop Class
class Bishop : public Piece {
public:
		//methods
	void draw();
	void setup(int _x, int _y, int _squarePos, string _team, int _pieceIDTicker);
		//constructor
	Bishop();
};
//End of Bishop Class

//Knight Class
class Knight : public Piece {
public:
		//methods
	void draw();
	void setup(int _x, int _y, int _squarePos, string _team, int _pieceIDTicker);
		//constructor
	Knight();
};
//End of Knight Class

//Queen Class
class Queen : public Piece {
public:
		//methods
	void draw();
	void setup(int _x, int _y, int _squarePos, string _team, int _pieceIDTicker);
		//constructor
	Queen();
};
//End of Queen Class

//King Class
class King : public Piece {
public:
		//methods
	void draw();
	void setup(int _x, int _y, int _squarePos, string _team, int _pieceIDTicker);
		//constructor
	King();
};
#endif




