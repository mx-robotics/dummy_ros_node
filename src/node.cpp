
#include <ros/ros.h>
#ifdef NODELET_DYNAMIC_LOAD
#include <nodelet/loader.h>
#else
#include <nodelet_dummy/ros.h>
#endif

int main(int argc, char **argv)
{
    ros::init(argc, argv, "nodelet_dummy"); 
#ifdef NODELET_DYNAMIC_LOAD   
    std::cout << "NODELET_DYNAMIC_LOAD=ON" << std::endl;
    nodelet::Loader nodelet;
    nodelet::M_string remap(ros::names::getRemappings());
    nodelet::V_string nargv;
    std::string nodelet_name = ros::this_node::getName();
    nodelet.load(nodelet_name, "nodelet_dummy/NodeletDummyNodelet", remap, nargv);
#else   
    std::cout << "NODELET_DYNAMIC_LOAD=OFF" << std::endl;
    ros::NodeHandle nh_public;
    ros::NodeHandle nh_private("~");
    nodelet_dummy::NodeletDummyROS node;
    node.init(nh_public, nh_private);
#endif
    ros::spin();
    return 0;
    
    
}
