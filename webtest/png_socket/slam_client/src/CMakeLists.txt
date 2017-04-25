


# 增加opencv的依赖
FIND_PACKAGE( OpenCV REQUIRED )
include_directories(include ${OpenCV_INCLUDE_DIRS})


ADD_LIBRARY( slambase slamBase.cpp )
TARGET_LINK_LIBRARIES( slambase ${OpenCV_LIBS}  )

ADD_EXECUTABLE( socket_client socket_client.cpp )
TARGET_LINK_LIBRARIES( socket_client slambase ${OpenCV_LIBS} )
