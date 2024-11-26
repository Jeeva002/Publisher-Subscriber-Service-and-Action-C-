#include "ros/ros.h"
#include "std_srvs/Empty.h"

bool handleServiceRequest(std_srvs::Empty::Request &req, std_srvs::Empty::Response &res)
{
  ROS_INFO("Service called");
  return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "service_server_node");
  ros::NodeHandle n;

  ros::ServiceServer service = n.advertiseService("my_service", handleServiceRequest);
  ROS_INFO("Service server ready.");

  ros::spin();

  return 0;
}
