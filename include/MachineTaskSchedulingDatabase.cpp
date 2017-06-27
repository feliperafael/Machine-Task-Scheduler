#include "MachineTaskSchedulingDatabase.h"

MachineTaskSchedulingDatabase::MachineTaskSchedulingDatabase() {

}

void MachineTaskSchedulingDatabase::loadBase(string databaseName) {
    ifstream file;
    file.open(databaseName.c_str());

    file >> totalMachines >> totalTasks;

    timeMachineTask = new int*[totalTasks];
    for(int i = 0; i < totalTasks; i++) {
        timeMachineTask[i] = new int[totalMachines];
        for(int j = 0; j < totalMachines; j++) {
            file >> timeMachineTask[i][j];
        }
    }

    preparingTime = new int**[totalMachines];
    for(int k = 0; k < totalMachines; k++) {
        preparingTime[k] = new int*[totalTasks];
        for(int i = 0; i < totalTasks; i++) {
            preparingTime[k][i] = new int[totalTasks];
            for(int j = 0; j < totalTasks; j++) {
                file >> preparingTime[k][i][j];
            }
        }
    }

    deadline = new int[totalTasks];
    for(int i = 0; i < totalTasks; i++) {
        file >> deadline[i];
    }

    advance = new int[totalTasks];
    for(int i = 0; i < totalTasks; i++) {
        file >> advance[i];
    }

    delay = new int[totalTasks];
    for(int i = 0; i < totalTasks; i++) {
        file >> delay[i];
    }
}

void MachineTaskSchedulingDatabase::print() {
    cout << totalMachines << endl << totalTasks << endl;

    for(int i = 0; i < totalTasks; i++) {
        for(int j = 0; j < totalMachines; j++) {
            cout << timeMachineTask[i][j] << " ";
        }
        cout << endl;
    }
    for(int k = 0; k < totalMachines; k++) {
        for(int i = 0; i < totalTasks; i++) {
            for(int j = 0; j < totalTasks; j++) {
                cout << preparingTime[k][i][j] << " ";
            }
            cout << endl;
        }
    }

    for(int i = 0; i < totalTasks; i++) {
        cout << deadline[i] << " ";
    }
    cout << endl;
}

MachineTaskSchedulingDatabase::~MachineTaskSchedulingDatabase() {
    //dtor
}
