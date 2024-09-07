#include "ros/ros.h"
#include "std_msgs/String.h"

void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("I heard: [%s]", msg->data.c_str());  // Print the received message to the console
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "simple_subscriber");  // Initialize the ROS node
  ros::NodeHandle nh;  // Create a handle to this process node

  ros::Subscriber sub = nh.subscribe("chatter", 1000, chatterCallback);  // Subscribe to the "chatter" topic

  ros::spin();  // Keep the node running and processing callbacks

  return 0;
}