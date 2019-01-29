#include "RobotMechanum.h"

#include <frc/Joystick.h>
#include <frc/PWMVictorSPX.h>
#include <frc/TimedRobot.h>
#include <frc/drive/MecanumDrive.h>

void RobotMechanum::RobotInit() {
    // Invert the left side motors. You may need to change or remove this to
    // match your robot.
    m_frontLeft.SetInverted(true);
    m_rearLeft.SetInverted(true);
}

void RobotMechanum::TeleopPeriodic() {
    /* Use the joystick X axis for lateral movement, Y axis for forward
        * movement, and Z axis for rotation.
        */
    m_robotDrive.DriveCartesian(m_stick.GetX(), m_stick.GetY(), m_stick.GetZ());
}