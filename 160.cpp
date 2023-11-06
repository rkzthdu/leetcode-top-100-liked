/*
  相交链表
*/


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr) {
            return nullptr;
        }
        ListNode *ptr1 = headA, *ptr2;
        while(ptr1 != nullptr) {
            ptr2 = headB;
            while(ptr2 != nullptr) {
                if(ptr1 == ptr2) {
                    return ptr1;
                } else {
                    ptr2 = ptr2->next;
                }
            }
            ptr1 = ptr1->next;
        }
        return nullptr;
    }
};




/*
  哈希表解法
*/

class officialSolution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode *> visited;
        ListNode *temp = headA;
        while (temp != nullptr) {
            visited.insert(temp);
            temp = temp->next;
        }
        temp = headB;
        while (temp != nullptr) {
            if (visited.count(temp)) {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }
};



/*
  双指针解法，非常巧妙，关键点在于如何消除两个链表的长度差
  如果知道两个链表的长度差，则可以“对齐”双指针进行对比！
*/

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }
        ListNode *pA = headA, *pB = headB;
        while (pA != pB) {
            pA = pA == nullptr ? headB : pA->next;
            pB = pB == nullptr ? headA : pB->next;
        }
        return pA;
    }
};
