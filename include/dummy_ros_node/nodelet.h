#ifndef DUMMY_ROS_NODE_NODELET_H
#define DUMMY_ROS_NODE_NODELET_H

#include <nodelet/nodelet.h>
#include <dummy_ros_node/ros.h>


namespace dummy_ros_node {


class DummyRosNodeNodelet: public DummyRosNodeROS, public nodelet::Nodelet {
public:
    virtual void onInit();
};

}

#endif  // DUMMY_ROS_NODE_NODELET_H
