#ifndef PROJECT_H
#define PROJECT_H

#include <string>
#include <vector>
class Project 
{
private:
    std::string name;
    int budget;
public:
    Project(const std::string& name, int budget) : name(name), budget(budget) {}
    std::string getName() const { return name; }
    int getBudget() const { return budget; }
    void setBudget(int newBudget) { budget = newBudget; }
};
#endif
