#ifndef DRIVER_H
#define DRIVER_H
#include "Personal.h"
using namespace std;

class Driver : public Personal 
{
private:
    double nightHours;
    double nightBonus;
public:
    Driver(int id, const string& name, const string& position,
        double hourlyRate, double nightBonus = 1.5);
    virtual ~Driver() {}
    void setNightHours(double hours) { nightHours = hours; }
    double calcBonus() override;
    void calc() override;
};
#endif
