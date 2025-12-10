#define _CRT_SECURE_NO_WARNINGS
#include "video.h"

int main()
{
	vod = (video*)malloc(videosize * sizeof(video)); // 동적 메모리를 할당하며 size개의 video구조체를 저장할 수 있는 메모리
	if (vod == NULL) {
		printf("메모리 할당을 못했습니다.");
		return 1;
	}
	// 만약 vod가 NULL이라면 메모리 할당을 못한것이므로 예외처리 과정을 함.
	// 메모리 할당을 못했다면 1을 반환함.

	guest = (member*)malloc(membersize * sizeof(member)); // 위와 같은 원리로 동적 메모리를 할당함.
	if (guest == NULL) {
		printf("메모리 할당을 못했습니다.");
		return 1;
	}

	videoload(); // 내가 전에 비디오를 추가했던 것을 다시 가져와야 하므로 load함수를 먼저 호출한다.
	memberload();
	char choice[100]; // choice 배열을 100byte로 설정한 이유는 메인 화면 창에서 무슨 숫자나 문자를 입력할 지 모르기에 100byte의 배열로 설정
	char setmanager[5] = ""; // 관리자 비밀번호가 들어가기 전에 ""로 초기화를 함
	char password[100]; // 밑에 관리자 모드에서 사용하는 변수

	while (1) {
		printf("비디오 대여 프로그램\n");
		printf("1. 검색\n");
		printf("2. 대여\n");
		printf("3. 출력\n");
		printf("4. 추가\n");
		printf("5. 삭제\n");
		printf("6. 반납\n");
		printf("7. 수정\n");
		printf("8. 관리자 모드\n");
		printf("9. 종료\n");
		printf("번호를 입력하세요: ");
		scanf(" %[^\n]", choice); // choice는 문자열이기 때문에 앞에 &가 붙지 않는다.
		getchar();
		// getchar()를 사용한 이유는 입력 버퍼를 지우기 위해서이다.

		char searchchoice[100]; // 위에 배열을 설정한 이유와 같은 이유이다.
		char printchoice[100];
		char addchoice[100];
		char deletenumber[100];
		char editnumber[100];
		// choice의 0번째를 가지고 오는 이유는 만약 1dkhskj 이런식으로 입력한다면 제일 앞에 있는 1만 가지고 오기 위해서 choice[0]을 사용함.
		switch (choice[0]) {
		case '1': // 1번을 입력하면 비디오 검색과 고객/가입자 검색으로 넘어가게 된다.
			printf("1. 비디오 검색\n");
			printf("2. 고객/가입자 검색\n");
			printf("번호를 입력하세요: ");
			scanf(" %[^\n]", searchchoice); //  %[^\n] 문자열을 입력 받을 때 이렇게 한 이유는 공백를 제외하고 받기 위해서이다.
			getchar();
			switch (searchchoice[0]) {
			case '1':
				videosearch();
				break;
			case '2':
				membersearch();
				break;
			default: // 1, 2가 아닌 다른 문자열을 입력하게 되면 다시 입력하세요 라는 말과 함께 continue를 이용하여 끊기지 않고 다시 시작을 하게 함.
				printf("다시입력하세요.\n\n");
				continue;
			}
			break;
		case '2':
			rent(); // rent함수로 넘어가게 함.
			break;
		case '3': // 3번을 입력하게 되면 1. 비디오 목록 출력, 2. 가입자 목록 출력 이 출력된다.
			printf("1. 비디오 목록 출력\n");
			printf("2. 가입자 목록 출력\n");
			printf("번호를 입력하세요: ");
			scanf(" %[^\n]", printchoice); // 문자열을 이렇게 받은 이유는 위와 같은 이유이다.
			getchar();
			switch (printchoice[0])
			{
			case '1':
				videoprint();
				break;
			case '2':	
				memberprint();
				break;
			default:
				printf("다시입력하세요.\n\n"); // 1, 2 를 제외한 다른 문자열을 입력 했을 때 다시 입력하세요 라는 문구와 함께 프로그램을 계속한다.
				continue;
			}
			break;
		case '4': // 4번을 입력하면 1. 가입자를 추가 하고 2. 비디오를 추가한다.
			printf("1. 가입자 추가\n");
			printf("2. 비디오 추가\n");
			printf("번호를 입력하세요: ");
			scanf(" %[^\n]", addchoice);
			getchar();
			switch (addchoice[0])
			{
			case '1':
				memberadd();
				break;
			case '2':
				videoadd();
				break;
			default:
				printf("다시입력하세요.\n\n"); // 위와 같은 이유이다.
				continue;
			}
			break;
		case '5': // 5번을 입력하면 1. 회원 정보 삭제, 2. 비디오 삭제가 가능하다.
			printf("1. 회원 정보 삭제\n");
			printf("2. 비디오 삭제\n");
			printf("번호를 입력하세요: ");
			scanf("%[^\n]", deletenumber);
			getchar();
			switch (deletenumber[0])
			{
			case '1':
				memberdelete();
				break;
			case '2':
				videodelete();
				break;
			default:
				printf("다시 입력하세요.\n");
				continue;
			}
			break;
		case '6':
			videoreturn(); // 비디오를 반납하는 함수
			break;
		case '7':
			printf("1. 비디오 수정\n");
			printf("2. 회원정보 수정\n");
			printf("번호를 입력하세요: ");
			scanf("%[^\n]", editnumber);
			getchar();
			switch (editnumber[0])
			{
			case '1':
				videoedit();
				break;
			case '2':
				memberedit();
				break;
			default:
				printf("다시 입력하세요.\n");
				continue;
			}
			break;
		case '8': // 관리자 모드를 실행하는 부분
			while (1) { // while(1)을 이용해서 항상 참으로 만들어서 무한 루프를 돌림
				if (firstmembermanager == 1) {
					printf("현재 관리자 모드입니다.\n\n");
					break; // firstmembermanger가 1이면 현재 관리자 모드인것.
				}
				if (strcmp(setmanager, "") == 0) {
					printf("관리자 모드를 실행하기 위한 비밀번호를 설정하세요.\n");
					printf("비밀번호를 설정하지 않는다면 자동으로 1111로 설정됩니다.\n");
					printf("설정하시겠습니까? (1: 예, 1이외의 문자열: 아니오): ");
					scanf("%s", password);
					getchar();
					// 관리자 모드를 시작하기 전에 관리자의 비밀번호를 등록하는 과정

					if (password[0] == '1') {
						printf("설정할 비밀번호를 입력하세요(최대 4자리): ");
						scanf("%s", setmanager);
						getchar();
						printf("비밀번호가 설정되었습니다.\n");
						break;
						// 만약 '1'을 입력하면 내가 직접 비밀번호를 설정한다.
					}
					else {
						printf("비밀번호가 자동으로 1111로 설정되었습니다.\n");
						strcpy(setmanager, "1111");
						break;
						// 만약 1이 아닌 다른 문자열을 입력하면 자동으로 1111이 들어가도록 strcpy함수를 사용함.
					}
				}
				else {
					printf("이미 비밀번호가 설정되어 있습니다.\n\n");
					break;
					// 위에서 setmanager[5] = "";로 초기화를 해놨기 때문에 빈 문자가 아니라면 이미 비밀번호가 설정이 되어 있는 것.
				}
			}
				char choice[100];
				char inputpassword[100];
				while (1) {
					printf("1. 관리자 모드 실행\n");
					printf("2. 관리자 모드 해제\n");
					printf("3. 관리자 모드 비밀번호 변경\n");
					printf("번호를 입력하세요: ");
					scanf("%[^\n]", choice);
					getchar();

					switch (choice[0])
					{
					case '1':
						if (firstmembermanager && firstvideomanager == 1) {
							printf("이미 관리자 모드이기 때문에 실행할 수 없습니다.\n\n");
							break;
						}
						printf("비밀번호를 입력하세요: ");
						scanf("%s", inputpassword);
						getchar();
						if (strcmp(setmanager, inputpassword) == 0) {
							printf("비밀번호가 일치합니다.\n");
							printf("관리자 모드를 실행하겠습니다.\n");
							printf("검색, 출력, 추가, 삭제, 수정 등의 기능은 관리자만 실행할 수 있습니다.\n");
							firstmembermanager = 1;
							firstvideomanager = 1;
							break;
							// 비밀번호가 일치 할때 관리자 모드를 실행시킴.
						}
						else {
							printf("비밀번호가 일치하지 않습니다.\n");
							break;
						}
						break;
					case '2':
						if (firstmembermanager == 0) {
							printf("현재 관리자 모드가 아니기 때문에 해제를 할 수 없습니다.\n\n");
							// 관리자 모드를 해제는 관리자만 할 수 있는 것임.
						}

						else {
							printf("비밀번호를 입력하세요: ");
							scanf("%s", inputpassword);
							getchar();
							if (strcmp(setmanager, inputpassword) == 0) {
								printf("비밀번호가 일치합니다.\n");
								printf("관리자 모드를 해제하겠습니다.\n\n");
								firstmembermanager = 0;
								firstvideomanager = 0;
								break;
							}
							else {
								printf("비밀번호가 일치하지 않습니다.\n");
								break;
							}
							break;
						}
						break;
					case '3':
						if (firstmembermanager == 0) {
							printf("현재 관리자 모드가 아니기 때문에 비밀번호 수정을 할 수 없습니다.\n\n");
							// 비밀번호 수정도 위와 같은 과정으로 코드를 작성함.
						}
						else {
							printf("현재 비밀번호를 입력하세요: ");
							scanf("%s", inputpassword);
							getchar();

							char reserve[100];
							char really[100];
							if (strcmp(setmanager, inputpassword) == 0) {
								printf("비밀번호가 일치합니다.\n");
								printf("수정할 비밀번호를 입력하세요: ");
								scanf("%s", reserve);
								printf("해당 비밀번호로 수정하시겠습니까? (1: 예, 1이외의 다른 문자열: 아니오): ");
								scanf("%s", really);
								if (really[0] == '1') {
									printf("해당 비밀번호로 수정했습니다.\n");
									strcpy(setmanager, reserve);
									break;
								}
								else {
									printf("해당 비밀번호로 수정을 하지 않았습니다.\n\n");
									break;
								}
							}
							else {
								printf("비밀번호가 일치하지 않습니다.\n");
								break;
							}
						}
						break;
					default:
						printf("다시 입력하세요.\n\n");
						break;
					}
					if (firstmembermanager && firstvideomanager == 1) {
						break;
					}
					break;
				}
				break;
		case '9':
			membersave(); // 회원을 저장하는 함수
			videosave(); // 비디오를 저장하는 함수
			printf("프로그램을 종료합니다.");
			free(vod); // 위에서 할당한 메모리를 해제함
			free(guest);
			return;
		default:
			printf("다시입력하세요.\n\n"); // 목록에 있는 숫자 이외의 문자나 숫자를 입력하면 다시 입력하세요 라는 문구가 출력되게 함.
			break;
		}
	}
	return 0;
}