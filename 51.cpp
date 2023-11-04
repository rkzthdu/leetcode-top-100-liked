/*
  N皇后问题
  回溯法，除此之外个人觉得如何使用比较高效的数据结构来记录不可选取点、以及回溯临时解也是一个问题
*/



class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        auto solutions = vector<vector<string>>();
        auto columns = unordered_set<int>();
        auto diags1 = unordered_set<int>();
        auto diags2 = unordered_set<int>();
        auto board = vector<int>(n);
        backtrack(0, columns, diags1, diags2, board, solutions);
        return solutions;
    }
    void backtrack(int row, unordered_set<int> &columns, unordered_set<int> &diags1, unordered_set<int> &diags2, vector<int> &board, vector<vector<string>> &solutions) {
        int n = board.size();
        if(row == n) {
            auto sol = genSolution(board);
            solutions.emplace_back(sol);
            return;
        }
        for(int column = 0; column < n; ++column) {
            if(columns.find(column) != columns.end()) {
                continue;
            }
            auto diag1 = row - column;
            if(diags1.find(diag1) != diags1.end()) {
                continue;
            }
            auto diag2 = row + column;
            if(diags2.find(diag2) != diags2.end()) {
                continue;
            }
            board[row] = column;
            columns.emplace(column);
            diags1.emplace(diag1);
            diags2.emplace(diag2);
            backtrack(row + 1, columns, diags1, diags2, board, solutions);
            columns.erase(column);
            diags1.erase(diag1);
            diags2.erase(diag2);
        }
    }
    vector<string> genSolution(vector<int> &board) {
        vector<string> ans;
        int n = board.size();
        string str(n, '.');
        for(int i = 0; i < n; ++i) {
            str[board[i]] = 'Q';
            ans.emplace_back(str);
            str[board[i]] = '.';
        }
        return ans;
    }
};
