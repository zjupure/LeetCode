class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        for(int i = 0; i < 26; i++)
            child[i] = NULL;
    }
    TrieNode(char _key, int _color, int _cnt):key(_key),color(_color), cnt(_cnt)
    {
        for(int i = 0; i < 26; i++)
            child[i] = NULL;
    }
    char key;
    int color;
    int cnt;
    TrieNode *child[26];
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string s) {
        TrieNode *cur = root;
        
        for(int i = 0; i < s.size(); i++)
        {
            int id = s[i] - 'a';
            if(cur->child[id] == NULL)
            {
                TrieNode *post = new TrieNode(s[i],0,1);
                cur->child[id] = post;
            }
            else
            {
                cur->cnt++;
            }
            
            cur = cur->child[id];
        }
        cur->color = 1;
    }

    // Returns if the word is in the trie.
    bool search(string key) {
        bool isOk = true;
        TrieNode *cur = root;
        
        for(int i = 0; i < key.size(); i++)
        {
            int id = key[i] - 'a';
            if(cur->child[id] == NULL)
            {
                isOk = false;
                break;
            }
            
            cur = cur->child[id];
        }
        
        if(cur->color != 1)
            isOk = false;
        
        return isOk;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        bool isOk = true;
        TrieNode *cur = root;
        
        for(int i = 0; i < prefix.size(); i++)
        {
            int id = prefix[i] - 'a';
            if(cur->child[id] == NULL)
            {
                isOk = false;
                break;
            }
            
            cur = cur->child[id];
        }
        
        return isOk;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");