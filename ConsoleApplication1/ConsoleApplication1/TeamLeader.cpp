#include "TeamLeader.h"
using namespace std;

TeamLeader::TeamLeader(int id, const string& name, const string& position,
    double hourlyRate, Project* project)
    : Programmer(id, name, position, hourlyRate, project),
    subordinatesCount(0), bonusPerSubordinate(0) 
{
}
double TeamLeader::calcHeads(int subordinatesCount) 
{
    return subordinatesCount * bonusPerSubordinate;
}
double TeamLeader::calcProAdditions() 
{
    return Programmer::calcProAdditions() + calcHeads(subordinatesCount);
}
void TeamLeader::calc() 
{
    double basePayment = calcBase(hourlyRate, worktime);
    double projectPayment = 0;
    if (project != nullptr) 
    {
        projectPayment = calcBudgetPart(projectPart, project->getBudget());
    }
    payment = basePayment + projectPayment + calcProAdditions();
}