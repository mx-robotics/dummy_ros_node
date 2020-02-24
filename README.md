# nodelet_dummy
A ROS nodelet dummy
## To build option for the nodelet
This crates a node which links the nodelet
```
catkin_make -DCMAKE_BUILD_TYPE=Debug -DNODELET_DYNAMIC_LOAD=OFF
```
This crates a node which loads the nodelet
```
catkin_make -DCMAKE_BUILD_TYPE=Debug -DNODELET_DYNAMIC_LOAD=ON
```
