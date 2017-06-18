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

    int random_task_a = rand()%s->machinesAndTasksInit[random_machine_a].size();
    int random_task_b = rand()%s->machinesAndTasksInit[random_machine_b].size();

    //necessario dar todos swaps? sim...
    swap(s->machinesAndTasksEnd[random_machine_a][random_task_a],s->machinesAndTasksEnd[random_machine_b][random_task_b]);
    swap(s->machinesAndTasksIndex[random_machine_a][random_task_a],s->machinesAndTasksIndex[random_machine_b][random_task_b]);
    swap(s->machinesAndTasksInit[random_machine_a][random_task_a],s->machinesAndTasksInit[random_machine_b][random_task_b]);

    return s;
}

MachineTaskSchedulingIndividual * MachineTaskSchedulingMutation::mutationMachine(MachineTaskSchedulingIndividual * s) {
    int random_machine_a = rand()%s->totalMachines;
    int random_machine_b = rand()%s->totalMachines;

    swap(s->machinesAndTasksEnd[random_machine_a],s->machinesAndTasksEnd[random_machine_b]);
    swap(s->machinesAndTasksIndex[random_machine_a],s->machinesAndTasksIndex[random_machine_b]);
    swap(s->machinesAndTasksInit[random_machine_a],s->machinesAndTasksInit[random_machine_b]);

    return s;
}


MachineTaskSchedulingMutation::~MachineTaskSchedulingMutation() {
    //dtor
}
