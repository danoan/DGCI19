#include "Illustration/AroundBoundaryReasoning.h"
#include "Illustration/Flow.h"

namespace BinOCS
{
    namespace Lab
    {

        std::string projectDir = PROJECT_DIR;
        std::string outputDir = projectDir + "/output";
    }
}

using namespace BinOCS::Lab::Illustration;
using namespace BinOCS::Lab;

int main()
{
    AroundBoundaryReasoning abr(outputDir + "/illustration/ab-reasoning");

    Flow flow(outputDir +"/illustration/flow",false);
    return 0;
}

