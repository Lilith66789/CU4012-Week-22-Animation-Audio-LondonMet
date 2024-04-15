#include "Zombie.h"

Zombie::Zombie()
{
	speed = 200;
	zombTexture.loadFromFile("gfx/animZombie.png");
	setSize(sf::Vector2f(110, 216));
	setPosition(100, 100);
	setTexture(&zombTexture);

	walk.addFrame(sf::IntRect(0, 0, 55, 108));
	walk.addFrame(sf::IntRect(55, 0, 55, 108));
	walk.addFrame(sf::IntRect(110, 0, 55, 108));
	walk.addFrame(sf::IntRect(165, 0, 55, 108));
	walk.addFrame(sf::IntRect(220, 0, 55, 108));
	walk.addFrame(sf::IntRect(275, 0, 55, 108));
	walk.addFrame(sf::IntRect(330, 0, 55, 108));
	walk.addFrame(sf::IntRect(385, 0, 55, 108));

	walk.setFrameSpeed(1.f/ 10.f);
}

Zombie::~Zombie()
{
}



void Zombie::handleInput(float dt)
{
	velocity.x = 0;
	setTextureRect(walk.getCurrentFrame());

	if (input->isKeyDown(sf::Keyboard::A)){
		walk.animate(dt);
		velocity.x = -speed;
		walk.setFlipped(true);
	}

	if (input->isKeyDown(sf::Keyboard::D)) {
		walk.animate(dt);
		velocity.x = speed;
		walk.setFlipped(false);
	}

	if (input->isKeyDown(sf::Keyboard::Space) && canJump) {
		Jump(200.f);
		audio->playSoundbyName("jump");
	}
}
