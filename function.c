#define _CRT_SECURE_NO_WARNINGS
#include "video.h"

// 검색함수에서 데이터의 일관성을 지키기 위해서 진행한것
// 우선 관리자 모드가 실행되어 있는지 확인하면서 관리자가 아닌경우 검색을 못하게 하며, 허가받지 않은 데이터의 접근을 방지한다. 이로써 데이터의 무결성과 접근권한을 보호함.
// strstr 함수를 사용하여 데이터의 일부라도 검색이 되게 하여, 데이터의 접근성을 높이고 일관성을 해치지 않는다.
// searching 변수를 이용해서 검색 결과가 있는지를 확인하며 데이터의 일관성을 유지한다.
void videosearch() { // 비디오 검색 함수
   char videoname[100]; // videoname을 100byte의 배열로 선언한 이유는 내가 문자나 숫자를 얼마나 입력할지 모르기 때문에 100byte로 설정함.
   int searching = 0; // searching은 0으로 초기화를 시켜놓고 검색한 내용이 있을 때 1로 변경하기 위에서 0으로 지정
   if (firstvideomanager == 0) {
      printf("현재 관리자 모드가 아니기 때문에 검색을 할 수 없습니다.\n\n");
      return;
   }
   while (1) { // while(1)로 항상 참으로 만든 후에 마지막에 break;를 함
      printf("검색할 비디오를 입력하세요(부분 문자 검색가능): ");
      scanf("%[^\n]", videoname); //  %[^\n]은 공백을 제외하는 문자열 입력
      getchar(); // getchar(); 로 입력 버퍼를 지움
      for (int i = 0; i < videosize; i++) {
         if (strstr(vod[i].videonumber, videoname)) { // 내가 검색한 부분 문자열이 videonumber, 즉 비디오 고유번호에 포함되는지를 확인하고 포함된다면 출력함.
            printf("고유번호: %s\n", vod[i].videonumber);
            printf("이름: %s\n", vod[i].name);
            printf("장르: %s\n", vod[i].genre);
            printf("감독: %s\n", vod[i].director);
            printf("대여한 회원 id: %s\n", vod[i].rentmemberid);
            printf("대여 여부(1: 대여 가능, 0: 대여중): %d\n\n", vod[i].rental);
            searching = 1;
         }
         else if (strstr(vod[i].name, videoname)) { // 위와 같은 원리로 이름에서 부분 문자열을 검색함.
            printf("고유번호: %s\n", vod[i].videonumber);
            printf("이름: %s\n", vod[i].name);
            printf("장르: %s\n", vod[i].genre);
            printf("감독: %s\n", vod[i].director);
            printf("대여한 회원 id: %s\n", vod[i].rentmemberid);
            printf("대여 여부(1: 대여 가능, 0: 대여중): %d\n\n", vod[i].rental);
            searching = 1;
         }
         else if (strstr(vod[i].genre, videoname)) { // 장르에서 부분 문자열 검색하는 과정
            printf("고유번호: %s\n", vod[i].videonumber);
            printf("이름: %s\n", vod[i].name);
            printf("장르: %s\n", vod[i].genre);
            printf("감독: %s\n", vod[i].director);
            printf("대여한 회원 id: %s\n", vod[i].rentmemberid);
            printf("대여 여부(1: 대여 가능, 0: 대여중): %d\n\n", vod[i].rental);
            searching = 1;
         }
         else if (strstr(vod[i].director, videoname)) {
            printf("고유번호: %s\n", vod[i].videonumber);
            printf("이름: %s\n", vod[i].name);
            printf("장르: %s\n", vod[i].genre);
            printf("감독: %s\n", vod[i].director);
            printf("대여한 회원 id: %s\n", vod[i].rentmemberid);
            printf("대여 여부(1: 대여 가능, 0: 대여중): %d\n\n", vod[i].rental);
            searching = 1;
         }
         // 비디오 구조체에는 고유번호, 이름, 장르, 감독, 대여한 회원, 대여 여부가 출력이 되었지만 비디오 검색에서는 필수 과정은 아닌 것 같아 제외함.
      }
      if (searching == 0) { //  만약 searching이 0이라면 앞에서 초기화 한 값이 그대로 있는 것이므로 검색 결과가 없는 것임. 예외 처리 과정
         printf("검색한 비디오가 존재하지 않습니다.\n\n");
         break;
      }
      break;
   }
}

void membersearch() { //  회원 검색 함수
   char membername[100]; // 비디오 검색 함수와 같은 원리로 코드를 작성하였음.
   int searching = 0;
   if (firstmembermanager == 0) {
      printf("현재 관리자 모드가 아니기 때문에 검색을 할 수 없습니다.\n\n");
      return;
   }
   while (1) {
      printf("검색할 회원을 입력하세요(부분 문자 검색가능): ");
      scanf("%[^\n]", membername);
      getchar();
      for (int i = 0; i < membersize; i++) {
         if (strstr(guest[i].number, membername)) {
            printf("인덱스 번호: %d\n", i);
            printf("id: %s\n", guest[i].id);
            printf("이름: %s\n", guest[i].name);
            printf("전화번호: %s\n", guest[i].number);
            printf("성별: %s\n", guest[i].gender);
            printf("대여한 비디오 개수: %d\n\n", guest[i].rentcount);
            searching = 1;
         }
         else if (strstr(guest[i].name, membername)) {
            printf("인덱스 번호: %d\n", i);
            printf("id: %s\n", guest[i].id);
            printf("이름: %s\n", guest[i].name);
            printf("전화번호: %s\n", guest[i].number);
            printf("성별: %s\n", guest[i].gender);
            printf("대여한 비디오 개수: %d\n\n", guest[i].rentcount);
            searching = 1;
         }
         else if (strstr(guest[i].number, membername)) {
            printf("인덱스 번호: %d\n", i);
            printf("id: %s\n", guest[i].id);
            printf("이름: %s\n", guest[i].name);
            printf("전화번호: %s\n", guest[i].number);
            printf("성별: %s\n", guest[i].gender);
            printf("대여한 비디오 개수: %d\n\n", guest[i].rentcount);
            searching = 1;
         }
         else if (strstr(guest[i].gender, membername)) {
            printf("인덱스 번호: %d\n", i);
            printf("id: %s\n", guest[i].id);
            printf("이름: %s\n", guest[i].name);
            printf("전화번호: %s\n", guest[i].number);
            printf("성별: %s\n", guest[i].gender);
            printf("대여한 비디오 개수: %d\n\n", guest[i].rentcount);
            searching = 1;
         }
      }
      if (searching == 0) { // 회원이 존재하지 않을 때의 예외 처리
         printf("검색한 회원이 존재하지 않습니다.\n\n");
         break;
      }
      break;
   }
}
 // strcmp 함수를 사용하여 이름을 입력하여 잘못된 입력이나 잘못된 데이터가 반영이 되지 않도록 함.
 // 동명이인을 처리하여 데이터의 정확성을 지킴
 // 특정 아이디의 회원이 비디오를 대여하면 비디오의 대여 가능 상태를 0으로 바꿔서 대여불가능 하게 만듬, 하나의 비디오가 중복으로 대여되지 않도록 함. 
 // 비디오의 대여가능 여부를 확인하여 대여 가능한 비디오만 대여를 할 수있도록 함으로써 시스템의 상태와 일관된 대여가 이루어 지게 함.
 // 대여를 할 때 사용자가 선택을 함으로써 선택 과정을 명확하게 처리하여 데이터의 일관성을 유지함
void rent() { // 비디오 대여 함수
   char searchname[100]; // searchname배열은 회원 이름을 입력한 값이 들어감. 100byte로 설정한 이유는 얼마나 입력할지 정해지지 않았기 떄문임.
   char rentname[100]; // rentname배열은 해당 이름으로 대여하는 것을 확인할 때 들어감. 100byte의 이유는 위에 설명함.
   char rentid[100]; // rentid 배열은 대여를 하면서 id를 입력받아서 대여를 하기 때문에 id를 입력 받는 배열임. 
   char rentvideo[100]; // rentvideo 배열은 대여 과정에서 대여할 비디오의 고유번호를 입력 받을 때 사용함.
   int searching = 0; // 회원이 존재함을 찾기 위해서 변수를 지정함
   int duplicate = 0; // 동명이인이 있을 때를 처리 하기 위해서 변수를 지정함
   int idfound = 0; // id를 찾았을 때 1로 바꾸기 위해서 0으로 초기화를 시킴.
   int memberindex = -1; // memberindex를 -1로 해놓은 이유는 0으로 하면 0번째 인덱스에 접근 할 수도 있기 때문에 -1로 지정함
   printf("회원 이름을 입력하세요: ");
   scanf("%[^\n]", searchname);
   getchar();
   for (int i = 0; i < Nummember; i++) {
      if (strcmp(guest[i].name, searchname) == 0) { // strcmp함수를 이용해서 문자열을 비교하고 내가 입력한 이름과 같으먼 searching을 1로 바꿈.
         searching = 1;
         break;
      }
   }
   if (searching == 0) { // 만약 searching이 0이라면 입력한 이름이 존재하지 않는 것이기 때문에 존재하지 않는다는 문구를 출력함. 예외 처리 과정
      printf("해당 이름의 회원이 존재하지 않습니다.\n\n");
      return;
   }
   if (searching) { // 입력한 이름이 존재할 때 조건문이 실행됌
      printf("입력한 이름이 존재합니다. 해당 이름으로 대여하시겠습니까?(1: 예, 1이외의 문자열: 아니오) ");
      scanf("%s", rentname);
      getchar();
      if (rentname[0] == '1') { // rentname[0]으로 하는 이유는 앞에 있는 숫자만 받기 위해서이다.
         for (int i = 0; i < Nummember; i++) {
            if (strcmp(guest[i].name, searchname) == 0) {
               printf("인덱스 번호: %d\n", i);
               printf("id: %s\n", guest[i].id);
               printf("이름: %s\n", guest[i].name);
               printf("전화번호: %s\n", guest[i].number);
               printf("성별: %s\n", guest[i].gender);
               printf("대여한 비디오 개수: %d\n\n", guest[i].rentcount);
               duplicate++;
               // 동명이인을 찾는 과정 그리고 찾았다면 대여를 id로 하기 때문에 id를 찾기 위해서 회원 정보를 출력함.
            }
         }
         if (duplicate == 1) { // 동명이인이 존재하지 않을 때
            printf("비디오를 대여할 아이디를 선택해주세요: ");
            scanf("%s", rentid);
            for (int i = 0; i < Nummember; i++) {
               if (strcmp(guest[i].id, rentid) == 0) {
                  idfound = 1;
                  memberindex = i;
                  break;
                  // 대여할 아이디를 입력 받고 strcmp를 이용해서 비교한후 같다면 idfound를 1로 바꾸고 memberindex = i로 지정
               }
            }
            if (idfound == 0) { // 만약 idfound가 0이라면 위에서 아이디를 못찾은것이므로 아이디가 존재하지 않다는 문구와 함께 예외 처리를 함.
               printf("입력한 아이디가 존재하지 않습니다.\n\n");
               return;
            }
            printf("%s아이디의 회원으로 비디오를 대여하겠습니다.\n", rentid); // 아이디가 존재하면 출력됌
            int availablevideo = 0; // availablevideo 변수는 대여 가능한 비디오를 찾았을 때를 처리하기 위해서 만듬.
            for (int i = 0; i < Numvideo; i++) {
               if (vod[i].rental == 1) {
                  availablevideo++;
                  break;
                  // 만약 availablevideo가 1이상이면 대여가 가능한 비디오가 있는 것임.
               }
            }

            if (availablevideo == 0) {
               printf("대여 가능한 비디오가 존재하지 않습니다.\n\n");
               return;
               // 만약 availablevideo가 0이면 대여 가능한 비디오가 존재하지 않는 것이므로 예외 처리를 함.
            }

            printf("대여 가능한 비디오 목록: \n"); // 대여 가능한 비디오 목록을 출력해서 대여를 할 때 비디오의 고유 번호를 입력 받을 수 있도록 함.
            int available = 0; // 변수를 지정한 이유는 밑에서 대여 가능한 비디오만 출력이 되어야 하기 때문에 대여 가능이 1인 것만 찾기 위해서 변수를 지정함
            for (int i = 0; i < Numvideo; i++) {
               if (vod[i].rental == 1) {
                  printf("고유번호: %s\n", vod[i].videonumber);
                  printf("이름: %s\n", vod[i].name);
                  printf("장르: %s\n", vod[i].genre);
                  printf("감독: %s\n", vod[i].director);
                  printf("대여한 회원 id: %s\n", vod[i].rentmemberid);
                  printf("대여 여부(1: 대여 가능, 0: 대여중): %d\n\n", vod[i].rental);
                  available = 1;
                  // 만약 대여 가능 여부가 1이라면 정보를 출력하고 available을 1로 바꿈
               }
            }
            if (available == 0) {
               printf("대여 가능한 비디오가 없습니다.\n\n");
               return;
               // 만약 available이 0이라면 대여 가능한 비디오가 존재하지 않는 것이므로 예외 처리 과정.
            }
            if (Numvideo == 0) {
               printf("비디오가 존재하지 않습니다.\n\n");
               return;
            }
            printf("빌리실 비디오의 고유번호를 입력하세요: ");
            scanf("%s", rentvideo);
            getchar();

            int videorent = 0; // 밑에서 대여를 할 때 대여를 했으면 1로 바꾸기 위해서 변수를 지정함.
            for (int i = 0; i < Numvideo; i++) {
               if (strcmp(vod[i].videonumber, rentvideo) == 0) {
                  vod[i].rental = 0;
                  printf("%s번호의 비디오를 대여했습니다.\n", rentvideo);
                  strcpy(vod[i].rentmemberid, rentid);
                  guest[memberindex].rentcount++;
                  videorent = 1;
                  break;
                  // 만약 대여할 비디오의 고유번호가 비디오 목록에 존재 하면 대여를 하고 strcpy함수를이용해서 비디오 구조체 안에 들어있는 대여한 회원 id에 넣음.
                  // 빌린 비디오 개수를 하나 늘리고 위에서 선언한 videorent를 1로 바꿈
               }
            }
            if (videorent == 0) { // 만약 videorent가 0이라면 검색한 고유번호의 비디오가 존재하지 않는 것이므로 예외 처리를 함.
               printf("검색한 번호의 비디오가 존재하지 않습니다.\n\n");
               return;
            }
         }
         if (duplicate > 1) {
            printf("검색한 이름 중에서 중복된 이름이 이렇게 있습니다.\n");
            printf("비디오를 대여할 아이디를 선택해주세요: ");
            scanf("%s", rentid);
            for (int i = 0; i < Nummember; i++) {
               if (strcmp(guest[i].id , rentid) == 0) {
                  idfound = 1;
                  memberindex = i;
                  break;
                  // 대여할 아이디를 입력 받고 strcmp를 이용해서 비교한후 같다면 idfound를 1로 바꾸고 memberindex = i로 지정
               }
            }
            if (idfound == 0) { // 만약 idfound가 0이라면 위에서 아이디를 못찾은것이므로 아이디가 존재하지 않다는 문구와 함께 예외 처리를 함.
               printf("입력한 아이디가 존재하지 않습니다.\n\n");
               return;
            }
            printf("%s아이디의 회원으로 비디오를 대여하겠습니다.\n", rentid); // 아이디가 존재하면 출력됌
            int availablevideo = 0; // availablevideo 변수는 대여 가능한 비디오를 찾았을 때를 처리하기 위해서 만듬.
            for (int i = 0; i < Numvideo; i++) {
               if (vod[i].rental == 1) {
                  availablevideo++;
                  break;
                  // 만약 availablevideo가 1이상이면 대여가 가능한 비디오가 있는 것임.
               }
            }

            if (availablevideo == 0) { 
               printf("대여 가능한 비디오가 존재하지 않습니다.\n\n");
               return;
               // 만약 availablevideo가 0이면 대여 가능한 비디오가 존재하지 않는 것이므로 예외 처리를 함.
            }

            printf("대여 가능한 비디오 목록: \n"); // 대여 가능한 비디오 목록을 출력해서 대여를 할 때 비디오의 고유 번호를 입력 받을 수 있도록 함.
            int available = 0; // 변수를 지정한 이유는 밑에서 대여 가능한 비디오만 출력이 되어야 하기 때문에 대여 가능이 1인 것만 찾기 위해서 변수를 지정함
            for (int i = 0; i < Numvideo; i++) {
               if (vod[i].rental == 1) {
                  printf("고유번호: %s\n", vod[i].videonumber);
                  printf("이름: %s\n", vod[i].name);
                  printf("장르: %s\n", vod[i].genre);
                  printf("감독: %s\n", vod[i].director);
                  printf("대여한 회원 id: %s\n", vod[i].rentmemberid);
                  printf("대여 여부(1: 대여 가능, 0: 대여중): %d\n\n", vod[i].rental);
                  available = 1;
                  // 만약 대여 가능 여부가 1이라면 정보를 출력하고 available을 1로 바꿈
               }
            }
            if (available == 0) {
               printf("대여 가능한 비디오가 없습니다.\n\n");
               return;
               // 만약 available이 0이라면 대여 가능한 비디오가 존재하지 않는 것이므로 예외 처리 과정.
            }
            if (Numvideo == 0) {
               printf("비디오가 존재하지 않습니다.\n\n");
               return;
            }
            printf("빌리실 비디오의 고유번호를 입력하세요: ");
            scanf("%s", rentvideo);
            getchar();

            int videorent = 0; // 밑에서 대여를 할 때 대여를 했으면 1로 바꾸기 위해서 변수를 지정함.
            for (int i = 0; i < Numvideo; i++) {
               if (strcmp(vod[i].videonumber, rentvideo) == 0) {
                  vod[i].rental = 0;
                  printf("%s번호의 비디오를 대여했습니다.\n", rentvideo);
                  strcpy(vod[i].rentmemberid, rentid);
                  guest[memberindex].rentcount++;
                  videorent = 1;
                  break;
                  // 만약 대여할 비디오의 고유번호가 비디오 목록에 존재 하면 대여를 하고 strcpy함수를이용해서 비디오 구조체 안에 들어있는 대여한 회원 id에 넣음.
                  // 빌린 비디오 개수를 하나 늘리고 위에서 선언한 videorent를 1로 바꿈
               }
            }
            if (videorent == 0) { // 만약 videorent가 0이라면 검색한 고유번호의 비디오가 존재하지 않는 것이므로 예외 처리를 함.
               printf("검색한 번호의 비디오가 존재하지 않습니다.\n\n");
               return;
            }
         }
      }
      else { // 만약 1이 아닌 다른 숫자나 문자열을 입력하면 대여하지 않는 과정.
         printf("입력한 이름으로 대여하지 않겠습니다.\n\n");
         return;
      }
   }
}

int static videocompare(const void* first, const void* second)
{
   return strcmp(((video*)first)->name, ((video*)second)->name);
   // first포인터에 이름, second 포인터에도 이름이 들어간후 qsort함수에서 이름을 기준으로 오름차순 정렬을 함.
}
// first는 첫번째 요소를 가리킬 포인터, second는 두번째 요소를 가리킬 포인터
// void을 사용한 이유는 qsort()함수를 사용하기 위해서 qsort는 어떤 타입의 데이터도 받을 수 있어야 함
// 저장된 비디오 정보를 이름 기준으로 오름차순 정렬을 하기 위해서 사용함

// 비디오를 출력할 때 관리자 모드가 아니라면 출력을 못하게 함으로써 데이터의 사용을 막으면서 데이터의 무결성을 보호함.
// 대여 가능한 비디오만 출력할 수 있도록 함으로써 데이터의 일관성을 유지함.
void videoprint() { // 비디오 출력 함수
   if (firstvideomanager == 0) {
      printf("현재 관리자 모드가 아니기 때문에 출력을 할 수 없습니다.\n\n");
      return;
   }
   qsort(vod, Numvideo, sizeof(video), videocompare); // qsort 함수를 이용해서 비디오의 정보를 오름차순으로 정렬을 함
   if (Numvideo > 0) { // Numvideo가 현재 비디오의 개수이기 때문에 0 이상일 때만 정보를 출력함.
      int available = 0; // 변수를 지정한 이유는 밑에서 대여 가능한 비디오만 출력이 되어야 하기 때문에 대여 가능이 1인 것만 찾기 위해서 변수를 지정함
      for (int i = 0; i < Numvideo; i++) {
         if (vod[i].rental == 1) {
            printf("고유번호: %s\n", vod[i].videonumber);
            printf("이름: %s\n", vod[i].name);
            printf("장르: %s\n", vod[i].genre);
            printf("감독: %s\n", vod[i].director);
            printf("대여한 회원 id: %s\n", vod[i].rentmemberid);
            printf("대여 여부(1: 대여 가능, 0: 대여중): %d\n\n", vod[i].rental);
            available = 1;
            // 만약 대여 가능 여부가 1이라면 정보를 출력하고 available을 1로 바꿈
         }
      }
      if (available == 0) {
         printf("대여 가능한 비디오가 없습니다.\n\n");
         // 만약 available이 0이라면 대여 가능한 비디오가 존재하지 않는 것이므로 예외 처리 과정.
      }
   }
   else {
      printf("비디오가 존재하지 않습니다.\n\n");
      // 만약 Numvideo가 0보다 크지 않다면 비디오가 존재하지 않는 것.
   }
}

int static membercompare(const void* first, const void* second)
{
   return strcmp(((member*)first)->name, ((member*)second)->name);
   // first포인터에 이름, second 포인터에도 이름이 들어간후 qsort함수에서 이름을 기준으로 오름차순 정렬을 함.
}
// first는 첫번째 요소를 가리킬 포인터, second는 두번째 요소를 가리킬 포인터
// void을 사용한 이유는 qsort()함수를 사용하기 위해서 qsort는 어떤 타입의 데이터도 받을 수 있어야 함
// 저장된 회원 정보를 이름 기준으로 오름차순 정렬을 하기 위해서 사용함

void memberprint() { // 회원 정보를 출력하는 함수
   if (firstmembermanager == 0) {
      printf("현재 관리자 모드가 아니기 때문에 출력을 할 수 없습니다.\n\n");
      return;
   }
   qsort(guest, Nummember, sizeof(member), membercompare); // qsort함수를 이용해서 회원 정보를 오름차순 정렬함.
   if (Nummember > 0) { // 비디오 출력과 같은 원리로 코드를 작성함.
      for (int i = 0; i < Nummember; i++) {
         printf("인덱스 번호: %d\n", i);
         printf("id: %s\n", guest[i].id);
         printf("이름: %s\n", guest[i].name);
         printf("전화번호: %s\n", guest[i].number);
         printf("성별: %s\n", guest[i].gender);
         printf("대여한 비디오 개수: %d\n\n", guest[i].rentcount);
      }
   }
   else {
      printf("회원정보가 존재하지 않습니다.\n\n");
   }
}
// 회원정보를 추가할 떄도 마찬가지로 관리자 모드가 아닌 이상 데이터에 접근할 수 없도록 만들면서 무결성을 보호함
// 회원정보를 추가할 때, 동명이인이나, 지정된 길이를 초과해서 입력하거나, 같은 전화번호를 입력할 수 없게 하는 등, 이러한 작업에서 데이터의 일관성이 유지됨.
void memberadd() { // 회원 정보 추가 함수.
   if (firstmembermanager == 0) {
      printf("현재 관리자 모드가 아니기 때문에 추가를 할 수 없습니다.\n\n");
      return;
   }
   if (Nummember >= membersize) {
      membersize = membersize * 2; // 만약 Nummember가 membersize보다 커지면 크기를 2배 한 후에 realloc함수를 이용해서 메모리를 재할당 함.
      member* maxguest = (member*)realloc(guest, membersize * sizeof(member));
      if (maxguest == NULL) {
         printf("메모리 할당을 못했습니다.\n");
         return 1;
         // 만약 위에서 지정한 maxguest가 NULL이라면 메모리 할당을 못한것이므로 예외 처리를 함.
      }
      guest = maxguest; // 그 후에 만들어 놓은 guest에 maxguest를 넣음.
   }
   int repetition = 1; // while문을 반복하기 위해서
   char samename[100]; // 동명이인을 처리하기 위해서 100byte의 배열을 설정함.
   int duplicate = 0; // 동명이인을 처리 할 때 사용되는 변수.
   randomid(guest[Nummember].id); // 밑에서 만든 id를 랜덤으로 만드는 함수임.
   while (repetition) { // repetition은 현재 1이므로 일단 while문이 실행됌.
      printf("이름을 입력하세요: ");
      scanf("%s", guest[Nummember].name);
      repetition = 0; // 이름을 입력 받은 후에 더이상 입력을 받지 않기 위해서 repetition을 0으로 바꿈
      for (int i = 0; i < Nummember; i++) {
         if (strcmp(guest[Nummember].name, guest[i].name) == 0) {
            duplicate = 1; // 동명이인을 처리하는 과정.
         }
      }
      if (duplicate) {
         printf("같은 이름의 사람이 존재합니다.\n");
         printf("같은 이름의 다른 사람으로 저장하시겠습니까?(다른 사람이면 1 같은 사람이면 1이외의 다른 문자열) ");
         scanf("%s", samename);
         getchar();
         if (samename[0] == '1') {
            printf("같은 이름의 다른 사람으로 추가하겠습니다.\n");
            // 1을 입력하면 같은 이름의 다른사람, 즉 동명이인으로 정보를 추가함.
         }
         else {
            printf("회원 정보를 추가하지 않았습니다.\n\n");
            strcpy(guest[Nummember].id, "0");
            strcpy(guest[Nummember].name, "힣힣힣힣");
            strcpy(guest[Nummember].number, "0");
            strcpy(guest[Nummember].gender, "0");
            guest[Nummember].rentcount = 0;
            return;
            // 회원 정보를 추가하지 않았을 때 이런식의 방법을 쓴 이유는 맨 마지막에서 Nummember++을 하기 때문에 도중에 이름을 입력하고 취소를 하면
            // 쓰레기 값이 생기기 때문에 오름차순을 정렬 했을 때의 제일 마지막인 '힣힣힣힣' 을 넣어서 가장 밑으로 가게함으로써 쓰레기 값을 출력되지 않게함.
         }
      }
      if (strlen(guest[Nummember].name) > 11) {
         printf("입력한 이름이 너무 깁니다. 다시 입력하세요.\n");
         repetition = 1;
         fflush(stdin);
         // 내가 위에서 지정한 이름의 크기보다 크게 입력한다면 다시 입력을 받게 함.
      }
   }
   printf("제대로 입력되었습니다.\n\n");

   repetition = 1; // 다시 1로 만들어서 전화번호를 추가받을 수 있도록 함.
   while (repetition) { // 이름 추가 과정과 같은 원리로 코드를 작성함.
      printf("전화번호를 입력하세요(ex 010-1234-1234): ");
      scanf("%s", guest[Nummember].number);
      repetition = 0;
      for (int i = 0; i < Nummember; i++) {
         if (strcmp(guest[Nummember].number, guest[i].number) == 0) {
            printf("전화번호는 같을 수 없습니다. 다시 입력하세요.\n");
            repetition = 1;
            break;
         }
      }
      if (strlen(guest[Nummember].number) > 13) {
         printf("입력한 전화번호가 너무 깁니다. 다시 입력하세요.\n");
         repetition = 1;
         fflush(stdin);
      }
   }
   printf("제대로 입력되었습니다.\n\n");

   repetition = 1;
   while (repetition) { // 위와 같은 과정.
      printf("성별을 입력하세요(남/여): ");
      scanf("%s", guest[Nummember].gender);
      getchar();
      repetition = 0;
      if (strlen(guest[Nummember].gender) > 3) {
         printf("입력한 성별이 너무 깁니다. 다시 입력하세요.\n");
         repetition = 1;
         fflush(stdin);
      }
   }
   printf("제대로 입력되었습니다.\n\n");
   guest[Nummember].rentcount = 0; // 맨 처음에 대여한 비디오 개수는 0이기 때문에 0으로 설정함.
   Nummember++; // 정보가 다 입력이 되었다면 Nummember++을 통해서 개수를 늘림.
   printf("회원 정보 생성 완료\n\n");
   membersave(); // 회원 정보를 저장함.
}

void videoadd() { //  비디오 추가 함수
   if (firstvideomanager == 0) {
      printf("현재 관리자 모드가 아니기 때문에 추가를 할 수 없습니다.\n\n");
      return;
   }
   if (Numvideo >= videosize) { // 위에서 회원 정보 추가 함수에서 설명한 내용과 같은 원리로 코드를 작성함.
      videosize = videosize * 2;
      video* maxvod = (video*)realloc(vod, videosize * sizeof(video));
      if (maxvod == NULL) {
         printf("메모리 할당을 못했습니다.\n");
         exit(1);
      }
      vod = maxvod;
   }
   
   int repetition = 1;
   char samevideo[100];

   randomvideonumber(vod[Numvideo].videonumber);
   while (repetition) {
      printf("비디오 제목을 입력하세요: ");
      scanf("%s", vod[Numvideo].name);
      getchar();
      repetition = 0;

      if (strlen(vod[Numvideo].name) > 61) {
         printf("비디오의 제목이 너무 깁니다. 다시 입력하세요.\n");
         repetition = 1;
         fflush(stdin);
      }
   }
   printf("제대로 입력되었습니다.\n\n");

   repetition = 1;
   while (repetition) {
      printf("비디오의 장르를 입력하세요: ");
      scanf("%s", vod[Numvideo].genre);
      getchar();
      repetition = 0;
      if (strlen(vod[Numvideo].genre) > 20) {
         printf("입력한 비디오의 장르가 너무 깁니다. 다시 입력하세요.\n");
         repetition = 1;
         fflush(stdin);
      }
   }
   printf("제대로 입력되었습니다.\n\n");

   repetition = 1;
   while (repetition) {
      printf("비디오의 감독을 입력하세요: ");
      scanf("%s", vod[Numvideo].director);
      getchar();
      repetition = 0;
      if (strlen(vod[Numvideo].director) > 12) {
         printf("입력한 비디오의 감독이 너무 깁니다. 다시 입력하세요.\n\n");
         repetition = 1;
         fflush(stdin);
      }
   }

   strcpy(vod[Numvideo].rentmemberid, "없음"); // 처음에 비디오가 추가되었을 때 대여한 회원이 당연히 없어야 하므로 없음으로 문자열을 복사해서 넣어둠.
   vod[Numvideo].rental = 1; // 대여 가능 여부를 1로 만듬.

   printf("제대로 입력되었습니다.\n\n");
   Numvideo++;
   printf("비디오 생성완료\n\n");
   videosave(); // 비디오를 저장함.
}

void randomid(char* id) { // 회원 고유 정보를 랜덤으로 만드는 함수.
   int unique = 0;// 중복을 검사하기 위한 변수
   srand((unsigned)time(NULL)); // 난수 초기화

   while (!unique) {
      for (int i = 0; i < 2; i++) {
         id[i] = 'A' + rand() % 26; // 0부터 2까지 반복하면서 2개의 대문자 알파벳을 받을 수 있도록 하였으며 대문자의 총 개수는 26개 이므로 rand함수를 이용해서 고유 번호 생성.
      }
      for (int i = 2; i < 4; i++) { // 위에서 2개의 알파벳은 만들어 졌기 때문에 숫자 2개를 더 추가함.
         id[i] = '0' + rand() % 10;
      }
      id[4] = '\0'; // 문자열의 제일 마지막은 널문자가 들어감.

      unique = 1;
      for (int i = 0; i < Nummember; i++) {
         if (strcmp(guest[i].id, id) == 0) {
            unique = 0;
            printf("고유 번호는 같을 수 없습니다.\n");
            break;
            // strcmp를 이용해서 같은지를 비교하고 같으면 unique를 0으로 만듬 0이면 같은 것이기 때문에 같을 수 없다고 출력 됌. 예외 처리 과정.
         }
      }
   }
   printf("회원 고유 id가 입력되었습니다.\n\n");
}

void randomvideonumber(char* videonumber) { // 비디오 고유번호를 만드는 함수
   int unique = 0; // 회원 고유 번호를 만드는 함수와 같은 원리
   srand((unsigned)time(NULL)); // 난수 초기화

   while (!unique) {
      for (int i = 0; i < 2; i++) {
         videonumber[i] = '0' + rand() % 10;
      }
      for (int i = 2; i < 4; i++) {
         videonumber[i] = 'A' + rand() % 26;
      }
      videonumber[4] = '\0';

      unique = 1;
      for (int i = 0; i < Numvideo; i++) {
         if (strcmp(vod[i].videonumber, videonumber) == 0) {
            unique = 0;
            printf("고유 번호는 같을 수 없습니다.\n");
            break;
         }
      }
   }
   printf("비디오 고유 번호가 입력되었습니다.\n\n");
}

void videosave() { // 비디오 저장 함수.
   FILE* videobook; // 파일 포인터를 videobook으로 받음
   videobook = fopen("Video.txt", "w+"); // 현재 디렉토리에 있는 Video.txt에 저장을 하고 w+ 읽기와 쓰기 모드로 파일을 생성 하기 위함.
   if (videobook == NULL) {
      printf("파일을 열지 못했습니다.");   
      exit(1);// 만약 videobook = NULL이면 파일이 안열리는 것이므로 예외처리를 함.
   }
   for (int i = 0; i < Numvideo; i++) {
      fprintf(videobook, " %s %s %s %s %s %d\n",
         vod[i].videonumber,
         vod[i].name,
         vod[i].genre,
         vod[i].director,
         vod[i].rentmemberid,
         vod[i].rental);
   } //fprintf가 파일에 출력을 하는 것이기 때문에 비디오 정보에 있는 videonumber, name, genre, director, rentmemberid, rental을 각 인덱스에 맞게 파일안에 출력을 하고 저장을 함.
   fclose(videobook); // 파일을 닫음.
   printf("비디오가 파일에 저장되었습니다.\n\n");
}

void membersave() { // 비디오 저장과 같은 원리로 작성함.
   FILE* memberbook; 
   memberbook = fopen("Member.txt", "w+"); 
   if (memberbook == NULL) {
      printf("파일을 열지 못했습니다.");
      exit(1);
   }
   for (int i = 0; i < Nummember; i++) {
      fprintf(memberbook, " %s %s %s %s %d\n",
         guest[i].id,
         guest[i].name,
         guest[i].number,
         guest[i].gender,
         guest[i].rentcount);
   } 
   fclose(memberbook);
   printf("회원정보가 파일에 저장되었습니다.\n\n");
}

void videoload() { // 비디오를 불러오는 함수.
   FILE* videobook = fopen("Video.txt", "r+"); // videobook을 r+로 읽기와 쓰기 모드가 가능하도록 파일을 염
   if (videobook == NULL) { // videobook이 NULL이면 파일을 열지 못한것이므로 예외 처리 과정.
      printf("파일을 열지 못했습니다.");
      exit(1);
   }

   while (fscanf(videobook, " %s %s %s %s %s %d\n",
      vod[Numvideo].videonumber,
      vod[Numvideo].name,
      vod[Numvideo].genre,
      vod[Numvideo].director,
      vod[Numvideo].rentmemberid,
      &vod[Numvideo].rental) == 6) {  // fscanf를 이용해서 파일을 읽고 6개가 성공적으로 읽혔는지 확인함.

      Numvideo++; // 읽은 후 Numvideo을 증가시켜 연락처의 개수를 늘림

      // Numvideo가 videosize를 초과하면 크기를 조정하고 메모리를 재 할당함.
      if (Numvideo >= videosize) {
         videosize = videosize * 2;  // 크기를 두 배로 증가
         video* temp = (video*)realloc(vod, videosize * sizeof(video));
         if (temp == NULL) {  // temp가 NULL이먄 재할당을 못한 것이므로 예외 처리 과정.
            printf("메모리 재할당 실패\n");
            fclose(videobook); // 파일 닫기
            exit(1);
         }
         vod = temp; // 재할당을 성공하면 temp를 vod로 만듬.
      }
   }

   fclose(videobook); // 파일을 닫음.
}


void memberload() { // 비디오를 불러오는 함수와 같은 원리
   FILE* memberbook = fopen("Member.txt", "r+");
   if (memberbook == NULL) {
      printf("파일을 열지 못했습니다.");
      exit(1);
   }

   while (fscanf(memberbook, " %s %s %s %s %d\n",
      guest[Nummember].id,
      guest[Nummember].name,
      guest[Nummember].number,
      guest[Nummember].gender,
      &guest[Nummember].rentcount) == 5) {

      Nummember++; 

      if (Nummember >= membersize) {
         membersize = membersize * 2;    
         member* temp = (member*)realloc(guest, membersize * sizeof(member));
         if (temp == NULL) { 
            printf("메모리 재할당 실패\n");
            fclose(memberbook); 
            exit(1);
         }
         guest = temp; 
      }
   }

   fclose(memberbook); 
}

void videoreturn() { // 비디오를 반납하는 함수
   char searchname[100]; // 이름을 입력받을 때 사용하는 배열
   char returnvideo[100]; // 반납할 비디오의 고유번호를 입력받을 때 사용하는 변수
   char id[100]; // 동명이인이 존재할 때 회원의 고유번호를 입력받기 위해 사용하는 변수
   int duplicate = 0; // 동명이인이 존재할 때 처리하기 위한 변수
   int memberindex = -1; // memberindex를 -1로 설정한 이유는 0으로 하면 0으로 잘못 접근할 수 있기 때문.
   int rentfound = 0; // 입력한 회원이 대여한 비디오가 있을 때 체크하는 변수
   printf("회원 이름을 입력하세요: ");
   scanf("%[^\n]", searchname);
   getchar();

   for (int i = 0; i < Nummember; i++) { // 내가 입력한 이름과 정보의 이름이 같다면 정보를 출력함.
      if (strcmp(guest[i].name, searchname) == 0) {
         printf("id: %s\n", guest[i].id);
         printf("이름: %s\n", guest[i].name);
         printf("전화번호: %s\n", guest[i].number);
         printf("성별: %s\n", guest[i].gender);
         printf("대여한 비디오 개수: %d\n\n", guest[i].rentcount);
         duplicate++; // duplicate를 늘리면서 동명이인의 개수를 찾음.
         if (duplicate == 1) { // 만약 duplicate가 1이라면 동명이인이 없는 것이므로 memberindex를 i로 설정하고 문자열을 복사해서 id에 해당 회원의 id를 넣음.
            memberindex = i;
            strcpy(id, guest[i].id);
         }
      }
   }
   if (duplicate == 0) { // 만약 duplicate가 0이라면 입력한 이름이 존재하지 않는 것이므로 예외 처리 과정.
      printf("입력한 이름이 존재하지 않습니다.\n\n");
      return;
   }
   if (duplicate > 1) { // 동명이인이 존재 할때.
      printf("같은 이름의 회원이 존재합니다.\n");
      printf("회원의 id를 입력하여 반납을 진행하겠습니다.\n");
      printf("회원 id를 입력하세요: ");
      scanf("%[^\n]", id);
      getchar();
      memberindex = -1;
      for (int i = 0; i < Nummember; i++) {
         if (strcmp(guest[i].id, id) == 0) {
            strcpy(id, guest[i].id);
            memberindex = i;
            break;
            // 만약 입력한 id와 회원정보의 아이디가 같다면 입력한 아이디를 id에 복사한 후 memberindex를 i로 바꿈.
         }
      }
      if (memberindex == -1) { // 만약 memberindex가 -1이면 입력한 id의 회원이 존재하지 않는 것이므로 예외 처리 과정.
         printf("입력한 id를 가진 회원이 존재하지 않습니다.\n\n");
         return;
      }
   }
   if (guest[memberindex].rentcount == 0) { // rentcount가 0이면 대여한 비디오가 없는 것이므로 반납을 할 수가 없음.
      printf("대여한 비디오가 없습니다.\n\n");
      return;
   }
   printf("%s아이디의 회원이 대여 중인 비디오 목록.\n\n", guest[memberindex]); // 입력한 아이디의 회원이 대여중인 비디오 목록을 출력하여 고유번호를 확인함.
   for (int i = 0; i < Numvideo; i++) {
      if (vod[i].rental == 0 && strcmp(vod[i].rentmemberid, id) == 0) {
         printf("고유번호: %s\n", vod[i].videonumber);
         printf("이름: %s\n", vod[i].name);
         printf("장르: %s\n", vod[i].genre);
         printf("감독: %s\n", vod[i].director);
         printf("대여한 회원 id: %s\n", vod[i].rentmemberid);
         printf("대여 여부(1: 대여 가능, 0: 대여중): %d\n\n", vod[i].rental);
         rentfound = 1;
         // rentfound를 1로 만들어서 찾았을 때를 처리함.
      }
   }
   if (rentfound == 0) { // 만약 rentfound가 0이라면 대여중인 비디오 목록이 없는 것이므로 예외 처리 과정.
      printf("대여 중인 비디오 목록이 없습니다.\n\n");
      return;
   }
   printf("반납할 비디오의 고유번호를 입력하세요: ");
   scanf("%[^\n]", returnvideo);
   getchar();

   int revideo = 0; // 입력한 비디오의 고유번호가 존재하는지 확인하기 위한 변수
   for (int i = 0; i < Numvideo; i++) {
      if (strcmp(vod[i].rentmemberid, id) == 0 && strcmp(vod[i].videonumber, returnvideo) == 0) {
         printf("%s고유 번호의 비디오를 반납했습니다.\n", returnvideo);
         vod[i].rental = 1;
         strcpy(vod[i].rentmemberid, "없음");
         guest[memberindex].rentcount--;
         revideo = 1;
         break;
         // 만약 입력한 번호의 고유번호와 반납할 비디오의 제목이 같다면 반납을 진행하고 다시 빌린 회원 id를 없음으로 만들고 rentcount를 하나 줄인후 revideo를 1로 만듬.
      }
   }
   if (revideo == 0) { // 만약 revideo가 0이라면 입력한 비디오가 존재하지 않거나 반납할 수 없는 것이므로 예외 처리 과정.
      printf("입력한 비디오가 존재하지 않거나 반납할 수 없습니다.\n\n");
      return;
   }
}

void memberdelete() { // 회원을 제거하는 함수.
   if (firstmembermanager == 0) {
      printf("현재 관리자 모드가 아니기 때문에 삭제를 할 수 없습니다.\n\n");
      return;
   }
   char deleteid[100]; // deleteid는 제거할 아이디를 입력받을 때 사용하는 변수.
   char select[100]; // select라는 변수로 문자열 배열을 100byte만큼의 크기로 받아서 내가 번호를 입력할 때 숫자만이 아닌 문자로도 입력을 가능하게 함
   char really[100]; // 위와 같은 이유
   while (1) {
      printf("1. 회원 정보 전체삭제 \n");
      printf("2. 회원 정보 선택삭제 \n");
      printf("번호를 입력하세요: ");
      scanf("%[^\n]", select);
      getchar();
      if (Nummember == 0) { // 만약 Nummmember가 0이라면 회원정보가 없는 것이므로 회원 정보가 존재하지 않는다는 문구를 출력하게 함. 예외 처리 과정.
         printf("회원정보가 존재하지 않습니다.\n\n");
         return;
      }
      switch (select[0]) {
      case '1':
         for (int i = 0; i < Nummember; i++) {
            if (guest[i].rentcount > 0) {
               printf("%s이름의 회원이 비디오를 대여중이므로 전체 삭제를 할 수 없습니다.\n\n", guest[i].name);
               return;
               // 만약 전체 삭제를 하더라도 한명이라도 비디오를 대여하고 있다면 삭제가 되면 안되기 때문에 전체 삭제를 할 수 없도록 함. 예외 처리 과정.
            }
         }
         printf("정말 삭제하시겠습니까?(1을 누르면 삭제 1이외의 다른 숫자, 문자 입력시 삭제안함) ");
         scanf("%[^\n]", really);
         if (really[0] == '1') {
            Nummember = 0;
            printf("회원 정보가 전체 삭제되었습니다.\n\n");
            return;
            // 1을 입력하면 전체삭제가 되고 그 외의 문자를 입력하면 메뉴로 넘어감
         }
         else {
            printf("전체삭제를 하지 않았습니다.\n\n");
            return;
            // 1을 입력하지 않았다면 전체삭제를 하지 않고 메뉴로 넘어감.
         }
      case '2':
         memberprint(); // 선택 삭제를 하기 전에 삭제할 회원 정보의 id를 알고 있어야 하므로 미리 회원 정보를 출력함.
         printf("삭제할 회원 정보의 id를 입력하세요: ");
         scanf("%[^\n]", deleteid);
         getchar();
         int found = -1; //  found는 인덱스를 표현하기 위해서 사용한 변수.
         for (int i = 0; i < Nummember; i++) {
            if (strcmp(guest[i].id, deleteid) == 0) {
               found = i;
               break;
               // 만약 내가 입력한 id가 존재한다면 found를 i로 만듬.
            }
         }
         if (found == -1) { // found가 -1이라면 입력한 아이디가 존재하지 않는 것. 예외 처리 과정.
            printf("입력한 id가 존재하지 않습니다.\n\n");
            return;
         }
         if (guest[found].rentcount > 0) { // 만약 입력한 고유번호의 rentcount가 0 이상이라면 현재 대여중이기 때문에 삭제를 못하게 함. 예외 처리 과정.
            printf("입력한 고유번호는 대여중이므로 삭제할 수 없습니다.\n\n");
            return;
         }
         printf("id: % s\n", guest[found].id);
         printf("이름: %s\n", guest[found].name);
         printf("전화번호: %s\n", guest[found].number);
         printf("성별: %s\n\n", guest[found].gender);
         printf("정말 삭제하시겠습니까?(1: 삭제 1이외의 다른 문자열: 삭제 안함): ");
         scanf("%[^\n]", really);
         getchar();
         // 삭제할 정보를 출력하고 정말 삭제를 할것인지를 입력 받음.
         if (really[0] == '1') {
            for (int i = found; i < Nummember; i++) {
               guest[i] = guest[i + 1];
            }
            //really 배열에서 제일 앞에 있는것이 문자열 1이면 해당 인덱스를 삭제하고 배열이 비기 때문에 뒤에 있는 배열을 앞으로 채움
            printf("삭제 완료.\n\n");
            Nummember--;
            return;
         }
         else {
            printf("해당 회원 정보를 삭제하지 않았습니다.\n\n");
            return;
         }
      default:
         printf("다시 입력하세요.\n");
         return;
      }
   }
}

void videodelete() { // 회원 삭제와 같은 원리로 코드를 작성함.
   if (firstvideomanager == 0) {
      printf("현재 관리자 모드가 아니기 때문에 삭제를 할 수 없습니다.\n\n");
      return;
   }
   char deletenumber[100];
   char choice[100];
   char really[100];
   while (1) {
      printf("1. 비디오 전체 삭제\n");
      printf("2. 비디오 선택 삭제\n");
      printf("번호를 입력하세요: ");
      scanf("%[^\n]", choice);
      getchar();
      if (Numvideo == 0) {
         printf("비디오가 존재하지 않습니다.\n");
         return;
      }

      switch (choice[0]) {
      case '1':
         for (int i = 0; i < Numvideo; i++) {
            if (vod[i].rental == 0) {
               printf("%s제목의 비디오가 현재 대여중이므로 삭제할 수 없습니다.\n\n", vod[i].name);
               return;
            }
         }
         printf("정말 삭제하시겠습니까?(1을 누르면 삭제 1이외의 다른 숫자, 문자 입력시 삭제안함) ");
         scanf("%[^\n]", really);
         if (really[0] == '1') {
            Numvideo = 0;
            printf("비디오가 전체삭제되었습니다.\n\n");
            return;
            // 1을 입력하면 전체삭제가 되고 그 외의 문자를 입력하면 메뉴로 넘어감
         }
         else {
            printf("전체삭제를 하지 않았습니다.\n\n");
            return;
         }
      case '2':
         if (Numvideo > 0) {
            for (int i = 0; i < Numvideo; i++) {
               printf("인덱스 번호: %d\n", i);
               printf("고유번호: %s\n", vod[i].videonumber);
               printf("제목: %s\n", vod[i].name);
               printf("장르: %s\n", vod[i].genre);
               printf("감독: %s\n", vod[i].director);
               printf("대여한 회원 id: %s\n", vod[i].rentmemberid);
               printf("대여여부(1: 대여 가능, 0: 대여 중): %d\n\n", vod[i].rental);
            }
         }
         else {
            printf("비디오가 존재하지 않습니다.\n\n");
         }
         printf("삭제할 비디오의 고유번호를 입력하세요: ");
         scanf("%[^\n]", deletenumber);
         getchar();
         int found = -1;
         for (int i = 0; i < Numvideo; i++) {
            if (strcmp(vod[i].videonumber, deletenumber) == 0) {
               found = i;
               break;
            }
         }
         if (vod[found].rental == 0) {
            printf("해당 비디오는 대여중이므로 삭제할 수 없습니다.\n\n");
            return;
         }
         if (found == -1) {
            printf("입력한 고유 번호가 존재하지 않습니다.\n\n");
            return;
         }
         printf("고유번호: %s\n", vod[found].videonumber);
         printf("제목: %s\n", vod[found].name);
         printf("장르: %s\n", vod[found].genre);
         printf("감독: %s\n", vod[found].director);
         printf("대여여부(1: 대여 가능, 0: 대여 중): %d\n\n", vod[found].rental);
         printf("정말 삭제하시겠습니까?(1: 삭제 1이외의 다른 문자열: 삭제 안함): ");
         scanf("%[^\n]", really);
         getchar();
         if (really[0] == '1') {
            for (int i = found; i < Numvideo; i++) {
               vod[i] = vod[i + 1];
            }
            //really 배열에서 제일 앞에 있는것이 문자열 1이면 해당 인덱스를 삭제하고 배열이 비기 때문에 뒤에 있는 배열을 앞으로 채움
            printf("삭제완료.\n\n");
            Numvideo--;
            return;
         }
         else {
            printf("해당 비디오를 삭제하지않았습니다.\n\n");
            return;
         }
      default:
         printf("다시 입력하세요.\n");
         return;
      }
   }
}

void videoedit() { // 비디오 수정하는 함수
   if (firstvideomanager == 0) { // firstvideomanager는 현재 비디오의 개수가 0일 때는 관리자 모드를 설정할 수 없기 때문에 변수를 설정해서 관리자 모드를 실행하면 1, 아니면 0으로 하게 함.
      printf("현재 관리자 모드가 아니기 때문에 수정을 할 수 없습니다.\n\n");
      return;
   }
   char videonumber[100]; // videonumber라는 변수를 100byte배열로 설정한 이유는 입력한 고유번호가 들어가는 변수인데 어떤 숫자와 문자가 들어갈지 모르기 때문
   int index = -1; // index라는 변수를 설정한 이유는 밑에서 존재하는지 확인할 때 index = i를 하기 위함.
   while (1) {
      for (int i = 0; i < Numvideo; i++) {
         printf("고유번호: %s\n", vod[i].videonumber);
         printf("이름: %s\n", vod[i].name);
         printf("장르: %s\n", vod[i].genre);
         printf("감독: %s\n", vod[i].director);
         printf("대여한 회원 id: %s\n", vod[i].rentmemberid);
         printf("대여 여부(1: 대여 가능, 0: 대여중): %d\n\n", vod[i].rental);
      }
      if (Numvideo == 0) {
         printf("비디오 정보가 존재하지 않습니다.\n");
         return;
      }
      // 먼저 비디오를 수정하기 전에 현재 가지고 있는 비디오의 정보를 출력하여 고유번호를 입력 받을 수 있도록 함.
      printf("수정할 비디오의 고유번호를 입력하세요: ");
      scanf("%s", videonumber);
      getchar();
      for (int i = 0; i < Numvideo; i++) {
         if (strcmp(vod[i].videonumber, videonumber) == 0) {
            index = i;
            break;
            // 만약 비디오 정보안에 내가 입력한 비디오의 고유번호가 존재한다면 index = i로 바꿈.
         }
      }
      if (index == -1) {
         printf("입력한 고유번호의 비디오가 존재하지 않습니다.\n\n");
         return;
      }

      if (vod[index].rental == 1) {
         char editvideo[100]; // 번호를 입력받을 때 들어가는 변수
         char editgenre[100]; // 비디오 장르를 수정할 때 사용하는 변수
         char editdirector[100]; // 비디오 감독을 수정할 때 사용하는 변수
         printf("고유번호: %s\n", vod[index].videonumber);
         printf("이름: %s\n", vod[index].name);
         printf("장르: %s\n", vod[index].genre);
         printf("감독: %s\n", vod[index].director);
         printf("1. 비디오 제목 수정\n");
         printf("2. 비디오 장르 수정\n");
         printf("3. 비디오 감독 수정\n");
         printf("4. 전체 수정\n");
         printf("번호를 입력하세요: ");
         scanf("%s", editvideo);
         getchar();

         char editname[100];
         switch (editvideo[0]) { // editvideo[0]으로 한 이유는 배열에서 제일 앞에 있는 것을 따오기 위함.
         case '1':
            printf("수정할 비디오 제목을 입력하세요: ");
            scanf("%s", editname);
            getchar();
            if (strlen(editname) > 61) {
               printf("입력한 비디오의 제목이 너무 깁니다. 다시 입력하세요.\n");
               fflush(stdin);
               return;
               // 만약 지정한 크기보다 제목을 길게 한다면 메인메뉴로 돌아가게 됌.
            }
            if (strcmp(vod[index].name, editname) == 0) {
               printf("수정할 비디오의 제목은 같을 수 없습니다. 다시 입력하세요.\n");
               fflush(stdin);
               return;
               // 수정할 비디오의 제목을 같지 않게 한 이유는 수정이기 때문에 같은 것은 있을 수 없다고 생각했기 때문.
            }
            strcpy(vod[index].name, editname); // 위에서 수정을 안했을 때 그 값이 그대로 수정이 되어버리기 때문에 변수를 하나 만들어서 성공적으로 수정이 되었다면 복사해서 수정을 함.
            printf("수정완료.\n\n");
            printf("고유번호: %s\n", vod[index].videonumber);
            printf("이름: %s\n", vod[index].name);
            printf("장르: %s\n", vod[index].genre);
            printf("감독: %s\n", vod[index].director);
            printf("대여한 회원 id: %s\n", vod[index].rentmemberid);
            printf("대여 여부(1: 대여 가능, 0: 대여중): %d\n\n", vod[index].rental);
            return;
         case '2':
            printf("수정할 비디오 장르를 입력하세요: "); // 위와 같은 개념으로 작성된 코드
            scanf("%s", editgenre);
            getchar();
            if (strlen(editgenre) > 20) {
               printf("입력한 비디오의 장르가 너무 깁니다. 다시 입력하세요\n");
               fflush(stdin);
               return;
            }
            if (strcmp(vod[index].genre, editgenre) == 0) {
               printf("수정할 비디오의 장르는 같을 수 없습니다. 다시 입력하세요.\n");
               fflush(stdin);
               return;
            }
            strcpy(vod[index].genre, editgenre);
            printf("수정완료.\n\n");
            printf("고유번호: %s\n", vod[index].videonumber);
            printf("이름: %s\n", vod[index].name);
            printf("장르: %s\n", vod[index].genre);
            printf("감독: %s\n", vod[index].director);
            printf("대여한 회원 id: %s\n", vod[index].rentmemberid);
            printf("대여 여부(1: 대여 가능, 0: 대여중): %d\n\n", vod[index].rental);
            return;
         case '3':
            printf("수정할 비디오 감독을 입력하세요: "); // 위와 같은 개념으로 작성된 코드
            scanf("%s", editdirector);
            getchar();
            if (strlen(editdirector) > 12) {
               printf("입력한 비디오의 감독이 너무 깁니다. 다시 입력하세요.\n");
               fflush(stdin);
               return;
            }
            if (strcmp(vod[index].director, editdirector) == 0) {
               printf("수정할 비디오의 감독은 같을 수 없습니다. 다시 입력하세요.\n");
               fflush(stdin);
               return;
            }
            strcpy(vod[index].director, editdirector);
            printf("수정완료.\n\n");
            printf("고유번호: %s\n", vod[index].videonumber);
            printf("이름: %s\n", vod[index].name);
            printf("장르: %s\n", vod[index].genre);
            printf("감독: %s\n", vod[index].director);
            printf("대여한 회원 id: %s\n", vod[index].rentmemberid);
            printf("대여 여부(1: 대여 가능, 0: 대여중): %d\n\n", vod[index].rental);
            return;
         case '4':
            printf("수정할 비디오 제목을 입력하세요: ");
            scanf("%s", editname);
            getchar();
            if (strlen(editname) > 61) {
               printf("입력한 비디오의 제목이 너무 깁니다. 다시 입력하세요.\n");
               fflush(stdin);
               return;
               // 만약 지정한 크기보다 제목을 길게 한다면 메인메뉴로 돌아가게 됌.
            }
            if (strcmp(vod[index].name, editname) == 0) {
               printf("수정할 비디오의 제목은 같을 수 없습니다. 다시 입력하세요.\n");
               fflush(stdin);
               return;
               // 수정할 비디오의 제목을 같지 않게 한 이유는 수정이기 때문에 같은 것은 있을 수 없다고 생각했기 때문.
            }
            strcpy(vod[index].name, editname); // 위에서 수정을 안했을 때 그 값이 그대로 수정이 되어버리기 때문에 변수를 하나 만들어서 성공적으로 수정이 되었다면 복사해서 수정을 함.
            printf("수정완료.\n\n");

            printf("수정할 비디오 장르를 입력하세요: "); // 위와 같은 개념으로 작성된 코드
            scanf("%s", editgenre);
            getchar();
            if (strlen(editgenre) > 20) {
               printf("입력한 비디오의 장르가 너무 깁니다. 다시 입력하세요\n");
               fflush(stdin);
               return;
            }
            if (strcmp(vod[index].genre, editgenre) == 0) {
               printf("수정할 비디오의 장르는 같을 수 없습니다. 다시 입력하세요.\n");
               fflush(stdin);
               return;
            }
            strcpy(vod[index].genre, editgenre);
            printf("수정완료.\n\n");
            printf("고유번호: %s\n", vod[index].videonumber);

            printf("수정할 비디오 감독을 입력하세요: "); // 위와 같은 개념으로 작성된 코드
            scanf("%s", editdirector);
            getchar();
            if (strlen(editdirector) > 12) {
               printf("입력한 비디오의 감독이 너무 깁니다. 다시 입력하세요.\n");
               fflush(stdin);
               return;
            }
            if (strcmp(vod[index].director, editdirector) == 0) {
               printf("수정할 비디오의 감독은 같을 수 없습니다. 다시 입력하세요.\n");
               fflush(stdin);
               return;
            }
            strcpy(vod[index].director, editdirector);
            printf("수정완료.\n\n");
            printf("고유번호: %s\n", vod[index].videonumber);
            printf("이름: %s\n", vod[index].name);
            printf("장르: %s\n", vod[index].genre);
            printf("감독: %s\n", vod[index].director);
            printf("대여한 회원 id: %s\n", vod[index].rentmemberid);
            printf("대여 여부(1: 대여 가능, 0: 대여중): %d\n\n", vod[index].rental);
            return;
         default:
            printf("다시 입력하세요.\n");
            return;
         }
      }
      else {
         printf("해당 비디오는 현재 대여중이므로 수정할 수 없습니다.\n\n");
         return;
      }
      break;
   }
}


void memberedit() { // 위에서 짠 비디오 수정 함수와 같은 개념을 사용하여 코드를 짬.
   if (firstvideomanager == 0) {
      printf("현재 관리자 모드가 아니기 때문에 수정을 할 수 없습니다.\n\n");
      return;
   }
   char memberid[100];
   int index = -1;
   while (1) {
      memberprint();
      printf("수정할 회원정보의 고유번호를 입력하세요: ");
      scanf("%s", memberid);
      getchar();
      for (int i = 0; i < Nummember; i++) {
         if (strcmp(guest[i].id, memberid) == 0) {
            index = i;
            break;
         }
      }
      if (index == -1) {
         printf("입력한 고유번호의 회원이 존재하지 않습니다.\n\n");
         return;
      }

      if (guest[index].rentcount == 0) {
         printf("id: % s\n", guest[index].id);
         printf("이름: %s\n", guest[index].name);
         printf("전화번호: %s\n", guest[index].number);
         printf("성별: %s\n\n", guest[index].gender);
         char editmember[100];
         printf("1. 회원 이름 수정\n");
         printf("2. 회원 전화번호 수정\n");
         printf("3. 회원 성별 수정\n");
         printf("4. 전체 수정\n");
         printf("번호를 입력하세요: ");
         scanf("%s", editmember);
         getchar();

         char editname[100];
         char editnumber[100];
         char editgender[100];
         int duplicate = 0;
         char samename[100];

         switch (editmember[0])
         {
         case '1':
            printf("수정할 회원 이름을 입력하세요: ");
            scanf("%s", editname);
            getchar();
            for (int i = 0; i < Nummember; i++) {
               if (strcmp(guest[i].name, editname) == 0) {
                  duplicate = 1;
                  break;
               }
            }
            if (duplicate == 1) {
               printf("같은 이름을 가진 다른 사람이 있습니다.\n");
               printf("같은 이름의 다른 사람으로 수정하시겠습니까?(1:예 1이외의 문자열:아니오): ");
               scanf("%s", samename);
               getchar();
               if (samename[0] == '1') {
                  printf("같은 이름의 다른 사람으로 수정하겠습니다.\n");
               }
               else {
                  printf("수정하지 않았습니다.\n\n");
                  return;
               }
            }
            else {
               printf("해당 이름으로 수정하겠습니다.\n");
            }
            if (strlen(editname) > 12) {
               printf("입력한 이름의 길이가 너무 깁니다. 다시 입력하세요.\n");
               fflush(stdin);
               return;
            }
            if (strcmp(guest[index].name, editname) == 0) {
               printf("수정할 이름은 같을 수 없습니다. 다시 입력하세요.\n");
               fflush(stdin);
               return;
            }
            strcpy(guest[index].name, editname);
            printf("수정 완료.\n");
            printf("id: %s\n", guest[index].id);
            printf("이름: %s\n", guest[index].name);
            printf("전화번호: %s\n", guest[index].number);
            printf("성별: %s\n", guest[index].gender);
            printf("대여한 비디오 개수: %d\n\n", guest[index].rentcount);
            break;
         case '2':
            printf("수정할 전화번호를 입력하세요: ");
            scanf("%s", editnumber);
            getchar();
            if (strlen(editnumber) > 14) {
               printf("입력한 전화번호가 너무 깁니다. 다시 입력하세요.\n");
               fflush(stdin);
               return;
            }
            for (int i = 0; i < Nummember; i++) {
               if (strcmp(guest[i].number, editnumber) == 0) {
                  printf("수정할 전화번호는 같을 수 없습니다. 다시 입력하세요.\n");
                  fflush(stdin);
                  return;
               }
            }
            strcpy(guest[index].number, editnumber);
            printf("수정 완료.\n");
            printf("id: %s\n", guest[index].id);
            printf("이름: %s\n", guest[index].name);
            printf("전화번호: %s\n", guest[index].number);
            printf("성별: %s\n", guest[index].gender);
            printf("대여한 비디오 개수: %d\n\n", guest[index].rentcount);
            break;
         case '3':
            printf("수정할 성별을 입력하세요: ");
            scanf("%s", editgender);
            getchar();
            if (strlen(editgender) > 3) {
               printf("입력한 성별이 너무 깁니다. 다시 입력하세요.\n");
               fflush(stdin);
               return;
            }
            for (int i = 0; i < Nummember; i++) {
               if (strcmp(guest[i].gender, editgender) == 0) {
                  printf("수정할 성별은 같을 수 없습니다. 다시 입력하세요.\n");
                  fflush(stdin);
                  return;
               }
            }
            strcpy(guest[index].gender, editgender);
            printf("수정 완료.\n");
            printf("id: %s\n", guest[index].id);
            printf("이름: %s\n", guest[index].name);
            printf("전화번호: %s\n", guest[index].number);
            printf("성별: %s\n", guest[index].gender);
            printf("대여한 비디오 개수: %d\n\n", guest[index].rentcount);
            break;
         case '4':
            printf("수정할 회원 이름을 입력하세요: ");
            scanf("%s", editname);
            getchar();
            for (int i = 0; i < Nummember; i++) {
               if (strcmp(guest[i].name, editname) == 0) {
                  duplicate = 1;
                  break;
               }
            }
            if (duplicate == 1) {
               printf("같은 이름을 가진 다른 사람이 있습니다.\n");
               printf("같은 이름의 다른 사람으로 수정하시겠습니까?(1:예 1이외의 문자열:아니오): ");
               scanf("%s", samename);
               getchar();
               if (samename[0] == '1') {
                  printf("같은 이름의 다른 사람으로 수정하겠습니다.\n");
               }
               else {
                  printf("수정하지 않았습니다.\n\n");
                  return;
               }
            }
            else {
               printf("해당 이름으로 수정하겠습니다.\n");
            }
            if (strlen(editname) > 12) {
               printf("입력한 이름의 길이가 너무 깁니다. 다시 입력하세요.\n");
               fflush(stdin);
               return;
            }
            if (strcmp(guest[index].name, editname) == 0) {
               printf("수정할 이름은 같을 수 없습니다. 다시 입력하세요.\n");
               fflush(stdin);
               return;
            }
            strcpy(guest[index].name, editname);
            printf("수정 완료.\n");

            printf("수정할 전화번호를 입력하세요: ");
            scanf("%s", editnumber);
            getchar();
            if (strlen(editnumber) > 14) {
               printf("입력한 전화번호가 너무 깁니다. 다시 입력하세요.\n");
               fflush(stdin);
               return;
            }
            for (int i = 0; i < Nummember; i++) {
               if (strcmp(guest[i].number, editnumber) == 0) {
                  printf("수정할 전화번호는 같을 수 없습니다. 다시 입력하세요.\n");
                  fflush(stdin);
                  return;
               }
            }
            strcpy(guest[index].number, editnumber);
            printf("수정 완료.\n");

            printf("수정할 성별을 입력하세요: ");
            scanf("%s", editgender);
            getchar();
            if (strlen(editgender) > 3) {
               printf("입력한 성별이 너무 깁니다. 다시 입력하세요.\n");
               fflush(stdin);
               return;
            }
            for (int i = 0; i < Nummember; i++) {
               if (strcmp(guest[i].gender, editgender) == 0) {
                  printf("수정할 성별은 같을 수 없습니다. 다시 입력하세요.\n");
                  fflush(stdin);
                  return;
               }
            }
            strcpy(guest[index].gender, editgender);
            printf("수정 완료.\n");
            printf("id: %s\n", guest[index].id);
            printf("이름: %s\n", guest[index].name);
            printf("전화번호: %s\n", guest[index].number);
            printf("성별: %s\n", guest[index].gender);
            printf("대여한 비디오 개수: %d\n\n", guest[index].rentcount);
            break;
         default:
            printf("다시 입력하세요.\n");
            return;
         }
      }
      else {
         printf("해당 회원은 현재 대여중인 비디오가 있어 수정할 수 없습니다.\n\n");
         return;
      }
      break;
   }
}