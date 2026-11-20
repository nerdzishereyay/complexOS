project(complexwalletmgr
  LANGUAGES CXX
  VERSION 0.0.1
)
cmake_minimum_required(VERSION 4.3)



add_executable(complexwalletmgr tools/complexwalletmgr.cpp)

include(FetchContent)

set(FTXUI_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(FTXUI_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(FTXUI_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(FTXUI_BUILD_TESTS_FUZZER OFF CACHE BOOL "" FORCE)
set(FTXUI_ENABLE_INSTALL OFF CACHE BOOL "" FORCE)

FetchContent_Declare(ftxui
  GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
  GIT_TAG v7.0.0
  GIT_SHALLOW TRUE
  GIT_PROGRESS TRUE
)
FetchContent_MakeAvailable(ftxui)

target_link_libraries(complexwalletmgr PRIVATE
    ftxui::dom
    ftxui::component
)

target_sources(complexwalletmgr
  PRIVATE
    tools/complexwalletmgr.cpp
)
