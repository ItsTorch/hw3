#include <iostream>
#include <functional>
#include "heap.h"

using namespace std;

int main() {
  // test min-heap, already m = 2
  Heap<int> minHeap;
  minHeap.push(3);
  minHeap.push(7);
  minHeap.push(10);
  minHeap.push(1);

  cout << "min-heap m = 2: " << endl;
  while (!minHeap.empty()) {
    cout << minHeap.top() << " ";
    minHeap.pop();
  }
  cout << endl << endl;

  // test min-heap, m = 3
  Heap<int> minHeap3(3);
  minHeap3.push(15);
  minHeap3.push(3);
  minHeap3.push(8);
  minHeap3.push(1);
  minHeap3.push(27);

  cout << "min-heap m = 3: " << endl;
  while (!minHeap3.empty()) {
    cout << minHeap3.top() << " ";
    minHeap3.pop();
  }
  cout << endl << endl;

  // test max-heap
  Heap<int, std::greater<int>> maxHeap;
  maxHeap.push(6);
  maxHeap.push(3);
  maxHeap.push(21);
  maxHeap.push(2);

  cout << "max-heap m = 2: " << endl;
  while (!maxHeap.empty()) {
    cout << maxHeap.top() << " ";
    maxHeap.pop();
  }
  cout << endl << endl;

  // test string min-heap
  Heap<string> stringMinHeap;
  stringMinHeap.push("blue");
  stringMinHeap.push("green");
  stringMinHeap.push("yellow");
  stringMinHeap.push("red");

  cout << "string min-heap: " << endl;
  while (!stringMinHeap.empty()) {
    cout << stringMinHeap.top() << " ";
    stringMinHeap.pop();
  }
  cout << endl << endl;

  return 0;
}