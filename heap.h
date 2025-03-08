#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  void heapify(size_t idx);
  void trickleUp(size_t idx);
  size_t parent(size_t idx) const {
    return (idx - 1) / m_;
  }
  size_t child(size_t idx, size_t k) {
    return m_ * idx + k + 1;
  }

  std::vector<T> data_;
  int m_;
  PComparator comp_;
};

// Add implementation of member functions here
// constructor
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c) : m_(m), comp_(c) {}

// destructor
template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap() {}

// push, also keeps heapness by calling trickleUp on new item pushed
template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T &item) {
  data_.push_back(item);
  trickleUp(data_.size() - 1);
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("empty heap");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return data_[0];
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("empty heap");
  }
  std::swap(data_[0], data_.back());
  data_.pop_back();
  // to keep heapness
  heapify(0);
}

// empty
template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const {
  return data_.empty();
}

// size
template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const {
  return data_.size();
}

// trickle up helper function
template <typename T, typename PComparator>
void Heap<T, PComparator>::trickleUp(size_t idx) {
  
  // keeps swapping with its parent up the tree until it is worse than its parent
  while (idx > 0 && comp_(data_[idx], data_[parent(idx)])) {
    std::swap(data_[idx], data_[parent(idx)]);
    idx = parent(idx);
  }
}

// heapify helper function
template <typename T, typename PComparator>
void Heap<T, PComparator>::heapify(size_t idx) {
  
  // checks for best child to swap with parent to push item down the tree
  size_t best = idx;
  for (size_t k = 0; k < (size_t)m_; ++k) {
    size_t c = child(idx, k);
    if (c < data_.size() && comp_(data_[c], data_[best])) {
      best = c;
    }
  }

  // heapify done recursively down the tree
  if (best != idx) {
    std::swap(data_[idx], data_[best]);
    heapify(best);
  }
}

#endif

