#include <iostream>
#include <vector>

using namespace std;
struct Job {
    char id;
    int dead;
    int profit;
};

bool sortJobs(Job a, Job b) {
    return (a.profit > b.profit);
}

int findMaxDead(Job arr[], int n) {
    int result = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i].dead > result) {
            result = arr[i].dead;
        }
    }
    return result;
}

void findJobSequence(Job arr[], int n) {
    sort(arr, arr + n, sortJobs);
    int maxdead = findMaxDead(arr, n);
    char sequence[maxdead + 1];

    for(int i = 0; i <= maxdead; i++) {
        sequence[i] = '0';
    }

    for(int i = 0; i < n; i++) {
        if(sequence[arr[i].dead] == '0') {
            sequence[arr[i].dead] = arr[i].id;
        }

        else {
            int temp = arr[i].dead;
            while(sequence[temp] != '0') {
                temp = temp - 1;
            }

            if(temp != 0) {
                sequence[temp] = arr[i].id;                
            }

        }
    }

    for(int i = 0;i <= maxdead; i++) {
        if(sequence[i] != '0') {
            cout << sequence[i] << "\t";
        }
    }

}


int main() {
    Job arr[] = { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27},
                {'d', 1, 25}, {'e', 3, 15}};
   findJobSequence(arr, 5);
    return 0;
}