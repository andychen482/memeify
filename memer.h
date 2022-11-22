//
// Created by andyc on 11/16/2022.
//

#include <SFML/Graphics.hpp>

#ifndef LAB10_MEMER_H
#define LAB10_MEMER_H

#endif //LAB10_MEMER_H

class memer
{
public:
    memer();

    sf::Image generateMeme(sf::Image base, sf::String topText, sf::String bottomText = "",
                           int topX = -1, int topY = -1, int bottomX = -1, int bottomY = -1);

    sf::Image loadImage(std::string imagePath);

    void drawWindow(sf::Image image);
};