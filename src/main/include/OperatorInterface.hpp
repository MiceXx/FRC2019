#pragma once

#include <frc/XboxController.h>

namespace frc
{
namespace lcchs
{

class OperatorInterface
{
public:
  void setSlider(int sliderId, double value);

  double getSlider(int sliderId, double preset = 0);

  void setString(int stringId, std::string value);

  std::string getString(int stringId, std::string preset = "default");

  void setButton(int ButtonId, bool value);

  bool getButton(int ButtonId, bool preset = false);

  void setLed(int LedId, bool value);

  bool getLed(int LedId, bool preset = false);

  // controller functions

  double getLeftHandY();
  
  double getRightHandY();

  bool getAButton(); 

  bool getAButton();

  bool getBButton();

  bool getXButton();

  bool getYButton();

  bool getRightBumper();

  bool getLeftBumper();

  int getPov();
  

  private:

    static constexpr int ControllerChannel = 1;
    frc::XboxController gamePad{ControllerChannel};
  double getLeftTrigger();
  double getRightTrigger();

  int getPov();

private:
  static constexpr int ControllerChannel = 1;
  frc::XboxController gamePad{ControllerChannel};
};

} // namespace lcchs
} // namespace frc