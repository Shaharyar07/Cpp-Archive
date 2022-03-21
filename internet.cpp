
#include <deque>
#include <iostream>
#include <string>

using namespace std;

bool palchecker(string aString) {
    deque<char> chardeque;
    int strLen = aString.length();
    for (int i = 0; i < strLen; i++) {
        
        chardeque.push_back(aString[i]);
    }

    bool stillEqual = true;

    while (chardeque.size() > 1 && stillEqual) {
        char first = chardeque.front();
        chardeque.pop_front();
        char last = chardeque.back();
        chardeque.pop_back();
        if (first != last) { 
            stillEqual = false;
        }
    }
    return stillEqual;
}

int main() {
    cout << palchecker("lsdkjfskf") << endl;
    cout << palchecker("radar") << endl;
    cout << palchecker("civic") << endl;
    
}

