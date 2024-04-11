cmake_minimum_required(VERSION 3.13)
project(testsome)

add_executable(testsome main.cpp)

# 대부분 INTERFACE 키워드로 PRIVATE를 쓰면 된다고 한다.
# testsom 실행파일이 다른 경로에 있는 static library 인 mearlymath 라이브러리에 접근하기위해서는 해당 라이브러리가 어느 경로에 있는지 알아야 한다. 
# ${CMAKE_SOURCE_DIR} 은 CMakeLists.txt파일이 존재하는 pwd 경로이다. pwd경로로부터 ../../SomeLibDemo/cpp/build 위치에 mearlymath 정적 라이브러리가 위치한다.
# 그런데, 사실 /../../SomeLibDemo/cpp/build 와 같이 상대 경로를 직접 입력해주기는 꽤나 까다로운 일이다.
# 이제 아래의 복잡한 상대경로를 적을 필요가 없다. 왜냐면 /home/keti/CMakeList_lecture/lecture_2/case2_Library/src/SomeLibDemo/cpp/CMakeLists.txt의 11, 18번째 줄에서 
# 내 라이브러리를 전역에 공유 했기 때문이다. 
# target_link_directories(testsome PRIVATE ${CMAKE_SOURCE_DIR}/../../SomeLibDemo/cpp/build) # 이젠 이걸 할 필요가 없어진거다.




# target_link_directories 를 통해 라이브러리의 경로를 알아냈으니, 실행파일과 링킹하자.  
target_link_libraries(testsome mearlymath)
