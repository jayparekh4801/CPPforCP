// { Driver Code Starts
// #include<bits/stdc++.h>
#include <iostream>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(int arr[], int n){
        
        // Your code here
        int sum_till = 0, max_sum = INT_MIN ;
        
        for(int i = 0; i < n; i++) {
            sum_till += arr[i];
            if(sum_till > max_sum) {
                max_sum = sum_till;
            }
            
            if(sum_till < 0) {
                sum_till = 0;
            }
            
        }
        
        return max_sum;
    }
};

// { Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}
  // } Driver Code Ends