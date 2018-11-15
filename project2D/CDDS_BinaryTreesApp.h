#pragma once
#include <Application.h>
#include <Texture.h>
#include <Renderer2D.h>
#include "Binary Tree.h"
#include <Font.h>
#include "TreeNode.h"

class CDDS_BinaryTreesApp : public aie::Application {
public:

	CDDS_BinaryTreesApp();
	virtual ~CDDS_BinaryTreesApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;

	aie::Font*			m_font;
	BinaryTree m_binaryTree;
	TreeNode* m_selectedNode;

	float m_cameraX, m_cameraY;
	float m_timer;
};