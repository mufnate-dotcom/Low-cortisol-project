#ifndef TESTER_H
#define TESTER_H
#include "Engineer.h"
using namespace std;

class Tester : public Engineer 
{
private:
    int bugsFound;
    double bonusPerBug;
public:
    Tester(int id, const string& name, const string& position,
        double hourlyRate, Project* project = nullptr);
    virtual ~Tester() {}
    void setBugsFound(int bugs) { bugsFound = bugs; }
    void setBonusPerBug(double bonus) { bonusPerBug = bonus; }
    double calcProAdditions() override;
};
#endif