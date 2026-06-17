project(ComplexWalletMgr)
cmake_minimum_required(VERSION 4.3)

add_executable(ComplexWalletMgr)

target_sources(ComplexWalletMgr
  PRIVATE
    tools/complexwalletmgr.cpp
)
