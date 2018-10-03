#ifndef BINOCS_EXPERIMENTS_FLOW_H
#define BINOCS_EXPERIMENTS_FLOW_H

#include <ostream>

#include <boost/filesystem/operations.hpp>

#include <DGtal/helpers/StdDefs.h>
#include <DGtal/shapes/parametric/AccFlower2D.h>
#include <DGtal/shapes/parametric/Ball2D.h>
#include <DGtal/shapes/parametric/NGon2D.h>
#include <DGtal/shapes/parametric/Ellipse2D.h>
#include <DGtal/shapes/Shapes.h>
#include <DGtal/io/writers/GenericWriter.h>

#include <SCaBOliC/Utils/Utils.h>

#include <DIPaCUS/base/Representation.h>

#include <BinOCS/Application/BoundaryCorrection/BCApplication.h>

#include "utils.h"
#include "MockDistribution.h"


namespace BinOCS
{
    namespace Lab
    {
        namespace Illustration
        {
            class Flow
            {
            private:
                typedef DGtal::Z2i::DigitalSet DigitalSet;
                typedef DGtal::Z2i::Space Space;
                typedef DGtal::Z2i::Domain Domain;

                typedef DGtal::Shapes<Domain> Shapes;
                typedef DIPaCUS::Representation::DigitalSetToImage::Image2D Image2D;

                typedef DGtal::AccFlower2D<Space> Flower;
                typedef DGtal::Ball2D<Space> Ball;
                typedef DGtal::NGon2D<Space> NGon;
                typedef DGtal::Ellipse2D<Space> Ellipse;

                typedef BinOCS::Application::BCApplication::BCSolution Solution;
                typedef BinOCS::Application::BCApplication::BCConfigData ConfigData;

                typedef BinOCS::Lab::Utils::MockDistribution MockDistribution;

            private:
                struct TableEntry
                {
                    TableEntry(Solution& solution, std::string name):solution(solution),
                                                                     name(name){}
                    Solution solution;
                    std::string name;
                };

            public:
                Flow(std::string outputFolder, bool exportRegions);

            private:
                template<class TShape>
                void shapeFlow(TShape s,
                               int maxIt,
                               double h,
                               std::string name,
                               std::string imageOutputFolder,
                               bool exportRegions);

                void exportImageFromDigitalSet(const DigitalSet& ds,
                                               const std::string& outputFilepath);

                void exportImageFromDigitalSet(const DigitalSet& ds,
                                               const Domain& domain,
                                               const std::string& outputFilepath);

                ConfigData defaultConfigData(MockDistribution& frDistr,
                                             MockDistribution& bkDistr);
		void outputElasticaEnergy(const DigitalSet& ds, std::ostream& os);
                void printTable(const std::vector<TableEntry> &entries,
                                std::ostream &os);
            };
        }
    }
}

#include "Flow.hpp"

#endif //BINOCS_EXPERIMENTS_FLOW_H
