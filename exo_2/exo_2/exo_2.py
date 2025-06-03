import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from nav_msgs.msg import Odometry
import math

class MoveStraight(Node):

    def __init__(self):
        super().__init__('move_straight')

        # Publisher for velocity
        self.cmd_pub = self.create_publisher(Twist, '/cmd_vel', 10)

        # Subscriber for odometry
        self.odom_sub = self.create_subscription(Odometry, '/odom', self.odom_callback, 10)

        # Timer for publishing velocity
        self.timer = self.create_timer(0.1, self.publish_velocity)

        # Movement parameters
        self.speed = 0.1  # m/s
        self.target_distance = 1.0  # meters

        # Internal state
        self.start_pos = None
        self.current_pos = None
        self.is_moving = False
        self.should_stop = False

    def odom_callback(self, msg):
        # Get current position from odometry
        x = msg.pose.pose.position.x
        y = msg.pose.pose.position.y
        self.current_pos = (x, y)

        if self.start_pos is None:
            self.start_pos = self.current_pos
            self.get_logger().info(f"Start position recorded: x={x:.2f}, y={y:.2f}")
            self.is_moving = True
            return

        # Calculate distance from start
        dx = self.current_pos[0] - self.start_pos[0]
        dy = self.current_pos[1] - self.start_pos[1]
        distance = math.sqrt(dx**2 + dy**2)

        self.get_logger().info(f"Distance traveled: {distance:.2f} m")

        if distance >= self.target_distance:
            self.should_stop = True

    def publish_velocity(self):
        cmd = Twist()

        if self.should_stop:
            cmd.linear.x = 0.0
            self.cmd_pub.publish(cmd)
            self.get_logger().info("Target distance reached. Robot stopped.")
            rclpy.shutdown()
            return

        if self.is_moving:
            cmd.linear.x = self.speed
            self.cmd_pub.publish(cmd)

def main(args=None):
    rclpy.init(args=args)
    node = MoveStraight()
    rclpy.spin(node)

if __name__ == '__main__':
    main()

