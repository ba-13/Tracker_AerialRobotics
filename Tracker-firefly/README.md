# Firefly in `rotors_simulator`

Link to repo is [here](https://github.com/ethz-asl/rotors_simulator).  
The package used is `rotors_gazebo`.  
Make the changes as in this directory, include the node `hovering_subscriber` in `src`, `mav_hovering_camera_example.launch` in `launch` and update the `CMakeLists.txt` and `package.xml`.  
Camera used to integrate in gazebo is provided by another package of the same repository, can be seen in the launch file.  
Husky simulator has been used as the prey, which can be installed by:

```bash
sudo apt install ros-melodic-husky-simulator
```
