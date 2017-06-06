#ifndef MACHINETASKSCHEDULINGCROSSOVER_H
#define MACHINETASKSCHEDULINGCROSSOVER_H

#include "MachineTaskSchedulingIndividual.h"
#include "Crossover.h"

class MachineTaskSchedulingCrossover : public Crossover
{
    public:
        MachineTaskSchedulingCrossover();
        void cross(Individual ** vec_individuos, int num_individuos);
        virtual ~MachineTaskSchedulingCrossover();

    protected:

    private:
};

#endif // MACHINETASKSCHEDULINGCROSSOVER_H
