/*leetcode */
#include<vector>
#include<string>
#include<map>
#include<stack>
#include<queue>
using namespace std;

// NO.51 // 
class Solution {
public:
    // 将该轮的结果插入到最终结果result之中
    void add_result(vector<vector<string>>& result, vector<int> temp_index, int n){
        vector<string> temp;
        for(int i = 0; i < n; i++){
            string input = "";
            for(int j = 0; j < n; j++){
                if(temp_index[i] != j){
                    input.append(".");
                }
                else{
                    input.append("Q");
                }
            }
            temp.push_back(input);
        }
        result.push_back(temp);
        return;
    }
    // 判断当前插入位置是否合理
    bool judge(vector<int> temp_index, int index){
        int len = temp_index.size();
        for(int j = 0; j < len; j++){
            // 判断是否处于同一列
            if(temp_index[j] == index){
                return false;
            }
            // 判断是否处于斜对角
            else if(abs(temp_index[j] - index) == abs(j - len)){
                return false;
            }
        }
        return true;
    }
    void DFSQueens(vector<vector<string>>& result, int n, int row, vector<int>& temp_index){
        // 先判断是否最后一行已经结束
        if(n == row){
            add_result(result, temp_index, n);
            return;
        }
        else{
            for(int i = 0; i < n; i++){
                // 判断当前插入位置是否合理
                if(judge(temp_index, i) == true){
                    temp_index.push_back(i);
                    DFSQueens(result, n, row+1, temp_index);
                    temp_index.pop_back();
                }
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        // temp_index向量存放当前递归中每一行中皇后的位置
        vector<int> temp_index;
        DFSQueens(result, n, 0, temp_index);
        // 递归调用函数DFSQueens
        return result;
    }

};




// NO.303 //


class NumArray {
private:
    vector<int> numarrays;
public:
    NumArray(vector<int>& nums) {
        numarrays = nums;
    }
    
    int sumRange(int i, int j) {
        int result = 0;
        for(int index = i; index <= j: index++){
            result += numarrays[index];
        }
        return result;
    }
};


// NO.290

class Solution {
public:
    // 先对s字符串按空格进行切分
    vector<string> split(string s) {
        vector<string> result;
        int len = s.length();
        string temp = "";
        for(int i = 0; i < len; i++){
            if(s[i] == ' '){
                result.push_back(temp);
                temp = "";
            }
            else{
                temp += s[i];
            }
        }
        result.push_back(temp);
        return result;
    }

    // 建设规则字典
    vector<char> pattern_dictionary(string pattern) {
        vector<char> result;
        map<char, int> temp;
        int lens = pattern.length();
        for(int i = 0; i < lens; i++) {
            if(temp[pattern[i]] == 0){
                result.push_back(pattern[i]);
                temp[pattern[i]] = 1;
            }
        }
        return result;
    }
    int word_types(vector<string> words){
        int result = 0;
        map<string, int> words_dictionary;
        for(auto str : words){
            if(words_dictionary[str] == 0){
                result++;
                words_dictionary[str] = 1;
            }
        }
        return result;
    }
    string transform(string pattern, string s) {
        string result = "";

        vector<string> words = split(s);
        vector<char> pattern_words = pattern_words(pattern);
        
        int lens_of_s = words.size();
        int sum_of_pattern = pattern_dictionary.size();
        int sum_of_s = word_types(words);
        map<string, char> dictionary;
        
        // 判断pattern的字符种类是否和s的词种类相同；不相同的情况下需要返回空
        if(sum_of_pattern != sum_of_s){
            return result;
        }

        int k = 0;
        for(int i = 0; i < lens_of_s; i++){
            // 如果当前词之前还未出现过，则将当前词转换为pattern词，并作标注在字典上
            if(dictionary.find(words[i]) == dictionary.end()){
                dictionary[words[i]] = pattern_words[k++];
                result += (dictionary[words[i]]);
            }
            else{
                result += (dictionary[words[i]]);
            }
        }
        return result;
    }
    bool wordPattern(string pattern, string s) {
        string transform_s = transform(pattern, s);
        return (transform_s == pattern);
    }
};


// NO.17

class Solution {
public:
    // 根据输入数字返回可能字符

    vector<char> number_to_char(char number) {
        vector<char> result;
        switch (number) {
        case '2':
            result.push_back('a');
            result.push_back('b');
            result.push_back('c');
            break;
        case '3':
            result.push_back('d');
            result.push_back('e');
            result.push_back('f');
            break;
        case '4':
            result.push_back('g');
            result.push_back('h');
            result.push_back('i');
            break;
        case '5':
            result.push_back('j');
            result.push_back('k');
            result.push_back('l');
            break;
        case '6':
            result.push_back('m');
            result.push_back('n');
            result.push_back('o');
            break;
        case '7':
            result.push_back('p');
            result.push_back('q');
            result.push_back('r');
            result.push_back('s');
            break;
        case '8':
            result.push_back('t');
            result.push_back('u');
            result.push_back('v');
            break;
        case '9':
            result.push_back('w');
            result.push_back('x');
            result.push_back('y');
            result.push_back('z');
            break;
        }
        return result;
    }
    queue<string> add_char(queue<string> letters, vector<char> chars) {
        queue<string> result;
        int lens = chars.size();

        // 如果是第一轮，则直接将chars插入到letters
        if (letters.empty() == true) {
            for (int i = 0; i < lens; i++) {
                string temp = "";
                temp = temp + chars[i];
                result.push(temp);
            }
        }
        else {
            while (!letters.empty()) {
                string temp_letter = letters.front();
                letters.pop();
                for (int i = 0; i < lens; i++) {
                    string temp = temp_letter + chars[i];
                    result.push(temp);
                }
            }
        }
        return result;
    }
    vector<string> queue_to_vector(queue<string> letters) {
        vector<string> result;
        string temp;
        while (!letters.empty()) {
            temp = letters.front();
            letters.pop();
            result.push_back(temp);
        }
        return result;
    }
    vector<string> letterCombinations(string digits) {
        queue<string> letters;
        vector<char> chars;
        int lens = digits.length();

        for (int i = 0; i < lens; i++) {
            chars = number_to_char(digits[i]);
            letters = add_char(letters, chars);
            chars.clear();
        }
        return queue_to_vector(letters);
    }
};


// NO.52
class Solution {
public:
    bool judge(vector<int> checkerboard, int index){
        int lens = checkerboard.size();
        for(int i = 0; i < lens; i++){
            if(checkerboard[i] == index){
                return false;
            }
            else if(abs(checkerboard[i] - index) == abs(lens - i)){
                return false;
            }
        }
        return true;
    }

    void DFSQueens(int n, int row, int& result, vector<int> checkerboard){
        if(row == n){
            result++;
            return;
        }
        else{
            for(int i = 0; i < n; i++){
                if(judge(checkerboard, i) == true){
                    checkerboard.push_back(i);
                    DFSQueens(n, row+1, result, checkerboard);
                    checkerboard.pop_back();
                }
            }
        }
    }
    int totalNQueens(int n) {
        int row = 0;
        int result = 0;
        vector<int> checkerboard;
        DFSQueens(n, row, result, checkerboard);
        return result;
    }
};

// NO.54
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<bool> inside(n, false);
        vector<vector<bool>> flag_matrix(m, inside);
        vector<int> result;
        // 1：towards the right
        // 2：downward
        // 3：towards the left
        // 4：upward
        int flag = 1;
        int lens = m * n;
        int i = 0;
        int j = 0;
        while(lens > 0){
            result.push_back(matrix[i][j]);
            flag_matrix[i][j] = true;
            if(flag == 1){
                if(j + 1 < n && flag_matrix[i][j+1] == false){
                    j++;
                }
                else if(i + 1 < m && flag_matrix[i+1][j] == false){
                    i++;
                    flag = 2;
                }
            }
            else if(flag == 2){
                if(i + 1 < m && flag_matrix[i+1][j] == false){
                    i++;
                }
                else if(j - 1 >= 0 && flag_matrix[i][j-1] == false){
                    j--;
                    flag = 3;
                }
            }
            else if(flag == 3){
                if(j - 1 >= 0 && flag_matrix[i][j-1] == false){
                    j--;
                }
                else if(i - 1 >= 0 && flag_matrix[i-1][j] == false){
                    i--;
                    flag = 4;
                }
            }
            else if(flag == 4){
                if(i - 1 >= 0 && flag_matrix[i-1][j] == false){
                    i--;
                }
                else if(j + 1 < n && flag_matrix[i][j+1] == false){
                    j++;
                    flag = 1;
                }
            }
            lens--;
        }
        return result;
    }
};

//NO.45
class Solution {
public:
    // 在当前位置能够跳到的范围内找寻最大的点
    int jump(vector<int>& nums) {
        int result = 0;
        int index = 0;
        // 当前位置
        int step = 0;
        // 当前位置能跳的最大步数
        while(index != nums.size() - 1){
            // 确定当前位置可以跳几步
            step = nums[index];


            if(index + step >= nums.size() - 1){
                index = nums.size() - 1;
                result++;
            }
            else{
                // 下一个最大跳跃步数的点的位置
                int next_index = index;
                int max_index = nums[index];
                int last = index + step;
                for(int i = index + 1; i <= last; i++){
                    if(nums[i] + i >= max_index + next_index){
                        max_index = nums[i];
                        next_index = i;
                    }
                }
                index = next_index;
                result++;
            }
        }
        return result;
    }
};

// NO.39
class Solution {
public:
    void DFSCombinationSum(vector<int>& candidates, int target, vector<vector<int>>& result, vector<int>& temp_result, int index){
        if(index == candidates.size()){
            return;
        }
        if(target == 0){
            result.push_back(temp_result);
            return;
        }
        DFSCombinationSum(candidates, target, result, temp_result, index + 1);
        if(target - candidates[index] >= 0){
            temp_result.push_back(candidates[index]);
            DFSCombinationSum(candidates,target - candidates[index], result, temp_result, index);
            temp_result.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp_result;
        DFSCombinationSum(candidates, target, result, temp_result, 0);
        return result;
    }
};

// NO.227
class Solution {
public:
    vector<string> split(string s) {
        vector<string> result;
        int lens = s.length();
        string temp = "";
        for (int i = 0; i < lens; i++) {
            if (s[i] == ' ') {
                continue;
            }
            if (s[i] >= '0' && s[i] <= '9') {
                temp += s[i];
            }
            else {
                result.push_back(temp);
                temp.clear();
                string input(1, s[i]);
                result.push_back(input);
            }
        }
        result.push_back(temp);
        return result;
    }
    int str_to_int(string number){
        int result = 0;
        int lens = number.length();
        for(int i = 0; i < lens; i++){
            result = (result * 10) + (number[i] - '0');
        }
        return result;
    }
    int calculate(string s) {
        stack<int> number;
        stack<char> symbol;
        vector<string> functions;
        functions = split(s);
        int lens = functions.size();
        // 先完成所有的乘除法
        for(int i = 0; i < lens; i++){
            // 先判断是为数还是为操作符
            if(functions[i] != "+" && functions[i] != "-" && functions[i] != "*" && functions[i] != "/"){
                int this_number = str_to_int(functions[i]);
                number.push(this_number);
            }
            else{
                if(functions[i] == "+" || functions[i] == "-"){
                    symbol.push(functions[i][0]);
                }
                else if(functions[i] == "*" || functions[i] == "/"){
                    int number1 = number.top();
                    number.pop();
                    int number2 = str_to_int(functions[i+1]);
                    if(functions[i] == "*"){
                        number.push(number1 * number2);
                    }
                    else{
                        number.push(number1 / number2);
                    }
                    i++;
                }
            }
        }
        stack<int> temp_number;
        
        while(number.empty() == false){
            temp_number.push(number.top());
            number.pop();
        }
        number = temp_number;
        
        stack<char> temp_symbol;
        while(symbol.empty() == false){
            temp_symbol.push(symbol.top());
            symbol.pop();
        }
        symbol = temp_symbol;

        while(symbol.empty() == false){
            int number1 = number.top();
            number.pop();
            int number2 = number.top();
            number.pop();
            if(symbol.top() == '+'){
                number.push(number1 + number2);
                symbol.pop();
            }
            else{
                number.push(number1 - number2);
                symbol.pop();
            }
        }
        return number.top();
    }
};

class Solution {
public:
    int calculate(string s) {
        vector<int> number;
        char symbol = '+';
        int lens = s.length();
        int num = 0;
        for (int i = 0; i < lens; i++) {
            if (isdigit(s[i])) {
                num = num * 10 + int(s[i] - '0');
            }
            if (isdigit(s[i]) == false && s[i] != ' ' || i == lens - 1) {
                switch (symbol)
                {
                case '+':
                    number.push_back(num);
                    break;
                case '-':
                    number.push_back(-num);
                    break;
                case '*':
                    number.back() *= num;
                    break;
                case '/':
                    number.back() /= num;
                }
                num = 0;
                symbol = s[i];
            }
        }
        return accumulate(number.begin(), number.end(), 0);
    }
};

// NO.125
class Solution {
public:
    vector<char> str_to_char(string s){
        vector<char> result;
        int lens = s.length();
        for(int i = 0; i < lens; i++){
            if(isdigit(s[i]) || isalpha(s[i])){
                if(s[i] >= 'A' && s[i] <= 'Z'){
                    s[i] = s[i] + 32;
                }
                result.push_back(s[i]);
            }
        }
        return result;
    }
    bool isPalindrome(string s) {
        vector<char> chars;
        chars = str_to_char(s);
        int left = 0;
        int right = chars.size() - 1;
        while(left < right){
            if(chars[left] != chars[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};


// NO.155
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        vector<int> my_stack;
    }
    
    void push(int x) {
        my_stack.push_back(x);
    }
    
    void pop() {
        my_stack.pop_back();
    }
    
    int top() {
        return my_stack.back();
    }
    
    int getMin() {
        if(my_stack.size() == 0){
            return NULL;
        }
        else{
            int result = my_stack[0];
            int lens = my_stack.size();
            for(int i = 0; i < lens; i++){
                if(result > my_stack[i]){
                    result = my_stack[i];
                }
            }
            return result;
        }
    }
};

// NO.1266
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int x1, y1;
        int result = 0;
        int x2, y2;
        x1 = points[0][0];
        y1 = points[0][1];
        for(int i = 1; i < points.size(); i++){
            x2 = points[i][0];
            y2 = points[i][1];
            result += max(abs(x1 - x2), abs(y1 - y2));
            x1 = x2;
            y1 = y2;
        }
        return result;
    }
};

// NO.1128
class Solution {
public:
    vector<int> Count_of_same_dominoe(vector<vector<int>> dominoes){
        vector<int> result;
        vector<vector<int>> temp_dominoes = dominoes;
        int lens = temp_dominoes.size();
        // 所有的多米诺对都转化为小数在前，大数在后
        for(int i = 0; i < lens; i++){
            if(temp_dominoes[i][0] > temp_dominoes[i][1]){
                int temp = temp_dominoes[i][0];
                temp_dominoes[i][0] = temp_dominoes[i][1];
                temp_dominoes[i][1] = temp;
            }
        }
        sort(temp_dominoes.begin(), temp_dominoes.end());
        int count = 1;
        vector<int> this_dominoe = temp_dominoes[0];
        for(int i = 1; i < lens; i++){
            if(this_dominoe == temp_dominoes[i]){
                count++;
            }
            else{
                result.push_back(count);
                count = 1;
                this_dominoe = temp_dominoes[i];
            }
            if(i == lens - 1){
                result.push_back(count);
            }
        }
        return result;
    }
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int result = 0;
        vector<int> sum_of_each_card;
        sum_of_each_card = Count_of_same_dominoe(dominoes);
        int lens = sum_of_each_card.size();
        for(int i = 0; i < lens; i++){
            int sum = 1;
            for(int j = sum_of_each_card[i]; j > sum_of_each_card[i] - 2; j--){
                sum *= j;
            }
            sum = sum / 2;
            result += sum;
        }
        return result;
    }
};

// NO.1221
class Solution {
public:
    int balancedStringSplit(string s) {
        int result = 1;
        int countR = 0;
        int countL = 0;
        int lens = s.length();
        for(int i = 0; i < lens; i++){
            if(countR > 0 && countL > 0 && countR == countL){
                countR = 0;
                countL = 0;
                result++;
            }
            if(s[i] == 'R'){
                countR++;
            }
            if(s[i] == 'L'){
                countL++;
            }
        }
        return result;
    }
};


// NO.728
class Solution {
public:
    bool judge(int number) {
        if (number >= 1 && number <= 9) {
            return true;
        }
        int temp = number;
        int factor;
        while (temp > 0) {
            factor = temp % 10;
            temp /= 10;
            if (factor == 0) {
                return false;
            }
            else if(number % factor != 0) {
                return false;
            }
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;
        for (int i = left; i <= right; i++) {
            if (judge(i) == true) {
                result.push_back(i);
            }
        }
        return result;
    }
};

// NO.1491
class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin(), salary.end());
        int sum = 0;
        int lens = salary.size();
        for(int i = 1; i < lens - 1; i++){
            sum += salary[i];
        }
        return sum / (lens - 2);
    }
};

// NO.1232
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int x1 = coordinates[0][0];
        int y1 = coordinates[0][1];
        int x2 = coordinates[1][0];
        int y2 = coordinates[1][1];
        double k, b;
        // flag = 1：夹角不为90、270
        // flag = 2：夹角为90、270

        int flag = 1;

        if((x2 - x1) == 0){
            flag = 2;
        }
        else{
            k = double(y2 - y1) / double(x2 - x1);
            b = double(y1) - double(k * x1);
        }
        int lens = coordinates.size();
        for(int i = 2; i < lens; i++){
            x1 = coordinates[i][0];
            y1 = coordinates[i][1];
            if(flag == 1){
                if(y1 != (k * x1) + b){
                    return false;
                }
            }
            else if(flag == 2 && x1 != coordinates[0][0]){
                 return false;
            }
        }
        return true;
    }
};

// NO.94
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
    void DFS(TreeNode* root, vector<int>& result) {
        if (root == NULL) {
            return;
        }
        else {
            DFS(root->left, result);
            result.push_back(root->val);
            DFS(root->right, result);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        DFS(root, result);
        return result;
    }
};



// NO.12
class Solution {
public:
    string exchange(int num, int flag) {
        string result = "";
        vector<vector<char>> dictionary = { {'X', 'V', 'I'}, {'C', 'L', 'X'}, {'M', 'D', 'C'} };
        if (flag == 3) {
            for (int i = 1; i <= num; i++) {
                result += dictionary[2][0];
            }
        }
        else {
            if (num == 9) {
                result += dictionary[flag][2];
                result += dictionary[flag][0];
            }
            else if (num >= 5 && num <= 8) {
                result = dictionary[flag][1];
                for (int i = 6; i <= num; i++) {
                    result += dictionary[flag][2];
                }
            }
            else if (num == 4) {
                result += dictionary[flag][2];
                result += dictionary[flag][1];
            }
            else if (num > 0 && num < 4) {
                for (int i = 1; i <= num; i++) {
                    result += dictionary[flag][2];
                }
            }
        }
        return result;
    }
    string intToRoman(int num) {
        string result = "";
        int flag = 0;
        while (num > 0) {
            result = exchange(num % 10, flag) + result;
            num = num / 10;
            flag++;
        }
        return result;
    }
};

// NO.40
class Solution {
public:
    bool judge(vector<vector<int>> results, vector<int> temp_result) {
        for (int i = 0; i < results.size(); i++) {
            if (results[i] == temp_result) {
                return false;
            }
        }
        return true;
    }
    void DFS(vector<int> candidates, int target, vector<bool> visited, vector<vector<int>>& result, vector<int> temp_result, int count, int index) {
        if (count == target && judge(result, temp_result)) {
            result.push_back(temp_result);
            return;
        }
        else {
            if (count > target) {
                return;
            }
            else {
                for (int i = index; i < candidates.size(); i++) {
                    if (visited[i] == false) {
                        visited[i] = true;
                        temp_result.push_back(candidates[i]);
                        count += candidates[i];
                        DFS(candidates, target, visited, result, temp_result, count, i + 1);
                        temp_result.pop_back();
                        count -= candidates[i];
                        visited[i] = false;
                    }
                }
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp_result;
        int count = 0;
        int lens = candidates.size();
        vector<bool> visited(lens, false);
        sort(candidates.begin(), candidates.end());
        DFS(candidates, target, visited, result, temp_result, count, 0);
        return result;
    }
};
class Solution {
private:
    vector<pair<int, int>> freq;
    vector<vector<int>> ans;
    vector<int> sequence;

public:
    void dfs(int pos, int rest) {
        if (rest == 0) {
            ans.push_back(sequence);
            return;
        }
        if (pos == freq.size() || rest < freq[pos].first) {
            return;
        }

        dfs(pos + 1, rest);

        int most = min(rest / freq[pos].first, freq[pos].second);
        for (int i = 1; i <= most; ++i) {
            sequence.push_back(freq[pos].first);
            dfs(pos + 1, rest - i * freq[pos].first);
        }
        for (int i = 1; i <= most; ++i) {
            sequence.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        for (int num: candidates) {
            if (freq.empty() || num != freq.back().first) {
                freq.emplace_back(num, 1);
            } else {
                ++freq.back().second;
            }
        }
        dfs(0, target);
        return ans;
    }
};

// NO.30
class Solution {
public:

    bool judge(map<string, int> dictionarys, string target, int word_size) {
        bool result = true;
        for (int i = 0; i < (target.length() / word_size); i++) {
            string word = target.substr(i * word_size, word_size);
            if (dictionarys.find(word) == dictionarys.end()) {
                result = false;
                return result;
            }
            else {
                dictionarys[word]--;
            }
        }
        map<string, int>::iterator item;
        for (item = dictionarys.begin(); item != dictionarys.end(); item++) {
            if (item->second != 0) {
                result = false;
                break;
            }
        }
        return result;
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        // 制作字典，用于做比对
        map<string, int> dictionarys;
        for (int i = 0; i < words.size(); i++) {
            dictionarys[words[i]]++;
        }

        //
        int combination_word_size = words.size() * words[0].length();
        string substring = "";
        int len = s.length() - combination_word_size;
        for (int i = 0; i <= len; i++) {
            substring = s.substr(i, combination_word_size);
            if (judge(dictionarys, substring, words[0].length()) == true) {
                result.push_back(i);
            }
        }
        return result;

    }
};


// NO.551

class Solution {
public:
    bool checkRecord(string s) {
        int flag1 = 0;
        int flag2 = 0;
        int len = s.size();
        int A_count = 0;
        int L_count = 0;
        for(int i = 0; i < len; i++){
            if(s[i] == 'A'){
                A_count++;
            }
            if(s[i] == 'L'){
                L_count++;
                if(L_count >= 3){
                    flag2 = 1;
                }
            }
            else{
                L_count = 0;
            }
        } 
        if(A_count >= 2){
            flag1 = 1;
        }
        if(flag1 == 0 && flag2 == 0){
            return true;
        }
        else{
            return false;
        }
    }
};

// No.300
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        vector<int> Long_LIS(len, 0);
        int result = 0;
        for(int i = 0; i < len; i++){
            Long_LIS[i] = 1;
            for(int j = 0; j < i;j++){
                if(nums[j] < nums[i]){
                    Long_LIS[i] = max(Long_LIS[i], Long_LIS[j] + 1);
                }
            }
            if(Long_LIS[i] > result){
                result = Long_LIS[i];
            }
        }
        return result;
    }
};

// No.114
class Solution {
public:
    void DFS(TreeNode* root, vector<TreeNode*>& nodes){
        if(root == NULL){
            return;
        }
        nodes.push_back(root);
        DFS(root->left, nodes);
        DFS(root->right, nodes);
    }

    void flatten(TreeNode* root) {
        vector<TreeNode*> nodes;
        DFS(root, nodes);
        for(int i = 1; i < nodes.size(); i++){
            TreeNode* p = nodes[i-1];
            TreeNode* q = nodes[i];
            p->left = NULL;
            p->right = q;
        }
    }
};

// NO.508
class Solution {
public:
    int DFS(TreeNode* root, map<int, int>& dictionarys){
        if(root == NULL){
            return 0;
        }
        int sum = 0;
        sum += DFS(root->left, dictionarys);
        sum += DFS(root->right, dictionarys);
        if(dictionarys.count(sum + root->val) == 0){
            dictionarys[sum + root->val] = 1;
        }
        else{
            dictionarys[sum + root->val]++;
        }
        return sum + root->val;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        map<int, int> dictionarys;
        int sum = DFS(root, dictionarys);

        map<int, int>::iterator item = dictionarys.begin();
        int max_key = item->first;
        while(item != dictionarys.end()){
            if(item->second > dictionarys[max_key]){
                max_key = item->first;
            }
            item++;
        }   

        vector<int> result;
        result.push_back(max_key);
        item = dictionarys.begin();
        while(item != dictionarys.end()){
            if(item->first != max_key && item->second == dictionarys[max_key]){
                result.push_back(item->first);
            }
            item++;
        }   
        return result;
    }
};