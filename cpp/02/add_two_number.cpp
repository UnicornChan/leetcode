//cost 40ms in leetcode
#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
using namespace std;

struct ListNode{
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
class Solution{
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode *node = NULL;
            ListNode *node1 = NULL;
            int carry = 0;
            int b = 1;
            while(l1 || l2 || carry){
                int sum = ((l1 != NULL) ? l1->val:0) + ((l2 != NULL) ? l2->val : 0) + carry;
                if(l1 != NULL) l1 = l1->next;
                if(l2 != NULL) l2 = l2->next;
                carry = sum / 10;
                sum = sum % 10;
                if(b){
                    node = new ListNode(sum);
                    node1 = node;
                    b = 0;
                } else {
                    node->next = new ListNode(sum);
                    node = node->next;
                }
            }
            return node1;
        }
};

int main(){
    Solution solution1;
    ListNode *x = NULL;
    ListNode *l1 = new ListNode(9);
    ListNode *l2 = new ListNode(8);
    x = solution1.addTwoNumbers(l1,l2);
    while(x != NULL) {cout<< x->val; x = x -> next;}
    cout<<endl;
    return 0;
}
