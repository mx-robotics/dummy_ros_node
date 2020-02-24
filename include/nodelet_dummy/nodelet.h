#ifndef NODELET_DUMMY_NODELET_H
#define NODELET_DUMMY_NODELET_H

#include <nodelet/nodelet.h>
#include <nodelet_dummy/ros.h>


namespace nodelet_dummy {


class NodeletDummyNodelet: public NodeletDummyROS, public nodelet::Nodelet {
public:
    virtual void onInit();
};

}

#endif  // NODELET_DUMMY_NODELET_H
