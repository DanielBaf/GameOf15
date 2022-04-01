#pragma once
#include "OrtogonalNodes.h"

/// <summary>
/// HEADER NODES, UP = NULL
/// </summary>
struct HeaderNode
{
    int x;
    HeaderNode* next, * previous;
    VerticalList* column;


    HeaderNode(int x) {
        this->x = x;
        this->next = this->previous = NULL;
        this->column = new VerticalList();
    }
};

/// <summary>
/// EACCH NODE FROM ANY SIDE 
/// </summary>
struct AsideNode {
    int y;
    AsideNode* next, * previous;
    HorizontalList* row;


    AsideNode(int y) {
        this->y = y;
        this->next = this->previous = NULL;
        this->row = new HorizontalList();
    }
};

/// <summary>
/// GROUP OF MULTIPLE HEADER NODES
/// </summary>
struct OrtogonalHeaders {
    HeaderNode* head, * tail;

    OrtogonalHeaders()
    {
        this->tail = this->head = NULL;
    }

    void insert(HeaderNode* node)
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
    }

    void insertHead(HeaderNode* node)
    {
        head->next = node;
        node->previous = head;
        head = head->next;
    }

    void insertTail(HeaderNode* node)
    {
        tail->previous = node;
        node->next = tail;
        tail = tail->previous;
    }


    void insertMiddle(HeaderNode* node)
    {
        HeaderNode* temp = tail;
        HeaderNode* temp2;

        while (temp->x < node->x)
        {
            temp = temp->next; // break loop when get a value lower than actual data
        }
        temp2 = temp->previous; // break list
        temp2->next = node;
        temp->previous = node;
        node->next = temp; // merge broken list with new node
        node->previous = temp2;
    }

    bool isEmpty()
    {
        return this->tail == NULL;
    }

    void print()
    {
        if (!isEmpty())
        {//  // LEFT -> previous  | RIGHT ->  next
            HeaderNode* temp = this->tail;
            while (temp != NULL)
            {
                cout << "[x=" << temp->x << " v=";
                temp->column->print();
                cout << "] ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    bool exist(int x) {
        if (isEmpty()) {
            return false;
        }
        else {
            // search
            HeaderNode* temp = tail;
            while (temp != NULL) {
                if (temp->x == x) {
                    return true;
                }
                temp = temp->next;
            }
            return false;
        }
    }

    HeaderNode* find(int x) {
        if (exist(x)) {
            HeaderNode* temp = tail;
            while (temp->x != x) {
                temp = temp->next;
            }
            return temp;
        }
        return new HeaderNode(-1);
    }
};

/// <summary>
/// GROUP OF MULTIPLE ASIDE NODES
/// </summary>
struct OrtogonalAsides {
    AsideNode* head, * tail;

    OrtogonalAsides()
    {
        this->tail = this->head = NULL;
    }

    void insert(AsideNode* node)
    {
        if (isEmpty())
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

    void insertHead(AsideNode* node)
    {
        head->next = node;
        node->previous = head;
        head = head->next;
    }

    void insertTail(AsideNode* node)
    {
        tail->previous = node;
        node->next = tail;
        tail = tail->previous;
    }


    void insertMiddle(AsideNode* node)
    {
        AsideNode* temp = tail;
        AsideNode* temp2;

        while (temp->y < node->y)
        {
            temp = temp->next; // break loop when get a value lower than actual data
        }
        temp2 = temp->previous; // break list
        temp2->next = node;
        temp->previous = node;
        node->next = temp; // merge broken list with new node
        node->previous = temp2;
    }

    bool isEmpty()
    {
        return this->tail == NULL;
    }

    void print()
    {
        if (!isEmpty())
        {//  // LEFT -> previous  | RIGHT ->  next
            AsideNode* temp = this->tail;
            while (temp != NULL)
            {
                cout << "[y=" << temp->y << " v=";
                temp->row->print();
                cout << "] " << endl;
                temp = temp->next;
            }
            cout << endl;
        }
    }

    bool exist(int y) {
        if (isEmpty()) {
            return false;
        }
        else {
            // search
            AsideNode* temp = tail;
            while (temp != NULL) {
                if (temp->y == y) {
                    return true;
                }
                temp = temp->next;
            }
            return false;
        }
    }

    AsideNode* find(int y) {
        if (exist(y)) {
            AsideNode* temp = tail;
            while (temp->y != y) {
                temp = temp->next;
            }
            return temp;
        }
        return new AsideNode(-1);
    }
};
