# nodelet_dummy
A ROS nodelet dummy
## change node name to "xxx_yyy"
* rename the pgk folder to xxx_yyy
* rename include nodelet_dummy to xxx_yyy
* rename cfg NodeletDummy.cfg to XxxYyy.cfg
* rename in all files nodelet_dummy to xxx_yyy 
* rename in all files NodeletDummy to XxxYyy 
* rename in all files NODELET_DUMMY to XXX_YYY 
* update/edit README.md

```
export xxx_yyy=my_pkg
export XxxYyy=MyPkg
export XXX_YYY=MY_PKG
find . -type f -exec sed -i 's/nodelet_dummy/'"${xxx_yyy}"'/g' {} +
find . -type f -exec sed -i 's/NodeletDummy/'"${XxxYyy}"'/g' {} +
find . -type f -exec sed -i 's/NODELET_DUMMY/'"${XXX_YYY}"'/g' {} +
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
