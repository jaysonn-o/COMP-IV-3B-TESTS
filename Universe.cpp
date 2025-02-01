// "Copyright [2024] Jason Ossai"
#include "Universe.hpp"
#include <cmath>  // For mathematical operations

namespace NB {

    Universe::Universe() : num_planets(0), universe_radius(2.50e+11) {
        bodies.resize(num_planets);
    }

    double Universe::getUniverseRadius() const {
        return universe_radius;
    }

    std::vector<CelestialBody>& Universe::getBodies() {
        return bodies;
    }

    // Implement the step function
    void Universe::step(double dt) {
        const double G = 6.67430e-11;  // Gravitational constant

        // Loop over each pair of celestial bodies to calculate forces
        for (int i = 0; i < num_planets; ++i) {
            double forceX = 0.0, forceY = 0.0;

            for (int j = 0; j < num_planets; ++j) {
                if (i != j) {
                    double dx = bodies[j].getX() - bodies[i].getX();
                    double dy = bodies[j].getY() - bodies[i].getY();
                    double distance = std::sqrt(dx * dx + dy * dy);
                    double force = (G * bodies[i].getMass() * bodies[j].getMass()) / (distance * distance);
                    forceX += force * (dx / distance);  // Normalize force in x-direction
                    forceY += force * (dy / distance);  // Normalize force in y-direction
                }
            }

            // Update velocity based on calculated forces
            bodies[i].updateVel(forceX / bodies[i].getMass(), forceY / bodies[i].getMass(), dt);
        }

        // Update the position of each body based on their velocities
        for (int i = 0; i < num_planets; ++i) {
            bodies[i].updatep(dt);
        }
    }

    std::istream& operator>>(std::istream& in, Universe& universe) {
        in >> universe.num_planets >> universe.universe_radius;
        universe.bodies.resize(universe.num_planets);
        for (int i = 0; i < universe.num_planets; ++i) {
            in >> universe.bodies[i];
        }
        return in;
    }

    std::ostream& operator<<(std::ostream& out, const Universe& universe) {
        out << universe.num_planets << " " << universe.universe_radius << "\n";
        for (const auto& body : universe.bodies) {
            out << body << "\n";
        }
        return out;
    }

    void Universe::draw(sf::RenderTarget& target, sf::RenderStates states) const {
        for (const auto& body : bodies) {
            target.draw(body, states);
        }
    }

}  // namespace NB
