#pragma once
#include <iostream>

using namespace std;

class GameBoard
{
private:
	int lines, columns;
	void createGameBoard();
public:
	GameBoard(int lines, int columns); // constructor
	~GameBoard();
	int getLines(), getColumns();
};

GameBoard::GameBoard(int _lines, int _columns) {
	lines = _lines;
	columns = _columns;
}

GameBoard::~GameBoard() {}

void GameBoard::createGameBoard() {
	cout << "Creando tablero con filas: " << lines << " columnas: " << columns << endl;
}


// GETTERS AND SETTERS
int GameBoard::getLines() {
	return lines;
}

int GameBoard::getColumns() {
	return columns;
}