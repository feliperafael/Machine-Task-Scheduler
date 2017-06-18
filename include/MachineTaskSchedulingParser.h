#ifndef MACHINETASKSCHEDULINGPARSER_H
#define MACHINETASKSCHEDULINGPARSER_H

#include "Parser.h"
#include "MachineTaskSchedulingIndividual.h"
#include "MachineTaskSchedulingDatabase.h"

class MachineTaskSchedulingParser : public Parser {
public:
    MachineTaskSchedulingParser();
    virtual ~MachineTaskSchedulingParser();

    double Evaluate(Individual* s);
    string nameParser();
    void setDatabase(Database* data);

    MachineTaskSchedulingDatabase* database;

protected:

private:
};

#endif // MACHINETASKSCHEDULINGPARSER_H
