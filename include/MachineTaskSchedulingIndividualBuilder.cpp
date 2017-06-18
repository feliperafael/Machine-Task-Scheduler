#include "MachineTaskSchedulingIndividualBuilder.h"

MachineTaskSchedulingIndividualBuilder::MachineTaskSchedulingIndividualBuilder(Database* data) {
    this->database = dynamic_cast<MachineTaskSchedulingDatabase*>(data);
}

Individual * MachineTaskSchedulingIndividualBuilder::generateIndividuo() {
    MachineTaskSchedulingIndividual * i = new MachineTaskSchedulingIndividual();
    i->create(database);
    return i;
}

string MachineTaskSchedulingIndividualBuilder::nameIndividuo() {
    return "MachineTaskSchedulingIndividualBuilder";
}

MachineTaskSchedulingIndividualBuilder::~MachineTaskSchedulingIndividualBuilder() {
    //dtor
}
