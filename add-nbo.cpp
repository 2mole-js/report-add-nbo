#include <stdio.h>
#include <stdint.h>
#include <cstdio>
#include <cstdlib>
#include <netinet/in.h>

void add(uint32_t num1,uint32_t num2){

    uint32_t hbo_num1 = ntohl(num1);
    uint32_t hbo_num2 = ntohl(num2);
    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", hbo_num1, hbo_num1, hbo_num2, hbo_num2, hbo_num1+hbo_num2, hbo_num1+hbo_num2);

}


int main (int argc, char *argv[]){

    if (argc!=3){
        printf("ERROR\n");
        printf("must 2 argc");
        return 1;
    }
    // fopen 구문 : FILE *변수(포인터) = fopen(파일의 이름, 옵션)
    FILE *file_1 = fopen(argv[1], "rb");
    FILE *file_2 = fopen(argv[2], "rb");



    uint32_t file_num1;
    uint32_t file_num2;
    //file_num1, file_num2에 저장하며 fread(%변수 의 주소위치 (&사용), 사이즈 크기, 몇개받아올지, 읽어올 파일명)
    fread(&file_num1, 1, 32, file_1);
    fread(&file_num2, 1, 32, file_2);

    add(file_num1,file_num2);

}

