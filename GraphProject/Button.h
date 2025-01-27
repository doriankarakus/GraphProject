#pragma once
#include <SFML/Graphics.hpp>

class Button{
public:
    Button(){}
    int textLength=0;
    Button(std::string t, sf::Vector2f size, int charSize, sf::Color bgColor, sf::Color textColor){
        textLength = t.length()/2;
        text.setString(t);
        text.setFillColor(textColor);
        text.setCharacterSize(charSize);
        button.setSize(size);
        button.setFillColor(bgColor);
    }

    void setFont(sf::Font &font){
        text.setFont(font);
    }

    void setBackColor(sf::Color color){
        button.setFillColor(color);
    }

    void setTextColor(sf::Color color){
        text.setFillColor(color);
    }

    void setPosition(sf::Vector2f pos){
        button.setPosition(pos);

        float xPos = (pos.x + button.getLocalBounds().width / 2) - textLength*10.56;
        float yPos = (pos.y + button.getLocalBounds().height / 2)-12;
        text.setPosition({xPos,yPos});
    }

    void drawTo(sf::RenderWindow &window){
        window.draw(button);
        window.draw(text);
    }

    bool isMouseOver(sf::RenderWindow &window){
        float mouseX = sf::Mouse::getPosition(window).x;
        float mouseY = sf::Mouse::getPosition(window).y;
        float btnPosX = button.getPosition().x;
        float btnPosY = button.getPosition().y;
        float btnXPosWidth = button.getPosition().x + button.getLocalBounds().width;
        float btnYPosHeight = button.getPosition().y + button.getLocalBounds().height;

        if(mouseX < btnXPosWidth && mouseX > btnPosX && mouseY < btnYPosHeight && mouseY > btnPosY){
            return true;
        }
        return false;
    }
private:
    sf::RectangleShape button;
    sf::Text text;
};