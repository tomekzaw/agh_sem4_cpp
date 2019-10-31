#include <iostream>
#include <cstring>
#include "TreeBST.h"

using namespace std;

template<class T>
bool rowne(T a, T b, T c) {
    return (a == b) && (b == c);
}

template<>
bool rowne<const char *>(const char *a, const char *b, const char *c) {
    return (strcmp(a, b) == 0) && (strcmp(b, c) == 0);
}

int main() {
    /*
    cout << rowne(1, 2, 3) << endl;
    cout << rowne(1, 1, 3) << endl;
    cout << rowne(1, 3, 3) << endl;
    cout << rowne(3, 3, 3) << endl;
    */

    /*
    cout << rowne("abcdef", "123456", "ABCDEF") << endl;
    cout << rowne("abcdef", "abcdef", "ABCDEF") << endl;
    cout << rowne("abcdef", "ABCDEF", "ABCDEF") << endl;
    cout << rowne("abcdef", "abcdef", "abcdef") << endl;
    */

    /*
    cout << rowne((void *) "abcdef", (void *) "abcdef", (void *) "abcdef") << endl;
    */

    /*
    const char *str1 = "abcdef";
    const char *str2 = (string("abc") + string("def")).c_str();
    cout << rowne((void *) str1, (void *) str2, (void *) str2) << endl;
    cout << rowne(str1, str2, str2) << endl;
    */

    TreeBST<int> bst;
    bst.insert(5);
    try {
        bst.insert(5);
    } catch (const NodeAlreadyExistsException& e) {
        cout << e.what() << endl;
    }
    bst.insert(3);
    bst.insert(7);
    bst.insert(4);
    bst.insert(6);
    bst.insert(8);
    bst.insert(2);

    bst.print();

    return 0;
}