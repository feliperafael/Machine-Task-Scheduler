#include "MachineTaskSchedulingCrossover.h"

MachineTaskSchedulingCrossover::MachineTaskSchedulingCrossover()
{
    //ctor
}

void MachineTaskSchedulingCrossover::cross(Individual ** vec_individuos, int num_individuos){
    //simple crossover com 2 individuos
    simpleCrossover(vec_individuos[0],vec_individuos[1]);
}
// esse cruzamento ta uma porra kkk tudo errado...
void MachineTaskSchedulingCrossover::simpleCrossover(Individual * a, Individual * b){

    //Individuals 'a' and 'b' that are the same number of machines
    MachineTaskSchedulingIndividual * ind_1 = dynamic_cast<MachineTaskSchedulingIndividual*>(a);
    MachineTaskSchedulingIndividual * ind_2 = dynamic_cast<MachineTaskSchedulingIndividual*>(b);


    int random_machine = rand()%ind_1->totalMachines;
    cout << "num_machines " << ind_1->totalMachines << endl;

    int num_tasks = ind_1->machinesAndTasksInit[random_machine].size();
    cout << "num_tasks " << num_tasks << " of machine " << random_machine  << endl;

    int random_task = rand()%num_tasks;
    cout << "random_task " << random_task << endl;

    int index = ind_1->machinesAndTasksIndex[random_machine][random_task];

    cout << " index " << index << endl;
    int index_machine_ind_2 = getMachineOfTask(index,ind_2);

    swap(ind_1->machinesAndTasksEnd[random_machine][index],ind_2->machinesAndTasksEnd[index_machine_ind_2][index]);
    swap(ind_1->machinesAndTasksIndex[random_machine][index],ind_2->machinesAndTasksIndex[index_machine_ind_2][index]);
    swap(ind_1->machinesAndTasksInit[random_machine][index],ind_2->machinesAndTasksInit[index_machine_ind_2][index]);

//    swap(ind_1->machinesAndTasksIndex[luck],ind_2->machinesAndTasksIndex[luck]);
//    swap(ind_1->machinesAndTasksInit[luck],ind_2->machinesAndTasksInit[luck]);
//
    cout << "\n\nind_1\n";
    ind_1->print();
    cout << "\nind_2\n";
    ind_2->print();

}

int MachineTaskSchedulingCrossover::getMachineOfTask(int task,MachineTaskSchedulingIndividual * ind){
    for( int i = 0; i < ind->totalMachines; i++ ){
        for( int j = 0; j < ind->machinesAndTasksIndex[i].size(); j++ ){
            if(task == ind->machinesAndTasksIndex[i][j]){
                //cout << "machine " << i << " task " << j << "task "<< ind->machinesAndTasksIndex[i][j] << endl;
                return i;
            }
        }
    }
    return -1;

}

MachineTaskSchedulingCrossover::~MachineTaskSchedulingCrossover()
{
    //dtor
}
