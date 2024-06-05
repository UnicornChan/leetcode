/**
 * @Description  :  
 * @Author       : chenxl
 * @Date         : 2024-06-05 23:22:55
 * @Version      : 1.0.0
 * @LastEditors  : chenxl 
 * @LastEditTime : 2024-06-05 23:22:55
**/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution{
    public:
        int maxArea(vector<int>& height) {
            if(height.size()<1) return 0;
            int begin = 0;
            int end = height.size() - 1;
            int result = 0;
            int min = 0;
            while(begin < end){
                if(height[begin] > height[end]){
                    min = height[end];
                    end--;
                } else {
                    min = height[begin];
                    begin++;
                }
                result = (result < (min * (end-begin+1))) ? (min*(end-begin+1)) : result;
            }
            return result;
        }
};

int main(){
    Solution solution;
    int a[9] = {1,8,6,2,5,4,8,3,7};
    vector<int> height(a,a+9);
    cout<<solution.maxArea(height)<<endl;
    return 0;
}
