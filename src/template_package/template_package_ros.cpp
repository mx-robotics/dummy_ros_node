#include <template_package/template_package_ros.h>


namespace template_package {

void TemplatePackageROS::init(ros::NodeHandle &public_nh, ros::NodeHandle &private_nh) {

    ROS_INFO ("Initializing TemplatePackageROS...");
    nh_ = public_nh;
    private_nh_ = private_nh;
    reconfigureFnc_ = boost::bind ( &TemplatePackageROS::callbackConfigLocalPlanner, this,  _1, _2 );
    reconfigureServer_.setCallback ( reconfigureFnc_ );
    sub_laser = nh_.subscribe("scan", 10, &TemplatePackageROS::callbackLaser, this);
}


void TemplatePackageROS::callbackConfigLocalPlanner ( template_package::TemplatePackageConfig &config, uint32_t level ) {
    ROS_INFO ("callbackConfig");
    config_ = config;
}

void TemplatePackageROS::callbackLaser(const sensor_msgs::LaserScan::ConstPtr &msg) {
    ROS_INFO ("callbackLaser");
    
}
}
