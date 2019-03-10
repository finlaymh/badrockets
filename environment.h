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
    float RMass;//kg
    float RFuel;//kg
    float TMass;//kg
    double RDrag;//N
    double RHeight;//m
    double RThrust;//N
    double RAcceleration;//ms^-2
    double RVelocity = 0;//ms^-1
    double REscapeV;//ms^-1
    double RMFR;//kgs^-1
    // constants
    const double UGS = 8.31432;// Nm(MolK)^-1
    const double MMAir = 0.0289644;// kgMol^-1
    const double GmE = 3.9909562e+14;// N
    const double mE = 5.98e+24;// kg
    const double StandardG = 9.80665;// ms^-2
    const double SGasConstant = 287.05;// JKg^-1K

public: // methods
    double calculateG(double mR, double D);
    double calculateA();
    double calculateV(int T);
    double calculateRMFR( int T);
    double calculateEscapeV();
    double calculateAirTemp(double D);
    double calculateAirDensity();
    double calculateAirPressure(double D);
    double calculateDrag(double Coefficient, double Area);

    void setRMass(float mass);
    void setTMass();
    void setRFuel(float mass);
    void setRHeight(double height);
    void setThrust(double force);
    float getRMass();
    float getTMass();
    float getRFuel();
    double getRHeight();
    double getRThrust();
};

#endif // ENVIRONMENT_H
