#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot) {
  // base case if head is null
  if (!head) {
    smaller = nullptr;
    larger = nullptr;
    return;
  }

  // hold the next Node
  Node* nextNode = head->next;

  // disconnect current node from list
  head->next = nullptr;

  if (!smaller) {
    smaller = nullptr;
  }
  if (!larger) {
    larger = nullptr;
  }

  // check if head is larger or smaller than pivot, then add to corresponding list
  if (head->val <= pivot) {
    smaller = head;
    llpivot(nextNode, smaller->next, larger, pivot);
  }
  else {
    larger = head;
    llpivot(nextNode, smaller, larger->next, pivot);
  }
  head = nullptr;
}
