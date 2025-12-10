#include "numberbook.h"

int n = 0; // 현재 연락처 개수 연락처 추가를 할 수록 n은 점점 늘어나게 해놈
int size = 1; // 현재 연락처 크기 realloc 함수를 이용해서 크기를 늘어나게 해놈
address* telephone = NULL; // address를 가리키는 telephone이라는 포인터를 NULL로 초기화를 시킴