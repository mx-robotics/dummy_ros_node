#include <dummy_ros_node/ros.h>


namespace dummy_ros_node {

void DummyRosNodeROS::init(ros::NodeHandle &public_nh, ros::NodeHandle &private_nh) {

    ROS_INFO ("Initializing DummyRosNodeROS...");
    nh_ = public_nh;
    private_nh_ = private_nh;
    reconfigureFnc_ = boost::bind ( &DummyRosNodeROS::callbackConfigLocalPlanner, this,  _1, _2 );
    reconfigureServer_.setCallback ( reconfigureFnc_ );
    sub_laser = nh_.subscribe("scan", 10, &DummyRosNodeROS::callbackLaser, this);
}


void DummyRosNodeROS::callbackConfigLocalPlanner ( dummy_ros_node::DummyRosNodeConfig &config, uint32_t level ) {
    ROS_INFO ("callbackConfig");
    config_ = config;
}

void DummyRosNodeROS::callbackLaser(const sensor_msgs::LaserScan::ConstPtr &msg) {
    ROS_INFO ("callbackLaser");
    
}
}
