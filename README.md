# dummy_ros_node
A ROS nodelet dummy
## change node name to "new_pkg_name"
* rename the pgk folder to new_pkg_name
* rename include dummy_ros_node to new_pkg_name
* rename cfg DummyRosNode.cfg to NewPkgName.cfg
* rename in all files dummy_ros_node to new_pkg_name 
* rename in all files DummyRosNode to NewPkgName 
* rename in all files DUMMY_ROS_NODE to NEW_PGK_NAME 
* update/edit README.md

```
# you can run
./rename.sh new_pkg_name dummy_ros_node 
```

## To build option for the nodelet
This crates a node which links the nodelet
```
catkin_make -DCMAKE_BUILD_TYPE=Debug -DNODELET_DYNAMIC_LOAD=OFF
```
This crates a node which loads the nodelet
```
catkin_make -DCMAKE_BUILD_TYPE=Debug -DNODELET_DYNAMIC_LOAD=ON
```
