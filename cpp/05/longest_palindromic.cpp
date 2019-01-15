//
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution{
    public:
        string longestPalindrome(string s) {
            int result = 0;
            int length = s.size();
            int begin = 0;
            int **matrix = new int*[length];
            for(int i = 0; i < length; i++){
                matrix[i] = new int[length];
            }
            for(int i = 0; i < length; i++){
                matrix[i][i] = 1;
                for(int j = i + 1; j < length; j++){
                    matrix[i][j] = 0;
                }
            }
            for(int i = 1; i < length; i++){
                if(s[i] == s[i-1]){
                    matrix[i-1][i] = 1;
                    result = 1;
                    begin = i-1;
                }
            }
            for(int i = length - 3; i >= 0; i--){
                for(int j = i + 2; j < length; j++){
                    if (matrix[i+1][j-1] && s[i]==s[j]){
                        matrix[i][j] = 1;
                        if(result < j - i){
                            begin = i;
                            result = j - i;
                        }
                    }
                }
            }
            string r(s, begin, result+1);
            for(int i = 0; i < length; i++){
                delete matrix[i];
            }
            delete matrix;
            return r;
        }
};

int main(){
    Solution solution1;
    string s("babad");
    string r = solution1.longestPalindrome(s);
    cout<< r<<endl;
    return 0;
}
