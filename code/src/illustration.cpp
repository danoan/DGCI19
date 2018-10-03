#include <Illustration/OneImageFlow.h>
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
    //AroundBoundaryReasoning abr(outputDir + "/illustration/ab-reasoning");
    Flow flow(outputDir +"/illustration/flow-b1",false);

    boost::filesystem::path srcImagePath = outputDir +"/illustration/flow-b1";
    boost::filesystem::directory_iterator di(srcImagePath);
    while(di!=boost::filesystem::directory_iterator())
    {
        if( boost::filesystem::is_directory(*di) )
        {
            std::string name = di->path().stem().string();
            std::string outputImagePath = srcImagePath.string() + "/" + name + ".eps";
            OneImageFlow oif(di->path().string(),outputImagePath,2);
        }
        ++di;
    }

    return 0;
}

