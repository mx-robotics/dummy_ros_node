#include <nodelet_dummy/nodelet.h>
#include <pluginlib/class_list_macros.h>

    
namespace nodelet_dummy {

void NodeletDummyNodelet::onInit() {

    NODELET_INFO ("Initializing nodelet NodeletDummyNodelet...");
        NodeletDummyROS::init(getNodeHandle(), getPrivateNodeHandle());
}
}


PLUGINLIB_EXPORT_CLASS (nodelet_dummy::NodeletDummyNodelet, nodelet::Nodelet)
//int main(int argc, char **argv) {}
