#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <stack>

using namespace std;

template<class T>
class TransparentStack : public stack<T> {
public:
  const T peek_at(int index) {
    return (stack<T>::c).at(index);
  }
};
#endif