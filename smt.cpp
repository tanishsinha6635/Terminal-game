#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 400, 400 }), "SFML works!",);
    sf::RectangleShape shape(sf::Vector2f(100.f, 100.f));
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
}
