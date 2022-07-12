set(component "SocketServerComponent")

find_package(Qt5 ${QT_REQUIRED_VERSION}
	COMPONENTS REQUIRED
            Sql
)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
set(OPENSSL_USE_STATIC_LIBS TRUE)
find_package(OpenSSL REQUIRED)

file(GLOB_RECURSE HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/inclde/BaseDataBase.hpp" )
file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/BaseDataBase.cpp")

add_executable(Server ./src/main.cpp ${HEADERS} ${SOURCES})

target_link_libraries(Server
    PRIVATE
      Qt5::Sql
      Threads::Threads
      OpenSSL::Crypto
)

target_include_directories(Server
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include/${Component}
)

