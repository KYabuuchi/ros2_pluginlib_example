#include <base_interface/base_interface.hpp>
#include <pluginlib/class_loader.hpp>
#include <rclcpp/rclcpp.hpp>

namespace plugin_loader
{
class PluginLoader : public rclcpp::Node
{
public:
  PluginLoader() : Node("plugin_loader"),
                   plugin_loader_("base_interface", "base_interface::BaseInterface")
  {
    const std::string plugin_name = declare_parameter<std::string>("plugin_name", "plugin1");
    load_plugin(*this, plugin_name);

    auto on_timer = [this]() -> void {
      if (plugin_) {
        plugin_->execute();
      }
    };
    timer_ = rclcpp::create_timer(this, this->get_clock(), rclcpp::Rate(1).period(), std::move(on_timer));
  }

private:
  rclcpp::TimerBase::SharedPtr timer_;
  std::shared_ptr<base_interface::BaseInterface> plugin_{nullptr};
  pluginlib::ClassLoader<base_interface::BaseInterface> plugin_loader_;

  void load_plugin(rclcpp::Node& node, const std::string& name)
  {
    if (plugin_loader_.isClassAvailable(name)) {
      plugin_ = plugin_loader_.createSharedInstance(name);
      plugin_->init(node);
    } else {
      RCLCPP_ERROR_STREAM(get_logger(), "The plugin '" << name << "' is not available.");
      exit(EXIT_FAILURE);
    }
  }
};
}  // namespace plugin_loader

int main(int argc, char* argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<plugin_loader::PluginLoader>());
  rclcpp::shutdown();
  return 0;
}
