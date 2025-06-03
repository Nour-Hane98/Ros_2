import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
from robot_actions.action import Polygon

class PolygonClient(Node):
    def __init__(self):
        super().__init__('polygon_client')
        self._client = ActionClient(self, Polygon, 'draw_polygon')

    def send_goal(self, sides, side_length):
        goal_msg = Polygon.Goal()
        goal_msg.sides = sides
        goal_msg.side_length = side_length

        self._client.wait_for_server()
        send_future = self._client.send_goal_async(goal_msg, feedback_callback=self.feedback_callback)
        send_future.add_done_callback(self.goal_response_callback)

    def feedback_callback(self, feedback_msg):
        self.get_logger().info(f"Step {feedback_msg.feedback.current_step}")

    def goal_response_callback(self, future):
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().info("Goal rejected.")
            return
        self.get_logger().info("Goal accepted.")
        result_future = goal_handle.get_result_async()
        result_future.add_done_callback(self.get_result_callback)

    def get_result_callback(self, future):
        result = future.result().result
        self.get_logger().info(f"Result: {result.message}")
        rclpy.shutdown()

def main(args=None):
    rclpy.init(args=args)
    client = PolygonClient()

    try:
        N = int(input("Enter number of sides (N ≥ 3): "))
        L = float(input("Enter side length (meters): "))
        client.send_goal(N, L)
        rclpy.spin(client)
    except Exception as e:
        client.get_logger().error(f"Input error: {e}")
        rclpy.shutdown()

if __name__ == '__main__':
    main()

