#pragma once
namespace frc
{
namespace lcchs
{
class RobotVision
{
public:
  RobotVision();
  void RobotVisionInit();

private:
  static void VisionThread();
};
} // namespace lcchs
} // namespace frc
