#include <iostream>
#include <map>

using namespace std;

int main() {

    map<int, string> m;
    map<int, string> :: iterator itr;
    pair<int, string> p;
    string names[] = {"vyom", "nisarg", "heema", "mansi", "hem", "jay", "ishika"};

    for(int i = 0; i < 7; i++) {
        p.first = i;
        p.second = names[i];
        m.insert(p);
    }

    for(itr = m.begin(); itr != m.end(); itr++) {
        cout << itr -> first << " " << itr -> second << "\n"; 
    }
    return 0;
}