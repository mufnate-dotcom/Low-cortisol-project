//Project.cpp
#include "Project.h"
#include
using namespace std;
Project::Project(const std::string& name, int budget) : name(name), budget(budget) {}
void Project::addEmployee(int employeeId)
{
for (int id : employeeIds)
{
if (id == employeeId) return;
}
employeeIds.push_back(employeeId);
}
void Project::removeEmployee(int employeeId)
{
for (auto it = employeeIds.begin(); it != employeeIds.end(); ++it)
{
if (it == employeeId)
{
employeeIds.erase(it);
break;
}
}
}
bool Project::hasEmployee(int employeeId) const
{
for (int id : employeeIds)
{
if (id == employeeId) return true;
}
return false;
}
string Project::serialize() const
{
string result = name + ";" + to_string(budget);
for (int id : employeeIds)
{
result += ";" + to_string(id);
}
return result;
}
Project Project::deserialize(const string& data)
{
vector parts;
stringstream ss(data);
string item;
while (getline(ss, item, ';'))
{
parts.push_back(item);
}
if (parts.size() < 2) return nullptr;
Project* project = new Project(parts[0], std::stoi(parts[1]));
for (size_t i = 2; i < parts.size(); ++i)
{
project->addEmployee(std::stoi(parts[i]));
}
return project;
}

//Personal.h
#ifndef PERSONAL_H
#define PERSONAL_H
#include "Employee.h"
using namespace std;
class Personal : public Employee, public WorkBaseTime
{
protected:
double hourlyRate;
public:
Personal(int id, const string& name, const string& position, double hourlyRate);
double calcBase(double hours, double rate) const override;
double calcBonus(double hours) const override { return 0; }
void calc() override;
void printInfo() const override;
string serialize() const override;
};
class Cleaner : public Personal
{
public:
Cleaner(int id, const string& name, double hourlyRate);
double calcBonus(double hours) const override;
};
#endif
