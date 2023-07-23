# ros2 pluginlib example

## build

```shell
colcon build --symlink-install --cmake-args -DCMAKE_BUILD_TYPE=Release
```

## execute

```shell
ros2 launch plugin_loader plugin_loader.launch.xml 
```