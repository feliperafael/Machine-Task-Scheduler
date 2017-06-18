#ifndef MACHINETASKSCHEDULINGINDIVIDUALBUILDER_H
#define MACHINETASKSCHEDULINGINDIVIDUALBUILDER_H

#include "IndividualBuilder.h"
#include "Database.h"
#include "MachineTaskSchedulingIndividual.h"
#include "MachineTaskSchedulingDatabase.h"

class MachineTaskSchedulingIndividualBuilder {
public:
    MachineTaskSchedulingDatabase * database;
    MachineTaskSchedulingIndividualBuilder(Database * database);
    virtual ~MachineTaskSchedulingIndividualBuilder();

    Individual * generateIndividuo();
    string nameIndividuo();

protected:

private:
};

#endif // MACHINETASKSCHEDULINGINDIVIDUALBUILDER_H
