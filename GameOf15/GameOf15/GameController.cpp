#include "GameController.h"
#include "Sorter.h"

GameController::GameController(string nickname) {
	this->user_nick = nickname;
	this->current_game = Game();
}

GameController::~GameController() {
	this->current_game.~Game();
}

void GameController::default_game() {
	std::vector<vector<int>> NA;
	this->current_game.create_game(4, 4, NA, true);

}
void GameController::custom_game_autofill() {
	int rows, columns, levels;
	ask_basic_game(rows, columns, levels);
	std::vector<vector<int>> NA;
	this->current_game.set_levels(levels);
	this->current_game.create_game(rows, columns, NA, true);
}

void GameController::custom_game_manual_fill() {
	int rows, columns, levels;
	ask_basic_game(rows, columns, levels);
	// TODO ask for data
	vector<int> data = sort_array_manually(1,rows*columns, columns);
}

void GameController::ask_basic_game(int &rows, int &columns, int &levels) {
	while (rows < 2 || columns < 2 || levels < 1) {
		cout << CLEAR_CONSOLE;
		cout << endl << "PREPARATIVOS PARA TABLEROS PERSONALIZADOS"<<endl;
		cout << endl<<"Por favor ingrese los valores solicitados"<<endl;
		cout << "Ingrese no. niveles (min 1): ";
		cin >> levels;
		cout << "Ingrese no. filas (min 2): ";
		cin >> rows;
		cout << "Ingrese no. columnas (min 2): ";
		cin >> columns;
		// reset buffer
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "---------------------------------------" << endl;
	}
	cout << endl << "Se generaran " << levels << " tablero(s), de " << columns << " columna(s) x " << rows << " fila(s)" << endl;
}

void GameController::print_current_board() {
	this->current_game.print_board();
}

void GameController::print_boards() {
	cout << "PRINT BOARDS";
	for (int i = 0; i < this->current_game.get_levels(); i++)
	{
		print_current_board();
		this->current_game.forward_board();
	}
}
