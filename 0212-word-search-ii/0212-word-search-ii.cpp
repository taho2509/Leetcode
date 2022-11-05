class TrieNode {
public:
    bool isWord = false;
    string word;
    vector<TrieNode*> children = vector<TrieNode*>(26);
    
    bool hasChild() {
        for (const auto child : children) {
            if (child) {
                return true;
            }
        }
        return false;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();
        n = board[0].size();

        root = new TrieNode();
        for (const auto& word : words) {
            insertWord(word);
        }
        
        res.clear();
        visited = vector<vector<bool>>(m, vector<bool>(n));
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                dfs(board, row, col, root);
            }
        }
        return res;
    }
    
private:
    int m;
    int n;
    TrieNode* root;
    vector<string> res;
    vector<vector<bool>> visited;
    vector<int> rowOffset = {-1, 0, 1, 0};
    vector<int> colOffset = {0, 1, 0, -1};
    
    void insertWord(const string& word) {
        TrieNode* curr = root;
        
        for (const auto ch : word) {
            if (curr->children[ch - 'a'] == nullptr) {
                curr->children[ch - 'a'] = new TrieNode();
            }
            curr = curr->children[ch - 'a'];
        }
        
        curr->isWord = true;
        curr->word = word;
    }
    
    void dfs(const vector<vector<char>>& board, int row, int col, TrieNode* node) {
        auto nextNode = node->children[board[row][col] - 'a'];
        
        if (!nextNode) {
            return;
        }
        
        if (nextNode->isWord) {
            res.push_back(nextNode->word);
            nextNode->isWord = false;
            nextNode->word = "";
        }
        
        visited[row][col] = true;
        for (int d = 0; d < rowOffset.size(); d++) {
            int nextRow = row + rowOffset[d];
            int nextCol = col + colOffset[d];
            
            if (nextRow < 0 || nextRow >= m || nextCol < 0 || nextCol >= n) {
                continue;
            }
            
            if (visited[nextRow][nextCol]) {
                continue;
            }

            dfs(board, nextRow, nextCol, nextNode);
        }
        visited[row][col] = false;
        
        if (!nextNode->isWord && !nextNode->hasChild()) {
            delete nextNode;
            node->children[board[row][col] - 'a'] = nullptr;
        }
    }
};