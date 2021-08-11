#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

bool bydesc(float a, float b) {
    return (b < a);
}
vector<float> findThree(vector<float> p, int n, float rm) {
    vector<float> result;

    sort(p.begin(), p.end(), bydesc);
    for(int i = 0; i < p.size(); i++) {
        if(p[i] != rm) {
            for(int j = i; j < p.size() && result.size() != 3; j++) {
                result.push_back(p[i]);
            }
            break;
        }
    }
    return result;
}

int main() {
    vector<float> p;
    vector<float> result;
    float rm = 42.195;
    string val;
    while(true) {
        cin >> val;
        if(val == "q") {
            if(!p.empty()) {
                result = findThree(p, p.size(), rm);

                if(result.size() == 0) {
                    cout << 0;
                }
                else {
                    for(int i = 0 ; i < result.size(); i++) {
                        cout << result[i] << " ";
                    }
                }
                exit(0);
            }
            else {
                exit(0);
            }
        }
        else{
            float temp = stof(val);
            p.push_back(temp);
        }
    }
    
    return 0;
}