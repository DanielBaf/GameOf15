#include "GameController.h"
#include "../Utils/Sorter.h"

GameController::GameController(string nickname) {
	this->user_nick = nickname;
	this->current_game = Game();
};

GameController::~GameController() {
	this->current_game.~Game();
};

/// <summary>
/// Create a Game with default configurations
/// </summary>
void GameController::default_game() {
	std::vector<vector<int>> NA;
	this->current_game.create_game(4, 4, NA, true);

};

/// <summary>
/// Create a game with custom matrix size, but the data of matrix is automatically filled
/// </summary>
void GameController::custom_game_autofill() {
	int rows, columns, levels;
	ask_basic_game(rows, columns, levels);
	std::vector<vector<int>> NA;
	this->current_game.set_levels(levels);
	this->current_game.create_game(rows, columns, NA, true);
};

/// <summary>
/// Custom matrix size and ask 1 by one the value of each node, if there is multiple boards, ask n nodes per m boards that exists
/// </summary>
void GameController::custom_game_manual_fill() {
	int rows, columns, levels;
	ask_basic_game(rows, columns, levels);
	// TODO ask for data
	std::vector<vector<int>> matrixes_data(levels);
	for (int i = 0; i < levels; i++)
	{ // start at 1 + (rows*cols * i)
		matrixes_data[i] = sort_array_manually(1 + (rows * columns * i), rows * columns, columns);
	}
	this->current_game.set_levels(levels);
	this->current_game.create_game(rows, columns, matrixes_data, false);
};

/// <summary>
/// Start timer, steps counter... and run the game, move the values of matrix... 
/// </summary>
void GameController::start_game() {
	// start running time
	auto start_time = std::chrono::system_clock::now();
	int action = -1;
	string option = "";
	bool is_game_won = false;
	cout << CLEAR_CONSOLE; // clear for linux terminals
	system("CLS"); // clear for windows terminals
	cout << "Bienvendio, " << this->user_nick << " aqui empieza el juego" << endl << "Escribe 'help' para ver los comandos" << endl << endl;

	while (action != 9) {
		print_boards();
// 		print_current_board();
		cout << "Accion: ";
		cin >> option;
		if (option._Equal("help")) {
			print_help_game();
		}
		else if (option._Equal("board")) {
			string action;
			cin >> action;
			cout << "ACTION: " << action;
		}
		else if (option._Equal("mv")) { // mv = move
			int cell;
			string action;
			cin >> cell;
			cin >> action;
			move_cell_input(cell, action);
			// check if won
			if (this->current_game.check_is_won() == -1) {
				action = 9;
				is_game_won = true;
				cout << "Cerrando el juego...";
				system("PAUSE");
				break;
			}
		}
		else if (option._Equal("restart")) {
			cout << "NO PROGRAMADO AÚN" << endl;
		}
		else if (option._Equal("stop")) { // end game
			// end game
			action = 9;
		}
		else {
			cout << CLEAR_CONSOLE; // clear for linux terminals
			system("CLS"); // clear for windows terminals
			cout << "OPERACION INVALIDA";
		}
	}
	// end of game and time
	auto end_time = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end_time - start_time;
	print_game_result(elapsed_seconds, is_game_won);
	// create a new GameDataSaver
};

/// <summary>
/// Sub method to cast an "@action" into ENUM 
/// </summary>
/// <param name="cell"></param>
/// <param name="action"></param>
void GameController::move_cell_input(int cell, string action) {
	cout << CLEAR_CONSOLE; // clear for linux terminals
	system("CLS"); // clear for windows terminals
	if (action._Equal("up")) {
		this->current_game.move_cell(cell, UP);
	}
	else if (action._Equal("down")) {
		this->current_game.move_cell(cell, DOWN);
	}
	else if (action._Equal("right")) {
		this->current_game.move_cell(cell, RIGHT);
	}
	else if (action._Equal("left")) {
		this->current_game.move_cell(cell, LEFT);
	}
	else {
		cout << "OPERACION INVALIDA" << endl;
	}
};

/// <summary>
/// Common method to get the number of rows, columns and levels, uses pointers to return multiple values to incomer method
/// </summary>
/// <param name="rows"></param>
/// <param name="columns"></param>
/// <param name="levels"></param>
void GameController::ask_basic_game(int& rows, int& columns, int& levels) {
	while (rows < 3 || columns < 3 || levels < 1) {
		cout << CLEAR_CONSOLE; // clear for linux terminals
		system("CLS"); // clear for windows terminals
		cout << endl << "PREPARATIVOS PARA TABLEROS PERSONALIZADOS" << endl;
		cout << endl << "Por favor ingrese los valores solicitados" << endl;
		cout << "Ingrese no. niveles (min 1): ";
		cin >> levels;
		cout << "Ingrese no. filas (min 3): ";
		cin >> rows;
		cout << "Ingrese no. columnas (min 3): ";
		cin >> columns;
		// reset buffer
		restore_cin_buffer_game();
		cout << "---------------------------------------" << endl;
	}
	cout << endl << "Se generaran " << levels << " tablero(s), de " << columns << " columna(s) x " << rows << " fila(s)" << endl;
};

/// <summary>
/// Print the playable board
/// </summary>
void GameController::print_current_board() {
	this->current_game.print_board();
};

/// <summary>
/// Print all boards wich belongs to actual game
/// </summary>
void GameController::print_boards() {
	int board_recover = this->current_game.get_current_board();
	this->current_game.set_current_board(0);
	for (int i = 0; i < this->current_game.get_levels(); i++)
	{
		print_current_board();
		this->current_game.forward_board();
	}
	this->current_game.set_current_board(board_recover);
};

/// <summary>
/// CUSTOM MENU for comman "help"
/// </summary>
void GameController::print_help_game() {
	cout << CLEAR_CONSOLE; // clear for linux terminals
	system("CLS"); // clear for windows terminals
	cout << "---------- MENU ACCIONES EN JUEGO ----------" << endl;
	cout << "| help : despliega lista de comandos" << endl;
	cout << "| board : imprime el tablero actual" << endl;
	cout << "| board $action: imprime el siguiente tablero en caso exista" << endl;
	cout << "| \t$action = PREV, NEXT, ALL: imprime el tablero anterior o siguiente o todos" << endl;
	cout << "| mv $id $action" << endl;
	cout << "| \t$id=el valor de la celda" << endl;
	cout << "| \t$action = up, down, left, right " << endl;
	cout << "| restart : reinicia el juego" << endl;
	cout << "| stop: termina el juego actual" << endl;
	cout << "-----------------------------------------___" << endl;
	system("PAUSE");
	cout << CLEAR_CONSOLE; // clear for linux terminals
	system("CLS"); // clear for windows terminals
};

void GameController::custom_game_file_fill() {
	// create object data reader
}

/// <summary>
/// Restore the cache at std::cin
/// </summary>
void GameController::restore_cin_buffer_game() {
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
};

/// <summary>
/// Prints the number of steps, the time and the points
/// </summary>
/// <param name="elapsed_seconds"></param>
void GameController::print_game_result(std::chrono::duration<double> elapsed_seconds, bool is_game_won) {
	// calc points
	cout << CLEAR_CONSOLE; // clear for linux terminals
	system("CLS"); // clear for windows terminals
	cout << "RESULTADOS: " << endl;
	cout << "Usuario: " << this->user_nick << endl;
	cout << "Pasos: " << this->current_game.get_steps() << endl;
	cout << "Tiempo: " << elapsed_seconds.count() << "s" << endl;
	cout << "Puntos: " << this->current_game.get_final_points() << endl;
	cout << "Juego ganado: " << is_game_won << endl;
	// TODO calc pints and show
	system("PAUSE");

	// create object to save data
	this->player_stats = PodiumDataSaver(this->current_game.get_steps(), -1, this->current_game.get_final_points(), this->user_nick, elapsed_seconds);
}

PodiumDataSaver GameController::get_player_stats() {
	return this->player_stats;
}