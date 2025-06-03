import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
from robot_actions.action import Triangle  # Update with your actual package


class TriangleClient(Node):
    def __init__(self):
        super().__init__('triangle_client')
        self._client = ActionClient(self, Triangle, 'draw_triangle')

    def send_goal(self, side_length):
        goal_msg = Triangle.Goal()
        goal_msg.side_length = side_length

        self._client.wait_for_server()
        send_goal_future = self._client.send_goal_async(goal_msg, feedback_callback=self.feedback_callback)
        send_goal_future.add_done_callback(self.goal_response_callback)

    def goal_response_callback(self, future):
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().info('Goal was rejected.')
            return
        self.get_logger().info('Goal accepted.')
        result_future = goal_handle.get_result_async()
        result_future.add_done_callback(self.get_result_callback)

    def feedback_callback(self, feedback_msg):
        self.get_logger().info(f'Feedback: Step {feedback_msg.feedback.current_step}/6')

    def get_result_callback(self, future):
        result = future.result().result
        self.get_logger().info(f"Result: {result.message}")
        rclpy.shutdown()


def main(args=None):
    rclpy.init(args=args)
    client = TriangleClient()

    try:
        side = float(input("Enter side length for triangle (meters): "))
        client.send_goal(side)
        rclpy.spin(client)
    except Exception as e:
        client.get_logger().error(f"Error: {e}")
        rclpy.shutdown()


if __name__ == '__main__':
    main()


