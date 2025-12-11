#define _CRT_SECURE_NO_WARNINGS
#include "numberbook.h"

void add()      // 번호 추가하는 함수
{
   if (n >= size) {
      size = size * 2;
      // size는 위에서 전역변수로써 연락처 크기를 의미하며 1로 지정해 두었음 처음 1번은 size가 1이기 때문에 연락처의 크기가 1이며
      // 먼저 하나의 연락처를 저장한다. 그 이후 2를 곱해가면서 연락처의 크기가 최대가 될때마다 추가할 수 있는 인원의 개수를 늘린다.
      address* maxtelephone = (address*)realloc(telephone, size * sizeof(address));
      // realloc함수는 할당한 메모리의 블록의 크기를 변경하는 함수로써 위에서 지정한 telephone의 크기를 
      // 계속 전화번호부를 저장할 때마다 크기가 다했을때 동적 메모리의 크기를 변경할 수 있게 해준다.
      if (maxtelephone == NULL) {
         printf("메모리 할당을 못했습니다\n");
         return;
      }
      // 만약 maxtelephone이 NULL이면 메모리 할당을 못하게 된것이므로 if문을 사용해서 메모리 할당에서 발생할 수 있는 예외를 처리한 것이다.
      telephone = maxtelephone;
      // 내가 위에서 maxtelephone에 telephone의 동적 메모리의 크기가 최대에 다했을 때 크기를 변경하였기 때문에 이 식을 붙여서 maxtelephone의 값을
      // telephone에 넣는다.
   }
   int i = 0;
   int repetition = 1;
   // while문안에 들어갈 repetition이라는 변수를 정수형으로 입력을 받은것
   // int형으로 받은 이유는 while문을 사용할 때 repetition의 숫자를 바꾸면서 진행을 할 것이기 때문에 int형으로 선언하였음
   char samename[100];
   // samename이라는 문자 배열을 만들었는데 크기를 100byte로 한 이유는 밑에서 동명이인을 처리하는 과정에서 samename이 사용되는데
   // 내가 입력을 받을 때 얼마나 입력을 할지 모르기 때문에 100byte로 지정하였음
   int duplicate = 0;
   // while문 안에서 사용할 동명이인을 처리하는 과정에서 동명이인이 발견되면 1로 바뀌게 해놓기 위해서 변수를 지정함
   while (repetition) { // repetition은 현재 1이기 때문에 무한루프를 돌아감
      printf("이름을 입력하세요: ");
      scanf("%s", telephone[n].name);
      repetition = 0; // 이름을 입력 받은 후에는 반복을 하게 하는 변수인  repetition을 0으로 만들어서 루프를 끝낸다.
      duplicate = 0; // 새로운 이름을 입력받을 때마다 동명이인을 확인하는 것을 0으로 바꿔야 새로운 연락처로 들어갈 수 있음
      // scanf를 telephone[n].name으로 받은 이유는 연락처의 개수가 n이기 때문에 만약 현재 연락처가 5개 있다면
      // 5번째 인덱스의 이름에 입력을 받게 하였음
      for (i = 0; i < n; i++) {
         if (strcmp(telephone[n].name, telephone[i].name) == 0) {
            // for문을 i=0부터 n까지 돌리면서 내가 지금 입력한 이름과 0번째 인덱스 부터 n번째 인덱스 까지의 이름중에
            // 내가 아까 입력한 이름과 같은것이 있는지 strcmp함수를 이용해서 찾는 과정을 표현함
            duplicate = 1; // 만약 찾았다면 위에서 설정해놓은 duplicate를 1로 지정함.
         }
      }
      if (duplicate) {
         // 위에서 만약 동명이인을 찾아서 duplicate가 1이 된다면 이 if문은 참이므로 진행이 된다.
         printf("같은 이름의 연락처가 이미 있습니다.\n");
         printf("같은 이름을 가진 다른 사람인가요?(다른사람이면 1, 같은사람이면 1이외의 다른 문자열) ");
         scanf("%s", samename);
         getchar();
         // 같은 이름의 연락처가 이미 있다고 출력을 하게 한후 같은 이름을 가진 다른 사람이면 1 아니면 다른 문자열을 입력받은 후에
         // getchar();로 남은 버퍼를 지움
         if (samename[0] == '1') {
            printf("같은 이름의 다른 사람으로 추가하겠습니다.\n");
            // 위에서 설정한 samename의 배열중에 0번째 즉 제일 앞에 있는 문자가 '1'과 같다면 같은 이름의 다른 사람으로 추가를 하게 함
         }
         else {
            printf("연락처 추가를 하지않았습니다.\n\n");
            strcpy(telephone[n].age, "0");
            strcpy(telephone[n].number, "0");
            strcpy(telephone[n].gender, "0");
            strcpy(telephone[n].name, "힣힣힣힣힣"); // 내 구조체 배열에서 가장 크게 할 수 있는 이름
            return;
            //여기에서 strcpy함수를 이용해서 이름에 힣힣힣힣힣, 나이에 0, 전화번호에 0, 성별에 0을 넣은 이유는
            // 지금 이제 출력이되는데 오름차순 정렬이 되고있고 추가함수의 마지막 부분에서 n++을 해주기 때문에 
            // n은 늘어나지 않은 상태에서 return으로 함수가 끝났으므로 오름차순 기준 마지막 글자인 힣을 
            // 내 구조체 배열에서 크기를 가장 크게 할 수 있는 이름으로 복사를 해서 마지막에 넣어놓고 쓰레기 값을 없애기 위해서
            // '1'이외의 다른 문자가 들어온다면 연락처 추가를 하지 않았다고 출력을 한후 함수를 종료한다.
         }
   }

      if (strlen(telephone[n].name) > 8) {
         printf("입력한 이름이 너무 깁니다. 다시 입력하세요.\n");
         repetition = 1;
         fflush(stdin);
         // 맨 위에서 전역변수로 구조체 배열을 만들면서 이름의 크기를 12로 지정을 했는데 내가 입력한 이름이 12byte보다 크다면
         // 입력한 이름이 너무 깁니다. 다시 입력하세요. 를 출력하게 한후 repetiton을 다시 1로 만들어서 무한루프를 만들어준다.
         // fflush(stdin);을 이용해서 입력 버퍼를 지운다.
      }
   }
   printf("제대로 입력되었습니다.\n\n");

   repetition = 1; // repetition = 1 로 만들어서 while문을 항상 참으로 돌아가게 한다
   while (repetition) {
      printf("나이를 입력하세요: ");
      scanf("%s", telephone[n].age);
      repetition = 0; 
      // 여기서 다시 0으로 바꾼후에 만약 내가 입력한 나이가 너무 길다면 다시 while문을 반복해야 하기 때문에 if문 안에서 다시 1로 변경
      if (strlen(telephone[n].age) > 3) {
         printf("입력한 나이가 너무 깁니다. 다시 입력하세요.\n");
         repetition = 1;
         fflush(stdin); // 입력 버퍼를 지움
      }
   }
   printf("제대로 입력되었습니다.\n\n");
   // 위와 같은 기준으로 작성한 코드
   repetition = 1;
   while (repetition) {
      printf("전화번호를 입력하세요(ex:010-8888-8888): ");
      scanf("%s", telephone[n].number);
      repetition = 0;
      for (i = 0; i < n; i++) {
         if (strcmp(telephone[n].number, telephone[i].number) == 0) {
            printf("전화번호는 같을 수 없습니다. 다시 입력하세요.\n");
            repetition = 1;
            break;
            // 전화번호는 절대 같을 수가 없기 때문에 strcmp함수를 이용해서 0부터 n까지의 연락처 중에서 내가 입력한 전화번호와
            // 같은 것이 있다면 다시 1로 바꿔서 while문을 항상 참으로 만든다.
         }
      }
      if (strlen(telephone[n].number) > 13) {
         printf("입력한 전화번호가 너무 깁니다. 다시 입력하세요.\n");
         repetition = 1;
         fflush(stdin); 
      } // 만약 전화번호가 너무 길다면 다시 입력을 받게 함
   }
   printf("제대로 입력되었습니다.\n\n");
   
   // 위와 똑같은 개념으로 작성된 코드
   repetition = 1;
   while (repetition) {
      printf("성별을 입력하세요(남/여): ");
      scanf("%s", telephone[n].gender);
      repetition = 0;
      if (strlen(telephone[n].gender) > 3) {
         printf("입력한 성별이 너무 깁니다. 다시 입력하세요.\n");
         repetition = 1;
         fflush(stdin);
      }
   }
   printf("제대로 입력되었습니다.\n\n");
   n++; // 이름, 나이, 전화번호, 성별을 다 입력받은후 연락처의 개수를 늘림 그래서 위에서 힣 작업을 한것.
   printf("전화번호 생성 완료\n\n");
   save(); 
   // 이름, 나이, 전화번호, 성별을 입력받고 연락처 개수를 늘린뒤에 전화번호 생성 완료 라는 문구와 함께 그 전화번호부를 지정한 파일에 저장하는
   // save함수를 호출하여 파일에 저장할 수 있게 한다
}

void edit() {
   int repetition = 1;
   int duplicate = 0;
   char samename[100]; 
   // samename이라는 배열은 동명이인을 확인할 때 사용할 배열인데 배열의 크기를 100으로 해놓은 이유는 
   // 내가 입력을 할 때 얼마나 입력을 할지 모르기 때문에 100으로 지정함
   int index;
   while (1) {
      print(); 
      // print함수를 먼저 호출하는 이유는 바로 밑에서 수정할 전화번호부의 인덱스 번호를 입력받을건데
      // 연락처의 모든 인덱스를 알고있는 것이 아니기 때문
      printf("수정할 전화번호부의 인덱스 번호를 입력하세요(숫자만 입력가능): ");
      scanf("%d", &index);
      // 문자열도 입력받을 수 있게 하려고 했으나 오류 수정 불가.
      getchar();
      if (index < 0) {
         printf("다시입력하세요.\n");
      }
      else if (index > n) {
         printf("다시입력하세요.\n");
      }
      else if (n == 0) {
         printf("전화번호부가 존재하지 않습니다.\n\n");
         break;
      }
      else {
         break;
      }
   }
   printf("인덱스 번호: %d\n", index);
   printf("이름: %s\n", telephone[index].name);
   printf("나이: %s\n", telephone[index].age);
   printf("전화번호: %s\n", telephone[index].number);
   printf("성별: %s\n\n", telephone[index].gender); //수정할 전화번호부 출력
   while (n != 0)
   {
      char select[100]; // select도 위와 마찬가지로 내가 번호를 입력하는 것이 문자나 문자열로 얼마나 받을 지 모르기에 100으로 지정
      printf("1. 이름 수정\n");
      printf("2. 나이 수정\n");
      printf("3. 전화번호 수정\n");
      printf("4. 성별 수정\n");
      printf("5. 전체 수정\n");
      printf("6. 종료\n");
      printf("번호를 입력하세요: ");
      scanf("%s", select);
      getchar();

      switch (select[0]) { // select[0]으로 한 이유는 만약 내가 입력을 287294u4로 했다고 가정을 하자 그러면 오직 앞에 있는 2만 받기 위해서
      case '1':
         repetition = 1;
         while (repetition) {
            char backup[100];
            strcpy(backup, telephone[index].name);
            printf("수정할 이름을 입력하세요: ");
            scanf("%s", telephone[index].name);
            getchar();
            repetition = 0;
            duplicate = 0;
            for (int i = 0; i < n; i++) {
               if (i != index && strcmp(telephone[index].name, telephone[i].name) == 0) {
                  duplicate = 1;
               }
            }
            if (duplicate) {
               printf("같은 이름의 연락처가 이미 있습니다.\n");
               printf("같은 이름의 다른 연락처로 수정하시겠습니까?(다른사람이면 1 같은사람이면 1이외의 다른 문자열) ");
               scanf("%s", samename);
               getchar();
               if (samename[0] == '1') {
                  printf("같은 이름의 다른 연락처로 수정하겠습니다.\n");
               }
               else {
                  printf("연락처 수정을 하지 않았습니다.\n\n");
                  strcpy(telephone[index].name, backup);
                  return;
               }
            }
            if (strlen(telephone[index].name) > 8) {
               printf("입력한 이름이 너무 깁니다. 다시 입력하세요.\n");
               repetition = 1;
               fflush(stdin);
            }
         }
         // 연락처 추가에서 했던 개념을 똑같이 사용하여 수정을 한것
         printf("수정완료\n\n");
         printf("인덱스 번호: %d\n", index);
         printf("이름: %s\n", telephone[index].name);
         printf("나이: %s\n", telephone[index].age);
         printf("전화번호: %s\n", telephone[index].number);
         printf("성별: %s\n\n", telephone[index].gender);
         break;
      case '2':
         repetition = 1;
         while (repetition) {
            printf("수정할 나이를 입력하세요: ");
            scanf("%s", telephone[index].age);
            repetition = 0;
            if (strlen(telephone[index].age) > 3) {
               printf("입력한 나이가 너무 깁니다. 다시 입력하세요.\n");
               repetition = 1;
               fflush(stdin);
            }
         }
         // 이것도 마찬가지로 위에서 나이 추가할 때 사용한 개념 그대로 사용
         printf("수정완료\n\n");
         printf("인덱스 번호: %d\n", index);
         printf("이름: %s\n", telephone[index].name);
         printf("나이: %s\n", telephone[index].age);
         printf("전화번호: %s\n", telephone[index].number);
         printf("성별: %s\n\n", telephone[index].gender);
         break;
      case '3':
         repetition = 1;
         while (repetition) {
            printf("수정할 전화번호를 입력하세요(ex:010-8888-8888): ");
            scanf("%s", telephone[index].number);
            repetition = 0;
            for (int i = 0; i < n; i++) {
               if (i != index && strcmp(telephone[index].number, telephone[i].number) == 0) {
                  printf("전화번호는 같을 수 없습니다. 다시 입력하세요.\n");
                  repetition = 1;
                  break;
               }
            }
            if (strlen(telephone[index].number) > 14) {
               printf("입력한 전화번호가 너무 깁니다. 다시 입력하세요.\n");
               repetition = 1;
               fflush(stdin);
            }
         }
         // 전화번호도 마찬가지 위의 개념 그대로
         printf("수정완료\n\n");
         printf("인덱스 번호: %d\n", index);
         printf("이름: %s\n", telephone[index].name);
         printf("나이: %s\n", telephone[index].age);
         printf("전화번호: %s\n", telephone[index].number);
         printf("성별: %s\n\n", telephone[index].gender);
         break;
      case '4':
         repetition = 1;
         while (repetition) {
            printf("수정할 성별을 입력하세요: ");
            scanf("%s", telephone[index].gender);
            repetition = 0;
            if (strlen(telephone[index].gender) > 3) {
               printf("입력한 성별이 너무 깁니다. 다시 입력하세요.\n");
               repetition = 1;
               fflush(stdin);
            }
         }
         // 성별도 위의 개념을 그대로 사용하였습니다.
         printf("수정완료\n\n");
         printf("인덱스 번호: %d\n", index);
         printf("이름: %s\n", telephone[index].name);
         printf("나이: %s\n", telephone[index].age);
         printf("전화번호: %s\n", telephone[index].number);
         printf("성별: %s\n\n", telephone[index].gender);
         break;
      case '5':
         repetition = 1;
         while (repetition) {
            char backup[100]; 
            // 여기에서 backup이라는 배열을 100byte만큼의 크기로 만든 이유는 밑에 사용했을 때 다시 설명하겠음.
            strcpy(backup, telephone[index].name); // 일단 위에서 backup이라고 만든 배열에 입력받은 인덱스의 이름을 복사해서 넣어둠
            printf("수정할 이름을 입력하세요: ");
            scanf("%s", telephone[index].name);
            getchar();
            repetition = 0;
            duplicate = 0;
            if (strlen(telephone[index].name) > 8) {
               printf("입력한 이름이 너무 깁니다. 다시 입력하세요.\n"); // 이름 길이 최대치 처리과정
               repetition = 1;
               continue;
               fflush(stdin);
            }
            for (int i = 0; i < n; i++) {
               if (i != index && strcmp(telephone[index].name, telephone[i].name) == 0) {
                  duplicate = 1; // 동명이인 처리과정
               }
            }
            if (duplicate) {
               printf("같은 이름의 연락처가 이미 있습니다.\n");
               printf("같은 이름의 다른 연락처로 수정하시겠습니까?(다른사람이면 1 같은사람이면 1이외의 다른 문자열) ");
               scanf("%s", samename); 
               getchar();
               if (samename[0] == '1') {
                  printf("같은 이름의 다른 연락처로 수정하겠습니다.\n");
                  repetition = 1;
                  while (repetition) { // 동명이인을 처리하고 난 후에 만약 같은 이름의 다른 사람일 때 나이, 전화번호, 성별 수정코드
                     // 이 밑에 나와있는 코드들은 나이수정, 전화번호 수정, 성별 수정 과정에서 사용한 코드들의 활용임
                     printf("수정할 나이를 입력하세요: ");
                     scanf("%s", telephone[index].age);
                     repetition = 0;
                     if (strlen(telephone[index].age) > 3) {
                        printf("입력한 나이가 너무 깁니다. 다시 입력하세요.\n");
                        fflush(stdin);
                        repetition = 1;
                     }
                     else {
                        break;
                     }
                  }
                  repetition = 1;
                  while (repetition) {
                     printf("수정할 전화번호를 입력하세요(ex:010-8888-8888): ");
                     scanf("%s", telephone[index].number);
                     repetition = 0;
                     for (int i = 0; i < n; i++) {
                        if (i != index && strcmp(telephone[index].number, telephone[i].number) == 0) {
                           printf("전화번호는 같을 수 없습니다. 다시 입력하세요.\n");
                           repetition = 1;
                           break;
                        }
                     }
                     if (strlen(telephone[index].number) > 14) {
                        printf("입력한 전화번호가 너무 깁니다. 다시 입력하세요.\n");
                        repetition = 1;
                        fflush(stdin);
                     }
                  }
                  printf("수정할 성별을 입력하세요: ");
                  scanf("%s", telephone[index].gender);
                  if (strlen(telephone[index].gender) > 3) {
                     printf("입력한 성별이 너무 깁니다. 다시 입력하세요.\n");
                     repetition = 1;
                     continue;
                     fflush(stdin);
                  }
                  printf("수정완료\n\n"); // 수정이 되었다는 걸 보여주기 위해 해당 인덱스의 전화번호부를 재출력
                  printf("인덱스 번호: %d\n", index);
                  printf("이름: %s\n", telephone[index].name);
                  printf("나이: %s\n", telephone[index].age);
                  printf("전화번호: %s\n", telephone[index].number);
                  printf("성별: %s\n\n", telephone[index].gender);
               }
               // 만약 같은이름의 동명이인을 수정하는 과정에서의 if문이 끝나는 곳

               else {
                  printf("연락처 수정을 하지 않았습니다.\n\n");
                  strcpy(telephone[index].name, backup);
                  return;
                  // 여기에서 만약에 이름에 동명이인이 있어서 동명이인에서 처리를 해버렸는데 연락처 수정을 하지 않았다고 끝나버리면
                  // 이름은 바뀌고 나머지는 안바뀌기 때문에 backup으로 올려놓은 값을 다시 입력한 인덱스의 이름으로 넣은것.
               }
            }
            else { // 동명이인이 아닐 때 나이, 전화번호, 성별을 수정하는 코드 위의 것 활용한것
               repetition = 1;
               while (repetition) {
                  printf("수정할 나이를 입력하세요: ");
                  scanf("%s", telephone[index].age);
                  repetition = 0;
                  if (strlen(telephone[index].age) > 3) {
                     printf("입력한 나이가 너무 깁니다. 다시 입력하세요.\n");
                     fflush(stdin);
                     repetition = 1;
                  }
                  else {
                     break;
                  }
               }
               repetition = 1;
               while (repetition) {
                  printf("수정할 전화번호를 입력하세요(ex:010-8888-8888): ");
                  scanf("%s", telephone[index].number);
                  repetition = 0;
                  for (int i = 0; i < n; i++) {
                     if (i != index && strcmp(telephone[index].number, telephone[i].number) == 0) {
                        printf("전화번호는 같을 수 없습니다. 다시 입력하세요.\n");
                        repetition = 1;
                        break;
                     }
                  }
                  if (strlen(telephone[index].number) > 14) {
                     printf("입력한 전화번호가 너무 깁니다. 다시 입력하세요.\n");
                     repetition = 1;
                     fflush(stdin);
                  }
               }
               repetition = 1;
               while (repetition) {
                  printf("수정할 성별을 입력하세요: ");
                  scanf("%s", telephone[index].gender);
                  repetition = 0;
                  if (strlen(telephone[index].gender) > 3) {
                     printf("입력한 성별이 너무 깁니다. 다시 입력하세요.\n");
                     repetition = 1;
                     fflush(stdin);
                  }
               }

               printf("수정완료\n\n"); // 수정이 되었다는 걸 보여주기 위해 해당 인덱스의 전화번호부를 재출력
               printf("인덱스 번호: %d\n", index);
               printf("이름: %s\n", telephone[index].name);
               printf("나이: %s\n", telephone[index].age);
               printf("전화번호: %s\n", telephone[index].number);
               printf("성별: %s\n\n", telephone[index].gender);
               return;
            }
         }
         break;
      case '6':
         printf("아무것도 수정하지 않았습니다.\n\n");
         break;
      default:
         printf("다시입력하세요.\n\n");
         continue;
      }
      break;
   }
}

void deletenumber() {
   int index;
   char select[100]; // select라는 변수로 문자열 배열을 100byte만큼의 크기로 받아서 내가 번호를 입력할 때 숫자만이 아닌 문자로도 입력을 가능하게 함
   char really[100]; // 위와 같은 이유
   while (1) {
      printf("1. 전체삭제 \n");
      printf("2. 부분삭제 \n");
      printf("번호를 입력하세요: ");
      scanf(" %s", select);
      getchar();
      index = select[0] - (int)'0'; 
      // 이 코드는 지금 위에서 index가 정수형으로 받았기 때문에 index에는 정수만 들어갈 수 있다
      // 하지만 select는 문자기 때문에 select에 예를 들어 2982dkshdka2가 입력이 되었다고 해도
      // select배열에서 0번째 인덱스만 가져옥 때문에 문자 '2'만 받게 된다.
      // 여기에서 정수형 0의 문자 즉, 아스키 코드 값을 빼서 문자열 '2'의 아스키 코드값과 '0'의 코드값을 빼서 숫자 2로 만드는 과정임
      if (n == 0) {
         printf("전화번호부에 연락처가 없습니다.\n\n");
         return;
      }
      switch (select[0]) {
      case '1':
         printf("정말 삭제하시겠습니까?(1을 누르면 삭제 1이외의 다른 숫자, 문자 입력시 삭제안함) ");
         scanf(" %s", really);
         if (really[0] == '1') {
            n = 0;
            printf("연락처가 전체삭제되었습니다.\n\n");
            return;
            // 1을 입력하면 전체삭제가 되고 그 외의 문자를 입력하면 메뉴로 넘어감
         }
         else {
            printf("전체삭제를 하지 않았습니다.\n\n");
            return;
         }
      case '2':
         print(); // 이것도 수정함수와 마찬가지로 미리 연락처를 출력하여 몇번째의 인덱스를 지울지 선택하기 위해서 연락처를 출력함
         printf("삭제할 전화번호부의 인덱스 번호를 입력하세요: ");
         scanf("%d", &index);
         getchar();
         printf("이름: %s\n", telephone[index].name);
         printf("나이: %s\n", telephone[index].age);
         printf("전화번호: %s\n", telephone[index].number);
         printf("성별: %s\n\n", telephone[index].gender);
         printf("정말 삭제하시겠습니까?(1: 삭제 1이외의 다른 문자열: 삭제 안함): ");
         scanf("%s", really);
         getchar();
         if (really[0] == '1') {
            for (int i = index; i < n; i++) {
               telephone[i] = telephone[i + 1];
            }
            //really 배열에서 제일 앞에 있는것이 문자열 1이면 해당 인덱스를 삭제하고 배열이 비기 때문에 뒤에 있는 배열을 앞으로 채움
            printf("삭제완료.\n\n");
            n--;
            return;
         }
         else {
            printf("다시 입력하세요.\n\n");
            return;
         }
      default:
         printf("다시 입력하세요.\n");
         break;
      }
   }
}

void search() {
   char nameornumber[100]; // nameornumber라는 문자열 배열을 100byte로 만들어서 위와 같은 방식으로 처리하기 위함
   int searching = 0; // 만약 문자열을 검색했을 때 결과가 있으면 1이 되고 아니면 0이 그대로 가는데 만약 이 변수가 0이면 검색 결과가 없는 것
   while (1) {
      printf("검색할 내용을 입력하세요(부분 문자 검색가능): ");
      scanf("%s", nameornumber);
      for (int i = 0; i < size; i++)
      {
         if (strstr(telephone[i].name, nameornumber)) {
            printf("인덱스 번호: %d\n", i);   
            printf("이름: %s\n", telephone[i].name);
            printf("나이: %s\n", telephone[i].age);
            printf("전화번호: %s\n", telephone[i].number);
            printf("성별: %s\n\n", telephone[i].gender);
            searching = 1;
            // strstr함수를 이용해서 내가 입력한 문자와 i=0부터 n-1까지 반복하면서 문자열이 있는지 확인해줌
            // 만약 있다면 그 문자를 가지고 있는 모든 연락처를 출력함
         }
         else if (strstr(telephone[i].age, nameornumber)) {
            printf("인덱스 번호: %d\n", i);
            printf("이름: %s\n", telephone[i].name);
            printf("나이: %s\n", telephone[i].age);
            printf("전화번호: %s\n", telephone[i].number);
            printf("성별: %s\n\n", telephone[i].gender);
            searching = 1;
            // 위와 같은 개념 사용
         }
         else if (strstr(telephone[i].number, nameornumber)) {
            printf("인덱스 번호: %d\n", i);
            printf("이름: %s\n", telephone[i].name);
            printf("나이: %s\n", telephone[i].age);
            printf("전화번호: %s\n", telephone[i].number);
            printf("성별: %s\n\n", telephone[i].gender);
            searching = 1;
            // 위와 같은 개념 사용
         }
         else if (strstr(telephone[i].gender, nameornumber)) {
            printf("인덱스 번호: %d\n", i);
            printf("이름: %s\n", telephone[i].name);
            printf("나이: %s\n", telephone[i].age);
            printf("전화번호: %s\n", telephone[i].number);
            printf("성별: %s\n\n", telephone[i].gender);
            searching = 1;
            // 위와 같은 개념 사용
         }
      }

      if (searching == 0) {
         printf("검색한 이름 또는 전화번호가 존재하지 않습니다.\n\n");
         break;
         // 위에서 만들어둔 searching == 0이면 검색결과가 없는 것임
      }
      break;
   }
}


int static compare(const void* first, const void* second)
{
   return strcmp(((address*)first) -> name, ((address*)second) -> name); 
   // first포인터에 이름, second 포인터에도 이름이 들어간후 qsort함수에서 이름을 기준으로 오름차순 정렬을 함.
}
// first는 첫번째 요소를 가리킬 포인터, second는 두번째 요소를 가리킬 포인터
// void을 사용한 이유는 qsort()함수를 사용하기 위해서 qsort는 어떤 타입의 데이터도 받을 수 있어야 함
// 저장된 연락처를 이름 기준으로 오름차순 정렬을 하기 위해서 사용함

void print() {
   int i;
   qsort(telephone, size, sizeof(address), compare); // qsort()함수를 사용해서 이름을 오름차순 정렬을 한 후에 출력을 함
   if (n > 0) {
      for (i = 0; i < n; i++) {
         printf("인덱스 번호 %d\n", i);
         printf("이름: %s\n", telephone[i].name);
         printf("나이: %s\n", telephone[i].age);
         printf("전화번호: %s\n", telephone[i].number);
         printf("성별: %s\n\n", telephone[i].gender);
      }
   }
   else {
      printf("전화번호부가 존재하지 않습니다.\n\n");
   }
}

void save() {
   FILE* numberbook;
   numberbook = fopen("C:\\Temp\\Number.txt", "w");
   if (numberbook == NULL) {
      printf("파일을 열지 못했습니다.");
      exit(1);
   }
   for (int i = 0; i < n; i++) {
      fprintf(numberbook, " %s %s %s %s\n",
         telephone[i].name,
         telephone[i].age,
         telephone[i].number,
         telephone[i].gender);
   } //fprintf가 파일에 출력을 하는 것이기 때문에 전화번호부에 있는 name,age,number,gender를 각 인덱스에 맞게 파일안에 출력을 하고 저장을 함.
   fclose(numberbook);
   printf("전화번호가 파일에 저장되었습니다.\n\n");
}
void load() {
   FILE* numberbook;
   numberbook = fopen("C:\\Temp\\Number.txt", "r");
   if (numberbook == NULL) {
      printf("파일을 열지 못했습니다.");
      exit(1);
   }
   while (!feof(numberbook)) {
      fscanf(numberbook, "%s %s %s %s",
         telephone[n].name,
         telephone[n].age,
         telephone[n].number,
         telephone[n].gender);
      n++;
      if (n >= size) {
         size = size * 2;
         telephone = (address*)realloc(telephone, size * sizeof(address));
      }
   }
   n--;
}