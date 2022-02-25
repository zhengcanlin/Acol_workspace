/*
 * 这个文件存放的是字节跳动的笔试代码题 
 */


#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;
/*
 *  @题目要求：字符串S由小写字母构成，长度为n。定义一种操作，每次都可以挑选字符串中
 *    任意的两个相邻字母进行交换。询问在至多交换m次之后，字符串中最多有多少个连续的位
 *    置上的字母相同？
 *  @输入描述：第一行为一个字符串S与一个非负整数m。(1 <= |S| <= 1000, 1 <= m <= 1000000)
 */

#define N 26 

int dp(int first, int second, vector<int> index_of_alpha){
    if(first == second){
        return 0;
    }
    if((first + 1) == second){
        return index_of_alpha[second] - index_of_alpha[first] - 1;
    }
    else{
        return dp(first+1, second-1, index_of_alpha) + index_of_alpha[second] - index_of_alpha[first] - (second - first);
    }
}

int main(){
    string str;
    int num;
    cin>>str>>num;
    int length = str.length();

    int **pos = new int*[length];
    for(int i = 0; i < length; i++){
        pos[i] = new int[N];
    }
    for(int i = 0; i < length; i++){
        for(int j = 0; j < N; j++){
            pos[i][j] = 0;
        }
        pos[i][str[i] - 'a'] = 1;
    }
    int *result = new int[N];
    
    for(int j = 0; j < N; j++){
        int k;
        vector<int> index_of_alpha;
        for(int i = 0; i < length; i++){
            if(pos[i][j] == 1){
                k++;
                index_of_alpha.push_back(i);
            }
        }
        int temp = -1;
        for(int i = 0; i < k; i++){
            for(int ii = i+1; ii < k; ii++){
                int t = dp(i, ii, index_of_alpha);
                if(t <= num){
                    if((ii-i) + 1 > temp){
                        temp = (ii - i) + 1;
                    }
                }
            }
        }
        result[j] = temp;
    }
    sort(result, result + N);
    cout<<result[N - 1];
}
