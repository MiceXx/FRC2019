#include "Robot.h"

#include <iostream>
#include <string>

namespace frc
{
namespace lcchs
{
void Robot::RobotInit()
{
    m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
    m_chooser.AddOption(kAutoNameCustom, kAutoNameCustom);
    frc::SmartDashboard::PutData("Auto Modes", &m_chooser);

    RobotVision *rv = new RobotVision();
    rv->RobotVisionInit();

    powerTrain.initalizePowerTrain();

    liftDestination = elevator.getPosition();

    bootDestination = boot.getPosition();

    gyro.Calibrate();
    roller.init();

    limelightTable = networkTableInstance.GetTable("limelight");

    elevator.initializeElevator();

    wrist.initializeHinges();

}
} // namespace lcchs
} // namespace frc