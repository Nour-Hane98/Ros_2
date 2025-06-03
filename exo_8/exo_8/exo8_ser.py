import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from rclpy.action import ActionServer
from robot_actions.action import SafeMove
from sensor_msgs.msg import LaserScan
import time  


class SafeMoveActionServer(Node):
    def __init__(self):
        super().__init__('safe_move_action_server')

        self._action_server = ActionServer(
            self,
            SafeMove,
            'safe_move',
            self.execute_callback
        )
        self.publisher_ = self.create_publisher(Twist, '/cmd_vel', 10)
        self.lidar_sub = self.create_subscription(LaserScan, '/scan', self.lidar_callback, 10)

        self.obstacle_detected = False
        self.safety_distance = 0.5  # meters, threshold distance for obstacle

        self.get_logger().info("SafeMove Action Server started.")

    def lidar_callback(self, msg: LaserScan):
        # Check front obstacle within ±15 degrees
        front_angle_deg = 15
        ranges = msg.ranges
        angle_increment = msg.angle_increment

        middle_index = len(ranges) // 2
        range_indices = int(front_angle_deg * (3.14159 / 180) / angle_increment)

        front_ranges = ranges[middle_index - range_indices : middle_index + range_indices + 1]

        self.obstacle_detected = any(
            r < self.safety_distance and r > 0.0 for r in front_ranges if r is not None
        )

    def execute_callback(self, goal_handle):
        motion = goal_handle.request.motion_type.lower()
        value = goal_handle.request.value

        self.get_logger().info(f"Received goal: {motion} {value}")

        twist = Twist()
        if motion == "linear":
            if self.obstacle_detected:
                self.get_logger().warn("Obstacle detected! Aborting linear movement before start.")
                goal_handle.abort()
                result = SafeMove.Result()
                result.success = False
                result.message = "Movement unsafe — obstacle detected!"
                return result

            speed = 0.2  # linear speed m/s
            duration = abs(value) / speed
            twist.linear.x = speed if value >= 0 else -speed

        elif motion == "rotation":
            speed = 0.5  # angular speed rad/s
            duration = abs(value) / speed
            twist.angular.z = speed if value >= 0 else -speed

        else:
            self.get_logger().error(f"Invalid motion_type: {motion}")
            goal_handle.abort()
            result = SafeMove.Result()
            result.success = False
            result.message = f"Invalid motion_type: {motion}"
            return result

        start_time = self.get_clock().now()
        while (self.get_clock().now() - start_time).nanoseconds / 1e9 < duration:
            # Check obstacle during linear movement only
            if motion == "linear" and self.obstacle_detected:
                self.get_logger().warn("Obstacle detected during movement! Stopping.")
                self.publisher_.publish(Twist())  # Stop robot
                goal_handle.abort()
                result = SafeMove.Result()
                result.success = False
                result.message = "Movement aborted due to obstacle!"
                return result

            self.publisher_.publish(twist)

            feedback = SafeMove.Feedback()
            elapsed = (self.get_clock().now() - start_time).nanoseconds / 1e9
            feedback.progress = min(elapsed / duration, 1.0)
            goal_handle.publish_feedback(feedback)

            time.sleep(0.1)  

        # Stop robot at the end
        self.publisher_.publish(Twist())

        goal_handle.succeed()
        result = SafeMove.Result()
        result.success = True
        result.message = f"{motion.capitalize()} movement of {value} completed successfully."
        self.get_logger().info(result.message)
        return result


def main(args=None):
    rclpy.init(args=args)
    node = SafeMoveActionServer()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == '__main__':
    main()

