# ��~^�~J| opencv�~Z~D��~]��~V
FIND_PACKAGE( OpenCV REQUIRED )
ADD_EXECUTABLE(server server_node.cpp )
TARGET_LINK_LIBRARIES(server ${OpenCV_LIBS})


