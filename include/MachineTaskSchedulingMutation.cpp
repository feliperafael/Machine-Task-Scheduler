#include "MachineTaskSchedulingMutation.h"

MachineTaskSchedulingMutation::MachineTaskSchedulingMutation() {
    //ctor
}

void MachineTaskSchedulingMutation::mutate(Individual * s) {

    MachineTaskSchedulingIndividual * s1 = dynamic_cast<MachineTaskSchedulingIndividual*>(s);

    mutationTasks(s1);
}


/*Does the mutation of the task of a machine*/
MachineTaskSchedulingIndividual * MachineTaskSchedulingMutation::mutationTasks(MachineTaskSchedulingIndividual * s){

}

MachineTaskSchedulingIndividual * MachineTaskSchedulingMutation::auxMutationTasks(MachineTaskSchedulingIndividual * s,int machine){

}

MachineTaskSchedulingMutation::~MachineTaskSchedulingMutation() {
    //dtor
}
