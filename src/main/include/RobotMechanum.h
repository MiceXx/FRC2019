#pragma once

#include <frc/Joystick.h>
#include <frc/PWMVictorSPX.h>
#include <frc/TimedRobot.h>
#include <frc/drive/MecanumDrive.h>

class RobotMechanum : public frc::TimedRobot {
 public:
  void RobotInit() override;

  void TeleopPeriodic() override;

 private:
  static constexpr int kFrontLeftChannel = 0;
  static constexpr int kRearLeftChannel = 1;
  static constexpr int kFrontRightChannel = 2;
  static constexpr int kRearRightChannel = 3;

  static constexpr int kJoystickChannel = 0;

  frc::PWMVictorSPX m_frontLeft{kFrontLeftChannel};
  frc::PWMVictorSPX m_rearLeft{kRearLeftChannel};
  frc::PWMVictorSPX m_frontRight{kFrontRightChannel};
  frc::PWMVictorSPX m_rearRight{kRearRightChannel};
  frc::MecanumDrive m_robotDrive{m_frontLeft, m_rearLeft, m_frontRight,
                                 m_rearRight};

  frc::Joystick m_stick{kJoystickChannel};
};
