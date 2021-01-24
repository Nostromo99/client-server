cmake_minimum_required(VERSION 3.0.0)
project(client_server VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(client_server server.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
find_package(asio CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE asio asio::asio)