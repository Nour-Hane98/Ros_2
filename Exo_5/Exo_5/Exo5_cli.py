import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
from robot_actions.action import Move

class MoveActionClient(Node):
    def __init__(self):
        super().__init__('move_action_client')
        self._client = ActionClient(self, Move, 'move')

    def send_goal(self, motion_type, value):
        goal_msg = Move.Goal()
        goal_msg.motion_type = motion_type
        goal_msg.value = value

        self._client.wait_for_server()
        self._send = self._client.send_goal_async(goal_msg, feedback_callback=self.feedback_callback)
        self._send.add_done_callback(self.goal_response_callback)

    def goal_response_callback(self, future):
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().info('Goal rejected')
            return
        self.get_logger().info('Goal accepted')
        goal_handle.get_result_async().add_done_callback(self.get_result_callback)

    def feedback_callback(self, feedback_msg):
        progress = feedback_msg.feedback.progress
        self.get_logger().info(f'Feedback: {progress * 100:.1f}% complete')

    def get_result_callback(self, future):
        result = future.result().result
        self.get_logger().info(f'Result: {result.message}')
        rclpy.shutdown()

def main(args=None):
    rclpy.init(args=args)
    motion_type = input("Enter motion type (linear or rotation): ").strip().lower()
    value = float(input("Enter value (e.g., 1.0 meters or 1.57 radians): "))

    client = MoveActionClient()
    client.send_goal(motion_type, value)
    rclpy.spin(client)

if __name__ == '__main__':
    main()


