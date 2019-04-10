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
#include "Boot.hpp"

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
  void robotClimb();
  void writeDebugInfo();
  void readInput();

private:
  void alignRobot();
  void changeCam();
  void wheelDriftFix();

  //GYRO ANGLE
  double gyroAngle;

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

  frc::lcchs::Boot boot;

  frc::Joystick *jStick = new Joystick(kJoystickChannelone);
  frc::ADXRS450_Gyro gyro{GyroChannel};

  //joystick buttons
  JoystickButton *button1 = new JoystickButton(jStick, 1);
  JoystickButton *button2 = new JoystickButton(jStick, 2);
  JoystickButton *button3 = new JoystickButton(jStick, 3);
  JoystickButton *button4 = new JoystickButton(jStick, 4);
  // JoystickButton *button5 = new JoystickButton(jStick, 5);
  // JoystickButton *button6 = new JoystickButton(jStick, 6);
  JoystickButton *button7 = new JoystickButton(jStick, 7);
  JoystickButton *button8 = new JoystickButton(jStick, 8);
  JoystickButton *button9 = new JoystickButton(jStick, 9);
  JoystickButton *button10 = new JoystickButton(jStick, 10);

  JoystickButton *button14 = new JoystickButton(jStick, 14);

  nt::NetworkTableInstance networkTableInstance = nt::NetworkTableInstance::GetDefault();

  frc::lcchs::OperatorInterface driveStation;

  //Override switch
  bool overrideSwtich = false;

  // lift
  int liftPosition;
  int liftVelocity;
  double liftCommand = 0;
  double liftCommandFilter = 0;
  bool liftReset = false;
  int gamePadPOV;
  int liftDestination;
  bool elevatorAutoMode = false;
  int ballOpenings[4] = {0, -16300, -38000, -51200};
  int hatchOpenings[4] = {0, -3800, -26000, -47000};
  int liftLevel = 0;
  bool selectBall = false;
  bool selectHatch = false;
  int loadingStation = -30000;
  bool hatchPickup = false;
  bool hatchRelease = false;
  int liftHatchOffset = 0;

  //LIMELIGHT
  std::shared_ptr<NetworkTable> limelightTable;

  bool useCam = true;

  //Boot For Climb
  int bootDestination;
  int bootOrientations[3] = {0, -1000, -2000};
  int bootLevel = 0;

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
