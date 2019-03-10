#include "environment.h"
#include <math.h>

Environment::Environment()
{
}

double Environment::calculateDrag(double Coefficient, double Area)
{
    RDrag = Coefficient * (AirDensity * (RVelocity * RVelocity)) / 2 * Area;
    return  RDrag;
}

double Environment::calculateEscapeV()
{
    REscapeV = std::sqrt((2*StandardG*mE)/6371000);
    return REscapeV;
}

double Environment::calculateRMFR(int T)
{
    // RMFR =  (RAcceleration * TMass) / (RVelocity + (RAcceleration * (10000 - T)));
    RMFR = 2442.59259259;
    return RMFR;
}

double Environment::calculateG(double mR, double D)
{
    double calculatedD = 6371000 + D;
    GStrength = (GmE*(mR/(calculatedD*calculatedD)));
    return GStrength;
}

double Environment::calculateAirTemp(double D)
{
    if (D > 100000)
    {
        AirTemp = -50 + 273.15;
    }
    else
    {
        AirTemp = 15 - (D * 6.5) + 273.15;
        if (AirTemp < 0)
        {
            AirTemp = -50 + 273.15;
        }
    }
    return AirTemp;
}

double Environment::calculateAirDensity()
{
    AirDensity = AirPressure/(SGasConstant*AirTemp);
    return AirDensity;
}

double Environment::calculateAirPressure(double D)
{
    AirPressure = 101 * std::exp(-StandardG * MMAir * D / (UGS * AirTemp));
    return AirPressure;
}

double Environment::calculateA()
{
    // F = M * A
    // A = F / M

    RAcceleration = (RThrust - (GStrength*1.3) - RDrag) / static_cast<double>(TMass);
    return RAcceleration;
}

double Environment::calculateV(int T)
{
    //2s/t-u=v
    if (T == 0)
    {
        //RVelocity = std::sqrt((RVelocity*RVelocity) + 2 * RAcceleration * RHeight);
        RVelocity += 10;
    } else
    {
        // RVelocity = ((2*RHeight)/T) - RVelocity;
        RVelocity = RVelocity + RAcceleration * T;
    }
    // RVelocity = std::sqrt((RVelocity*RVelocity) + 2 * RAcceleration * RHeight);

    return RVelocity;
}

// methods for setup

void Environment::setThrust(double force)
{
    RThrust = force;
}

void Environment::setRHeight(double height)
{
    RHeight = height;
}

void Environment::setRFuel(float mass)
{
    RFuel = mass;
}

void Environment::setRMass(float mass)
{
    RMass = mass;
}

void Environment::setTMass()
{
    TMass = RMass + RFuel;
}

float Environment::getRMass()
{
    return RMass;
}

float Environment::getTMass()
{
    return TMass;
}

float Environment::getRFuel()
{
    return RFuel;
}

double Environment::getRHeight()
{
    return RHeight;
}

double Environment::getRThrust()
{
    return RThrust;
}
