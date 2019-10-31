#include <iostream>
#include <cstring>

#include "List.h"

using namespace std;

template<typename T>
T max(T a, T b, T c) {
    if (a >= b && a >= c) return a;
    if (b >= c) return b;
    return c;
}

template<>
const char *max<const char *>(const char *a, const char *b, const char *c) {
    if (strcmp(a, b) >= 0 && strcmp(a, c) >= 0) return a;
    if (strcmp(b, c) >= 0) return b;
    return c;
}

int main() {
    /*
    cout << max(1, 2, 3) << endl;
    cout << max(1, 3, 2) << endl;
    cout << max(2, 1, 3) << endl;
    cout << max(2, 3, 1) << endl;
    cout << max(3, 1, 2) << endl;
    cout << max(3, 2, 1) << endl;

    cout << max("a", "b", "c") << endl;
    cout << max("c", "b", "a") << endl;

    cout << max("aaa", "abb", "abc") << endl;
    cout << max("aaa", "abc", "abb") << endl;
    cout << max("abb", "aaa", "abc") << endl;
    cout << max("abb", "abc", "aaa") << endl;
    cout << max("abc", "abb", "aaa") << endl;
    cout << max("abc", "aaa", "abb") << endl;
    */

    List<int> list;
    cout << list;

    try {
        list.remove();
    } catch (const EmptyListException& e) {        
        cout << "Exception: " << e.what() << endl;
    }

    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    cout << list;

    list.remove();
    cout << list;

    list.insert(5);
    cout << list;

    list.remove();
    list.remove();
    list.remove();
    cout << list;

    list.insert(6);
    list.insert(7);
    cout << list;

    return 0;
}