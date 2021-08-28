# OBSERVATIONS

## PHYSICAL INTERPRETATIONS

Points to Ponder over:

- Scaling of object
- Occlusion
  - Partial => The tracker gives great results in case of fluid motions, detecting even the face's one side, even if it was initiated to track the other side.
  - Complete => CSRT Tracker behaves the poorly in the case of instant and complete occlusion, i.e. if an object is covered and uncovered quickly, the tracker is likely to fail.
- Change in FPS
- Various similar objects are present in the scene
- Sudden background changes
- Fast moving objects
