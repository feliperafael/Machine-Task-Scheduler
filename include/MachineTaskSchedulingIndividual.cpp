#include "MachineTaskSchedulingIndividual.h"

MachineTaskSchedulingIndividual::MachineTaskSchedulingIndividual()
{

}

string MachineTaskSchedulingIndividual::nameIndividual(){
    return "MachineTaskSchedulingIndividual";
};

void MachineTaskSchedulingIndividual::create(Database* data){
    MachineTaskSchedulingDatabase* database = dynamic_cast<MachineTaskSchedulingDatabase*>(data);

    totalMachines = database->totalMachines;
    totalTasks = database->totalTasks;

    machinesAndTasksIndex = new vector<int>[totalMachines];

    int tasks_vec[totalTasks];
    for(int i = 0; i < totalTasks; i++){
        tasks_vec[i] = i;
    }
    random_shuffle(tasks_vec,tasks_vec + totalTasks);

    /**---------------------------------------------------------**/
    for(int i = 0; i < totalTasks; ++i){
        int machine = rand() % totalMachines;
        machinesAndTasksIndex[machine].push_back(tasks_vec[i]);

    }
    calculateTimes(database);
    print();
}

void MachineTaskSchedulingIndividual::calculateTimes(MachineTaskSchedulingDatabase *database){
    machinesAndTasksInit = new vector<int>[totalMachines];
    machinesAndTasksEnd = new vector<int>[totalMachines];

    for(int machine = 0; machine < totalMachines;++machine){
         for(int i = 0; i < machinesAndTasksIndex[machine].size(); ++i){
            if(i == 0){
                machinesAndTasksInit[machine].push_back(0);
                machinesAndTasksEnd[machine].push_back(database->timeMachineTask[machinesAndTasksIndex[machine].at(0)][machine]);
            }
            else{
                int time = machinesAndTasksEnd[machine].at(i - 1);
                time += database->preparingTime[machine][machinesAndTasksIndex[machine].at(i - 1)][machinesAndTasksIndex[machine].at(i)];
                machinesAndTasksInit[machine].push_back(time);
                time += database->timeMachineTask[machinesAndTasksIndex[machine].at(i)][machine];
                machinesAndTasksEnd[machine].push_back(time);
            }
        }
    }
}

Individual* MachineTaskSchedulingIndividual::clone(){
    MachineTaskSchedulingIndividual * s = new MachineTaskSchedulingIndividual();

    s->totalMachines = totalMachines;
    s->totalTasks = totalTasks;
    s->machinesAndTasksIndex = new vector<int>[totalMachines];

    for(int i = 0; i < totalMachines; i++){
        for(int j = 0; j < machinesAndTasksIndex[i].size(); j++){
            s->machinesAndTasksIndex[i].push_back(machinesAndTasksIndex[i].at(j));
//            s->machinesAndTasksInit[i].push_back(machinesAndTasksInit[i].at(j));
//            s->machinesAndTasksEnd[i].push_back(machinesAndTasksEnd[i].at(j));
        }
    }

    return s;
}

void MachineTaskSchedulingIndividual::print(){
    for(int i = 0; i < totalMachines; i++){
        cout << "M" << i << " = ";
        for(int j = 0; j < machinesAndTasksIndex[i].size(); j++)
            cout << machinesAndTasksIndex[i].at(j) << "[" << machinesAndTasksInit[i].at(j) << ", " << machinesAndTasksEnd[i].at(j) << "] -> ";
        cout << endl;
    }
}

MachineTaskSchedulingIndividual::~MachineTaskSchedulingIndividual()
{
    //dtor
}
