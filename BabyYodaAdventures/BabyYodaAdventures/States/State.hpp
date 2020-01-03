#ifndef STATE_HPP
#define STATE_HPP

#include <iostream>
#include <memory>
#include <vector>
#include <map>
#include <stack> 
#include <fstream>

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

class State
{
private:
	/////////////////////
	// Variables
	//

	std::shared_ptr<sf::RenderWindow> m_renderWindow;
	std::vector<std::shared_ptr<sf::Texture>> m_textures;

public:
	/////////////////////
	// Methods
	//

	// Constructors

	State(std::shared_ptr<sf::RenderWindow> renderWindow);

	// Destructors

	virtual ~State();

	// Udate

	virtual void update(const float& frameTime) = 0;

	// Render

	virtual void render(std::shared_ptr<sf::RenderTarget> renderTarget = nullptr) = 0;

	// Managing state

	virtual void endState() = 0;
};

#endif