#include "Robot.h"

#include <iostream>
#include <string>

/**
 * This autonomous (along with the chooser code above) shows how to select
 * between different autonomous modes using the dashboard. The sendable chooser
 * code works with the Java SmartDashboard. If you prefer the LabVIEW Dashboard,
 * remove all of the chooser code and uncomment the GetString line to get the
 * auto name from the text box below the Gyro.
 *
 * You can add additional auto modes by adding additional comparisons to the
 * if-else structure below with additional strings. If using the SendableChooser
 * make sure to add them to the chooser code above as well.
 */

namespace frc {
    namespace lcchs{
      void Robot::AutonomousInit() {
        m_autoSelected = m_chooser.GetSelected();
        // m_autoSelected = SmartDashboard::GetString("Auto Selector",
        //     kAutoNameDefault);
        std::cout << "Auto selected: " << m_autoSelected << std::endl;

        /* start of networking tables*/
        auto dataTable = networkTableInstance.GetTable("datatable");
        auto smartDashboard = networkTableInstance.GetTable("SmartDashboard");
        xEntry = dataTable->GetEntry("X");
        yEntry = dataTable->GetEntry("Y");
        /* end of networking tables*/

        if (m_autoSelected == kAutoNameCustom) {
          // Custom Auto goes here
        } else {
          // Default Auto goes here
        }
      }
    }
}
