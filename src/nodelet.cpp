#include <dummy_ros_node/nodelet.h>
#include <pluginlib/class_list_macros.h>

    
namespace dummy_ros_node {

void DummyRosNodeNodelet::onInit() {

    NODELET_INFO ("Initializing nodelet DummyRosNodeNodelet...");
        DummyRosNodeROS::init(getNodeHandle(), getPrivateNodeHandle());
}
}


PLUGINLIB_EXPORT_CLASS (dummy_ros_node::DummyRosNodeNodelet, nodelet::Nodelet)
//int main(int argc, char **argv) {}
