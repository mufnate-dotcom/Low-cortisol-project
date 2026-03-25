#include "SeniorManager.h"
using namespace std;

SeniorManager::SeniorManager(int id, const string& name, const string& position)
    : Employee(id, name, position), totalSubordinates(0),
    partFromEachProject(0), bonusPerSubordinate(0) 
{
}
void SeniorManager::addProject(Project* project) 
{
    projects.push_back(project);
}
double SeniorManager::calcBudgetPart(double part, int budget) 
{
    return budget * part;
}
double SeniorManager::calcHeads(int subordinatesCount) 
{
    return subordinatesCount * bonusPerSubordinate;
}
void SeniorManager::calc() 
{
    double totalProjectPayment = 0;

    for (Project* project : projects)
    {
        if (project != nullptr)
        {
            totalProjectPayment += calcBudgetPart(partFromEachProject, project->getBudget());
        }
    }
    payment = totalProjectPayment + calcHeads(totalSubordinates);
}