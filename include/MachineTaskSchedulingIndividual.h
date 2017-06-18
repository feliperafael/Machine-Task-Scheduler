#ifndef MACHINETASKSCHEDULINGINDIVIDUAL_H
#define MACHINETASKSCHEDULINGINDIVIDUAL_H

#include "Individual.h"
#include "Database.h"
#include "MachineTaskSchedulingDatabase.h"
#include <vector>
#include <algorithm>

class MachineTaskSchedulingIndividual : public Individual {
public:
    MachineTaskSchedulingIndividual();
    virtual ~MachineTaskSchedulingIndividual();

    virtual string nameIndividual();
    virtual Individual* clone();
    void create(Database* data);
    void calculateTimes(Database *data);
    void print();

    vector<int>* machinesAndTasksIndex;
    vector<int>* machinesAndTasksInit;
    vector<int>* machinesAndTasksEnd;

    int totalMachines;
    int totalTasks;

protected:

private:
};

#endif // MACHINETASKSCHEDULINGINDIVIDUAL_H
