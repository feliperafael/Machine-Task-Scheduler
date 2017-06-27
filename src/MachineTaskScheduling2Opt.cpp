#include "MachineTaskScheduling2Opt.h"

MachineTaskScheduling2Opt::MachineTaskScheduling2Opt(){
    //ctor
}

MachineTaskScheduling2Opt::~MachineTaskScheduling2Opt(){
    //dtor
}

Individual* MachineTaskScheduling2Opt::doLocalSearch(Individual* s1){
    return opt2(s1);
}

Individual* MachineTaskScheduling2Opt::neh(Individual* s1){
    MachineTaskSchedulingIndividual * ind = dynamic_cast<MachineTaskSchedulingIndividual*>(s1);
    ind->fitness = parser->Evaluate(ind);
    double historicalFit = ind->fitness;
//    return s1;
    for(int i = 0; i < 100; ++i){
        for(int j = 0; j < ind->totalTasks; ++j){ // seleciona a tarefa
            MachineTaskSchedulingIndividual * clone = dynamic_cast<MachineTaskSchedulingIndividual*>(ind->clone());
//            cout << "Removendo tarefa posicao " << j << endl;
//            cin.get();
            int task = clone->removeTask(j);
            for(int k = 0; k < ind->totalTasks; ++k){ // realoca ela em cada lugar
                if(j != k){
//                    cout << "Colocando " << task << " em " << k;
                    clone->insertTask(task, k);
                    clone->fitness = parser->Evaluate(clone);
                    if(clone->fitness < ind->fitness){
//                        cout << " +" << endl;
                        swap(ind, clone);
                        break;
                    }
                    else{
//                        cout << " -" << endl;
                        clone->removeTask(k);
                    }
                }
            }
            delete clone;
//            cin.get();
        }
    }

    return ind;
}

Individual* MachineTaskScheduling2Opt::opt2(Individual* s1){
    MachineTaskSchedulingIndividual * ind = dynamic_cast<MachineTaskSchedulingIndividual*>(s1);
    ind->fitness = parser->Evaluate(ind);
    double historicalFit = ind->fitness;
//    return s1;
    for(int i = 0; i < 100; ++i){
        for(int j = 0; j < ind->totalTasks; ++j){ // seleciona a tarefa
            MachineTaskSchedulingIndividual * clone = dynamic_cast<MachineTaskSchedulingIndividual*>(ind->clone());
//            cout << "Removendo tarefa posicao " << j << endl;
//            cin.get();
            int task = clone->removeTask(j);
            for(int k = 0; k < ind->totalTasks; ++k){ // realoca ela em cada lugar
                if(j != k){
//                    cout << "Colocando " << task << " em " << k;
                    clone->insertTask(task, k);
                    clone->fitness = parser->Evaluate(clone);
                    if(clone->fitness < ind->fitness){
//                        cout << " +" << endl;
                        swap(ind, clone);
                        break;
                    }
                    else{
//                        cout << " -" << endl;
                        clone->removeTask(k);
                    }
                }
            }
            delete clone;
//            cin.get();
        }
    }

    return ind;
}
