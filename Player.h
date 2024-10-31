#include <SFML/Graphics.hpp>
#include "Game.h"
using namespace sf;

class Player : public CircleShape {
public:
    explicit Player(float radio, unsigned int pointCount, int _hp, Vector2f _pos, float _vel = 150.f)
        : CircleShape(radio, pointCount), hp{_hp}, pos{_pos}, vel{_vel}, 
          collisione{Collider(_pos, CircleShape(radio, pointCount))} {
        setOrigin(radio , radio);
        setFillColor(Color(250, 200, 250));
        setPosition(pos);
    }

    void Update() {
        collisione.setPos(getPosition());
    }

    void movePlayer(float deltaTime) {
        Vector2f mvel(0.f, 20.f); // Gravity effect

        // Movement logic
        if (Keyboard::isKeyPressed(Keyboard::A)) {
            mvel.x = -vel; // Move left
        }
        if (Keyboard::isKeyPressed(Keyboard::D)) {
            mvel.x = vel; // Move right
        }
        if (Keyboard::isKeyPressed(Keyboard::Space)) {
            //Jump(); // Jump logic
        }

        // Move the player and immediately update the collider
        move(mvel * deltaTime);
        Update();  // Ensure the collider follows the player
    }

    void checkBorder(int scw, int sch) {
        if (getPosition().x + getRadius() > scw) {  // Right border
            setPosition(scw - getRadius(), getPosition().y);
        } 
        else if (getPosition().x - getRadius() < 0) {  // Left border
            setPosition(0 + getRadius(), getPosition().y);
        }

        if (getPosition().y + getRadius() > sch) {  // Bottom border
            setPosition(getPosition().x, sch - getRadius());

        } 
        else if (getPosition().y - getRadius() < 0) {  // Top border
            setPosition(getPosition().x, 0 + getRadius());
        }

        Update();
    }

    Collider getCollider() {
        return collisione;
    }
//
private:
    int hp;                 
    Vector2f pos;           
    float vel;              
    Collider collisione;    
};