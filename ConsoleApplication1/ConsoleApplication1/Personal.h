#ifndef PERSONAL_H
#define PERSONAL_H
#include "Employee.h"
#include "Interfaces.h"
using namespace std;

class Personal : public Employee, public WorkBaseTime 
{
protected:
    double hourlyRate;
public:
    Personal(int id, const string& name, const string& position, double hourlyRate);
    virtual ~Personal() {}
    double calcBase(double hourlyRate, double worktime) override;
    double calcBonus() override { return 0; }
    virtual void calc() override;
};
#endif