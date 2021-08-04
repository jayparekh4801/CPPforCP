#include <iostream>

using namespace std;

int findStepsToReach1(int n) {
    if(n == 1) {
        return 0;
    }
    int count = 0;

    while(n != 1) {
        if(n % 2 == 0) {
            n = n / 2;
            count++;
        }

        else {
            n = (3 * n) + 1;
        }
    }

    return count;
}


int main() {
    int n;
    cout << "enter number to find steps to reach 1\n";
    cin >> n;
    int steps;

    steps = findStepsToReach1(n);
    cout << steps;
    return 0;
}