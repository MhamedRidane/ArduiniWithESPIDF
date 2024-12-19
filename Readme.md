# 🚀 Getting started

## 🐧 Linux (Ubuntu)

1. [Install VSCode](https://code.visualstudio.com/docs/setup/linux)

2. [Install Platformio VSCode extension](https://marketplace.visualstudio.com/items?itemName=platformio.platformio-ide)

```bash
# Download this repo
git clone https://github.com/MhamedRidane/Gate_to_platformio_esp32.git
# Open it on VSCode
cd Gate_to_platformio_esp32
code .
```

```ini
# To choose the micro-ros distrobution
board_microros_distro = humble
# To select the communication protocol
board_microros_transport = serial
# To add the micro-ros library
lib_deps =
    https://github.com/micro-ROS/micro_ros_platformio
# Note : Make sure your MCU memories are enough to import and use micro-ros library.
```
