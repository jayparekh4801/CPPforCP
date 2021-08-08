#include <iostream>
#include <vector>

using namespace std;

bool bysec(const pair<int, int> &a, const pair<int, int> &b) {
    int t1 = a.second;
    int t2 = b.second;

    return (t1 < t2);
}

int findMaximumActivities(int s[], int f[], int n) {
    vector<pair<int, int> > timings;

    for(int i = 0; i < n; i++) {
        timings.push_back(make_pair(s[i], f[i]));
    }

    sort(timings.begin(), timings.end(), bysec);

    int ans = 1;
    int last = 0;

    for(int j = 1; j < timings.size(); j++) {
        if(timings[j].first >= timings[last].second) {
            last = j;
            ans++;
        }
    }
    return ans;
}

int main() {
    int s[] = {1, 3, 0, 5, 8, 5};
    int f[] = {2, 4, 6, 7, 9, 9};
    int nm = findMaximumActivities(s, f, 6); 
    cout << nm;
    return 0;
}