#ifndef ENGINEER_H
#define ENGINEER_H
#include "Personal.h"
#include "ProjectBudget.h"
using namespace std;

class Engineer : public Personal, public ProjectBudget 
{
protected:
    Project* project;
    double projectPart;
public:
    Engineer(int id, const string& name, const string& position,
        double hourlyRate, Project* project = nullptr);
    virtual ~Engineer() {}

    double calcBudgetPart(double part, int budget) override;
    double calcProAdditions() override { return 0; }
    void calc() override;
    Project* getProject() const override { return project; }
    void setProject(Project* proj) override { project = proj; }
    void setProjectPart(double part) { projectPart = part; }
};
#endif
