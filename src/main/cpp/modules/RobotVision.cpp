#include "RobotVision.h"
#include "GripPipeline.h"

#include <thread>

#include <cameraserver/CameraServer.h>
#include <frc/TimedRobot.h>
#include <opencv2/core/core.hpp>
#include <opencv2/core/types.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <wpi/raw_ostream.h>

namespace frc
{
namespace lcchs
{

// rise and grind gamer time.
RobotVision::RobotVision()
{
}

void RobotVision::RobotVisionInit()
{
#if defined(__linux__)
  std::thread visionThread(VisionThread);
  visionThread.detach();
#else
  wpi::errs() << "Vision only available on Linux.\n";
  wpi::errs().flush();
#endif
}

#if defined(__linux__)

void RobotVision::VisionThread()
{
  // Get the USB camera from CameraServer
  cs::UsbCamera camera =
      frc::CameraServer::GetInstance()->StartAutomaticCapture();
  // Set the resolution
  camera.SetResolution(320, 240);

  // Get a CvSink. This will capture Mats from the Camera
  cs::CvSink cvSink = frc::CameraServer::GetInstance()->GetVideo();
  // Setup a CvSource. This will send images back to the Dashboard
  cs::CvSource outputStream =
      frc::CameraServer::GetInstance()->PutVideo("Rectangle", 640, 480);
}

#endif
} // namespace lcchs
} // namespace frc