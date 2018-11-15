#include "Binary Tree.h"

void BinaryTree::remove(int a_nValue)
{
	/*TreeNode * ppOutNode = nullptr;
	TreeNode* ppOutParent=nullptr;*/
	TreeNode* node = nullptr;
	TreeNode* parent = nullptr;
	if (findNode(a_nValue, node, parent))
	{
		if (m_pRoot->getData() == a_nValue)
		{
			if (m_pRoot->hasLeft()&&!m_pRoot->hasRight())
				m_pRoot = m_pRoot->getLeft();
			else if(!m_pRoot->hasLeft() && m_pRoot->hasRight())
				m_pRoot = m_pRoot->getRight();
		}
		if (!node->hasLeft() && !node->hasRight())
		{
			if (parent->hasRight())
			{
				if (parent->getRight()->getData() == a_nValue)
				{
					parent->setRight(nullptr);
					delete node;
				}
			}
			if (parent->hasLeft())
			{
				if (parent->getLeft()->getData() == a_nValue)
				{
					parent->setLeft(nullptr);
					delete node;
					return;
				}
			}
			else
			{
				delete parent;
				m_pRoot = nullptr;
			}
		}
		else if (!node->hasLeft() && node->hasRight())
		{
			if (node->getData() < parent->getData())
			{
				parent->setLeft(&(*node->getRight()));
			}
			else
			{
				parent->setRight(&(*node->getRight()));
			}
			delete node;
			return;
		}
		else if (node->hasLeft() && !node->hasRight())
		{
			if (node->getData() > parent->getData())
			{
				parent->setRight(&(*node->getLeft()));
			}
			else
			{
				parent->setLeft(&(*node->getLeft()));
			}
			delete node;
			return;
		}
		else if (node->hasLeft() && node->hasRight())
		{
			TreeNode*search = node;
			TreeNode*search2 = node->getRight();
			bool pastRoot = false;
			while (true)
			{
				if (search2->getLeft() == nullptr)
				{
					if (pastRoot == true)
					{
						node->setData(search2->getData());
						search->setLeft(&(*search2->getRight()));
						delete search2;
						break;
					}
					else
					{
						node->setData(search2->getData());
						node->setRight(search2->getRight());
						delete search2;
						break;
					}
				}
				else
				{
					pastRoot = true;
					search = search2;
					search2 = search2->getLeft();
				}
			}
		}
	}
}


TreeNode * BinaryTree::find(int a_nValue)
{
	TreeNode* search = m_pRoot;
	while (search != nullptr)
	{
		if (a_nValue == search->getData())
		{
			return search;
		}
		else if (a_nValue < search->getData())
		{
			search = search->getLeft();
			continue;
		}
		else if (a_nValue > search->getData())
		{
			search = search->getRight();
			continue;
		}
	}
}

void BinaryTree::draw(aie::Renderer2D* renderer, TreeNode* selected)
{
	if (isEmpty())
		return;
	draw(renderer, m_pRoot, 640, 680, 640, selected);
}

bool BinaryTree::findNode(int a_nSearchValue, TreeNode * &ppOutNode, TreeNode *& ppOutParent)
{
	TreeNode* search = m_pRoot;
	TreeNode* search2 = m_pRoot;
	bool pastRoot = false;
	if (search->getData() == a_nSearchValue)
	{
		ppOutParent = search2;
		ppOutNode = search;
		return true;
	}
	else
	{
		while (search != nullptr)
		{
			if (a_nSearchValue == search->getData())
			{
				ppOutParent = search2;
				ppOutNode = search;
				return true;
			}
			else if (a_nSearchValue == search2->getData())
			{
				ppOutParent = m_pRoot;
				ppOutNode = search2;
				return true;
			}
			else if (a_nSearchValue < search->getData() && !pastRoot)
			{
				if (m_pRoot->hasLeft())
				{
					search = search2->getLeft();
				}
				pastRoot = true;
			}
			else if (a_nSearchValue > search->getData() && !pastRoot)
			{
				if (m_pRoot->hasRight())
				{
					search = search2->getRight();
				}
				pastRoot = true;
			}
			if (a_nSearchValue == search->getData())
			{
				ppOutParent = search2;
				ppOutNode = search;
				return true;
			}
			else if (a_nSearchValue == search2->getData())
			{
				ppOutParent = m_pRoot;
				ppOutNode = search2;
				return true;
			}
			else if (a_nSearchValue < search->getData() && pastRoot)
			{
				search2 = search;
				search = search->getLeft();
			}
			else if (a_nSearchValue > search->getData() && pastRoot)
			{
				search2 = search;
				search = search->getRight();
			}
		}
	}
	return false;
}

void BinaryTree::draw(aie::Renderer2D * renderer, TreeNode *pNode, int x, int y, int horizontalSpacing, TreeNode * selected)
{
	if (isEmpty())
		return;
	horizontalSpacing /= 2;
	if (pNode) {
		if (pNode->hasLeft()) {
			renderer->setRenderColour(1, 0, 0);
			renderer->drawLine(x, y, x - horizontalSpacing, y - 80);
			draw(renderer, pNode->getLeft(), x - horizontalSpacing,
				y - 80, horizontalSpacing, selected);
		}
		if (pNode->hasRight()) {
			renderer->setRenderColour(1, 0, 0);
			renderer->drawLine(x, y, x + horizontalSpacing, y - 80);
			draw(renderer, pNode->getRight(), x + horizontalSpacing,
				y - 80, horizontalSpacing, selected);
		}
		pNode->draw(renderer, x, y, (selected == pNode));
	}

}

BinaryTree::BinaryTree()
{
	m_pRoot = nullptr;
}

BinaryTree::~BinaryTree()
{
}

const bool BinaryTree::isEmpty()
{
	return m_pRoot == nullptr;
}

void BinaryTree::insert(int a_nValue)
{
	TreeNode* search = m_pRoot;
	TreeNode* newNode = new TreeNode;
	newNode->setData(a_nValue);
	newNode->setLeft(nullptr);
	newNode->setRight(nullptr);
	if (isEmpty() ==true)
	{
		m_pRoot = new TreeNode;
		m_pRoot->setData(a_nValue); 
		m_pRoot->setLeft(nullptr);
		m_pRoot->setRight(nullptr);
	}
	else
	{
		while (true)
		{
			if (a_nValue <search->getData() && !(search->hasLeft()))
			{
				search->setLeft(newNode);
				break;
			}
			else if (a_nValue > search->getData() && !(search->hasRight()))
			{
				search->setRight(newNode);
				break;
			}
			if (a_nValue < search->getData())
			{
				search = search->getLeft();
				continue;
			}
			else if (a_nValue > search->getData())
			{
				search = search->getRight();
				continue;
			}
			else if (a_nValue == search->getData())
			{
				break;
			}
		}
	}
}
