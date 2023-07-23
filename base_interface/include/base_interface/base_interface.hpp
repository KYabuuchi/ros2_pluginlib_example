#pragma once
#include <rclcpp/rclcpp.hpp>

namespace base_interface
{
class BaseInterface
{
public:
  virtual ~BaseInterface() = default;
  virtual void init(rclcpp::Node& node) = 0;
  virtual void execute() = 0;
};

}  // namespace base_interface