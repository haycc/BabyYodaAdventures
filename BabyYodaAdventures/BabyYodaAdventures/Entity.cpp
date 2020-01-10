#include "Entity.hpp"

/////////////////////////////////////////////////
// 
//		PROTECTED METHODS
//
/////////////////////////////////////////////////

//-----------------------------------------------
//		Initialization
//

void Entity::initTextures(shared<sf::Texture>& texture)
{
	m_texture = texture;
}

void Entity::initSprite(const float& startX, const float& startY)
{
	m_sprite = std::make_shared<sf::Sprite>(*m_texture);
	m_sprite->setPosition(startX, startY);
}

void Entity::initComponentMovement(const float maxVelocity)
{
	m_componentMovement = std::make_unique<Component_Movement>(maxVelocity, m_sprite);
}



/////////////////////////////////////////////////
// 
//		PUBLIC METHODS
//
/////////////////////////////////////////////////

//-----------------------------------------------
//		Constructors
//

Entity::Entity() :
	m_posX(0),
	m_posY(0)
{

}



//-----------------------------------------------
//		Destructors
//

Entity::~Entity()
= default;



//-----------------------------------------------
//		Accessors
//

	// Getters

float Entity::getX() const
{
	return m_sprite->getPosition().x;
}

float Entity::getY() const
{
	return m_sprite->getPosition().y;
}

sf::Vector2f Entity::getPos() const
{
	return m_sprite->getPosition();
}

	// Setters

void Entity::setX(const float& x)
{
	m_sprite->setPosition(x, m_posY);
}

void Entity::setY(const float& y)
{
	m_sprite->setPosition(m_posX, y);
}

void Entity::setPos(const sf::Vector2f& pos)
{
	m_sprite->setPosition(pos);
}


//-----------------------------------------------
//		Update
//

void Entity::move(const float dirX, const float dirY, const float& frameTime)
{
	if (m_sprite && m_componentMovement)
	{
		m_componentMovement->move(dirX, dirY, frameTime);
	}
}
