#include "List_Int.h"

void List_Int::push_back(const int& val)
{
	Node *new_node = new Node(val);
	list_size++;
	if(head==NULL && tail==NULL)
	{
		head=tail=new_node;
	}
	else
	{
		tail->set_next_ptr(new_node);
		tail = new_node;
	}
}

void List_Int::push_front(const int& val)
{
	Node *new_node = new Node(val);
	list_size++;
	if(head==NULL && tail==NULL)
	{
		head=tail=new_node;
	}
	else
	{
		new_node->set_next_ptr( head );
		head = new_node;

	}
}

void List_Int::pop_front()
{
	if(size() == 0)
		return;
	if(size() == 1)
		delete head, head=tail=NULL;
	else
	{
		Node *temp = head;
		head = head->get_next_ptr();
		delete temp;
	}
	list_size--;
}
void List_Int::pop_back()
{
	if(size() == 0)
		return;
	if(size() == 1)
	{
		pop_front();
		return;
	}
	Node *prev = NULL, *cur = head;
	while(cur!=tail)
	{
		prev = cur;
		cur = cur->get_next_ptr();
	}
	prev->set_next_ptr(NULL);
	tail=prev;
	delete cur;
	list_size--;
	
}

ostream & operator<<(ostream &out,const List_Int &l)
{
	if(l.size() == 0)
		out<<"List Empty"<<endl;
	else
	{
		for(List_Int::iterator it = l.begin();it!=l.end();it++)
			out<<*it<<" ";
		out<<endl;
	}
	return out;
}

List_Int::iterator List_Int::insert(List_Int::iterator pos,const int &x)
{
	
	Node* temp = new Node(x);
	list_size++;
	if(pos==begin())
	{
		temp->set_next_ptr(head);
		head = temp;
		return temp;
	}
	else if(pos==end())
	{
		tail->set_next_ptr(temp);
		tail=temp;
		return temp;
	}
	else
	{
		List_Int::iterator prev = NULL,cur=begin();
		while(cur!=pos)
			prev++,cur++;
		prev->set_next_ptr(temp);
		temp->set_next_ptr(cur.get_node_ptr());
		return temp;
	}
}

void List_Int::swap(List_Int &x)
{	
	std::swap(head,x.head);
	std::swap(tail,x.tail);
	std::swap(list_size,x.list_size);
}

