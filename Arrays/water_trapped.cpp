// { Driver Code Starts
// #include<bits/stdc++.h>
#include <iostream>

using namespace std;


 // } Driver Code Ends

class Solution{

    // Function to find the trapped water between the blocks.
    public:
    int trappingWater(int arr[], int n) {
        // Code here
        int left[n];
        int right[n];
        int water_trapped = 0;
        int max = INT_MIN;
        for(int i = 0; i < n; i++) {
            if(arr[i] > max) {
                max = arr[i];
            }
            left[i] = max;
        }
        
        max = INT_MIN;
        for(int i = n - 1; i >= 0; i--) {
            if(arr[i] > max) {
                max = arr[i];
            }
            right[i] = max;
        }
        
        for(int i = 0; i < n; i++) {
            water_trapped += min(left[i], right[i]) - arr[i];
        }
        
        return water_trapped;
        
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends