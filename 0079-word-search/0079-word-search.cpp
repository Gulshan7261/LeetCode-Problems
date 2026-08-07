class Solution {
public:

    bool dfs(vector<vector<char>>& board, string &word,
             int i,int j,int count) {

        // Base case
        if (count == word.size()) {
            return true;
        }
        // Boundary and character check
        if (i < 0 || i >= board.size() ||
            j < 0 || j >= board[0].size() ||
            board[i][j] != word[count]) {
            return false;
        }
        // Mark current cell as visited
        char temp = board[i][j];
        board[i][j] = '*';

        // Explore all 4 directions
        bool isFound =
            dfs(board, word, i + 1, j, count + 1) ||
            dfs(board, word, i - 1, j, count + 1) ||
            dfs(board, word, i, j + 1, count + 1) ||
            dfs(board, word, i, j - 1, count + 1);

        // Backtrack
        board[i][j] = temp;

        return isFound;
    }

    bool exist(vector<vector<char>>& board, string word) {

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {

                if (board[i][j] == word[0]) {
                    if (dfs(board, word, i, j, 0)) {
                        return true;
                    }
                }

            }
        }

        return false;
    }
};