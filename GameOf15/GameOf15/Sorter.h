#pragma once
#include<vector>
#include<iostream>

using namespace std;

// prototypes
vector<int> sort_array_manually(int, int, int);
vector<int> swap_vals_array(vector<int>);
void print_array_fragmented(vector<int>, int);
void restore_cin_buffer();
bool find_on_array(int, vector<int>);

vector<int> sort_array_manually(int index_start, int size, int columns) {
	// create vector
	vector<int> to_fill(size);
	string act = "";
	// create array 
	int inserted = 0, input;

	while(inserted < size - 1) {
		cout << CLEAR_CONSOLE;
		cout << "Llenando arreglo, arreglo actual: " << endl;
		print_array_fragmented(to_fill, columns);
		cout << "Ingresa un nuevo valor, rango [" << index_start << "-" << index_start + size - 2<<"]: ";
		// get value, check if already declared and add it
		cin >> input;
		if (!find_on_array(input, to_fill) && input >= index_start && input < size + index_start - 1) {
			to_fill[inserted] = input; // add
			inserted++;
		}
		else {
			cout << "El valor ya existe o esta fuera del rango esperaddo"<<endl;
			cout << ".. enter para continuar";
			_getch();
		}
	}
	// set last on array as 0
	to_fill[size - 1] = 0;

	cout << "GENRATED ARRAY: " << endl;
	for (size_t i = 0; i < to_fill.size(); i++)
	{
		cout << "arr " << i << ": " << to_fill[i];
	}
	return to_fill;
}

bool find_on_array(int find, vector<int> data) {
	for (int i = 0; i < data.size(); i++)
	{
		if (data[i] == find) {
			return true;
		}
	}
	return false;
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

void restore_cin_buffer() {
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}