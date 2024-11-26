#include "ros/ros.h"
#include "actionlib/client/simple_action_client.h"
#include "actionlib_tutorials/FibonacciAction.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "action_client_node");

  actionlib::SimpleActionClient<actionlib_tutorials::FibonacciAction> ac("fibonacci", true);
  ac.waitForServer();

  actionlib_tutorials::FibonacciGoal goal;
  goal.order = 10;

  ac.sendGoal(goal);
  bool finished_before_timeout = ac.waitForResult(ros::Duration(30.0));

  if (finished_before_timeout)
  {
    actionlib_tutorials::FibonacciResultConstPtr result = ac.getResult();
    ROS_INFO("Fibonacci sequence: %s", result->sequence.c_str());
  }
  else
  {
    ROS_WARN("Action did not finish before the timeout.");
  }

  return 0;
}
