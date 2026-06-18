project(Complexwalletmgr)
cmake_minimum_required(VERSION 4.3)

add_executable(Complexwalletmgr)





add_library(component
  include/ftxui/component/screen_interactive.hpp
)
target_sources(Complexwalletmgr
  PRIVATE
    tools/complexwalletmgr.cpp
)
