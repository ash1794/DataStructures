#ifndef ____MAX__HEAP____
#define ____MAX__HEAP____

#include<vector>
#include<iostream>
#include<cstdlib>

using namespace std;

template<class T>
class Max_heap
{

private:
	vector<T> data;
	size_t heap_size;
public:
	Max_heap(typename vector<T>::iterator v_begin,typename vector<T>::iterator v_end);
	Max_heap(vector<T> v);
	Max_heap():heap_size(0)
	{
		data.push_back(0);
	}
	
	void make_heap();
	void heapify_down(size_t index);
	void heapify_up(size_t index);

	void push_heap(T value);
	void pop_heap();

	//void levelorder_traversal(ostream &out = cout); 		size_t size()	const			{return heap_size;		 }	bool empty()	const			{return (heap_size == 0);}	T	peak()		const			{return data[1];		 }	T	find_max()	const			{return data[1];		 }	int height()	const			{return int(log(double(heap_size) /log(2.0)));}	/*				static bool is_heap(
		typename vector<T>::iterator first,
		typename vector<T>::iterator last
	);*/
	
};

#include "Max_heap.cpp"

#endif