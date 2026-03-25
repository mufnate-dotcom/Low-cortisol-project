#include "Employee.h"
#include <iostream>
#include <iomanip>
using namespace std;

Employee::Employee(int id, const string& name, const string& position)
    : id(id), name(name), position(position), worktime(0), payment(0) 
{
}
void Employee::setWorkTime(double hours) 
{
    worktime = hours;
}
void Employee::printInfo() const 
{
    cout << setw(8) << id
        << setw(20) << name
        << setw(15) << position
        << setw(10) << worktime
        << setw(15) << fixed << setprecision(2) << payment << endl;
}