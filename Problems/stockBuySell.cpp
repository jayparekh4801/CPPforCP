#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > stocks(vector<int> A, int n) {
    int l = 0;
    vector<vector<int> > result;
    int i = 1;
    while(i < n) {
       while(A[i] >= A[i - 1] && i < n) {
           i++;
       }
       vector<int> temp;
       temp.push_back(l);
       temp.push_back(i - 1);
       result.push_back(temp);
       l = i;
       i++;
    }
    
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> a;

    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        a.push_back(temp);
    }

    vector<vector<int> > result = stocks(a, n);

    for(int i = 0; i < result.size(); i++) {
        cout << result[i][0] << " " << result[i][1] << "\n";
    }

    return 0;
}