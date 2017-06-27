#include "MachineTaskSchedulingMutation.h"

MachineTaskSchedulingMutation::MachineTaskSchedulingMutation() {
    //ctor
}

void MachineTaskSchedulingMutation::mutate(Individual * s) {

    MachineTaskSchedulingIndividual * s1 = dynamic_cast<MachineTaskSchedulingIndividual*>(s);

    mutationTasks(s1);
}


/*Does the mutation of the task of a machine*/
MachineTaskSchedulingIndividual * MachineTaskSchedulingMutation::mutationTasks(MachineTaskSchedulingIndividual * s) {
    int random_machine_a = rand()%s->totalMachines;
    int random_machine_b = rand()%s->totalMachines;

    int max_a = s->machinesAndTasksIndex[random_machine_a].size();
    int max_b = s->machinesAndTasksIndex[random_machine_b].size();

    if(max_a > 0 && max_b > 0){
        int random_task_a = rand()% max_a;
        int random_task_b = rand()% max_b;

        swap(s->machinesAndTasksIndex[random_machine_a][random_task_a],s->machinesAndTasksIndex[random_machine_b][random_task_b]);
    }

    return s;
}

MachineTaskSchedulingIndividual * MachineTaskSchedulingMutation::mutationMachine(MachineTaskSchedulingIndividual * s) {
    int random_machine_a = rand()%s->totalMachines;
    int random_machine_b = rand()%s->totalMachines;

    swap(s->machinesAndTasksIndex[random_machine_a],s->machinesAndTasksIndex[random_machine_b]);

    return s;
}


MachineTaskSchedulingMutation::~MachineTaskSchedulingMutation() {
    //dtor
}
