#ifndef MACHINETASKSCHEDULINGCROSSOVER_H
#define MACHINETASKSCHEDULINGCROSSOVER_H

#include "MachineTaskSchedulingIndividual.h"
#include "Crossover.h"

class MachineTaskSchedulingCrossover : public Crossover {
public:
    MachineTaskSchedulingCrossover();
    void cross(Individual ** vec_individuos, int num_individuos);
    virtual ~MachineTaskSchedulingCrossover();

protected:

private:
    void simpleCrossover(Individual * a, Individual * b);
    //return if of machine responsible by the task of id 'task'
    int getMachineOfTask(int task,MachineTaskSchedulingIndividual * ind);

    bool taskAlreadyExists(int index_max, int task, int vec[]);
};

#endif // MACHINETASKSCHEDULINGCROSSOVER_H
