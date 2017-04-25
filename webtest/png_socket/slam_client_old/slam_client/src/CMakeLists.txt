


# 增加opencv的依赖
FIND_PACKAGE( OpenCV REQUIRED )
include_directories(include ${OpenCV_INCLUDE_DIRS})


ADD_LIBRARY( slambase slamBase.cpp )
TARGET_LINK_LIBRARIES( slambase ${OpenCV_LIBS}  )

ADD_EXECUTABLE( main main.cpp )
TARGET_LINK_LIBRARIES( main slambase ${OpenCV_LIBS} )
