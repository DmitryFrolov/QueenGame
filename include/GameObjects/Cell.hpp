#ifndef CELL_HPP
#define CELL_HPP

#include <SFML/Graphics.hpp>
#include "../GameSystem/ResourceManager.hpp"

using namespace std;

const sf::Color TEXT_COLOR = sf::Color(145, 80, 76, 255);

enum CellType { Black, White };

class Cell
{
private:
    sf::RectangleShape* layer;
    sf::Text* weightLabel;
    sf::Vector2f position;
    sf::Vector2f size;
    CellType cellType;
    int weight;
    
public:
    Cell();
    ~Cell();

    bool checkBelongs(const sf::Vector2f& _point) const;

    void setPosition(const sf::Vector2f& _newPosition);
    void setSize(const sf::Vector2f& _newSize);
    void setType(CellType _newType);
    void setWeight(int _newWeight);

    const sf::Vector2f getCenterCoord() const;
    const sf::Vector2f& getSize() const;
    const int getWeight() const;
    CellType getType() const;

    void showFrame();
    void disableFrame();
    void resetWeight();
    
    void draw(sf::RenderWindow* _renderWindow);
};

#endif //CELL_HPP
