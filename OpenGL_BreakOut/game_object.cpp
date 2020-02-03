/*******************************************************************
** This code is part of Breakout.
**
** Breakout is free software: you can redistribute it and/or modify
** it under the terms of the CC BY 4.0 license as published by
** Creative Commons, either version 4 of the License, or (at your
** option) any later version.
******************************************************************/
#include "game_object.h"


GameObject::GameObject()
    : Position(0, 0), Size(1, 1), Velocity(0.0f), Color(1.0f), Rotation(0.0f), Sprite(), IsSolid(false), Destroyed(false), Collision(nullptr) { }

GameObject::GameObject(glm::vec2 pos, glm::vec2 size, Texture2D sprite, glm::vec3 color, glm::vec2 velocity)
    : Position(pos), Size(size), Velocity(velocity), Color(color), Rotation(0.0f), Sprite(sprite), IsSolid(false), Destroyed(false), Collision(nullptr) { }

void GameObject::Draw(SpriteRenderer& renderer)
{
    renderer.DrawSprite(this->Sprite, this->Position, this->Size, this->Rotation, this->Color);
}

void GameObject::Update(float dt)
{
    if (Collision)
    {
        this->Position.x = Collision->GetPosition().x;
        this->Position.y = Collision->GetPosition().y;
        this->Collision->ApplyForce(b2Vec2(this->Velocity.x, this->Velocity.y), this->Collision->GetWorldCenter(), GL_FALSE);
        //this->Collision->SetLinearVelocity(b2Vec2(this->Velocity.x, this->Velocity.y));
        //this->Collision->SetAngularVelocity(0); //90 degrees per second clockwise
    }
}
