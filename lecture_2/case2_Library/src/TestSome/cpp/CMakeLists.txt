cmake_minimum_required(VERSION 3.13)
project(testsome)

add_executable(testsome main.cpp)

# 대부분 INTERFACE 키워드로 PRIVATE를 쓰면 된다고 한다.
# testsom 실행파일이 다른 경로에 있는 static library 인 mearlymath 라이브러리에 접근하기위해서는 해당 라이브러리가 어느 경로에 있는지 알아야 한다. 
# ${CMAKE_SOURCE_DIR} 은 CMakeLists.txt파일이 존재하는 pwd 경로이다. pwd경로로부터 ../../SomeLibDemo/cpp/build 위치에 mearlymath 정적 라이브러리가 위치한다.
target_link_directories(testsome PRIVATE ${CMAKE_SOURCE_DIR}/../../SomeLibDemo/cpp/build)

# target_link_directories 를 통해 라이브러리의 경로를 알아냈으니, 실행파일과 링킹하자.
target_link_libraries(testsome mearlymath)