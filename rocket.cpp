#include <math.h>
#include "rocket.h"
#include "environment.h"

Rocket::Rocket()
{

}

double Rocket::calculateDrag(Environment env, double Coefficient, double Area) {
    Drag = Coefficient * (env.getAirDensity() * (Velocity * Velocity)) / 2 * Area;
    return  Drag;
}

double Rocket::calculateEscapeV(Environment env) {
    REscapeV = std::sqrt((2*env.StandardG*env.mE)/6371000);
    return REscapeV;
}

double Rocket::calculateRMFR(int T) {
    // RMFR =  (RAcceleration * TMass) / (RVelocity + (RAcceleration * (10000 - T)));
    RMFR = 2442.59259259;
    return RMFR;
}


double Rocket::calculateA(Environment env) {
    // F = M * A
    // A = F / M

    Acceleration = (Thrust - (env.getG()*1.3) - Drag) / static_cast<double>(TMass);
    return Acceleration;
}

double Rocket::calculateV(int T) {
    //2s/t-u=v
    if (T == 0) {
        //RVelocity = std::sqrt((RVelocity*RVelocity) + 2 * RAcceleration * RHeight);
        Velocity += 10;
    } else {
        // RVelocity = ((2*RHeight)/T) - RVelocity;
        Velocity = Velocity + Acceleration * T;
    }
    // RVelocity = std::sqrt((RVelocity*RVelocity) + 2 * RAcceleration * RHeight);

    return Velocity;
}



// methods for setup

void Rocket::setThrust(double force) {
    Thrust = force;
}

void Rocket::setHeight(double height) {
    Height = height;
}

void Rocket::setFuel(float mass) {
    Fuel = mass;
}

void Rocket::setRMass(float mass) {
    RMass = mass;
}

void Rocket::setTMass() {
    TMass = RMass + Fuel;
}

float Rocket::getRMass() {
    return RMass;
}

float Rocket::getTMass() {
    return TMass;
}

float Rocket::getFuel() {
    return Fuel;
}

double Rocket::getHeight() {
    return Height;
}

double Rocket::getThrust() {
    return Thrust;
}
