#include "Illustration/Flow.h"

using namespace BinOCS::Lab::Illustration;
using namespace BinOCS::Lab;


template<class TShape>
void Flow::shapeFlow(TShape shape,
                     int maxIt,
                     double h,
                     std::string imageName,
                     std::string outputFolder,
                     bool exportRegions)
{
    std::string flowFolder = outputFolder
                             + "/" + imageName;
    boost::filesystem::create_directories(flowFolder);
    std::ofstream os(outputFolder + "/" + imageName + ".txt");


    typedef DGtal::GaussDigitizer<Space,TShape> MyGaussDigitizer;
    MyGaussDigitizer gd;

    gd.attach(shape);
    gd.init(shape.getLowerBound() + DGtal::Z2i::RealPoint(0,0),
            shape.getUpperBound() + DGtal::Z2i::RealPoint(0,0),h);

    DigitalSet ds(gd.getDomain());
    Shapes::digitalShaper(ds,gd);

    MockDistribution frDistr;
    MockDistribution bkDistr;
    ConfigData configData = defaultConfigData(frDistr,bkDistr);

    std::string currImagePath = flowFolder + "/00.pgm";
    exportImageFromDigitalSet(ds,currImagePath);

    os << "Image: " << imageName << "\n"
       << std::endl;

    std::vector<TableEntry> entries;

    Solution solution(gd.getDomain());
    solution.outputDS = ds;
    solution.energyValue = -1;
    entries.push_back(TableEntry(solution,"IT 0"));


    cv::Mat img = cv::imread(currImagePath,CV_LOAD_IMAGE_COLOR);
    Domain solutionDomain(Point(0,0),Point(img.cols-1,img.rows-1));

    int i=1;
    do
    {
        img = cv::imread(currImagePath,CV_LOAD_IMAGE_COLOR);

        Solution solution(solutionDomain);
        BinOCS::Application::BCApplication BCA(solution,1,img,configData);

        entries.push_back(TableEntry(solution,"IT " + std::to_string(i)));

        currImagePath = flowFolder + "/" + Utils::nDigitsString(i,2) + ".pgm";
        exportImageFromDigitalSet(solution.outputDS,solutionDomain,currImagePath);
        ++i;
    }while(i<maxIt);



    printTable(entries,os);

}
