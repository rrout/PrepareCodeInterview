#include "sheader.h"
#ifndef __LIST_H__
#define __LIST_H__
template <class T>
class node
{
public:
	T data;
	node *next;

	node(T dat){
		data = dat;
		next = nullptr;
	}
};

template <class T>
class list
{
private:
	node<T> *root;
	node<T> *end;
	node<T> *reverseNgroup(node<T> *root, int n);
public:
	list();
	~list();
	void insert(T data);
	void remove(T &data);
	void print();
	node<T> *get(T data);
	void reverse();
	void reverseNgroup(int n);
	int countelement();
};

#endif //__LIST_H__