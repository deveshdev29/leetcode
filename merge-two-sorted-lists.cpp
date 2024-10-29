#include <iostream>
using namespace std;

struct ListNode{
    int data;
    ListNode* next;

    ListNode(int value){
        data = value;
        next = nullptr;
    }
};

class Solution{
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
        ListNode dummy(0);
        ListNode* current = &dummy;

        while(list1 && list2){
            if(list1->data >= list2->data){
                current->next = list2;
                list2 = list2->next;
            }else{
                current->next = list1;
                list1 = list1->next;
            }
            current = current->next;
        }

        current->next = list1 ? list1 : list2;

        return dummy.next;
    }
};

int main(){

    Solution sol;

    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(5);

    ListNode* mergedList = sol.mergeTwoLists(list1, list2);

    ListNode* temp = mergedList;
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return 0;
}