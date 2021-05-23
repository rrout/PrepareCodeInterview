#include "list.h"

template <class T>
list<T>::list() {
	root = nullptr;
	end = nullptr;
}
template <class T>
list<T>::~list() {
	node<T> *p = nullptr;
	while(root) {
		p = root;
		root = root->next;
		std::cout << "Freeing " << p->data << std::endl;
		free(p);
	}
}
template <class T>
void list<T>::insert(T data){
	node<T> *elem = new node<T>(data);
	//std::cout << elem->data << " ";
	node<T> *p, *q;
	if(!root) {
		root = elem;
	} else {
		p = root;
		if (data < p->data) {
			elem->next = root;
			root = elem;
			return;
		}
		while (p) {
			if(data < p->data) {
				elem->next = p;
				q->next = elem;
				return;
			}
			q = p;
			p = p->next;
		}
		q->next = elem;
	}
}
template <class T>
void list<T>::remove(T &data){

}
template <class T>
void list<T>::print(){
	std::cout << "List count :  " << countelement() << std::endl;
	if(root) {
		node<T> *p = root;
		while (p) {
			std::cout << "[" << p->data << "]--> ";
			p = p->next;
		}
		std::cout << "[NULL]" << std::endl;
	} else {
		std::cout << "List is empty....." << std::endl;
	}
	std::cout << std::endl;
}
template <class T>
node<T> * list<T>::get(T data){
	node<T> *p = root;
	if (root) {
		while(p) {
			if(p->data == data) {
				return p;
			}
			p = p->next;
		}
	} else {
		std::cout << "List is empty....." << std::endl;
	}
	return nullptr;
}
template <class T>
int list<T>::countelement(){
	int count = 0;
	node<T> *p = root;
	while(p) {
		count++;
		p = p->next;
	}
	return count;
}
template <class T>
void list<T>::reverse(){
	node<T> *p = root, *q, *r = nullptr;
	if (root) {
		while(p) {
			q = p;
			p = p->next;
			q->next = r;
			r = q;
		}
		root = r;
	} else {
		std::cout << "List is empty....." << std::endl;
	}
}
template <class T>
node<T> * list<T>::reverseNgroup(node<T> *root, int n){
	node<T> *p = root, *q, *r = nullptr;
	int count = 0;
	while(p && count < n) {
		q = p;
		p = p->next;
		q->next = r;
		r = q;
		count++;
	}
	if(p)
		root->next = reverseNgroup(p, n);
	return q;
}
template <class T>
void list<T>::reverseNgroup(int n){
	root = reverseNgroup(root, n);
}













//https://bytefreaks.net/programming-2/c/c-undefined-reference-to-templated-class-function
//Explicitly instantiate the template
template class list<int>;
template class list<std::string>;


/*
https://www.cs.technion.ac.il/users/yechiel/c++-faq/separate-template-class-defn-from-decl.html
https://www.reddit.com/r/cpp_questions/comments/i2u4tt/linker_error_when_using_templates/
https://www.codeproject.com/Articles/48575/How-to-Define-a-Template-Class-in-a-h-File-and-Imp
https://bytefreaks.net/programming-2/c/c-undefined-reference-to-templated-class-function
*/