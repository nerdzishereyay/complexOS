project(complexwalletmgr)
cmake_minimum_required(VERSION 4.3)


add_executable(complexwalletmgr tools/complexwalletmgr.cpp)
target_link_libraries(complexwalletmgr
  PRIVATE ftxui::screen
  PRIVATE ftxui::dom
  PRIVATE ftxui::component
)

target_sources(complexwalletmgr
  PRIVATE
    tools/complexwalletmgr.cpp
)
