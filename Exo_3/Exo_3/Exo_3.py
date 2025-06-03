import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from std_srvs.srv import Trigger
import time


class MoveStraight(Node):

    def __init__(self):
        super().__init__('move_straight')
        self.publisher_ = self.create_publisher(Twist, '/cmd_vel', 10)
        self.cmd = Twist()

        # Parameters
        self.speed = 0.05  # m/s
        self.target_distance = 1.0  # meters
        self.duration = self.target_distance / self.speed  # duration to move 1m

        # Service to trigger movement
        self.service_ = self.create_service(Trigger, 'move_one_meter', self.service_callback)

        self.get_logger().info('Service "move_one_meter" is ready. Call it to move the robot 1 meter.')

    def service_callback(self, request, response):
        self.get_logger().info('Service called. Moving robot forward 1 meter...')

        start_time = time.time()
        elapsed_time = 0.0

        # Move forward for the calculated duration
        while elapsed_time < self.duration:
            self.cmd.linear.x = self.speed
            self.publisher_.publish(self.cmd)
            time.sleep(0.1)
            elapsed_time = time.time() - start_time

        # Stop the robot
        self.cmd.linear.x = 0.0
        self.publisher_.publish(self.cmd)

        response.success = True
        response.message = 'Movement complete: 1 meter traveled.'
        self.get_logger().info(response.message)
        return response


def main(args=None):
    rclpy.init(args=args)
    node = MoveStraight()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()

  

