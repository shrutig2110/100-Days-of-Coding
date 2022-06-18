struct TrieNode{
    struct TrieNode* children[27];
    int index=0;
    TrieNode(){
        for(int i=0;i<27;i++){
            children[i]=NULL;
        }
        index=0;
    }
};

class WordFilter {
private:
    TrieNode* root;
public:
    WordFilter(vector<string>& words){
        root=new TrieNode();
        for(int index=0;index<words.size();index++){
            string word=words[index]+"{";
            for(int i=0;i<word.size();i++){
                TrieNode* cur=root;
                for(int j=i;j<2*word.size()-1;j++){ // 2*word.size()-1 because "{" not considered
                    // cout<<word[j%word.length()]<<" ";
                    int k=word[j%word.length()]-'a';
                    if(cur->children[k]==NULL){
                        cur->children[k]=new TrieNode();
                    }
                    cur=cur->children[k];
                    cur->index=index;
                }
            // cout<<endl;
            }
        }
    }
    
    int f(string prefix, string suffix){
        TrieNode* cur=root;
        string newStr=suffix+'{'+prefix;
        for(char letter: newStr){
            if(cur->children[letter-'a']==NULL){
                return -1;
            } 
            cur=cur->children[letter-'a'];
        }
        return cur->index;
    }
};