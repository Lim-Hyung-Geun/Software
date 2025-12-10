#define _CRT_SECURE_NO_WARNINGS
#include "numberbook.h"

int main() //main함수 시작
{
	telephone = (address*)malloc(size * sizeof(address)); // 동적 메모리를 할당함 size개의 address구조체를 저장할 수 있는 메모리
	// 위에서 지정한 구조체 배열을 가리키는 포인터인 telephone에 구조체 배열의 포인터로 malloc함수는 동적 메모리를 할당하는 것이므로
	// address의* 타입으로 변환을 해야함
	if (telephone == NULL) {
		printf("메모리 할당을 못했습니다.");
		return;
		// malloc함수는 메모리가 부족하면 NULL을 반환하기 때문에 오류 처리 과정으로 만약 telephone이 NULL이라면 메모리 할당을 못했다는 메세지와 함께
		// 출력되고 만약 메모리가 부족하지 않다면 return을 통해 다시 돌아간다  
		// exit()함수를 사용하지 않은 이유는 메모리 할당을 못했을 때 전체 프로그램이 종료가 되는 것을 방지한 것이다.
	}
	load();	// 우선적으로 내가 이전에 만들었던 전화번호부가 로드가 되어야 하기 때문에 직접 만든 load()함수를 먼저 호출한다.
	char choice[100];
	// 문자열 배열을 100바이트의 크기로 만든 이유는 화면이 출력이 되었을 때 문자가 들어갈 수도 있고 숫자가 들어갈 수도 있는데
	// 숫자 이외의 문자가 들어가면 무한루프에 빠지는 것을 방지하기 위함과 밑에서 사용할 switch-case문을 위해서 배열로 만들었음.
	while (1) {
		printf("전화번호부\n");
		printf("1. 전화번호 추가\n");
		printf("2. 전화번호 수정\n");
		printf("3. 전화번호 삭제\n");
		printf("4. 전화번호 검색\n");
		printf("5. 전화번호 출력\n");
		printf("6. 종료\n");
		printf("번호를 입력하세요: ");
		scanf("%s", choice); //choice는 문자열이기 때문에 %s로 받으며 변수앞에 &가 붙지 않는다.
		getchar();
		//getchar()를 사용한 이유는 입력 버퍼에 남아있는 것을 지우기 위함이다.
		// 조건을 choice[0]으로 받은 이유는 내가 만약 프로그램에 1whi2dh이런식으로 입력을 했을때에도 문자열 배열중에 0번째 인덱스만
		// 입력을 받기 위해서 choice[0]으로 지정하였음
		switch (choice[0]) {
		case '1':
			add(); // 1번을 누르면 밑에 만든 add() 함수로 넘어가게 되고 break문으로 종료된다.
			break;
		case '2': // 2번을 누르면 밑에 만든 edit()함수로 넘어가게 되고 break문으로 종료된다.
			edit();
			break;
		case '3':
			deletenumber(); // 3번을 누르면 밑에 만든 deletenumber()함수로 넘어가게 되고 break문으로 종료된다.
			break;
		case '4':
			search(); // 4번을 누르면 밑에 만든 search()함수로 넘어가게 되고 break문으로 종료된다.
			break;
		case '5': // 5번을 누르면 밑에 만든 print()함수로 넘어가게 되고 break문으로 종료된다.
			print();
			break;
		case '6': // 6번을 누르면 밑에 만든 save()함수를 이용해서 파일을 저장을 하고 프로그램을 종료시킨다.
			save();
			printf("프로그램을 종료합니다.");
			free(telephone); // 동적 메모리를 반납하는 것
			return 0;		// 강제 종료
		default: // 1,2,3,4,5,6 이외의 다른 숫자나 문자열이 입력되었을 때 다시입력하세요. 라고 출력하게 했음
			printf("다시입력하세요.\n\n");
			break;
		}
	}
	return 0;
}