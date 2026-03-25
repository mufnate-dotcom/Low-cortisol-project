#include "StaffFactory.h"
#include "Cleaner.h"
#include "Driver.h"
#include "Programmer.h"
#include "Tester.h"
#include "TeamLeader.h"
#include "ProjectManager.h"
#include "SeniorManager.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

vector<Employee*> StaffFactory::makeStaff(const string& filename,
    vector<Project*>& projects) 
{
    vector<Employee*> staff;
    ifstream file(filename);

    if (!file.is_open()) 
    {
        cerr << "Cannot open file: " << filename << endl;
        return staff;
    }
    string line;
    while (getline(file, line)) 
    {
        stringstream ss(line);
        int id;
        string name, position, projectName;
        double salary;
        ss >> id >> name >> position >> salary >> projectName;
        Project* project = nullptr;
        if (!projectName.empty() && projectName != "-") 
        {
            auto it = find_if(projects.begin(), projects.end(),
                [&projectName](Project* p) { return p->getName() == projectName; });
            if (it != projects.end()) 
            {
                project = *it;
            }
            else 
            {
                project = new Project(projectName, 100000);
                projects.push_back(project);
            }
        }
        Employee* emp = nullptr;
        if (position == "Cleaner") 
        {
            emp = new Cleaner(id, name, position, salary);
        }
        else if (position == "Driver") 
        {
            emp = new Driver(id, name, position, salary);
            static_cast<Driver*>(emp)->setNightHours(0);
        }
        else if (position == "Programmer") 
        {
            emp = new Programmer(id, name, position, salary, project);
            static_cast<Programmer*>(emp)->setProjectPart(0.1);
            static_cast<Programmer*>(emp)->setEarlyCodeLines(0);
            static_cast<Programmer*>(emp)->setBonusPerLine(50);
        }
        else if (position == "Tester") 
        {
            emp = new Tester(id, name, position, salary, project);
            static_cast<Tester*>(emp)->setProjectPart(0.05);
            static_cast<Tester*>(emp)->setBugsFound(0);
            static_cast<Tester*>(emp)->setBonusPerBug(100);
        }
        else if (position == "TeamLeader") 
        {
            emp = new TeamLeader(id, name, position, salary, project);
            static_cast<TeamLeader*>(emp)->setProjectPart(0.15);
            static_cast<TeamLeader*>(emp)->setSubordinatesCount(0);
            static_cast<TeamLeader*>(emp)->setBonusPerSubordinate(500);
        }
        else if (position == "ProjectManager") 
        {
            emp = new ProjectManager(id, name, position, project);
            static_cast<ProjectManager*>(emp)->setPartFromBudget(0.2);
            static_cast<ProjectManager*>(emp)->setSubordinatesCount(0);
            static_cast<ProjectManager*>(emp)->setBonusPerSubordinate(1000);
        }
        else if (position == "SeniorManager") 
        {
            emp = new SeniorManager(id, name, position);
            static_cast<SeniorManager*>(emp)->setPartFromEachProject(0.05);
            static_cast<SeniorManager*>(emp)->setTotalSubordinates(0);
            static_cast<SeniorManager*>(emp)->setBonusPerSubordinate(2000);
        }
        if (emp != nullptr) 
        {
            staff.push_back(emp);
        }
    }
    file.close();
    return staff;
}
void StaffFactory::saveStaff(const string& filename,
    const vector<Employee*>& staff,
    const vector<Project*>& projects) 
{
    ofstream file(filename);
    if (!file.is_open()) 
    {
        cerr << "Cannot save to file: " << filename << endl;
        return;
    }
    for (Employee* emp : staff) 
    {
        file << emp->getId() << " "
            << emp->getName() << " "
            << emp->getPosition() << " ";
        if (dynamic_cast<Personal*>(emp)) 
        {
            file << "0 ";
        }
        else 
        {
            file << "0 ";
        Project* project = emp->getProject();
        if (project != nullptr) 
        {
            file << project->getName();
        }
        else 
        {
            file << "-";
        }
        file << endl;
    }
    file.close();
}