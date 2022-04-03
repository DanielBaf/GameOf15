#pragma once
#include <vector>
#include "PodiumDataSaver.h"


class Podium
{
public:
	Podium();
	~Podium();
	// methods
	void print_top_players();
	void add_player_to_podium(PodiumDataSaver);
private:
	vector<PodiumDataSaver> top_players;
};

