class Trie {
    Trie* child[26];
public:
    Trie() {
        for(int i = 0; i < 26; i++)
            this->child[i] = NULL;
    }
    
    void insert(string &word) {
        auto node = this;
        for(auto &c: word) {
            if(!node->child[c-'a'])
                node->child[c-'a'] = new Trie();
            node = node->child[c-'a'];
        }
    }
    
    int count() {
        int ret = 0;
        auto node = this;
        queue<Trie*> q;
        q.push(node);
        int level = -1;
        
        while(!q.empty()) {
            level++;
            int s = q.size();
            for(int i = 0; i < s; i++) {
                auto n = q.front();
                q.pop();
                bool is_leaf = true;
                for(int j = 0; j < 26; j++) {
                    if(n->child[j]) {
                        q.push(n->child[j]);
                        is_leaf = false;
                        
                    }
                }
                if(is_leaf) {
                    ret += level + 1;
                }
            }
        }
        
        return ret;
    }
};

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        Trie t;
        for(auto &word: words) {
            reverse(word.begin(), word.end());
            t.insert(word);
        }
        
        return t.count();
    }
};