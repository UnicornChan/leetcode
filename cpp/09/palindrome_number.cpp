//use solution of 07, if reverse == origin ,return true;
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution{
    public:
        bool isPalindrome(int x) {
            if(x < 0) return false;
            int y = reverse(x);
            if(y == x) return true;
            return false;
        }
        int reverse(int x) {
            int result = 0;
            while(x){
                int temp = result * 10 + x % 10;
                if (temp / 10 != result) return 0;
                x = x / 10;
                result = temp;
            }
            return result;
        }
};

int main(){
    return 0;
}
