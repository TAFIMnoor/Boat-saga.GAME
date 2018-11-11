#include <SFML/Graphics.hpp>
#include <time.h>
using namespace sf;

struct point
{ int x,y;};

int main()
{
    srand(time(0));

    RenderWindow app(VideoMode(800, 533), "Doodle Game!");
    app.setFramerateLimit(60);

    Texture t1,t2,t3;
    t1.loadFromFile("River.png");
    t2.loadFromFile("platform.png");
    t3.loadFromFile("pirate_ship.png");

    Sprite sBackground(t1), sPlat(t2), sPers(t3);
	sPers.setScale(0.2, 0.2);
    point plat[20];

    for (int i=0;i<10;i++)
      {
       plat[i].x=rand()%800;
       plat[i].y=rand()%533;
      }

	int x=400,y=400,h=400;
    float dx=0,dy=0;

    while (app.isOpen())
    {
        Event e;
        while (app.pollEvent(e))
        {
            if (e.type == Event::Closed)
                app.close();
        }

    if (Keyboard::isKeyPressed(Keyboard::Right)) x+=6;
    if (Keyboard::isKeyPressed(Keyboard::Left)) x-=6;

    dy+=0.2;
    y+=dy;
    if (y>500)  dy=-10;

	if (y<h)
    for (int i=0;i<10;i++)
    {
      y=h;
      plat[i].y=plat[i].y-dy;
      if (plat[i].y>533) {plat[i].y=0; plat[i].x=rand()%800;}
	  if (sPers.getGlobalBounds().intersects(sPlat.getGlobalBounds()) {
		  app.close();
	  }
    }
	dy=-5;
	
	if (sPers.getGlobalBounds().intersects(sPlat.getGlobalBounds()) {
		app.close();
	}

	sPers.setPosition(x,y);
    app.draw(sBackground);
    app.draw(sPers);
    for (int i=0;i<10;i++)
    {
    sPlat.setPosition(plat[i].x,plat[i].y);
    app.draw(sPlat);
    }

    app.display();
}

    return 0;
}
