/*
题目描述：
给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。
异位词 指由相同字母重排列形成的字符串（包括相同的字符串）。

我的思路：
1、统计字符串p所有字符出现的个数，以字符为key、格数为value建立hashmap，用于判断s的字串是否为p的“异位词”;
2、用滑动窗口逐步检测s长为p.size()的子串;
3、若上一个子串是p的“异位词”，则滑动时只要判断移除窗口的字符与移进窗口的字符是否相等
4、剪枝操作，窗口可以跳过部分子串
*/
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans = {};
        int np = p.size(), sp = s.size();
        if(np > sp) {
            return ans;
        }
        unordered_map<char, int> nletter;
        for(auto c: p) {
            if(nletter.find(c) == nletter.end()) {
                nletter.emplace(c, 1);
            } else {
                nletter[c] += 1;
            }
        }
        bool last = false;
        for(int i = 0; i < sp - np + 1; ++i) {
            if(last) {
                if(s[i - 1] == s[i + np - 1]) {
                    ans.emplace_back(i);
                    continue;
                } else {
                    last = false;
                    continue;
                }
            }
            unordered_map<char, int> tmp(nletter);
            for(int j = 0; j < np; ++j) {
                if(tmp.find(s[i + j]) == tmp.end()) {
                    i = i + j;
                    break;
                } else {
                    if(tmp[s[i + j]] == 0) {
                        break;
                    } else {
                        tmp[s[i + j]] -= 1;
                    }
                }
                if(j == np - 1) {
                    ans.emplace_back(i);
                    last = true;
                }
            }
        }
        return ans;
    }
};




/* 
    没有像我一样反复建立哈希表，而是通过维护两个哈希表的方式来处理（因为我没有想到 == 运算符的重载）
    并且利用vector的下标，与26个字母的顺序所对应
*/

class officialSolution {
public:
    vector<int> findAnagrams(string s, string p) {
        int sLen = s.size(), pLen = p.size();

        if (sLen < pLen) {
            return vector<int>();
        }

        vector<int> ans;
        vector<int> sCount(26);
        vector<int> pCount(26);
        for (int i = 0; i < pLen; ++i) {
            ++sCount[s[i] - 'a'];
            ++pCount[p[i] - 'a'];
        }

        if (sCount == pCount) {
            ans.emplace_back(0);
        }

        for (int i = 0; i < sLen - pLen; ++i) {
            --sCount[s[i] - 'a'];
            ++sCount[s[i + pLen] - 'a'];

            if (sCount == pCount) {
                ans.emplace_back(i + 1);
            }
        }

        return ans;
    }
};

