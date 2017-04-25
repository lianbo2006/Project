# ��~^�~J| opencv�~Z~D��~]��~V
FIND_PACKAGE( OpenCV REQUIRED )
include_directories(include ${OpenCV_INCLUDE_DIRS})

ADD_EXECUTABLE(socket_server socket_server.cpp )
TARGET_LINK_LIBRARIES(socket_server ${OpenCV_LIBS})


