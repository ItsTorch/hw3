#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot) {
  // base case if head is null
  if (!head) {
    return;
  }

  // hold the next Node
  Node* nextNode = head->next;

  // check if head is larger or smaller than pivot, then add to corresponding list
  if (head->val <= pivot) {
    head->next = smaller;
    smaller = head;
  }
  else {
    head->next = larger;
    larger = head;
  }

  // remove head from linked list
  head = NULL;

  //recursive case
  llpivot(nextNode, smaller, larger, pivot);

}
