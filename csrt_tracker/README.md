# Package implementing CSRT_Tracker

This package is self sufficient (add to a catkin workspace), and uses firefly from `rotors_ws` as the mav by default. All relevant files of the mav have been transferred to this package.  
The packages you will need to run the `main.launch` are `gazebo_ros` and `husky_gazebo`, both of which can be easily installed.
The other relevant files from `rotors_ws` are copied here as well.  
If the `hovering_example` node shows include errors, you will need to install rotors_ws and symlink (just point to) `rotors_ws/devel/include/mav_msgs`

Plans are to implement a node that takes all relevant topic data to find world coordinates of the prey, and publish on `prey_needed_coordinates` topic.  
This will in turn let us decide the relative position of the mav and the prey, thus enabling to follow it by changing /firefly/command/pose accordingly.

Note that all header files in `./include/mav_msgs/` with capital first letters, are from `rotors_ws/devel/include/mav_msgs`, used to be symlinks, but used `sed` to copy the contents to an actual file.

> **To be edited out later**  
> Currently `catkin build` yields errors similar to [this](https://github.com/ArduPilot/ardupilot_wiki/issues/194).  
> If the current state doesn't work, install rotors-simulator, copy all src files (and add the header files too) into rotors_gazebo, update CMakeLists.txt, and try again.
