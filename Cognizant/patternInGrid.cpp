#include <iostream>

using namespace std;

bool findPattern(string grid[], string pattern[], int gr, int pr) {
    int si = -1;
    int csi = -1;
    bool result;

    for(int i = 0; i < gr; i++) {
        if(grid[i].find(pattern[0])) {
            for(int k = 0, l = i; k < pr; k++) {
                for(int j = 0; j < grid[l].length() - pattern[k].length() + 1; j++) {
                    if(pattern[k] == grid[l].substr(j, pattern[k].length())) {
                        if(csi == -1) {
                            csi = j;
                        }
                    }
                }

                if(si == -1 || si == csi) {
                    si = csi;
                    result = true;
                }
                else if(si != csi) {
                    si = -1;
                    csi = -1;
                    result = false;
                    break;
                }

                if(k == pr - 1 && si == csi) {
                    result = true;
                }
            }
            if(result) {
                break;
            }
        }

    }

    return result;
}

int main() {
    int gr, gc, pr, pc;
    cin >> gr;
    cin >> gc;
    string grid[gr];

    for(int i = 0; i < gr; i++) {
        cin >> grid[i]; 
    }

    cin >> pr;
    cin >> pc;
    string pattern[pr];

    for(int i  = 0; i < pr; i++) {
        cin >> pattern[i];
    }

    bool result = findPattern(grid, pattern, gr, pr);
    if(result) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    return 0;
}