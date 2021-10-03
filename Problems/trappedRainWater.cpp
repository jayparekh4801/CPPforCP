#include <iostream>
#include <vector>

using namespace std;

int trappedWater(vector<int> A) {
    int premax = INT_MIN;
    int sufmax = INT_MIN;
    vector<int> prefixmax;
    vector<int> suffixmax;
    int result = 0;

    for(int i = 0; i < A.size(); i++) {
        if(A[i] > premax) {
            premax = A[i];
        }
        prefixmax.push_back(premax);
    }

    for(int i = A.size() - 1; i >= 0; i--) {
        if(A[i] > sufmax) {
            sufmax = A[i];
        }
        suffixmax.push_back(sufmax);
    }
    reverse(suffixmax.begin(), suffixmax.end());

    for(int i = 0; i < A.size(); i++) {
        int unit = min(prefixmax[i], suffixmax[i]) - A[i];
        result += unit;
    }

    return result;
}

int main() {
    vector<int> a;
    a.push_back(0);
    a.push_back(1);
    a.push_back(0);
    a.push_back(2);
    a.push_back(1);
    a.push_back(0);
    a.push_back(1);
    a.push_back(3);
    a.push_back(2);
    a.push_back(1);
    a.push_back(2);
    a.push_back(1);

    int result = trappedWater(a);
    cout << result;

    return 0;
}