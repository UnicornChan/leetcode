//
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution{
    public:
        string convert(string s, int numRows) {
            int lenth = s.length();
            string s_c(lenth, '0');
            int i = 0;
            if (numRows == 1){
                return s;
            } else {
                int c_index = 0;
                for (int i = 0; i < numRows; i++){
                    int index = i;
                    if(i == numRows - 1 || i == 0){
                        while(index < lenth){
                            s_c[c_index++] = s[index];
                            index = index + (numRows * 2) - 2;
                        }
                    } else {
                        while(index < lenth){
                            s_c[c_index++] = s[index];
                            index = index + (numRows - i - 1) * 2;
                            if (index < lenth){
                                s_c[c_index++] = s[index];
                                index = index + 2 * i;
                            }
                        }
                    }
                }
                return s_c;
            }
        }
};

int main(){
    Solution solution1;
    string s("PAYPALISHIRING");
    string s_c;
    s_c = solution1.convert(s, 3);
    cout<<s_c<<endl;
    return 0;
}
