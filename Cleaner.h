#ifndef CLEANER_H
#define CLEANER_H
#include "Personal.h"
using namespace std;

class Cleaner : public Personal 
{
public:
    Cleaner(int id, const string& name, const string& position, double hourlyRate);
    virtual ~Cleaner() {}

    void calc() override;
};
#endif
