#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    explicit ListNode(int x) : val(x), next(nullptr) {}
};

//反转链表
ListNode* reverseList(ListNode* head) {
    //两个额外空间，现在操作的节点和前一步操作的节点即向前节点反转后的的后置
    ListNode* cur = head;
    ListNode* pre = nullptr;
    while(cur != nullptr) {
        //存储下一个节点
        ListNode* follow = cur -> next;
        cur -> next = pre;
        pre = cur;
        cur = follow;
    }
    return pre;
}