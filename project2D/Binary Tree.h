#pragma once
#include "TreeNode.h" 
class BinaryTree
{
	struct Node;
private:

	/*The find() function could be implemented as a recursive function or using a while loop. If you find
the former easier, you may wish to modify your class accordingly.
Set the current node to the root
While the current node is not null
if the search value equals the current node value,
return the current node and its parent
otherwise
If the search value is less than the current node
set the current node to the left child
otherwise set the current node to the right child
end While
If the loop exits, then a match was not found, so return false*/
	bool findNode(int a_nSearchValue, TreeNode*&ppOutNode, TreeNode*&ppOutParent);

	void draw(aie::Renderer2D* renderer, TreeNode*, int x, int y, int horizontalSpacing, TreeNode* selected = nullptr);

	//the root of the tree
	TreeNode* m_pRoot;
public:
	BinaryTree();
	~BinaryTree();

	const bool isEmpty();

	/*If the tree is empty, the value is inserted at the root
	Set the current node to the root
	While the current node is not null
	If the value to be inserted is less than the value in the current node
	Set the current node to the left child and continue
	If the value to be inserted is greater than the current node
	Set the current node to the right child and continue
	If the value to be inserted is the same as the value in the current node
	The value is already in the tree, so exit end While
	Get the parent of the current node (before it was set to null)
	If value to be inserted is less than parent
	insert value as left child node
	otherwise insert value as right child node
	*/
	void insert(int a_nValue);
	/*find the value in the tree, obtaining a pointer to the node and its parent
	If the current node has a right branch, then
	find the minimum value in the right branch by iterating down the left branch of the
	current node�s right child until there are no more left branch nodes
	copy the value from this minimum node to the current node
	find the minimum node�s parent node (the parent of the node you are deleting)
	if you are deleting the parent�s left node
	set this left child of the parent to the right child of the minimum
	node
	if you are deleting the parent�s right node
	set the right child of the parent to the minimum node�s right child
	If the current node has no right branch
	if we are deleting the parent�s left child, set the left child of the parent to the left
	child of the current node
	If we are deleting the parent�s right child, set the right child of the parent to the left
	child of the current node
	If we are deleting the root, the root becomes the left child of the current node*/
	void remove(int a_nValue);
	/*void makeTree(int a_nValue);*/
	TreeNode*find(int a_nValue);
	void draw(aie::Renderer2D* renderer, TreeNode* selected = nullptr);
};