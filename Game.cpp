#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string>
#include <fstream>
#include <cwchar>
#include <iomanip>

using namespace std;

#define black = 0;
#define blue = 1;
#define green = 2;
#define aqua = 3;
#define red = 4;
#define purple = 5;
#define yellow = 6;
#define white = 7;
#define gray = 8;
#define light_blue = 9;
#define light_green = 10;
#define light_aqua = 11;
#define light_red = 12;
#define light_purple = 13;
#define light_yellow = 14;
#define bright_white = 15;


enum Direction { Up, Down, Left, Right };



struct Position {
	int ri;
	int ci;
};



struct snake {

	Position* body;
	int size;
	Direction dir;
	char head;
	char tailnbody;
	int color;
	int score;
	int speed;
	int leftkey;
	int rightkey;
	int upkey;
	int downkey;
	int level;
	string name;

};



struct food {

	Position pos;
	bool is_active;
	int score;
	int color;
	char symbol;

};



struct bigfood {

	Position pos;
	bool is_active;
	int score;
	int color;
	char symbol;
	int time;
};



void gotoxy(int x, int y) {

	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}



void setcolor(int color, int background_color = 0) {
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, background_color * 16 + color);
}




void print_alphabet_A(int x, int y) {
	char sym = -37;
	gotoxy(x, y);
	cout << "  " << sym << "  ";
	gotoxy(x, y + 1);
	cout << " " << sym << " " << sym << " ";
	gotoxy(x, y + 2);
	cout << sym << sym <<sym << sym << sym;
	gotoxy(x, y + 3);
	cout << sym << " " << " " << " " << sym;
	gotoxy(x, y + 4);
	cout << sym << " " << " " << " " << sym;
}

void print_alphabet_B(int x, int y) {
	char sym = -37;
	gotoxy(x, y);
	cout << sym << sym << sym << sym;
	gotoxy(x, y + 1);
	cout << sym << " " << " " << sym;
	gotoxy(x, y + 2);
	cout << sym << sym << sym << sym;
	gotoxy(x, y + 3);
	cout << sym << " " << " " << sym;
	gotoxy(x, y + 4);
	cout << sym << sym << sym << sym;
}

void print_alphabet_C(int x, int y) {
	char sym = -37;
	gotoxy(x, y);
	cout << sym << sym << sym << sym;
	gotoxy(x, y + 1);
	cout << sym << " " << " " << " ";
	gotoxy(x, y + 2);
	cout << sym << " " << " " << " ";
	gotoxy(x, y + 3);
	cout << sym << " " << " " << " ";
	gotoxy(x, y + 4);
	cout << sym << sym << sym << sym;
}

void print_alphabet_D(int x, int y) {
	char sym = -37;
	gotoxy(x, y);
	cout << sym << sym << sym << " ";
	gotoxy(x, y + 1);
	cout << sym << " " << " " << sym;
	gotoxy(x, y + 2);
	cout << sym << " " << " " << sym;
	gotoxy(x, y + 3);
	cout << sym << " " << " " << sym;
	gotoxy(x, y + 4);
	cout << sym << sym << sym << " ";
}

void print_alphabet_E(int x, int y) {
	char sym = -37;
	gotoxy(x, y);
	cout << sym << sym << sym << sym;
	gotoxy(x, y + 1);
	cout << sym << " " << " " << " ";
	gotoxy(x, y + 2);
	cout << sym << sym << sym << sym;
	gotoxy(x, y + 3);
	cout << sym << " " << " " << " ";
	gotoxy(x, y + 4);
	cout << sym << sym << sym << sym;
}

void print_alphabet_F(int x, int y) {
	char sym = -37;
	gotoxy(x, y);
	cout << sym << sym << sym << sym;
	gotoxy(x, y + 1);
	cout << sym << " " << " " << " ";
	gotoxy(x, y + 2);
	cout << sym << sym << sym << " ";
	gotoxy(x, y + 3);
	cout << sym << " " << " " << " ";
	gotoxy(x, y + 4);
	cout << sym << " " << " " << " ";
}

void print_alphabet_G(int x, int y) {
	char sym = -37;
	gotoxy(x, y);
	cout << sym << sym << sym << sym;
	gotoxy(x, y + 1);
	cout << sym << " " << " " << " ";
	gotoxy(x, y + 2);
	cout << sym << " " << sym << sym;
	gotoxy(x, y + 3);
	cout << sym << " " << " " << sym;
	gotoxy(x, y + 4);
	cout << sym << sym << sym << sym;
}


void print_alphabet_H(int x, int y) {
	char sym = -37;
	gotoxy(x, y);
	cout << sym << " " << " " << sym;
	gotoxy(x, y + 1);
	cout << sym << " " << " " << sym;
	gotoxy(x, y + 2);
	cout << sym << sym << sym << sym;
	gotoxy(x, y + 3);
	cout << sym << " " << " " << sym;
	gotoxy(x, y + 4);
	cout << sym << " " << " " << sym;
}


void print_alphabet_I(int x, int y) {
	char sym = -37;
	gotoxy(x, y);
	cout << sym << sym << sym << sym << sym;
	gotoxy(x, y + 1);
	cout << " " <<  " " << sym << " " << " ";
	gotoxy(x, y + 2);
	cout << " " << " " << sym << " " << " ";
	gotoxy(x, y + 3);
	cout << " " << " " << sym << " " << " ";
	gotoxy(x, y + 4);
	cout << sym << sym << sym << sym << sym;
}


void print_alphabet_J(int x, int y) {
	char sym = -37;
	gotoxy(x, y);
	cout << sym << sym << sym << sym;
	gotoxy(x, y + 1);
	cout << " " << " " << sym << " ";
	gotoxy(x, y + 2);
	cout << " " << " " << sym << " ";
	gotoxy(x, y + 3);
	cout << sym << " " << sym << " ";
	gotoxy(x, y + 4);
	cout << sym << sym << sym << " ";
}


void print_alphabet_K(int x, int y) {
	char sym = -37;
	gotoxy(x, y);
	cout << sym << " " << " " << sym;
	gotoxy(x, y + 1);
	cout << sym << " " << sym << " ";
	gotoxy(x, y + 2);
	cout << sym << sym << " " << " ";
	gotoxy(x, y + 3);
	cout << sym << " " << sym << " ";
	gotoxy(x, y + 4);
	cout << sym << " " << " " << sym;
}


void print_alphabet_L(int x, int y) {
	char sym = -37;
	gotoxy(x, y);
	cout << sym << " " << " " << " ";
	gotoxy(x, y + 1);
	cout << sym << " " << " " << " ";
	gotoxy(x, y + 2);
	cout << sym << " " << " " << " ";
	gotoxy(x, y + 3);
	cout << sym << " " << " " << " ";
	gotoxy(x, y + 4);
	cout << sym << sym << sym << sym;
}


void print_alphabet_M(int x, int y) {
	char sym = -37;
	gotoxy(x, y);
	cout << sym << " " << " " << " " << sym;
	gotoxy(x, y + 1);
	cout << sym << sym << " " << sym << sym;
	gotoxy(x, y + 2);
	cout << sym << " " << sym << " " << sym;
	gotoxy(x, y + 3);
	cout << sym << " " << " " << " " << sym;
	gotoxy(x, y + 4);
	cout << sym << " " << " " << " " << sym;
}


void print_alphabet_N(int x, int y) {
	char sym = -37;
	gotoxy(x, y);
	cout << sym << " " << " " << " " << sym;
	gotoxy(x, y + 1);
	cout << sym << sym << " " << " " << sym;
	gotoxy(x, y + 2);
	cout << sym << " " << sym << " " << sym;
	gotoxy(x, y + 3);
	cout << sym << " " << " " << sym << sym;
	gotoxy(x, y + 4);
	cout << sym << " " << " " << " " << sym;
}


void print_alphabet_O(int x, int y) {
	char sym = -37;
	gotoxy(x, y);
	cout << sym << sym << sym << sym;
	gotoxy(x, y + 1);
	cout << sym << " " << " " << sym;
	gotoxy(x, y + 2);
	cout << sym << " " << " " << sym;
	gotoxy(x, y + 3);
	cout << sym << " " << " " << sym;
	gotoxy(x, y + 4);
	cout << sym << sym << sym << sym;
}


void print_alphabet_P(int x, int y) {
	char sym = -37;
	gotoxy(x, y);
	cout << sym << sym << sym << sym;
	gotoxy(x, y + 1);
	cout << sym << " " << " " << sym;
	gotoxy(x, y + 2);
	cout << sym << sym << sym << sym;
	gotoxy(x, y + 3);
	cout << sym << " " << " " << " ";
	gotoxy(x, y + 4);
	cout << sym << " " << " " << " ";
}



void print_alphabet_Q(int x, int y) {
	char sym = -37;
	gotoxy(x, y);
	cout << sym << sym << sym << sym;
	gotoxy(x, y + 1);
	cout << sym << " " << " " << sym;
	gotoxy(x, y + 2);
	cout << sym << " " << " " << sym;
	gotoxy(x, y + 3);
	cout << sym << sym << sym << sym;
	gotoxy(x, y + 4);
	cout << " " << " " << sym << " ";
}


void print_alphabet_R(int x, int y) {
	char sym = -37;
	gotoxy(x, y);
	cout << sym << sym << sym << sym;
	gotoxy(x, y + 1);
	cout << sym << " " << " " << sym;
	gotoxy(x, y + 2);
	cout << sym << sym << sym << sym;
	gotoxy(x, y + 3);
	cout << sym << " " << sym << " ";
	gotoxy(x, y + 4);
	cout << sym << " " << " " << sym;
}


void print_alphabet_S(int x, int y) {
	char sym = -37;
	gotoxy(x, y);
	cout << sym << sym << sym << sym;
	gotoxy(x, y + 1);
	cout << sym << " " << " " << " ";
	gotoxy(x, y + 2);
	cout << sym << sym << sym << sym;
	gotoxy(x, y + 3);
	cout << " " << " " << " " << sym;
	gotoxy(x, y + 4);
	cout << sym << sym << sym << sym;
}


void print_alphabet_T(int x, int y) {
	char sym = -37;
	gotoxy(x, y);
	cout << sym << sym << sym << sym << sym;
	gotoxy(x, y + 1);
	cout << " " << " " << sym << " " << " ";
	gotoxy(x, y + 2);
	cout << " " << " " << sym << " " << " ";
	gotoxy(x, y + 3);
	cout << " " << " " << sym << " " << " ";
	gotoxy(x, y + 4);
	cout << " " << " " << sym << " " << " ";
}


void print_alphabet_U(int x, int y) {
	char sym = -37;
	gotoxy(x, y);
	cout << sym << " " << " " << sym;
	gotoxy(x, y + 1);
	cout << sym << " " << " " << sym;
	gotoxy(x, y + 2);
	cout << sym << " " << " " << sym;
	gotoxy(x, y + 3);
	cout << sym << " " << " " << sym;
	gotoxy(x, y + 4);
	cout << sym << sym << sym << sym;
}


void print_alphabet_V(int x, int y) {
	char sym = -37;
	gotoxy(x, y);
	cout << sym << " " << " " << " " << sym;
	gotoxy(x, y + 1);
	cout << sym << " " << " " << " " << sym;
	gotoxy(x, y + 2);
	cout << sym << " " << " " << " " << sym;
	gotoxy(x, y + 3);
	cout << " " << sym << " " << sym << " ";
	gotoxy(x, y + 4);
	cout << " " << " " << sym << " " << " ";
}


void print_alphabet_W(int x, int y) {
	char sym = -37;
	gotoxy(x, y);
	cout << sym << " " << " " << " " << sym;
	gotoxy(x, y + 1);
	cout << sym << " " << " " << " " << sym;
	gotoxy(x, y + 2);
	cout << sym << " " << sym << " " << sym;
	gotoxy(x, y + 3);
	cout << sym << sym << " " << sym << sym;
	gotoxy(x, y + 4);
	cout << sym << " " << " " << " " << sym;
}



void print_alphabet_X(int x, int y) {
	char sym = -37;
	gotoxy(x, y);
	cout << sym << " " << " " << " " << sym;
	gotoxy(x, y + 1);
	cout << " " << sym << " " << sym << " ";
	gotoxy(x, y + 2);
	cout << " " << " " << sym << " " << " ";
	gotoxy(x, y + 3);
	cout << " " << sym << " " << sym << " ";
	gotoxy(x, y + 4);
	cout << sym << " " << " " << " " << sym;
}



void print_alphabet_Y(int x, int y) {
	char sym = -37;
	gotoxy(x, y);
	cout << sym << " " << " " << " " << sym;
	gotoxy(x, y + 1);
	cout << " " << sym << " " << sym << " ";
	gotoxy(x, y + 2);
	cout << " " << " " << sym << " " << " ";
	gotoxy(x, y + 3);
	cout << " " << " " << sym << " " << " ";
	gotoxy(x, y + 4);
	cout << " " << " " << sym << " " << " ";
}


void print_alphabet_Z(int x, int y) {
	char sym = -37;
	gotoxy(x, y);
	cout << sym << sym << sym << sym << sym;
	gotoxy(x, y + 1);
	cout << " " << " " << " " << sym;
	gotoxy(x, y + 2);
	cout << " " << " " << sym << " " << " ";
	gotoxy(x, y + 3);
	cout << " " << sym << " " << " " << " ";
	gotoxy(x, y + 4);
	cout << sym << sym << sym << sym << sym;
}


void print_digit_0(int x, int y) {
	char sym = -37;
	gotoxy(x, y);
	cout << sym << sym << sym;
	gotoxy(x, y + 1);
	cout << sym << " " << sym;
	gotoxy(x, y + 2);
	cout << sym << " " << sym;
	gotoxy(x, y + 3);
	cout << sym << " " << sym;
	gotoxy(x, y + 4);
	cout << sym << sym << sym;
}


void print_digit_1(int x, int y) {
	char sym = -37;
	gotoxy(x, y);
	cout << " " << sym << " ";
	gotoxy(x, y + 1);
	cout << sym << sym << " ";
	gotoxy(x, y + 2);
	cout << " " << sym << " ";
	gotoxy(x, y + 3);
	cout << " " << sym << " ";
	gotoxy(x, y + 4);
	cout << sym << sym << sym;
}


void print_digit_2(int x, int y) {
	char sym = -37;
	gotoxy(x, y);
	cout << sym << sym << sym;
	gotoxy(x, y + 1);
	cout << " " << " " << sym;
	gotoxy(x, y + 2);
	cout << sym << sym << sym;
	gotoxy(x, y + 3);
	cout << sym << " " << " ";
	gotoxy(x, y + 4);
	cout << sym << sym << sym;
}


void print_digit_3(int x, int y) {
	char sym = -37;
	gotoxy(x, y);
	cout << sym << sym << sym;
	gotoxy(x, y + 1);
	cout << " " << " " << sym;
	gotoxy(x, y + 2);
	cout << sym << sym << sym;
	gotoxy(x, y + 3);
	cout << " " << " " << sym;
	gotoxy(x, y + 4);
	cout << sym << sym << sym;
}



void print_digit_4(int x, int y) {
	char sym = -37;
	gotoxy(x, y);
	cout << sym << " " << sym;
	gotoxy(x, y + 1);
	cout << sym << " " << sym;
	gotoxy(x, y + 2);
	cout << sym << sym << sym;
	gotoxy(x, y + 3);
	cout << " " << " " << sym;
	gotoxy(x, y + 4);
	cout << " " << " " << sym;
}



void print_digit_5(int x, int y) {
	char sym = -37;
	gotoxy(x, y);
	cout << sym << sym << sym;
	gotoxy(x, y + 1);
	cout << sym << " " << " ";
	gotoxy(x, y + 2);
	cout << sym << sym << sym;
	gotoxy(x, y + 3);
	cout << " " << " " << sym;
	gotoxy(x, y + 4);
	cout << sym << sym << sym;
}



void print_digit_6(int x, int y) {
	char sym = -37;
	gotoxy(x, y);
	cout << sym << sym << sym;
	gotoxy(x, y + 1);
	cout << sym << " " << " ";
	gotoxy(x, y + 2);
	cout << sym << sym << sym;
	gotoxy(x, y + 3);
	cout << sym << " " << sym;
	gotoxy(x, y + 4);
	cout << sym << sym << sym;
}



void print_digit_7(int x, int y) {
	char sym = -37;
	gotoxy(x, y);
	cout << sym << sym << sym;
	gotoxy(x, y + 1);
	cout << " " << " " << sym;
	gotoxy(x, y + 2);
	cout << " " << " " << sym;
	gotoxy(x, y + 3);
	cout << " " << " " << sym;
	gotoxy(x, y + 4);
	cout << " " << " " << sym;
}



void print_digit_8(int x, int y) {
	char sym = -37;
	gotoxy(x, y);
	cout << sym << sym << sym;
	gotoxy(x, y + 1);
	cout << sym << " " << sym;
	gotoxy(x, y + 2);
	cout << sym << sym << sym;
	gotoxy(x, y + 3);
	cout << sym << " " << sym;
	gotoxy(x, y + 4);
	cout << sym << sym << sym;
}



void print_digit_9(int x, int y) {
	char sym = -37;
	gotoxy(x, y);
	cout << sym << sym << sym;
	gotoxy(x, y + 1);
	cout << sym << " " << sym;
	gotoxy(x, y + 2);
	cout << sym << sym << sym;
	gotoxy(x, y + 3);
	cout << " " << " " << sym;
	gotoxy(x, y + 4);
	cout << sym << sym << sym;
}




void draw_box_in_middle(int boxheight, int boxwidth, int screenheight, int screenwidth) {

	setcolor(4, 0);
	int startx;
	int starty;

	startx = (screenwidth - boxwidth) / 2;
	starty = (screenheight - boxheight) / 2;

	for (int i = 0; i < boxheight; i++) {
		for (int j = 0; j < boxwidth; j++) {
			if (i == 0 || i == boxheight - 1 || j == 0 || j == boxwidth - 1) {
				gotoxy(startx + j, starty + i);
				cout << char(219);
			}
		}
	}
	setcolor(7, 0);
}



bool islegalcoordinate(Position pos, snake& s, snake& s2, bigfood& bf, int rightedge, int leftedge, int topedge, int bottomedge, bool multiplayer) {

	for (int i = 0; i < s.size; i++) {
		if (pos.ri == s.body[i].ri && pos.ci == s.body[i].ci) {
			return false;
		}
	}

	if (multiplayer == true) {
		for (int i = 0; i < s2.size; i++) {
			if (pos.ri == s2.body[i].ri && pos.ci == s2.body[i].ci) {
				return false;
			}
		}
	}

	if (bf.is_active) {

		if ((pos.ri == bf.pos.ri && pos.ci == bf.pos.ci) || 
			(pos.ri == bf.pos.ri && pos.ci == bf.pos.ci + 1) || 
			(pos.ri == bf.pos.ri && pos.ci == bf.pos.ci - 1) || 
			(pos.ri == bf.pos.ri + 1 && pos.ci == bf.pos.ci) || 
			(pos.ri == bf.pos.ri + 1 && pos.ci == bf.pos.ci + 1) || 
			(pos.ri == bf.pos.ri + 1 && pos.ci == bf.pos.ci - 1) || 
			(pos.ri == bf.pos.ri - 1 && pos.ci == bf.pos.ci) || 
			(pos.ri == bf.pos.ri - 1 && pos.ci == bf.pos.ci + 1) || 
			(pos.ri == bf.pos.ri - 1 && pos.ci == bf.pos.ci - 1)) {
			return false;
		}

	}

	if ((pos.ci > rightedge || pos.ci < leftedge) || (pos.ri < topedge || pos.ri > bottomedge)) {
		return false;
	}

	return true;

}

void generate_food(food& f, int boxheight, int boxwidth, snake& s, snake& s2, bool multiplayer, bigfood& bf) {

	int rightedge = boxwidth + 13;
	int leftedge = 15;
	int topedge = 5;
	int bottomedge = boxheight + 3;

	do {
		f.pos.ri = (rand() % (boxheight)) + 4;
		f.pos.ci = (rand() % (boxwidth)) + 14;
	} while (!islegalcoordinate(f.pos, s, s2, bf, rightedge, leftedge, topedge, bottomedge, multiplayer));

	f.is_active = true;
	f.score = 10 * s.level;
	f.color = 2;
	f.symbol = '*';

}



void innit(snake& s, snake& s2, food &f, int screenheight, int screenwidth, int boxheight, int boxwidth, bool multiplayer, bigfood& bf) {

	s.body = new Position[3];
	s.body[0].ri = screenheight / 2 - 8;
	s.body[0].ci = screenwidth / 2;
	s.body[1].ri = screenheight / 2 - 8;
	s.body[1].ci = screenwidth / 2-1;
	s.body[2].ri = screenheight / 2 - 8;
	s.body[2].ci = screenwidth / 2-2;

	s.size = 3;
	s.dir = Right;
	s.head = 'O';
	s.tailnbody = -37;
	s.color = 3;
	s.score = 0;
	s.speed = 50;
	s.leftkey = 75;
	s.rightkey = 77;
	s.upkey = 72;
	s.downkey = 80;
	s.level = 1;
	s.name = "Player 1";


	s2.body = new Position[3];

	if (multiplayer == false) {
		s2.body[0].ri = 0;
		s2.body[0].ci = 0;
		s2.body[1].ri = 0;
		s2.body[1].ci = 0;
		s2.body[2].ri = 0;
		s2.body[2].ci = 0;

	}
	else {

		s2.body[0].ri = screenheight / 2 + 8;
		s2.body[0].ci = screenwidth / 2;
		s2.body[1].ri = screenheight / 2 + 8;
		s2.body[1].ci = screenwidth / 2 - 1;
		s2.body[2].ri = screenheight / 2 + 8;
		s2.body[2].ci = screenwidth / 2 - 2;
	}

	s2.size = 3;
	s2.dir = Right;
	s2.head = '<';
	s2.tailnbody = -37;
	s2.color = 5;
	s2.score = 0;
	s2.speed = 50;
	s2.leftkey = 97;
	s2.rightkey = 100;
	s2.upkey = 119;
	s2.downkey = 115;
	s2.level = 1;
	s2.name = "Player 2";

	generate_food(f, boxheight, boxwidth, s, s2, multiplayer, bf);
}


void display_game_description_bar(int score, int highscore, int level) {
	int startx;
	int starty;

	startx = 25;
	starty = 2;

	gotoxy(startx, starty);
	cout << "Score: " << score;

	gotoxy(startx + 30, starty);
	cout << "HighScore: " << highscore;

	gotoxy(startx + 60, starty);
	cout << "Level: " << level;
}

void display_game_description_bar_multiplayer(string name, int score, string name2, int score2, int color1, int color2) {
	int startx;
	int starty;

	startx = 25;
	starty = 3;

	setcolor(color1, 0);
	gotoxy(startx, starty);
	cout << name;
	setcolor(7, 0);

	gotoxy(startx + 20, starty);
	cout << "Score: " << score;

	setcolor(color2, 0);
	gotoxy(startx + 40, starty);
	cout << name2;
	setcolor(7, 0);

	gotoxy(startx + 60, starty);
	cout << "Score: " << score2;
}




void display_snake(const snake &s) {
	setcolor(s.color, 0);
	gotoxy(s.body[0].ci, s.body[0].ri);
	cout << s.head;

	for (int i = 1; i < s.size; i++) {
		gotoxy(s.body[i].ci, s.body[i].ri);
		cout << s.tailnbody;
	}
	setcolor(7, 0);
}

void display_snake_in_game(const snake& s) {

	setcolor(s.color, 0);
	gotoxy(s.body[0].ci, s.body[0].ri);
	cout << s.head;
	
	gotoxy(s.body[1].ci, s.body[1].ri);
	cout << s.tailnbody;
	setcolor(7, 0);
}

void display_food(const food& f) {
	setcolor(f.color, 0);
	gotoxy(f.pos.ci, f.pos.ri);
	cout << f.symbol;
	setcolor(7, 0);
}


void move_snake(snake& s, int boxheight, int boxwidth, bool wraparound, bool& gameover) {

	for (int i = s.size - 1; i > 0; i--) {
		s.body[i] = s.body[i - 1];
	}

	int rightedge = boxwidth + 14;
	int leftedge = 14;
	int topedge = 4;
	int bottomedge = boxheight + 4;

	if (s.dir == Right) {
		s.body[0].ci++;
		if (s.body[0].ci == rightedge) {
			if (!wraparound) {
				gameover = true;
				return;
			}
			s.body[0].ci = leftedge+1;
		}
		
	}
	else if (s.dir == Left) {
		s.body[0].ci--;
		if (s.body[0].ci == leftedge) {
			if (!wraparound) {
				gameover = true;
				return;
			}
			s.body[0].ci = rightedge-1;
		}
	}
	else if (s.dir == Up) {
		s.body[0].ri--;
		if (s.body[0].ri == topedge) {
			if (!wraparound) {
				gameover = true;
				return;
			}
			s.body[0].ri = bottomedge-1;
		}
	}
	else if (s.dir == Down) {
		s.body[0].ri++;
		if (s.body[0].ri == bottomedge) {
			if (!wraparound) {
				gameover = true;
				return;
			}
			s.body[0].ri = topedge+1;
		}
	}

	
}

bool is_food_eaten(snake &s, food &f) {
	return s.body[0].ri == f.pos.ri && s.body[0].ci == f.pos.ci;
}


void erase_snake(const snake& s) {
	/*gotoxy(s.body[0].ci, s.body[0].ri);
	cout << " ";

	for (int i = 1; i < s.size; i++) {
		gotoxy(s.body[i].ci, s.body[i].ri);
		cout << " ";
	}*/

	gotoxy(s.body[s.size - 1].ci, s.body[s.size - 1].ri);
	cout << " ";
}



void change_direction(snake& s, char ch) {
	if (ch == s.leftkey) {
		if (s.dir != Right) {
			s.dir = Left;
		}
	}
	else if (ch == s.rightkey) {
		if (s.dir != Left) {
			s.dir = Right;
		}
	}
	else if (ch == s.upkey) {
		if (s.dir != Down) {
			s.dir = Up;
		}
	}
	else if (ch == s.downkey) {
		if (s.dir != Up) {
			s.dir = Down;

		}
	}
}


void grow_snake(snake& s) {
	Position* temp = new Position[s.size + 1];
	for (int i = 0; i < s.size; i++) {
		temp[i] = s.body[i];
	}
	temp[s.size] = s.body[s.size - 1];
	s.size++;
	delete[] s.body;
	s.body = temp;

}


bool islegalcoordinate_bf(Position pos, snake& s, snake& s2, food& f, int rightedge, int leftedge, int topedge, int bottomedge, bool multiplayer) {

	for (int i = 0; i < s.size; i++) {
		if (pos.ri == s.body[i].ri && pos.ci == s.body[i].ci) {
			return false;
		}
		else if (pos.ri == s.body[i].ri && pos.ci + 1 == s.body[i].ci) {
			return false;
		}
		else if (pos.ri == s.body[i].ri && pos.ci - 1 == s.body[i].ci) {
			return false;
		}
		else if (pos.ri + 1 == s.body[i].ri && pos.ci == s.body[i].ci) {
			return false;
		}
		else if (pos.ri + 1 == s.body[i].ri && pos.ci + 1 == s.body[i].ci) {
			return false;
		}
		else if (pos.ri + 1 == s.body[i].ri && pos.ci - 1 == s.body[i].ci) {
			return false;
		}
		else if (pos.ri - 1 == s.body[i].ri && pos.ci == s.body[i].ci) {
			return false;
		}
		else if (pos.ri - 1 == s.body[i].ri && pos.ci + 1 == s.body[i].ci) {
			return false;
		}
		else if (pos.ri - 1 == s.body[i].ri && pos.ci - 1 == s.body[i].ci) {
			return false;
		}
	}

	if (multiplayer) {
		for (int i = 0; i < s2.size; i++) {
			if (pos.ri == s2.body[i].ri && pos.ci == s2.body[i].ci) {
				return false;
			}
			else if (pos.ri == s2.body[i].ri && pos.ci + 1 == s2.body[i].ci) {
				return false;
			}
			else if (pos.ri == s2.body[i].ri && pos.ci - 1 == s2.body[i].ci) {
				return false;
			}
			else if (pos.ri + 1 == s2.body[i].ri && pos.ci == s2.body[i].ci) {
				return false;
			}
			else if (pos.ri + 1 == s2.body[i].ri && pos.ci + 1 == s2.body[i].ci) {
				return false;
			}
			else if (pos.ri + 1 == s2.body[i].ri && pos.ci - 1 == s2.body[i].ci) {
				return false;
			}
			else if (pos.ri - 1 == s2.body[i].ri && pos.ci == s2.body[i].ci) {
				return false;
			}
			else if (pos.ri - 1 == s2.body[i].ri && pos.ci + 1 == s2.body[i].ci) {
				return false;
			}
			else if (pos.ri - 1 == s2.body[i].ri && pos.ci - 1 == s2.body[i].ci) {
				return false;
			}
		}
	
	}

	if ((pos.ri == f.pos.ri && pos.ci == f.pos.ci) ||
		(pos.ri == f.pos.ri && pos.ci == f.pos.ci + 1) ||
		(pos.ri == f.pos.ri && pos.ci == f.pos.ci - 1) ||
		(pos.ri == f.pos.ri + 1 && pos.ci == f.pos.ci) ||
		(pos.ri == f.pos.ri + 1 && pos.ci == f.pos.ci + 1) ||
		(pos.ri == f.pos.ri + 1 && pos.ci == f.pos.ci - 1) ||
		(pos.ri == f.pos.ri - 1 && pos.ci == f.pos.ci) ||
		(pos.ri == f.pos.ri - 1 && pos.ci == f.pos.ci + 1) ||
		(pos.ri == f.pos.ri - 1 && pos.ci == f.pos.ci - 1)) {
		return false;
	}



	if ((pos.ci > rightedge || pos.ci < leftedge) || (pos.ri < topedge || pos.ri > bottomedge)) {
		return false;
	}

	return true;

}


void generate_big_food(bigfood& bf, int boxheight, int boxwidth, snake& s, snake& s2, bool multiplayer, food& f) {

	int rightedge = boxwidth + 12;
	int leftedge = 16;
	int topedge = 6;
	int bottomedge = boxheight + 2;

	do {
		bf.pos.ri = (rand() % (boxheight)) + 4;
		bf.pos.ci = (rand() % (boxwidth)) + 14;
	} while (!islegalcoordinate_bf(bf.pos, s, s2, f, rightedge, leftedge, topedge, bottomedge, multiplayer));

	bf.is_active = true;
	bf.score = 50 * s.level;
	bf.color = 14;
	bf.symbol = '#';
	bf.time = 0;

}

void display_bigfood(const bigfood& f) {
	setcolor(f.color, 0);
	
	gotoxy(f.pos.ci, f.pos.ri);
	cout << f.symbol;
	gotoxy(f.pos.ci+1, f.pos.ri);
	cout << f.symbol;
	gotoxy(f.pos.ci - 1, f.pos.ri);
	cout << f.symbol;
	
	gotoxy(f.pos.ci, f.pos.ri+1);
	cout << f.symbol;
	gotoxy(f.pos.ci+1, f.pos.ri+1);
	cout << f.symbol;
	gotoxy(f.pos.ci - 1, f.pos.ri+1);
	cout << f.symbol;

	gotoxy(f.pos.ci, f.pos.ri-1);
	cout << f.symbol;
	gotoxy(f.pos.ci+1, f.pos.ri-1);
	cout << f.symbol;
	gotoxy(f.pos.ci - 1, f.pos.ri-1);
	cout << f.symbol;

	setcolor(7, 0);
}



bool is_bigfood_eaten(snake& s, bigfood& f) {
	return (s.body[0].ri == f.pos.ri && s.body[0].ci == f.pos.ci) || 
		(s.body[0].ri == f.pos.ri && s.body[0].ci == f.pos.ci+1) || 
		(s.body[0].ri == f.pos.ri && s.body[0].ci == f.pos.ci-1) || 
		(s.body[0].ri == f.pos.ri+1 && s.body[0].ci == f.pos.ci) || 
		(s.body[0].ri == f.pos.ri+1 && s.body[0].ci == f.pos.ci+1) || 
		(s.body[0].ri == f.pos.ri+1 && s.body[0].ci == f.pos.ci-1) || 
		(s.body[0].ri == f.pos.ri-1 && s.body[0].ci == f.pos.ci) || 
		(s.body[0].ri == f.pos.ri-1 && s.body[0].ci == f.pos.ci+1) || 
		(s.body[0].ri == f.pos.ri-1 && s.body[0].ci == f.pos.ci-1);
}



void erase_bigfood(const bigfood& f) {

	gotoxy(f.pos.ci, f.pos.ri);
	cout << " ";
	gotoxy(f.pos.ci+1, f.pos.ri);
	cout << " ";
	gotoxy(f.pos.ci - 1, f.pos.ri);
	cout << " ";

	gotoxy(f.pos.ci, f.pos.ri+1);
	cout << " ";
	gotoxy(f.pos.ci+1, f.pos.ri+1);
	cout << " ";
	gotoxy(f.pos.ci - 1, f.pos.ri+1);
	cout << " ";

	gotoxy(f.pos.ci, f.pos.ri-1);
	cout << " ";
	gotoxy(f.pos.ci+1, f.pos.ri-1);
	cout << " ";
	gotoxy(f.pos.ci - 1, f.pos.ri-1);
	cout << " ";
}


bool iscolliding(snake& s, snake& s2, bool& p1wins, bool& p2wins, bool multiplayer) {

	for (int i = 1; i < s.size; i++) {
		if (s.body[0].ri == s.body[i].ri && s.body[0].ci == s.body[i].ci) {
			return true;
		}
	}

	if (multiplayer == true) {

		if (s.body[0].ri == s2.body[0].ri && s.body[0].ci == s2.body[0].ci) {
			return true;
		}

		for (int i = 1; i < s2.size; i++) {
			if (s2.body[0].ri == s2.body[i].ri && s2.body[0].ci == s2.body[i].ci) {
				return true;
			}
		}

		for (int i = 1; i < s2.size; i++) {
			if (s.body[0].ri == s2.body[i].ri && s.body[0].ci == s2.body[i].ci) {
				p2wins = true;
				return true;
			}
		}

		for (int i = 1; i < s.size; i++) {
			if (s2.body[0].ri == s.body[i].ri && s2.body[0].ci == s.body[i].ci) {
				p1wins = true;
				return true;
			}
		}

	}

	
	return false;
}

void drawbox_at_x_y(int x, int y, int boxheight, int boxwidth) {

	setcolor(11, 0);
	char sym = -37;
	
	for (int i = 0; i <= boxwidth; i++) {
		gotoxy(x + i, y);
		cout << sym;
		gotoxy(x + i, y + boxheight);
		cout << sym;
	
	}

	for (int i = 0; i <= boxheight; i++) {
		gotoxy(x, y + i);
		cout << sym;
		gotoxy(x + boxwidth, y + i);
		cout << sym;
	}


	setcolor(7, 0);
}


void erasebox_at_x_y(int x, int y, int boxheight, int boxwidth) {

	char sym = ' ';

	for (int i = 0; i <= boxwidth; i++) {
		gotoxy(x + i, y);
		cout << sym;
		gotoxy(x + i, y + boxheight);
		cout << sym;

	}

	for (int i = 0; i <= boxheight; i++) {
		gotoxy(x, y + i);
		cout << sym;
		gotoxy(x + boxwidth, y + i);
		cout << sym;
	}
}



void print_game_title() {
	
	int x = 20;
	int y = 23;
	int boxheight = 15;
	int boxwidth = 76;
	Sleep(1000);
	drawbox_at_x_y(x, y, boxheight, boxwidth);
	Sleep(500);
	system("cls");
	Sleep(200);
	drawbox_at_x_y(x, y, boxheight, boxwidth);
	Sleep(500);
	print_alphabet_S(30, 28);
	Sleep(500);
	print_alphabet_N(36, 28);
	Sleep(500);
	print_alphabet_A(42, 28);
	Sleep(500);
	print_alphabet_K(48, 28);
	Sleep(500);
	print_alphabet_E(54, 28);
	Sleep(500);
	print_alphabet_G(66, 28);
	Sleep(500);
	print_alphabet_A(72, 28);
	Sleep(500);
	print_alphabet_M(78, 28);
	Sleep(500);
	print_alphabet_E(84, 28);
	Sleep(500);

	system("cls");
	Sleep(400);
	drawbox_at_x_y(x, y, boxheight, boxwidth);
	print_alphabet_S(30, 28);
	print_alphabet_N(36, 28);
	print_alphabet_A(42, 28);
	print_alphabet_K(48, 28);
	print_alphabet_E(54, 28);
	print_alphabet_G(66, 28);
	print_alphabet_A(72, 28);
	print_alphabet_M(78, 28);
	print_alphabet_E(84, 28);
	Sleep(1000);
	system("cls");
	Sleep(200);
	drawbox_at_x_y(x, y, boxheight, boxwidth);
	print_alphabet_S(30, 28);
	print_alphabet_N(36, 28);
	print_alphabet_A(42, 28);
	print_alphabet_K(48, 28);
	print_alphabet_E(54, 28);
	print_alphabet_G(66, 28);
	print_alphabet_A(72, 28);
	print_alphabet_M(78, 28);
	print_alphabet_E(84, 28);

	
}


void print_game_mode_1_details() {

	gotoxy(12, 45);
	cout << "Border blockade is a mode in which the";
	gotoxy(12, 47);
	cout << "snake cannot pass through the border of";
	gotoxy(12, 49);
	cout << "the box.If the snake hits the border,";
	gotoxy(12, 51);
	cout << "the game is over.";

}


void erase_game_mode_1_details() {

	gotoxy(12, 45);
	cout << "                                        ";
	gotoxy(12, 47);
	cout << "                                        ";
	gotoxy(12, 49);
	cout << "                                        ";
	gotoxy(12, 51);
	cout << "                                        ";

}


void print_game_mode_2_details() {

	gotoxy(66, 45);
	cout << "Endless entwist is a mode in which the";
	gotoxy(66, 47);
	cout << "snake can pass through the border of";
	gotoxy(66, 49);
	cout << "the box.If the snake hits the border,";
	gotoxy(66, 51);
	cout << "it will come out from opposite side.";


}


void erase_game_mode_2_details() {

	gotoxy(66, 45);
	cout << "                                        ";
	gotoxy(66, 47);
	cout << "                                        ";
	gotoxy(66, 49);
	cout << "                                        ";
	gotoxy(66,51);
	cout << "                                        ";

}



void draw_selection(int x, int y, int boxheight, int boxwidth) {

	setcolor(11, 0);
	char sym = -37;

	for (int i = -3; i <= boxwidth + 3; i++) {

		if (i >= 0 && i <= boxwidth) {
			gotoxy(x + i, y);
			cout << " ";
			gotoxy(x + i, y + boxheight);
			cout << " ";

		}

		gotoxy(x + i, y - 3);
		cout << sym;
		gotoxy(x + i, y - 2);
		cout << sym;

		gotoxy(x + i, y + boxheight+2);
		cout << sym;
		gotoxy(x + i, y + boxheight+3);
		cout << sym;
	}

	for (int i = -3; i <= boxheight + 3; i++) {

		if (i >= 0 && i <= boxheight) {
			gotoxy(x, y + i);
			cout << " ";
			gotoxy(x + boxwidth, y + i);
			cout << " ";

		}

		gotoxy(x - 3, y + i);
		cout << sym;
		gotoxy(x - 2, y + i);
		cout << sym;

		gotoxy(x + boxwidth + 2, y + i);
		cout << sym;
		gotoxy(x + boxwidth + 3, y + i);
		cout << sym;

	}

	setcolor(7, 0);

}




void erase_selection(int x, int y, int boxheight, int boxwidth, int num = 0) {

	setcolor(11, 0);
	char sym = -37;

	for (int i = -3; i <= boxwidth + 3; i++) {

		if (i >= 0 && i <= boxwidth) {
			gotoxy(x + i, y);
			cout << sym;
			gotoxy(x + i, y + boxheight-num);
			cout << sym;

		}

		gotoxy(x + i, y - 3);
		cout << " ";
		gotoxy(x + i, y - 2);
		cout << " ";

		gotoxy(x + i, y + boxheight + 2);
		cout << " ";
		gotoxy(x + i, y + boxheight + 3);
		cout << " ";
	}

	for (int i = -3; i <= boxheight + 3; i++) {

		if (i >= 0 && i <= boxheight-num) {
			gotoxy(x, y + i);
			cout << sym;
			gotoxy(x + boxwidth, y + i);
			cout << sym;

		}

		gotoxy(x - 3, y + i);
		cout << " ";
		gotoxy(x - 2, y + i);
		cout << " ";

		gotoxy(x + boxwidth + 2, y + i);
		cout << " ";
		gotoxy(x + boxwidth + 3, y + i);
		cout << " ";

	}

	setcolor(7, 0);

}





void print_game_mode(bool& wraparound) {
	
	char sym = -37;

	print_alphabet_G(34, 15);
	print_alphabet_A(40, 15);
	print_alphabet_M(46, 15);
	print_alphabet_E(52, 15);
	print_alphabet_M(64, 15);
	print_alphabet_O(70, 15);
	print_alphabet_D(76, 15);
	print_alphabet_E(82, 15);
	
	int x = 10;
	int y = 30;

	int boxheight = 22;
	int boxwidth = 43;

	drawbox_at_x_y(x, y, boxheight-8, boxwidth);
	drawbox_at_x_y(x+54, y, boxheight-8, boxwidth-1);

	// border blockade

	gotoxy(12, 32);
	print_alphabet_B(17, 32);
	print_alphabet_O(22, 32);
	print_alphabet_R(27, 32);
	print_alphabet_D(32, 32);
	print_alphabet_E(37, 32);
	print_alphabet_R(42, 32);

	print_alphabet_B(12, 38);
	print_alphabet_L(17, 38);
	print_alphabet_O(22, 38);
	print_alphabet_C(27, 38);
	print_alphabet_K(32, 38);
	print_alphabet_A(37, 38);
	print_alphabet_D(43, 38);
	print_alphabet_E(48, 38);


	// endless entwist
	print_alphabet_E(68, 32);
	print_alphabet_N(73, 32);
	print_alphabet_D(79, 32);
	print_alphabet_L(84, 32);
	print_alphabet_E(89, 32);
	print_alphabet_S(94, 32);
	print_alphabet_S(99, 32);

	print_alphabet_E(66, 38);
	print_alphabet_N(71, 38);
	print_alphabet_T(77, 38);
	print_alphabet_W(83, 38);
	print_alphabet_I(89, 38);
	print_alphabet_S(95, 38);
	print_alphabet_T(100, 38);

	

	char ch;
	bool selected = false;

	while (true) {

		if (_kbhit()) {
			ch = _getch();
			if (ch == 13 && selected) {
				break;
			}
			else if (ch == -32) {
				ch = _getch();
				if (ch == 75) {
					erase_game_mode_2_details();
					erase_selection(x+54, y, boxheight, boxwidth-1, 8);
					drawbox_at_x_y(x + 54, y, boxheight - 8, boxwidth - 1);
					erasebox_at_x_y(x, y, boxheight-8, boxwidth);
					draw_selection(x, y, boxheight, boxwidth);
					print_game_mode_1_details();
					wraparound = false;
					selected = true;
				}
				else if (ch == 77) {
					erase_game_mode_1_details();
					erase_selection(x, y, boxheight, boxwidth, 8);
					drawbox_at_x_y(x, y, boxheight - 8, boxwidth);
					erasebox_at_x_y(x + 54, y, boxheight - 8, boxwidth - 1);
					draw_selection(x + 54, y, boxheight, boxwidth - 1);
					print_game_mode_2_details();
					wraparound = true;
					selected = true;
				}
			}
		}
		
	}


}


void print_play_mode_1_details() {

	gotoxy(12, 40);
	cout << "Navigate a single snake through the";
	gotoxy(12, 42);
	cout << "game board, collecting food to grow";
	gotoxy(12, 44);
	cout << "longer while avoiding collisions";;

}



void erase_play_mode_1_details() {

	gotoxy(12, 40);
	cout << "                                      ";
	gotoxy(12, 42);
	cout << "                                      ";
	gotoxy(12, 44);
	cout << "                                      ";

}



void print_play_mode_2_details() {

	gotoxy(72, 40);
	cout << "Two players control individual snakes";
	gotoxy(72, 42);
	cout << "simultaneously on the same game board";
	gotoxy(72, 44);
	cout << "competing to collect more food ";

}



void erase_play_mode_2_details() {

	gotoxy(72, 40);
	cout << "                                    ";
	gotoxy(72, 42);
	cout << "                                    ";
	gotoxy(72, 44);
	cout << "                                    ";

}





void print_play_mode(bool& multiplayer) {

	char sym = -37;

	print_alphabet_P(34, 15);
	print_alphabet_L(40, 15);
	print_alphabet_A(46, 15);
	print_alphabet_Y(52, 15);
	print_alphabet_M(64, 15);
	print_alphabet_O(70, 15);
	print_alphabet_D(76, 15);
	print_alphabet_E(82, 15);

	int x = 10;
	int y = 25;

	int boxheight = 20;
	int boxwidth = 40;

	drawbox_at_x_y(x, y, boxheight-6, boxwidth);
	drawbox_at_x_y(x + 60, y, boxheight-6, boxwidth);

	// single player

	print_alphabet_S(15, 27);
	print_alphabet_I(20, 27);
	print_alphabet_N(26, 27);
	print_alphabet_G(32, 27);
	print_alphabet_L(37, 27);
	print_alphabet_E(42, 27);

	print_alphabet_P(15, 33);
	print_alphabet_L(20, 33);
	print_alphabet_A(25, 33);
	print_alphabet_Y(31, 33);
	print_alphabet_E(37, 33);
	print_alphabet_R(42, 33);


	//multiplayer

	print_alphabet_M(77, 27);
	print_alphabet_U(83, 27);
	print_alphabet_L(88, 27);
	print_alphabet_T(93, 27);
	print_alphabet_I(99, 27);

	print_alphabet_P(75, 33);
	print_alphabet_L(80, 33);
	print_alphabet_A(85, 33);
	print_alphabet_Y(91, 33);
	print_alphabet_E(97, 33);
	print_alphabet_R(102, 33);


	char ch;
	bool selected = false;


	while (true) {

		if (_kbhit()) {
			ch = _getch();
			if (ch == 13 && selected) {
				break;
			}
			else if (ch == -32) {
				ch = _getch();
				if (ch == 75) {
					erase_play_mode_2_details();
					erase_selection(x + 60, y, boxheight, boxwidth, 6);
					drawbox_at_x_y(x + 60, y, boxheight - 6, boxwidth);
					erasebox_at_x_y(x, y, boxheight - 6, boxwidth);
					draw_selection(x, y, boxheight, boxwidth);
					print_play_mode_1_details();
					multiplayer = false;
					selected = true;
				}
				else if (ch == 77) {
					erase_play_mode_1_details();
					erase_selection(x, y, boxheight, boxwidth, 6);
					drawbox_at_x_y(x, y, boxheight - 6, boxwidth);
					erasebox_at_x_y(x + 60, y, boxheight - 6, boxwidth);
					draw_selection(x + 60, y, boxheight, boxwidth);
					print_play_mode_2_details();
					multiplayer = true;
					selected = true;
				}
			}
		}

	}
		

}


void print_game_start(bool& gamestart) {

	char sym = -37;

	print_alphabet_P(25, 20);
	print_alphabet_R(30, 20);
	print_alphabet_E(35, 20);
	print_alphabet_S(40, 20);
	print_alphabet_S(45, 20);

	print_alphabet_A(55, 20);
	print_alphabet_N(61, 20);
	print_alphabet_Y(67, 20);

	print_alphabet_K(78, 20);
	print_alphabet_E(83, 20);
	print_alphabet_Y(88, 20);

	print_alphabet_T(53, 26);
	print_alphabet_O(59, 26);

	print_alphabet_S(22, 32);
	print_alphabet_T(27, 32);
	print_alphabet_A(33, 32);
	print_alphabet_R(39, 32);
	print_alphabet_T(43, 32);

	print_alphabet_T(54, 32);
	print_alphabet_H(60, 32);
	print_alphabet_E(65, 32);

	print_alphabet_G(75, 32);
	print_alphabet_A(80, 32);
	print_alphabet_M(86, 32);
	print_alphabet_E(92, 32);

	_getch();

	gamestart = true;

}


void draw_filled_box(int x, int y, int boxheight, int boxwidth, int color) {

	setcolor(color, 0);
	char sym = -37;

	gotoxy(x, y);

	for (int i = 0; i < boxheight; i++) {
		for (int j = 0; j < boxwidth; j++) {

			cout << sym;
		}
		gotoxy(x, y + i + 1);
	}
	
	setcolor(7, 0);

}



void print_game_terminated() {

	char sym = -37;

	int x = 17;
	int y = 25;

	int boxheight = 11;
	int boxwidth = 89;
	int color = 4;

	draw_filled_box(x, y, boxheight, boxwidth, color);

	setcolor(7, color);

	print_alphabet_G(20, 28);
	print_alphabet_A(25, 28);
	print_alphabet_M(31, 28);
	print_alphabet_E(37, 28);

	print_alphabet_T(47, 28);
	print_alphabet_E(53, 28);
	print_alphabet_R(58, 28);
	print_alphabet_M(63, 28);
	print_alphabet_I(69, 28);
	print_alphabet_N(75, 28);
	print_alphabet_A(81, 28);
	print_alphabet_T(87, 28);
	print_alphabet_E(93, 28);
	print_alphabet_D(98, 28);

	setcolor(7, 0);

}




void print_game_over() {

	char sym = -37;

	int x = 30;
	int y = 18;

	int boxheight = 11;
	int boxwidth = 60;
	int color = 4;
	draw_filled_box(x, y, boxheight, boxwidth, color);

	setcolor(7, color);

	print_alphabet_G(34, 21);
	print_alphabet_A(40, 21);
	print_alphabet_M(46, 21);
	print_alphabet_E(52, 21);
	print_alphabet_O(64, 21);
	print_alphabet_V(70, 21);
	print_alphabet_E(76, 21);
	print_alphabet_R(82, 21);

	setcolor(7, 0);

	gotoxy(0, 0);

}


void print_digit(int digit, int x, int y) {

	switch (digit) {
	case 0:
		print_digit_0(x, y);
		break;
	case 1:
		print_digit_1(x, y);
		break;
	case 2:
		print_digit_2(x, y);
		break;
	case 3:
		print_digit_3(x, y);
		break;
	case 4:
		print_digit_4(x, y);
		break;
	case 5:
		print_digit_5(x, y);
		break;
	case 6:
		print_digit_6(x, y);
		break;
	case 7:
		print_digit_7(x, y);
		break;
	case 8:
		print_digit_8(x, y);
		break;
	case 9:
		print_digit_9(x, y);
		break;

	}

}


void print_p1_wins() {

	char sym = -37;

	int x = 17;
	int y = 4;

	int boxheight = 11;
	int boxwidth = 86;
	int color = 6;
	draw_filled_box(x, y, boxheight, boxwidth, color);

	setcolor(1, 6);
	print_alphabet_P(20, 7);
	print_alphabet_L(25, 7);
	print_alphabet_A(30, 7);
	print_alphabet_Y(36, 7);
	print_alphabet_E(42, 7);
	print_alphabet_R(47, 7);

	print_alphabet_O(57, 7);
	print_alphabet_N(62, 7);
	print_alphabet_E(68, 7);

	print_alphabet_W(78, 7);
	print_alphabet_I(84, 7);
	print_alphabet_N(90, 7);
	print_alphabet_S(96, 7);

	setcolor(7, 0);

}


void print_p2_wins() {


	char sym = -37;

	int x = 17;
	int y = 4;

	int boxheight = 11;
	int boxwidth = 87;
	int color = 6;
	draw_filled_box(x, y, boxheight, boxwidth, color);

	setcolor(1, 6);
	print_alphabet_P(20, 7);
	print_alphabet_L(25, 7);
	print_alphabet_A(30, 7);
	print_alphabet_Y(36, 7);
	print_alphabet_E(42, 7);
	print_alphabet_R(47, 7);

	print_alphabet_T(57, 7);
	print_alphabet_W(63, 7);
	print_alphabet_O(69, 7);

	print_alphabet_W(79, 7);
	print_alphabet_I(85, 7);
	print_alphabet_N(91, 7);
	print_alphabet_S(97, 7);

	setcolor(7, 0);


}


void print_draw() {


	char sym = -37;

	int x = 47;
	int y = 4;

	int boxheight = 11;
	int boxwidth = 27;
	int color = 6;
	draw_filled_box(x, y, boxheight, boxwidth, color);

	setcolor(1, 6);

	print_alphabet_D(50, 7);
	print_alphabet_R(55, 7);
	print_alphabet_A(60, 7);
	print_alphabet_W(66, 7);

	setcolor(7, 0);

}



void print_score(string name, int score, string name2, int score2, int color, int color2, int highscore, bool multiplayer, bool p1wins, bool p2wins) {
	
	char sym = -37;

	if (!multiplayer) {

		print_alphabet_S(41, 30);
		print_alphabet_C(46, 30);
		print_alphabet_O(51, 30);
		print_alphabet_R(56, 30);
		print_alphabet_E(61, 30);

		gotoxy(68, 33);
		cout << sym;
		gotoxy(69, 33);
		cout << sym;
		gotoxy(68, 31);
		cout << sym;
		gotoxy(69, 31);
		cout << sym;
		

		int x = 73;
		int y = 30;

		int refnum = score;
		int count = 1;
		int digit;
		while (refnum > 9) {
			refnum = refnum / 10;
			count = count * 10;
		}

		while (count > 0) {
			digit = score / count;
			score = score % count;
			count = count / 10;
			print_digit(digit, x, y);
			x += 4;
		}

		print_alphabet_H(28, 36);
		print_alphabet_I(33, 36);
		print_alphabet_G(39, 36);
		print_alphabet_H(44, 36);
		print_alphabet_S(49, 36);
		print_alphabet_C(54, 36);
		print_alphabet_O(59, 36);
		print_alphabet_R(64, 36);
		print_alphabet_E(69, 36);

		gotoxy(76, 39);
		cout << sym;
		gotoxy(77, 39);
		cout << sym;
		gotoxy(76, 37);
		cout << sym;
		gotoxy(77, 37);
		cout << sym;

		x = 82;
		y = 36;

		refnum = highscore;
		count = 1;
		while (refnum > 9) {
			refnum = refnum / 10;
			count = count * 10;
		}

		while (count > 0) {
			digit = highscore / count;
			highscore = highscore % count;
			count = count / 10;
			print_digit(digit, x, y);
			x += 4;
		}

	}
	else {

		setcolor(color, 0);

		print_alphabet_P(23, 30);
		print_alphabet_L(28, 30);
		print_alphabet_A(33, 30);
		print_alphabet_Y(39, 30);
		print_alphabet_E(45, 30);
		print_alphabet_R(50, 30);

		print_alphabet_O(60, 30);
		print_alphabet_N(65, 30);
		print_alphabet_E(71, 30);

		setcolor(7, 0);

		gotoxy(78, 33);
		cout << sym;
		gotoxy(79, 33);
		cout << sym;
		gotoxy(78, 31);
		cout << sym;
		gotoxy(79, 31);
		cout << sym;

		int x = 84;
		int y = 30;


		int refnum = score;
		int count = 1;
		int digit;

		while (refnum > 9) {
			refnum = refnum / 10;
			count = count * 10;
		}

		while (count > 0) {
			digit = score / count;
			score = score % count;
			count = count / 10;
			print_digit(digit, x, y);
			x += 4;
		}


		setcolor(color2, 0);

		print_alphabet_P(23, 36);
		print_alphabet_L(28, 36);
		print_alphabet_A(33, 36);
		print_alphabet_Y(39, 36);
		print_alphabet_E(45, 36);
		print_alphabet_R(50, 36);

		print_alphabet_T(60, 36);
		print_alphabet_W(66, 36);
		print_alphabet_O(72, 36);

		setcolor(7, 0);

		gotoxy(79, 39);
		cout << sym;
		gotoxy(80, 39);
		cout << sym;
		gotoxy(79, 37);
		cout << sym;
		gotoxy(80, 37);
		cout << sym;

		x = 85;
		y = 36;


		refnum = score2;
		count = 1;
		digit;

		while (refnum > 9) {
			refnum = refnum / 10;
			count = count * 10;
		}

		while (count > 0) {
			digit = score2 / count;
			score2 = score2 % count;
			count = count / 10;
			print_digit(digit, x, y);
			x += 4;
		}


		print_alphabet_H(28, 42);
		print_alphabet_I(33, 42);
		print_alphabet_G(39, 42);
		print_alphabet_H(44, 42);
		print_alphabet_S(49, 42);
		print_alphabet_C(54, 42);
		print_alphabet_O(59, 42);
		print_alphabet_R(64, 42);
		print_alphabet_E(69, 42);

		gotoxy(76, 45);
		cout << sym;
		gotoxy(77, 45);
		cout << sym;
		gotoxy(76, 43);
		cout << sym;
		gotoxy(77, 43);
		cout << sym;

		x = 82;
		y = 42;

		refnum = highscore;
		count = 1;
		while (refnum > 9) {
			refnum = refnum / 10;
			count = count * 10;
		}

		while (count > 0) {
			digit = highscore / count;
			highscore = highscore % count;
			count = count / 10;
			print_digit(digit, x, y);
			x += 4;
		}


		
	}


}



void print_gamepaused(bool& gameover) {


	char sym = -37;

	print_alphabet_G(30, 15);
	print_alphabet_A(35, 15);
	print_alphabet_M(41, 15);
	print_alphabet_E(47, 15);
	print_alphabet_P(57, 15);
	print_alphabet_A(62, 15);
	print_alphabet_U(68, 15);
	print_alphabet_S(73, 15);
	print_alphabet_E(78, 15);
	print_alphabet_D(83, 15);

	int x = 11;
	int y = 30;

	int boxheight = 14;
	int boxwidth = 39;

	drawbox_at_x_y(x, y, boxheight, boxwidth);
	drawbox_at_x_y(x + 57, y, boxheight, boxwidth);

	print_alphabet_E(20, 35);
	print_alphabet_X(25, 35);
	print_alphabet_I(31, 35);
	print_alphabet_T(37, 35);

	print_alphabet_R(73, 35);
	print_alphabet_E(78, 35);
	print_alphabet_S(83, 35);
	print_alphabet_U(88, 35);
	print_alphabet_M(93, 35);
	print_alphabet_E(99, 35);

	char ch;
	bool selected = false;


	while (true) {

		if (_kbhit()) {
			ch = _getch();
			if (ch == 13 && selected) {
				break;
			}
			else if (ch == -32) {
				ch = _getch();
				if (ch == 75) {
					erase_selection(x + 57, y, boxheight, boxwidth);
					draw_selection(x, y, boxheight, boxwidth);
					gameover = true;
					selected = true;
				}
				else if (ch == 77) {
					erase_selection(x, y, boxheight, boxwidth);
					draw_selection(x + 57, y, boxheight, boxwidth);
					gameover = false;
					selected = true;
				}
			}
		}

	}

}


void print_play_again(bool& playagian) {


	char sym = -37;

	print_alphabet_R(25, 15);
	print_alphabet_E(30, 15);
	print_alphabet_S(35, 15);
	print_alphabet_T(40, 15);
	print_alphabet_A(46, 15);
	print_alphabet_R(52, 15);
	print_alphabet_T(57, 15);

	print_alphabet_G(68, 15);
	print_alphabet_A(73, 15);
	print_alphabet_M(79, 15);
	print_alphabet_E(85, 15);


	int x = 17;
	int y = 30;

	int boxheight = 10;
	int boxwidth = 24;

	drawbox_at_x_y(x, y, boxheight, boxwidth);
	drawbox_at_x_y(x + 57, y, boxheight, boxwidth);


	print_alphabet_Y(22, 33);
	print_alphabet_E(28, 33);
	print_alphabet_S(33, 33);

	print_alphabet_N(82, 33);
	print_alphabet_O(88, 33);

	char ch;
	bool selected = false;


	while (true) {

		if (_kbhit()) {
			ch = _getch();
			if (ch == 13 && selected) {
				break;
			}
			else if (ch == -32) {
				ch = _getch();
				if (ch == 75) {
					erase_selection(x + 57, y, boxheight, boxwidth);
					draw_selection(x, y, boxheight, boxwidth);
					playagian = true;
					selected = true;
				}
				else if (ch == 77) {
					erase_selection(x, y, boxheight, boxwidth);
					draw_selection(x + 57, y, boxheight, boxwidth);
					playagian = false;
					selected = true;
				}
			}
		}

	}



}


void print_screen_1p() {


	print_alphabet_I(24, 5);
	print_alphabet_N(30, 5);
	print_alphabet_S(36, 5);
	print_alphabet_T(41, 5);
	print_alphabet_R(47, 5);
	print_alphabet_U(52, 5);
	print_alphabet_C(57, 5);
	print_alphabet_T(62, 5);
	print_alphabet_I(68, 5);
	print_alphabet_O(74, 5);
	print_alphabet_N(79, 5);
	print_alphabet_S(85, 5);


	gotoxy(15, 15);
	cout << "- Consume regular food item scattered across the board to accumulate points and";
	gotoxy(15, 17);
	cout << " extend the length of your snake. Eat the food to regenerate it.";

	gotoxy(15, 21);
	cout << "- Periodically, a bonus food will show up with a limmited time frame, offering ";
	gotoxy(15, 23);
	cout << "a higher score; however, it won't contribute to the snake's length.";

	gotoxy(15, 27);
	cout << "- With each growth phase, your snake's level advances, amplifying its speed and";
	gotoxy(15, 29);
	cout << "elevating the score associated with each standard and bonus food item.";

	gotoxy(15, 33);
	cout << "- Prevent your snake from colliding with its own body, as such mishaps will result";
	gotoxy(15, 35);
	cout << "to the death of snake and the game will end.";

	
}



void print_screen_1p_bb() {

	gotoxy(15, 39);

	cout << "- Navigate your snake freely across the board, exploring without fear of collision";
	gotoxy(15, 41);
	cout << "with the borders. The board is endless, allowing you to travel in any direction.";

	gotoxy(15, 45);
	cout << "- When the snake touches the border, it will seemlessly emerge from the opposite side";

	gotoxy(15, 49);
	cout << "- Strive to devour as much food as possible to surpass the existing highscore and";
	gotoxy(15, 51);
	cout << "emerge victorious in this challenging adventure!";


}



void print_screen_1p_ee() {

	gotoxy(15, 39);
	cout << "- Navigate your snake across the board with caution, colliding with border will";
	gotoxy(15, 41);
	cout << "cause the game to end.";

	
	gotoxy(15, 45);
	cout << "- Strive to devour as much food as possible to surpass the existing highscore and";
	gotoxy(15, 47);
	cout << "emerge victorious in this challenging adventure!";


}


void print_screen_2p() {


	print_alphabet_I(24, 5);
	print_alphabet_N(30, 5);
	print_alphabet_S(36, 5);
	print_alphabet_T(41, 5);
	print_alphabet_R(47, 5);
	print_alphabet_U(52, 5);
	print_alphabet_C(57, 5);
	print_alphabet_T(62, 5);
	print_alphabet_I(68, 5);
	print_alphabet_O(74, 5);
	print_alphabet_N(79, 5);
	print_alphabet_S(85, 5);


	gotoxy(15, 12);
	cout << "- Two snakes are now in play, each under the control of a separate user.";

	gotoxy(15, 14);
	cout << "- Consume regular food item scattered across the board to accumulate points and";
	gotoxy(15, 16);
	cout << " extend the length of your snake. Eating the food will cause it to regenerate.";
	gotoxy(15, 18);
	cout << "The snake that consumes the food first will be awarded the points.";


	gotoxy(15, 21);
	cout << "- Periodically, a bonus food will show up with a limmited time frame, offering ";
	gotoxy(15, 23);
	cout << "a higher score; however, it won't contribute to the snake's length.";

	gotoxy(15, 26);
	cout << "- With each growth phase, your snake's level advances, and elevating the score";
	gotoxy(15, 28);
	cout << " associated with consuming each standard and bonus food item.";

	gotoxy(15, 31);
	cout << "- Prevent your snake from colliding with its own body, as such mishaps will result";
	gotoxy(15, 33);
	cout << "to the death of snake and the game will end under normal rule.";

	gotoxy(15, 36);
	cout << "- Colliding with the other snake will also end the game. Special rule apply, ";
	gotoxy(15, 38);
	cout << "the snake whose head touches the body of the other snake will lose the game";

	gotoxy(15, 41);
	cout << "- If both snakes collide their head simultaneously, the game ends under normal rule";

}


void print_screen_2p_bb() {

	gotoxy(15, 44);
	cout << "- Navigate each of the snake freely across the board  without fear of collision";
	gotoxy(15, 46);
	cout << "with the borders. The board is endless, allowing you to travel in any direction.";

	gotoxy(15, 49);
	cout << "- When the snake touches the border, it will seemlessly emerge from the opposite side";

	gotoxy(15, 52);
	cout << "- Under normal rule game end, snake with more score will emerge victorious!";

}



void print_screen_2p_ee() {

	gotoxy(15, 44);
	cout << "- Navigate your snake across the board with caution, colliding with border will";
	gotoxy(15, 46);
	cout << "cause the game to end under normal rule.";


	gotoxy(15, 49);
	cout << "- Under normal rule game end, snake with more score will emerge victorious!";

}


void draw_up_arrow_key(int x, int y) {

	char sym = -37;

	setcolor(7, 0);

	gotoxy(x, y);
	cout << "  " << sym << "  ";
	gotoxy(x, y + 1);
	cout << " " << sym << sym << sym << " ";
	gotoxy(x, y + 2);
	cout << sym << " " << sym << " " << sym;
	gotoxy(x, y + 3);
	cout << "  " << sym << "  ";
	gotoxy(x, y + 4);
	cout << "  " << sym << "  ";

}


void draw_down_arrow_key(int x, int y) {

	char sym = -37;

	setcolor(7, 0);

	gotoxy(x, y);
	cout << "  " << sym << "  ";
	gotoxy(x, y + 1);
	cout << "  " << sym << "  ";
	gotoxy(x, y + 2);
	cout << sym << " " << sym << " " << sym;
	gotoxy(x, y + 3);
	cout << " " << sym << sym << sym << " ";
	gotoxy(x, y + 4);
	cout << "  " << sym << "  ";

}



void draw_left_arrow_key(int x, int y) {

	char sym = -37;

	setcolor(7, 0);

	gotoxy(x, y);
	cout << "  " << sym << "  ";
	gotoxy(x, y + 1);
	cout << " " << sym << "   ";
	gotoxy(x, y + 2);
	cout << sym << sym << sym << sym << sym;
	gotoxy(x, y + 3);
	cout << " " << sym << "   ";
	gotoxy(x, y + 4);
	cout << "  " << sym << "  ";

}



void draw_right_arrow_key(int x, int y) {

	char sym = -37;

	setcolor(7, 0);

	gotoxy(x, y);
	cout << "  " << sym << "  ";
	gotoxy(x, y + 1);
	cout << "   " << sym << " ";
	gotoxy(x, y + 2);
	cout << sym << sym << sym << sym << sym;
	gotoxy(x, y + 3);
	cout << "   " << sym << " ";
	gotoxy(x, y + 4);
	cout << "  " << sym << "  ";

}



void controls_1p() {


	print_alphabet_C(37, 5);
	print_alphabet_O(42, 5);
	print_alphabet_N(47, 5);
	print_alphabet_T(53, 5);
	print_alphabet_R(59, 5);
	print_alphabet_O(64, 5);
	print_alphabet_L(69, 5);
	print_alphabet_S(74, 5);


	draw_up_arrow_key(55, 22);
	draw_down_arrow_key(55, 30);
	draw_left_arrow_key(47, 30);
	draw_right_arrow_key(63, 30);

	gotoxy(49, 38);
	cout << "Navigate the snake";

	gotoxy(44, 48);
	cout << "Press esc to pause the game";


}


void controls_2p() {


	print_alphabet_C(37, 5);
	print_alphabet_O(42, 5);
	print_alphabet_N(47, 5);
	print_alphabet_T(53, 5);
	print_alphabet_R(59, 5);
	print_alphabet_O(64, 5);
	print_alphabet_L(69, 5);
	print_alphabet_S(74, 5);


	draw_up_arrow_key(30, 20);
	draw_down_arrow_key(30, 28);
	draw_left_arrow_key(22, 28);
	draw_right_arrow_key(38, 28);


	print_alphabet_W(90, 20);
	print_alphabet_A(90, 28);
	print_alphabet_S(82, 28);
	print_alphabet_D(98, 28);

	gotoxy(28, 35);
	cout << "Player 1";

	gotoxy(88, 35);
	cout << "Player 2";


	gotoxy(47, 45);
	cout << "Press esc to pause the game";


}



void print_controls_screen(bool multiplayer) {

	if (multiplayer) {
		controls_2p();
	}
	else {
		controls_1p();
	}

	gotoxy(0, 58);
	system("pause");

}


void print_instruction_screen(bool multiplayer, bool wraparound) {

	if (multiplayer) {

		print_screen_2p();

		if (wraparound) {

			print_screen_2p_bb();

		}
		else {

			print_screen_2p_ee();

		}

	}
	else {

		print_screen_1p();

		if (wraparound) {

			print_screen_1p_bb();

		}
		else {

			print_screen_1p_ee();

		}

	}
	
	gotoxy(0, 58);
	system("pause");

}


void print_alphabet_exclam(int x, int y) {

	char sym = -37;

	gotoxy(x, y);
	cout << " " << sym << " ";

	gotoxy(x, y + 1);
	cout << " " << sym << " ";

	gotoxy(x, y + 2);
	cout << " " << sym << " ";

	gotoxy(x, y + 3);
	cout << "   ";

	gotoxy(x, y + 4);
	cout << " " << sym << " ";

}



void print_new_highscore() {
	

	char sym = -37;

	int x = 22;
	int y = 4;

	int boxheight = 11;
	int boxwidth = 76;
	int color = 6;
	draw_filled_box(x, y, boxheight, boxwidth, color);

	setcolor(1, 6);
	print_alphabet_N(25, 7);
	print_alphabet_E(31, 7);
	print_alphabet_W(36, 7);

	print_alphabet_H(47, 7);
	print_alphabet_I(52, 7);
	print_alphabet_G(58, 7);
	print_alphabet_H(63, 7);
	print_alphabet_S(68, 7);
	print_alphabet_C(73, 7);
	print_alphabet_O(78, 7);
	print_alphabet_R(83, 7);
	print_alphabet_E(88, 7);
	print_alphabet_exclam(93, 7);

	setcolor(7, 0);

}



int main() {


	srand(time(0));
	bool playagain;

	bool gameover = false;
	bool gamestart = false;
	bool wraparound;
	bool multiplayer;
	bool newhigh;


	const int screenwidth = 120;
	const int screenheight = 60;

	int boxheight = 50;
	int boxwidth = 90;


	snake s;
	snake s2;
	food f;
	bigfood bf;

	print_game_title();
	Sleep(5000);


	do {
		system("cls");
		
		gameover = false;
		char ch;
		int count1 = 0, count2 = 0;
		bool generated = false;
		
		
		int level;
		int highscore;
		int highscore_wraparound = 0;
		int highscore_border = 0;

		fstream score_file;

	

		score_file.open("HIGHSCORE.txt", ios::in);

		if (score_file.is_open()) {
			score_file >> highscore_wraparound;
			score_file >> highscore_border;
			score_file.close();
		}
		else {
			score_file.open("HIGHSCORE.txt", ios::out);
			score_file << highscore_wraparound;
			score_file << endl;
			score_file << highscore_border;
			score_file.close();
		}


		
		bool p1wins = false;
		bool p2wins = false;

		Sleep(100);

		print_game_mode(wraparound);
		Sleep(100);
		system("cls");

		if (wraparound) {
			highscore = highscore_wraparound;
		}
		else {
			highscore = highscore_border;
		}

		print_play_mode(multiplayer);
		Sleep(100);
		system("cls");

		print_instruction_screen(multiplayer, wraparound);
		Sleep(100);
		system("cls");

		print_controls_screen(multiplayer);
		Sleep(100);
		system("cls");


		print_game_start(gamestart);
		Sleep(100);
		system("cls");

		bf.is_active = false;
		innit(s, s2, f, screenheight, screenwidth, boxheight, boxwidth, multiplayer, bf);

		draw_box_in_middle(boxheight + 1, boxwidth + 1, screenheight, screenwidth);
		display_food(f);

		bool first = true;

		while (true) {

			if (_kbhit()) {

				ch = _getch();

				if (ch == -32) {
					ch = _getch();
					change_direction(s, ch);
				}
				else if (multiplayer == true) {

					if (ch == s2.leftkey || ch == s2.rightkey || ch == s2.upkey || ch == s2.downkey) {
						change_direction(s2, ch);
					}
				}
				else if (ch == 27) {
					system("cls");
					print_gamepaused(gameover);
					Sleep(200);
					system("cls");
					if (gameover) {
						gameover = false;
						break;
					}
					else {
						draw_box_in_middle(boxheight + 1, boxwidth + 1, screenheight, screenwidth);
						display_food(f);
						display_snake(s);
						if (multiplayer == true) {
							display_snake(s2);
						}
					}
				}
			}



			if (multiplayer == true) {
				display_game_description_bar_multiplayer(s.name, s.score, s2.name, s2.score, s.color, s2.color);
			}
			else {
				display_game_description_bar(s.score, highscore, s.level);
			}

			if (first) {
				display_snake(s);
				if (multiplayer == true) {
					display_snake(s2);
				}
				first = false;
			}
			else {

				display_snake_in_game(s);
				if (multiplayer == true) {
					display_snake_in_game(s2);
				}
			}

			

			if (iscolliding(s, s2, p1wins, p2wins, multiplayer)) {
				gameover = true;
				break;
			}


			if (multiplayer) {
				if (s.speed > s2.speed) {
					Sleep(s.speed);
				}
				else {
					Sleep(s2.speed);
				}
			}
			else {
				Sleep(s.speed);
			}

			erase_snake(s);

			if (multiplayer == true) {
				erase_snake(s2);
			}


			move_snake(s, boxheight, boxwidth, wraparound, gameover);
			if (multiplayer == true) {
				move_snake(s2, boxheight, boxwidth, wraparound, gameover);
			}

			if (gameover) {
				break;
			}

			if (is_food_eaten(s, f)) {
				generate_food(f, boxheight, boxwidth, s, s2, multiplayer, bf);
				display_food(f);
				grow_snake(s);
				s.score += f.score;
				count1++;
				generated = false;
				
			}
			else {
				if (multiplayer == true) {
					if (is_food_eaten(s2, f)) {
						generate_food(f, boxheight, boxwidth, s, s2, multiplayer, bf);
						display_food(f);
						grow_snake(s2);
						s2.score += f.score;
						count2++;
						generated = false;
						
					}
				}
			}

			if (count1 == 10) {
				s.speed = 40;
				s.level = 2;
			}
			else if (count1 == 20) {
				s.speed = 30;
				s.level = 3;
			}
			else if (count1 == 30) {
				s.speed = 20;
				s.level = 4;
			}
			else if (count1 == 40) {
				s.speed = 10;
				s.level = 5;
			}
			else if (count1 == 50) {
				s.speed = 5;
				s.level = 6;
			}

			if (count2 == 10) {
				s2.speed = 40;
				s2.level = 2;
			}
			else if (count2 == 20) {
				s2.speed = 30;
				s2.level = 3;
			}
			else if (count2 == 30) {
				s2.speed = 20;
				s2.level = 4;
			}
			else if (count2 == 40) {
				s2.speed = 10;
				s2.level = 5;
			}
			else if (count2 == 50) {
				s2.speed = 5;
				s2.level = 6;
			}

			if (multiplayer) {
				if ((count1 % 5 == 0 && count1 != 0 && !bf.is_active && !generated) || (count2 % 5 == 0 && count2 != 0 && !bf.is_active && !generated)) {
					generate_big_food(bf, boxheight, boxwidth, s, s2, multiplayer, f);
					display_bigfood(bf);
					generated = true;
				}
			}
			else {
				if (count1 % 5 == 0 && count1 != 0 && !bf.is_active && !generated) {
					generate_big_food(bf, boxheight, boxwidth, s, s2, multiplayer, f);
					display_bigfood(bf);
					generated = true;
				}
			}


			if (bf.is_active) {
				if (is_bigfood_eaten(s, bf)) {
					s.score += bf.score;
					bf.is_active = false;
					erase_bigfood(bf);
				}
				else if (multiplayer == true && is_bigfood_eaten(s2, bf)) {
					
						s2.score += bf.score;
						bf.is_active = false;
						erase_bigfood(bf);
				}
				else {
					if (multiplayer) {

						if (s.speed < s2.speed) {
							bf.time += s.speed * s.level;
						}
						else {
							bf.time += s2.speed * s2.level;
						}

						if (bf.time >= 6000) {
							bf.is_active = false;
							erase_bigfood(bf);
						}

					}
					else {
						bf.time += s.speed * s.level;
						if (bf.time >= 6000) {
							bf.is_active = false;
							erase_bigfood(bf);
						}
					}
				}
			}


		}

		system("cls");


		if (gameover) {
			print_game_over();

			if (!multiplayer) {

				if (s.score > highscore) {
					highscore = s.score;
					newhigh = true;
				}
				else {
					newhigh = false;
				}


				if (newhigh) {
					print_new_highscore();
				}


			}
			else if (multiplayer) {

				if (p1wins == false && p2wins == false) {
					if (s.score > s2.score) {
						p1wins = true;
					}
					else if (s2.score > s.score) {
						p2wins = true;
					}
				}

				if (s.score > highscore && p1wins) {
					highscore = s.score;
				}
				if (s2.score > highscore && p2wins) {
					highscore = s2.score;
				}

				if (p1wins) {
					print_p1_wins();
				}
				else if (p2wins) {
					print_p2_wins();
				}
				else {
					print_draw();
				}


			}

			print_score(s.name, s.score, s2.name, s2.score, s.color, s2.color, highscore, multiplayer, p1wins, p2wins);


			if (wraparound) {
				highscore_wraparound = highscore;
			}
			else {
				highscore_border = highscore;
			}

			score_file.open("HIGHSCORE.txt", ios::out);
			score_file << highscore_wraparound;
			score_file << endl;
			score_file << highscore_border;
			score_file.close();


		}
		else {

			print_game_terminated();

		}


		gotoxy(0, 58);
		system("pause");


		system("cls");

		print_play_again(playagain);

	} while (playagain);

	system("cls");
	gotoxy(0, 0);
	system("pause");
	return 0;

}