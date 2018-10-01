#include "Illustration/AroundBoundaryReasoning.h"

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
    AroundBoundaryReasoning abr(outputDir + "/illustration");
    std::cout << abr.t << std::endl;
    return 0;
}

