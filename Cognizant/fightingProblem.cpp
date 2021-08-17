#include<iostream>
#include <set>

using namespace std;

int findMaxOnTrip(int n, int p, int a[][2]) {
    set<int> s1, s2;
    for(int i = 0; i < p; i++) {
        if(s1.find(a[i][0]) != s1.end()) {
            if(s2.find(a[i][1]) != s2.end()) {
                continue;
            }

            else {
                s2.insert(a[i][1]);
            }
        }

        else if(s2.find(a[i][0]) != s2.end()) {
            if(s1.find(a[i][1]) != s1.end()) {
                continue;
            }
            else {
                s1.insert(a[i][1]);
            }
        }

        else {
            if(s1.find(a[i][1]) != s1.end()) {
                s2.insert(a[i][0]);
            }
            else if(s2.find(a[i][1]) != s2.end()) {
                s1.insert(a[i][0]);
            }
            else {
                s1.insert(a[i][0]);
                s2.insert(a[i][1]);
            }
        }
    }

    if(s1.size() <= s2.size()) {
        return s2.size();
    }
    else {
        return s1.size();
    }
    
}

int main() {
    int n, p;
    cin >> n;
    cin >> p;

    int a[p][2];
    for(int i = 0;  i< p; i++) {
        cin >> a[i][0];
        cin >> a[i][1];
    }
    int result = findMaxOnTrip(n, p, a);
    cout << result;
    return 0;
}