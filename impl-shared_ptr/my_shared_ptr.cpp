#include <bits/stdc++.h>

template <typename T> class Shared_ptr {
public:
  Shared_ptr() : _counter(0), _ptr(nullptr) {}
  Shared_ptr(T *p) : _counter(new int(1)), _ptr(p) {}
  Shared_ptr(Shared_ptr<T> &sptr)
      : _counter(&(++*sptr._counter)), _ptr(sptr._ptr) {}

  T *operator->() { return _ptr; }
  T &operator*() { return *_ptr; }
  Shared_ptr<T> &operator=(Shared_ptr<T> &sptr) {
    ++sptr._counter;
    if (this->_ptr && 0 == --*this->_counter) {
      delete _counter;
      delete _ptr;
    }
    this->_ptr = sptr._ptr;
    this->_counter = sptr._counter;
    return *this;
  }

  ~Shared_ptr() {
    if (--*_counter == 0) {
      delete _counter;
      delete _ptr;
    }
  }

  friend std::ostream &operator<<(std::ostream &os, Shared_ptr<T> &sp) {
    os << "Address pointed : " << sp._counter << std::endl;
    std::cout << *(sp._counter) << std::endl;
  }

private:
  int *_counter;
  T *_ptr;
};

int main() {
  // ptr1 pointing to an integer.
  Shared_ptr<int> ptr1(new int(151));
  std::cout << "--- Shared pointers ptr1 ---\n";
  *ptr1 = 100;
  std::cout << " ptr1's value now: " << *ptr1 << std::endl;
  std::cout << ptr1;

  {
    // ptr2 pointing to same integer
    // which ptr1 is pointing to
    // Shared pointer reference counter
    // should have increased now to 2.
    Shared_ptr<int> ptr2 = ptr1;
    std::cout << "--- Shared pointers ptr1, ptr2 ---\n";
    std::cout << ptr1;
    std::cout << ptr2;

    {
      // ptr3 pointing to same integer
      // which ptr1 and ptr2 are pointing to.
      // Shared pointer reference counter
      // should have increased now to 3.
      Shared_ptr<int> ptr3(ptr2);
      std::cout << "--- Shared pointers ptr1, ptr2, ptr3 ---\n";
      std::cout << ptr1;
      std::cout << ptr2;
      std::cout << ptr3;
    }

    // ptr3 is out of scope.
    // It would have been destructed.
    // So shared pointer reference counter
    // should have decreased now to 2.
    std::cout << "--- Shared pointers ptr1, ptr2 ---\n";
    std::cout << ptr1;
    std::cout << ptr2;
  }

  // ptr2 is out of scope.
  // It would have been destructed.
  // So shared pointer reference counter
  // should have decreased now to 1.
  std::cout << "--- Shared pointers ptr1 ---\n";
  std::cout << ptr1;

  return 0;
}
