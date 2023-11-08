/*
  队列，层次遍历，依次交换遍历节点的左右子树
*/



class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) {
            return root;
        }
        queue<TreeNode *> nodes;
        nodes.push(root);
        while(nodes.empty() != true) {
            TreeNode *parent = nodes.front();
            TreeNode *tmp = parent->left;
            parent->left = parent->right;
            parent->right = tmp;
            nodes.pop();
            if(parent->left != nullptr) {
                nodes.push(parent->left);
            }
            if(parent->right != nullptr) {
                nodes.push(parent->right);
            }
        }
        return root;
    }
};



/*
  递归
*/

class officialSolution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);
        root->left = right;
        root->right = left;
        return root;
    }
};
