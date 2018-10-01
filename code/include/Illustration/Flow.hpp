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
    gd.init(shape.getLowerBound() + DGtal::Z2i::RealPoint(-0,-0),
            shape.getUpperBound() + DGtal::Z2i::RealPoint(0,0),h);


    DigitalSet ds(gd.getDomain());
    Shapes::digitalShaper(ds,gd);


    MockDistribution frDistr;
    MockDistribution bkDistr;
    ConfigData configData = defaultConfigData(frDistr,bkDistr);

    std::string currImagePath = flowFolder + "/0.pgm";
    exportImageFromDigitalSet(ds,currImagePath);

    std::vector<TableEntry> entries;
    cv::Mat img;
    int i=1;
    do
    {
        img = cv::imread(currImagePath,CV_LOAD_IMAGE_COLOR);
        Domain solutionDomain(Point(0,0),Point(img.cols,img.rows));
        Solution solution(solutionDomain);
        BinOCS::Application::BCApplication BCA(solution,1,img,configData);

        entries.push_back(TableEntry(solution,"IT " + std::to_string(i)));

        currImagePath = flowFolder + "/" + std::to_string(i) + ".pgm";
        exportImageFromDigitalSet(solution.outputDS,currImagePath);
        ++i;
    }while(i<maxIt);

    os << "Image: " << imageName << "/n"
       << std::endl;

    printTable(entries,os);

}