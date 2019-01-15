//cost 28ms in leetcode
#include<iostream>
#include<string>
using namespace std;
class Solution{
    public:
        int lengthOfLongestSubstring(string s) {
        int result = 0;
        int char_list[128];
        for (int i = 0; i < 128; i++){
            char_list[i] = -1;
        }
        int left = 0;
        for (int i = 0; i < s.length(); i++){
            if(char_list[int(s[i])] >= left){
                left = char_list[int(s[i])] + 1;
            }
            char_list[int(s[i])] = i;
            if (result < (i - left + 1)){
                result = i - left + 1;
            }
        }
        return result;
    }
};

int main(){
    Solution solution1;
    string s("aacd");
    int x=0;
    x = solution1.lengthOfLongestSubstring(s);
    cout << x << endl;
    return 0;
}
