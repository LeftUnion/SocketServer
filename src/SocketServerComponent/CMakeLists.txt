set(component "SocketServerComponent")

find_package(Qt5 ${QT_REQUIRED_VERSION}
	COMPONENTS REQUIRED
          Sql
)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

file(GLOB_RECURSE HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/inclde/*.hpp" )
file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_executable(Server ${HEADERS} ${SOURCES})
target_link_libraries(Server
    PRIVATE
      Qt5::Sql
      Threads::Threads
    )
target_include_directories(Server
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include/${Component}
)

