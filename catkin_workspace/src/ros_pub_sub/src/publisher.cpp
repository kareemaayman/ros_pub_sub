#include "ros/ros.h"
#include "std_msgs/String.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "simple_publisher");  // Initialize the ROS node
  ros::NodeHandle nh;  // Create a handle to this process node

  ros::Publisher pub = nh.advertise<std_msgs::String>("chatter", 1000);  // Define the publisher

  ros::Rate loop_rate(10);  // Set the loop rate to 10 Hz

  while (ros::ok())  // Keep running while ROS is active
  {
    std_msgs::String msg;  // Define a message to publish
    msg.data = "Hello, ROS!";

    pub.publish(msg);  // Publish the message

    ROS_INFO("%s", msg.data.c_str());  // Print the message to the console

    ros::spinOnce();  // Allow ROS to process incoming messages
    loop_rate.sleep();  // Sleep to maintain the loop rate
  }

  return 0;
}