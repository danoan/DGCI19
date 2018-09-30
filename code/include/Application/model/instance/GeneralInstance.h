#ifndef BINOCS_EXPERIMENTS_BCORRECTIONINSTANCE_H
#define BINOCS_EXPERIMENTS_BCORRECTIONINSTANCE_H

#include <vector>
#include <ostream>

#include <Application/utils.h>
#include <Application/model/OptOutput.h>

namespace BinOCS
{
    namespace Lab
    {
        namespace Model
        {
            template<typename TInput>
            struct GeneralInstance
            {
            public:
                typedef TInput Input;
                typedef OptOutput Output;

            public:
                GeneralInstance(std::string instanceName):instanceName(instanceName){};

                void write(std::ostream& os,
                           const std::string& outputFolder="-");

            public:
                std::vector<TInput> vectorOfInput;
                std::vector<Output> vectorOfOutput;

            private:
                std::string instanceName;
            };

        }
    }
}

#include "GeneralInstance.hpp"

#endif //BINOCS_EXPERIMENTS_BCORRECTIONINSTANCE_H
