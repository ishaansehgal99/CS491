#include <iostream>
#include <list>
#include <iterator>

using namespace std;


int main() {
    string input;
    while (getline(cin, input)) {
        list<char> l;
        auto it = l.begin();

        for (char i : input) {
            if (i == '[') {
                it = l.begin();
            } else if (i == ']') {
                it = l.end();
            } else {
                l.insert(it, i);
            }
        }

        for (it = l.begin(); it != l.end(); it++) {
            cout << *it;
        }
        cout << endl;
    }
    return 0;
}