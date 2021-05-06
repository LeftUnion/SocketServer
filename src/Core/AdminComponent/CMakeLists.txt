set(Component "AdminComponent")

file(GLOB_RECURSE HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp")
file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_library(${Component}
  ${HEADERS}
  ${SOURCES}
)

target_link_libraries(${Component}
  PUBLIC
    Core::NetworkComponent
    Core::MessageComponent
)

target_include_directories(${Component}
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include/${Component}
)

add_library(${PROJECT_NAME}::${Component} ALIAS ${Component})
