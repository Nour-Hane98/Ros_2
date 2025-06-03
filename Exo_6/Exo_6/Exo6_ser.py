import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from rclpy.action import ActionServer
from robot_actions.action import Triangle  

import math
import time


class TriangleActionServer(Node):
    def __init__(self):
        super().__init__('triangle_action_server')

        self._action_server = ActionServer(
            self,
            Triangle,
            'draw_triangle',
            self.execute_callback
        )

        self.cmd_pub = self.create_publisher(Twist, '/cmd_vel', 10)
        self.linear_speed = 0.2  # m/s
        self.angular_speed = 0.5  # rad/s

        self.get_logger().info('Triangle Action Server ready.')

    def move_straight(self, distance):
        twist = Twist()
        twist.linear.x = self.linear_speed if distance >= 0 else -self.linear_speed
        duration = abs(distance) / self.linear_speed

        start = time.time()
        while time.time() - start < duration:
            self.cmd_pub.publish(twist)
            time.sleep(0.1)
        self.cmd_pub.publish(Twist())

    def rotate(self, radians):
        twist = Twist()
        twist.angular.z = self.angular_speed if radians >= 0 else -self.angular_speed
        duration = abs(radians) / self.angular_speed

        start = time.time()
        while time.time() - start < duration:
            self.cmd_pub.publish(twist)
            time.sleep(0.1)
        self.cmd_pub.publish(Twist())

    def execute_callback(self, goal_handle):
        side = goal_handle.request.side_length
        result = Triangle.Result()
        feedback = Triangle.Feedback()

        if side <= 0:
            goal_handle.abort()
            result.success = False
            result.message = "Side length must be positive."
            return result

        try:
            for step in range(3):
                feedback.current_step = step * 2 + 1  # 1, 3, 5
                goal_handle.publish_feedback(feedback)

                self.move_straight(side)

                feedback.current_step = step * 2 + 2  # 2, 4, 6
                goal_handle.publish_feedback(feedback)

                self.rotate(2 * math.pi / 3)  # 120 degrees

            goal_handle.succeed()
            result.success = True
            result.message = f"Triangle with side {side}m completed."
        except Exception as e:
            goal_handle.abort()
            result.success = False
            result.message = f"Error: {str(e)}"

        self.get_logger().info(result.message)
        return result


def main(args=None):
    rclpy.init(args=args)
    node = TriangleActionServer()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == '__main__':
    main()




