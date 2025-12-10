#include "video.h"

int Nummember = 0; // 현재 회원정보 개수 회원정보가 추가될 때마다 개수를 늘림
int Numvideo = 0; // 현재 비디오 개수 비디오가 추가될 때마다 개수를 늘림
int membersize = 1; // 현재 회원 정보의 크기 realloc 함수를 이용해서 크기를 늘어나게 함
int videosize = 1; // 현재 비디오 정보의 크기 realloc 함수를 이용해서 크기를 늘어나게 함
int firstmembermanager = 0; // 회원 정보가 하나도 없을 때 관리자 모드를 관리하기 위한 변수
int firstvideomanager = 0; // 위와 같은 이유
video* vod = NULL; // video를 가리키는 vod라는 포인터를 NULL로 초기화
member* guest = NULL; // member를 가리키는 guest라는 포인터를 NULL로 초기화