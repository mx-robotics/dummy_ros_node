# nodelet_dummy
A ROS nodelet dummy
## change node name to "new_pkg_name"
* rename the pgk folder to new_pkg_name
* rename include nodelet_dummy to new_pkg_name
* rename cfg NodeletDummy.cfg to NewPkgName.cfg
* rename in all files nodelet_dummy to new_pkg_name 
* rename in all files NodeletDummy to NewPkgName 
* rename in all files NODELET_DUMMY to NEW_PGK_NAME 
* update/edit README.md

```
# you can run
./rename.sh new_pkg_name nodelet_dummy 
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
