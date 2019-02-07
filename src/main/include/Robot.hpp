#pragma once

#include <string>

#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/PWMVictorSPX.h>
#include <frc/Joystick.h>
#include <frc/ADXRS450_Gyro.h>
#include "Manipulator.hpp"
#include <frc/buttons/JoystickButton.h>
#include <networktables/NetworkTable.h>
#include <networktables/NetworkTableEntry.h>
#include <networktables/NetworkTableInstance.h>

<<<<<<< HEAD:src/main/include/Robot.hpp
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
=======
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
    void setRobotScaling();
    void gyroResetPos();

  private:
    frc::SendableChooser<std::string> m_chooser;
    const std::string kAutoNameDefault = "Default";
    const std::string kAutoNameCustom = "My Auto";
    std::string m_autoSelected;

    frc::PWMVictorSPX m_left{0};
    
    frc::Joystick* jStick = new Joystick(0);
    static constexpr int kJoystickChannelone = 0;

    static constexpr int kJoystickChanneltwo = 1;

    static constexpr frc::SPI::Port GyroChannel = frc::SPI::kOnboardCS0;

    frc::lcchs::PowerTrain powerTrain; 

    frc::lcchs::Manipulator manipulator;

    frc::Joystick m_stick{kJoystickChannelone};
    
    frc::Joystick m_sticktwo{kJoystickChanneltwo};
    frc::ADXRS450_Gyro gyro{GyroChannel};
    
    //joystick buttons
    JoystickButton*  button1 = new JoystickButton(jStick, 1);
    JoystickButton*  button2 = new JoystickButton(jStick, 2);
    JoystickButton*  button3 = new JoystickButton(jStick, 3);
    JoystickButton*  button4 = new JoystickButton(jStick, 4);

    nt::NetworkTableEntry xEntry;
    nt::NetworkTableEntry yEntry;
    nt::NetworkTableInstance networkTableInstance = nt::NetworkTableInstance::GetDefault();

  };

  }   // namespacelcchs
>>>>>>> 467fe5552e190cdea959fe280ce1239d6ae0316c:src/main/include/Robot.h
}  // namespacefrc