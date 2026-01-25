//
// Created by mahmo on 23/01/2026.
//
#include  <bits/stdc++.h>
using namespace  std;
#ifndef STACK_H
#define STACK_H
template <class T>
class Stack {
    struct Node {
        T value;
        Node* next;
    };
    Node* Top;
    public:
    Stack() {
        Top = nullptr;
    }
void push (T val) {
        Node* Newnode = new Node;
        Newnode -> value = val;
        Newnode -> next = Top;
        Top = Newnode;
    }
    void pop() {
        if (isEmpty()) throw runtime_error("Stack is empty");
        Node* temp = Top;
        Top = Top-> next;
        delete temp;
    }
    T top() {
        if (isEmpty()) throw runtime_error("Stack is empty");
        return Top->value;
    }
    bool isEmpty() {
        return Top == nullptr;
    }
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

};
#endif //STACK_H
