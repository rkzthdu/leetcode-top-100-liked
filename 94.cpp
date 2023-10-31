/*
  94. 二叉树中序遍历
  采用二叉树中序遍历的迭代写法（不规范，不是最优解，写题时临时写的）
  使用了栈来存储一定顺序的二叉树节点地址
  按 “左、中、右” 的顺序来存储节点：
    每次迭代通过top()访问栈顶部节点，
    若该节点有左孩子节点，将其左孩子节点压栈；
    若该节点没有左孩子节点但有右孩子节点，将其本身出栈，并将其右孩子压栈；
    若该节点没有孩子节点，将其本身出栈；
  为了避免已访问过的节点重复遍历，又设置了一个哈希表visted来记录以及遍历过的节点，这就导致内存使用增加
*/



class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == nullptr) {
            return ans;
        }
        stack<TreeNode*> st;
        st.push(root);
        TreeNode *tmp = root;
        unordered_map<TreeNode*, bool> visted;
        while(st.empty() == false) {
            tmp = st.top();
            if(tmp->left != nullptr && visted.find(tmp->left) == visted.end()) {
                st.push(tmp->left);
            } else if(tmp->right != nullptr && visted.find(tmp->right) == visted.end()) {
                ans.emplace_back(tmp->val);
                visted.emplace(tmp, true);
                st.pop();
                st.push(tmp->right);
            } else {
                ans.emplace_back(tmp->val);
                visted.emplace(tmp, true);
                st.pop();
            }
        }
        return ans;
    }
};



/*
  官方的二叉树中序遍历迭代方法
  思路是：
  1、一直往左访问节点，逐个压栈，直到没有左孩子结点；
  2、然后将栈顶元素出栈，访问其右孩子节点；
  3、重复步骤1，直至【root为空和栈为空】
*/

class officialSolution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        while (root != nullptr || !stk.empty()) {
            while (root != nullptr) {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            res.push_back(root->val);
            root = root->right;
        }
        return res;
    }
};
