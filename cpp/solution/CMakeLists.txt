cmake_minimum_required( VERSION 3.5.1 )

project(lab_02_blending)

# Compiler flags
if (MSVC)
  set(compiler_options /W4)
  add_definitions(/D_USE_MATH_DEFINES)
else ()
  set(compiler_options -Wall -Wextra -Wpedantic)
endif (MSVC)

# Find libraries
find_package(OpenCV 4 REQUIRED)

add_executable(${PROJECT_NAME}
  main.cpp
  lab_2.h
  lab_2.cpp
  laplace_blending.h
  laplace_blending.cpp
  linear_blending.h
  linear_blending.cpp
  )

target_link_libraries(${PROJECT_NAME}
  ${OpenCV_LIBS}
  )

target_compile_options(${PROJECT_NAME} PRIVATE ${compiler_options})
set_target_properties(${PROJECT_NAME} PROPERTIES
  CXX_STANDARD_REQUIRED ON
  CXX_STANDARD 14
  )
