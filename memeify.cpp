#include <iostream>
#include "memer.cpp"
#include <SFML/Graphics.hpp>

//
// Created by andyc on 11/16/2022.
//

int main(int argc, const char** argv)
{
    //sf::Image base();
    //base.loadFromFile(argv[2]); // argvs wrong
    //generateMeme(base,argv[3]);
    sf::String topString = "Hi";

    memer* image;

    sf::Image base = image->loadImage("doge.jpg");

    sf::Image finalImage = image->generateMeme(base, topString);

    image->drawWindow(finalImage);



}
