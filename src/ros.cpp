#include <nodelet_dummy/ros.h>


namespace nodelet_dummy {

void NodeletDummyROS::init(ros::NodeHandle &public_nh, ros::NodeHandle &private_nh) {

    ROS_INFO ("Initializing NodeletDummyROS...");
    nh_ = public_nh;
    private_nh_ = private_nh;
    reconfigureFnc_ = boost::bind ( &NodeletDummyROS::callbackConfigLocalPlanner, this,  _1, _2 );
    reconfigureServer_.setCallback ( reconfigureFnc_ );
    sub_laser = nh_.subscribe("scan", 10, &NodeletDummyROS::callbackLaser, this);
}


void NodeletDummyROS::callbackConfigLocalPlanner ( nodelet_dummy::NodeletDummyConfig &config, uint32_t level ) {
    ROS_INFO ("callbackConfig");
    config_ = config;
}

void NodeletDummyROS::callbackLaser(const sensor_msgs::LaserScan::ConstPtr &msg) {
    ROS_INFO ("callbackLaser");
    
}
}
