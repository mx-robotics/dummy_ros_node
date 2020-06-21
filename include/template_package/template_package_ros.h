#ifndef TEMPLATE_PACKAGE_ROS_H
#define TEMPLATE_PACKAGE_ROS_H

#include <ros/ros.h>

#include <sensor_msgs/LaserScan.h>
#include <dynamic_reconfigure/server.h>
#include <template_package/TemplatePackageConfig.h>


namespace template_package {

class TemplatePackageROS {
    
private:
    ros::Subscriber sub_laser;
    ros::Timer timer_;
    ros::NodeHandle nh_;
    ros::NodeHandle private_nh_;
    template_package::TemplatePackageConfig config_;
    dynamic_reconfigure::Server<template_package::TemplatePackageConfig> reconfigureServer_; /// parameter server stuff
    dynamic_reconfigure::Server<template_package::TemplatePackageConfig>::CallbackType reconfigureFnc_;  /// parameter server stuff
    void callbackConfigLocalPlanner ( template_package::TemplatePackageConfig &config, uint32_t level ); /// callback function on incoming parameter changes

public:
    void init(ros::NodeHandle &public_nh, ros::NodeHandle &private_nh);
    void callbackLaser ( const sensor_msgs::LaserScan::ConstPtr& msg);

};
}

#endif  // TEMPLATE_PACKAGE_ROS_H
