#include "Cleaner.h"
using namespace std;

Cleaner::Cleaner(int id, const string& name, const string& position, double hourlyRate)
    : Personal(id, name, position, hourlyRate) 
{
}
void Cleaner::calc() 
{
    payment = calcBase(hourlyRate, worktime);
}
