#include <SFML/Graphics.hpp>

using namespace sf;

class Collider {//
public:
    Collider(Vector2f _pos, RectangleShape _rect) 
        : pos{_pos}, rect{_rect}{
        rect.setOrigin(rect.getSize().x/2, rect.getSize().y/2);
        rect.setPosition(pos);
        size = rect.getSize();
    }
    Collider(Vector2f _pos, CircleShape _circ) 
        : pos{_pos}, circ{_circ}{
        circ.setOrigin(circ.getRadius(), circ.getRadius());
        size.x = circ.getRadius() * 2;
        size.y = circ.getRadius() * 2;
    }
    Vector2f getPos(){return pos;}
    Vector2f getSize(){return size;}

    void drawCollider(RenderWindow& window){
        circ.setFillColor(Color::Red);
        rect.setFillColor(Color::Red);
        window.draw(circ);
        window.draw(rect);
    }
    
    void setPos(Vector2f _pos){
        pos = _pos;
        circ.setPosition(pos);
        rect.setPosition(pos);
    }

    bool isColliding(Collider other){
        Vector2f deltaDist = Vector2f(abs(pos.x - other.getPos().x), abs(pos.y - other.getPos().y)); // distancia entre centros 
        Vector2f lim = Vector2f(size.x / 2 + other.getSize().x / 2, size.y / 2 + other.getSize().y / 2); // distancia min si
        std::cout << deltaDist.x << " - " << deltaDist.y << std::endl;
        std::cout << lim.x << " - " << lim.y << std::endl;

        if (deltaDist.x > lim.x) {return false;} // no es posible en x
        if (deltaDist.y > lim.y) {return false;} // no es posible en y

        // es posible donde
        if (deltaDist.x <= lim.x){return true;} // choque horizontal
        if (deltaDist.y <= lim.y){return true;} // choque vertical

        return (deltaDist.x <= lim.x && deltaDist.y <= lim.y);
    }
private:
    Vector2f size;
    Vector2f pos;
    CircleShape circ;
    RectangleShape rect;
};

class BoxObject : public RectangleShape {
public:
    explicit BoxObject(Vector2f position, Vector2f size)
        : RectangleShape(size), pos{position}, collisione{Collider(position, RectangleShape(size))}{
        setOrigin(getSize().x/2, getSize().y /2);
        setPosition(pos);
    }

    Collider getCollider(){return collisione;}

private:
    Vector2f pos;  
    Collider collisione;
};