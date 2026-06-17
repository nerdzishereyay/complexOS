project(Complexwalletmgr)
cmake_minimum_required(VERSION 4.3)

add_executable(Complexwalletmgr)

target_sources(Complexwalletmgr
  PRIVATE
    tools/complexwalletmgr.cpp
)
