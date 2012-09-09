#include "../include/Villes.h"

#include <SFML/Graphics.hpp>

#include <iostream>
#include <algorithm>
using namespace std;

Villes::Villes(unsigned int Nombre)
{
    size=Nombre;
    d=new float*[Nombre];
    pos=new float*[Nombre];
    for(unsigned int i=0;i<Nombre;++i)
    {
        d[i]=new float[Nombre];
        pos[i]=new float[2];
    }

    for(unsigned int i=0;i<Nombre;++i)
    {
        d[i][i]=0;
        pos[i][0]=rand100();
        pos[i][1]=rand100();
        for(unsigned int j=0;j<i;++j)
        {
            float x=pos[i][0] - pos[j][0],
                  y=pos[i][1] - pos[j][1];

            float val=sqrt(x*x + y*y);
            d[i][j]=d[j][i]=val;
        }
    }
}

Villes::~Villes()
{
    for(unsigned int i=0;i<size;++i)
        delete d[i];
    delete pos;
    delete d;
};


void Villes::Start(unsigned int nb_voyageur,unsigned int iteration_max)
{
    const unsigned int nb_voyageur_2=nb_voyageur>>1;
    std::vector<unsigned int> val;
    val.resize(size);
    for(unsigned int i=0;i<size;++i)
        val[i]=i;

    Voyageur voy[nb_voyageur];

    // initialisation aléatiore des voyageur, mais avec une seul fois la même ville.
    for(unsigned int i=0;i<nb_voyageur;++i)
    {
        voy[i].Creat(size);
        random_shuffle(val.begin(),val.end());
        voy[i].InitWith(val);
    }
// Create the main window

    sf::RenderWindow App(sf::VideoMode(1900, 900), "SFML window");

	// Start the game loop
	unsigned int cpt=0;
	bool run=false;
    while (App.isOpen() || cpt<iteration_max)
    {
        // Process events
        sf::Event Event;
        while (App.pollEvent(Event))
        {
            // Close window : exit
            if (Event.type == sf::Event::Closed)
                App.close();
            else if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Escape))
            {
                App.close();
                return;
            }
            else if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Space))
            {
                run = !run;
            }
        }
        // Clear screen
        App.clear();

        if (run)
        {

            for(unsigned int i=0;i<nb_voyageur;++i)
                Evaluate(voy[i]);

            //sort
            for(unsigned int i=nb_voyageur;i>nb_voyageur_2+1;--i)
                for(unsigned int j=1;j<i;++j)
                    //if(voy[j-1]>voy[j]) //plus long
                    if(voy[j-1]<voy[j]) //plus court
                        voy[j-1].InverseWith(voy[j]);

            best = voy[nb_voyageur-1].distance;

            //mélange des individus
            for(unsigned int i=nb_voyageur_2*1.5;i<nb_voyageur;++i)
            {
                unsigned int j=randBorne(nb_voyageur_2,nb_voyageur-1),
                            k=randBorne(nb_voyageur_2,nb_voyageur-1);
                if(j!=k)
                    voy[k].InverseWith(voy[j]);
            }


            int u=nb_voyageur_2;
            // reproduction de la moitié supérieur du tableau
            for (unsigned int i=nb_voyageur-1;i>=nb_voyageur_2;--i)
            {
                unsigned int start=randMax(size),
                            end=randMax(size);
                voy[u].ReplaceWith(voy[i]);//en remplace une copie d'un parent
                //on le fait se mélanger avec son 2eme parent

                if(start==end)
                {
                    --u;
                    continue; //fuck it
                }

                else if (start > end)
                {
                    unsigned int save=start;
                    start=end;
                    end=save;
                }
                voy[u].Inverse(voy[(unsigned int)randBorne(nb_voyageur_2,nb_voyageur)],start,end); // on inverse les bits avec ceux en params

                if(randMax(100)<=1)
                {
                    unsigned int a=0,b=0;

                    do
                    {
                        a=randMax(size);
                        b=randMax(size);
                    }while(a==b);
                    voy[u].Inverse(a,b); // invese 2 bits
                }

                --u;
            }
            ++cpt;
        }

        // dessins
        unsigned int* res=voy[size-1].Get();
        for(unsigned int i=1;i<size;++i)
        {
            sf::ConvexShape Line(4);
            Line.setOutlineColor(sf::Color::Green);
            Line.setFillColor(sf::Color::Green);
            Line.setOutlineThickness(1);

            float xa= pos[res[i]][0]*18,
                         ya= pos[res[i]][1]*9,
                         xb=pos[res[i-1]][0]*18,
                         yb=pos[res[i-1]][1]*9;

            Line.setPoint(0,sf::Vector2f(xa,ya));
            Line.setPoint(3,sf::Vector2f(xa,ya));
            Line.setPoint(1,sf::Vector2f(xb,yb));
            Line.setPoint(2,sf::Vector2f(xb,yb));
            App.draw(Line);
        }

        sf::ConvexShape Line(4);
        Line.setOutlineColor(sf::Color::Green);
        Line.setFillColor(sf::Color::Green);
        Line.setOutlineThickness(1);

        float xa= pos[res[0]][0]*18,
             ya= pos[res[0]][1]*9,
             xb=pos[res[size-1]][0]*18,
             yb=pos[res[size-1]][1]*9;

        Line.setPoint(0,sf::Vector2f(xa,ya));
        Line.setPoint(3,sf::Vector2f(xa,ya));
        Line.setPoint(1,sf::Vector2f(xb,yb));
        Line.setPoint(2,sf::Vector2f(xb,yb));
        App.draw(Line);

        // Update the window
        //sf::Sleep(1);
        App.display();
    }
};

void Villes::Evaluate(Voyageur& voy)
{
  voy.distance=0;
  unsigned int* res=voy.Get();

  for(unsigned int i=1;i<size;++i)
      voy.distance += d[res[i-1]][res[i]];

  voy.distance += d[res[0]][res[size-1]];

  delete res;
};
