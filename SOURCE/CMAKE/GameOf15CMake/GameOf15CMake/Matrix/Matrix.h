#pragma once
#include <sstream>
#include "MatrixComponents.h"
constexpr auto RESET = "\033[0m";
constexpr auto GREEN = "\033[32m"      /* Green */;

struct OrtogonalMatrix {
	OrtogonalHeaders* headers;
	OrtogonalAsides* asides;
	int max_width;
	int highest_val;

	OrtogonalMatrix() {
		this->headers = new OrtogonalHeaders();
		this->asides = new OrtogonalAsides();
		this->highest_val = 1;
		this->max_width = 2;
	};

	~OrtogonalMatrix() {
		// delete all nodes
		this->headers->~OrtogonalHeaders();
		this->asides->~OrtogonalAsides();
	};

	void insert(int x, int y, int value) {
		// create data to insert
		OrtogonalNode* node = new OrtogonalNode(value, x, y);
		// find position to insert
		if (headers->exist(x) == false) {
			headers->insert(new HeaderNode(x));

		}
		if (asides->exist(y) == false) {
			asides->insert(new AsideNode(y));
		}
		// temporal data, to recover data after
		HeaderNode* tempHeader = headers->find(x);
		AsideNode* tempoAside = asides->find(y);
		// update
		tempHeader->column->insert(node);
		tempoAside->row->insert(node);
	};

	void fill(int columns, int rows, vector<int> init_num_fill) {
		calc_max_witdh(columns, rows);
		int item_to_assign = 0;
		for (int i = 0; i < columns; i++)
		{
			for (int j = 0; j < rows; j++)
			{
				insert(j, i, init_num_fill[item_to_assign++]);// TODO receive data to insert on method
			}
		}
	};

	void print() {
		// print via rows | aside nodes
		OrtogonalNode* origin = this->asides->tail->row->tail;
		int maxLengh = 6;
		string tmp;

		AsideNode* currentRowNode = this->asides->tail;
		int line = 1;
		int column = 1;
		print_headers();

		while (currentRowNode != NULL) {
			// print row
			print_border(line++);
			OrtogonalNode* node = currentRowNode->row->tail;
			while (node != NULL) {
				// calc space to keep all same width
				calc_space(node->value, '[', "] ");
				node = node->right;
			}
			// new row
			currentRowNode = currentRowNode->next;
			cout << endl;
		}
	}

	void print_headers() {
		// print header
		print_border(0);
		OrtogonalNode* node = this->headers->tail->column->tail;
		int i = 1;
		while (node != NULL) {
			print_border(i++);
			node = node->right;
		}
		cout << RESET << endl;
	};

	void calc_space(int data, char open, string close) {
		string dataString = cast_int_to_string(data);
		cout << open;
		for (int i = 0; i < this->max_width; i++)
		{
			if (i < dataString.length() && data != 0) {
				cout << dataString[i];
			}
			else {
				cout << " ";
			}
		}
		cout << close;
	};

	void print_border(int data) {
		cout << GREEN;
		calc_space(data, '|', "| ");
		cout << RESET;
	};

	void calc_max_witdh(int rows, int columns) {
		// get last value on array
		this->max_width = cast_int_to_string(rows * columns * this->highest_val).length();
	};

	string cast_int_to_string(int data) {
		stringstream ss;
		string s;
		ss << data;
		ss >> s;
		return s;
	};

	/// <summary>
	/// find a node by using the node value, I'll assume there is no multuple nodes for same value
	/// retunrr the 1st node found
	/// </summary>
	/// <returns>the node found</returns>
	OrtogonalNode* findByValue(int val_find) {
		// start with the first row
		AsideNode* row_data = this->asides->tail;
		OrtogonalNode* current;
		while (row_data != NULL) {
			// get row
			current = row_data->row->tail;
			while (current != NULL) {
				if (current->value == val_find) {
					return current;
				}
				current = current->right;
			}
			row_data = row_data->next;
		}

		return NULL;
	};

	void set_highest(int highest_val) {
		this->highest_val = highest_val;
	};


};