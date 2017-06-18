#ifndef MACHINETASKSCHEDULINGDATABASE_H
#define MACHINETASKSCHEDULINGDATABASE_H

#include "Database.h"
#include <vector>

class MachineTaskSchedulingDatabase : public Database {
public:
    MachineTaskSchedulingDatabase();
    virtual ~MachineTaskSchedulingDatabase();
    void loadBase(string databaseName);
    void print();

    int totalMachines; //total amount of machines
    int totalTasks; //total amount of tasks

    int** timeMachineTask; //time for task i be processed on a machine j (Pij)
    int*** preparingTime;  //time for preparing a machine i for process task k after task j (Skij)
    int* deadline;         //time for delivery a task i
protected:

private:
};

#endif // MACHINETASKSCHEDULINGDATABASE_H
