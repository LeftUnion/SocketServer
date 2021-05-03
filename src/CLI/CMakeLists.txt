project(CLI)

find_package(Qt5 ${QT_REQUIRED_VERSION} COMPONENTS REQUIRED
  Core
)

file(GLOB_RECURSE HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp")
file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_executable(SocketServer main.cpp)

target_link_libraries(SocketServer
    PUBLIC
        Qt5::Core
        Core::AdminComponent
)


