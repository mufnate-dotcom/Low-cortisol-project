#ifndef STAFFFACTORY_H
#define STAFFFACTORY_H
#include <vector>
#include <string>
#include "Employee.h"
#include "Project.h"
using namespace std;

class StaffFactory 
{
public:
    static vector<Employee*> makeStaff(const string& filename,
        vector<Project*>& projects);
    static void saveStaff(const string& filename,
        const vector<Employee*>& staff,
        const vector<Project*>& projects);
};
#endif