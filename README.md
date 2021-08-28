# Tracker_AerialRobotics

Aerial Robotics: Mini Project

- Implementing Trackers from OpenCV.

- cvBridge

- cameraIntegration

---

## Setup

To run .py files:

- If Miniconda is installed,

```bash
conda create -n cvenv python=3.8 # Or above
conda activate cvenv
conda install -c conda-forge opencv
python3 <FileName>.py
```

- Otherwise,

```bash
sudo pip install pipenv
pipenv --python 3.8 # Works only for a root directory
pip install opencv-python
```

---

## `./Trackers`

Implemented KCF Trackers as .py and .cpp  
Building through cmake.

Implemented CSRT Tracker as .cpp  
Building through cmake.

[DataSet](http://crowley-coutaz.fr/jlc/Courses/2020/GVR.VO/AVDIAR-videos+BBoxs/) for video tracking.

---

## `./Tracker-firefly`

Attaching a camera to firefly provided by this [repo](https://github.com/ethz-asl/rotors_simulator), tracking a Husky by varying the pose of both, Husky and Firefly.
