// { Driver Code Starts
//Initial template for C++

// #include <bits/stdc++.h>
#include <iostream>
using namespace std;


 // } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find the median of the two arrays when they get merged.
    int findMedian(int arr[], int n, int brr[], int m)
    {
        // code here
        int i, j;
        for(i = 0, j = 0; i < n;) {
            if(arr[i] <= brr[j]) {
                i++;
            }
            else {
                swap(arr[i], brr[j]);
                i++;
                j++;
            }
        }
        for(int i = 0; i < n; i++) {
            cout << arr[i];
        }
        for(int i = 0; i < m; i++) {
            cout << brr[i];
        }
        int tot = n + m;
        int mid, midean;
        if(tot % 2 == 0) {
            mid = (tot - 1) / 2;
            
            if(mid < (n - 1)) {
                midean = (arr[mid] + arr[mid + 1]) / 2;
            }
            
            else if(mid > (n - 1)) {
                midean = (brr[mid - n] + brr[(mid - n) + 1]) / 2;
            }
            
            else {
                midean = (arr[mid] + brr[0]) / 2;
            }
        }
        
        else {
            mid = (tot - 1) / 2;
            
            if(mid <= (n - 1)) {
                midean = arr[mid];
            }
            
            else {
                midean = brr[mid - (n)];
            }
        }
        
        return midean;
    }
};

// { Driver Code Starts.

int main() {
	int t;
	cin >> t;
	
	while(t--){
	    int n, m;
	    cin >> n >> m;
	    int arr[n];
	    int brr[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> brr[i];
	    }
	    Solution obj;
	    if(n < m)
	        cout << obj.findMedian(arr, n, brr, m) << endl;
	   else
	        cout << obj.findMedian(brr, m, arr, n) << endl;
	    
	}

}  // } Driver Code Ends