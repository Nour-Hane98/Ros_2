// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robot_actions:action/Triangle.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_ACTIONS__ACTION__DETAIL__TRIANGLE__BUILDER_HPP_
#define ROBOT_ACTIONS__ACTION__DETAIL__TRIANGLE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robot_actions/action/detail/triangle__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robot_actions
{

namespace action
{

namespace builder
{

class Init_Triangle_Goal_side_length
{
public:
  Init_Triangle_Goal_side_length()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::robot_actions::action::Triangle_Goal side_length(::robot_actions::action::Triangle_Goal::_side_length_type arg)
  {
    msg_.side_length = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_actions::action::Triangle_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_actions::action::Triangle_Goal>()
{
  return robot_actions::action::builder::Init_Triangle_Goal_side_length();
}

}  // namespace robot_actions


namespace robot_actions
{

namespace action
{

namespace builder
{

class Init_Triangle_Result_message
{
public:
  explicit Init_Triangle_Result_message(::robot_actions::action::Triangle_Result & msg)
  : msg_(msg)
  {}
  ::robot_actions::action::Triangle_Result message(::robot_actions::action::Triangle_Result::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_actions::action::Triangle_Result msg_;
};

class Init_Triangle_Result_success
{
public:
  Init_Triangle_Result_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Triangle_Result_message success(::robot_actions::action::Triangle_Result::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_Triangle_Result_message(msg_);
  }

private:
  ::robot_actions::action::Triangle_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_actions::action::Triangle_Result>()
{
  return robot_actions::action::builder::Init_Triangle_Result_success();
}

}  // namespace robot_actions


namespace robot_actions
{

namespace action
{

namespace builder
{

class Init_Triangle_Feedback_current_side
{
public:
  Init_Triangle_Feedback_current_side()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::robot_actions::action::Triangle_Feedback current_side(::robot_actions::action::Triangle_Feedback::_current_side_type arg)
  {
    msg_.current_side = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_actions::action::Triangle_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_actions::action::Triangle_Feedback>()
{
  return robot_actions::action::builder::Init_Triangle_Feedback_current_side();
}

}  // namespace robot_actions


namespace robot_actions
{

namespace action
{

namespace builder
{

class Init_Triangle_SendGoal_Request_goal
{
public:
  explicit Init_Triangle_SendGoal_Request_goal(::robot_actions::action::Triangle_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::robot_actions::action::Triangle_SendGoal_Request goal(::robot_actions::action::Triangle_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_actions::action::Triangle_SendGoal_Request msg_;
};

class Init_Triangle_SendGoal_Request_goal_id
{
public:
  Init_Triangle_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Triangle_SendGoal_Request_goal goal_id(::robot_actions::action::Triangle_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Triangle_SendGoal_Request_goal(msg_);
  }

private:
  ::robot_actions::action::Triangle_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_actions::action::Triangle_SendGoal_Request>()
{
  return robot_actions::action::builder::Init_Triangle_SendGoal_Request_goal_id();
}

}  // namespace robot_actions


namespace robot_actions
{

namespace action
{

namespace builder
{

class Init_Triangle_SendGoal_Response_stamp
{
public:
  explicit Init_Triangle_SendGoal_Response_stamp(::robot_actions::action::Triangle_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::robot_actions::action::Triangle_SendGoal_Response stamp(::robot_actions::action::Triangle_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_actions::action::Triangle_SendGoal_Response msg_;
};

class Init_Triangle_SendGoal_Response_accepted
{
public:
  Init_Triangle_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Triangle_SendGoal_Response_stamp accepted(::robot_actions::action::Triangle_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_Triangle_SendGoal_Response_stamp(msg_);
  }

private:
  ::robot_actions::action::Triangle_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_actions::action::Triangle_SendGoal_Response>()
{
  return robot_actions::action::builder::Init_Triangle_SendGoal_Response_accepted();
}

}  // namespace robot_actions


namespace robot_actions
{

namespace action
{

namespace builder
{

class Init_Triangle_GetResult_Request_goal_id
{
public:
  Init_Triangle_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::robot_actions::action::Triangle_GetResult_Request goal_id(::robot_actions::action::Triangle_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_actions::action::Triangle_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_actions::action::Triangle_GetResult_Request>()
{
  return robot_actions::action::builder::Init_Triangle_GetResult_Request_goal_id();
}

}  // namespace robot_actions


namespace robot_actions
{

namespace action
{

namespace builder
{

class Init_Triangle_GetResult_Response_result
{
public:
  explicit Init_Triangle_GetResult_Response_result(::robot_actions::action::Triangle_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::robot_actions::action::Triangle_GetResult_Response result(::robot_actions::action::Triangle_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_actions::action::Triangle_GetResult_Response msg_;
};

class Init_Triangle_GetResult_Response_status
{
public:
  Init_Triangle_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Triangle_GetResult_Response_result status(::robot_actions::action::Triangle_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_Triangle_GetResult_Response_result(msg_);
  }

private:
  ::robot_actions::action::Triangle_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_actions::action::Triangle_GetResult_Response>()
{
  return robot_actions::action::builder::Init_Triangle_GetResult_Response_status();
}

}  // namespace robot_actions


namespace robot_actions
{

namespace action
{

namespace builder
{

class Init_Triangle_FeedbackMessage_feedback
{
public:
  explicit Init_Triangle_FeedbackMessage_feedback(::robot_actions::action::Triangle_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::robot_actions::action::Triangle_FeedbackMessage feedback(::robot_actions::action::Triangle_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_actions::action::Triangle_FeedbackMessage msg_;
};

class Init_Triangle_FeedbackMessage_goal_id
{
public:
  Init_Triangle_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Triangle_FeedbackMessage_feedback goal_id(::robot_actions::action::Triangle_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Triangle_FeedbackMessage_feedback(msg_);
  }

private:
  ::robot_actions::action::Triangle_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_actions::action::Triangle_FeedbackMessage>()
{
  return robot_actions::action::builder::Init_Triangle_FeedbackMessage_goal_id();
}

}  // namespace robot_actions

#endif  // ROBOT_ACTIONS__ACTION__DETAIL__TRIANGLE__BUILDER_HPP_
