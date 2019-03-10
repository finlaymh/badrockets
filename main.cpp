#include <iostream>
#include <unistd.h>
#include <cmath>
#include "environment.h"
#include "rocket.h"

void launch(Rocket rocket, Environment env, double D, float fuel, float TMass, double RMFR, double EV);
//void display(Environment env, double D, float fuel, double V, int T);

void display(Rocket rocket, Environment env, double D, float fuel, double V, int T, int &flame) {

    system("clear");
    if (D < 10000) {
        for (int i = 3000; i > 0; i -= 100) {

            if ((D - 50) <= i and (D + 50) >= i) {
                std::cout << "                                           /A\\  " << std::endl;
                std::cout << "                                           ||| " << std::endl;
                std::cout << "                                           ||| " << std::endl;
                std::cout << "                                           ||| " << std::endl;
                std::cout << "                                           ||| " << std::endl;
                std::cout << "                                           ||| " << std::endl;
                std::cout << "                                           ||| " << std::endl;
                std::cout << "                                           /W\\ ";


            }
            else {
                std::cout << std::endl;
            }
            std::cout << std::endl;
            // std::cout << i;
        }

        std::cout << "                     -------------------------------------------    " << std::endl;
        std::cout << "                ----------------------------------------------------" << std::endl;
        std::cout << "           --------------------------------------------------------------" << std::endl;
        std::cout << "       ----------------------------------------------------------------------" << std::endl;
        std::cout << "    -----------------------------------------------------------------------------" << std::endl;
        if (D <= 0) {
            std::cout << "  [ Crashed! ]  " << std::endl;
            std::exit(0);
        }

        std::cout << "velocity: " << V / 1000 << "kms^-1 | ";// << std::endl;
        std::cout << "height: " << D / 1000 << "km | fuel: " << fuel << "kg/395700kg [remaining: ";
        std::cout << (fuel / 395700) * 100 << "%]"<< std::endl;
        std::cout << "Time: T+" << T << "s [" << T/60 << " minutes]" << std::endl;
        std::cout << "temp: " << env.calculateAirTemp(D) << "K | ";
        std::cout << "pressure: " << env.calculateAirPressure(D) << "kPa | ";
        std::cout << "density: " << env.calculateAirDensity() << "kgm^-3 | ";
        std::cout << "drag: " << rocket.calculateDrag(env, 0.3, 5.2) << "N" << std::endl;
    }
    else {

        std::cout << "" << std::endl;
        std::cout << "" << std::endl;
        std::cout << "" << std::endl;
        std::cout << "                          A    " << std::endl;
        std::cout << "                         /-\\   " << std::endl;
        std::cout << "                        /---\\  " << std::endl;
        std::cout << "                        |...|      ==========================" << std::endl;
        std::cout << "                        |.O.|       velocity: " << V / 1000 << "kms^-1  " << std::endl;
        std::cout << "                        |...|       height: " << D / 1000 <<  "km     " << std::endl;
        std::cout << "                        |.O.|       Time: T+" << T << "s [" << T/60 << " minutes]" << std::endl;
        std::cout << "                        |...|       fuel: " << fuel << "kg/395700kg" << std::endl;
        std::cout << "                        |.*.|      ==========================" << std::endl;
        std::cout << "                        |.*.|  " << std::endl;
        std::cout << "                        |...|  " << std::endl;
        std::cout << "                        /...\\  " << std::endl;
        if (flame == 0 && fuel > 0) {

            std::cout << "                        WWWWW " << std::endl;
            std::cout << "                         W W   " << std::endl;
            std::cout << "                         O O" << std::endl;
            std::cout << "                        O O O" << std::endl;
            std::cout << "                         O O" << std::endl;
            std::cout << "                          O" << std::endl;
            flame = 1;
        } else if (flame == 1 && fuel > 0) {

            std::cout << "                        WWWWW " << std::endl;
            std::cout << "                         W W   " << std::endl;
            std::cout << "                        O O O" << std::endl;
            std::cout << "                         O O" << std::endl;
            std::cout << "                        O O O" << std::endl;
            std::cout << "                          O" << std::endl;
            flame = 0;
        }
    }


}

void countdown(Environment env, Rocket rocket) {
    double EV = rocket.calculateEscapeV(env);
    double D = 70;
    float fuel = 395700;
    rocket.setFuel(fuel);
    rocket.setRMass( 153354);
    rocket.setTMass();
    double RMFR = 0.0;
    float TMass = rocket.getTMass();
    for (int i = 3; i  != -1; i--) {
        system("clear");
        std::cout << "launch in T-" << i << std::endl;
        sleep(1);
    }
    launch(rocket, env, D, fuel, TMass, RMFR, EV);
}

void launch(Rocket rocket, Environment env, double D, float fuel, float TMass, double RMFR, double EV) {
    rocket.setThrust(8227000);
    int flame = 0;
    for (int T = 0; T < 10000; T++) {
        double V = 0.0;
        rocket.setHeight(D);
        env.calculateG(static_cast<double>(TMass), D);
        rocket.calculateA(env);
        V = rocket.calculateV(T);
        rocket.setFuel(fuel);
        rocket.setTMass();
        display(rocket, env, D, fuel, V, T, flame);
        if (fuel <= 0) {
            std::cout << "  [Fuel Empty!]  " << std::endl;
            rocket.setThrust(0);
            fuel = 0;
        }
        else {

            RMFR = rocket.calculateRMFR(T);
            fuel -= static_cast<float>(RMFR);
        }
        D += V;

        if (V >= EV) {
            std::cout << "Escape Velocity Reached" << std::endl;
        }
        //std::cin.get();
        usleep(125000);
        //sleep(1);

    }
}



int main(void) {
    Environment env;
    Rocket rocket;
    countdown(env, rocket);
    std::cout << "[Press Any Key To Exit]";
    std::cin.get();


}
