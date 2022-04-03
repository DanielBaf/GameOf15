#pragma once
#include<vector>
#include<iostream>

using namespace std;

// prototypes
vector<int> sort_array_manually(int, int, int);
void print_array_fragmented(vector<int>, int);
vector<int> swap_vals_array(vector<int>);
void restore_cin_buffer();

vector<int> sort_array_manually(int index_start, int size, int columns) {
	// create vector
	vector<int> to_fill(size);
	string act = "";
	for (int i = 0; i < size; i++)
	{
		to_fill[i] = i + index_start;
	}
	// print array and sort
	while (act != "y") {
		cout << CLEAR_CONSOLE;
		print_array_fragmented(to_fill, columns);
		to_fill = swap_vals_array(to_fill);
		cout << "¿Deseas terminar de revolver el arreglo? (y/n): ";
		cin >> act;
		restore_cin_buffer();
	}
	// set last on array as 0
	to_fill[size - 1] = 0;
	return to_fill;
}

void print_array_fragmented(vector<int> to_fill, int break_at) {
	int jump_lines = 0;
	// print
	while (true) {
		for (int i = 0; i < break_at; i++)
		{
			// print vector 10 by 10
			if (i + jump_lines * break_at < to_fill.size()) {
				cout << "[n=" << i + (break_at * jump_lines) << ",v=" << to_fill[i + (break_at * jump_lines)] << "] ";
			}
			else {
				return;
			}
		}
		jump_lines++;
		cout << endl;
	}
}

vector<int> swap_vals_array(vector<int> to_swap) {
	cout << endl;
	cout << "Ingresa la posicon a mover(n) seguido de la posicion destino(n)" << endl;
	cout << "EJEMPLO: 1 4 -> mover n=1 a n=4\n...Ingresa las cooredenadas x1 x2: ";
	int origin, direction, transaction;
	cin >> origin;
	cin >> direction;
	restore_cin_buffer();
	// check if positions are valid
	if ((origin < to_swap.size() && origin >=0) && (direction < to_swap.size() && direction >=0)) {
		transaction = to_swap[direction];
		to_swap[direction] = to_swap[origin];
		to_swap[origin] = transaction;
	}
	else {
		cout << "IMPOSIBLE MOVER, EL RANGO DE NUMEROS ES [" << 0 << to_swap.size() - 1 << endl;
	}
	return to_swap;
}

void restore_cin_buffer() {
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}