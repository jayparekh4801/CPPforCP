#include <iostream>

using namespace std;

void printArray(int a[], int n) {
    for(int i = 1; i < n - 1; i++) {
        cout << a[i];
    }
}

void findState(int houses[], int h,int d) {
    int temp[10] = {0};
    for(int i = 0; i < d; i++) {
        for(int j = 1; j < h - 1; j++) {
            if(houses[j - 1] == houses[j + 1]) {
                temp[j] = 0;
            }
            else {
                temp[j] = houses[j];
            }
        }
        for(int j = 1; j < h - 1; j++) {
                houses[j] = temp[j];
        }
    }

    printArray(houses, h);
}

int main() {
    int h = 10;
    int housesState[10] = {0};
    int d;
    for(int i = 1; i < 9; i++) {
        cin >> housesState[i];
    }
    printArray(housesState, h);
    cin >> d;
    findState(housesState, h, d);
    return 0;
}