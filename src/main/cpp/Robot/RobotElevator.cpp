#include "Robot.h"

namespace frc {
namespace lcchs{

  void Robot::operateLift()
  {
    int currentPov=driveStation.getPov();
    
    //lift Ops
    liftPosition=manipulator.getPosition();
    liftVelocity=manipulator.getVelocity();
    liftCommand=driveStation.getLeftHandY();
    liftReset=driveStation.getYButton();
    

    if (gamePadPOV!=0 && currentPov==0)
    {
        liftDestination+=50000;    
    }

    if (gamePadPOV!=180 && currentPov==180)
    {
        liftDestination-=50000;    
    }
  
    gamePadPOV=currentPov;
   

    if (liftReset)
    {
        manipulator.resetEncoder();
        liftDestination = manipulator.getPosition();
    }
    else if (abs(liftCommand)>0.05)
    {
        manipulator.moveLift(liftCommand);
        liftDestination=liftPosition;
    }
    else
    {
     manipulator.setPosition(liftDestination);
    }

                 

    driveStation.setString( 5,std::to_string(liftPosition) );

    driveStation.setString( 6,std::to_string(liftVelocity) );

    driveStation.setString( 7,std::to_string(liftCommand) );

    driveStation.setString( 8,std::to_string(liftDestination) );

    driveStation.setString( 9,std::to_string(gamePadPOV) );

  }//operateLift()

}//namespace lcchs
}//namespace frc





