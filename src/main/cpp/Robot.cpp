#include "Robot.h"

namespace frc {
namespace lcchs{

void Robot::TestPeriodic() 
{
    writeDebugInfo();
    TeleopPeriodic();
}

void Robot::writeDebugInfo() 
{

     //Get the debug information selection for the PC Dashboard.
     bool button0 = driveStation.getButton(0);
     bool button1 = driveStation.getButton(1);
     bool button2 = driveStation.getButton(2);
     bool button3 = driveStation.getButton(3);

     frc::SmartDashboard::PutNumber("Joystick X", jStick->GetX());
     frc::SmartDashboard::PutNumber("Joystick Y", jStick->GetY());

     //Drive the PC Dashboard compatible fields.
     if (button0 )
     {
         liftDebug    = true;
         rollerDebug  = false;
         hingeDebug   = false;
         grappleDebug = false;
     }
     else if (button1 )
     {
         liftDebug    = false;
        rollerDebug  = true;
        hingeDebug   = false;
        grappleDebug = false;
    }
    else if (button2 )
    {
        liftDebug    = false;
        rollerDebug  = false;
        hingeDebug   = true;
        grappleDebug = false;

    }
    else if (button3 )
    {
        liftDebug    = false;
        rollerDebug  = false;
        hingeDebug   = false;
        grappleDebug = true;

    }
    else
    {
        liftDebug    = false;
        rollerDebug  = false;
        hingeDebug   = false;
        grappleDebug = false;
    
    }
      
    if(liftDebug) 
    {
        driveStation.setString(0,"Lift Debug");
        
        driveStation.setString(1, "command: " + std::to_string(liftCommand));

        driveStation.setString(2, "level: " + std::to_string(liftLevel));

        driveStation.setString(3, "destination: " + std::to_string(liftDestination));

        driveStation.setString(4, "POV: " + std::to_string(gamePadPOV));

        driveStation.setString(5, "Select DB Button 0");

        driveStation.setString(6, "position: " + std::to_string(liftPosition));
       
        driveStation.setString(7, "velocity: " + std::to_string(liftVelocity));
       
        driveStation.setString(8, "t/b: " + std::to_string(liftRaised) + " " + std::to_string(liftLowered) );   

        driveStation.setString(9, " " );
    }
    else if (rollerDebug)
    {
        driveStation.setString(0,"Roller Debug");
        
        driveStation.setString(1, "capture: " + std::to_string(captureCommand));

        driveStation.setString(2, "shoot: " + std::to_string(shootCommand));

        driveStation.setString(3, " " );

        driveStation.setString(4, " " );

        driveStation.setString(5, "Select DB Button 1");

        driveStation.setString(6, " " );
       
        driveStation.setString(7, " " );
       
        driveStation.setString(8, " " );

        driveStation.setString(9, " " );
    }
    else if (hingeDebug)
    {
        driveStation.setString(0,"Hinge Debug");
        
        driveStation.setString(1, "command: " + std::to_string(wristCommand));

        driveStation.setString(2, "level: " + std::to_string(liftLevel));

        driveStation.setString(3, "destination: " + std::to_string(wristDestination));

        driveStation.setString(4, "current time: " + std::to_string(currentTime));

        driveStation.setString(5, "Select DB Button 2");

        driveStation.setString(6, "position: " + std::to_string(wristPosition));
       
        driveStation.setString(7, "stop time: " + std::to_string(wristStopTime));
       
        driveStation.setString(8, "t/b: " + std::to_string(wristRaised) + " " + std::to_string(wristLowered) );

        driveStation.setString(9, " " );
    }
        else if (grappleDebug)
    {
        driveStation.setString(0,"Grapple Debug");
        
        driveStation.setString(1, "");

        driveStation.setString(2, "" );

        driveStation.setString(3, "" );

        driveStation.setString(4, " " );

        driveStation.setString(5, "Select DB Button 3");

        driveStation.setString(6, "" );
       
        driveStation.setString(7, " " );
       
        driveStation.setString(8, " " );

        driveStation.setString(9, " " );
    }
    else
    {
        //Drive debug by default.

        driveStation.setString( 0,"Drive Debug" );

        driveStation.setString(1, "stickX: " + std::to_string(jStick->GetX()));

        driveStation.setString(2, "stickY: " + std::to_string(jStick->GetY()));

        driveStation.setString(3, "stickZ: " + std::to_string(jStick->GetZ()));

        driveStation.setString(4, "Gyro: " + std::to_string(gyroAngle));

        driveStation.setString(5, "Default Selection");

        driveStation.setString(6, " " );

        driveStation.setString(7, " " );

        driveStation.setString(8, " " );

        driveStation.setString(9, " " );
    }

    driveStation.setLed(0, liftDebug);
    driveStation.setLed(1, rollerDebug);
    driveStation.setLed(2, hingeDebug);
    driveStation.setLed(3, grappleDebug);



    frc::SmartDashboard::PutNumber("Joystick X", jStick->GetX());
    frc::SmartDashboard::PutNumber("Joystick Y", jStick->GetY());

    // if (button14->Get())
    // {
    //     double now = Timer().GetFPGATimestamp();
    //     double debounceTime = 1;
    //     if (now - lastButtonpress > debounceTime)
    //     {
    //         changeCam();
    //         lastButtonpress = now;
    //     }
    // }

    //Set Scaling
    double scaling = driveStation.getSlider(0);

    if (scaling < 0.)
    {
        scaling = 0.;
    }
    else if (scaling > 5.)
    {
        scaling = 5.;
    }

    driveOutput = 1 / (scaling + 1);
    liftOutput = 1 / (scaling + 1);
    powerTrain.setScaling(driveOutput);
    elevator.setScaling(liftOutput);
}


}   // namespacelcchs
}  // namespacefrc
