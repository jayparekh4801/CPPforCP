// { Driver Code Starts
// #include <bits/stdc++.h> 
#include <iostream>
#include <vector>
using namespace std; 

 // } Driver Code Ends



class Solution
{   
    public:
    //Function to add two matrices.
    vector<vector<int> > sumMatrix( const vector<vector<int> >& A, const vector<vector<int> >& B)
    {
        // code here
        vector<vector <int> > result;
        
        int temp;
        
        if(A.size() != B.size()) {
            return result;
        }
        
        else {
            for(int i = 0; i < A.size(); i++) {
                if(A[i].size() != B[i].size()) {
                    break;
                }
                else {
                    vector<int> tempv;
                    for(int j = 0; j < A[i].size(); j++) {
                        temp = A[i][j] + B[i][j];
                        tempv.push_back(temp);
                    }
                    result.push_back(tempv);
                }
                
            }
        }
        
        return result;
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int row, col;
        cin>> row>> col;
        vector<vector<int> > A(row); 
        for(int i=0; i<row; i++)
        {
            A[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>A[i][j];
            }
        }
        cin>> row>> col;
        vector<vector<int> > B(row);
        for(int i=0; i<row; i++)
        {
            B[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>B[i][j];
            }
        }
        Solution ob;
        vector<vector<int> > result = ob.sumMatrix(A,B);
        if(result.size() == 0)
            cout<<"-1";
        else
        {
            for (int i = 0; i < result.size(); ++i)
            {
                for (int j = 0; j < result[0].size(); ++j)
                {
                    cout<<result[i][j]<<" ";
                }
            }
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends