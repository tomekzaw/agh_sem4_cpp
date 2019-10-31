#ifndef NODE_H
#define NODE_H

#include <iostream>

template<typename T>
class List;

template<typename T>
class Node;

template<typename T>
std::ostream& operator<<(std::ostream&, const Node<T>&);

template<typename T>
std::ostream& operator<<(std::ostream&, const List<T>&);

template<typename T>
class Node
{
	T data;
	Node<T>* next;
    friend class List<T>;
    Node<T>(const Node<T>&) = delete;
    Node<T>& operator=(const Node<T>&) = delete;
public:
	Node(T _data) : data(_data), next(NULL) {}
    friend std::ostream& operator<< <T>(std::ostream&, const Node<T>&);
    friend std::ostream& operator<< <T>(std::ostream&, const List<T>&);
/*
private:
    Node<T>(const Node<T>&);
    Node<T>& operator=(const Node<T>&);
*/
};

template<typename T>
std::ostream& operator<<( std::ostream& o, const Node<T>& node) {
    std::cout << node.data << " ";
    return o;
}

#endif // NODE_H