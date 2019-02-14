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
//#include <frc/drive/MecanumDrive.h>

#include "PowerTrain.hpp"
#include "Manipulator.hpp"

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

  private:
    void gyroResetPos();
    void alignRobot();
    void changeCam();

    double lastButtonpress = 0;

    frc::SendableChooser<std::string> m_chooser;
    const std::string kAutoNameDefault = "Default";
    const std::string kAutoNameCustom = "My Auto";
    std::string m_autoSelected;

    frc::PWMVictorSPX m_left{0};

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

    frc::lcchs::Manipulator manipulator;

    frc::Joystick *jStick = new Joystick(kJoystickChannelone);
    frc::Joystick *jStick2 = new Joystick(kJoystickChanneltwo);
    frc::ADXRS450_Gyro gyro{GyroChannel};

    //joystick buttons
    JoystickButton *button1 = new JoystickButton(jStick, 1);
    JoystickButton *button2 = new JoystickButton(jStick, 2);
    JoystickButton *button3 = new JoystickButton(jStick, 3);
    JoystickButton *button4 = new JoystickButton(jStick, 4);
    JoystickButton *button7 = new JoystickButton(jStick, 7);

    nt::NetworkTableEntry xEntry;
    nt::NetworkTableEntry yEntry;
    nt::NetworkTableInstance networkTableInstance = nt::NetworkTableInstance::GetDefault();

    /*
    WPI_TalonSRX m_frontLeft{kFrontLeftChannel};
    WPI_TalonSRX m_rearLeft{kRearLeftChannel};
    WPI_TalonSRX m_frontRight{kFrontRightChannel};
    WPI_TalonSRX m_rearRight{kRearRightChannel};
    frc::MecanumDrive m_robotDrive{m_frontLeft, m_rearLeft, m_frontRight, m_rearRight};
*/
    PowerTrain powerTrain;
};

} // namespace lcchs
} // namespace frc