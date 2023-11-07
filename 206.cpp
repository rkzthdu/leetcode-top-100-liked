/*
  反转链表
*/


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return head;
        } else if(head->next->next == nullptr) {
            ListNode* tmp = head->next;
            head->next->next = head;
            head->next = nullptr;
            return tmp;
        }
        ListNode *first, *second, *third;
        first = head;
        second = first->next;
        third = second->next;
        first->next = nullptr;
        while(third != nullptr) {
            second->next = first;
            first = second;
            second = third;
            third = third->next;
        }
        second->next = first;
        return second;
    }
};



/*
  递归做法
*/

class Solution2 {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
};
