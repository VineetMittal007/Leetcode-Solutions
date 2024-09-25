class Solution {
struct TrieNode {
    TrieNode* arr[26];
    bool is_end;
    TrieNode() {
        for (int i = 0; i < 26; i ++) arr[i] = NULL;
        is_end = false;
    }  
};

void insert(TrieNode* root, string key) {
    TrieNode* curr = root;
    for (int i = 0; i < key.size(); i ++) {
        int idx = key[i] - 'a';
        if (curr->arr[idx] == NULL)
            curr->arr[idx] = new TrieNode();
        curr = curr->arr[idx];
    }
    curr->is_end = true;
}

bool dfs(TrieNode* root, string key, int index, int count) {
    if (index >= key.size())
        return count > 1;
    TrieNode* curr = root;
    for (int i = index; i < key.size(); i ++) {
        int p = key[i] - 'a';
        if (curr->arr[p] == NULL) {
            return false;
        }
        curr = curr->arr[p];
        if (curr->is_end) {
            if (dfs(root, key, i+1, count+1))
                return true;
        }
    }
    return false;
}
public:
vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
    TrieNode* root = new TrieNode();
    for (int i = 0; i < words.size(); i ++) {
        insert(root, words[i]);
    }
    vector<string> ans;
    for (int i = 0; i < words.size(); i ++) {
        if (dfs(root, words[i], 0, 0))
            ans.push_back(words[i]);
    }
    return ans;   
}
};