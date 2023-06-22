int turnModulo = 0;
#include "ofApp.h"
//#include "Board.h"
//#include "Board.cpp"

//--------------------------------------------------------------



void ofApp::setup() {



	clickerCount = 0;
	//turnModulo = 0;

	//initialise the board
	boardVar.setup();

	//declare a variable to give each square a number ID
	int posCounter = 0;
	pieceIDTicker = 0;

	//go through and initialise each square.
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			posCounter += 1;
			squares[i][j].setup((i * 100) + 100, (j * 100) + 100, posCounter);
		}
	}
	//INITIALISING BLACK PIECES--
	//initialise black pawns
	for (int i = 0; i < 8; i++) {
		Pawn* pawner = new Pawn();
		pieceArray[i] = pawner;
		pieceArray[i]->setup(squares[i][1].x, squares[i][1].y, squares[i][1].squarePos, "black", pieceIDTicker);
		squares[i][1].occupied = true;
		squares[i][1].occupier = pieceArray[i]->pieceID;
		squares[i][1].occupierTeamInt = pieceArray[i]->teamInt;
		pieceIDTicker += 1;
	}

	//initialise black rooks
	for (int i = 0; i < 2; i++) {
		Rook* rooker = new Rook();
		pieceArray[pieceIDTicker] = rooker;
		pieceArray[pieceIDTicker]->setup(squares[i*7][0].x, squares[i * 7][0].y, squares[i*7][0].squarePos, "black", pieceIDTicker);
		squares[i*7][0].occupied = true;
		squares[i*7][0].occupier = pieceArray[pieceIDTicker]->pieceID;
		squares[i*7][0].occupierTeamInt = pieceArray[pieceIDTicker]->teamInt;
		pieceIDTicker += 1;
	}

	//initialise black bishops
	for (int i = 2; i < 6; i+=3) {
		Bishop* bishoper = new Bishop();
		pieceArray[pieceIDTicker] = bishoper;
		pieceArray[pieceIDTicker]->setup(squares[i][0].x, squares[i][0].y, squares[i][0].squarePos, "black", pieceIDTicker);
		squares[i][0].occupied = true;
		squares[i][0].occupier = pieceArray[pieceIDTicker]->pieceID;
		squares[i][0].occupierTeamInt = pieceArray[pieceIDTicker]->teamInt;
		pieceIDTicker += 1;
	}

	//initialise black knights
	for (int i = 1; i < 7; i+=5) {
		Knight* knighter= new Knight();
		pieceArray[pieceIDTicker] = knighter;
		pieceArray[pieceIDTicker]->setup(squares[i][0].x, squares[i][0].y, squares[i][0].squarePos, "black", pieceIDTicker);
		squares[i][0].occupied = true;
		squares[i][0].occupier = pieceArray[pieceIDTicker]->pieceID;
		squares[i][0].occupierTeamInt = pieceArray[pieceIDTicker]->teamInt;
		pieceIDTicker += 1;
	}

	//initialise black queen

	Queen* queener= new Queen();
	pieceArray[pieceIDTicker] = queener;
	pieceArray[pieceIDTicker]->setup(squares[3][0].x, squares[3][0].y, squares[3][0].squarePos, "black", pieceIDTicker);
	squares[3][0].occupied = true;
	squares[3][0].occupier = pieceArray[pieceIDTicker]->pieceID;
	squares[3][0].occupierTeamInt = pieceArray[pieceIDTicker]->teamInt;
	pieceIDTicker += 1;

	//initialise black king

	King* kinger = new King();
	pieceArray[pieceIDTicker] = kinger;
	pieceArray[pieceIDTicker]->setup(squares[4][0].x, squares[4][0].y, squares[4][0].squarePos, "black", pieceIDTicker);
	squares[4][0].occupied = true;
	squares[4][0].occupier = pieceArray[pieceIDTicker]->pieceID;
	squares[4][0].occupierTeamInt = pieceArray[pieceIDTicker]->teamInt;
	pieceIDTicker += 1;
	
	//--END OF INITIALISING BLACK PIECES

	//INITIALISING WHITE PIECES--

	//initialise white pawns
	for (int i = 0; i < 8; i++) {
		Pawn* pawner = new Pawn();
		pieceArray[pieceIDTicker] = pawner;
		pieceArray[pieceIDTicker]->setup(squares[i][6].x, squares[i][6].y, squares[i][6].squarePos, "white", pieceIDTicker);
		squares[i][6].occupied = true;
		squares[i][6].occupier = pieceArray[pieceIDTicker]->pieceID;
		squares[i][6].occupierTeamInt = pieceArray[pieceIDTicker]->teamInt;
		pieceIDTicker += 1;
	}
	//initialise white rooks
	for (int i = 0; i < 2; i++) {
		Rook* rooker = new Rook();
		pieceArray[pieceIDTicker] = rooker;
		pieceArray[pieceIDTicker]->setup(squares[i * 7][7].x, squares[i * 7][7].y, squares[i * 7][7].squarePos, "white", pieceIDTicker);
		squares[i * 7][7].occupied = true;
		squares[i * 7][7].occupier = pieceArray[pieceIDTicker]->pieceID;
		squares[i * 7][7].occupierTeamInt = pieceArray[pieceIDTicker]->teamInt;
		pieceIDTicker += 1;
	}

	//initialise white bishops
	for (int i = 2; i < 6; i += 3) {
		Bishop* bishoper = new Bishop();
		pieceArray[pieceIDTicker] = bishoper;
		pieceArray[pieceIDTicker]->setup(squares[i][7].x, squares[i][7].y, squares[i][7].squarePos, "white", pieceIDTicker);
		squares[i][7].occupied = true;
		squares[i][7].occupier = pieceArray[pieceIDTicker]->pieceID;
		squares[i][7].occupierTeamInt = pieceArray[pieceIDTicker]->teamInt;
		pieceIDTicker += 1;
	}

	//initialise white knights
	for (int i = 1; i < 7; i += 5) {
		Knight* Knighter = new Knight();
		pieceArray[pieceIDTicker] = Knighter;
		pieceArray[pieceIDTicker]->setup(squares[i][7].x, squares[i][7].y, squares[i][7].squarePos, "white", pieceIDTicker);
		squares[i][7].occupied = true;
		squares[i][7].occupier = pieceArray[pieceIDTicker]->pieceID;
		squares[i][7].occupierTeamInt = pieceArray[pieceIDTicker]->teamInt;
		pieceIDTicker += 1;
	}

	//initialise white queen
	Queen* Queener2 = new Queen();
	pieceArray[pieceIDTicker] = Queener2;
	pieceArray[pieceIDTicker]->setup(squares[3][7].x, squares[3][7].y, squares[3][7].squarePos, "white", pieceIDTicker);
	squares[3][7].occupied = true;
	squares[3][7].occupier = pieceArray[pieceIDTicker]->pieceID;
	squares[3][7].occupierTeamInt = pieceArray[pieceIDTicker]->teamInt;
	pieceIDTicker += 1;

	//initialise white king
	King* kinger2 = new King();
	pieceArray[pieceIDTicker] = kinger2;
	pieceArray[pieceIDTicker]->setup(squares[4][7].x, squares[4][7].y, squares[4][7].squarePos, "white", pieceIDTicker);
	squares[4][7].occupied = true;
	squares[4][7].occupier = pieceArray[pieceIDTicker]->pieceID;
	squares[4][7].occupierTeamInt = pieceArray[pieceIDTicker]->teamInt;
	pieceIDTicker += 1;




	ofSetBackgroundColor(255);
	ofSetFrameRate(30);


}

////code for checking pins and checks
//void checkPinCheck(Piece* pieceArray[]) {
//	for (int i = 0; i < 32; i++) {
//		pieceArray[i]->pinned = false;
//	}
//
//	for (int i = 0; i < 32; i++) {
//		if (pieceArray[i]->active) {
//			if (pieceArray[i]->type == "rook") {
//				//north
//				for (int j = 0; j < i; j++) {
//
//				}
//			}
//		}
//	}
//}

//I am deeply apologetic for what you're about to witness below
//PIECE MOVEMENT LOGIC
void moveLogicCheck(int i1, int j1, int i2, int j2, Piece* pieceArray[], Square squares[8][8]) {
	// PAWN MOVEMENT LOGIC
	if (pieceArray[squares[i1][j1].occupier]->type == "pawn") {
		//Check if initial and target squares are in the same column - if they are, move on to next phase of movement check
		if (i1 == i2) {
			//If the square is unoccupied, and the pawn is moving in the right direction (up if it's a white pawn, down if it's a black pawn,
			//- and it's moving in accordance with the first-move-rule for pawns (they can move two spaces on their first move - then allow the move))
			if (squares[i2][j2].occupied == false && (squares[i1][j1].occupierTeamInt == 0 && j1 > j2 && j1 - j2 - pieceArray[squares[i1][j1].occupier]->moveHistory < 2 
				||squares[i1][j1].occupierTeamInt == 1 &&	j1 < j2 && abs(j1 - j2) - pieceArray[squares[i1][j1].occupier]->moveHistory < 2)) {
				//If the pawn has reached the end of the board, upgrade it to a queen - white or black, dependant on which side of the board its reached
				if (j2 == 0) {
					bool upSwitcher = false;
					while (!upSwitcher) {
						cout << "Upgrade! Enter q for a queen, r for a rook, k for a knight, or b for a bishop " << endl;
						char switchChoice = cin.get();
						string trashCan;
						getline(cin, trashCan);
						if (switchChoice == 'q') {
							pieceArray[squares[i1][j1].occupier] = new Queen;
							pieceArray[squares[i1][j1].occupier]->setup(i1, j1, squares[i1][j1].squarePos, "white", 0);
							upSwitcher = true;
							cout << "Queen Upgrade! Where switchChoice == " << switchChoice << endl;
							break;
						}
						else if (switchChoice == 'k') {
							pieceArray[squares[i1][j1].occupier] = new Knight;
							pieceArray[squares[i1][j1].occupier]->setup(i1, j1, squares[i1][j1].squarePos, "white", 0);
							upSwitcher = true;
							cout << "Knight Upgrade! Where switchChoice == " << switchChoice << endl;
							break;
						}
						else if (switchChoice == 'b') {
							pieceArray[squares[i1][j1].occupier] = new Bishop;
							pieceArray[squares[i1][j1].occupier]->setup(i1, j1, squares[i1][j1].squarePos, "white", 0);
							upSwitcher = true;
							cout << "Bishop Upgrade! Where switchChoice == " << switchChoice << endl;
							break;
						}
						else if (switchChoice == 'r') {
							pieceArray[squares[i1][j1].occupier] = new Rook;
							pieceArray[squares[i1][j1].occupier]->setup(i1, j1, squares[i1][j1].squarePos, "white", 0);
							upSwitcher = true;
							cout << "Rook Upgrade! Where switchChoice == " << switchChoice << endl;
							break;
						}
						else {
							cout << "Please input either q for a queen, k for a knight, b for a bishop, or r for a rook (upgrade)" << endl;
							cout << "upSwitcher == " << upSwitcher << ", switchChoice == " << switchChoice << endl;
						}
					}
				}
				else if (j2 == 7) {
					char switchChoice = cin.get();
					bool upSwitcher = false;
					string trashCan;
					getline(cin, trashCan);
					while (!upSwitcher) {
						if (switchChoice == 'q') {
							pieceArray[squares[i1][j1].occupier] = new Queen;
							pieceArray[squares[i1][j1].occupier]->setup(i1, j1, squares[i1][j1].squarePos, "black", 0);
							upSwitcher = true;
							cout << "Queen Upgrade! Where switchChoice == " << switchChoice << endl;

							break;
						}
						else if (switchChoice == 'k') {
							pieceArray[squares[i1][j1].occupier] = new Knight;
							pieceArray[squares[i1][j1].occupier]->setup(i1, j1, squares[i1][j1].squarePos, "black", 0);
							upSwitcher = true;
							cout << "Knight Upgrade! Where switchChoice == " << switchChoice << endl;

							break;
						}
						else if (switchChoice == 'b') {
							pieceArray[squares[i1][j1].occupier] = new Bishop;
							pieceArray[squares[i1][j1].occupier]->setup(i1, j1, squares[i1][j1].squarePos, "black", 0);
							upSwitcher = true;
							cout << "Bishop Upgrade! Where switchChoice == " << switchChoice << endl;

							break;
						}
						else if (switchChoice == 'r') {
							pieceArray[squares[i1][j1].occupier] = new Rook;
							pieceArray[squares[i1][j1].occupier]->setup(i1, j1, squares[i1][j1].squarePos, "black", 0);
							upSwitcher = true;
							cout << "Rook Upgrade! Where switchChoice == " << switchChoice << endl;
							break;
						}
						else {
							cout << "upSwitcher == " << upSwitcher << ", switchChoice == " << switchChoice << endl;
						}
						cout << "upgrade!" << endl;

					}
				}

				//updating piece variables
				pieceArray[squares[i1][j1].occupier]->x = squares[i2][j2].x;
				pieceArray[squares[i1][j1].occupier]->y = squares[i2][j2].y;
				pieceArray[squares[i1][j1].occupier]->squarePos = squares[i2][j2].squarePos;
				pieceArray[squares[i1][j1].occupier]->moveHistory = 0;

				//transferring square occupier data
				squares[i2][j2].occupier = squares[i1][j1].occupier;
				squares[i2][j2].occupierTeamInt = squares[i1][j1].occupierTeamInt;

				squares[i1][j1].occupier = NULL;
				squares[i1][j1].occupierTeamInt = NULL;

				squares[i2][j2].occupied = true;
				squares[i1][j1].occupied = false;

				squares[i1][j1].clicked = false;



				//Change turns
				turnModulo = (turnModulo + 1) % 2;
			}
			//otherwise, disallow the move
			else {
				squares[i1][j1].clicked = false;
				cout << "No move for you!" << endl;
			}

		}
		//Pawn Attack Logic - if the pawn is moving to an enemy-occupied square one space to either side and one space down if black or one space up if white,
		//allow the move and deactivate the defending piece
		else if (squares[i2][j2].occupied == true &&
			(squares[i1][j1].occupierTeamInt == 0 && (squares[i2][j2].squarePos == squares[i1][j1].squarePos - 9 || squares[i2][j2].squarePos == squares[i1][j1].squarePos + 7)) ||
			(squares[i1][j1].occupierTeamInt == 1 && (squares[i2][j2].squarePos == squares[i1][j1].squarePos + 9 || squares[i2][j2].squarePos == squares[i1][j1].squarePos - 7))) {

			//If the pawn has reached the end of the board, upgrade it to a queen - white or black, depending on which side of the board its touched

			if (j2 == 0) {
				bool upSwitcher = false;
				while (!upSwitcher) {
					char switchChoice = cin.get();
					string trashCan;
					getline(cin, trashCan);
					if (switchChoice == 'q') {
						pieceArray[squares[i1][j1].occupier] = new Queen;
						pieceArray[squares[i1][j1].occupier]->setup(i1, j1, squares[i1][j1].squarePos, "white", 0);
						upSwitcher = true;
						cout << "Queen Upgrade! Where switchChoice == " << switchChoice << endl;

						break;
					}
					else if (switchChoice == 'k') {
						pieceArray[squares[i1][j1].occupier] = new Knight;
						pieceArray[squares[i1][j1].occupier]->setup(i1, j1, squares[i1][j1].squarePos, "white", 0);
						upSwitcher = true;
						cout << "Knight Upgrade! Where switchChoice == " << switchChoice << endl;

						break;
					}
					else if (switchChoice == 'b') {
						pieceArray[squares[i1][j1].occupier] = new Bishop;
						pieceArray[squares[i1][j1].occupier]->setup(i1, j1, squares[i1][j1].squarePos, "white", 0);
						upSwitcher = true;
						cout << "Bishop Upgrade! Where switchChoice == " << switchChoice << endl;
						break;
					}
					else if (switchChoice == 'r') {
						pieceArray[squares[i1][j1].occupier] = new Rook;
						pieceArray[squares[i1][j1].occupier]->setup(i1, j1, squares[i1][j1].squarePos, "white", 0);
						upSwitcher = true;
						cout << "Rook Upgrade! Where switchChoice == " << switchChoice << endl;
						break;
					}
					else {
						cout << "Please input either q for a queen, k for a knight, b for a bishop, or r for a rook (upgrade)" << endl;
						cout << "upSwitcher == " << upSwitcher << ", switchChoice == " << switchChoice << endl;

					}
				}
			}
			else if (j2 == 7) {
				char switchChoice = cin.get();
				bool upSwitcher = false;
				string trashCan;
				getline(cin, trashCan);
				while (!upSwitcher) {
					if (switchChoice == 'q') {
						pieceArray[squares[i1][j1].occupier] = new Queen;
						pieceArray[squares[i1][j1].occupier]->setup(i1, j1, squares[i1][j1].squarePos, "black", 0);
						upSwitcher = true;
						cout << "Queen Upgrade! Where switchChoice == " << switchChoice << endl;

						break;
					}
					else if (switchChoice == 'k') {
						pieceArray[squares[i1][j1].occupier] = new Knight;
						pieceArray[squares[i1][j1].occupier]->setup(i1, j1, squares[i1][j1].squarePos, "black", 0);
						upSwitcher = true;
						cout << "Knight Upgrade! Where switchChoice == " << switchChoice << endl;

						break;
					}
					else if (switchChoice == 'b') {
						pieceArray[squares[i1][j1].occupier] = new Bishop;
						pieceArray[squares[i1][j1].occupier]->setup(i1, j1, squares[i1][j1].squarePos, "black", 0);
						upSwitcher = true;
						cout << "Bishop Upgrade! Where switchChoice == " << switchChoice << endl;

						break;
					}
					else if (switchChoice == 'r') {
						pieceArray[squares[i1][j1].occupier] = new Rook;
						pieceArray[squares[i1][j1].occupier]->setup(i1, j1, squares[i1][j1].squarePos, "black", 0);
						upSwitcher = true;
						cout << "Rook Upgrade! Where switchChoice == " << switchChoice << endl;
						break;
					}
					else {
						cout << "upSwitcher == " << upSwitcher << ", switchChoice == " << switchChoice << endl;
					}
					cout << "upgrade!" << endl;

				}
			}

			//updating piece variables
			pieceArray[squares[i2][j2].occupier]->active = false;
			pieceArray[squares[i1][j1].occupier]->x = squares[i2][j2].x;
			pieceArray[squares[i1][j1].occupier]->y = squares[i2][j2].y;
			pieceArray[squares[i1][j1].occupier]->squarePos = squares[i2][j2].squarePos;
			pieceArray[squares[i1][j1].occupier]->moveHistory = 0;

			//transferring square occupier data
			squares[i2][j2].occupier = squares[i1][j1].occupier;
			squares[i2][j2].occupierTeamInt = squares[i1][j1].occupierTeamInt;

			squares[i1][j1].occupier = NULL;
			squares[i1][j1].occupierTeamInt = NULL;

			squares[i2][j2].occupied = true;
			squares[i1][j1].occupied = false;

			squares[i1][j1].clicked = false;




			//change turns
			turnModulo = (turnModulo + 1) % 2;

		}
		else {
			squares[i1][j1].clicked = false;
		}
	}
	else if (pieceArray[squares[i1][j1].occupier]->type == "rook" || (pieceArray[squares[i1][j1].occupier]->type == "queen" && (j1 == j2 || i1 == i2))) {
		bool switcher = false;
		//if we are moving horizontally, iterate through every square between start and target square
		//If there is a piece obstructing the path, disallow the move
		if (j1 == j2) {
			//if we are moving left
			if (i1 > i2) {
				for (int i = 1; i < (i1 - i2); i += 8) {
					if (squares[i2 + i][j1].occupied) {
						switcher = true;
						cout << "Rook//Queen hoz path obstructed left" << endl;
						break;
					}
				}
			//if we are moving right
			}
			else if (i2 > i1) {
				for (int i = 1; i < (i2 - i1); i += 8) {
					if (squares[i1 + i][j1].occupied) {
						switcher = true;
						cout << "Rook//Queen hoz path obstructed right" << endl;
						break;
					}
				}
			}
			//if we are moving vertically, iterate through every square between start and target square
			//if a piece obstructs the path, disallow the move
		}
		else if (i1 == i2) {
			cout << i1 << " " << i2 << endl;
			//if we are moving up
			if (j1 > j2) {
				for (int i = 1; i < (j1 - j2); i++) {
					if (squares[i1][j2 + i].occupied) {
						switcher = true;
						cout << "Rook//Queen vert path obstructed up" << endl;
						break;
					}
				}
				//if we are moving down
			}
			else if (j2 > j1) {
				for (int i = 1; i < (j2 - j1); i++) {
					if (squares[i1][j1 + i].occupied) {
						switcher = true;
						cout << "Rook//Queen vert path obstructed down" << endl;
						break;
					}
				}
			}
			//if no pieces obstruct the path, run the following code
		}
		else {
			switcher = true;
		}
		if (switcher == false) {

			//disabling the defending piece if the move is an attack
			if (squares[i2][j2].occupied == true) {
				pieceArray[squares[i2][j2].occupier]->active = false;
			}

			//moving the piece to its new square
			pieceArray[squares[i1][j1].occupier]->x = squares[i2][j2].x;
			pieceArray[squares[i1][j1].occupier]->y = squares[i2][j2].y;
			pieceArray[squares[i1][j1].occupier]->squarePos = squares[i2][j2].squarePos;
			//vestigial
			pieceArray[squares[i1][j1].occupier]->moveHistory = 0;

			//transferring square occupier data
			squares[i2][j2].occupier = squares[i1][j1].occupier;
			squares[i2][j2].occupierTeamInt = squares[i1][j1].occupierTeamInt;

			squares[i1][j1].occupier = NULL;
			squares[i1][j1].occupierTeamInt = NULL;

			squares[i2][j2].occupied = true;
			squares[i1][j1].occupied = false;

			squares[i1][j1].clicked = false;

			//change turns
			turnModulo = (turnModulo + 1) % 2;
		}
		else {
			//
			squares[i1][j1].clicked = false;
			cout << "invalid rook//queen move!" << endl;
		}
	}
	else if (pieceArray[squares[i1][j1].occupier]->type == "bishop" || pieceArray[squares[i1][j1].occupier]->type == "queen") {
	bool switcher = false;
	//the below code checks if a bishop's path is obstructed. If it is obstructed, disallow the move
	//moving up left
	if (i1 > i2 &&
		j1 > j2 &&
		i1 - i2 == j1 - j2) {
		for (int x = 1; x < (i1 - i2); x++) {
			if (squares[i1 - x][j1 - x].occupied == true) {
				switcher = true;
			}
		}
	//moving up right
	}
	else if (i1 < i2 &&	j1 > j2 && abs(i1 - i2) == abs(j1 - j2)) {
		for (int x = 1; x < (i2 - i1); x++) {
			if (squares[i1 + x][j1 - x].occupied == true) {
				switcher = true;
			}
		}
		//moving down left
	}
	else if (i1 > i2 &&
		j1 < j2 &&
		abs(i1 - i2) == abs(j1 - j2)) {
		for (int x = 1; x < (i1 - i2); x++) {
			if (squares[i1 - x][j1 + x].occupied == true) {
				switcher = true;
			}
		}
		//moving down right
	}
	else if (i1 < i2 &&
		j1 < j2 &&
		(i1 - i2) == (j1 - j2)) {
		for (int x = 1; x < (i2 - i1); x++) {
			if (squares[i1 + x][j1 + x].occupied == true) {
				switcher = true;
			}
			else {
			}
		}
	}
	else {
		cout << "Invalid Bishop//Queen Move" << endl;
		switcher = true;
	}
	//if no pieces obstruct the path, run the following code
	if (switcher == false) {

			//deactivate the defending piece if this move is an attack
			if (squares[i2][j2].occupied == true) {
				pieceArray[squares[i2][j2].occupier]->active = false;
			}


		pieceArray[squares[i1][j1].occupier]->x = squares[i2][j2].x;
		pieceArray[squares[i1][j1].occupier]->y = squares[i2][j2].y;
		pieceArray[squares[i1][j1].occupier]->squarePos = squares[i2][j2].squarePos;

		//transferring square occupier data
		squares[i2][j2].occupier = squares[i1][j1].occupier;
		squares[i2][j2].occupierTeamInt = squares[i1][j1].occupierTeamInt;

		squares[i1][j1].occupier = NULL;
		squares[i1][j1].occupierTeamInt = NULL;

		squares[i2][j2].occupied = true;
		squares[i1][j1].occupied = false;

		squares[i1][j1].clicked = false;


		turnModulo = (turnModulo + 1) % 2; 
	}
	else {
		squares[i1][j1].clicked = false;
		cout << "invalid bishop//queen move 2" << endl;
	}
	}
	else if (pieceArray[squares[i1][j1].occupier]->type == "knight") {

		//the below code creates an array corresponding to the target square (c1) and each legal vector of movement for a knight (c2 - c9)
	//target square
	std::array<int,2> c1 { i2, j2 };
	//1 o'clock
	std::array<int,2> c2 { i1 - 1, j1 - 2 };
	//2 o'clock
	std::array<int,2> c3{ i1 - 2, j1 - 1 };
	//4 o'clock
	std::array<int,2> c4 {i1 - 2, j1 + 1};
	//5 o'clock
	std::array<int,2> c5 {i1 - 1, j1 + 2};
	//7 o'clock
	std::array<int,2> c6{i1 + 1, j1 + 2};
	//8 o'clock
	std::array<int,2> c7 {i1 + 2, j1 + 1};
	//10 o'clock
	std::array<int,2> c8{i1 + 2, j1 - 1};
	//11 o'clock
	std::array<int,2> c9{i1 + 1, j1 - 2};
		
		//below code compares the target square to each possible vector of movement for a knight. 
		//if the target square matches any of them, allow the movement checking process to continue
		
		bool switcher = NULL;
		if (c1 == c2 || c1 == c3 || c1 == c4 || c1 == c5 || c1 == c6 || c1 == c7 || c1 == c8|| c1 == c9) {
			switcher = false;
		}
		else {
			switcher = true;
		}

		if (switcher == false) {


				//updating piece variables
				if (squares[i2][j2].occupied == true) {
					pieceArray[squares[i2][j2].occupier]->active = false;
				}

			//updating piece information
			pieceArray[squares[i1][j1].occupier]->x = squares[i2][j2].x;
			pieceArray[squares[i1][j1].occupier]->y = squares[i2][j2].y;
			pieceArray[squares[i1][j1].occupier]->squarePos = squares[i2][j2].squarePos;

			//transferring square occupier data
			squares[i2][j2].occupier = squares[i1][j1].occupier;
			squares[i2][j2].occupierTeamInt = squares[i1][j1].occupierTeamInt;

			//updating occupaction status
			squares[i1][j1].occupier = NULL;
			squares[i1][j1].occupierTeamInt = NULL;

			squares[i2][j2].occupied = true;
			squares[i1][j1].occupied = false;

			squares[i1][j1].clicked = false;


			turnModulo = (turnModulo + 1) % 2;
		}
		else {
			squares[i1][j1].clicked = false;
			cout << "invalid Knight move 2" << endl;
		}
	}        //KING MOVEMENT LOGIC
	else if (pieceArray[squares[i1][j1].occupier]->type == "king") {
		if (abs(i1 - i2) < 2 && abs(j1 - j2) < 2) {

				 //updating piece variables
			if (squares[i2][j2].occupied == true) {
				pieceArray[squares[i2][j2].occupier]->active = false;
			}
			pieceArray[squares[i1][j1].occupier]->x = squares[i2][j2].x;
			pieceArray[squares[i1][j1].occupier]->y = squares[i2][j2].y;
			pieceArray[squares[i1][j1].occupier]->squarePos = squares[i2][j2].squarePos;

			//transferring square occupier data
			squares[i2][j2].occupier = squares[i1][j1].occupier;
			squares[i2][j2].occupierTeamInt = squares[i1][j1].occupierTeamInt;

			squares[i1][j1].occupier = NULL;
			squares[i1][j1].occupierTeamInt = NULL;

			squares[i2][j2].occupied = true;
			squares[i1][j1].occupied = false;

			squares[i1][j1].clicked = false;


			turnModulo = (turnModulo + 1) % 2;
		}
		else {
			squares[i1][j1].clicked = false;
		}
	}
	else {
	//This should only happen if the piece moved doesn't have a type corresponding to one of the above pathways
	cout << "Something has gone deeply, deeply wrong" << endl;
	}
}



//--------------------------------------------------------------
void ofApp::update() {
}

//--------------------------------------------------------------
void ofApp::draw() {

	boardVar.draw(squares);
	for (int i = 0; i < 32; i++) {
		pieceArray[i]->draw();
	}




}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	//cout << x << "," << y << endl;

	if (clickerCount == 0) {
		bool broken = false;
		for (int i = 0; i < 8; i++) {
			if (broken == true) {
				break;
			}
			for (int j = 0; j < 8; j++) {
				if (squares[i][j].inRange) {
					//If the square is occupied by the person whose turn it is, mark it as clicked and get ready to move the piece
					if (squares[i][j].occupied == true &&
						squares[i][j].occupierTeamInt == turnModulo) {
						squares[i][j].clicked = true;
						firstClickedX = i;
						firstClickedY = j;
						clickerCount = abs((clickerCount + 1) % 2);
						cout << squares[i][j].occupierTeamInt << endl;
						broken = true;
						break;
					}
					else if (squares[i][j].occupied == true &&
						squares[i][j].occupierTeamInt != turnModulo) {
						cout << "It's not your turn!" << endl;
						broken = true;
						break;
					}
					else {
						broken = true;
						break;
					}
				}
			}
		}
	}
	else if (clickerCount == 1) {
		bool broken = false;
		for (int i = 0; i < 8; i++) {
			if (broken == true) {
				break;
			}
			for (int j = 0; j < 8; j++) {
				//if the player tries to move to a square occupied by their own piece, disallow the move
				if (squares[i][j].inRange &&
					squares[i][j].occupied == true &&
					squares[i][j].occupierTeamInt == turnModulo) {
					if (squares[i][j].clicked == true) {
						squares[i][j].clicked = false;
						clickerCount = abs((clickerCount - 1) % 2);
						cout << "Invalid move...1" << endl;
						broken = true;
						break;
					}
					else {
						squares[firstClickedX][firstClickedY].clicked = false;
						clickerCount = abs((clickerCount - 1) % 2);
						cout << "Invalid move...2" << endl;
						broken = true;
						break;
					}
				}
			else if (squares[i][j].inRange &&
				squares[i][j].occupied == false) {
					moveLogicCheck(firstClickedX, firstClickedY, i, j, pieceArray, squares);
					clickerCount = (clickerCount + 1) % 2;
					broken = true;
					break;
			}
			else if (squares[i][j].inRange &&
				squares[i][j].occupied == true &&
				squares[i][j].occupierTeamInt != turnModulo) {
						moveLogicCheck(firstClickedX, firstClickedY, i, j, pieceArray, squares);
					
			}
			else if (i == 7 && j == 7) {
				squares[firstClickedX][firstClickedY].clicked = false;
				clickerCount = (clickerCount + 1) % 2;

				}
			}
		} 
	}


}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
