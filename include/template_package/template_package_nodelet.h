#ifndef TEMPLATE_PACKAGE_NODELET_H
#define TEMPLATE_PACKAGE_NODELET_H

#include <nodelet/nodelet.h>
#include <template_package/template_package_ros.h>


namespace template_package {


class TemplatePackageNodelet: public TemplatePackageROS, public nodelet::Nodelet {
public:
    virtual void onInit();
};

}

#endif  // TEMPLATE_PACKAGE_NODELET_H
