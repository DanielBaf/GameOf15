#include "Podium.h"

Podium::Podium() {

}

Podium::~Podium(){
}

void Podium::print_top_players() {
	cout << "IMPRIMIENDO JUGADORES" << endl;
}

void Podium::add_player_to_podium(PodiumDataSaver player) {
	// check if list is lower than 20
	cout << "ADD PLAYER" << endl;
	if (this->top_players.size() < 20) {
		// TODO insert but 1st find position
	}
	else {
		// TODO insert but 1st find position
	}
}