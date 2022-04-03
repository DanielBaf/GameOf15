#include "Game.h"
Game::Game() {
    this->boards = std::vector<OrtogonalMatrix*>(1);
    this->user_nick = "MrMayoneso";
    this->steps = 0;
    this->levels = 1;
    this->current_board = 0;
}

Game::~Game() {
    // delete boards
    cout << "size: " << this->boards.size();
    cout << "levels: " << this->levels;
    for (int i = 0; i < this->boards.size() - 1; i++)
    {
        if (i < this->boards.size()) {
            this->boards[i]->~OrtogonalMatrix();
        }
    }
    // delete board array
}

void Game::create_game(int lines, int columns, vector<vector<int>> to_fill, bool autofill) {
    // start index = 0;
    int start_index = 0;
    // add dinamically levels
    for (int i = 0; i < this->levels; i++)
    {
        // get array of data
        vector<int> current_data_to_fill;
        if (autofill) {
            current_data_to_fill = create_array(lines, columns, start_index);
            start_index += lines * columns - 1;
        }
        else {
            current_data_to_fill = to_fill[i];
        }
        // save data to new orotognal matrix
        OrtogonalMatrix* board = new OrtogonalMatrix();
        board->set_highest(i + 1); // new max value for formatting, if matrix highest is 88 -> new matrix max length is 88*(i+1)
        board->fill(lines, columns, current_data_to_fill);
        // increases 
        this->boards[i] = board;
    }
}


vector<int> Game::create_array(int cols, int rows, int start_index) {
    std::vector<int> intArray(cols * rows);
    // fill array
    for (int i = 0; i < cols * rows - 1; i++)
    {
        intArray[i] = start_index +  i + 1;
    }
    cout << endl;
    // shuffle array
    std::random_device rd;
    auto rng = std::default_random_engine(rd());
    std::shuffle(intArray.begin(), intArray.end() - 1, rng); // i always want the last as 0
    return intArray;
};

bool Game::move_cell(int value, BoardMovements action) {
    OrtogonalNode* to_move = this->boards[this->current_board]->findByValue(value);
    if (to_move != NULL) {
        switch (action)
        {
        case UP:
            return move_node(to_move, to_move->up);
        case DOWN:
            return move_node(to_move, to_move->down);
        case LEFT:
            return move_node(to_move, to_move->left);
        case RIGHT:
            return move_node(to_move, to_move->right);
        default:
            return false;
        }
    }
    return false;
};

bool Game::move_node(OrtogonalNode* origin, OrtogonalNode* destination) {
    // check nodes are not null
    if (origin != NULL && destination != NULL) {
        if (destination->value == 0) {
            int data_recover = destination->value;
            destination->value = origin->value;
            origin->value = data_recover;
            return true;
        }
    }
    return false;
}

void Game::print_board() {
    try
    {
        cout << "BOARD: " << this->current_board << endl;
        this->boards[this->current_board]->print();
    }
    catch (const std::exception&)
    {
        cout << "ERROR PRINTING BOARD: " << endl;
    }
}

void Game::forward_board() {
    if (this->current_board < this->levels - 1) {
        this->current_board++;
    }
}

void Game::backward_board() {
    if (this->current_board > 0) {
        this->current_board--;
    }
}

void Game::set_levels(int levels) {
    this->levels = levels;
    this->boards = std::vector<OrtogonalMatrix*>(levels);
}

int Game::get_levels() {
    return this->levels;
}