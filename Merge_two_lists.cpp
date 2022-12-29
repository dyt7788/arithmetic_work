#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//使用递归
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==nullptr){//临界情况
            return list2;
        }
        else if(list2==nullptr){
            return list1;
        }
        else if (list1->val<list2->val)//1的数字小于2 
        {
            /* code */
            list1->next=mergeTwoLists(list1->next,list2);
            return list1;
        }
        else{
            list2->next=mergeTwoLists(list1,list2->next);
            return list2;
        }
}
int main()
{


}
