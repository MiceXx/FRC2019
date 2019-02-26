#include "Robot.h"
#include <iostream>

namespace frc
{
namespace lcchs
{

void Robot::operateHinges()
{
  double rootWristCommand;
  wristCommand = driveStation.getRightHandY();

  // if (wristCommand < 0)
  // {
  //   rootWristCommand = -sqrt(abs(wristCommand));
  // }
  // else
  // {
  //   rootWristCommand = sqrt(wristCommand);
  // }

  double wristError = wristDestination - wristPosition;
  double wristSpeed = 0;

  currentTime = Timer().GetFPGATimestamp();

  if( (std::abs(wristError)) > 0.01 && (currentTime > wristStopTime) ){
    wristStopTime = currentTime + 0.5 * std::abs(wristError);
  }


  if(std::abs(wristCommand) > 0.05){

    wristSpeed = wristCommand;

  }
  else if(currentTime < wristStopTime){
    
    // if(wristError > 0 ){
    //   wristSpeed = -0.5;
    // }
    // else {
    //   wristSpeed = 0.5;
      
    // }
  }
  else {
  
  }
  wrist.rotateHinges(wristSpeed);
  wristPosition -= wristSpeed * 0.02;
}

} //namespace lcchs
} //namespace frc