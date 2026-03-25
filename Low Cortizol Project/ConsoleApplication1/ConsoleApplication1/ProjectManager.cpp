#include "ProjectManager.h"
using namespace std;

ProjectManager::ProjectManager(int id, const std::string& name, const std::string& position,
    Project* project)
    : Employee(id, name, position), project(project),
    subordinatesCount(0), partFromBudget(0), bonusPerSubordinate(0) 
{
}
double ProjectManager::calcBudgetPart(double part, int budget) 
{
    return budget * part;
}
double ProjectManager::calcHeads(int subordinatesCount) 
{
    return subordinatesCount * bonusPerSubordinate;
}
void ProjectManager::calc() 
{
    double projectPayment = 0;

    if (project != nullptr) 
    {
        projectPayment = calcBudgetPart(partFromBudget, project->getBudget());
    }
    payment = projectPayment + calcHeads(subordinatesCount);
}