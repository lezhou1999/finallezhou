#ifndef LINKED_LIST_H
#define LINKED_LIST_H


#include <cstddef>
#include <iostream>

using namespace std;

template <typename T> 
struct Node{
	T data;
	Node *prev = nullptr;
	Node *next = nullptr;
};

template <typename T> 
class LinkedList {

	public:
		LinkedList() {
			head = nullptr;
			tail = nullptr;
			numItems = 0;
		}
		~LinkedList() {
			if (head == nullptr) {
					return;
			}

			Node<T>* cur = head;
			while (cur != nullptr) {
				Node<T>* tmp = cur;
				cur = tmp->next;
				delete tmp;
			}

			head = nullptr;
			tail = nullptr;
		}

		void push_back(T item){
			Node<T> *n = new Node<T>;
			n->data = item;
			numItems++;
			
			if(head == nullptr){
				head = n;
				tail = n;
				return;
			}

			tail->next = n;
			n->prev = tail;
			tail = n;	
		}

		void push_front(T item){
			Node<T> *n = new Node<T>;
			n->data = item;
			numItems++;

			if(head == nullptr){
				head = n;
				tail = n;
				return;
			}

			head->prev = n;
			n->next = head;
			head = n;
		}

		void insert(size_t pos, T item) {
			if (pos == 0) {
				push_front(item);
				return;
			}

			if (pos == numItems) {
				push_back(item);
				return;
			}

			Node<T> *n = new Node<T>;
			n->data = item;

			Node<T>* pre = head;
			while (pos - 1 > 0) {
				pre = pre->next;
				pos--;
			}

			n->next = pre->next;
			pre->next = n;
			n->prev = pre;

			if (n->next != nullptr) {
				n->next->prev = n;
			}
			numItems++;
		}

		T at(size_t idx){
			if(idx >= numItems){
				throw std::invalid_argument("List index out of range: " + std::to_string(idx));
			}

			Node<T> *n = get_node(idx);
			return n->data;
		}

		size_t size() { return numItems; };


	private:
		Node<T> *head;
		Node<T> *tail;
		size_t numItems;

		Node<T> *get_node(size_t idx){

			size_t i = 0;
			Node<T> *cur = head;
			while(i < idx){
				cur = cur->next;
				i++;
			}

			return cur;
		}
}; 




#endif