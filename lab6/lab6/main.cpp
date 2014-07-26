#include "Tree_Int.h"

int main()
{
	TreeInt t;
	//int arr[] = {8,3,10,1,6,14,4,7,13};
	int arr[] = {0,1,2,3,4,5,6,7,8};
	for(int i=0;i<9;i++)
		t.insert(arr[i]);
	t.inorder();
	cout<<"\n";
	t.preorder();
	cout<<"\n";
	t.postorder();
	cout<<"\n";

	

	return 0;
}