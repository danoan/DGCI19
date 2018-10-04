#include <BinOCS/Application/GrabCut/GrabCutApplication.h>

#include <Application/modes/Interactive.h>


namespace BinOCS
{
    namespace Lab
    {
        std::string projectDir = PROJECT_DIR;
        std::string imageDir = projectDir + "/images";
        std::string outputDir = projectDir + "/output";
    }
}


using namespace BinOCS::Lab;
using namespace BinOCS::Lab::Experiments;


void interactive(const Model::GrabCorrectionInput& gci)
{
    typedef BinOCS::Application::GrabCutApplication GCApplication;

    boost::filesystem::path pFile(gci.imagePath);
    boost::filesystem::path pOutputFolder(outputDir);

    pOutputFolder.append("Interactive");
    pOutputFolder.append(pFile.filename().string());

    ExpInteractive(gci,pOutputFolder.string());
}

int main(int argc, char** argv)
{
    Model::GrabCorrectionInput input("My Input");
    Utils::readInput(input,argc,argv)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  ;
    interactive(input);

    return 0;
}

