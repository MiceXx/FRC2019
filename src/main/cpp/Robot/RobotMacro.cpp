#include "Robot.h"

#include <fstream>
#include <iostream>
#include <string.h>

namespace frc
{
namespace lcchs
{
void Robot::recordDrive()
{
    std::ofstream fs;
    const std::string filename = "auto_macro.txt";

    fs.open(filename);
    fs << powerTrain.getSpeedFL() << ",";
    fs << powerTrain.getSpeedFR() << ",";
    fs << powerTrain.getSpeedRL() << ",";
    fs << powerTrain.getSpeedRR();

    fs.close();
}

} // namespace lcchs
} // namespace frc