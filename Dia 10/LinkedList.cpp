#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* first;

public:
    LinkedList() : first(nullptr) {}
    LinkedList(int A[], int n);
    ~LinkedList();

    void Display();
    void Insert(int index, int x);
    int Delete(int index);
    int Length();
};

LinkedList::LinkedList(int A[], int n) {
    if (n <= 0) {
        first = nullptr;
        return;
    }

    first = new Node;
    first->data = A[0];
    first->next = nullptr;
    
    Node* last = first;

    for (int i = 1; i < n; i++) {
        Node* t = new Node;
        t->data = A[i];
        t->next = nullptr;
        last->next = t;
        last = t;
    }
}

LinkedList::~LinkedList() {
    Node* p = first;
    while (first) {
        first = first->next;
        delete p;
        p = first;
    }
}

void LinkedList::Display() {
    Node* p = first;
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int LinkedList::Length() {
    Node* p = first;
    int len = 0;
    while (p) {
        len++;
        p = p->next;
    }
    return len;
}

void LinkedList::Insert(int index, int x) {
    if (index < 0 || index > Length()) {
        return;
    }

    Node* t = new Node;
    t->data = x;
    t->next = nullptr;

    if (index == 0) {
        t->next = first;
        first = t;
    } else {
        Node* p = first;
        for (int i = 0; i < index - 1; i++) {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

int LinkedList::Delete(int index) {
    if (index < 1 || index > Length()) {
        return -1;
    }

    Node* p;
    int x = -1;

    if (index == 1) {
        p = first;
        first = first->next;
        x = p->data;
        delete p;
    } else {
        p = first;
        Node* q = nullptr;
        for (int i = 0; i < index - 1; i++) {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;
    }
    return x;
}

int main() {
    int A[] = {1, 2, 3, 4, 5};
    LinkedList l(A, 5);
    l.Insert(5, 6);
    cout << l.Delete(3) << endl; //deletando o 3 elemento e mostrando no display com cout qual elemento está sendo exlcuido
    l.Delete(1);
    cout << "Length: " << l.Length() << endl; //mostrando o comprimento da lista
    l.Display();

    return 0;
}
// se eu sempre der delete(1) ele vai deletando todos os elementos da lista na primeira posição (4 são necessários para acabar com a lista)