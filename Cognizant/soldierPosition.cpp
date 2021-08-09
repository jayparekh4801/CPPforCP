#include <iostream>
#include <vector>

using namespace std;

int findSoldier(int sol[], vector<pair <int, int> > ac, int k, int n, int a) {

    for(int i = 0; i < a; i++) {
        int l = ac[i].first - 1;
        int r = ac[i].second - 1;
        int temp;

        while(l < r) {
            temp = sol[l];
            sol[l] = sol[r];
            sol[r] = temp;
            l++;
            r--;
        }
    }
    return sol[k - 1];

}

int main() {
    int n, a, k;
    cin >> n;
    cin >> a;
    cin >> k;
    vector<pair<int, int> > ac;
    for(int i = 0; i < a; i++) {
        int s, e;
        cin >> s;
        cin >> e;
        ac.push_back(make_pair(s, e));
    }

    int sol[n];

    for(int i = 0; i < n; i++) {
        sol[i] = i + 1;
    }

    int result = findSoldier(sol, ac, k, n, a);
    cout << result;

    return 0;
}