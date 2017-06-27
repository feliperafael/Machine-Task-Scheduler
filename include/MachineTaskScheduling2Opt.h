#ifndef MACHINETASKSCHEDULING2OPT_H
#define MACHINETASKSCHEDULING2OPT_H

#include "LocalSearch.h"
#include "MachineTaskSchedulingParser.h"
#include "MachineTaskSchedulingDatabase.h"

class MachineTaskScheduling2Opt : public LocalSearch
{
    public:
        MachineTaskScheduling2Opt();
        virtual ~MachineTaskScheduling2Opt();

        virtual Individual* doLocalSearch(Individual* s1);
        virtual Individual* opt2(Individual* s1);
        virtual Individual* neh(Individual* s1);

        void setParser(Parser* parser_){
            parser = dynamic_cast<MachineTaskSchedulingParser*>(parser_);
        }

        MachineTaskSchedulingParser* parser;

        void setDatabase(MachineTaskSchedulingDatabase* data_){
            data = data_;
        }

        MachineTaskSchedulingDatabase* data;

    protected:

    private:
};

#endif // MACHINETASKSCHEDULING2OPT_H
