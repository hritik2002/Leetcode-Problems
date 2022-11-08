class Solution {
public:
    int n, m;
    bool wordSearch(vector<vector<char>>& board, string word, int currRow, int currCol, int currIndex) {
        if(currIndex == word.length()) {
            return true;
        }
        if(currRow < 0 || currCol < 0 || currRow >= m || currCol >= n || board[currRow][currCol] == '.') {
            return false;
        }
        
        if(board[currRow][currCol] != word[currIndex]) {
            return false;
        }
        
        char tmp = board[currRow][currCol];
        
        board[currRow][currCol] = '.';
        bool up = wordSearch(board, word, currRow - 1, currCol, currIndex + 1);
        bool down = wordSearch(board, word, currRow + 1, currCol, currIndex + 1);
        bool left = wordSearch(board, word, currRow, currCol - 1, currIndex + 1);
        bool right = wordSearch(board, word, currRow, currCol + 1, currIndex + 1);
        
        board[currRow][currCol] = tmp;
        
        return up || down || left || right;
    }
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(), n = board[0].size();
        int currRow = 0, currCol = 0, currIndex = 0;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(word[0] == board[i][j]) {
                    if(wordSearch(board, word, i, j, currIndex)) {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};
