#include <iostream>

using namespace std;



bool isSubsetsum(int a[], int n, int s) {
    bool t[n + 1][s + 1];
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < s; j++) {
            if(i == 0) {
                t[i][j] = false;
            }
            if(j == 0) {
                t[i][j] = true;
            }
        }
    }

   for(int i = 1; i < n + 1; i++) {
       for(int j = 1; j < s + 1; j++) {
           if(a[i - 1] <= j) {
               t[i][j] = t[i - 1][j - a[i - 1]] || t[i - 1][j];
           }
           else {
               t[i][j] = t[i - 1][j];
           }
       }
   }

   return t[n][s];
}

int main() {
    int a[] = {2, 3, 7, 8, 10};
    int s = 11;
    int result = isSubsetsum(a, 5, s);

    if(result) {
        cout << "YES";
    }   
    else {
        cout << "NO";
    }
    return 0;
}