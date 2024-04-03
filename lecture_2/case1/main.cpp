/*
이 코드는 프로그램에 전달된 모든 명령줄 인자를 하나의 문자열로 연결(concatenate)하는 기능을 수행합니다.
*/
#include <iostream>
#include <string>

// argc (Argument Count)는 명령줄을 통해 프로그램에 전달된 인자(파라미터)의 수를 나타냅니다. 이 값은 항상 1 이상이며, 프로그램 자체의 이름도 인자로 취급되기 때문입니다.
// argv (Argument Vector)는 실제 인자들의 값을 포함하는 문자열 배열입니다. argv[0]은 프로그램의 이름이고, argv[1]부터 나머지 인자들의 값을 순서대로 가집니다.
int main(int argc , char ** argv)
{
    int count = 1;
    std::string name;

    while(count < argc)
    {
        name += argv[count++];
    }

    name.erase(0,name.find_first_not_of("\t\n\r\f\v"));
    name.erase(name.find_last_not_of("\t\n\r\f\v")+1);
    std::cout << name <<" "<< std::endl;
    return 0;
}


// 실행 예시  ./main hi im doyoung