project(complexwalletmgr)
cmake_minimum_required(VERSION 4.3)

find_package(ftxui
  REQUIRED
)
add_executable(complexwalletmgr tools/complexwalletmgr.cpp)
target_link_libraries(complexwalletmgr
  PRIVATE
    ftxui::screen
    ftxui::dom
    ftxui::component
)

target_sources(complexwalletmgr
  PRIVATE
    tools/complexwalletmgr.cpp
)
