#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > Sum3(vector<int> A) {
    vector<vector<int> > result;
    sort(A.begin(), A.end());
    for(int i = 0; i < A.size(); i++) {
        int left = i + 1;
        int right = A.size() - 1;
        int target =  0 - A[i];
        while(left < right) {
            int sum = A[left] + A[right];
            if(sum < target) {
                left++;
            }
            else if(sum > target) {
                right--;
            }
            else {
                vector<int> temp;
                temp.push_back(A[i]);
                temp.push_back(A[left]);
                temp.push_back(A[right]);
                result.push_back(temp);

                while(left < right && A[left] == temp[1]) {
                    left++;
                }

                while(left < right && A[right] == temp[2]) {
                    right--;
                }
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
    a.push_back(2147483647);
    a.push_back(-2147483648);
    a.push_back(-2147483648);
    a.push_back(0);
    a.push_back(1);

    result = Sum3(a);

    for(int i = 0; i < result.size(); i++) {
        for(int j = 0; j < result[0].size(); j++) {
            cout << result[i][j] << "\t";
        }
        cout << "\n";
    }
}