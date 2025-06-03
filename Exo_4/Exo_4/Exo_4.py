import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from move_command_interfaces.srv import MoveCommand # Custom service
import time


class MoveCommandService(Node):

    def __init__(self):
        super().__init__('move_command_service')
        self.publisher_ = self.create_publisher(Twist, '/cmd_vel', 10)

        # Speeds
        self.linear_speed = 0.2     # m/s
        self.angular_speed = 0.5    # rad/s

        self.service_ = self.create_service(MoveCommand, 'move_command', self.service_callback)
        self.get_logger().info('Service "move_command" ready. Send "linear" or "rotation" with a value.')

    def service_callback(self, request, response):
        motion = request.motion_type.lower()
        value = request.value

        twist = Twist()

        if motion == "linear":
            duration = abs(value) / self.linear_speed
            direction = 1.0 if value >= 0 else -1.0
            twist.linear.x = direction * self.linear_speed
            self.get_logger().info(f'Moving linearly for {value} meters...')

            start_time = time.time()
            while time.time() - start_time < duration:
                self.publisher_.publish(twist)
                time.sleep(0.1)

        elif motion == "rotation":
            duration = abs(value) / self.angular_speed
            direction = 1.0 if value >= 0 else -1.0
            twist.angular.z = direction * self.angular_speed
            self.get_logger().info(f'Rotating {value} radians...')

            start_time = time.time()
            while time.time() - start_time < duration:
                self.publisher_.publish(twist)
                time.sleep(0.1)

        else:
            response.success = False
            response.message = f'Invalid motion_type: {motion}. Use "linear" or "rotation".'
            return response

        # Stop the robot after the movement
        self.publisher_.publish(Twist())

        response.success = True
        response.message = f'{motion.capitalize()} movement of {value} completed.'
        self.get_logger().info(response.message)
        return response


def main(args=None):
    rclpy.init(args=args)
    node = MoveCommandService()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()

