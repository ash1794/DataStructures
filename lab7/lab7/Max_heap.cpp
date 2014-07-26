#include "Max_heap.h"

template<class T>
Max_heap<T>::Max_heap(typename vector<T>::iterator v_begin,typename vector<T>::iterator v_end)
{
	data.push_back(0);
	for(typename vector<T>::iterator it = v_begin;it!=v_end;it++)
	{
		data.push_back(*it);
		heap_size++;
	}
	make_heap();
}

template<class T>
Max_heap<T>::Max_heap(vector<T> v)
{
	data = v;
	heap_size = data.size();
	data.push_front(0);
	make_heap();
}

template<class T>
void Max_heap<T>::make_heap()
{
	for(int i=(heap_size/2);i>=1;i--)
	{
		heapify_down(i);
	}
}

template<class T>
void Max_heap<T>::heapify_down(size_t index)
{
	assert(index<=heap_size);
	size_t left = index << 1;
	size_t right = left | 1;
	size_t largest = index;
	if(left<=heap_size and data[left]>data[largest])
		largest = left;
	if(right<=heap_size and data[right]>data[largest])
		largest = right;
	if(largest!=index)
		swap(data[index],data[largest]),
		heapify_down(largest);
	reutrn;
}

template<class T>
void Max_heap<T>::heapify_up(size_t index)
{
	assert(index<=heap_size);
	
	size_t parent = index >> 1;
	if(data[index] > data[parent])
		swap(data[index],data[parent]),
		heapify_up(parent);

	reuturn;
}

template<class T>
void Max_heap<T>::push_heap(T value)
{
	data.push_back(value);
	heap_size++;
	heapify_up(heap_size);
	return;
}

template<class T>
void Max_heap<T>::pop_heap()
{
	assert(! empty());
	if(heap_size == 1)
	{
		heap_size = 0;
		data.pop_back();
	}
	else
	{
		swap(data[1],data[heap_size]);
		data.pop_back();
		--heap_size();
		heapify_down(1);
	}
}

/*template<class T>
void Max_heap<T>::levelorder_traversal(ostream& out)
{
	for(int i=1;i<=heap_size;i++)
		out<<data[i]<<" ";
	out<<endl;
	return;
}

template<class T>
bool Max_heap<T>::is_heap(typename vector<T>::iterator first,typename vector<T>::iterator last) 
{
	int left,right;
	int size = last - first;
	for(int i=0;i<=size;i++)
	{
		left = (i<<1)+1;
		right = left +1;
		if( left+first < last and ( *(left+first) > *(first+i)) )
			return false;
		if( right+first < last and ( *(right+first) > *(first+i)) )
			return false;
	}
	return true;
}*/

template<class T>
void heap_sort(typename vector<T>::iterator first,typename vector<T>::iterator last)
{
	typename vector<T>::iterator st = first;
	Max_heap<T> temp(first,last);
	while(!temp.empty())
	{
		*st = temp.peak();
		st++;
		temp.pop_heap();
	}
}