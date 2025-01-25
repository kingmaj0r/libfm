#include <iostream>
#include <string>
#include "libfm/FileSystem/DriveUtils.hpp"
#include "libfm/utils/Logger.hpp"

int main()
{
  std::string drivePath = "/";

  auto [usedBytes, totalBytes] = DriveUtils::GetDriveUsage(drivePath);

  Logger::Info("Used space: " + std::to_string(usedBytes) + " bytes");
  Logger::Info("Total space: " + std::to_string(totalBytes) + " bytes");

  std::cout << "Used space: " << usedBytes << " bytes" << std::endl;
  std::cout << "Total space: " << totalBytes << " bytes" << std::endl;

  return 0;
}
