#pragma once
#include "Framework/GameObject.h"
#include "Framework/Animation.h"
class Zombie :
    public GameObject
{
    sf::Texture zombTexture;
    int speed;
public: 
    Zombie();
    ~Zombie();

    void handleInput(float dt) override;

protected:
    Animation walk;
};

