#include "ros/ros.h"
#include "std_srvs/Empty.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "service_client_node");
  ros::NodeHandle n;

  ros::ServiceClient client = n.serviceClient<std_srvs::Empty>("my_service");
  std_srvs::Empty srv;

  if (client.call(srv))
  {
    ROS_INFO("Service call successful.");
  }
  else
  {
    ROS_ERROR("Failed to call service.");
  }

  return 0;
}
