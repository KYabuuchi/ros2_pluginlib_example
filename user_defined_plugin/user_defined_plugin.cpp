#include <base_interface/base_interface.hpp>

namespace user_defined_plugin
{
class UserDefinedPlugin1 : public base_interface::BaseInterface
{
public:
  void init(rclcpp::Node& node) override
  {
    logger_ = std::make_shared<rclcpp::Logger>(node.get_logger());
  }

  void execute() override
  {
    RCLCPP_INFO_STREAM(*logger_, "user defined plugin 1");
  }

private:
  std::shared_ptr<rclcpp::Logger> logger_;
};

class UserDefinedPlugin2 : public base_interface::BaseInterface
{
public:
  void init(rclcpp::Node& node) override
  {
    logger_ = std::make_shared<rclcpp::Logger>(node.get_logger());
  }

  void execute() override
  {
    RCLCPP_INFO_STREAM(*logger_, "user defined plugin 2");
  }

private:
  std::shared_ptr<rclcpp::Logger> logger_;
};

}  // namespace user_defined_plugin

#include <pluginlib/class_list_macros.hpp>
PLUGINLIB_EXPORT_CLASS(user_defined_plugin::UserDefinedPlugin1, base_interface::BaseInterface)
PLUGINLIB_EXPORT_CLASS(user_defined_plugin::UserDefinedPlugin2, base_interface::BaseInterface)