#ifndef MACHINETASKSCHEDULINGMUTATION_H
#define MACHINETASKSCHEDULINGMUTATION_H

#include "MachineTaskSchedulingIndividual.h"
#include "Mutation.h"

class MachineTaskSchedulingMutation
{
    public:
        MachineTaskSchedulingMutation();
        virtual void mutate(Individual * s);
        virtual ~MachineTaskSchedulingMutation();


        MachineTaskSchedulingIndividual * mutationTasks(MachineTaskSchedulingIndividual * s);

        MachineTaskSchedulingIndividual * auxMutationTasks(MachineTaskSchedulingIndividual * s,int machine);



    protected:

    private:
};

#endif // MACHINETASKSCHEDULINGMUTATION_H
