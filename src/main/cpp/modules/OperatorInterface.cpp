#include <frc/smartdashboard/SmartDashboard.h>

#include "OperatorInterface.hpp"


namespace  frc{
namespace  lcchs{

//Slider IO
void OperatorInterface::setSlider(int sliderId, double value)
{
  std::string prefix= "DB/Slider ";
  SmartDashboard::PutNumber(prefix +std::to_string(sliderId) , value);
}

double OperatorInterface::getSlider(int sliderId, double preset)
{
  std::string prefix= "DB/Slider ";
  return SmartDashboard::GetNumber(prefix +std::to_string(sliderId) , preset);
}

//String IO
void OperatorInterface::setString(int stringId, std::string value)
{
  std::string prefix= "DB/String ";
  SmartDashboard::PutString(prefix +std::to_string(stringId) , value);
}

std::string OperatorInterface::getString(int stringId, std::string preset)
{
  std::string prefix= "DB/String ";
  return SmartDashboard::GetString(prefix +std::to_string(stringId) , preset);
}

//Button IO
void OperatorInterface::setButton(int ButtonId, bool value)
{
  std::string prefix= "DB/Button ";
  SmartDashboard::PutNumber(prefix +std::to_string(ButtonId) , value);
}

bool OperatorInterface::getButton(int ButtonId, bool preset)
{
  std::string prefix= "DB/Button ";
  return SmartDashboard::GetNumber(prefix +std::to_string(ButtonId) , preset);
}


//LED IO
void OperatorInterface::setLed(int LedId, bool value)
{
  std::string prefix= "DB/LED ";
  SmartDashboard::PutNumber(prefix +std::to_string(LedId) , value);
}

bool OperatorInterface::getLed(int LedId, bool preset)
{
  std::string prefix= "DB/LED ";
  return SmartDashboard::GetNumber(prefix +std::to_string(LedId) , preset);
}

//gamepad IO

double OperatorInterface::getLeftHandY()
{
  return gamePad.GetY(XboxController::kLeftHand);

}

bool OperatorInterface::getYButton()
{
  return gamePad.GetYButton();
}

}  // namespace lcchs
} // namespace frc