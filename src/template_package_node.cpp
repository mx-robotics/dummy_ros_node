
#include <ros/ros.h>
#ifdef NODELET_DYNAMIC_LOAD
#include <nodelet/loader.h>
#else
#include <template_package/template_package_ros.h>
#endif

int main(int argc, char **argv)
{
    ros::init(argc, argv, "template_package"); 
#ifdef NODELET_DYNAMIC_LOAD   
    std::cout << "NODELET_DYNAMIC_LOAD=ON" << std::endl;
    nodelet::Loader nodelet;
    nodelet::M_string remap(ros::names::getRemappings());
    nodelet::V_string nargv;
    std::string nodelet_name = ros::this_node::getName();
    nodelet.load(nodelet_name, "template_package/TemplatePackageNodelet", remap, nargv);
#else   
    std::cout << "NODELET_DYNAMIC_LOAD=OFF" << std::endl;
    ros::NodeHandle nh_public;
    ros::NodeHandle nh_private("~");
    template_package::TemplatePackageROS node;
    node.init(nh_public, nh_private);
#endif
    ros::spin();
    return 0;
    
    
}
