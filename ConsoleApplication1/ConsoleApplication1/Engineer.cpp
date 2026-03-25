#include "Engineer.h"
using namespace std;

Engineer::Engineer(int id, const string& name, const string& position,
    double hourlyRate, Project* project)
    : Personal(id, name, position, hourlyRate), project(project), projectPart(0) 
{
}
double Engineer::calcBudgetPart(double part, int budget) 
{
    return budget * part;
}
void Engineer::calc() 
{
    double basePayment = calcBase(hourlyRate, worktime);
    double projectPayment = 0;

    if (project != nullptr)
    {
        projectPayment = calcBudgetPart(projectPart, project->getBudget());
    }
    payment = basePayment + projectPayment + calcProAdditions();
}