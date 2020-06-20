#ifndef NODELET_DUMMY_ROS_H
#define NODELET_DUMMY_ROS_H

#include <ros/ros.h>

#include <sensor_msgs/LaserScan.h>
#include <dynamic_reconfigure/server.h>
#include <nodelet_dummy/NodeletDummyConfig.h>


namespace nodelet_dummy {

class NodeletDummyROS {
    
private:
    ros::Subscriber sub_laser;
    ros::Timer timer_;
    ros::NodeHandle nh_;
    ros::NodeHandle private_nh_;
    nodelet_dummy::NodeletDummyConfig config_;
    dynamic_reconfigure::Server<nodelet_dummy::NodeletDummyConfig> reconfigureServer_; /// parameter server stuff
    dynamic_reconfigure::Server<nodelet_dummy::NodeletDummyConfig>::CallbackType reconfigureFnc_;  /// parameter server stuff
    void callbackConfigLocalPlanner ( nodelet_dummy::NodeletDummyConfig &config, uint32_t level ); /// callback function on incoming parameter changes

public:
    void init(ros::NodeHandle &public_nh, ros::NodeHandle &private_nh);
    void callbackLaser ( const sensor_msgs::LaserScan::ConstPtr& msg);

};
}

#endif  // NODELET_DUMMY_ROS_H
