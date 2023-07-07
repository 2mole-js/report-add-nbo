#include <stdio.h>                  //C언어 기반 라이브러리 사용호출을 위한 헤더
#include <stdint.h>                 //uint_32 를 사용하기 위한 헤더
#include <cstdio>                   //C++에서 C언어의 입출력 함수를 사용할 수 있도록 하는 헤더
#include <cstdlib>                  //C++에서 C언어의 메모리 관련 함수를 사용할 수 있도록 하는 헤더
#include <netinet/in.h>         //리눅스 상에서 ntohl를 사용하기 위해 사용하는 헤더 
//#include <winsock.h>               //윈도우 상에서 인터넷 네트워크 및 소켓 관련 함수 제공 <ver.2도 있음>
//uint32_t (32bit)값의 변수를 받아와 NetByOrder로 저장된 값을 HostByOrder로 변환한다.
void add(uint32_t num1,uint32_t num2){
    uint32_t hbo_num1 = ntohl(num1);
    uint32_t hbo_num2 = ntohl(num2);
    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", hbo_num1, hbo_num1, hbo_num2, hbo_num2, hbo_num1+hbo_num2, hbo_num1+hbo_num2);

}


//main 함수 호출시, 인자를 받아오며 해당 인자 개수 확인 및 해당 인자를 통한 파일명 받아오기
int main (int argc, char *argv[]){
    // 인자 2개를 받지 않을 경우 에러 표출
    if (argc!=3){
        printf("ERROR\n");
        printf("must 2 argc");
        return 1;
    }
    // fopen 구문 : FILE *변수(포인터) = fopen(파일의 이름, 옵션)
    // file_x 에 호출된 인자를 열어 저장한다.
    FILE *file_1 = fopen(argv[1], "rb");
    FILE *file_2 = fopen(argv[2], "rb");
    

    // 해당 파일은 32bit로 저장되어 있기 때문에 변수를 uint32_t 로 지정한다. 
    uint32_t file_num1;
    uint32_t file_num2;
    //file_num1, file_num2에 저장하며 fread(%변수 의 주소위치(버퍼) (&사용), 배열 사이즈 크기, 한개의 배열에 몇개받아올지, 읽어올 파일명)
    fread(&file_num1, 1, 32, file_1);
    fread(&file_num2, 1, 32, file_2);

    // 받아온 file_num1, file_num2의 값이 없을경우 종료
    if (file_num1 == NULL || file_num2 == NULL){
        printf("ERROR");
        printf("file is not existence");
        return 1;
    }

        
    // 두 파일을 더하는 함수 호출
    add(file_num1,file_num2);

    //file close
    fclose(file_1);
    flcose(file_2);

}

