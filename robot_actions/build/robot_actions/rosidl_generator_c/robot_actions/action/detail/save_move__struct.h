// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from robot_actions:action/SaveMove.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_ACTIONS__ACTION__DETAIL__SAVE_MOVE__STRUCT_H_
#define ROBOT_ACTIONS__ACTION__DETAIL__SAVE_MOVE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'motion_type'
#include "rosidl_runtime_c/string.h"

/// Struct defined in action/SaveMove in the package robot_actions.
typedef struct robot_actions__action__SaveMove_Goal
{
  /// "linear" or "rotation"
  rosidl_runtime_c__String motion_type;
  /// meters or radians
  double value;
} robot_actions__action__SaveMove_Goal;

// Struct for a sequence of robot_actions__action__SaveMove_Goal.
typedef struct robot_actions__action__SaveMove_Goal__Sequence
{
  robot_actions__action__SaveMove_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_actions__action__SaveMove_Goal__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in action/SaveMove in the package robot_actions.
typedef struct robot_actions__action__SaveMove_Result
{
  bool success;
  rosidl_runtime_c__String message;
} robot_actions__action__SaveMove_Result;

// Struct for a sequence of robot_actions__action__SaveMove_Result.
typedef struct robot_actions__action__SaveMove_Result__Sequence
{
  robot_actions__action__SaveMove_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_actions__action__SaveMove_Result__Sequence;


// Constants defined in the message

/// Struct defined in action/SaveMove in the package robot_actions.
typedef struct robot_actions__action__SaveMove_Feedback
{
  /// from 0.0 to 1.0
  float progress;
} robot_actions__action__SaveMove_Feedback;

// Struct for a sequence of robot_actions__action__SaveMove_Feedback.
typedef struct robot_actions__action__SaveMove_Feedback__Sequence
{
  robot_actions__action__SaveMove_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_actions__action__SaveMove_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "robot_actions/action/detail/save_move__struct.h"

/// Struct defined in action/SaveMove in the package robot_actions.
typedef struct robot_actions__action__SaveMove_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  robot_actions__action__SaveMove_Goal goal;
} robot_actions__action__SaveMove_SendGoal_Request;

// Struct for a sequence of robot_actions__action__SaveMove_SendGoal_Request.
typedef struct robot_actions__action__SaveMove_SendGoal_Request__Sequence
{
  robot_actions__action__SaveMove_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_actions__action__SaveMove_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/SaveMove in the package robot_actions.
typedef struct robot_actions__action__SaveMove_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} robot_actions__action__SaveMove_SendGoal_Response;

// Struct for a sequence of robot_actions__action__SaveMove_SendGoal_Response.
typedef struct robot_actions__action__SaveMove_SendGoal_Response__Sequence
{
  robot_actions__action__SaveMove_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_actions__action__SaveMove_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/SaveMove in the package robot_actions.
typedef struct robot_actions__action__SaveMove_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} robot_actions__action__SaveMove_GetResult_Request;

// Struct for a sequence of robot_actions__action__SaveMove_GetResult_Request.
typedef struct robot_actions__action__SaveMove_GetResult_Request__Sequence
{
  robot_actions__action__SaveMove_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_actions__action__SaveMove_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "robot_actions/action/detail/save_move__struct.h"

/// Struct defined in action/SaveMove in the package robot_actions.
typedef struct robot_actions__action__SaveMove_GetResult_Response
{
  int8_t status;
  robot_actions__action__SaveMove_Result result;
} robot_actions__action__SaveMove_GetResult_Response;

// Struct for a sequence of robot_actions__action__SaveMove_GetResult_Response.
typedef struct robot_actions__action__SaveMove_GetResult_Response__Sequence
{
  robot_actions__action__SaveMove_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_actions__action__SaveMove_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "robot_actions/action/detail/save_move__struct.h"

/// Struct defined in action/SaveMove in the package robot_actions.
typedef struct robot_actions__action__SaveMove_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  robot_actions__action__SaveMove_Feedback feedback;
} robot_actions__action__SaveMove_FeedbackMessage;

// Struct for a sequence of robot_actions__action__SaveMove_FeedbackMessage.
typedef struct robot_actions__action__SaveMove_FeedbackMessage__Sequence
{
  robot_actions__action__SaveMove_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_actions__action__SaveMove_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROBOT_ACTIONS__ACTION__DETAIL__SAVE_MOVE__STRUCT_H_
