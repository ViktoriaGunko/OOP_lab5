#include "clist.h"

CList::CList() : head(nullptr), tail(nullptr) {}

CList::~CList() {
    while (!isEmpty()) {
        popBegin();
    }
}

CList::CList(const CList& other) : head(nullptr), tail(nullptr) {
    Node* current = other.head;
    while (current) {
        insertEnd(current->data);
        current = current->next;
    }
}

CList& CList::operator=(const CList& other) {
    if (this == &other) {
        return *this;
    }

    while (!isEmpty()) {
        popBegin();
    }

    Node* current = other.head;
    while (current) {
        insertEnd(current->data);
        current = current->next;
    }

    return *this;
}

void CList::insertBegin(int value) {
    Node* newNode = new Node{ value, nullptr, head };
    if (head) {
        head->prev = newNode;
    }
    else {
        tail = newNode;
    }
    head = newNode;
}

void CList::insertEnd(int value) {
    Node* newNode = new Node{ value, tail, nullptr };
    if (tail) {
        tail->next = newNode;
    }
    else {
        head = newNode;
    }
    tail = newNode;
}

bool CList::insertAfter(int afterValue, int value) {
    Node* current = head;
    while (current && current->data != afterValue) {
        current = current->next;
    }

    if (current) {
        Node* newNode = new Node{ value, current, current->next };
        if (current->next) {
            current->next->prev = newNode;
        }
        else {
            tail = newNode;
        }
        current->next = newNode;
        return true;
    }

    return false;
}

int CList::popBegin() {
    if (!head) {
        return -1; // List is empty
    }

    int value = head->data;
    Node* temp = head;
    head = head->next;
    if (head) {
        head->prev = nullptr;
    }
    else {
        tail = nullptr;
    }

    delete temp;
    return value;
}

int CList::popEnd() {
    if (!tail) {
        return -1; // List is empty
    }

    int value = tail->data;
    Node* temp = tail;
    tail = tail->prev;
    if (tail) {
        tail->next = nullptr;
    }
    else {
        head = nullptr;
    }
    delete temp;
    return value;
}

bool CList::deleteElem(int value) {
    Node* current = head;
    while (current && current->data != value) {
        current = current->next;
    }
    if (current) {
        if (current->prev) {
            current->prev->next = current->next;
        }
        else {
            head = current->next;
        }

        if (current->next) {
            current->next->prev = current->prev;
        }
        else {
            tail = current->prev;
        }

        delete current;
        return true;
    }

    return false;
}

bool CList::isEmpty() const {
    return head == nullptr;
}

void CList::sort() {
    if (isEmpty()) {
        return;
    }
    for (Node* i = head; i != nullptr; i = i->next) {
        for (Node* j = i->next; j != nullptr; j = j->next) {
            if (i->data > j->data) {
                std::swap(i->data, j->data);
            }
        }
    }
}

void CList::show(bool reverse) const {
    if (reverse) {
        Node* current = tail;
        while (current) {
            std::cout << current->data << " ";
            current = current->prev;
        }
    }
    else {
        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
    }
    std::cout << std::endl;
}
