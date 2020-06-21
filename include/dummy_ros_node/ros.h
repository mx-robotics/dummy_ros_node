#ifndef DUMMY_ROS_NODE_ROS_H
#define DUMMY_ROS_NODE_ROS_H

#include <ros/ros.h>

#include <sensor_msgs/LaserScan.h>
#include <dynamic_reconfigure/server.h>
#include <dummy_ros_node/DummyRosNodeConfig.h>


namespace dummy_ros_node {

class DummyRosNodeROS {
    
private:
    ros::Subscriber sub_laser;
    ros::Timer timer_;
    ros::NodeHandle nh_;
    ros::NodeHandle private_nh_;
    dummy_ros_node::DummyRosNodeConfig config_;
    dynamic_reconfigure::Server<dummy_ros_node::DummyRosNodeConfig> reconfigureServer_; /// parameter server stuff
    dynamic_reconfigure::Server<dummy_ros_node::DummyRosNodeConfig>::CallbackType reconfigureFnc_;  /// parameter server stuff
    void callbackConfigLocalPlanner ( dummy_ros_node::DummyRosNodeConfig &config, uint32_t level ); /// callback function on incoming parameter changes

public:
    void init(ros::NodeHandle &public_nh, ros::NodeHandle &private_nh);
    void callbackLaser ( const sensor_msgs::LaserScan::ConstPtr& msg);

};
}

#endif  // DUMMY_ROS_NODE_ROS_H
