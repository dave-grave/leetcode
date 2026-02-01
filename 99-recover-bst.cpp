#include <vector>

/**
 * Definition for a binary tree node.
 */
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void recoverTree(TreeNode* root) {
        
        // perform in order traversal, save all pointers in a running list
        std::vector<TreeNode*> in_order_nodes;
        in_order_traversal(root, in_order_nodes);

        // find and swap the pointers
        int first_bad_index = -1;
        int second_bad_index = -1; 
        for (int i=0; i<in_order_nodes.size()-1; i++) {
            if (in_order_nodes[i] > in_order_nodes[i+1]) {
                if (first_bad_index == -1) {
                    first_bad_index = i;
                }
                else {
                    second_bad_index = i;
                }
            }
        }
        

        // swap the two indices
        
    }

    void in_order_traversal(TreeNode* root, std::vector<TreeNode*> &in_order_nodes) {
        if (root) {
            in_order_traversal(root->left, in_order_nodes);
            in_order_nodes.push_back(root);
            in_order_traversal(root->right, in_order_nodes);
        }
        return;
    }

};