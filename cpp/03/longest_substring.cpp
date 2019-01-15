//cost 40ms in leetcode
#include<iostream>
#include<string>
using namespace std;
class Solution{
    public:
        int lengthOfLongestSubstring(string s) {
        int result = 0;
        int char_list[128];
        for (int i = 0; i < 128; i++){
            char_list[i] = 0;
        }   
        int x = 1;
        for (int i = 0; i < s.length(); i++){
            int char_sequence = int(s[i]);
            if(char_list[char_sequence]){
                if (result < (x - 1)){
                    result = x - 1;
                }   
                int y = char_list[char_sequence];
                for (int j = 0; j < 128; j++){
                    char_list[j] = char_list[j] - y;
                    if (char_list[j] < 0){ 
                        char_list[j] = 0;
                    }   
                }   
                char_list[char_sequence] = x - y;
                x = x - y + 1;
            } else {
                char_list[char_sequence] = x;
                x += 1;                
            }
        }
        if (result < (x - 1)){
            result = x - 1;
        }
        return result;
    }
};

int main(){
    Solution solution1;
    string s("abcd");
    int x=0;
    x = solution1.lengthOfLongestSubstring(s);
    cout << x << endl;
    return 0;
}
