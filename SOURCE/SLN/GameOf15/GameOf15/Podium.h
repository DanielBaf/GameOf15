#pragma once
#include <vector>
#include <list>
#include <string>
#include "PodiumDataSaver.h"

using namespace std;

class Podium
{
public:
	Podium();
	~Podium();
	// methods
	void print_top_players();
	void add_player_to_podium(PodiumDataSaver);
private:
	std::vector<PodiumDataSaver> top_players;
	void fix_size_print(int,string,char);
	int find_new_insert_pos(int);
	void update_list(int, PodiumDataSaver);
	string format_seconds(double);
};

