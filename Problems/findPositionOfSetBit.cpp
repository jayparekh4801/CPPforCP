// Problem Statement :- Given a number N having only one ‘1’ and all other ’0’s in its binary representation, 
// find position of the only set bit. 
// If there are 0 or more than 1 set bit the answer should be -1. 
// Position of  set bit '1' should be counted starting with 1 from LSB side in binary representation of the number

#include <iostream>

using namespace std;

int findPosition(int N) {
    int pos = 0;
    int ones = 0;
    int result = -1;

    while (N >= 1) {
        if (ones > 1) {
            result = -1;
            break;
        }

        if (N % 2 == 1) {
            result = pos + 1;
            ones++;
        }
        pos++;
        N /= 2;
    }

    if (ones > 1)
        result = -1;

    return result;
}

int main()
{
    int n;
    cin >> n;
    int result = findPosition(n);
    cout << result;
    return 0;
}