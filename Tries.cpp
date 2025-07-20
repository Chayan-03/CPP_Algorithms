#include<bits/stdc++.h>
using namespace std;




//Trie Type 1 example
class Trienode{
    public;
    bool isEnd;
    Trienode* children[26];
    Trienode() {
        for (int i=0;i<26;i++) {
            children[i] = nullptr;
        }
        isEnd = false;
    }
};
class Trie{
    public:
    void insertTrie(Trienode* root,string word) {
        Trienode* curr = root;
        for (char c: word) {
            int index = c - 'a';
            if (curr->children[index]!=nullptr) {
                curr = curr->children[index];
            }
            else {
                Trienode* newNode = new Trienode();
                curr->children[index] = newNode;
            }
        }
        curr->isEnd  = true;
    }
    bool searchTrie(Trienode* root,string word) {
        Trienode* curr = root;
        if (word.size() == 0) {
            return false;
        }
        for (char c :word) {
            int index = c - 'a';
            if (curr->children[index]!=nullptr) {
                //move ahead
                curr = curr->children[index];
            }
            else {
                return false;
            }
        }
        return curr->isEnd;
    }
};
int main() {
    //implementtries in c++
    //tries has nodes and the tree like structure
    Trie* t = new Trie();
    Trienode* root = new Trienode();
    t->insertTrie(root,"h");
    bool ans = t->searchTrie(root,"h");
    cout<<ans<<endl;
    return 0;

}



// Trie type 2 example
#include<bits/stdc++.h>
using namespace std;

class Trienode {
public:
    bool isEnd;
    Trienode* children[26];
    Trienode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isEnd = false;
    }
};

class Trie {
public:
    void insertTrie(Trienode* root, string word) {
        Trienode* curr = root;
        for (char c : word) {
            int index = c - 'a';
            if (curr->children[index] == nullptr) {
                curr->children[index] = new Trienode();
            }
            curr = curr->children[index];
        }
        curr->isEnd = true;
    }

    bool searchTrie(Trienode* root, string word) {
        Trienode* curr = root;
        for (char c : word) {
            int index = c - 'a';
            if (curr->children[index] == nullptr) {
                return false;
            }
            curr = curr->children[index];
        }
        return curr->isEnd;
    }
};

int main() {
    Trie t;
    Trienode* root = new Trienode();

    t.insertTrie(root, "h");
    bool ans = t.searchTrie(root, "h");
    cout << ans << endl;
    delete root;

    return 0;
}
