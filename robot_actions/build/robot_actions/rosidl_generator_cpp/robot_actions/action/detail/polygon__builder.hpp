// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robot_actions:action/Polygon.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_ACTIONS__ACTION__DETAIL__POLYGON__BUILDER_HPP_
#define ROBOT_ACTIONS__ACTION__DETAIL__POLYGON__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robot_actions/action/detail/polygon__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robot_actions
{

namespace action
{

namespace builder
{

class Init_Polygon_Goal_side_length
{
public:
  explicit Init_Polygon_Goal_side_length(::robot_actions::action::Polygon_Goal & msg)
  : msg_(msg)
  {}
  ::robot_actions::action::Polygon_Goal side_length(::robot_actions::action::Polygon_Goal::_side_length_type arg)
  {
    msg_.side_length = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_actions::action::Polygon_Goal msg_;
};

class Init_Polygon_Goal_sides
{
public:
  Init_Polygon_Goal_sides()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Polygon_Goal_side_length sides(::robot_actions::action::Polygon_Goal::_sides_type arg)
  {
    msg_.sides = std::move(arg);
    return Init_Polygon_Goal_side_length(msg_);
  }

private:
  ::robot_actions::action::Polygon_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_actions::action::Polygon_Goal>()
{
  return robot_actions::action::builder::Init_Polygon_Goal_sides();
}

}  // namespace robot_actions


namespace robot_actions
{

namespace action
{

namespace builder
{

class Init_Polygon_Result_message
{
public:
  explicit Init_Polygon_Result_message(::robot_actions::action::Polygon_Result & msg)
  : msg_(msg)
  {}
  ::robot_actions::action::Polygon_Result message(::robot_actions::action::Polygon_Result::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_actions::action::Polygon_Result msg_;
};

class Init_Polygon_Result_success
{
public:
  Init_Polygon_Result_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Polygon_Result_message success(::robot_actions::action::Polygon_Result::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_Polygon_Result_message(msg_);
  }

private:
  ::robot_actions::action::Polygon_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_actions::action::Polygon_Result>()
{
  return robot_actions::action::builder::Init_Polygon_Result_success();
}

}  // namespace robot_actions


namespace robot_actions
{

namespace action
{

namespace builder
{

class Init_Polygon_Feedback_current_step
{
public:
  Init_Polygon_Feedback_current_step()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::robot_actions::action::Polygon_Feedback current_step(::robot_actions::action::Polygon_Feedback::_current_step_type arg)
  {
    msg_.current_step = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_actions::action::Polygon_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_actions::action::Polygon_Feedback>()
{
  return robot_actions::action::builder::Init_Polygon_Feedback_current_step();
}

}  // namespace robot_actions


namespace robot_actions
{

namespace action
{

namespace builder
{

class Init_Polygon_SendGoal_Request_goal
{
public:
  explicit Init_Polygon_SendGoal_Request_goal(::robot_actions::action::Polygon_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::robot_actions::action::Polygon_SendGoal_Request goal(::robot_actions::action::Polygon_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_actions::action::Polygon_SendGoal_Request msg_;
};

class Init_Polygon_SendGoal_Request_goal_id
{
public:
  Init_Polygon_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Polygon_SendGoal_Request_goal goal_id(::robot_actions::action::Polygon_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Polygon_SendGoal_Request_goal(msg_);
  }

private:
  ::robot_actions::action::Polygon_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_actions::action::Polygon_SendGoal_Request>()
{
  return robot_actions::action::builder::Init_Polygon_SendGoal_Request_goal_id();
}

}  // namespace robot_actions


namespace robot_actions
{

namespace action
{

namespace builder
{

class Init_Polygon_SendGoal_Response_stamp
{
public:
  explicit Init_Polygon_SendGoal_Response_stamp(::robot_actions::action::Polygon_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::robot_actions::action::Polygon_SendGoal_Response stamp(::robot_actions::action::Polygon_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_actions::action::Polygon_SendGoal_Response msg_;
};

class Init_Polygon_SendGoal_Response_accepted
{
public:
  Init_Polygon_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Polygon_SendGoal_Response_stamp accepted(::robot_actions::action::Polygon_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_Polygon_SendGoal_Response_stamp(msg_);
  }

private:
  ::robot_actions::action::Polygon_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_actions::action::Polygon_SendGoal_Response>()
{
  return robot_actions::action::builder::Init_Polygon_SendGoal_Response_accepted();
}

}  // namespace robot_actions


namespace robot_actions
{

namespace action
{

namespace builder
{

class Init_Polygon_GetResult_Request_goal_id
{
public:
  Init_Polygon_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::robot_actions::action::Polygon_GetResult_Request goal_id(::robot_actions::action::Polygon_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_actions::action::Polygon_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_actions::action::Polygon_GetResult_Request>()
{
  return robot_actions::action::builder::Init_Polygon_GetResult_Request_goal_id();
}

}  // namespace robot_actions


namespace robot_actions
{

namespace action
{

namespace builder
{

class Init_Polygon_GetResult_Response_result
{
public:
  explicit Init_Polygon_GetResult_Response_result(::robot_actions::action::Polygon_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::robot_actions::action::Polygon_GetResult_Response result(::robot_actions::action::Polygon_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_actions::action::Polygon_GetResult_Response msg_;
};

class Init_Polygon_GetResult_Response_status
{
public:
  Init_Polygon_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Polygon_GetResult_Response_result status(::robot_actions::action::Polygon_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_Polygon_GetResult_Response_result(msg_);
  }

private:
  ::robot_actions::action::Polygon_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_actions::action::Polygon_GetResult_Response>()
{
  return robot_actions::action::builder::Init_Polygon_GetResult_Response_status();
}

}  // namespace robot_actions


namespace robot_actions
{

namespace action
{

namespace builder
{

class Init_Polygon_FeedbackMessage_feedback
{
public:
  explicit Init_Polygon_FeedbackMessage_feedback(::robot_actions::action::Polygon_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::robot_actions::action::Polygon_FeedbackMessage feedback(::robot_actions::action::Polygon_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_actions::action::Polygon_FeedbackMessage msg_;
};

class Init_Polygon_FeedbackMessage_goal_id
{
public:
  Init_Polygon_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Polygon_FeedbackMessage_feedback goal_id(::robot_actions::action::Polygon_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Polygon_FeedbackMessage_feedback(msg_);
  }

private:
  ::robot_actions::action::Polygon_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_actions::action::Polygon_FeedbackMessage>()
{
  return robot_actions::action::builder::Init_Polygon_FeedbackMessage_goal_id();
}

}  // namespace robot_actions

#endif  // ROBOT_ACTIONS__ACTION__DETAIL__POLYGON__BUILDER_HPP_
