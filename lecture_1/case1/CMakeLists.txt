cmake_minimum_required(VERSION 3.13)

project(KIM)

add_executable(${PROJECT_NAME} main.cpp)


# TARGETS 옆에는 executable파일이 와도 되고, library가 와도 된다. 여기서는 executable파일이 왔다.
# 위 install(TARGET <Target_목록> DESTINATION <설치 경로>)
# 즉 KIM 실행파일을 /usr/local/bin 경로에 install하겠다는 뜻.
# 이 경우 build 폴더에서 sudo make install 추가로 해줘야 /usr/local/bin 경로에 KIM 실행파일이 생김
install(TARGETS ${PROJECT_NAME} DESTINATION bin)
