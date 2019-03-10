#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H


class Environment
{
public:
    Environment();
private: // properties
    double AirPressure;//kPa
    double AirDensity;
    double GStrength;//N
    double AirTemp;//C


public:
    // constants
    const double UGS = 8.31432;// Nm(MolK)^-1
    const double MMAir = 0.0289644;// kgMol^-1
    const double GmE = 3.9909562e+14;// N
    const double mE = 5.98e+24;// kg
    const double StandardG = 9.80665;// ms^-2
    const double SGasConstant = 287.05;// JKg^-1K

public: // methods
    double calculateG(double mR, double D);

    double calculateAirTemp(double D);
    double calculateAirDensity();
    double calculateAirPressure(double D);

    double getAirDensity();
    double getG();
};

#endif // ENVIRONMENT_H
