#include <iostream>
#include <C:/Libraries/SFML-2.5.1/include/SFML/Graphics.hpp>
#include "memer.h"

sf::Image memer::generateMeme(sf::Image base, sf::String topText, sf::String bottomText = "",
                       int topX = -1, int topY = -1, int bottomX = -1, int bottomY = -1)
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
        return EXIT_FAILURE;

    sf::Text topTextObj(topText, font);
    text.setPosition(topX,topY);
    renTexture.draw(topTextObj);

    if (bottomText != "") {
        sf::Text bottomTextObj(bottomText, font);
        bottomText.setPosition(bottomX,bottomY);
        renTexture.draw(bottomTextObj);
    }

    // 6. Extracting an Image from a Texture, derived from the RenderTexture.

}