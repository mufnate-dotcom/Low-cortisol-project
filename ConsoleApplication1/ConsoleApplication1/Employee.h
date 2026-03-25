#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
#include "Project.h"
using namespace std;

class Employee
{
protected:
    int id;
    string name;
    double worktime;
    double payment;
    string position;
public:
    Employee(int id, const string& name, const string& position);
    virtual ~Employee() {}
    void setWorkTime(double hours);
    virtual void calc() = 0;
    virtual void printInfo() const;
    int getId() const { return id; }
    string getName() const { return name; }
    string getPosition() const { return position; }
    double getPayment() const { return payment; }
    double getWorktime() const { return worktime; }
    virtual Project* getProject() const { return nullptr; }
    virtual void setProject(Project* project) {}
};
#endif