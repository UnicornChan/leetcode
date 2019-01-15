//
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution{
    public:
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
    Solution solution1;
    string s("PAYPALISHIRING");
    int s_c;
    s_c = solution1.reverse(100000);
    cout<<s_c<<endl;
    return 0;
}
