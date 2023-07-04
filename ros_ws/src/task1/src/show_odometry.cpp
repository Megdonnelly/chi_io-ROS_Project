#include "show_odometry.h"

/*
geometry_msgs/PoseWithCovariance pose
  geometry_msgs/Pose pose
    geometry_msgs/Point position
      float64 x
      float64 y
      float64 z

*/
 void chatterCallback(const nav_msgs::Odometry::ConstPtr& msg)
 {
    ROS_INFO("geometry_msgs/PoseWithCovariance pose");
    ROS_INFO("float64 x: %.2lf", msg->pose.pose.position.x);
    ROS_INFO("float64 y: %.2lf", msg->pose.pose.position.y);
    ROS_INFO("float64 z: %.2lf", msg->pose.pose.position.z);
    ROS_INFO("-----------------------------------------------");
 }
int main(int argc, char** argv)
{
    
    ros::init(argc, argv, "show_odometry");
    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe("/odom", 1000, chatterCallback);
    ros::spin();
    return 0;
}