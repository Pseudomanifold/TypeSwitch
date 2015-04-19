CMAKE_MINIMUM_REQUIRED( VERSION 2.8 )

PROJECT( TypeSwitch )

SET( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra" )

ADD_EXECUTABLE( type_list_demo   type_list_demo.cc   )
ADD_EXECUTABLE( type_switch_demo type_switch_demo.cc )
