#pragma once
#include "Game.h"

class GameController
{
public:
	// constructors
	GameController(string);
	~GameController();
	// methods
	void default_game();
	void custom_game_autofill();
	void custom_game_manual_fill();
	void print_current_board();
	void print_boards();
private:
	// attributes
	string user_nick;
	Game current_game;
	// methods
	void ask_basic_game(int &, int&, int&);
protected:
};

