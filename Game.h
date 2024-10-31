#pragma once
#include <SFML/Graphics.hpp>
#include <array>
#include <vector>
#include <iostream>
#include "World.h"
#include "Player.h"


using namespace std;

template <typename T>
//referencias de funciones
//
void apendin(vector<T>& vec, T obj) {
        vec.push_back(obj);
}

void checkColObj(vector<BoxObject> boxObjects, Player Pete){
    for (int i = 0; i < boxObjects.size(); i++){
        if (Pete.getCollider().isColliding(boxObjects[i].getCollider())){
                cout << "COLLISION";
        }
    }
}

void Update(float time, Player& pete, Vector2f mvel){
    pete.move(time * mvel.x, time * mvel.y);
    pete.getCollider().setPos(Vector2f( time * mvel.x, time * mvel.y));
    pete.Update();
    std::cout << pete.getPosition().x << " - " << pete.getPosition().y << std::endl;
    std::cout << pete.getCollider().getPos().x << " - " << pete.getCollider().getPos().y << std::endl;
}

void RenderObjs(sf::RenderWindow& window, vector<BoxObject> boxObjects){
    for (int i = 0; i < boxObjects.size(); i++){
        window.draw(boxObjects[i]);
    }
}

void Render(sf::RenderWindow& window, Drawable& dibujo){
    window.draw(dibujo);
}