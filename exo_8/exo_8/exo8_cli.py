import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
from robot_actions.action import SafeMove

class SafeMoveActionClient(Node):
    def __init__(self):
        super().__init__('safe_move_action_client')
        self._client = ActionClient(self, SafeMove, 'safe_move')

    def send_goal(self, motion_type, value):
        goal_msg = SafeMove.Goal()
        goal_msg.motion_type = motion_type
        goal_msg.value = value

        self._client.wait_for_server()
        self._send_goal_future = self._client.send_goal_async(
            goal_msg,
            feedback_callback=self.feedback_callback
        )
        self._send_goal_future.add_done_callback(self.goal_response_callback)

    def goal_response_callback(self, future):
        self._goal_handle = future.result()
        if not self._goal_handle.accepted:
            self.get_logger().info('Goal rejected by server.')
            rclpy.shutdown()
            return

        self.get_logger().info('Goal accepted by server.')
        self._get_result_future = self._goal_handle.get_result_async()
        self._get_result_future.add_done_callback(self.get_result_callback)

    def feedback_callback(self, feedback_msg):
        progress = feedback_msg.feedback.progress
        self.get_logger().info(f'Feedback: {progress * 100:.1f}% complete')

    def get_result_callback(self, future):
        result = future.result().result
        if result.success:
            self.get_logger().info(f'Success: {result.message}')
        else:
            self.get_logger().warn(f'Failure: {result.message}')
        rclpy.shutdown()


def main(args=None):
    rclpy.init(args=args)

    motion_type = input("Enter motion type (linear or rotation): ").strip().lower()
    value = float(input("Enter value (meters for linear, radians for rotation): "))

    client = SafeMoveActionClient()
    client.send_goal(motion_type, value)

    rclpy.spin(client)


if __name__ == '__main__':
    main()

