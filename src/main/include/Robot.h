#pragma once

#include <string>

#include "PowerTrain.hpp"
#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/PWMVictorSPX.h>
#include <frc/Joystick.h>
#include <frc/ADXRS450_Gyro.h>
#include "Manipulator.hpp"
#include <frc/buttons/JoystickButton.h>

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

  frc::lcchs::PowerTrain mecanumDrive; 

  frc::lcchs::Manipulator dentistryTools;

  frc::Joystick m_stick{kJoystickChannelone};
  
  frc::Joystick m_sticktwo{kJoystickChanneltwo};
  frc::ADXRS450_Gyro gyro{GyroChannel};

  //joystick buttions
   
  JoystickButton* button1 = new JoystickButton(jStick, 1);
  JoystickButton* button2 = new JoystickButton(jStick, 2);
	JoystickButton* button3 = new JoystickButton(jStick, 3);
	JoystickButton* button4 = new JoystickButton(jStick, 4);
	JoystickButton* button5 = new JoystickButton(jStick, 5);
	JoystickButton* button6 = new JoystickButton(jStick, 6);
	JoystickButton* button7 = new JoystickButton(jStick, 7);
	JoystickButton* button8 = new JoystickButton(jStick, 8);

};

}   // namespacelcchs
}  // namespacefrc