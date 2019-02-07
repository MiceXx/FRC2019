#pragma once

#include <string>

#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/PWMVictorSPX.h>
#include <frc/Joystick.h>
#include <frc/ADXRS450_Gyro.h>

#include "Manipulator.hpp"
#include "OperatorInterface.hpp"
#include "PowerTrain.hpp"

namespace frc {
namespace lcchs{

 class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void TestPeriodic() override;

 private:
  frc::SendableChooser<std::string> m_chooser;
  const std::string kAutoNameDefault = "Default";
  const std::string kAutoNameCustom = "My Auto";
  std::string m_autoSelected;

  frc::PWMVictorSPX m_left{0};
  frc::Joystick jStick{0};
  static constexpr int kJoystickChannelone = 0;

  static constexpr int kJoystickChanneltwo = 1;

  static constexpr frc::SPI::Port GyroChannel = frc::SPI::kOnboardCS0;

  frc::lcchs::PowerTrain mecanumDrive; 

  frc::lcchs::Manipulator dentistryTools;

  frc::Joystick m_stick{kJoystickChannelone};
  
  frc::Joystick m_sticktwo{kJoystickChanneltwo};
  frc::ADXRS450_Gyro gyro{GyroChannel};

  frc::lcchs::OperatorInterface driveStation;

  int liftPosition;
  int liftVelocity;
  double liftCommand;
  bool liftReset;
};

}   // namespacelcchs
}  // namespacefrc