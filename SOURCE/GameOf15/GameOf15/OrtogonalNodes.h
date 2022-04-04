#pragma once
#include <iostream>
#include <stdlib.h>

using namespace std;

// struct Matrix

/// <summary>
/// An ortogonal is a node, as a simple list, this just saves his x, y position, a value, and 4 parents, up, down, left and right
/// </summary>
struct OrtogonalNode
{
    int value, x, y;
    OrtogonalNode* up, * down, * left, * right;

    OrtogonalNode(int value, int x, int y)
    {
        this->value = value;
        this->x = x;
        this->y = y;
        this->up = NULL;
        this->down = NULL;
        this->left = NULL;
        this->right = NULL;
    }

    ~OrtogonalNode() {
    }
};

/// <summary>
/// LIST OF DATA TO SAVE VERTICALLY
/// </summary>
struct VerticalList
{
    OrtogonalNode* tail, * head;

    VerticalList()
    {
        this->tail = this->head = NULL;
    }

    ~VerticalList() {
        OrtogonalNode* current = tail;
        while (current != NULL) {
            OrtogonalNode* recover = current->up;
            current->~OrtogonalNode();
            current = recover;
        }
    }


    void insert(OrtogonalNode* node)
    {
        if (isEmpty()) // if empty, is the first thing to insert
        {
            this->head = this->tail = node;
        }
        else
        {
            // check positon
            if (node->y < tail->y)
            { // insert tail
                insertTail(node);
            }
            else if (node->y > head->y)
            { // insert head
                insertHead(node);
            }
            else
            { // insert at some point between head and tail
                insertMiddle(node);
            }
        }
    }

    void insertHead(OrtogonalNode* node)
    {
        head->down = node;
        node->up = head;
        head = head->down;
    }

    void insertTail(OrtogonalNode* node)
    {
        tail->up = node;
        node->down = tail;
        tail = tail->up;
    }

    void insertMiddle(OrtogonalNode* node)
    {
        OrtogonalNode* temp = tail;
        OrtogonalNode* temp2;

        while (temp->y < node->y)
        {
            temp = temp->down; // break loop when get a value lower than actual data
        }
        temp2 = temp->up; // break list
        temp2->down = node;
        temp->up = node;
        node->down = temp; // merge broken list with new node
        node->up = temp2;
    }

    bool isEmpty()
    {
        return this->tail == NULL;
    }

    void print()
    {
        if (!isEmpty())
        {
            OrtogonalNode* temp = this->tail;
            while (temp != NULL)
            {
                cout << "[y=" << temp->y << " v=" << temp->value << "]" << endl;
                temp = temp->down;
            }
            cout << endl;
        }
    }
};

/// <summary>
/// LIST FOR HORIZONTAL DATA SAVE
/// </summary>
struct HorizontalList {
    OrtogonalNode* tail, * head;

    HorizontalList()
    {
        this->tail = this->head = NULL;
    };

    ~HorizontalList() {
        OrtogonalNode* current = tail;
        while (current != NULL) {
            OrtogonalNode* recover = current->right;
            current->~OrtogonalNode();
            current = recover;
        }
    };

    void insert(OrtogonalNode* node)
    {
        if (isEmpty())
        {
            this->head = this->tail = node;
        }
        else
        {
            // check positon
            if (node->x < tail->x)
            { // insert tail
                insertTail(node);
            }
            else if (node->x > head->x)
            { // insert head
                insertHead(node);
            }
            else
            { // insert at some point between head and tail
                insertMiddle(node);
            }
        }
    };

    void insertHead(OrtogonalNode* node)
    {
        head->right = node;
        node->left = head;
        head = head->right;
    };

    void insertTail(OrtogonalNode* node)
    {
        tail->left = node;
        node->right = tail;
        tail = tail->left;
    };


    void insertMiddle(OrtogonalNode* node)
    {
        OrtogonalNode* temp = tail;
        OrtogonalNode* temp2;

        while (temp->x < node->x)
        {
            temp = temp->right; // break loop when get a value lower than actual data
        }
        temp2 = temp->left; // break list
        temp2->right = node;
        temp->left = node;
        node->right = temp; // merge broken list with new node
        node->left = temp2;
    };

    bool isEmpty()
    {
        return this->tail == NULL;
    };

    void print()
    {
        if (!isEmpty())
        {
            OrtogonalNode* temp = this->tail;
            while (temp != NULL)
            {
                cout << "[x=" << temp->x << " v=" << temp->value << "] ";
                temp = temp->right;
            }
            cout << endl;
        }
    };
};