#pragma once

#include <random>

#include <box2d/b2_body.h>
#include <box2d/b2_circle_shape.h>
#include <box2d/b2_fixture.h>
#include <box2d/b2_world.h>

#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Graphics/Transformable.hpp"
#include "SFML/Graphics/Sprite.hpp"

#include "SFML_Utilities.h"
#include "textureManager.h"
#include "userData.h"

class Asteroid : public sf::Drawable, public sf::Transformable
{
public:
	Asteroid(b2World& world_, const sf::Vector2f startPos, const float angle);

	// DRAWABLE OVERRIDES
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void update();

	void setIsDead();
	bool getIsDead();

	long getLocalId();

private:
	sf::Sprite	m_sprite;

	b2Body* m_body = nullptr;
	UserData* m_userData = new UserData(UserDataType::ASTEROID);

	bool m_isDead = false;

	static long m_localIdAsteroid;
	static long getGlobalId();

};
