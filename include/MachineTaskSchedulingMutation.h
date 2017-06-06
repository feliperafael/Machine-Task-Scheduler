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

    protected:

    private:
};

#endif // MACHINETASKSCHEDULINGMUTATION_H
