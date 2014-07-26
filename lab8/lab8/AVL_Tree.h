#ifndef ____AVL__TREE__H____
#define ____AVL__TREE__H____

#include "Node.h"
#include <iostream>
#include <queue>


using std::ostream;
using std::cout;
using std::queue;

template<class T>
class AVL_Tree{
public:
	typedef size_t	size_type;
	typedef T		data_type;
private:
	//Data Members of Tree_Int
	Node<data_type>* root;
	size_t tree_size;
	static bool deletion_flag;

	//Utility Functions

	bool is_root(Node<data_type>* node)	{return (node==NULL)?false:(node == root);}
	bool is_root(data_type val)				{return root->get_data() == val		 ;}
	
	Node<data_type>* get_parent(Node<data_type>* node)	;
	Node<data_type>* get_parent(data_type val)			;

	bool is_left_child (Node<data_type>* node)			; 
	bool is_left_child (data_type value)				; 
	 
	bool is_right_child(Node<data_type>* node)			; 
	bool is_right_child(data_type value)				; 

	bool has_two_siblings(Node<data_type>* node)		; 
	bool has_two_siblings(data_type value)				; 

	bool is_leaf(Node<data_type>* node)					; 
	bool is_leaf(data_type value)						; 
	 
	bool has_only_one_sibling(Node<data_type>* node)	; 
	bool has_only_one_sibling(data_type value)			; 
public:
	//Life -- "Where there's life there's death."
	AVL_Tree():root(NULL),tree_size(0){	}
	//Death
	~AVL_Tree()	{	clear();			}

	//Public Functions
	
	Node<data_type>* get_root() const	{return root;			}
	size_type		 size() const	{return tree_size;			}
	bool			 empty()	const	{return tree_size==0;	}

	Node<data_type>*	search(data_type key)	;
	void	insert(data_type x)					;
	bool	delete_node(data_type value)		;
	bool	delete_node(Node<data_type>* node)	;
	void	clear()								;
	void	clear(Node<data_type>* node)		;
	//Traversal Functions
	void inorder	(Node<data_type> *node_ptr, ostream &out = cout)	const	;
	void preorder	(Node<data_type> *node_ptr, ostream &out = cout)	const	;
	void postorder	(Node<data_type> *node_ptr, ostream &out = cout)	const	;
	void levelorder	(Node<data_type> *node_ptr, ostream &out = cout)	const	;

	void inorder(ostream &out = cout)	const
		{inorder(root,out)		;			}
	void preorder(ostream &out = cout)	const
		{preorder(root,out)		;			}
	void postorder(ostream &out = cout)	const
		{postorder(root,out)	;			}
	void levelorder(ostream &out = cout)const
		{levelorder(root,out)	;			}
	
	Node<data_type>* inorder_successor(Node<data_type> *node)	;
	Node<data_type>* inorder_predecessor(Node<data_type> *node)	;

	Node<data_type>* inorder_successor(data_type value)			;
	Node<data_type>* inorder_predecessor(data_type value)		;

	//////////////////////////////////////////////////////////
	//	Conversion Of A BST to AVL Tree By the				//
	//	Following Functions									//
	//////////////////////////////////////////////////////////
	
	void update_height_after_insert(Node<T>* node);
	void update_height_after_delete(Node<T>* node);

	void left_rotate(Node<T>* node);
	void right_rotate(Node<T>* node);

	int balance_factor(Node<T>* node);
	
	void rebalance_insert(Node<T>* node);
	void rebalance_delete(Node<T>* node);

};

#include "AVL_Tree.cpp"
#endif