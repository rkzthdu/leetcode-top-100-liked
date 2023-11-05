/*
  分割回文串，回溯
*/


class Solution {
public:
    void backtrack(int n, vector<vector<string>> &ans, vector<int> &pos, string &str) {
        auto lastpos = pos.back();
        if(lastpos == n) {
            string tmp = "";
            vector<string> sol;
            for(int i = 0; i < pos.size() - 1; ++i) {
                tmp = str.substr(pos[i], pos[i + 1] - pos[i]);
                sol.emplace_back(tmp);
            }
            ans.emplace_back(sol);
            return;
        }
        for(int i = lastpos + 1; i < n + 1; ++i) {
            if(i == lastpos + 1) {
                pos.emplace_back(i);
                backtrack(n, ans, pos, str);
                pos.pop_back();
            } else {
                for(int j = 0; j < (i - lastpos)/2; ++j) {
                    if(str[lastpos + j] != str[i - j - 1]) {
                        break;
                    }
                    if(j == (i - lastpos)/2 - 1) {
                        pos.emplace_back(i);
                        backtrack(n, ans, pos, str);
                        pos.pop_back();
                    }
                }
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n = s.size();
        if(n == 1) {
            auto ans = vector<vector<string>>();
            auto tmp = vector<string>(1, s);
            ans.emplace_back(tmp);
            return ans;
        } else if(n == 2) {
            auto ans = vector<vector<string>>();
            auto tmp = vector<string>(2);
            tmp[0] = s.substr(0,1);
            tmp[1] = s.substr(1,1);
            ans.emplace_back(tmp);
            if(s[0] == s[1]) {
                auto tmp = vector<string>(1, s);
                ans.emplace_back(tmp);
            }
            return ans;
        } else {
            auto ans = vector<vector<string>>();
            auto pos = vector<int>(1, 0);
            backtrack(s.size(), ans, pos, s);
            return ans;
        }
    }
};


/*
  官方通过回溯结合动态规划算法，使得求解更加高效
*/


class officialSolution {
private:
    vector<vector<int>> f;
    vector<vector<string>> ret;
    vector<string> ans;
    int n;

public:
    void dfs(const string& s, int i) {
        if (i == n) {
            ret.push_back(ans);
            return;
        }
        for (int j = i; j < n; ++j) {
            if (f[i][j]) {
                ans.push_back(s.substr(i, j - i + 1));
                dfs(s, j + 1);
                ans.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        n = s.size();
        f.assign(n, vector<int>(n, true));

        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                f[i][j] = (s[i] == s[j]) && f[i + 1][j - 1];
            }
        }

        dfs(s, 0);
        return ret;
    }
};
