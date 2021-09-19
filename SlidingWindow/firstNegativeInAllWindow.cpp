#include <iostream>
#include <queue>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int A[],
                                            long long int N, long long int K)
{

    long long int l = 0;
    long long int r = 0;
    queue<long long int> q;
    vector<long long int> result;

    while (r < N)
    {
        if (A[r] < 0)
        {
            q.push(A[r]);
        }

        if (r - l + 1 < K)
        {
            r++;
            continue;
        }

        if ((r - l + 1) == K)
        {

            if (!q.empty())
            {
                result.push_back(q.front());
                if (A[l] == q.front())
                {
                    q.pop();
                }
            }
            else {
                result.push_back(0);
            }
            r++;
            l++;
        }
    }

    return result;
}

int main()
{
    long long int A[] = {12, -1, -7, 8, -15, 30, 16, 28};
    long long int n = 8;
    long long int k = 3;
    vector <long long> result = printFirstNegativeInteger(A, n, k);

    for(int i = 0; i < result.size(); i++) {
        cout << result[i];
    }
    return 0;
}