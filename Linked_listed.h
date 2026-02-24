//
// Created by mahmo on 24/02/2026.
//

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

template<class T>
class linked_list {
    struct Node {
        T val;
        Node * next;
        Node *prev;
    };
    Node * first;
    Node * last;

public:
    linked_list() : first(nullptr) , last(nullptr){};
    bool empty() {
        return first  == nullptr or last == nullptr;
    }
    void push_back(T x) {
        Node * tmp =new  Node;
        tmp ->val = x;
        tmp->next = nullptr;
        tmp->prev= nullptr;
        if (empty()) {
            first = last = tmp;

        }
        else {
            tmp->prev = last;
            last->next = tmp;
            last = tmp;
        }
    }
    void push_front( T x) {
        Node * tmp =new  Node;
        tmp ->val = x;
        tmp->next = nullptr;
        tmp->prev= nullptr;
        if (empty()) {
            first = last = tmp;
        }
        tmp->next = first;
        first = tmp;
    }
    void pop_back() {
        Node * tmp = last;
        last = last-> prev;
        delete tmp;
    }
    void pop_front() {
        Node * tmp = first;
        first = first-> next;
        delete tmp;
    }
    int front () {
        return first->val;
    }
    int rear() {
        return last->val;
    }
    ~linked_list() {
        while (!empty()) {
            pop_back();
        }
    }

};


#endif //LINKED_LIST_H
