#ifndef SENIORMANAGER_H
#define SENIORMANAGER_H
#include "Employee.h"
#include "ProjectBudget.h"
#include "Heading.h"
#include <vector>
using namespace std;

class SeniorManager : public Employee, public ProjectBudget, public Heading 
{
private:
    std::vector<Project*> projects;
    int totalSubordinates;
    double partFromEachProject;
    double bonusPerSubordinate;
public:
    SeniorManager(int id, const std::string& name, const std::string& position);
    virtual ~SeniorManager() {}
    void addProject(Project* project);
    void setTotalSubordinates(int count) { totalSubordinates = count; }
    void setPartFromEachProject(double part) { partFromEachProject = part; }
    void setBonusPerSubordinate(double bonus) { bonusPerSubordinate = bonus; }
    double calcBudgetPart(double part, int budget) override;
    double calcProAdditions() override { return 0; }
    double calcHeads(int subordinatesCount) override;
    void calc() override;
};
#endif