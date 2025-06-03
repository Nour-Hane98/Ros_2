# Software Architecture for Robots – UCLM MSc Robotics

This repository contains **8 practical exercises** developed using **ROS 2** and **TurtleBot3 simulation**, as part of the course **Software Architecture for Robots** in the **Master’s in Robotics and Automation** at the **University of Castilla-La Mancha (UCLM)**.

Each activity applies core software architecture principles to mobile robot control using nodes, services, actions, parameters, and LIDAR-based safety.


## Activity Descriptions

### 1. **Straight Line Movement (with timer)**
A node commands the TurtleBot3 to move **1 meter forward** by publishing a linear velocity of `0.05 m/s` for **20 seconds**.

### 2. **Straight Line Movement (with odometry)**
Same motion as exercise 1, but uses **odometry** instead of a timer. The robot stops automatically when it has traveled 1 meter.

### 3. **Move on Service Call (repeatable)**
The robot **waits for a service request** before starting the 1-meter movement. The service can be called multiple times until the node shuts down.

### 4. **Service with Movement Type and Value**
Extends exercise 3 by allowing the user to choose:
- **Linear movement** or **rotation**
- Specify the **value** (distance or angle)

### 5. **Action with Feedback**
Implements the previous logic using a **ROS 2 Action**, supporting:
- Periodic **feedback** during execution
- Result reporting upon completion
- Possibility to **cancel** goals

### 6. **Triangle Client**
A client node that calls the action server 3 times to draw a **triangle** with a side length `L` (user-defined).

### 7. **Polygon Client**
Generalizes the triangle client to draw **regular polygons** with `N` sides and side length `L`.
- For high `N`, approximates a **circle**
- Verifies if the end position matches the starting point to test robustness

### 8. **Collision-Aware Motion**
Enhances the action from exercise 5 by subscribing to the **LIDAR scan** topic (`/scan`) to ensure safety:
- If an obstacle is detected, the robot **waits** or **refuses to move**
- Provides feedback indicating if movement is unsafe

---

## 🛠 Requirements

- **ROS 2 (Foxy or Humble)**
- **TurtleBot3 (burger model)**
- **Gazebo simulator**
- **Python 3**



