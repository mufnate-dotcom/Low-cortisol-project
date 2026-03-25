#ifndef PROJECTBUDGET_H
#define PROJECTBUDGET_H

class ProjectBudget
{
public:
    virtual double calcBudgetPart(double part, int budget) = 0;
    virtual double calcProAdditions() = 0;
    virtual ~ProjectBudget() {}
};

#endif