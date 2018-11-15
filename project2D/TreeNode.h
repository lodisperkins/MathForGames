#pragma once
#include "Renderer2D.h"
#include <iostream>
class TreeNode
{
private:
	int m_value;

	TreeNode * m_left;
	TreeNode * m_right;
public:
	TreeNode(int value);
	TreeNode();
	~TreeNode();
	bool hasLeft()
	{
		return m_left != nullptr;
	}
	bool hasRight()
	{
		return m_right != nullptr;
	}
	int getData()
	{
		return m_value;
	}
	TreeNode* getLeft() 
	{
		return m_left;
	}
	TreeNode* getRight() 
	{
		return m_right;
	}

	void setData(int value)
	{
		m_value = value;
	}
	void setLeft(TreeNode* node)
	{
		m_left = node;
	}
	void setRight(TreeNode* node)
	{
		m_right = node;
	}

	void draw(aie::Renderer2D*, int x, int y, bool selected = false);

};