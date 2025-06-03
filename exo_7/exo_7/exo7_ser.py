import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from rclpy.action import ActionServer
from robot_actions.action import Polygon

import math
import time

class PolygonActionServer(Node):
    def __init__(self):
        super().__init__('polygon_action_server')

        self._server = ActionServer(
            self,
            Polygon,
            'draw_polygon',
            self.execute_callback
        )

        self.cmd_pub = self.create_publisher(Twist, '/cmd_vel', 10)
        self.linear_speed = 0.2
        self.angular_speed = 0.5
        self.get_logger().info('Polygon Action Server ready.')

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
        N = goal_handle.request.sides
        L = goal_handle.request.side_length
        result = Polygon.Result()
        feedback = Polygon.Feedback()

        if N < 3 or L <= 0:
            goal_handle.abort()
            result.success = False
            result.message = "Invalid parameters: N must be >= 3 and L > 0"
            return result

        try:
            angle = 2 * math.pi / N  # exterior angle in radians

            for i in range(N):
                feedback.current_step = i * 2 + 1  # linear step
                goal_handle.publish_feedback(feedback)
                self.move_straight(L)

                feedback.current_step = i * 2 + 2  # rotation step
                goal_handle.publish_feedback(feedback)
                self.rotate(angle)

            goal_handle.succeed()
            result.success = True
            result.message = f"{N}-gon with side {L}m completed."
        except Exception as e:
            goal_handle.abort()
            result.success = False
            result.message = f"Error: {str(e)}"

        self.get_logger().info(result.message)
        return result

def main(args=None):
    rclpy.init(args=args)
    node = PolygonActionServer()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()

