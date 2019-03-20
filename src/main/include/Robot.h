#pragma once

#include <string>

#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/PWMVictorSPX.h>
#include <frc/Joystick.h>
#include <frc/ADXRS450_Gyro.h>
#include <frc/buttons/JoystickButton.h>
#include <frc/Timer.h>
#include <networktables/NetworkTable.h>
#include <networktables/NetworkTableEntry.h>
#include <networktables/NetworkTableInstance.h>
#include <cmath>
#include <frc/DigitalInput.h>

#include "OperatorInterface.hpp"
#include "PowerTrain.hpp"
#include "Elevator.hpp"
#include "Hinges.hpp"
#include "Roller.hpp"
#include "RobotVision.h"

namespace frc
{
namespace lcchs
{

class Robot : public frc::TimedRobot
{
public:
  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void TestPeriodic() override;
  void setRobotScaling();

protected:
  void operateLift();
  void activateRoller();
  void operateHinges();
  void writeDebugInfo();
  void readInput();

private:
  void gyroResetPos();
  void alignRobot();
  void changeCam();

  //GYRO ANGLE
  double gyroAngle;

  //ROCKET ANGLES
  // void rotateToAngle45();
  // void rotateToAngle90();
  // void rotateToAngle135();
  // void rotateToAngleNeg45();
  // void rotateToAngleNeg90();
  // void rotateToAngleNeg135();
  void rotateToRocketAngles();

  double lastButtonpress = 0;

  frc::SendableChooser<std::string> m_chooser;
  const std::string kAutoNameDefault = "Default";
  const std::string kAutoNameCustom = "My Auto";
  std::string m_autoSelected;

  static constexpr int kJoystickChannelone = 0;

  static constexpr int kJoystickChanneltwo = 1;

  static constexpr frc::SPI::Port GyroChannel = frc::SPI::kOnboardCS0;

  /*
    static constexpr int kFrontLeftChannel = 1;
    static constexpr int kFrontRightChannel = 2;
    static constexpr int kRearLeftChannel = 3;
    static constexpr int kRearRightChannel = 4;
*/

  //frc::lcchs::PowerTrain powerTrain;

  frc::lcchs::Elevator elevator;

  frc::Joystick *jStick = new Joystick(kJoystickChannelone);
  frc::ADXRS450_Gyro gyro{GyroChannel};

  //joystick buttons
  JoystickButton *button1 = new JoystickButton(jStick, 1);
  JoystickButton *button2 = new JoystickButton(jStick, 2);
  // JoystickButton *button3 = new JoystickButton(jStick, 3);
  // JoystickButton *button4 = new JoystickButton(jStick, 4);
  // JoystickButton *button5 = new JoystickButton(jStick, 5);
  // JoystickButton *button6 = new JoystickButton(jStick, 6);
  // JoystickButton *button7 = new JoystickButton(jStick, 7);
  // JoystickButton *button8 = new JoystickButton(jStick, 8);
  // JoystickButton *button9 = new JoystickButton(jStick, 9);
  // JoystickButton *button10 = new JoystickButton(jStick, 10);

  nt::NetworkTableInstance networkTableInstance = nt::NetworkTableInstance::GetDefault();

  frc::lcchs::OperatorInterface driveStation;

  // lift
  int liftPosition;
  int liftVelocity;
  double liftCommand;
  bool liftReset;
  bool elevatorAutoMode = false;
  int gamePadPOV;
  int liftDestination;
  int ballOpenings[4] = {0, -13600, -34000, -48500};
  int hatchOpenings[4] = {0, -3400, -25400, -46500};
  int liftLevel;
  bool selectBall;
  bool selectHatch;
  int loadingStation = -23600;

  //Roller
  double captureCommand;
  double shootCommand;
  frc::lcchs::Roller roller;

  //Motor output scaling in percent(0-1)
  double liftOutput;
  double driveOutput;

  PowerTrain powerTrain;

  //Wrist hinge
  Hinges wrist;
  double wristCommand;
  double wristDestination;
  double wristPosition = 1;
  double currentTime;
  double wristStopTime;

  double wristAngles[4] = {0, 0.05, 0.05, 0.5};

  // angleTo45 =
  // int wristAngles[3] { 0, angleTo45 }

  // Debug display options
  // Default to power train debug if nothing is selected
  bool liftDebug;
  bool rollerDebug;
  bool hingeDebug;
  bool grappleDebug;

  bool liftRaised;
  bool liftLowered;
  bool wristRaised;
  bool wristLowered;
};

} // namespace lcchs
} // namespace frc
