#include <iostream>

using namespace std;

int consecutiveOnes(int N) {
    int len = 0;
        int maxLen = INT_MIN;
        bool sw = false;
        
        while(N / 2 != 0) {
            if(N % 2 == 0) {
                sw = false;
                maxLen = max(len, maxLen);
            }
            
            if(sw) {
                len++;
            }
            
            else if(N % 2 == 1) {
                len = 1;
                sw = true;
            }
            
            N = N / 2;
        }
        
        if(N % 2 == 1 && sw) {
            len++;
        }
        maxLen = max(len, maxLen);
        
        return maxLen;
}

int main() {
    int n = 222;
    int result = consecutiveOnes(n);
    cout << result;
    return 0;
}