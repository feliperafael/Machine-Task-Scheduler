#include "MachineTaskSchedulingCrossover.h"

MachineTaskSchedulingCrossover::MachineTaskSchedulingCrossover() {
    //ctor
}

void MachineTaskSchedulingCrossover::cross(Individual ** vec_individuos, int num_individuos) {
    //simple crossover com 2 individuos
    simpleCrossover(vec_individuos[0],vec_individuos[1]);
}

void MachineTaskSchedulingCrossover::PathRelinking(Individual* a, Individual* b){

}

// esse cruzamento ta uma porra kkk tudo errado...
void MachineTaskSchedulingCrossover::simpleCrossover(Individual * a, Individual * b) {

    //Individuals 'a' and 'b' that are the same number of machines
    MachineTaskSchedulingIndividual * ind_1 = dynamic_cast<MachineTaskSchedulingIndividual*>(a);
    MachineTaskSchedulingIndividual * ind_2 = dynamic_cast<MachineTaskSchedulingIndividual*>(b);

    int original1[ind_1->totalTasks];
    int original2[ind_1->totalTasks];

    int new1[ind_1->totalTasks];
    int new2[ind_1->totalTasks];

    int memory1[ind_1->totalTasks] = {0};
    int memory2[ind_1->totalTasks] = {0};

    int limits1[ind_1->totalMachines];
    int limits2[ind_1->totalMachines];

    int cut = rand() % ind_1->totalTasks;
//    cout << "cut = " << cut << endl;

    // lineariza as tarefas e guarda os pontos de corte
    for(int i = 0, k = 0, l = 0; i < ind_1->totalMachines; i++){
        for(int j = 0; j < ind_1->machinesAndTasksIndex[i].size(); j++, k++){
            original1[k] = ind_1->machinesAndTasksIndex[i][j];
            new1[k] = ind_1->machinesAndTasksIndex[i][j];
        }

        for(int j = 0; j < ind_2->machinesAndTasksIndex[i].size(); j++, l++){
            original2[l] = ind_2->machinesAndTasksIndex[i][j];
            new2[l] = ind_2->machinesAndTasksIndex[i][j];
        }

        limits1[i] = k;
        limits2[i] = l;
    }

    // atualiza dizendo que até o corte os valores estão na memória
    for(int i = 0; i < cut; i++){
        memory1[original1[i]] = 1;
        memory2[original2[i]] = 1;
    }

//    for(int i = 0; i < ind_1->totalTasks; i++){
//        if(i == cut)
//            cout << "| ";
//        cout << original1[i] << " ";
//    }
//    cout << endl;
//    for(int i = 0; i < ind_1->totalTasks; i++){
//        if(i == cut)
//            cout << "| ";
//        cout << original2[i] << " ";
//    }
//    cout << endl << "originais" << endl;;

//    //troca os valores que estão depois do corte
//    for(int i = cut; i < ind_1->totalTasks; i++){
//        swap(original1[i], original2[i]);
//    }


    int posA = cut;
    int posB = cut;

//    for(int i = 0; i < ind_1->totalTasks; i++){
//        if(i == cut)
//            cout << "| ";
//        cout << original1[i] << " ";
//    }
//    cout << endl;
    //enquanto originalX não estiver completo, acertar
    while(posA < ind_1->totalTasks){
//        cout << "   verificando " << original2[posB];
        if(memory1[original2[posB]] == 0){
//            cout << " inserido";
            memory1[original2[posB]] = 1;
            new1[posA] = original2[posB];
            posA++;
        }
        posB = (posB + 1) % ind_1->totalTasks;
//        cout << endl;
    }

//    for(int i = 0; i < ind_1->totalTasks; i++){
//        if(i == cut)
//            cout << "| ";
//        cout << original2[i] << " ";
//    }
//    cout << endl;
    posA = posB = cut;
    while(posA < ind_1->totalTasks){
//        cout << "   verificando " << original1[posB];
        if(memory2[original1[posB]] == 0){
//            cout << " inserido";
            memory2[original1[posB]] = 1;
            new2[posA] = original1[posB];
            posA++;
        }
        posB = (posB + 1) % ind_1->totalTasks;
//        cout << endl;
    }

//    for(int i = 0; i < ind_1->totalTasks; i++){
//        if(i == cut)
//            cout << "| ";
//        cout << new1[i] << " ";
//    }
//    cout << endl;
//    for(int i = 0; i < ind_1->totalTasks; i++){
//        if(i == cut)
//            cout << "| ";
//        cout << new2[i] << " ";
//    }
//    cout << endl << "finais" << endl;;

    for(int i = 0, k = 0, l = 0; i < ind_1->totalMachines; i++){
        for(int j = 0; j < ind_1->machinesAndTasksIndex[i].size(); j++, k++){
            ind_1->machinesAndTasksIndex[i][j] = new1[k];
        }

        for(int j = 0; j < ind_2->machinesAndTasksIndex[i].size(); j++, l++){
            ind_2->machinesAndTasksIndex[i][j] = new2[l];
        }
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
