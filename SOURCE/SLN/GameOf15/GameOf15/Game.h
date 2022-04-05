#pragma once
#include <algorithm>
#include <random>
#include <vector>
#include "Matrix.h"
constexpr auto CLEAR_CONSOLE = "\x1B[2J\x1B[H";

enum BoardMovements {
	UP, DOWN, LEFT, RIGHT
};

class Game
{
public:
	Game();
	~Game();
	void print_board();
	bool move_cell(int, BoardMovements);
	void forward_board();
	void backward_board();
	void create_game(int, int, vector<vector<int>>, bool);
	void set_levels(int);
	int get_levels();
	int get_steps();
	bool is_game_won();
	int check_is_won();
	int get_final_points();
private:
	// atributes
	int levels, current_board, final_points;
	long steps;
	string user_nick;
	vector<OrtogonalMatrix*> boards;
	// methods
	vector<int> create_array(int, int, int);
	bool move_node(OrtogonalNode*, OrtogonalNode*);
protected:
};

