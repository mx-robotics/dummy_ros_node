# template_package
A ROS nodelet dummy
## change node name to "new_pkg_name"
* rename the pgk folder to new_pkg_name
* rename include template_package to new_pkg_name
* rename cfg TemplatePackage.cfg to NewPkgName.cfg
* rename in all files template_package to new_pkg_name 
* rename in all files TemplatePackage to NewPkgName 
* rename in all files TEMPLATE_PACKAGE to NEW_PGK_NAME 
* update/edit README.md

```
# you can run
./rename.sh new_pkg_name template_package 
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
