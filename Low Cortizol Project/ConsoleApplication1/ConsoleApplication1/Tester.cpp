#include "Tester.h"
using namespace std;

Tester::Tester(int id, const string& name, const string& position,
    double hourlyRate, Project* project)
    : Engineer(id, name, position, hourlyRate, project), bugsFound(0), bonusPerBug(0)
{
}
double Tester::calcProAdditions() 
{
    return bugsFound * bonusPerBug;
}