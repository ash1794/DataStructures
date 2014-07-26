#ifndef ____AVL__TREE__CPP____
#define ____AVL__TREE__CPP____

#include "AVL_Tree.h"

template<class T>
bool AVL_Tree<T>::deletion_flag = true;

template<class T>
void AVL_Tree<T>::inorder(Node<data_type> *node_ptr, ostream &out)const
{
	if(node_ptr==NULL)
		return;
	inorder(node_ptr->get_left(),out);
	out<<node_ptr->get_data()<<" ";
	inorder(node_ptr->get_right(),out);
}

template<class T>
void AVL_Tree<T>::preorder(Node<data_type> *node_ptr, ostream &out)const
{
	if(node_ptr==NULL)
		return;
	out<<node_ptr->get_data()<<" ";
	preorder(node_ptr->get_left(),out);
	preorder(node_ptr->get_right(),out);
}

template<class T>
void AVL_Tree<T>::postorder(Node<data_type> *node_ptr, ostream &out)const
{
	if(node_ptr==NULL)
		return;
	postorder(node_ptr->get_left(),out);
	postorder(node_ptr->get_right(),out);
	out<<node_ptr->get_data()<<" ";
}

template<class T>
void AVL_Tree<T>::levelorder(Node<data_type> *node_ptr, ostream &out)const
{
	if(node_ptr == NULL)
		return;
	queue<Node<data_type>* > q;
	q.push(node_ptr);

	while(!q.empty())
	{
		Node<data_type> *cur = q.front();q.pop();
		out<<cur->get_data()<<" ";
		if(cur->get_left()!= NULL )
			q.push(cur->get_left());
		if(cur->get_right() != NULL )
			q.push(cur->get_right());
	}
	return;
}

template<class T>
void AVL_Tree<T>::insert(data_type x)
{
	Node<data_type> *temp = new Node<data_type>(x);
	if(empty())
		root=temp,tree_size++;
	else
	{
		Node<data_type> *prev,*cur;
		cur=get_root();
		while(cur!=NULL)
		{
			prev = cur;
			if(x < cur->get_data())
				cur = cur->get_left();
			else if(x > cur->get_data())
				cur = cur->get_right();
			else //Node already Exists.
				return;
		}
		if(x < prev->get_data())
			prev->set_left(temp);
		else
			prev->set_right(temp);
		tree_size++;
	}
	return;
		
}

template<class T>
Node<T>* AVL_Tree<T>::get_parent(Node<data_type>* node)
{
	if(node==NULL)
		return NULL;
	Node<data_type> *prev,*cur;
	int to_find = node->get_data();
	
	cur=get_root(),prev=NULL;
	while(cur!=node)
	{
		prev = cur;
		if(to_find < cur->get_data())
			cur = cur->get_left();
		else
			cur = cur->get_right();
	}
	return prev;
}



template<class T>
void AVL_Tree<T>::clear(Node<data_type>* node)
{
	if(node==NULL)
		return;
	
	clear(node->get_left() );
	clear(node->get_right());
	
	if(!is_root(node))
	{
		Node<data_type>* par = get_parent(node);
		if(par->get_left()==node)
			par->set_left(NULL);
		else
			par->set_right(NULL);
	}
	delete node;
	tree_size--;
}


template<class T>
void AVL_Tree<T>::clear()
{
	clear(root);
	root=NULL;
	tree_size = 0;
	return;
}

template<class T>
Node<T>* AVL_Tree<T>::search(data_type key)
{
	Node<data_type> *cur=get_root();
	while(cur!=NULL && cur->get_data()!=key)
	{
		if(key < cur->get_data())
			cur=cur->get_left();
		else
			cur=cur->get_right();
	}
	return cur;
}

template<class T>
bool AVL_Tree<T>::is_left_child(Node<data_type> *node)
{
	if(is_root(node))
		return false;
	else
	{
		Node<data_type> *par = get_parent(node);
		return (par->get_left() == node);
	}
}

template<class T>
bool AVL_Tree<T>::is_left_child(data_type value)
{
	Node<data_type> *node = search(value);
	if(node == NULL)
		return false;
	return is_left_child(node);

}

template<class T>
bool AVL_Tree<T>::is_right_child(Node<data_type> *node)
{
	if(is_root(node))
		return false;
	else
	{
		Node<data_type> *par = get_parent(node);
		return (par->get_right() == node);
	}
}

template<class T>
bool AVL_Tree<T>::is_right_child(data_type value)
{
	Node<data_type> *node = search(value);
	if(node == NULL)
		return false;
	return is_right_child(node);

}

template<class T>
bool AVL_Tree<T>::is_leaf(Node<data_type> *node)
{
	if(node == NULL)
		return false;
	return ((node->get_left()==NULL) && (node->get_right()==NULL));
}

template<class T>
bool AVL_Tree<T>::is_leaf(data_type value)
{
	Node<data_type> *node = search(value);
	if(node == NULL)
		return false;
	return is_leaf(node);
}

template<class T>
bool AVL_Tree<T>::has_two_siblings(Node<data_type> *node)
{
	if(node == NULL)
		return false;
	return ((node->get_left()!=NULL) && (node->get_right()!=NULL));
}

template<class T>
bool AVL_Tree<T>::has_two_siblings(data_type value)
{
	Node<data_type> *node = search(value);
	if(node == NULL)
		return false;
	return has_two_siblings(node);
}

template<class T>
bool AVL_Tree<T>::has_only_one_sibling(Node<data_type> *node)
{
	if(node == NULL)
		return false;
	return ((node->get_left()!=NULL) ^ (node->get_right()!=NULL));
}

template<class T>
bool AVL_Tree<T>::has_only_one_sibling(data_type value)
{
	Node<data_type> *node = search(value);
	if(node == NULL)
		return false;
	return has_only_one_sibling(node);
}

template<class T>
bool AVL_Tree<T>::delete_node(Node<data_type>* node)
{
	if(node==NULL)
		return false;
	if(is_leaf(node))
	{
		if(is_root(node))
			root = NULL;
		else
		{
			Node<data_type> *par = get_parent(node);
			//More Efficient to call get_parent(...) once than call it twice
			//in get_parent and is_left_child..
			if(par->get_left()==node)
				par->set_left(NULL);
			else
				par->set_right(NULL);
		}
		delete node;
		tree_size--;
		return true;
	}
	else if(has_only_one_sibling(node))
	{
		if(node->get_left()!=NULL) //Has Left Child
		{
			if(is_root(node))
			{
				root = node->get_left();
			}
			else
			{
				Node<data_type> *par = get_parent(node);
				if(par->get_left() == node)
					par->set_left(node->get_left());
				else
					par->set_right(node->get_left());
			}
			delete node;
			tree_size--;
			return true;

		}
		else	//Has right child
		{
			if(is_root(node))
			{
				root = node->get_right();
			}
			else
			{
				Node<data_type> *par = get_parent(node);
				if(par->get_left() == node)
					par->set_left(node->get_right());
				else
					par->set_right(node->get_right());
			}
			delete node;
			tree_size--;
			return true;
		}
	}
	else
	{
		Node<data_type> *to_be_deleted = NULL;
		if(deletion_flag)
			to_be_deleted = inorder_successor(node);
		else
			to_be_deleted = inorder_predecessor(node);
		deletion_flag = 1^deletion_flag;
		data_type temp = to_be_deleted->get_data();
		delete_node(to_be_deleted);
		node->set_data(temp);
		return true;
	}/*has two children*/
}

template<class T>
bool AVL_Tree<T>::delete_node(data_type value)
{
	Node<data_type> *node = search(value);
	if(node == NULL)
		return false;
	return delete_node(node);
}

template<class T>
Node<T>* AVL_Tree<T>::inorder_successor(Node<data_type> *node)
{
	if(node == NULL)
		return NULL;
	if(node->get_right() != NULL)
	{
		Node<data_type> *cur = node->get_right();
		while(cur->get_left()!=NULL)
			cur = cur->get_left();
		return cur;
	}
	else
	{
		Node<data_type> *ret = NULL;
		Node<data_type> *cur = root;
		while(cur != NULL)
		{
			if( node->get_data() < cur->get_data())
			{
				ret = cur;
				cur = cur->get_left();
			}
			else if( node->get_data() > cur->get_data())
			{
				cur = cur->get_right();	
			}
			else
			{
				break;
			}
		}
		return ret;
	}
}

template<class T>
Node<T>* AVL_Tree<T>::inorder_successor(T value)
{
	Node<data_type>* temp = search(value);
	return inorder_successor(temp);
}

//////////////////
template<class T>
Node<T>* AVL_Tree<T>::inorder_predecessor(Node<data_type> *node)
{
	if(node == NULL)
		return NULL;
	if(node->get_left() != NULL)
	{
		Node<data_type> *cur = node->get_left();
		while(cur->get_right()!=NULL)
			cur = cur->get_right();
		return cur;
	}
	else
	{
		Node<data_type> *ret = NULL;
		Node<data_type> *cur = root;
		while(cur != NULL)
		{
			if( node->get_data() < cur->get_data())
			{
				cur = cur->get_left();
			}
			else if( node->get_data() > cur->get_data())
			{
				ret = cur;
				cur = cur->get_right();	
			}
			else
			{
				break;
			}
		}
		return ret;
	}
}

template<class T>
Node<T>* AVL_Tree<T>::inorder_predecessor(T value)
{
	Node<data_type>* temp = search(value);
	return inorder_predecessor(temp);
}

void AVL_Tree::left_rotate(Node<T>* node)
{
	if(node == NULL)
		return;
	Node<T>* pivot = node->get_right();
	if(pivot == NULL)
		return;

	node->set_right(pivot->get_left());
	if(node->get_right()!=NULL)
		node->get_right()->set_parent(node);
	
	pivot->set_left(node);
	pivot->set_parent(node->get_parent());
	if(is_root(node))set_root
	node->set_parent(pivot);
	
}
#endif