#ifndef INTERFACES_H
#define INTERFACES_H

class WorkBaseTime 
{
public:
    virtual double calcBase(double hourlyRate, double worktime) = 0;
    virtual double calcBonus() = 0;
    virtual ~WorkBaseTime() {}
};
class ProjectBudget 
{
public:
    virtual double calcBudgetPart(double part, int budget) = 0;
    virtual double calcProAdditions() = 0;
    virtual ~ProjectBudget() {}
};
class Heading 
{
public:
    virtual double calcHeads(int subordinatesCount) = 0;
    virtual ~Heading() {}
};
#endif