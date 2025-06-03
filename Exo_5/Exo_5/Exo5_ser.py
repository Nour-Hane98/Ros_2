import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from rclpy.action import ActionServer
from robot_actions.action import Move  
import time


class MoveActionServer(Node):

    def __init__(self):
        super().__init__('move_action_server')

        self._action_server = ActionServer(
            self,
            Move,
            'move',
            self.execute_callback
        )
        self.get_logger().info('Action server started and waiting for clients...')

        self.publisher_ = self.create_publisher(Twist, '/cmd_vel', 10)
        self.linear_speed = 0.2    # m/s
        self.angular_speed = 0.5   # rad/s

    def execute_callback(self, goal_handle):
        self.get_logger().info(f'Executing goal: {goal_handle.request.motion_type} {goal_handle.request.value}')

        motion = goal_handle.request.motion_type.lower()
        value = goal_handle.request.value

        twist = Twist()
        duration = 0.0
        speed = 0.0

        # Determine movement
        if motion == "linear":
            speed = self.linear_speed
            duration = abs(value) / speed
            twist.linear.x = speed if value >= 0 else -speed

        elif motion == "rotation":
            speed = self.angular_speed
            duration = abs(value) / speed
            twist.angular.z = speed if value >= 0 else -speed

        else:
            goal_handle.abort()
            result = Move.Result()
            result.success = False
            result.message = f"Invalid motion_type: {motion}"
            return result

        # Execute motion with feedback
        start_time = time.time()
        while time.time() - start_time < duration:
            elapsed = time.time() - start_time
            progress = min(elapsed / duration, 1.0)

            self.publisher_.publish(twist)

            feedback = Move.Feedback()
            feedback.progress = progress
            goal_handle.publish_feedback(feedback)

            time.sleep(0.1)

        # Stop robot
        self.publisher_.publish(Twist())

        # Finish action
        goal_handle.succeed()
        result = Move.Result()
        result.success = True
        result.message = f"{motion.capitalize()} movement of {value} completed."
        self.get_logger().info(result.message)
        return result


def main(args=None):
    rclpy.init(args=args)
    node = MoveActionServer()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == '__main__':
    main()



