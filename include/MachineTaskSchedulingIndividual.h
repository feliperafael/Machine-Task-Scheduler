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
    void insertIdleTime(MachineTaskSchedulingDatabase* data);

    int removeTask(int t);
    void insertTask(int t, int p);
    void swapTasks(int t, int p);

    vector<int>* machinesAndTasksIndex;
    vector<int>* machinesAndTasksInit;
    vector<int>* machinesAndTasksEnd;

    int totalMachines;
    int totalTasks;

    protected:

    private:
};

#endif // MACHINETASKSCHEDULINGINDIVIDUAL_H
