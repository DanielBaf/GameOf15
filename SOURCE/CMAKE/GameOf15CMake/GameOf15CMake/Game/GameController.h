#pragma once
#include <chrono>
#include <ctime>   
#include <conio.h>
#include "../Podium/Podium.h"
#include "../Game/Game.h"

class GameController
{
public:
	// constructors
	GameController(string);
	~GameController();
	// variables
	// 
	// methods
	void default_game();
	void custom_game_autofill();
	void custom_game_manual_fill();
	void custom_game_file_fill();
	void print_current_board();
	void print_boards();
	void start_game();
	void restore_cin_buffer_game();
	void print_help_game();
	PodiumDataSaver get_player_stats();
private:
	// attributes
	string user_nick;
	Game current_game;
	PodiumDataSaver player_stats;
	// methods
	void ask_basic_game(int&, int&, int&);
	void move_cell_input(int, string);
	void print_game_result(std::chrono::duration<double>, bool);
protected:
};