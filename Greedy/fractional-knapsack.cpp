#include <iostream>
#include <vector>

using namespace std;

bool sortByRatio(pair<int, int> a, pair<int, int> b) {
    double r1 = (double)a.first / (double)a.second;
    double r2 = (double)b.first / (double)b.second;

    return (r1 > r2);
}

int findMaxValue(int values[], int weights[], int n, int w) {
    vector<pair<int, int> > items;
    int currw = 0;
    double ans = 0.0;

    for(int i = 0; i < n; i++) {
        items.push_back(make_pair(values[i], weights[i]));
    }

    sort(items.begin(), items.end(), sortByRatio);

    for(int i = 0; i < items.size(); i++) {
        if(items[i].second + currw <= w) {
            ans = ans + items[i].first;
            currw = currw + items[i].second;
        }
        else {
            int remain = w - currw;
            ans = ans + (remain * ((double)items[i].first / (double)items[i].second));
            break;
        }
    }

    return ans;
}

int main() {
    int values[] = {100, 60, 120};
    int weights[] = {20, 10 ,30};
    int maxValue = findMaxValue(values, weights, 3, 50);
    cout << maxValue;
    return 0;
}