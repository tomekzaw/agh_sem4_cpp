#ifndef NODEBST_H
#define NODEBST_H

#include <iostream>

using namespace std;

class NodeAlreadyExistsException : public std::exception {
public:
    virtual const char* what() const noexcept {
        return "Node already exists";
    }
};

template<class T>
class NodeBST
{
	T data;
	NodeBST<T>* left;
	NodeBST<T>* right;
public:
	NodeBST(T _data) : data(_data), left(NULL), right(NULL) {}
	bool contains(T val) const;
	bool insert(T val);
	void print() const;
};

template<class T>
bool NodeBST<T>::contains(T val) const {
	if (val == data) return true;
	NodeBST<T>* next = (val < data) ? left : right;
	return (next != NULL) ? next->contains(val) : false;
}

template<class T>
bool NodeBST<T>::insert(T val) {
	if (val == data) {
        throw NodeAlreadyExistsException();
    }
	NodeBST<T>* & next = (val < data) ? left : right;
	if (next == NULL) {
		next = new NodeBST(val);
		return true;
	}
	else return next->insert(val);
}

template<class T>
void NodeBST<T>::print() const {
	if (left != NULL) left->print();
	cout << data << " ";
	if (right != NULL) right->print();
}

#endif // NODEBST_H