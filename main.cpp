#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Game.h"

using namespace sf;

int main()
{
    //
    int SCREEN_WIDTH = 800, SCREEN_HEIGHT = 450;
    RenderWindow window(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Juego");window.setFramerateLimit(60u);
    Clock reloj; // reloj
    Vector2f mvel(0.0f, 0.0f);
   
    Player Pete (20.f, 360u, 100, Vector2f(50.f,400.f));

    BoxObject caja1 (Vector2f(100.0f, 425.0f), Vector2f(50.0f, 50.0f));
    BoxObject caja2 (Vector2f(200.0f, 390.0f), Vector2f(50.0f, 50.0f));

    vector<BoxObject> boxObjects;
    apendin(boxObjects, caja1);
    apendin(boxObjects, caja2);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
    
        float time = reloj.restart().asSeconds(); 

        Pete.movePlayer(time);
        
        //colisiones
        Pete.checkBorder(SCREEN_WIDTH, SCREEN_HEIGHT);

        checkColObj(boxObjects, Pete);

        window.clear();

        Update(time, Pete, mvel);

        RenderObjs(window, boxObjects);

        Render(window, Pete);

        window.display();
    }
    
    return 0;
}