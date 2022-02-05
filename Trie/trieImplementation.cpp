#include <iostream>

using namespace std;

struct Node {
    Node* links[26];
    bool flag = false;

    bool containsKey(char ch) {
        if(links[ch - 'a'] != NULL) {
            return true;
        }
        else {
            return false;
        }
    }

    void putKey(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void setEnd() {
        flag = true;
    }
};

class Trie {
    private :
        Node* root;
    public :

        // constructor 
        Trie() {
            root = new Node();
        }

        // insert method
        void insert(string word) {
            Node* node = root;

            for(int i = 0; i < word.length(); i++) {
                if(!node -> containsKey(word[i])) {
                    node -> putKey(word[i], new Node());
                }
                node = node -> get(word[i]);
            }

            node -> setEnd();
        }

        // search method
        bool search(string word) {
            Node* node = root;

            for(int i = 0; i < word.length(); i++) {
                if(!node -> containsKey(word[i])) {
                    return false;
                }
                node = node -> get(word[i]);
            }

            return node -> flag;
        }

        // starts with
        bool startsWith(string word) {
            Node* node = root;

            for(int i = 0; i < word.length(); i++) {
                if(!node -> containsKey(word[i])) {
                    return false;
                }
                node = node -> get(word[i]);
            }
            return true;
        }
};

int main() {
    Trie t;
    t.insert("jay");
    string temp = "";
    temp += 'j';
    cout << t.startsWith(temp);
    
    return 0;
}