#include "ros/ros.h"
#include "actionlib/server/simple_action_server.h"
#include "actionlib_tutorials/FibonacciAction.h"

void execute(const actionlib_tutorials::FibonacciGoalConstPtr &goal)
{
  actionlib_tutorials::FibonacciFeedback feedback;
  actionlib_tutorials::FibonacciResult result;

  for (int i = 1; i <= goal->order; i++)
  {
    if (i == 1)
      feedback.sequence.push_back(0);
    else if (i == 2)
      feedback.sequence.push_back(1);
    else
      feedback.sequence.push_back(feedback.sequence[i - 2] + feedback.sequence[i - 3]);

    if (i % 2 == 0)
    {
      server.publishFeedback(feedback);
      ros::Duration(0.5).sleep();
    }
  }

  result.sequence = feedback.sequence;
  server.setSucceeded(result);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "action_server_node");
  ros::NodeHandle n;

  actionlib::SimpleActionServer<actionlib_tutorials::FibonacciAction> server(n, "fibonacci", boost::bind(&execute, _1), false);
  server.start();

  ros::spin();

  return 0;
}
