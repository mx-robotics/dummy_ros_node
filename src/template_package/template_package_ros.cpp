#include <template_package/template_package_ros.h>


namespace template_package {

void TemplatePackageROS::init(ros::NodeHandle &public_nh, ros::NodeHandle &private_nh) {

    ROS_INFO ("Initializing TemplatePackageROS...");
    nh_ = public_nh;
    private_nh_ = private_nh;
    private_nh_.param<double> ( "watchdog_duration", watchdog_duration_, 5.0 );
    reconfigureFnc_ = boost::bind ( &TemplatePackageROS::callbackConfigTemplatePackage, this,  _1, _2 );
    reconfigureServer_.setCallback ( reconfigureFnc_ );
    sub_laser_ = nh_.subscribe("scan", 10, &TemplatePackageROS::callbackLaser, this);
    timer_ = nh_.createTimer(ros::Duration(watchdog_duration_), &TemplatePackageROS::callbackTimerWatchdog, this);
}

void TemplatePackageROS::callbackTimerWatchdog(const ros::TimerEvent& event) {
    ROS_DEBUG ("callbackTimerWatchdog");    /// @note there are some issues with 'rosparam get /use_sim_time'
}

void TemplatePackageROS::callbackConfigTemplatePackage ( template_package::TemplatePackageConfig &config, uint32_t level ) {
    ROS_INFO ("callbackConfig");
    config_ = config;
    if(config_.debug_loglevel){
        if( ros::console::set_logger_level(ROSCONSOLE_DEFAULT_NAME, ros::console::levels::Debug) ) {
            ros::console::notifyLoggerLevelsChanged();
        }
    }
}

void TemplatePackageROS::callbackLaser(const sensor_msgs::LaserScan::ConstPtr &msg) {
    ROS_DEBUG ("callbackLaser");
    
}
}
