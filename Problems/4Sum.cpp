#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > sum4(vector<int> A, int B) {
    vector<vector<int> > result;
    sort(A.begin(), A.end());
    for(int i = 0; i < A.size(); i++) {
        for(int j = i + 1; j < A.size(); j++) {
            int left = j + 1;
            int right = A.size() - 1;
            int target = B - (A[i] + A[j]);

            while(left < right) {
                if(A[left] + A[right] < target) {
                    left++;
                }

                else if(A[left] + A[right] > target) {
                    right--;
                }

                else {
                    vector<int> temp;
                    temp.push_back(A[i]);
                    temp.push_back(A[j]);
                    temp.push_back(A[left]);
                    temp.push_back(A[right]);
                    result.push_back(temp);

                    while(left < right && A[left] == temp[2]) {
                        left++;
                    }

                    while(left < right && A[right] == temp[3]) {
                        right--;
                    }
                }
            }

            while(j + 1 < A.size() && A[j + 1] == A[j]) {
                j++;
            }
        }

        while(i + 1 < A.size() && A[i + 1] == A[i]) {
            i++;
        }
    }

    return result;
}

int main() {
    vector<int> a;
    vector<vector<int> > result;
    a.push_back(1);
    a.push_back(0);
    a.push_back(-1);
    a.push_back(0);
    a.push_back(-2);
    a.push_back(2);

    int sum = 0;
    result = sum4(a, sum);

    for(int i = 0; i < result.size(); i++) {
        for(int j = 0; j < result[0].size(); j++) {
            cout << result[i][j] << "\t";
        }
        cout << "\n";
    }

    return 0;
}