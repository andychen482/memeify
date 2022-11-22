#include <iostream>
#include <SFML/Graphics.hpp>
#include "memer.h"

memer::memer()
{

}


sf::Image memer::loadImage(std::string imagePath)
{
    sf::Image base;
    if (!base.loadFromFile(imagePath))
        throw EXIT_FAILURE;
    return base;
}


sf::Image memer::generateMeme(sf::Image base, sf::String topText, sf::String bottomText,
                       int topX, int topY, int bottomX, int bottomY)
{
    // 1. Converting the Image into a Texture
    sf::Texture texture;
    texture.loadFromImage(base);

    // 2. Wrapping the Texture in a Sprite
    sf::Sprite sprite(texture);

    // 3. Drawing the Sprite on a fresh & empty RenderTexture
    sf::RenderTexture renTexture;
    renTexture.draw(sprite);

    // 4. Loading a Font, and using it to construct a Text element
    sf::Font font;
    if (!font.loadFromFile("Cave-Story.ttf"))
        throw EXIT_FAILURE;

    sf::Text topTextObj(topText, font);
    topTextObj.setPosition(topX,topY);
    renTexture.draw(topTextObj);

    if (bottomText != "") {
        sf::Text bottomTextObj(bottomText, font);
        bottomTextObj.setPosition(bottomX,bottomY);
        renTexture.draw(bottomTextObj);
    }

    // 6. Extracting an Image from a Texture, derived from the RenderTexture.
    sf::Texture derivedTexture = renTexture.getTexture();

    sf::Image finalImage = derivedTexture.copyToImage();

    return finalImage;

}

void memer::drawWindow(sf::Image image)
{
    sf::RenderWindow meme(sf::VideoMode(480, 480), "Meme Generator");

    sf::Texture finalTexture;
    finalTexture.loadFromImage(image);

    sf::Sprite finalMeme(finalTexture);

    while (meme.isOpen())
    {
        sf::Event event;
        while (meme.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                meme.close();
            }
        }

        meme.setActive();

        meme.draw(finalMeme);

        meme.display();
    }
}