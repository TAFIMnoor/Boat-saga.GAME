
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <iomanip>
#include <iostream>

#include <ctime>
#include <cstdlib>
#include <cstring>

#include<bits/stdc++.h>

using namespace std;
using namespace sf;
RenderWindow app(VideoMode(700, 600), "boat saga Game!");

bool menu=true;


struct point
{ int x,y;};


int main()
{
    srand(time(0));


    app.setFramerateLimit(60);



    Texture t1,t2,t3,t4;
    t1.loadFromFile("River.png");
    t2.loadFromFile("platform.png");
    t3.loadFromFile("pirate_ship.png");
    t4.loadFromFile("font.png");

    Sprite sbackground(t1), sPlat(t2), sPers(t3),s_t4;
	sPers.setScale(0.2, 0.2);
    point plat[5];
    s_t4.setTexture(t4);

    SoundBuffer soundbuffer;
    Sound sound;

    if(soundbuffer.loadFromFile("music.wav"))
    {
        printf("COULD NOT LOAD FILE\n");
    }
    sound.setBuffer(soundbuffer);
    sound.setVolume(50);

    Font myfont;
    if (!myfont.loadFromFile("myfont.ttf"));
        Text a7,b;
                    a7.setString("Press Enter!");
                      a7.setFont(myfont);
                      a7.setCharacterSize(50);
                      a7.setScale(1.f,1.f);
                      //gametxt.setFillColor(Color::Red);
                      a7.setPosition(200,200);
                      a7.setColor(Color::Red);
     b.setString("GOT HIT!");
                      b.setFont(myfont);
                      b.setCharacterSize(60);
                      b.setScale(1.f,1.f);
                      //gametxt.setFillColor(Color::Red);
                      b.setPosition(200,200);
                      b.setColor(Color::Red);


	for (int i = 0; i < 5; i++)
	{
		plat[i].x = rand() % 700;
		plat[i].y = rand() % 300;
	}

	int x=400,y=400,h=470;
    float dx=0,dy=0;
    int score=0;
    Clock clock,c2;

    float key=0.f;
    float slow=0.f;

    int hit=0;
    //Soundbuffer buffer1;
    //buffer1.loadFromFile("folder/music.wav");
    //Sound sound1;
    //sound1.setbuffer(buffer1);
    //sound1.play();
    //sound.play();
    //sound1.setLoop(true);



    while (app.isOpen())
    {
          Event event;
        while(app.pollEvent(event)) {

            if(event.type == event.Closed)

                 app.close();
            //if (event.key.code == sf::Keyboard::Escape)menu=true;
            }
        if(menu)
        {

             app.draw(s_t4);
             app.draw(a7);
             key=clock.getElapsedTime().asSeconds();
                 if(Keyboard::isKeyPressed(Keyboard::Return)  && key>0.2 )
                 {
                     menu=false;
                     clock.restart();
                         sound.play();
                 }
        }
        else if(!menu)
        {
                if(Keyboard::isKeyPressed(Keyboard::Escape)  && key>0.2 )
                {
                    menu=true;
                    clock.restart();
                }

             char overscore[25];
        sprintf(overscore,"SCORE :: %d", score);
        Text text(overscore,myfont, 40);
        text.setPosition(5,0);
        text.setColor(Color::Black);
//        Event e;
//        while (app.pollEvent(e))
//        {
//            if (e.type == Event::Closed)
//                app.close();
//        }

    if (Keyboard::isKeyPressed(Keyboard::Right)) x+=6.5;
    if (Keyboard::isKeyPressed(Keyboard::Left)) x-=6.5;

    dy+=1;
    y+=dy;
    if (y>600)  dy=10;

	if (y<h)
    for (int i=0;i<5;i++)
    {
      y=h;
      plat[i].y=plat[i].y-dy;
      if (plat[i].y>700) {plat[i].y=0; plat[i].x=rand()%700;}
    }
	dy=-7;

	sPers.setPosition(x,y);
    app.draw(sbackground);
    app.draw(sPers);
    for (int i=0;i<5;i++)
    {
    sPlat.setPosition(plat[i].x,plat[i].y);
    app.draw(sPlat);
	if (sPers.getGlobalBounds().intersects(sPlat.getGlobalBounds()))
        {
         app.draw(b);
           hit++;

            if(hit>20)
                {
                    menu=true;
                    sound.pause();
                }
	    }
	else
    {
        score++;

    }
    cout<<score<<" ";

    }

    if(score>3000)
    {
        dy=-10;
    }
     if(score>12000)
    {
        dy=-11;

    //if (Keyboard::isKeyPressed(Keyboard::Right)) x+=7;
    //if (Keyboard::isKeyPressed(Keyboard::Left)) x-=7;

    }
    app.draw(text);
}


    app.display();
    app.clear();
}


    return 0;

}

