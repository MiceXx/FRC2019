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

    gyro.Calibrate();
    roller.init();
    boot.initializeBoot();

    limelightTable = networkTableInstance.GetTable("limelight");

    elevator.initializeElevator();

    wrist.initializeHinges();

    period = GetPeriod();
}
} // namespace lcchs
} // namespace frc