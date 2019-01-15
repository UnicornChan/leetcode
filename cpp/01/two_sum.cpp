//cost 40ms in leetcode
#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
using namespace std;
class Solution{
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int, int> hash_map;
            vector<int> result;
            for (int i = 0; i < nums.size(); i++){
                int temp = target - nums[i];
                if (hash_map.find(temp) == hash_map.end()){
                    hash_map.insert(make_pair(nums[i], i));
                } else {
                    result.push_back(hash_map[temp]);
                    result.push_back(i);
                    return result;
                }
            }
        }
};

int main(){
    Solution solution1;
    vector<int> ilist = {2,7,11,5};
    vector<int> x;
    x = solution1.twoSum(ilist, 9);
    for (int i = 0; i < x.size(); i++)cout<< x[i]<< endl;
    return 0;
}
