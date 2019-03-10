#include "environment.h"
#include <math.h>

Environment::Environment()
{
}


double Environment::calculateG(double mR, double D) {
    double calculatedD = 6371000 + D;
    GStrength = (GmE*(mR/(calculatedD*calculatedD)));
    return GStrength;
}

double Environment::calculateAirTemp(double D) {
    if (D > 100000) {
        AirTemp = -50 + 273.15;
    }
    else {
        AirTemp = 15 - (D * 6.5) + 273.15;
        if (AirTemp < 0) {
            AirTemp = -50 + 273.15;
        }
    }
    return AirTemp;
}

double Environment::calculateAirDensity() {
    AirDensity = AirPressure/(SGasConstant*AirTemp);
    return AirDensity;
}

double Environment::calculateAirPressure(double D) {
    AirPressure = 101 * std::exp(-StandardG * MMAir * D / (UGS * AirTemp));
    return AirPressure;
}

double Environment::getG() {
    return GStrength;
}

double Environment::getAirDensity() {
    return AirDensity;
}
