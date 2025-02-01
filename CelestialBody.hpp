// "Copyright [2024] Jason Ossai"
#ifndef CELESTIAL_BODY_HPP
#define CELESTIAL_BODY_HPP

#include <iostream>
#include <SFML/Graphics.hpp>

namespace NB {
    class CelestialBody : public sf::Drawable {
    public:
        CelestialBody();
        void setPositionInWindow(double conversionFactor);
        sf::Vector2f getSpritePosition() const;
        double getX() const;
        double getY() const;
        double getMass() const;
        void updateVel(double xAcc, double yAcc, double dt);
        void updatep(double dt);
        friend std::istream& operator>>(std::istream& in, CelestialBody& body);
        friend std::ostream& operator<<(std::ostream& out, const CelestialBody& body);

    private:
        double x, y, xvel, yvel, mass;
        sf::Texture texture;
        sf::Sprite sprite;

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    };
} // namespace NB

#endif
