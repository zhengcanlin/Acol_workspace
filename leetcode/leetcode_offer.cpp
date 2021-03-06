/*
该工程文件是剑指offer第二版的题目代码
*/
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>

using namespace std;

/* 简单题目 */
/* 
 * @题号 : 剑指offer 001
 * @要求 : 给定两个整数 a 和 b ，求它们的除法的商 a/b ，要求不得使用乘号 '*'、除号 '/' 以及求余符号 '%' 
 * @考察内容 ：数学逻辑
 * @input : a=15, b = 2
 * @output : 7
 */
class Solution {
private:
    typedef int SIGN;
public:
    int divide(int a, int b) {
        if(a == INT_MIN && b == -1){
            return INT_MAX;
        }
        SIGN sign = (a > 0) ^ (b > 0) ? -1 : 1;
        if(a > 0){ a = -a; }
        if(b > 0){ b = -b; }

        int result = 0;
        while(a <= b){
            int value = b;
            int k = 1;
            while(value >= 0xc0000000 && a <= value + value){
                value += value;
                if(k > INT_MAX / 2) return INT_MIN;
                k += k;
            }
            a -= value;
            result += k;
        }
        return sign == -1 ? -result : result;
    }
};

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

/*
 * @题目 : 剑指offer 62
 * @要求 : 0,1,···,n-1这n个数字排成一个圆圈，从数字0开始，每次从这个圆圈里删除第m个数字
 *        （删除后从下一个数字开始计数）。求出这个圆圈里剩下的最后一个数字。
 *         例如，0、1、2、3、4这5个数字组成一个圆圈，从数字0开始每次删除第3个数字，
 *         则删除的前4个数字依次是2、0、4、1，因此最后剩下的数字是3。
 */
class Solution {
public:
    int lastRemaining(int n, int m) {
        int result = 0;
        for(int i = 2; i <= n; i++){
            result = (result + m) % i;
        }
        return result;
    }
};

/*
 * @题目 : 剑指offer 39
 * @要求 : 数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
 */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        map<int, int> dictionary;
        for(int i = 0; i < n; i++){
            dictionary[nums[i]]++;
        }
        map<int, int>::iterator item = dictionary.begin();
        n = int(n / 2);
        int result;
        while(item != dictionary.end()){
            if(item->second >= n){
                result = item->first;
                break;
            }
            item++;
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

/*
 * @题目 : 剑指offer 63
 * @要求 : 假设把某股票的价格按照时间先后顺序存储在数组中，
 *         请问买卖该股票一次可能获得的最大利润是多少？
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> result = {0};
        int min_prices = prices[0];
        for(int i = 1; i < prices.size(); i++){
            result.push_back(max(result.back(), prices[i] - min_prices));
            min_prices = min(min_prices, prices[i]);
        }
        return result.back();
    }
};

/*
 * @题目 : 剑指offer 47
 * @要求 : 在一个 m*n 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于 0）。
 *         你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格、直到到达
 *         棋盘的右下角。给定一个棋盘及其上面的礼物的价值，请计算你最多能拿到多少价值的礼物？
 * @考察类型 : 动态规化
 */
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int h,w;
        h = grid.size();
        w = grid[0].size();
        vector<vector<int>> result(h, vector<int>(w, 0));
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(i == 0 && j == 0){
                    result[i][j] = grid[i][j];
                }
                else{
                    if(i == 0 || j == 0){
                        if(i == 0 && j != 0){
                            result[i][j] = result[i][j-1] + grid[i][j];
                        }
                        else if(i != 0 && j == 0){
                            result[i][j] = result[i-1][j] + grid[i][j];
                        }
                    }
                    else{
                        result[i][j] = max(result[i-1][j] + grid[i][j], result[i][j-1] + grid[i][j]);
                    }
                }
            }
        }
        return result[h-1][w-1];

    }
};

/*
 * @题目 : 剑指offer 35
 * @要求 : 请实现 copyRandomList 函数，复制一个复杂链表。在复杂链表中，
 *         每个节点除了有一个 next 指针指向下一个节点，还有一个 random 
 *         指针指向链表中的任意节点或者 null。
 * @考察类型 : 数据结构
 */
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<int, Node*> index_2_address;       // 新链表中，链表序号对应的地址
        map<Node*, int> address_2_index;       // 原链表中，地址对应的链表序号
        Node* p = head;
        Node* result = new Node(0);
        Node* q = result;
        int i = 0;
        while(p != NULL){
            q->next = new Node(p->val);
            q = q->next; 
            index_2_address[i] = q;
            address_2_index[p] = i;
            i++;
            p = p->next;
        }
        p = head;
        q = result->next;
        while(p != NULL){
            if(p->random == NULL){
                q->random = NULL;
            }
            else{
                q->random = index_2_address[address_2_index[p->random]];
            }
            p = p->next;
            q = q->next;
        }
        return result->next;
    }
};

/*
 * @题目 : 剑指offer 46
 * @要求 : 给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，
 *         1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。一个数字
 *         可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不
 *         同的翻译方法。
 * @考察类型 : 递归回溯
 * @input : 12258
 * @output : 5
 */
class Solution {
public:
    int count = 0;
    void check(vector<int> nums, int left, int right){
        int temp = 0;
        for(int i = left; i <= right; i++){
            temp = temp * 10 + nums[i];
        }
        if(temp > 25){
            return;
        }
        if(right == nums.size()-1){
            count++;
            return;
        }
        else{

            check(nums, right+1, right+1);
            check(nums, left, right+1);
        }
    }
    int translateNum(int num) {
        vector<int> nums;
        if(num == 0){
            nums.push_back(0);
        }
        while(num > 0){
            nums.insert(nums.begin(), num%10);
            num = num / 10;
        }
        int left = 0;
        int right = 0;
        check(nums, left, right);
        return count;
    }
};

/*
 * @题目 : 剑指offer 48
 * @要求 : 请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。
 * @考察类型 : 左右指针
 * @input : abcabcbb
 * @output : 3
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> dictionary;
        int left = 0;
        int right = 0;
        int result = 1;
        while(right < s.length()){
            if(dictionary[s[right]] != 0){
                if(result < (right - left)){
                    result = right - left;
                }
                dictionary[s[left]]--;
                left++;
            }
            else{
                dictionary[s[right]]++;
                right++;
            }
        }
        if((right - left) > result){
            result = right - left;
        }
        return result;
    }
};

/*
 * @题目 : 剑指offer 49
 * @要求 : 我们把只包含质因子 2、3 和 5 的数称作丑数（Ugly Number）。求按从小到大的顺序的第 n 个丑数。
 * @考察类型 : 动态规化
 * @input : n=10
 * @output : 12
 */

class Solution {
public:
    int nthUglyNumber(int n) {
        int a,b,c;
        a = b = c = 0;
        int* dp = new int[n];
        dp[0] = 1;
        for(int i = 1; i < n; i++){
            dp[i] = min(dp[a] * 2, dp[b] * 3);
            dp[i] = min(dp[i], dp[c] * 5);
            if(dp[i] == dp[a] * 2){
                a++;
            }
            if(dp[i] == dp[b] * 3){
                b++;
            }
            if(dp[i] == dp[c] * 5){
                c++;
            }
        }
        return dp[n-1];
    }
};

/*
 * @题目 : 剑指offer 38
 * @要求 : 输入一个字符串，打印出该字符串中字符的所有排列。你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。
 * @考察类型 : 深度优先遍历
 * @input : "abc"
 * @output : ["abc","acb","bac","bca","cab","cba"]
 */

class Solution {
public:
    vector<string> result;

    void DFS(vector<char> characters, vector<int>& visits, string str, int n){
        if(str.length() == n){
            result.push_back(str);
            return;
        }
        for(int i = 0; i < characters.size(); i++){
            if(visits[i] == 0){
                visits[i] = 1;
                DFS(characters, visits, str+characters[i], n);
                visits[i] = 0;
            }
        }
    }

    vector<string> permutation(string s) {
        vector<char> characters;
        int n = s.length();
        vector<int> visits(n, 0);
        for(int i = 0; i < n; i++){
            characters.push_back(s[i]);
        }
        DFS(characters, visits, "", n);
        sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());
        return result;
    }
};

/*
 * @题目 : 剑指offer 67
 * @要求 : 写一个函数 StrToInt，实现把字符串转换成整数这个功能。不能使用 atoi 或者其他类似的库函数。
 *         
 *         首先，该函数会根据需要丢弃无用的开头空格字符，直到寻找到第一个非空格的字符为止。
 *         当我们寻找到的第一个非空字符为正或者负号时，则将该符号与之后面尽可能多的连续数字组合起来，
 *         作为该整数的正负号；假如第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成整数。
 *         该字符串除了有效的整数部分之后也可能会存在多余的字符，这些字符可以被忽略，它们对于函数不应该造成影响。
 *         注意：假如该字符串中的第一个非空格字符不是一个有效整数字符、字符串为空或字符串仅包含空白字符时，则你的函数不需要进行转换。
 *         在任何情况下，若函数不能进行有效的转换时，请返回 0。
 * 
 *         假设我们的环境只能存储 32 位大小的有符号整数，那么其数值范围为 [−2^31,  2^(31 − 1)]。
 *         如果数值超过这个范围，请返回  INT_MAX (2^(31 − 1)) 或 INT_MIN (−2^31) 。
 * @考察类型 : 工程能力
 * @input : "42"
 * @output : 42
 */
class Solution {
typedef bool FLAG;
typedef int SYMBOL;
typedef long long INT64;
public:
    int strToInt(string str) {
        INT64 result = 0;
        FLAG sflag = false;
        FLAG flag = false;
        SYMBOL symbol = 1;

        for(auto ch : str){
            if((ch >= '0' && ch <= '9')||ch == '+' || ch == '-'){
                if(ch >= '0' && ch <= '9'){
                    flag = true;
                }
                if(ch == '+' || ch == '-'){
                    if(flag == false){
                        if(sflag == false){
                            flag = true;
                            if(ch == '-'){
                                symbol = -1;
                            }
                        }
                        else{
                            break;
                        }
                    }
                    else{
                        break;
                    }
                }
                else{
                    INT64 temp = result;
                    temp = temp * 10 + (ch - '0');
                    temp = temp * symbol;
                    if(temp > INT_MAX){
                        result = INT_MAX;
                        break;
                    }
                    if(temp < INT_MIN){
                        result = INT_MIN;
                        break;
                    }
                    result = result * 10 + (ch - '0');
                }
            }
            else if(ch == ' '){
                if(flag == false && sflag == false) continue;
                else break;
            }
            else{
                break;
            }
        }
        result = result * symbol;
        return result;
    }
};

/*========================================================================*/


/* 困难题目 */

/*
 * @题目 : 剑指offer 51
 * @要求 : 在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。
 * @考察类型 : 动态规化
 * @input : [7,5,6,4]
 * @output : 5
 */
class Solution {
public:
    int mergeSort(vector<int>& nums, vector<int>& tmp, int l, int r) {
        if (l >= r) {
            return 0;
        }

        int mid = (l + r) / 2;
        int inv_count = mergeSort(nums, tmp, l, mid) + mergeSort(nums, tmp, mid + 1, r);
        int i = l, j = mid + 1, pos = l;
        while (i <= mid && j <= r) {
            if (nums[i] <= nums[j]) {
                tmp[pos] = nums[i];
                ++i;
                inv_count += (j - (mid + 1));
            }
            else {
                tmp[pos] = nums[j];
                ++j;
            }
            ++pos;
        }
        for (int k = i; k <= mid; ++k) {
            tmp[pos++] = nums[k];
            inv_count += (j - (mid + 1));
        }
        for (int k = j; k <= r; ++k) {
            tmp[pos++] = nums[k];
        }
        copy(tmp.begin() + l, tmp.begin() + r + 1, nums.begin() + l);
        return inv_count;
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> tmp(n);
        return mergeSort(nums, tmp, 0, n - 1);
    }
};
