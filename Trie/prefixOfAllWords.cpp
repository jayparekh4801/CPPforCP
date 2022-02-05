#include <iostream>
#include <vector>

using namespace std;

struct Node {
    Node* links[26];
    bool flag = false;
    int freq = 0;

    bool containsKey(char ch) {
        if(links[ch - 'a'] != NULL) {
            links[ch - 'a'] -> freq++;
            return true;
        }
        else {
            return false;
        }
    }

    void putKey(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* getNode(char ch) {
        return links[ch - 'a'];
    }

    void setEnd() {
        flag = false;
    }
};

class Trie {
    private :
        Node* root;
    
    public :
        Trie() {
            root = new Node();
        }

        void insert(string word) {
            Node* node = root;
            int l = word.length();
            for(int i = 0; i < l; i++) {
                if(!node -> containsKey(word[i])) {
                    node -> putKey(word[i], new Node());
                }
                node = node -> getNode(word[i]);
            }
            node -> setEnd();
        }

        string givePrefix(string word) {
            Node* node = root;
            string temp = "";
            int l = word.length();
            for(int i = 0; i < l; i++) {
                temp += word[i];
                if(node -> links[word[i] - 'a'] -> freq == 1) {
                    return temp;
                }
                node = node -> getNode(word[i]);
            }
        }
};

vector<string> findPrefixes(string arr[], int n) {

    Trie t;
    vector<string> result;
    for(int i = 0; i < n; i++) {
        t.insert(arr[i]);
    }

    for(int i = 0; i < n; i++) {
        string ne = t.givePrefix(arr[i]);
        result.push_back(ne);
    }

    return result;

}

int main() {
    int n;
    cin >> n;
    string arr[n];
    vector<string> result1;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    result1 = findPrefixes(arr, n);

    for(int i = 0; i < n; i++) {
        cout << result1[i] << "\n";
    }

    return 0;
}