// "Copyright [2024] Jason Ossai"
#ifndef UNIVERSE_HPP
#define UNIVERSE_HPP

#include <vector>
#include "CelestialBody.hpp"

namespace NB {

    class Universe : public sf::Drawable {
    public:
        Universe();
        double getUniverseRadius() const;
        std::vector<CelestialBody>& getBodies();
        void step(double dt);  // Add this declaration

        friend std::istream& operator>>(std::istream& in, Universe& universe);
        friend std::ostream& operator<<(std::ostream& out, const Universe& universe);

    private:
        int num_planets;
        double universe_radius;
        std::vector<CelestialBody> bodies;

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    };

} // namespace NB

#endif
