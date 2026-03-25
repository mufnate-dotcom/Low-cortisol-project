#ifndef TEAMLEADER_H
#define TEAMLEADER_H
#include "Programmer.h"
#include "Heading.h"
using namespace std;

class TeamLeader : public Programmer, public Heading 
{
private:
    int subordinatesCount;
    double bonusPerSubordinate;
public:
    TeamLeader(int id, const std::string& name, const std::string& position,
        double hourlyRate, Project* project = nullptr);
    virtual ~TeamLeader() {}
    void setSubordinatesCount(int count) { subordinatesCount = count; }
    void setBonusPerSubordinate(double bonus) { bonusPerSubordinate = bonus; }
    double calcHeads(int subordinatesCount) override;
    double calcProAdditions() override;
    void calc() override;
};
#endif