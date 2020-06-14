#!/bin/bash

echo "usage: rename.sh target_name [source_name=nodelet_dummy]"
echo "------------------------------------"

if [ $# -gt 0 ]; 
then
  TARGET_NAME=$1
else
  echo "Abort: no target_name"
  exit 0
fi
SOURCE_NAME=nodelet_dummy
if [ $# -gt 1 ]; then
    SOURCE_NAME=$2
fi


export new_pkg_name=${TARGET_NAME,,}                                 # to lower case
export NEW_PKG_NAME=${new_pkg_name^^}                                # to upper case
export NewPkgName=`echo "${new_pkg_name}" | perl -pe 's/(^|_)([a-z])/uc($2)/ge'`  # to camel case 


export old_pkg_name=${SOURCE_NAME,,}                                 # to lower case
export OLD_PKG_NAME=${old_pkg_name^^}                                # to upper case
export OldPkgName=`echo "${old_pkg_name}" | perl -pe 's/(^|_)([a-z])/uc($2)/ge'`  # to camel case 

echo "changing in files ${old_pkg_name} to ${new_pkg_name}"
echo "changing in files ${OLD_PKG_NAME} to ${NEW_PKG_NAME}"
echo "changing in files ${OldPkgName}   to ${NewPkgName}"
echo "moving ./cfg/${OldPkgName}.cfg to ./cfg/${NewPkgName}.cfg"
echo "moving ./include/${old_pkg_name}.cfg to ./include/${new_pkg_name}.cfg"

echo "------------------------------------"
read -p "Do you wish to start? y/n" yn
case $yn in
    [Yy]* ) 
        find . -type f \( -iname "*.*" ! -iname "rename.sh" \) -exec sed -i 's/'"${old_pkg_name}"'/'"${new_pkg_name}"'/g' {} +
        find . -type f \( -iname "*.*" ! -iname "rename.sh" \) -exec sed -i 's/'"${OLD_PKG_NAME}"'/'"${NEW_PKG_NAME}"'/g' {} +
        find . -type f \( -iname "*.*" ! -iname "rename.sh" \) -exec sed -i 's/'"${OldPkgName}"'/'"${NewPkgName}"'/g' {} +
        mv cfg/${OldPkgName}.cfg cfg/${NewPkgName}.cfg
        mv include/${old_pkg_name} include/${new_pkg_name}
        echo "------------------------------------"
        echo "Done :-) --> try catkin_make in your workspace root!"
        ;;
    [Nn]* ) 
        echo "abort renaming"
        ;;
esac
    
