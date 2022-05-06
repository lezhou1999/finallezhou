#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <stack>

using namespace std;

class TransparentStack : public stack<int> {
public:
  const int peek_at(int index);
};
#endif