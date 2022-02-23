/*
该工程文件是剑指offer第二版的题目代码
*/
#include<iostream>
#include<vector>
#include<map>
#include<string>

using namespace std;

/* 简单题目 */

/* 
 * @题号 : 剑指offer 30
 * @要求 : 定义栈的数据结构，请在该类型中实现一个能够得到栈
 *         的最小元素的 min 函数在该栈中，调用 min、push 
 *         及 pop 的时间复杂度都是 O(1)。
*/
class MinStack {
private:
    vector<int> buffer;
    map<int, int> buffer_check;
    int len;
public:
    /** initialize your data structure here. */
    MinStack() {
        len = 0;
    }
    
    void push(int x) {
        this->buffer.push_back(x);
        this->buffer_check[x]++;
        this->len++;
    }
    
    void pop() {
        this->buffer_check[this->top()]--;
        if(this->buffer_check[this->top()] == 0){
            this->buffer_check.erase(this->top());
        }
        this->buffer.pop_back();
        this->len--;
    }
    
    int top() {
        return this->buffer[this->len-1];
    }
    
    int min() {
        map<int,int>::iterator item = this->buffer_check.begin();
        return item->first;
    }
};

/*
 * @题目 : 剑指offer 03
 * @要求 : 找出数组中重复的数字。
 *         在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。
 *         数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每
 *         个数字重复了几次。请找出数组中任意一个重复的数字。
 */

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        map<int, int> cache_map;
        int result = NULL;
        for(int i = 0; i < nums.size(); i++){
            cache_map[nums[i]] ++;
            if(cache_map[nums[i]] > 1){
                result = nums[i];
                break;
            }
        }
        return result;
    }
};


/*========================================================================*/


/* 中等题目 */

// No.


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


/*========================================================================*/


/* 困难题目 */