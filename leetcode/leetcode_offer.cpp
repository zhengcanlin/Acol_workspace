/*
该工程文件是剑指offer第二版的题目代码
*/

#include<iostream>
#include<vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int find(vector<int> inorder, int target){
        int result;
        for(int i = 0; i < inorder.size(); i++){
            if(inorder[i] == target){
                result = i;
                break;
            }
        }
        return result;
    }
    TreeNode* build(vector<int> preorder, vector<int> inorder, int left, int right, int index){
        if(left > right){
            return NULL;
        }
        TreeNode* node = new TreeNode(preorder[index]);
        int index_in_inorder = this->find(inorder, preorder[index]);
        node->left = this->build(preorder, inorder, left, index_in_inorder-1, index+1);
        node->right = this->build(preorder, inorder, index_in_inorder+1, right, index+1+index_in_inorder-left);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0){
            return NULL;
        }
        int left = 0;
        int right = preorder.size() - 1;
        return this->build(preorder, inorder, left, right, 0);
    }
};
