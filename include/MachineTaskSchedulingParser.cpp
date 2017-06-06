#include "MachineTaskSchedulingParser.h"

MachineTaskSchedulingParser::MachineTaskSchedulingParser()
{

}

void MachineTaskSchedulingParser::setDatabase(Database* data){
    database = dynamic_cast<MachineTaskSchedulingDatabase*>(data);
}

double MachineTaskSchedulingParser::Evaluate(Individual* subj){
    MachineTaskSchedulingIndividual* s = dynamic_cast<MachineTaskSchedulingIndividual*>(subj);

    s->fitness = 0;

    for(int i = 0; i < s->totalMachines; i++){
        for(int j = 0; j < s->machinesAndTasksIndex[i].size(); j++){
            int E = database->deadline[s->machinesAndTasksIndex[i].at(j)] - s->machinesAndTasksEnd[i].at(j); //adiantamento
            int T = s->machinesAndTasksEnd[i].at(j) - database->deadline[s->machinesAndTasksIndex[i].at(j)]; //atraso
            s->fitness += max(0, E) + max(0, T);
        }
    }

    return s->fitness;
}

string MachineTaskSchedulingParser::nameParser(){
    return "MachineTaskSchedulingParser";
}

MachineTaskSchedulingParser::~MachineTaskSchedulingParser()
{
    //dtor
}
