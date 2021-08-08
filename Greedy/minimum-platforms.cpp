#include <iostream>
#include <vector>


using namespace std;

int findNoOfPlatforms(int a[], int d[], int n) {
    vector<pair<int , char> > timings;

    for(int i = 0; i < n; i++) {
        timings.push_back(make_pair(a[i], 'a'));
        timings.push_back(make_pair(d[i], 'd'));
    }

    sort(timings.begin(), timings.end());
    int ans = 0;
    int current = 0;
    for(int i = 0; i < timings.size(); i++) {
        if(timings[i].second == 'a') {
            current++;
        }

        else {
            current--;
        }

        if(current > ans) {
            ans = current;
        }
    }

    return ans;
}

int main() {
    int a[] = {900, 940, 950, 1100, 1500, 1800};
    int d[] = {910, 1200, 1120, 1130, 1900, 2000};
    int platforms = findNoOfPlatforms(a, d, 6);
    cout << platforms;
    return 0;
}