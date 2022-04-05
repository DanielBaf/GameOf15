// GameOf15CMake.cpp : Defines the entry point for the application.
//

#include "GameOf15CMake.h"

using namespace std; 
// variable global
Podium leader_board;
// prototypes
void print_main_menu(string);
void print_new_game_menu(string);
void print_leaderboard_menu();
void exec_new_game(string);
void restore_cin_buffer();


int main()
{
	// main menu
	leader_board = Podium();
	int choice = -1;
	// ask username
	char user_nick[20];
	string msg = "";
	cout << "Ingresa tu nickname: ";
	cin.getline(user_nick, 20);
	// execute actions
	do {
		// read actions
		print_main_menu(msg);
		cin >> choice;
		// execute action
		switch (choice)
		{
		case 1:
			exec_new_game(user_nick);
			break;
		case 2:
			print_leaderboard_menu();
			break;
		case 3:
			cout << CLEAR_CONSOLE;
			restore_cin_buffer();
			cout << "Ingrese el nuevo nicK: ";
			cin.getline(user_nick, 20);
			break;
		case 9:
			return 0;
		default:
			msg = "OPERACION INVALIDA";
			restore_cin_buffer();
			break;
		}
	} while (choice != '9');

	return EXIT_SUCCESS;
};

void print_main_menu(string footer_msg) {
	cout << CLEAR_CONSOLE;
	cout << "---- MENU PRINCIPAL GAME OF 15 (dynamic) ----" << endl;
	cout << "| 1. Nuevo juego " << endl;
	cout << "| 2. Tablero de punteos" << endl;
	cout << "| 3. Cambiar de jugador" << endl;
	cout << "| 9. Salir" << endl;
	cout << "---------------------------------------------" << endl;
	if (footer_msg != "") {
		cout << "MENSAJE: " << footer_msg << endl;
	}
	cout << " ... selecciona una opcion: ";
}

void print_new_game_menu(string footer_msg) {
	cout << "-------- MENU CREACION DE JUEGO NUEVO --------" << endl;
	cout << "| 1. Todos los ajustes por defecto " << endl;
	cout << "| 2. Tablero personalizado y llenado automatico" << endl;
	cout << "| 3. Tablero personalizado y llenado manual" << endl;
	cout << "| 4. Tablero personalizado y llenado a partir de archivo" << endl;
	cout << "| 9. Regresar" << endl;
	cout << "---------------------------------------------" << endl;
	if (footer_msg != "") {
		cout << "MENSAJE: " << footer_msg << endl;
	}
	cout << " ... selecciona una opcion: ";
};

void print_leaderboard_menu() {
	cout << CLEAR_CONSOLE;
	cout << "------------- MENU PUNTUACIONES --------------" << endl;
	leader_board.print_top_players();
	cout << "---------------------------------------------" << endl;
	cout << " ... enter para regresar: ";
	_getch();
};

void exec_new_game(string nickname) {
	int action = -1;
	GameController game_controller = GameController(nickname);
	string msg = "";
	// execute actions
	while (action != 9) {
		// get info
		cout << CLEAR_CONSOLE;
		print_new_game_menu(msg);
		cin >> action;
		restore_cin_buffer();
		msg = "";
		// show data
		switch (action)
		{
		case 1: // default values
			game_controller.default_game();
			game_controller.start_game();
			// add to list
			leader_board.add_player_to_podium(game_controller.get_player_stats());
			break;
		case 2: // custom size and fill data automatically
			game_controller.custom_game_autofill();
			game_controller.start_game();
			leader_board.add_player_to_podium(game_controller.get_player_stats());
			break;
		case 3: // custom size and fill manually
			game_controller.custom_game_manual_fill();
			game_controller.start_game();
			leader_board.add_player_to_podium(game_controller.get_player_stats());
			break;
		case 4: // load values from file and custom size
			msg = "OPCION NO PROGRAMADA";
			break;
		case 9: // DO NOTHING, RETURN PREVIOUS MENU AND DELETE DATA SAVED
			break;
		default:
			msg = "OPCION INVALIDA";
			break;
		}
	}
	// delete object
	game_controller.~GameController();
};