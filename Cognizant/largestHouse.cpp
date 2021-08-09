#include <iostream>
#include <sstream>
#include <vector>

using namespace std ;

pair<int, int> findMaxPlot(int hn[], int hp[], int n) {
    vector<pair<int, int> > houses;
    
    pair <int, int> result;
    int dif = 0;
    int cdif = 0;

    for(int i = 0; i < n; i++) {
        houses.push_back(make_pair(hn[i], hp[i]));
    }

    for(int i = 0; i < n - 1; i++) {
        cdif = abs(houses[i].second - houses[i + 1].second);
        if(cdif > dif) {
            if(houses[i].first > houses[i + 1].first) {
                result.first = houses[i + 1].first;
                result.second = houses[i].first;
            }

            else {
                result.first = houses[i].first;
                result.second = houses[i + 1].first;
            }
        }
    }

    return result;
}

int main() {
    int n;
    cin >> n;
    int hn[n];
    int hp[n];

    for(int i = 0; i < n; i++) {
        cin >> hn[i];
        cin >> hp[i];
    }

    pair <int , int> result = findMaxPlot(hn, hp, n);
    cout << result.first << " " << result.second;
    return 0;
}