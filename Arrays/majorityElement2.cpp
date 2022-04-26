#include <iostream>
#include <vector>

using namespace std;

vector<int>  majorityElement(int a[], int n) {
    vector<int> result;
    int result1 = INT_MIN;
    int result2 = INT_MIN;
    int count1 = 0;
    int count2 = 0;

    for(int i = 0; i < n; i++) {
        if(result1 == a[i]) {
            count1++;
        }

        else if(result2 == a[i]) {
            count2++;
        }

        else if(count1 == 0) {
            result1 = a[i];
            count1++;
        }

        else if(count2 == 0) {
            result2 = a[i];
            count2++;
        }
        else {
            count1--;
            count2--;
        }
    }

    count1 = count2 = 0;
        
        for(int i = 0; i < n; i++) {
            if(a[i] == result1) count1++;
            if(a[i] == result2) count2++;
        }


    if(count1 > n / 3) {
            result.push_back(result1);    
        }
        
    if( count2 > n / 3) {
        result.push_back(result2);            
    }
    

    return result;
}

int main() {
    int n;
    cin >> n;
    int a[n];

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> result = majorityElement(a, n);

    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << "\n";
    }

    return 0;
}