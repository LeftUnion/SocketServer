project(Core)

set(CMAKE_AUTOMOC ON)

add_subdirectory(NetworkComponent)
add_subdirectory(MessageComponent)
add_subdirectory(AdminComponent)

list(APPEND components "AdminComponent")
list(APPEND components "NetworkComponent")
list(APPEND components "MessageComponent")

message("Found the following components:")
foreach(component ${components})
  message("  ${component}")
endforeach()

