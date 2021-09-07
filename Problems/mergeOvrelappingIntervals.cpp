bool sortByFir(Interval a, Interval b) {
     return a.start < b.start;
 }
vector<Interval> Solution::merge(vector<Interval> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<Interval> result;
    sort(A.begin(), A.end(), sortByFir);

    for(int i = 0; i < A.size(); i++) {
        if(!result.empty()) {
            if(result[result.size() - 1].end >= A[i].start) {
                result[result.size() - 1].end = max(result[result.size() - 1].end, A[i].end);
            }

            else {
                Interval temp;
                temp.start = A[i].start;
                temp.end = A[i].end;
                result.push_back(temp);
            }
        }
        else {
            Interval temp;
            temp.start = A[i].start;
            temp.end = A[i].end;
            result.push_back(temp);
        }
    }

    return result;
}