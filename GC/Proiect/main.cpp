
//
// Disclamer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resource, use the helper
// method resourcePath() from ResourcePath.hpp
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

// Here is a small helper for you ! Have a look.
#include "ResourcePath.hpp"
#include <vector>
#include "point.hpp"
#include "convex_hull.hpp"
#include "polygon.hpp"
#include <iostream>
#include <stdexcept>
#include <fstream>

std::vector<point> read_points() {
    std::ifstream in(resourcePath() + "points.txt");
    if(!in.good()) throw std::runtime_error("file not found");
    std::vector<point> points;
    while(!in.eof()) {
        float x, y;
        in >> x >> y;
        points.emplace_back(x, y);
    }
    return points;
}

int main(int, char const**)
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "SFML window",  sf::Style::Default,sf::ContextSettings { 3,3,10});
   // sf::Image icon;
   // if (!icon.loadFromFile(resourcePath() + "icon.png")) {
   //     return EXIT_FAILURE;
  //  }
   // window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
   // sf::Music music;
  //  if (!music.openFromFile(resourcePath() + "nice_music.ogg")) {
 //       return EXIT_FAILURE;
 //   }
  //  music.play();
    std::vector<point> points;
    try {
        points = read_points();
        if(points.size() < 3)
            throw std::runtime_error("A minimum of 3 points are needed");
    }
    catch (std::runtime_error e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
            if(event.type == sf::Event::MouseButtonPressed) {
                std::cout << event.mouseButton.x << " " << event.mouseButton.y << std::endl;
                points.emplace_back(event.mouseButton.x, event.mouseButton.y);
            }
        }
        window.clear();
        auto hull = acoperire_convexa(points);
        polygon p = polygon(hull);
        window.draw(p.vertices);
        window.display();
    }

    return EXIT_SUCCESS;
}
