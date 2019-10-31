#ifndef LIST_H
#define LIST_H

#include <iostream>

#include "Node.h"
#include "EmptyListException.h"

template<typename T>
class List;

template<typename T>
std::ostream& operator<<(std::ostream&, const List<T>&);

template<typename T>
class List
{
	Node<T>* head;
public:
	List() : head(nullptr) {}
    List<T>(const List<T>&) = delete;
    List<T>& operator=(const List<T>&) = delete;
	void insert(T val);
	T remove();    
    friend std::ostream& operator<< <T>(std::ostream&, const List<T>&);
/*
private:
    List<T>(const List<T>&);
    List<T>& operator=(const List<T>&);
*/
};

template<typename T>
void List<T>::insert(T val) {
    Node<T>* inserted = new Node(val);
    if (head == nullptr) {
        head = inserted;
    } else {
        Node<T>* tail = head;
        while (tail->next) {
            tail = tail->next;
        }
        tail->next = inserted;
    }
}

template<class T>
T List<T>::remove() {
	if (head == nullptr) {
		throw EmptyListException();
	}
    Node<T>* removed = head;
    head = head->next;
    return removed->data;
}

template<typename T>
std::ostream& operator<<( std::ostream& o, const List<T>& list) {
    (void) list;
    o << "list: ";        
    if (list.head == nullptr) {
        o << "empty";
    } else {
        o << "[ ";
        Node<T>* node = list.head;
        while (node) {
            o << *node;
            node = node->next;
        }
        o << "]";
    }
    o << std::endl;
    return o;
}

#endif // LIST_H