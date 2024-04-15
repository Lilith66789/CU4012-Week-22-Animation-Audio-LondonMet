#include "Mario.h"

Mario::Mario()
{
	speed = 200;

	marioSpriteSheet.loadFromFile("gfx/MarioSheetT.png");
	setSize(sf::Vector2f(60, 81));
	setPosition(100, 100);
	setTexture(&marioSpriteSheet);

	walk.addFrame(sf::IntRect(0, 0, 15, 21)); 
	walk.addFrame(sf::IntRect(15, 0, 15, 21)); 
	walk.addFrame(sf::IntRect(30, 0, 15, 21)); 
	walk.addFrame(sf::IntRect(45, 0, 15, 21));

	walk.setFrameSpeed(1.f / 8.f); 


	swim.addFrame(sf::IntRect(0, 21, 16, 20));
	swim.addFrame(sf::IntRect(16, 21, 16, 20));
	swim.addFrame(sf::IntRect(32, 21, 16, 20));
	swim.setFrameSpeed(1.f / 4.f);
	
	currentAnimation = &walk;
	setTextureRect(currentAnimation->getCurrentFrame());

	duck.addFrame(sf::IntRect(0, 44, 17, 17));
	duck.setFrameSpeed(1.f / 2.f);


}

void Mario::handleInput(float dt)
{
	velocity.x = 0;
	currentAnimation->animate(dt);
	setTextureRect(currentAnimation->getCurrentFrame());

	if (input->isKeyDown(sf::Keyboard::A)) {
		velocity.x = -speed;
		currentAnimation = &walk;
		//currentAnimation->reset();
		currentAnimation->setFlipped(true);
	}

	else if (input->isKeyDown(sf::Keyboard::D)) {
		velocity.x = speed;
		currentAnimation = &walk;
		//currentAnimation->reset();
		currentAnimation->setFlipped(false);
	}

	else if (input->isKeyDown(sf::Keyboard::S)) {
		currentAnimation = &duck;
		currentAnimation->animate(dt);

	}

	else {
		currentAnimation->reset();
		currentAnimation= & walk;
	}

	if (input->isKeyDown(sf::Keyboard::Space) && canJump) {
		Jump(200.f);
		audio->playSoundbyName("jump");
	}
}
