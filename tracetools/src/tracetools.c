// Copyright 2019 Robert Bosch GmbH
// Copyright 2020 Christophe Bedard
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "tracetools/tracetools.h"

#ifndef TRACETOOLS_DISABLED

#ifdef TRACETOOLS_LTTNG_ENABLED
# include "tracetools/tp_call.h"
# define CONDITIONAL_TP(...) \
  tracepoint(TRACEPOINT_PROVIDER, __VA_ARGS__)
#else
# define CONDITIONAL_TP(...)
#endif

bool ros_trace_compile_status()
{
#ifdef TRACETOOLS_LTTNG_ENABLED
  return true;
#else
  return false;
#endif
}

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
#else
# pragma warning(push)
# pragma warning(disable: 4100)
#endif

void TRACEPOINT(
  rcl_init,
  const void * context_handle)
{
  CONDITIONAL_TP(
    rcl_init,
    context_handle);
}

void TRACEPOINT(
  rcl_node_init,
  const void * node_handle,
  const void * rmw_handle,
  const char * node_name,
  const char * node_namespace)
{
  CONDITIONAL_TP(
    rcl_node_init,
    node_handle,
    rmw_handle,
    node_name,
    node_namespace);
}

void TRACEPOINT(
  rcl_publisher_init,
  const void * publisher_handle,
  const void * node_handle,
  const void * rmw_publisher_handle,
  const char * topic_name,
  const size_t queue_depth)
{
  CONDITIONAL_TP(
    rcl_publisher_init,
    publisher_handle,
    node_handle,
    rmw_publisher_handle,
    topic_name,
    queue_depth);
}

void TRACEPOINT(
  rcl_publish,
  const void * publisher_handle,
  const void * message)
{
  CONDITIONAL_TP(
    rcl_publish,
    publisher_handle,
    message);
}

void TRACEPOINT(
  rclcpp_publish,
  const void * publisher_handle,
  const void * message)
{
  CONDITIONAL_TP(
    rclcpp_publish,
    publisher_handle,
    message);
}

void TRACEPOINT(
  rcl_subscription_init,
  const void * subscription_handle,
  const void * node_handle,
  const void * rmw_subscription_handle,
  const char * topic_name,
  const size_t queue_depth)
{
  CONDITIONAL_TP(
    rcl_subscription_init,
    subscription_handle,
    node_handle,
    rmw_subscription_handle,
    topic_name,
    queue_depth);
}

void TRACEPOINT(
  rclcpp_subscription_init,
  const void * subscription_handle,
  const void * subscription)
{
  CONDITIONAL_TP(
    rclcpp_subscription_init,
    subscription_handle,
    subscription);
}

void TRACEPOINT(
  rclcpp_subscription_callback_added,
  const void * subscription,
  const void * callback)
{
  CONDITIONAL_TP(
    rclcpp_subscription_callback_added,
    subscription,
    callback);
}

void TRACEPOINT(
  rcl_service_init,
  const void * service_handle,
  const void * node_handle,
  const void * rmw_service_handle,
  const char * service_name)
{
  CONDITIONAL_TP(
    rcl_service_init,
    service_handle,
    node_handle,
    rmw_service_handle,
    service_name);
}

void TRACEPOINT(
  rclcpp_service_callback_added,
  const void * service_handle,
  const void * callback)
{
  CONDITIONAL_TP(
    rclcpp_service_callback_added,
    service_handle,
    callback);
}

void TRACEPOINT(
  rcl_client_init,
  const void * client_handle,
  const void * node_handle,
  const void * rmw_client_handle,
  const char * service_name)
{
  CONDITIONAL_TP(
    rcl_client_init,
    client_handle,
    node_handle,
    rmw_client_handle,
    service_name);
}

void TRACEPOINT(
  rcl_timer_init,
  const void * timer_handle,
  int64_t period)
{
  CONDITIONAL_TP(
    rcl_timer_init,
    timer_handle,
    period);
}

void TRACEPOINT(
    rclcpp_timer_added,
    const void * node_handle,
    const void * timer_handle)
{
  CONDITIONAL_TP(
      rclcpp_timer_added,
      node_handle,
      timer_handle);
}

void TRACEPOINT(
  rclcpp_timer_callback_added,
  const void * timer_handle,
  const void * callback)
{
  CONDITIONAL_TP(
    rclcpp_timer_callback_added,
    timer_handle,
    callback);
}

void TRACEPOINT(
  rclcpp_timer_link_node,
  const void * timer_handle,
  const void * node_handle)
{
  CONDITIONAL_TP(
    rclcpp_timer_link_node,
    timer_handle,
    node_handle);
}

void TRACEPOINT(
  rclcpp_callback_register,
  const void * callback,
  const char * function_symbol)
{
  CONDITIONAL_TP(
    rclcpp_callback_register,
    callback,
    function_symbol);
}

void TRACEPOINT(
  callback_start,
  const void * callback,
  const bool is_intra_process)
{
  CONDITIONAL_TP(
    callback_start,
    callback,
    is_intra_process);
}

void TRACEPOINT(
  callback_end,
  const void * callback)
{
  CONDITIONAL_TP(
    callback_end,
    callback);
}

void TRACEPOINT(
  rcl_lifecycle_state_machine_init,
  const void * node_handle,
  const void * state_machine)
{
  CONDITIONAL_TP(
    rcl_lifecycle_state_machine_init,
    node_handle,
    state_machine);
}

void TRACEPOINT(
  rcl_lifecycle_transition,
  const void * state_machine,
  const char * start_label,
  const char * goal_label)
{
  CONDITIONAL_TP(
    rcl_lifecycle_transition,
    state_machine,
    start_label,
    goal_label);
}

//rei
void TRACEPOINT(
    rclcpp_subscribe,
    const void *callback,
    const uint64_t source_stamp,
    const uint64_t received_stamp) {
  CONDITIONAL_TP(
      rclcpp_subscribe,
      callback,
      source_stamp,
      received_stamp
  );
}

void TRACEPOINT(
  client_request,
  const void *client,
  const void *request)
{
  CONDITIONAL_TP(
    client_request,
    client,
    request);
}

void TRACEPOINT(
    service_request,
    const void *service,
    const uint64_t source_stamp,
    const uint64_t received_stamp) {
  CONDITIONAL_TP(
      service_request,
      service,
      source_stamp,
      received_stamp
  );
}

void TRACEPOINT(
  service_response,
  const void *service,
  const void *response)
{
  CONDITIONAL_TP(
    service_response,
    service,
    response);
}

void TRACEPOINT(
    client_response,
    const void *client,
    const uint64_t source_stamp,
    const uint64_t received_stamp) {
  CONDITIONAL_TP(
      client_response,
      client,
      source_stamp,
      received_stamp
  );
}
//rei

#ifndef _WIN32
# pragma GCC diagnostic pop
#else
# pragma warning(pop)
#endif

#endif  // TRACETOOLS_DISABLED
