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
    // void TestPeriodic() override;
    void setRobotScaling();
    void gyroResetPos();

  protected:
    void operateLift();

  private:
    frc::SendableChooser<std::string> m_chooser;
    const std::string kAutoNameDefault = "Default";
    const std::string kAutoNameCustom = "My Auto";
    std::string m_autoSelected;

    frc::PWMVictorSPX m_left{0};
    
    frc::Joystick* jStick = new Joystick(0);
    static constexpr int kJoystickChannelone = 0;


    static constexpr frc::SPI::Port GyroChannel = frc::SPI::kOnboardCS0;

    frc::lcchs::PowerTrain powerTrain; 

    frc::lcchs::Manipulator manipulator;

    frc::Joystick m_stick{kJoystickChannelone};
    
    frc::ADXRS450_Gyro gyro{GyroChannel};
    
    //joystick buttons
    JoystickButton*  button1 = new JoystickButton(jStick, 1);
    JoystickButton*  button2 = new JoystickButton(jStick, 2);
    JoystickButton*  button3 = new JoystickButton(jStick, 3);
    JoystickButton*  button4 = new JoystickButton(jStick, 4);

    nt::NetworkTableEntry xEntry;
    nt::NetworkTableEntry yEntry;
    nt::NetworkTableInstance networkTableInstance = nt::NetworkTableInstance::GetDefault();

    frc::lcchs::OperatorInterface driveStation;

    int liftPosition;
    int liftVelocity;
    double liftCommand;
    bool liftReset;
    int gamePadPOV;
    int liftDestination;

    //Motor output scaling in percent(0-1)
    double liftOutput;
    double driveOutput;

  };

  }   // namespacelcchs
}  // namespacefrc