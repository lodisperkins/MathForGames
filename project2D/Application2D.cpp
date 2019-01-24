#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"

float xpos, ypos, radius;

Application2D::Application2D() {

}

Application2D::~Application2D() {

}

bool Application2D::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	m_texture = new aie::Texture("./textures/numbered_grid.tga");
	m_shipTexture = new aie::Texture("./textures/ship.png");
	m_font = new aie::Font("./font/consolas.ttf", 32);
	
	m_cameraX = 0;
	m_cameraY = 0;
	m_timer = 0;
	
	
	circlevec =  Vector2(600,400);
	
	xpos = 500;
	ypos = 500;
	radius = 3.5;
	return true;
}

void Application2D::shutdown() {
	
	delete m_font;
	delete m_texture;
	delete m_shipTexture;
	delete m_2dRenderer;
}

void myUpdate(aie::Input* input)
{
	float deltaTime;
	input = aie::Input::getInstance();
	if (input->isKeyDown(aie::INPUT_KEY_D))
	{
		
	}
	if (input->isKeyDown(aie::INPUT_KEY_I))
	{
		radius++;
	}
	if (input->isKeyDown(aie::INPUT_KEY_A))
	{

	}
}

void Application2D::update(float deltaTime) {
	Vector2 up= Vector2(0,1);
	Vector2 right = Vector2(1,0);
	Vector2 left= Vector2(-1,0);
	Vector2 down = Vector2(0,-1);
	m_timer += deltaTime;
	ypos = 100;
	// input example
	aie::Input* input = aie::Input::getInstance();
	if (input->isKeyDown(aie::INPUT_KEY_D))
	{
		circlevec= circlevec+ right;
	}
	if (input->isKeyDown(aie::INPUT_KEY_W))
	{
		circlevec = circlevec + up;
	}
	if (input->isKeyDown(aie::INPUT_KEY_A))
	{
		circlevec = circlevec + left;
	}
	if (input->isKeyDown(aie::INPUT_KEY_S))
	{
		circlevec = circlevec + down;
	}
	if (input->isKeyDown(aie::INPUT_KEY_I))
	{
		radius++;
	}
	if (input->isKeyDown(aie::INPUT_KEY_U))
	{
		radius--;
	}
	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// set the camera position before we begin rendering
	m_2dRenderer->setCameraPos(m_cameraX, m_cameraY);

	// begin drawing sprites
	m_2dRenderer->begin();

	m_2dRenderer->drawCircle(circlevec.getX(), circlevec.getY(), radius);
	
	// done drawing sprites
	m_2dRenderer->end();
}