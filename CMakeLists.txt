project(complexwalletmgr
  LANGUAGES CXX
  VERSION 0.0.1
)
cmake_minimum_required(VERSION 4.3)


add_executable(complexwalletmgr tools/complexwalletmgr.cpp)

include(FetchContent)
FetchContent_Declare(ftxui
    GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
    GIT_TAG v3.0.0
)

target_link_libraries(complexwalletmgr
  PRIVATE ftxui::screen
  PRIVATE ftxui::dom
  PRIVATE ftxui::component
)

target_sources(complexwalletmgr
  PRIVATE
    tools/complexwalletmgr.cpp
)
