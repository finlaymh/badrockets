#ifndef ROCKET_H
#define ROCKET_H
#include "environment.h"


class Rocket
{
public:
    Rocket();

private://properties
    float RMass;//kg
    float Fuel;//kg
    float TMass;//kg
    double Drag;//N
    double Height;//m
    double Thrust;//N
    double Acceleration;//ms^-2
    double Velocity = 0;//ms^-1
    double REscapeV;//ms^-1
    double RMFR;//kgs^-1


public: //methods
    double calculateA(Environment env);
    double calculateV(int T);
    double calculateRMFR( int T);
    double calculateEscapeV(Environment env);
    double calculateDrag(Environment env, double Coefficient, double Area);


    void setRMass(float mass);
    void setTMass();
    void setFuel(float mass);
    void setHeight(double height);
    void setThrust(double force);
    float getRMass();
    float getTMass();
    float getFuel();
    double getHeight();
    double getThrust();
};

#endif // ROCKET_H
