#include "Driver.h"
using namespace std;

Driver::Driver(int id, const string& name, const string& position,
    double hourlyRate, double nightBonus)
    : Personal(id, name, position, hourlyRate), nightHours(0), nightBonus(nightBonus) 
{
}
double Driver::calcBonus() 
{
    return nightHours * hourlyRate * (nightBonus - 1);
}
void Driver::calc() 
{
    payment = calcBase(hourlyRate, worktime) + calcBonus();
}
