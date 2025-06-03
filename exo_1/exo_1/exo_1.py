import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist

class MoveStraight(Node):
    def __init__(self):
        super().__init__('move_straight_node')

        # Create a publisher to send velocity commands
        self.publisher_ = self.create_publisher(Twist, '/cmd_vel', 10)

        # Set the velocity command
        self.move_cmd = Twist()
        self.move_cmd.linear.x = 0.05  # 0.05 m/s linear velocity
        self.move_cmd.angular.z = 0.0  # No angular velocity (straight line)

        # Timer to execute the movement for 20 seconds
        self.timer = self.create_timer(0.1, self.timer_callback)  # 0.1 second interval
        self.get_logger().info("Starting movement: Moving 1 meter in a straight line")

        # Store the start time in nanoseconds
        self.start_time = self.get_clock().now().nanoseconds

    def timer_callback(self):
        # Calculate elapsed time in nanoseconds
        elapsed_time_ns = self.get_clock().now().nanoseconds - self.start_time

        # Convert elapsed time from nanoseconds to seconds
        elapsed_time_sec = elapsed_time_ns / 1e9

        if elapsed_time_sec < 20:
            self.publisher_.publish(self.move_cmd)  # Publish the move command
        else:
            self.publisher_.publish(Twist())  # Stop the robot after 20 seconds
            self.get_logger().info("Movement complete: Stopped after 20 seconds")
            self.destroy_timer(self.timer)  # Stop the timer

def main(args=None):
    rclpy.init(args=args)

    move_straight_node = MoveStraight()

    rclpy.spin(move_straight_node)

    # Shutdown ROS 2 client library
    move_straight_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
