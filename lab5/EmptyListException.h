#ifndef EMPTY_LIST_EXCEPTION_H
#define EMPTY_LIST_EXCEPTION_H

#include <exception>

class EmptyListException : public std::exception {
public:
    virtual const char* what() const noexcept {
        return "List is empty";
    }
};

#endif // EMPTY_LIST_EXCEPTION_H