cmake_minimum_required(VERSION 3.8)
project(loop_topic_test)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

# Set target
add_executable(loop_publisher_node src/loop_publisher.cpp)
target_compile_features(loop_publisher_node PRIVATE c_std_99 cxx_std_17)
ament_target_dependencies(loop_publisher_node rclcpp std_msgs)

add_executable(loop_subscriber_node src/loop_subscriber.cpp)
target_compile_features(loop_subscriber_node PRIVATE c_std_99 cxx_std_17)
ament_target_dependencies(loop_subscriber_node rclcpp std_msgs)

install(
  TARGETS
  loop_publisher_node
  loop_subscriber_node
  DESTINATION lib/${PROJECT_NAME}
)

# Install launch files.
install(
  DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
