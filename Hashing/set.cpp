#include <iostream>
#include <set>

using namespace std;

int main() {
    set<int> s;
    set<int>::iterator itr;
    int a[] = {10, 40, 30, 20, 60};

    for(int i = 0; i < 5; i++) {
        s.insert(a[i]);
    }

    for(itr = s.begin(); itr != s.end(); itr++) {
        cout << *itr << '\n';
    }

    // find value in set
    if(s.find(40) != s.end()) {
        cout << "40 is present\n";
    }
    else {
        cout << "40 is not present\n";
    }

    cout << s.size() << "\n";
    cout << s.empty() << "\n";

    
    return 0;
}