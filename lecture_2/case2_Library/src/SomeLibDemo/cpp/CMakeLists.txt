cmake_minimum_required(VERSION 3.13)
project(mearlymath)

# ar rcs libmearlymath.a adder.o 와 같은 기능을 함. 즉 adder.cpp를 통해 만들어진 obj 인 adder.o를 가지고 static library를 만듦
add_library(mearlymath adder.cpp)


# 11번째 라인이 실행되기 전에, static library가 헤더파일을 읽어올 수 있도록 경로를 잡아준다.
# PROPERTIES 키워드는 이 대상의 속성(properties)을 설정하는 명령어의 시작을 나타냅니다.
# PUBLIC_HEADER는 설정하려는 속성(properties)의 종류를 나타냅니다. 이 경우, mearlymath 라이브러리가 외부에 공개하는 헤더 파일에 관한 속성을 설정하려는 것입니다.
set_target_properties(mearlymath PROPERTIES PUBLIC_HEADER adder.h)


# mearlymath 정적 라이브러리를 다른 CMakeLists.txt에서 상대 경로 입력을 안 하더라도, 경로를 잡을 수 있도록 /usr/local/lib경로에 install해주자.
# LIBRARY DESTINATION lib 부분은 대상이 라이브러리인 경우 해당 라이브러리를 설치할 경로를 지정합니다. 여기서는 라이브러리를 시스템의 lib 디렉토리에 설치한다는 의미입니다.
# PUBLIC_HEADER DESTINATION include/ 부분은 라이브러리의 공개 헤더 파일을 설치할 경로를 지정합니다. 여기서는 헤더 파일들을 시스템의 include 디렉토리에 설치한다는 의미입니다.
# sudo make install을 해야 파일이 설치 된다.
install(TARGETS ${PROJECT_NAME} LIBRARY DESTINATION lib # usr/local/lib 경로에 libmearlymath.a 파일 생성됨
    PUBLIC_HEADER DESTINATION include/	# /usr/local/include 경로에 adder.h 파일 생성됨
)
