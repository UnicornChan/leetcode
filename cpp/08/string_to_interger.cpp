//
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution{
    public:
        int myAtoi(string str) {
            int n = 0;
            long result = 0;
            while(str[n] == ' ' && n < str.length()) n++;
            int sign = 1;
            if(n < str.length() && (str[n] == '-' || str[n] == '+')){
                if(str[n] == '-') sign = -1;
                n = n + 1;
            }
            while(n < str.length() && int(str[n]) > 47 && int(str[n]) < 58){
                if(sign == 1){
                    if((result * 10 + (str[n] - 48)) > 2147483646) {
                        return 2147483647;
                    } else {
                        result = result * 10 + (str[n] - 48);
                    }
                } else {
                    if((result * 10 + (str[n] - 48)) > 2147483647){
                        return -2147483648;
                    } else {
                        result = result * 10 + (str[n] - 48);
                    }
                }
                n = n+1;
            }
            return int(result * sign);
        }
};

int main(){
    Solution solution;
    string str = "-6147483648";
    int x = solution.myAtoi(str);
    cout<<x<<endl;
    return 0;
}
