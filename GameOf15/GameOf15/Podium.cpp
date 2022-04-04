#include "Podium.h"

Podium::Podium() {
	this->top_players = vector<PodiumDataSaver>(20);
}

Podium::~Podium() {
}

void Podium::print_top_players() {
	// print headers

	cout << endl << endl << "_______________________________________________________________" << endl << "|";
	fix_size_print(3, "POS", '|');
	fix_size_print(20, " NOMBRE", '|');
	fix_size_print(14, " MOVIMIENTOS", '|');
	fix_size_print(10, " PUNTOS", '|');
	fix_size_print(10, " TIEMPO(s)", '|');
	cout << endl;
	cout << "---------------------------------------------------------------" << endl;
	for (PodiumDataSaver pod : this->top_players)
	{ // NO | NAME | MOVEMENTS | POINTS | TIME |
		// check if is a valid to print
		if (pod.get_position() != -1) {
			cout << "|";
			fix_size_print(3, to_string(pod.get_position()), '|');
			fix_size_print(20, pod.get_user_nick(), '|');
			fix_size_print(14, to_string(pod.get_steps()), '|');
			fix_size_print(10, to_string(pod.get_points()), '|');
			fix_size_print(10, to_string(pod.get_elapsed_time().count()) + "s", '|');
			cout << endl;
		}
	}
	cout << "_______________________________________________________________" << endl << endl << endl;
}

void Podium::add_player_to_podium(PodiumDataSaver player) {
	// check if list is lower than 20
	int new_pos = find_new_insert_pos(player.get_points());
	if (new_pos > -1 && new_pos < 20) {
		// insert
		cout << "ADD TO " << new_pos << " VAL: " << player.get_user_nick();
		// move all current players valid from new post to last valid
		update_list(new_pos, player);
	}
}

void Podium::fix_size_print(int max_size, string data, char close_item) {
	cout << data;
	for (int i = 0; i < max_size - data.length(); i++)
	{
		cout << " ";
	}
	cout << close_item;
}

int Podium::find_new_insert_pos(int points) {
	int position = 0;
	for (PodiumDataSaver pod : this->top_players)
	{
		if (pod.get_points() < points) {
			return position;
			break;
		}
		position++;
	}
	return -1;
}

void Podium::update_list(int new_pos, PodiumDataSaver player) {
	// update all files from new_pos to last valid
	if (new_pos < this->top_players.size()) {
		// move all files  from x to last [ 1, 2, 4] -> delete 4, move 2 -> 4, 1 -> 2

		for (int i = this->top_players.size() - 1; i > new_pos; i--)
		{
			this->top_players[i] = this->top_players[i - 1];
		}
		this->top_players[new_pos] = player;
	}
}