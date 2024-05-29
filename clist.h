#ifndef CLIST_H
#define CLIST_H

#include <iostream>

class Node {
public:
    int data;
    Node* prev;
    Node* next;
};

class CList {
private:
    Node* head;
    Node* tail;
public:
    CList();
    ~CList();
    CList(const CList& other);
    CList& operator=(const CList& other);
    void insertBegin(int value);
    void insertEnd(int value);
    bool insertAfter(int afterValue, int value);
    int popBegin();
    int popEnd();
    bool deleteElem(int value);
    bool isEmpty() const;
    void sort();
    void show(bool reverse = false) const;
};

#endif // CLIST_H