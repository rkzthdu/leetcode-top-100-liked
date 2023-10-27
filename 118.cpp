/*
  杨辉三角
  没有想到动态规划的方法，选择了找一定的规律来求解
*/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<int> tmp = {1};
        vector<vector<int>> ans;
        ans.emplace_back(tmp);
        for(int i = 1; i < numRows; ++i) {
            if(i == 1) {
                tmp.emplace_back(1);
                ans.emplace_back(tmp);
            } else {
                for(int j = 0; j < ans[i - 1].size()/2; ++j) {
                    tmp.emplace_back(ans[i - 1][j] + ans[i - 1][j + 1]);
                }
                int len = tmp.size();
                if(ans.size() % 2 == 0) {
                    for(int j = 0; j < len - 1; ++j) {
                        tmp.emplace_back(tmp[len - j - 2]);
                    }
                } else {
                    for(int j = 0; j < len; ++j) {
                        tmp.emplace_back(tmp[len - j - 1]);
                    }
                }
                ans.emplace_back(tmp);
            }
            tmp = {1};
        }
        return ans;
    }
};


/*
  先建立了一个numRows行的二维vector，在处理每一行时再resize需要的元素数
  然后就直接根据上一行的元素相加得到当前处理行的元素
*/
class officialSolution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret(numRows);
        for (int i = 0; i < numRows; ++i) {
            ret[i].resize(i + 1);
            ret[i][0] = ret[i][i] = 1;
            for (int j = 1; j < i; ++j) {
                ret[i][j] = ret[i - 1][j] + ret[i - 1][j - 1];
            }
        }
        return ret;
    }
};
