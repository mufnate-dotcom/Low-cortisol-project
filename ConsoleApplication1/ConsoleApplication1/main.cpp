#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cctype>
#include <limits>
#include "Employee.h"
#include "StaffFactory.h"
#include "Project.h"
#include "Cleaner.h"
#include "Driver.h"
#include "Programmer.h"
#include "Tester.h"
#include "TeamLeader.h"
#include "ProjectManager.h"
#include "SeniorManager.h"
#include "Engineer.h"

using namespace std;

vector<Employee*> staff;
vector<Project*> projects;

void printTable();
void printEmployeesByProject();
void searchByPosition();
void searchByName();
void searchBySalary();
void createProject();
void addEmployeeToProject();
void transferEmployee();
void saveData();
void setWorkTimes();
void calculateSalaries();
void clearMemory();

string toLower(const string& str)
{
    string result = str;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

int main()
{
    cout << "=== Staff Management System ===" << endl;
    cout << "Loading data from file..." << endl;

    staff = StaffFactory::makeStaff("staff_data.txt", projects);

    if (staff.empty())
    {
        cout << "No data loaded. Creating sample data..." << endl;
        Project* project1 = new Project("Alpha", 500000);
        Project* project2 = new Project("Beta", 750000);
        projects.push_back(project1);
        projects.push_back(project2);

        staff.push_back(new Cleaner(1, "Ivanov Ivan", "Cleaner", 15.0));
        staff.push_back(new Driver(2, "Petrov Petr", "Driver", 20.0));
        static_cast<Driver*>(staff[1])->setNightHours(10);

        staff.push_back(new Programmer(3, "Sidorov Alex", "Programmer", 50.0, project1));
        static_cast<Programmer*>(staff[2])->setProjectPart(0.1);
        static_cast<Programmer*>(staff[2])->setEarlyCodeLines(500);
        static_cast<Programmer*>(staff[2])->setBonusPerLine(50);

        staff.push_back(new Tester(4, "Kuznetsova Maria", "Tester", 40.0, project1));
        static_cast<Tester*>(staff[3])->setProjectPart(0.05);
        static_cast<Tester*>(staff[3])->setBugsFound(25);
        static_cast<Tester*>(staff[3])->setBonusPerBug(100);

        staff.push_back(new TeamLeader(5, "Volkov Dmitry", "TeamLeader", 60.0, project2));
        static_cast<TeamLeader*>(staff[4])->setProjectPart(0.15);
        static_cast<TeamLeader*>(staff[4])->setSubordinatesCount(3);
        static_cast<TeamLeader*>(staff[4])->setBonusPerSubordinate(500);

        staff.push_back(new ProjectManager(6, "Morozova Elena", "ProjectManager", project1));
        static_cast<ProjectManager*>(staff[5])->setPartFromBudget(0.2);
        static_cast<ProjectManager*>(staff[5])->setSubordinatesCount(5);
        static_cast<ProjectManager*>(staff[5])->setBonusPerSubordinate(1000);

        staff.push_back(new SeniorManager(7, "Sokolov Andrey", "SeniorManager"));
        static_cast<SeniorManager*>(staff[6])->addProject(project1);
        static_cast<SeniorManager*>(staff[6])->addProject(project2);
        static_cast<SeniorManager*>(staff[6])->setTotalSubordinates(20);
        static_cast<SeniorManager*>(staff[6])->setBonusPerSubordinate(2000);
    }

    setWorkTimes();
    calculateSalaries();

    int choice;
    do
    {
        cout << "\n=== Main Menu ===" << endl;
        cout << "1. Show all employees" << endl;
        cout << "2. Show employees by project" << endl;
        cout << "3. Search by position" << endl;
        cout << "4. Search by name" << endl;
        cout << "5. Search by salary (more/less)" << endl;
        cout << "6. Create new project" << endl;
        cout << "7. Add employee to project" << endl;
        cout << "8. Transfer employee to another project" << endl;
        cout << "9. Save and exit" << endl;
        cout << "0. Exit without saving" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            printTable();
            break;
        case 2:
            printEmployeesByProject();
            break;
        case 3:
            searchByPosition();
            break;
        case 4:
            searchByName();
            break;
        case 5:
            searchBySalary();
            break;
        case 6:
            createProject();
            break;
        case 7:
            addEmployeeToProject();
            break;
        case 8:
            transferEmployee();
            break;
        case 9:
            saveData();
            cout << "Data saved. Goodbye!" << endl;
            break;
        case 0:
            cout << "Exiting without saving..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 9 && choice != 0);

    clearMemory();

    return 0;
}

void printTable()
{
    cout << "\n=== All Employees ===" << endl;
    cout << setw(8) << "ID"
        << setw(20) << "Name"
        << setw(15) << "Position"
        << setw(10) << "Worktime"
        << setw(15) << "Payment" << endl;
    cout << string(68, '-') << endl;

    for (Employee* emp : staff)
    {
        emp->printInfo();
    }
}

void printEmployeesByProject()
{
    string projectName;
    cout << "Enter project name: ";
    cin >> projectName;

    cout << "\n=== Employees on project: " << projectName << " ===" << endl;
    cout << setw(8) << "ID"
        << setw(20) << "Name"
        << setw(15) << "Position"
        << setw(10) << "Worktime"
        << setw(15) << "Payment" << endl;
    cout << string(68, '-') << endl;

    bool found = false;
    for (Employee* emp : staff)
    {
        Project* proj = emp->getProject();
        if (proj != nullptr && proj->getName() == projectName)
        {
            emp->printInfo();
            found = true;
        }
    }

    if (!found)
    {
        cout << "No employees found on this project." << endl;
    }
}

void searchByPosition()
{
    string position;
    cout << "Enter position to search: ";
    cin >> position;

    cout << "\n=== Employees with position: " << position << " ===" << endl;
    cout << setw(8) << "ID"
        << setw(20) << "Name"
        << setw(15) << "Position"
        << setw(10) << "Worktime"
        << setw(15) << "Payment" << endl;
    cout << string(68, '-') << endl;

    bool found = false;
    for (Employee* emp : staff)
    {
        if (toLower(emp->getPosition()) == toLower(position))
        {
            emp->printInfo();
            found = true;
        }
    }

    if (!found)
    {
        cout << "No employees found with this position." << endl;
    }
}

void searchByName()
{
    string name;
    cout << "Enter name (or part of name) to search: ";
    cin.ignore();
    getline(cin, name);

    cout << "\n=== Employees with name containing: " << name << " ===" << endl;
    cout << setw(8) << "ID"
        << setw(20) << "Name"
        << setw(15) << "Position"
        << setw(10) << "Worktime"
        << setw(15) << "Payment" << endl;
    cout << string(68, '-') << endl;

    bool found = false;
    for (Employee* emp : staff)
    {
        if (toLower(emp->getName()).find(toLower(name)) != string::npos)
        {
            emp->printInfo();
            found = true;
        }
    }

    if (!found)
    {
        cout << "No employees found with this name." << endl;
    }
}

void searchBySalary()
{
    double salary;
    char choice;

    cout << "Enter salary amount: ";
    cin >> salary;
    cout << "Find employees who earn (m)ore or (l)ess? ";
    cin >> choice;

    cout << "\n=== Employees with salary "
        << (choice == 'm' ? "more than" : "less than") << " " << salary << " ===" << endl;
    cout << setw(8) << "ID"
        << setw(20) << "Name"
        << setw(15) << "Position"
        << setw(10) << "Worktime"
        << setw(15) << "Payment" << endl;
    cout << string(68, '-') << endl;

    bool found = false;
    for (Employee* emp : staff)
    {
        if ((choice == 'm' && emp->getPayment() > salary) ||
            (choice == 'l' && emp->getPayment() < salary))
        {
            emp->printInfo();
            found = true;
        }
    }

    if (!found)
    {
        cout << "No employees found." << endl;
    }
}

void createProject()
{
    string name;
    int budget;

    cout << "Enter project name: ";
    cin >> name;

    for (Project* p : projects)
    {
        if (p->getName() == name)
        {
            cout << "Project already exists!" << endl;
            return;
        }
    }

    cout << "Enter project budget: ";
    cin >> budget;

    Project* newProject = new Project(name, budget);
    projects.push_back(newProject);
    cout << "Project created successfully!" << endl;
}

void addEmployeeToProject()
{
    int id;
    string projectName;

    cout << "Enter employee ID: ";
    cin >> id;

    Employee* emp = nullptr;
    for (Employee* e : staff)
    {
        if (e->getId() == id)
        {
            emp = e;
            break;
        }
    }

    if (emp == nullptr)
    {
        cout << "Employee not found!" << endl;
        return;
    }

    if (dynamic_cast<Engineer*>(emp) == nullptr &&
        dynamic_cast<ProjectManager*>(emp) == nullptr)
    {
        cout << "This employee cannot be assigned to a project!" << endl;
        return;
    }

    cout << "Enter project name: ";
    cin >> projectName;

    Project* project = nullptr;
    for (Project* p : projects)
    {
        if (p->getName() == projectName)
        {
            project = p;
            break;
        }
    }

    if (project == nullptr)
    {
        cout << "Project not found!" << endl;
        return;
    }

    emp->setProject(project);
    cout << "Employee added to project successfully!" << endl;

    emp->calc();
}

void transferEmployee()
{
    int id;
    string newProjectName;

    cout << "Enter employee ID: ";
    cin >> id;

    Employee* emp = nullptr;
    for (Employee* e : staff)
    {
        if (e->getId() == id)
        {
            emp = e;
            break;
        }
    }

    if (emp == nullptr)
    {
        cout << "Employee not found!" << endl;
        return;
    }

    if (emp->getProject() == nullptr)
    {
        cout << "Employee is not assigned to any project!" << endl;
        return;
    }

    cout << "Current project: " << emp->getProject()->getName() << endl;
    cout << "Enter new project name: ";
    cin >> newProjectName;

    Project* newProject = nullptr;
    for (Project* p : projects)
    {
        if (p->getName() == newProjectName)
        {
            newProject = p;
            break;
        }
    }

    if (newProject == nullptr)
    {
        cout << "Project not found!" << endl;
        return;
    }

    emp->setProject(newProject);
    cout << "Employee transferred successfully!" << endl;

    emp->calc();
}

void saveData()
{
    StaffFactory::saveStaff("staff_data.txt", staff, projects);
    cout << "Data saved to staff_data.txt" << endl;
}

void setWorkTimes()
{
    cout << "\n=== Set work hours for employees ===" << endl;
    for (Employee* emp : staff)
    {
        double hours;
        cout << "Enter work hours for " << emp->getName()
            << " (" << emp->getPosition() << "): ";
        cin >> hours;
        emp->setWorkTime(hours);

        if (Driver* driver = dynamic_cast<Driver*>(emp))
        {
            double nightHours;
            cout << "  Enter night hours for driver: ";
            cin >> nightHours;
            driver->setNightHours(nightHours);
        }

        if (Programmer* programmer = dynamic_cast<Programmer*>(emp))
        {
            int earlyLines;
            cout << "  Enter early code lines for programmer: ";
            cin >> earlyLines;
            programmer->setEarlyCodeLines(earlyLines);
        }

        if (Tester* tester = dynamic_cast<Tester*>(emp))
        {
            int bugs;
            cout << "  Enter bugs found for tester: ";
            cin >> bugs;
            tester->setBugsFound(bugs);
        }

        if (TeamLeader* tl = dynamic_cast<TeamLeader*>(emp))
        {
            int subordinates;
            cout << "  Enter number of subordinates for team leader: ";
            cin >> subordinates;
            tl->setSubordinatesCount(subordinates);
        }

        if (ProjectManager* pm = dynamic_cast<ProjectManager*>(emp))
        {
            int subordinates;
            cout << "  Enter number of subordinates for project manager: ";
            cin >> subordinates;
            pm->setSubordinatesCount(subordinates);
        }

        if (SeniorManager* sm = dynamic_cast<SeniorManager*>(emp))
        {
            int subordinates;
            cout << "  Enter total number of subordinates for senior manager: ";
            cin >> subordinates;
            sm->setTotalSubordinates(subordinates);
        }
    }
}

void calculateSalaries()
{
    for (Employee* emp : staff)
    {
        emp->calc();
    }
    cout << "Salaries calculated successfully!" << endl;
}

void clearMemory()
{
    for (Employee* emp : staff)
    {
        delete emp;
    }
    for (Project* proj : projects)
    {
        delete proj;
    }
}