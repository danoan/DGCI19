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

void defaultValues(Model::GrabCorrectionInput& gci)
{
    gci.bcInput.maxIterations=1;
    gci.bcInput.estimatingBallRadius=3.0;
    gci.bcInput.sqTermWeight=1.0;
    gci.bcInput.lengthTermWeight=0.5;
    gci.bcInput.dataTermWeight=0.25;
}

void readInput(Model::GrabCorrectionInput& gci,
               int argc,
               char** argv)
{
    defaultValues(gci);

    int opt;
    while( (opt=getopt(argc,argv,"c:d:l:b:i:"))!=-1)
    {
        switch(opt)
        {
            case 'c':
                gci.bcInput.sqTermWeight = atof(optarg);
                break;
            case 'd':
                gci.bcInput.dataTermWeight = atof(optarg);
                break;
            case 'l':
                gci.bcInput.lengthTermWeight = atof(optarg);
                break;
            case 'b':
                gci.bcInput.estimatingBallRadius = atoi(optarg);
                break;
            case 'i':
                gci.bcInput.maxIterations = atoi(optarg);
                break;

            default:
                std::cerr << "Usage: %s IMAGE_PATH [-c Curvature Weight] "
                            "[-d Data Weight] [-l Length Weight] [-b Ball Radius] "
                            "[-i Max Iterations]" << std::endl;

        }
    }

    gci.imagePath = argv[1];
}

int main(int argc, char** argv)
{
    Model::GrabCorrectionInput input("My Input");
    readInput(input,argc,argv)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  ;
    interactive(input);

    return 0;
}

