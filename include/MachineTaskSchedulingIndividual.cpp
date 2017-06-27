#include "MachineTaskSchedulingIndividual.h"

MachineTaskSchedulingIndividual::MachineTaskSchedulingIndividual() {

}

int MachineTaskSchedulingIndividual::removeTask(int p){
    int machine = 0;
    int task = 0;
    for(int i = 0; i < totalMachines; ++i){
        if(p >= machinesAndTasksIndex[machine].size() + task){
            task += machinesAndTasksIndex[machine].size();
            ++machine;
        }
        else{
            break;
        }
    }
//    cout << "removendo " << p << " " << p - task << " de " << machinesAndTasksIndex[machine].size() << " " << machine << endl;
    int ret = machinesAndTasksIndex[machine].at(p - task);
    machinesAndTasksIndex[machine].erase(machinesAndTasksIndex[machine].begin() + p - task);
    return ret;
}

void MachineTaskSchedulingIndividual::insertTask(int t, int p){
    int machine = 0;
    int task = 0;
    for(int i = 0; i < totalMachines; ++i){
        if(p > machinesAndTasksIndex[machine].size() + task){
            task += machinesAndTasksIndex[machine].size();
            ++machine;
        }
    }

    machinesAndTasksIndex[machine].insert(machinesAndTasksIndex[machine].begin() + p - task, t);
}

string MachineTaskSchedulingIndividual::nameIndividual() {
    return "MachineTaskSchedulingIndividual";
};

void MachineTaskSchedulingIndividual::insertIdleTime(MachineTaskSchedulingDatabase* data){
    for(int i = 0; i < totalMachines; i++){
//        cout << i << " =" << endl;
        for(int j = machinesAndTasksIndex[i].size() - 1; j >= 0; j--){
//            cout << "  " << j << " =" << endl;
            if(j == machinesAndTasksIndex[i].size() - 1 && machinesAndTasksEnd[i][j] < data->deadline[machinesAndTasksIndex[i][j]]){
//                cout << "    " << "a" << " =" << endl;
                machinesAndTasksInit[i][j] += data->deadline[machinesAndTasksIndex[i][j]] - machinesAndTasksEnd[i][j];
                machinesAndTasksEnd[i][j] = data->deadline[machinesAndTasksIndex[i][j]];
            }
            else if(machinesAndTasksEnd[i][j] < data->deadline[machinesAndTasksIndex[i][j]] && data->deadline[machinesAndTasksIndex[i][j]] < machinesAndTasksInit[i][j + 1]){
//                cout << "    " << "b" << " =" << endl;
                machinesAndTasksInit[i][j] += data->deadline[machinesAndTasksIndex[i][j]] - machinesAndTasksEnd[i][j];
                machinesAndTasksEnd[i][j] = data->deadline[machinesAndTasksIndex[i][j]];
            }
            else if(machinesAndTasksEnd[i][j] < data->deadline[machinesAndTasksIndex[i][j]] && data->deadline[machinesAndTasksIndex[i][j]] >= machinesAndTasksInit[i][j + 1] && machinesAndTasksEnd[i][j] < machinesAndTasksInit[i][j + 1] + data->preparingTime[i][machinesAndTasksIndex[i][j]][machinesAndTasksIndex[i][j + 1]]){
//                cout << "    " << "c" << " =" << endl;
                machinesAndTasksInit[i][j] += machinesAndTasksInit[i][j + 1] - machinesAndTasksEnd[i][j] - data->preparingTime[i][machinesAndTasksIndex[i][j]][machinesAndTasksIndex[i][j + 1]];
                machinesAndTasksEnd[i][j] = machinesAndTasksInit[i][j + 1] - data->preparingTime[i][machinesAndTasksIndex[i][j]][machinesAndTasksIndex[i][j + 1]];
            }
        }
    }
}

void MachineTaskSchedulingIndividual::create(Database* data) {
    MachineTaskSchedulingDatabase* database = dynamic_cast<MachineTaskSchedulingDatabase*>(data);

    totalMachines = database->totalMachines;
    totalTasks = database->totalTasks;

    machinesAndTasksIndex = new vector<int>[totalMachines];
    machinesAndTasksInit = new vector<int>[totalMachines];
    machinesAndTasksEnd = new vector<int>[totalMachines];

    int tasks_vec[totalTasks];
    for(int i = 0; i < totalTasks; i++) {
        tasks_vec[i] = i;
    }
    random_shuffle(tasks_vec,tasks_vec + totalTasks);

    /**---------------------------------------------------------**/
    for(int i = 0; i < totalTasks; ++i) {
        int machine = rand() % totalMachines;
        machinesAndTasksIndex[machine].push_back(tasks_vec[i]);
    }
}

void MachineTaskSchedulingIndividual::calculateTimes(Database *data) {
    MachineTaskSchedulingDatabase * database = dynamic_cast<MachineTaskSchedulingDatabase*>(data);

    ///need delete old vectors if they exist
//    if(machinesAndTasksInit != NULL && machinesAndTasksEnd!=NULL){
        for(int i = 0; i < totalMachines; i++){
            //machinesAndTasksInit[i].erase(machinesAndTasksInit[i].begin(),machinesAndTasksInit[i].begin()+machinesAndTasksInit[i].size());
            machinesAndTasksInit[i].clear();
            machinesAndTasksEnd[i].clear();
        }

//    }

    for(int machine = 0; machine < totalMachines; ++machine) {
        for(int i = 0; i < machinesAndTasksIndex[machine].size(); ++i) {
            if(i == 0) {
                machinesAndTasksInit[machine].push_back(0);
                machinesAndTasksEnd[machine].push_back(database->timeMachineTask[machinesAndTasksIndex[machine].at(0)][machine]);
            } else {
                int time = machinesAndTasksEnd[machine].at(i - 1);
                time += database->preparingTime[machine][machinesAndTasksIndex[machine].at(i - 1)][machinesAndTasksIndex[machine].at(i)];
                machinesAndTasksInit[machine].push_back(time);
                time += database->timeMachineTask[machinesAndTasksIndex[machine].at(i)][machine];
                machinesAndTasksEnd[machine].push_back(time);
            }
        }
    }
}

Individual* MachineTaskSchedulingIndividual::clone() {
    MachineTaskSchedulingIndividual * s = new MachineTaskSchedulingIndividual();

    s->totalMachines = totalMachines;
    s->totalTasks = totalTasks;
    s->machinesAndTasksIndex = new vector<int>[totalMachines];
    s->machinesAndTasksInit = new vector<int>[totalMachines];
    s->machinesAndTasksEnd = new vector<int>[totalMachines];

    for(int i = 0; i < totalMachines; i++) {
        for(int j = 0; j < machinesAndTasksIndex[i].size(); j++) {
            s->machinesAndTasksIndex[i].push_back(machinesAndTasksIndex[i].at(j));
//            s->machinesAndTasksInit[i].push_back(machinesAndTasksInit[i].at(j));
//            s->machinesAndTasksEnd[i].push_back(machinesAndTasksEnd[i].at(j));
        }
    }

    return s;
}

void MachineTaskSchedulingIndividual::print() {
    cout << fitness << " ";
    for(int i = 0; i < totalMachines; i++) {
        cout << "M" << i << " = ";
        for(int j = 0; j < machinesAndTasksIndex[i].size(); j++)
            cout << machinesAndTasksIndex[i].at(j) << "[" << machinesAndTasksInit[i].at(j) << ", " << machinesAndTasksEnd[i].at(j) << "] -> ";
//        cout << endl;
    }
}

MachineTaskSchedulingIndividual::~MachineTaskSchedulingIndividual() {
    for(int i = 0; i < totalMachines; i++){
        machinesAndTasksEnd[i].clear();
        machinesAndTasksInit[i].clear();
        machinesAndTasksIndex[i].clear();
    }

    delete [] machinesAndTasksEnd;
    delete [] machinesAndTasksInit;
    delete [] machinesAndTasksIndex;

}
