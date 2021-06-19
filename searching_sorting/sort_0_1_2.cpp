// { Driver Code Starts
// #include<bits/stdc++.h>
#include <iostream>
using namespace std;



 // } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        // coode here 
        int eles[3] = {0};
        int er = 0;
        for(int i = 0; i < n; i++) {
            eles[a[i]]++;
        }
        
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < eles[j]; k++) {
                a[er] = j;
                er++;
            }
        }
        
    }
    
};

// { Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}

  // } Driver Code Ends