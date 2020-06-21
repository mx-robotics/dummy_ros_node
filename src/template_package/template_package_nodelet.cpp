#include <template_package/template_package_nodelet.h>
#include <pluginlib/class_list_macros.h>

    
namespace template_package {

void TemplatePackageNodelet::onInit() {

    NODELET_INFO ("Initializing nodelet TemplatePackageNodelet...");
        TemplatePackageROS::init(getNodeHandle(), getPrivateNodeHandle());
}
}


PLUGINLIB_EXPORT_CLASS (template_package::TemplatePackageNodelet, nodelet::Nodelet)
//int main(int argc, char **argv) {}
