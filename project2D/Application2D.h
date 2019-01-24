#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Binary Tree.h"
#include "TreeNode.h"
#include <vector2.h>
class Application2D : public aie::Application {
public:

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Texture*		m_texture;
	aie::Texture*		m_shipTexture;

	aie::Font*			m_font;
	BinaryTree m_binaryTree;
	TreeNode* m_selectedNode;
	Vector2 circlevec;
	
	float m_cameraX, m_cameraY;
	float m_timer;
};