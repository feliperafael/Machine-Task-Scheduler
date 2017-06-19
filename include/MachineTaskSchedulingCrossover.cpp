#include "MachineTaskSchedulingCrossover.h"

MachineTaskSchedulingCrossover::MachineTaskSchedulingCrossover() {
    //ctor
}

void MachineTaskSchedulingCrossover::cross(Individual ** vec_individuos, int num_individuos) {
    //simple crossover com 2 individuos
    simpleCrossover(vec_individuos[0],vec_individuos[1]);
}
// esse cruzamento ta uma porra kkk tudo errado...
void MachineTaskSchedulingCrossover::simpleCrossover(Individual * a, Individual * b) {

    //Individuals 'a' and 'b' that are the same number of machines
    MachineTaskSchedulingIndividual * ind_1 = dynamic_cast<MachineTaskSchedulingIndividual*>(a);
    MachineTaskSchedulingIndividual * ind_2 = dynamic_cast<MachineTaskSchedulingIndividual*>(b);

    //vec {[machina,task];[machina,task];[machina,task]}
    int vec_a[ind_1->totalTasks*2];
    int vec_b[ind_2->totalTasks*2];

    for(int i = 0; i < ind_1->totalTasks*2;i++){
        vec_a[i] = -1;
    }
    for(int i = 0; i < ind_2->totalTasks*2;i++){
        vec_b[i] = -1;
    }
    int cont = 0;
    for(int i = 0; i < ind_1->totalMachines; i++){

        for(int j = 0; j < ind_1->machinesAndTasksIndex[i].size();j++){
            vec_a[cont] = i;
            vec_a[cont+1] = ind_1->machinesAndTasksIndex[i][j];
        }
        cont+=2;
    }

    cout << "VEC A \n\n\n";
    for(int i = 0; i < ind_1->totalTasks*2;i+=2){
        cout << "[ " << vec_a[i] << " , " << vec_a[i+1] << " ] => ";
    }

    int cont_1 = 0;
    for(int i = 0; i < ind_2->totalMachines; i++){

        for(int j = 0; j < ind_2->machinesAndTasksIndex[i].size();j++){
            vec_b[cont_1] = i;
            vec_b[cont_1+1] = ind_2->machinesAndTasksIndex[i][j];
        }
        cont_1+=2;
    }

    cout << "VEC B \n\n\n";
    for(int i = 0; i < ind_2->totalTasks*2;i+=2){
        cout << "[ " << vec_b[i] << " , " << vec_b[i+1] << " ] => ";
    }

    int random_task = rand()%ind_1->totalTasks;

    for(int i = random_task*2; i < ind_1->totalTasks*2;i+=2){
        if(vec_a[i] != -1 && vec_b[i] != -1){
            swap(ind_1->machinesAndTasksIndex[vec_a[i],vec_a[i+1]],ind_2->machinesAndTasksIndex[vec_b[i],vec_b[i+1]]);
        }
    }
    int i = random_task*2;
    int j = i;
    while(1){
        if(vec_a[i] != -1 && vec_b[j] != -1){
            if(taskAlreadyExists(i,vec_a[i], vec_b)==false){
                swap(ind_1->machinesAndTasksIndex[i][j],ind_2->machinesAndTasksIndex[i][j]);
            }
        }
        i+=2;
        j+=2;
    }

}
//verifica se uma tarefa ja existe em um vetor
bool MachineTaskSchedulingCrossover::taskAlreadyExists(int index_max, int task, int vec[]){
    for(int i = 0; i < index_max; i++){
        if(vec[i] == task){
            return true;
        }
    }
    return false;
}

int MachineTaskSchedulingCrossover::getMachineOfTask(int task,MachineTaskSchedulingIndividual * ind) {
    for( int i = 0; i < ind->totalMachines; i++ ) {
        for( int j = 0; j < ind->machinesAndTasksIndex[i].size(); j++ ) {
            if(task == ind->machinesAndTasksIndex[i][j]) {
                //cout << "machine " << i << " task " << j << "task "<< ind->machinesAndTasksIndex[i][j] << endl;
                return i;
            }
        }
    }
    return -1;

}

MachineTaskSchedulingCrossover::~MachineTaskSchedulingCrossover() {
    //dtor
}
