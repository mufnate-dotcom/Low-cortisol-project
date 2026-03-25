#include "Personal.h"
using namespace std;

Personal::Personal(int id, const string& name, const string& position, double hourlyRate)
    : Employee(id, name, position), hourlyRate(hourlyRate) 
{
}
double Personal::calcBase(double hourlyRate, double worktime) 
{
    return hourlyRate * worktime;
}
void Personal::calc() 
{
    payment = calcBase(hourlyRate, worktime) + calcBonus();
}
