/*
  二叉树的层次遍历
  首先使用队列这个没有问题。
  题目要求返回一个二维vector，因此要辨别节点所在的层数：
    做法1：将空节点也加入队列，则每层节点数与层数的关系是 n = 2^level，空节点不加入最后的ans
    做法2（我目前采用）：为了避免遍历空节点，在遍历 level - 1 层时统计 level 层的节点数，即遇到空节点就将总数(2^level)减去1
*/



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr) {
            return ans;
        }
        vector<int> tmp;
        ans.emplace_back(tmp);
        int level = 0, max = 1, num = 0, bias = 0;
        queue<TreeNode*> qu;
        qu.push(root);
        while(qu.empty() != true) {
            if(num == max) {
                max = max * 2 + bias;
                num = 0;
                bias = 0;
                ++level;
                ans.emplace_back(tmp);
            }
            root = qu.front();
            ans[level].emplace_back(root->val);
            qu.pop();
            ++num;
            if(root->left != nullptr) {
                qu.push(root->left);
            } else {
                --bias;
            }
            if(root->right != nullptr) {
                qu.push(root->right);
            } else {
                --bias;
            }

        }
        return ans;
    }
};



/*
  官方做法：广度优先遍历
  通过获取当前队列的大小，进行层次遍历，这样就不会遍历到下一层的节点
*/

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector <vector <int>> ret;
        if (!root) {
            return ret;
        }

        queue <TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int currentLevelSize = q.size();
            ret.push_back(vector <int> ());
            for (int i = 1; i <= currentLevelSize; ++i) {
                auto node = q.front(); q.pop();
                ret.back().push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        
        return ret;
    }
};

// 作者：力扣官方题解
// 链接：https://leetcode.cn/problems/binary-tree-level-order-traversal/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
