
#include <iostream>
#include <cassert>
#include "TransparentStack.h"

using namespace std;


void TestPeekAt(){
	cout << "Peek At Test..." << endl;

	TransparentStack<int> s;

	s.push(0);
	s.push(1);
	s.push(2);
	s.push(3);


	assert(s.peek_at(0) == 0);
	assert(s.peek_at(1) == 1);
	assert(s.peek_at(2) == 2);
	assert(s.peek_at(3) == 3);

	cout << "PASSED!" << endl << endl;
}

int main(){
	
	TestPeekAt();
	cout << "DONE!" << endl;
	return 0;
}
