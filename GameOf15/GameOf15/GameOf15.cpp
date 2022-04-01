// GameOf15.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <random>
#include <vector>
#include "Matrix.h"

using namespace std;

// prototype
vector<int> create_array(int cols, int rows);

int main()
{
    // get data
    int lines = 4, columns = 4;

    // create array
    vector<int> to_fill = create_array(lines,columns);
    // create matrix
    OrtogonalMatrix* matrix = new OrtogonalMatrix();
    matrix->fill(lines,columns,to_fill);

    matrix->print();
    
    return 0;
};

vector<int> create_array(int cols, int rows) {
    std::vector<int> intArray(cols * rows);
    // fill array
    for (int i = 0; i < cols * rows - 1; i++)
    {
        intArray[i] = i + 1;
    }
    // shuffle array
    auto rng = std::default_random_engine{};
    std::shuffle(intArray.begin(), intArray.end(), rng);
    return intArray;
};


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
