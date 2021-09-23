#include <iostream>
#include <map>

using namespace std;

int occurancesOfAnagrams(string txt, string pat) {
    int l = 0;
	    int r = 0;
	    int result = 0;
	    int dc;
	    map<char, int> m;
	    
	    for(int i = 0; i < pat.length(); i++) {
	       if(m.find(pat[i]) == m.end()) {
	           m.insert(make_pair(pat[i], 1));
	       }
	       else {
	           m[pat[i]]++;
	       }
	    }
	    dc = m.size();
	    while(r < txt.length()) {
	        if(m.find(txt[r]) != m.end()) {
                m[txt[r]]--;
                if(m[txt[r]] == 0) {
                    dc--;
                }
	        }
	        
	        if(r - l + 1 < pat.length()) {
	            r++;
	            continue;
	        }
	        
	        if(r - l + 1 == pat.length()) {
	            if(dc == 0) {
	                result++;
	            }
	            
	            if(m.find(txt[l]) != m.end()) {
	                m[txt[l]]++;
	                if(m[txt[l]] == 1) {
	                    dc++;
	                }
	            }
	            
	            l++;
	            r++;
	        }
	    }
	return result; 
}

int main() {
    string s1 = "forxxorfxdofr";
    string s2 = "for";
    int result = occurancesOfAnagrams(s1, s2);
    cout << result;
    return 0;
}