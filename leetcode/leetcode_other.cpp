#include<iostream>
#include<vector>
#include<map>
#include<string>

using namespace std;

/* 简单题目 */

/*
题号 ：917
要求 ：给你一个字符串 s ，根据下述规则反转字符串：
      所有非英文字母保留在原有位置。
      所有英文字母（小写或大写）位置反转。
      返回反转后的 s 。
 */
class Solution {
public:
    bool checkchar(char input){
        if((input >= 'a' && input <= 'z') || (input >= 'A' && input <= 'Z')){
            return true;
        }
        else{
            return false;
        }
    }
    
    string reverseOnlyLetters(string s) {
        string result = s;
        int left = 0;
        int right = s.length() - 1;

        while(left < right){
            if(this->checkchar(result[left]) == true && this->checkchar(result[right]) == true){
                char temp = result[left];
                result[left] = result[right];
                result[right] = temp;
                left++;
                right--;
            }
            else{
                if(this->checkchar(result[left]) == false){
                    left++;
                }
                if(this->checkchar(result[right]) == false){
                    right--;
                }
            }
        }
        return result;
    }
};