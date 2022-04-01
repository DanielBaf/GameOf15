#pragma once
#include <sstream>
#include "MatrixComponents.h"
#define RESET "\033[0m"
#define GREEN   "\033[32m"      /* Green */

struct OrtogonalMatrix {
    OrtogonalHeaders* headers;
    OrtogonalAsides* asides;
    int maxWidth;

    OrtogonalMatrix (){
        headers = new OrtogonalHeaders();
        asides = new OrtogonalAsides();
        maxWidth = 4;
    }

    void insert(int x, int y, int value) {
        // create data to insert
        OrtogonalNode* node = new OrtogonalNode(value, x, y);
        // find position to insert
        if (headers->exist(x)==false) {
            headers->insert(new HeaderNode(x));
        }
        if (asides->exist(y)==false) {
            asides->insert(new AsideNode(y));
        }
        // temporal data, to recover data after
        HeaderNode* tempHeader = headers->find(x);
        AsideNode* tempoAside = asides->find(y);
        // update
        tempHeader->column->insert(node);
        tempoAside->row->insert(node);
    }

    void fill(int columns, int rows, vector<int> init_num_fill) {
        calcMaxWitdh(columns, rows);
        int item_to_assign = 0;
        for (int i = 0; i < columns; i++)
        {
            for (int j = 0; j < rows; j++)
            {
                insert(j, i, init_num_fill[item_to_assign++]);// TODO receive data to insert on method
            }
        }
    }

    void print() {
        // print via rows | aside nodes
        OrtogonalNode* origin = this->asides->tail->row->tail;
        int maxLengh = 6;
        string tmp;

        AsideNode* currentRowNode = this->asides->tail;
        int line = 1;
        int column = 1;
        printHeaders();

        while (currentRowNode != NULL) {
            // print row
            printBorder(line++);
            OrtogonalNode *node = currentRowNode->row->tail;
            while (node != NULL) {
                // calc space to keep all same width
                calcSpace(node->value,'[',"] ");
                node = node->right;
            }
            // new row
            currentRowNode = currentRowNode->next;
            cout << endl;
        }

    }


    void printHeaders() {
        // print header
        printBorder(0);
        OrtogonalNode* node =  this->headers->tail->column->tail;
        int i = 1;
        while (node != NULL) {
            printBorder(i++);
            node = node->right;
        }
        cout << RESET<<endl;
    }

    void calcSpace(int data, char open, string close) {
        string dataString = castIntToString(data);
        cout << open;
        for (int i = 0; i < this->maxWidth; i++)
        {
            if (i < dataString.length() && data != 0) {
                cout <<dataString[i];
            }
            else {
                cout << " ";
            }
        }
        cout<<close;
    }

    void printBorder(int data) {
        cout << GREEN;
        calcSpace(data,'|',"| ");
        cout << RESET;
    }

    void calcMaxWitdh(int rows, int columns) {
        this->maxWidth = castIntToString(rows*columns).length();
    }

    string castIntToString(int data) {
        stringstream ss;
        string s;
        ss << data;
        ss >> s;
        return s;
    }


};