/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *curr = new ListNode();
    auto head      = curr;
    auto head1     = l1;
    auto head2     = l2;

    int carry = 0;

    while (head1 || head2) {
      int sum = 0;

      if (head1) {
        sum += head1->val;
        head1 = head1->next;
      }

      if (head2) {
        sum += head2->val;
        head2 = head2->next;
      }

      sum += carry;
      carry = sum / 10;

      curr->val = sum % 10;
      ListNode *temp = new ListNode();

      if (head1 || head2) {
        curr->next = temp;
        curr = curr->next;
      }
    }

    if (carry > 0)
      curr->next = new ListNode(carry);

    return head;
  }
};