# Generic test that uses conan libs
add_executable(example main.cpp) 
target_link_libraries(
  example 
  PRIVATE project_options
          project_warnings
          tml_lib
          )
