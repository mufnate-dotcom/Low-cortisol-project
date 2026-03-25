#ifndef PROJECTMANAGER_H
#define PROJECTMANAGER_H
#include "Employee.h"
#include "ProjectBudget.h"
#include "Heading.h"
using namespace std;

class ProjectManager : public Employee, public ProjectBudget, public Heading 
{
private:
    Project* project;
    int subordinatesCount;
    double partFromBudget;
    double bonusPerSubordinate;
public:
    ProjectManager(int id, const std::string& name, const std::string& position,
        Project* project = nullptr);
    virtual ~ProjectManager() {}

    void setSubordinatesCount(int count) { subordinatesCount = count; }
    void setPartFromBudget(double part) { partFromBudget = part; }
    void setBonusPerSubordinate(double bonus) { bonusPerSubordinate = bonus; }

    double calcBudgetPart(double part, int budget);
    double calcProAdditions() { return 0; }
    double calcHeads(int subordinatesCount);
    void calc() override;
    Project* getProject() const override { return project; }
    void setProject(Project* proj) override { project = proj; }
};
#endif