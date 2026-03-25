#include "Programmer.h"
using namespace std;

Programmer::Programmer(int id, const string& name, const string& position,
    double hourlyRate, Project* project)
    : Engineer(id, name, position, hourlyRate, project), earlyCodeLines(0), bonusPerLine(0) 
{
}
double Programmer::calcProAdditions() 
{
    return earlyCodeLines * bonusPerLine;
}
