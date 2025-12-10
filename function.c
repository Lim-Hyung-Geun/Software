#define _CRT_SECURE_NO_WARNINGS
#include "video.h"

// �˻��Լ����� �������� �ϰ����� ��Ű�� ���ؼ� �����Ѱ�
// �켱 ������ ��尡 ����Ǿ� �ִ��� Ȯ���ϸ鼭 �����ڰ� �ƴѰ�� �˻��� ���ϰ� �ϸ�, �㰡���� ���� �������� ������ �����Ѵ�. �̷ν� �������� ���Ἲ�� ���ٱ����� ��ȣ��.
// strstr �Լ��� ����Ͽ� �������� �Ϻζ� �˻��� �ǰ� �Ͽ�, �������� ���ټ��� ���̰� �ϰ����� ��ġ�� �ʴ´�.
// searching ������ �̿��ؼ� �˻� ����� �ִ����� Ȯ���ϸ� �������� �ϰ����� �����Ѵ�.
void videosearch() { // ���� �˻� �Լ�
	char videoname[100]; // videoname�� 100byte�� �迭�� ������ ������ ���� ���ڳ� ���ڸ� �󸶳� �Է����� �𸣱� ������ 100byte�� ������.
	int searching = 0; // searching�� 0���� �ʱ�ȭ�� ���ѳ��� �˻��� ������ ���� �� 1�� �����ϱ� ������ 0���� ����
	if (firstvideomanager == 0) {
		printf("���� ������ ��尡 �ƴϱ� ������ �˻��� �� �� �����ϴ�.\n\n");
		return;
	}
	while (1) { // while(1)�� �׻� ������ ���� �Ŀ� �������� break;�� ��
		printf("�˻��� ������ �Է��ϼ���(�κ� ���� �˻�����): ");
		scanf("%[^\n]", videoname); //  %[^\n]�� ������ �����ϴ� ���ڿ� �Է�
		getchar(); // getchar(); �� �Է� ���۸� ����
		for (int i = 0; i < videosize; i++) {
			if (strstr(vod[i].videonumber, videoname)) { // ���� �˻��� �κ� ���ڿ��� videonumber, �� ���� ������ȣ�� ���ԵǴ����� Ȯ���ϰ� ���Եȴٸ� �����.
				printf("������ȣ: %s\n", vod[i].videonumber);
				printf("�̸�: %s\n", vod[i].name);
				printf("�帣: %s\n", vod[i].genre);
				printf("����: %s\n", vod[i].director);
				printf("�뿩�� ȸ�� id: %s\n", vod[i].rentmemberid);
				printf("�뿩 ����(1: �뿩 ����, 0: �뿩��): %d\n\n", vod[i].rental);
				searching = 1;
			}
			else if (strstr(vod[i].name, videoname)) { // ���� ���� ������ �̸����� �κ� ���ڿ��� �˻���.
				printf("������ȣ: %s\n", vod[i].videonumber);
				printf("�̸�: %s\n", vod[i].name);
				printf("�帣: %s\n", vod[i].genre);
				printf("����: %s\n", vod[i].director);
				printf("�뿩�� ȸ�� id: %s\n", vod[i].rentmemberid);
				printf("�뿩 ����(1: �뿩 ����, 0: �뿩��): %d\n\n", vod[i].rental);
				searching = 1;
			}
			else if (strstr(vod[i].genre, videoname)) { // �帣���� �κ� ���ڿ� �˻��ϴ� ����
				printf("������ȣ: %s\n", vod[i].videonumber);
				printf("�̸�: %s\n", vod[i].name);
				printf("�帣: %s\n", vod[i].genre);
				printf("����: %s\n", vod[i].director);
				printf("�뿩�� ȸ�� id: %s\n", vod[i].rentmemberid);
				printf("�뿩 ����(1: �뿩 ����, 0: �뿩��): %d\n\n", vod[i].rental);
				searching = 1;
			}
			else if (strstr(vod[i].director, videoname)) {
				printf("������ȣ: %s\n", vod[i].videonumber);
				printf("�̸�: %s\n", vod[i].name);
				printf("�帣: %s\n", vod[i].genre);
				printf("����: %s\n", vod[i].director);
				printf("�뿩�� ȸ�� id: %s\n", vod[i].rentmemberid);
				printf("�뿩 ����(1: �뿩 ����, 0: �뿩��): %d\n\n", vod[i].rental);
				searching = 1;
			}
			// ���� ����ü���� ������ȣ, �̸�, �帣, ����, �뿩�� ȸ��, �뿩 ���ΰ� ����� �Ǿ����� ���� �˻������� �ʼ� ������ �ƴ� �� ���� ������.
		}
		if (searching == 0) { //  ���� searching�� 0�̶�� �տ��� �ʱ�ȭ �� ���� �״�� �ִ� ���̹Ƿ� �˻� ����� ���� ����. ���� ó�� ����
			printf("�˻��� ������ �������� �ʽ��ϴ�.\n\n");
			break;
		}
		break;
	}
}

void membersearch() { //  ȸ�� �˻� �Լ�
	char membername[100]; // ���� �˻� �Լ��� ���� ������ �ڵ带 �ۼ��Ͽ���.
	int searching = 0;
	if (firstmembermanager == 0) {
		printf("���� ������ ��尡 �ƴϱ� ������ �˻��� �� �� �����ϴ�.\n\n");
		return;
	}
	while (1) {
		printf("�˻��� ȸ���� �Է��ϼ���(�κ� ���� �˻�����): ");
		scanf("%[^\n]", membername);
		getchar();
		for (int i = 0; i < membersize; i++) {
			if (strstr(guest[i].number, membername)) {
				printf("�ε��� ��ȣ: %d\n", i);
				printf("id: %s\n", guest[i].id);
				printf("�̸�: %s\n", guest[i].name);
				printf("��ȭ��ȣ: %s\n", guest[i].number);
				printf("����: %s\n", guest[i].gender);
				printf("�뿩�� ���� ����: %d\n\n", guest[i].rentcount);
				searching = 1;
			}
			else if (strstr(guest[i].name, membername)) {
				printf("�ε��� ��ȣ: %d\n", i);
				printf("id: %s\n", guest[i].id);
				printf("�̸�: %s\n", guest[i].name);
				printf("��ȭ��ȣ: %s\n", guest[i].number);
				printf("����: %s\n", guest[i].gender);
				printf("�뿩�� ���� ����: %d\n\n", guest[i].rentcount);
				searching = 1;
			}
			else if (strstr(guest[i].number, membername)) {
				printf("�ε��� ��ȣ: %d\n", i);
				printf("id: %s\n", guest[i].id);
				printf("�̸�: %s\n", guest[i].name);
				printf("��ȭ��ȣ: %s\n", guest[i].number);
				printf("����: %s\n", guest[i].gender);
				printf("�뿩�� ���� ����: %d\n\n", guest[i].rentcount);
				searching = 1;
			}
			else if (strstr(guest[i].gender, membername)) {
				printf("�ε��� ��ȣ: %d\n", i);
				printf("id: %s\n", guest[i].id);
				printf("�̸�: %s\n", guest[i].name);
				printf("��ȭ��ȣ: %s\n", guest[i].number);
				printf("����: %s\n", guest[i].gender);
				printf("�뿩�� ���� ����: %d\n\n", guest[i].rentcount);
				searching = 1;
			}
		}
		if (searching == 0) { // ȸ���� �������� ���� ���� ���� ó��
			printf("�˻��� ȸ���� �������� �ʽ��ϴ�.\n\n");
			break;
		}
		break;
	}
}
 // strcmp �Լ��� ����Ͽ� �̸��� �Է��Ͽ� �߸��� �Է��̳� �߸��� �����Ͱ� �ݿ��� ���� �ʵ��� ��.
 // ���������� ó���Ͽ� �������� ��Ȯ���� ��Ŵ
 // Ư�� ���̵��� ȸ���� ������ �뿩�ϸ� ������ �뿩 ���� ���¸� 0���� �ٲ㼭 �뿩�Ұ��� �ϰ� ����, �ϳ��� ������ �ߺ����� �뿩���� �ʵ��� ��. 
 // ������ �뿩���� ���θ� Ȯ���Ͽ� �뿩 ������ ������ �뿩�� �� ���ֵ��� �����ν� �ý����� ���¿� �ϰ��� �뿩�� �̷�� ���� ��.
 // �뿩�� �� �� ����ڰ� ������ �����ν� ���� ������ ��Ȯ�ϰ� ó���Ͽ� �������� �ϰ����� ������
void rent() { // ���� �뿩 �Լ�
	char searchname[100]; // searchname�迭�� ȸ�� �̸��� �Է��� ���� ��. 100byte�� ������ ������ �󸶳� �Է����� �������� �ʾұ� ������.
	char rentname[100]; // rentname�迭�� �ش� �̸����� �뿩�ϴ� ���� Ȯ���� �� ��. 100byte�� ������ ���� ������.
	char rentid[100]; // rentid �迭�� �뿩�� �ϸ鼭 id�� �Է¹޾Ƽ� �뿩�� �ϱ� ������ id�� �Է� �޴� �迭��. 
	char rentvideo[100]; // rentvideo �迭�� �뿩 �������� �뿩�� ������ ������ȣ�� �Է� ���� �� �����.
	int searching = 0; // ȸ���� �������� ã�� ���ؼ� ������ ������
	int duplicate = 0; // ���������� ���� ���� ó�� �ϱ� ���ؼ� ������ ������
	int idfound = 0; // id�� ã���� �� 1�� �ٲٱ� ���ؼ� 0���� �ʱ�ȭ�� ��Ŵ.
	int memberindex = -1; // memberindex�� -1�� �س��� ������ 0���� �ϸ� 0��° �ε����� ���� �� ���� �ֱ� ������ -1�� ������
	printf("ȸ�� �̸��� �Է��ϼ���: ");
	scanf("%[^\n]", searchname);
	getchar();
	for (int i = 0; i < Nummember; i++) {
		if (strcmp(guest[i].name, searchname) == 0) { // strcmp�Լ��� �̿��ؼ� ���ڿ��� ���ϰ� ���� �Է��� �̸��� ������ searching�� 1�� �ٲ�.
			searching = 1;
			break;
		}
	}
	if (searching == 0) { // ���� searching�� 0�̶�� �Է��� �̸��� �������� �ʴ� ���̱� ������ �������� �ʴ´ٴ� ������ �����. ���� ó�� ����
		printf("�ش� �̸��� ȸ���� �������� �ʽ��ϴ�.\n\n");
		return;
	}
	if (searching) { // �Է��� �̸��� ������ �� ���ǹ��� ������
		printf("�Է��� �̸��� �����մϴ�. �ش� �̸����� �뿩�Ͻðڽ��ϱ�?(1: ��, 1�̿��� ���ڿ�: �ƴϿ�) ");
		scanf("%s", rentname);
		getchar();
		if (rentname[0] == '1') { // rentname[0]���� �ϴ� ������ �տ� �ִ� ���ڸ� �ޱ� ���ؼ��̴�.
			for (int i = 0; i < Nummember; i++) {
				if (strcmp(guest[i].name, searchname) == 0) {
					printf("�ε��� ��ȣ: %d\n", i);
					printf("id: %s\n", guest[i].id);
					printf("�̸�: %s\n", guest[i].name);
					printf("��ȭ��ȣ: %s\n", guest[i].number);
					printf("����: %s\n", guest[i].gender);
					printf("�뿩�� ���� ����: %d\n\n", guest[i].rentcount);
					duplicate++;
					// ���������� ã�� ���� �׸��� ã�Ҵٸ� �뿩�� id�� �ϱ� ������ id�� ã�� ���ؼ� ȸ�� ������ �����.
				}
			}
			if (duplicate == 1) { // ���������� �������� ���� ��
				printf("������ �뿩�� ���̵� �������ּ���: ");
				scanf("%s", rentid);
				for (int i = 0; i < Nummember; i++) {
					if (strcmp(guest[i].id, rentid) == 0) {
						idfound = 1;
						memberindex = i;
						break;
						// �뿩�� ���̵� �Է� �ް� strcmp�� �̿��ؼ� ������ ���ٸ� idfound�� 1�� �ٲٰ� memberindex = i�� ����
					}
				}
				if (idfound == 0) { // ���� idfound�� 0�̶�� ������ ���̵� ��ã�����̹Ƿ� ���̵� �������� �ʴٴ� ������ �Բ� ���� ó���� ��.
					printf("�Է��� ���̵� �������� �ʽ��ϴ�.\n\n");
					return;
				}
				printf("%s���̵��� ȸ������ ������ �뿩�ϰڽ��ϴ�.\n", rentid); // ���̵� �����ϸ� ���
				int availablevideo = 0; // availablevideo ������ �뿩 ������ ������ ã���� ���� ó���ϱ� ���ؼ� ����.
				for (int i = 0; i < Numvideo; i++) {
					if (vod[i].rental == 1) {
						availablevideo++;
						break;
						// ���� availablevideo�� 1�̻��̸� �뿩�� ������ ������ �ִ� ����.
					}
				}

				if (availablevideo == 0) {
					printf("�뿩 ������ ������ �������� �ʽ��ϴ�.\n\n");
					return;
					// ���� availablevideo�� 0�̸� �뿩 ������ ������ �������� �ʴ� ���̹Ƿ� ���� ó���� ��.
				}

				printf("�뿩 ������ ���� ���: \n"); // �뿩 ������ ���� ����� ����ؼ� �뿩�� �� �� ������ ���� ��ȣ�� �Է� ���� �� �ֵ��� ��.
				int available = 0; // ������ ������ ������ �ؿ��� �뿩 ������ ������ ����� �Ǿ�� �ϱ� ������ �뿩 ������ 1�� �͸� ã�� ���ؼ� ������ ������
				for (int i = 0; i < Numvideo; i++) {
					if (vod[i].rental == 1) {
						printf("������ȣ: %s\n", vod[i].videonumber);
						printf("�̸�: %s\n", vod[i].name);
						printf("�帣: %s\n", vod[i].genre);
						printf("����: %s\n", vod[i].director);
						printf("�뿩�� ȸ�� id: %s\n", vod[i].rentmemberid);
						printf("�뿩 ����(1: �뿩 ����, 0: �뿩��): %d\n\n", vod[i].rental);
						available = 1;
						// ���� �뿩 ���� ���ΰ� 1�̶�� ������ ����ϰ� available�� 1�� �ٲ�
					}
				}
				if (available == 0) {
					printf("�뿩 ������ ������ �����ϴ�.\n\n");
					return;
					// ���� available�� 0�̶�� �뿩 ������ ������ �������� �ʴ� ���̹Ƿ� ���� ó�� ����.
				}
				if (Numvideo == 0) {
					printf("������ �������� �ʽ��ϴ�.\n\n");
					return;
				}
				printf("������ ������ ������ȣ�� �Է��ϼ���: ");
				scanf("%s", rentvideo);
				getchar();

				int videorent = 0; // �ؿ��� �뿩�� �� �� �뿩�� ������ 1�� �ٲٱ� ���ؼ� ������ ������.
				for (int i = 0; i < Numvideo; i++) {
					if (strcmp(vod[i].videonumber, rentvideo) == 0) {
						vod[i].rental = 0;
						printf("%s��ȣ�� ������ �뿩�߽��ϴ�.\n", rentvideo);
						strcpy(vod[i].rentmemberid, rentid);
						guest[memberindex].rentcount++;
						videorent = 1;
						break;
						// ���� �뿩�� ������ ������ȣ�� ���� ��Ͽ� ���� �ϸ� �뿩�� �ϰ� strcpy�Լ����̿��ؼ� ���� ����ü �ȿ� ����ִ� �뿩�� ȸ�� id�� ����.
						// ���� ���� ������ �ϳ� �ø��� ������ ������ videorent�� 1�� �ٲ�
					}
				}
				if (videorent == 0) { // ���� videorent�� 0�̶�� �˻��� ������ȣ�� ������ �������� �ʴ� ���̹Ƿ� ���� ó���� ��.
					printf("�˻��� ��ȣ�� ������ �������� �ʽ��ϴ�.\n\n");
					return;
				}
			}
			if (duplicate > 1) {
				printf("�˻��� �̸� �߿��� �ߺ��� �̸��� �̷��� �ֽ��ϴ�.\n");
				printf("������ �뿩�� ���̵� �������ּ���: ");
				scanf("%s", rentid);
				for (int i = 0; i < Nummember; i++) {
					if (strcmp(guest[i].id , rentid) == 0) {
						idfound = 1;
						memberindex = i;
						break;
						// �뿩�� ���̵� �Է� �ް� strcmp�� �̿��ؼ� ������ ���ٸ� idfound�� 1�� �ٲٰ� memberindex = i�� ����
					}
				}
				if (idfound == 0) { // ���� idfound�� 0�̶�� ������ ���̵� ��ã�����̹Ƿ� ���̵� �������� �ʴٴ� ������ �Բ� ���� ó���� ��.
					printf("�Է��� ���̵� �������� �ʽ��ϴ�.\n\n");
					return;
				}
				printf("%s���̵��� ȸ������ ������ �뿩�ϰڽ��ϴ�.\n", rentid); // ���̵� �����ϸ� ���
				int availablevideo = 0; // availablevideo ������ �뿩 ������ ������ ã���� ���� ó���ϱ� ���ؼ� ����.
				for (int i = 0; i < Numvideo; i++) {
					if (vod[i].rental == 1) {
						availablevideo++;
						break;
						// ���� availablevideo�� 1�̻��̸� �뿩�� ������ ������ �ִ� ����.
					}
				}

				if (availablevideo == 0) { 
					printf("�뿩 ������ ������ �������� �ʽ��ϴ�.\n\n");
					return;
					// ���� availablevideo�� 0�̸� �뿩 ������ ������ �������� �ʴ� ���̹Ƿ� ���� ó���� ��.
				}

				printf("�뿩 ������ ���� ���: \n"); // �뿩 ������ ���� ����� ����ؼ� �뿩�� �� �� ������ ���� ��ȣ�� �Է� ���� �� �ֵ��� ��.
				int available = 0; // ������ ������ ������ �ؿ��� �뿩 ������ ������ ����� �Ǿ�� �ϱ� ������ �뿩 ������ 1�� �͸� ã�� ���ؼ� ������ ������
				for (int i = 0; i < Numvideo; i++) {
					if (vod[i].rental == 1) {
						printf("������ȣ: %s\n", vod[i].videonumber);
						printf("�̸�: %s\n", vod[i].name);
						printf("�帣: %s\n", vod[i].genre);
						printf("����: %s\n", vod[i].director);
						printf("�뿩�� ȸ�� id: %s\n", vod[i].rentmemberid);
						printf("�뿩 ����(1: �뿩 ����, 0: �뿩��): %d\n\n", vod[i].rental);
						available = 1;
						// ���� �뿩 ���� ���ΰ� 1�̶�� ������ ����ϰ� available�� 1�� �ٲ�
					}
				}
				if (available == 0) {
					printf("�뿩 ������ ������ �����ϴ�.\n\n");
					return;
					// ���� available�� 0�̶�� �뿩 ������ ������ �������� �ʴ� ���̹Ƿ� ���� ó�� ����.
				}
				if (Numvideo == 0) {
					printf("������ �������� �ʽ��ϴ�.\n\n");
					return;
				}
				printf("������ ������ ������ȣ�� �Է��ϼ���: ");
				scanf("%s", rentvideo);
				getchar();

				int videorent = 0; // �ؿ��� �뿩�� �� �� �뿩�� ������ 1�� �ٲٱ� ���ؼ� ������ ������.
				for (int i = 0; i < Numvideo; i++) {
					if (strcmp(vod[i].videonumber, rentvideo) == 0) {
						vod[i].rental = 0;
						printf("%s��ȣ�� ������ �뿩�߽��ϴ�.\n", rentvideo);
						strcpy(vod[i].rentmemberid, rentid);
						guest[memberindex].rentcount++;
						videorent = 1;
						break;
						// ���� �뿩�� ������ ������ȣ�� ���� ��Ͽ� ���� �ϸ� �뿩�� �ϰ� strcpy�Լ����̿��ؼ� ���� ����ü �ȿ� ����ִ� �뿩�� ȸ�� id�� ����.
						// ���� ���� ������ �ϳ� �ø��� ������ ������ videorent�� 1�� �ٲ�
					}
				}
				if (videorent == 0) { // ���� videorent�� 0�̶�� �˻��� ������ȣ�� ������ �������� �ʴ� ���̹Ƿ� ���� ó���� ��.
					printf("�˻��� ��ȣ�� ������ �������� �ʽ��ϴ�.\n\n");
					return;
				}
			}
		}
		else { // ���� 1�� �ƴ� �ٸ� ���ڳ� ���ڿ��� �Է��ϸ� �뿩���� �ʴ� ����.
			printf("�Է��� �̸����� �뿩���� �ʰڽ��ϴ�.\n\n");
			return;
		}
	}
}

int static videocompare(const void* first, const void* second)
{
	return strcmp(((video*)first)->name, ((video*)second)->name);
	// first�����Ϳ� �̸�, second �����Ϳ��� �̸��� ���� qsort�Լ����� �̸��� �������� �������� ������ ��.
}
// first�� ù��° ��Ҹ� ����ų ������, second�� �ι�° ��Ҹ� ����ų ������
// void�� ����� ������ qsort()�Լ��� ����ϱ� ���ؼ� qsort�� � Ÿ���� �����͵� ���� �� �־�� ��
// ����� ���� ������ �̸� �������� �������� ������ �ϱ� ���ؼ� �����

// ������ ����� �� ������ ��尡 �ƴ϶�� ����� ���ϰ� �����ν� �������� ����� �����鼭 �������� ���Ἲ�� ��ȣ��.
// �뿩 ������ ������ ����� �� �ֵ��� �����ν� �������� �ϰ����� ������.
void videoprint() { // ���� ��� �Լ�
	if (firstvideomanager == 0) {
		printf("���� ������ ��尡 �ƴϱ� ������ ����� �� �� �����ϴ�.\n\n");
		return;
	}
	qsort(vod, Numvideo, sizeof(video), videocompare); // qsort �Լ��� �̿��ؼ� ������ ������ ������������ ������ ��
	if (Numvideo > 0) { // Numvideo�� ���� ������ �����̱� ������ 0 �̻��� ���� ������ �����.
		int available = 0; // ������ ������ ������ �ؿ��� �뿩 ������ ������ ����� �Ǿ�� �ϱ� ������ �뿩 ������ 1�� �͸� ã�� ���ؼ� ������ ������
		for (int i = 0; i < Numvideo; i++) {
			if (vod[i].rental == 1) {
				printf("������ȣ: %s\n", vod[i].videonumber);
				printf("�̸�: %s\n", vod[i].name);
				printf("�帣: %s\n", vod[i].genre);
				printf("����: %s\n", vod[i].director);
				printf("�뿩�� ȸ�� id: %s\n", vod[i].rentmemberid);
				printf("�뿩 ����(1: �뿩 ����, 0: �뿩��): %d\n\n", vod[i].rental);
				available = 1;
				// ���� �뿩 ���� ���ΰ� 1�̶�� ������ ����ϰ� available�� 1�� �ٲ�
			}
		}
		if (available == 0) {
			printf("�뿩 ������ ������ �����ϴ�.\n\n");
			// ���� available�� 0�̶�� �뿩 ������ ������ �������� �ʴ� ���̹Ƿ� ���� ó�� ����.
		}
	}
	else {
		printf("������ �������� �ʽ��ϴ�.\n\n");
		// ���� Numvideo�� 0���� ũ�� �ʴٸ� ������ �������� �ʴ� ��.
	}
}

int static membercompare(const void* first, const void* second)
{
	return strcmp(((member*)first)->name, ((member*)second)->name);
	// first�����Ϳ� �̸�, second �����Ϳ��� �̸��� ���� qsort�Լ����� �̸��� �������� �������� ������ ��.
}
// first�� ù��° ��Ҹ� ����ų ������, second�� �ι�° ��Ҹ� ����ų ������
// void�� ����� ������ qsort()�Լ��� ����ϱ� ���ؼ� qsort�� � Ÿ���� �����͵� ���� �� �־�� ��
// ����� ȸ�� ������ �̸� �������� �������� ������ �ϱ� ���ؼ� �����

void memberprint() { // ȸ�� ������ ����ϴ� �Լ�
	if (firstmembermanager == 0) {
		printf("���� ������ ��尡 �ƴϱ� ������ ����� �� �� �����ϴ�.\n\n");
		return;
	}
	qsort(guest, Nummember, sizeof(member), membercompare); // qsort�Լ��� �̿��ؼ� ȸ�� ������ �������� ������.
	if (Nummember > 0) { // ���� ��°� ���� ������ �ڵ带 �ۼ���.
		for (int i = 0; i < Nummember; i++) {
			printf("�ε��� ��ȣ: %d\n", i);
			printf("id: %s\n", guest[i].id);
			printf("�̸�: %s\n", guest[i].name);
			printf("��ȭ��ȣ: %s\n", guest[i].number);
			printf("����: %s\n", guest[i].gender);
			printf("�뿩�� ���� ����: %d\n\n", guest[i].rentcount);
		}
	}
	else {
		printf("ȸ�������� �������� �ʽ��ϴ�.\n\n");
	}
}
// ȸ�������� �߰��� ���� ���������� ������ ��尡 �ƴ� �̻� �����Ϳ� ������ �� ������ ����鼭 ���Ἲ�� ��ȣ��
// ȸ�������� �߰��� ��, ���������̳�, ������ ���̸� �ʰ��ؼ� �Է��ϰų�, ���� ��ȭ��ȣ�� �Է��� �� ���� �ϴ� ��, �̷��� �۾����� �������� �ϰ����� ������.
void memberadd() { // ȸ�� ���� �߰� �Լ�.
	if (firstmembermanager == 0) {
		printf("���� ������ ��尡 �ƴϱ� ������ �߰��� �� �� �����ϴ�.\n\n");
		return;
	}
	if (Nummember >= membersize) {
		membersize = membersize * 2; // ���� Nummember�� membersize���� Ŀ���� ũ�⸦ 2�� �� �Ŀ� realloc�Լ��� �̿��ؼ� �޸𸮸� ���Ҵ� ��.
		member* maxguest = (member*)realloc(guest, membersize * sizeof(member));
		if (maxguest == NULL) {
			printf("�޸� �Ҵ��� ���߽��ϴ�.\n");
			return 1;
			// ���� ������ ������ maxguest�� NULL�̶�� �޸� �Ҵ��� ���Ѱ��̹Ƿ� ���� ó���� ��.
		}
		guest = maxguest; // �� �Ŀ� ����� ���� guest�� maxguest�� ����.
	}
	int repetition = 1; // while���� �ݺ��ϱ� ���ؼ�
	char samename[100]; // ���������� ó���ϱ� ���ؼ� 100byte�� �迭�� ������.
	int duplicate = 0; // ���������� ó�� �� �� ���Ǵ� ����.
	randomid(guest[Nummember].id); // �ؿ��� ���� id�� �������� ����� �Լ���.
	while (repetition) { // repetition�� ���� 1�̹Ƿ� �ϴ� while���� ������.
		printf("�̸��� �Է��ϼ���: ");
		scanf("%s", guest[Nummember].name);
		repetition = 0; // �̸��� �Է� ���� �Ŀ� ���̻� �Է��� ���� �ʱ� ���ؼ� repetition�� 0���� �ٲ�
		for (int i = 0; i < Nummember; i++) {
			if (strcmp(guest[Nummember].name, guest[i].name) == 0) {
				duplicate = 1; // ���������� ó���ϴ� ����.
			}
		}
		if (duplicate) {
			printf("���� �̸��� ����� �����մϴ�.\n");
			printf("���� �̸��� �ٸ� ������� �����Ͻðڽ��ϱ�?(�ٸ� ����̸� 1 ���� ����̸� 1�̿��� �ٸ� ���ڿ�) ");
			scanf("%s", samename);
			getchar();
			if (samename[0] == '1') {
				printf("���� �̸��� �ٸ� ������� �߰��ϰڽ��ϴ�.\n");
				// 1�� �Է��ϸ� ���� �̸��� �ٸ����, �� ������������ ������ �߰���.
			}
			else {
				printf("ȸ�� ������ �߰����� �ʾҽ��ϴ�.\n\n");
				strcpy(guest[Nummember].id, "0");
				strcpy(guest[Nummember].name, "�R�R�R�R");
				strcpy(guest[Nummember].number, "0");
				strcpy(guest[Nummember].gender, "0");
				guest[Nummember].rentcount = 0;
				return;
				// ȸ�� ������ �߰����� �ʾ��� �� �̷����� ����� �� ������ �� ���������� Nummember++�� �ϱ� ������ ���߿� �̸��� �Է��ϰ� ��Ҹ� �ϸ�
				// ������ ���� ����� ������ ���������� ���� ���� ���� ���� �������� '�R�R�R�R' �� �־ ���� ������ ���������ν� ������ ���� ��µ��� �ʰ���.
			}
		}
		if (strlen(guest[Nummember].name) > 11) {
			printf("�Է��� �̸��� �ʹ� ��ϴ�. �ٽ� �Է��ϼ���.\n");
			repetition = 1;
			fflush(stdin);
			// ���� ������ ������ �̸��� ũ�⺸�� ũ�� �Է��Ѵٸ� �ٽ� �Է��� �ް� ��.
		}
	}
	printf("����� �ԷµǾ����ϴ�.\n\n");

	repetition = 1; // �ٽ� 1�� ���� ��ȭ��ȣ�� �߰����� �� �ֵ��� ��.
	while (repetition) { // �̸� �߰� ������ ���� ������ �ڵ带 �ۼ���.
		printf("��ȭ��ȣ�� �Է��ϼ���(ex 010-1234-1234): ");
		scanf("%s", guest[Nummember].number);
		repetition = 0;
		for (int i = 0; i < Nummember; i++) {
			if (strcmp(guest[Nummember].number, guest[i].number) == 0) {
				printf("��ȭ��ȣ�� ���� �� �����ϴ�. �ٽ� �Է��ϼ���.\n");
				repetition = 1;
				break;
			}
		}
		if (strlen(guest[Nummember].number) > 13) {
			printf("�Է��� ��ȭ��ȣ�� �ʹ� ��ϴ�. �ٽ� �Է��ϼ���.\n");
			repetition = 1;
			fflush(stdin);
		}
	}
	printf("����� �ԷµǾ����ϴ�.\n\n");

	repetition = 1;
	while (repetition) { // ���� ���� ����.
		printf("������ �Է��ϼ���(��/��): ");
		scanf("%s", guest[Nummember].gender);
		getchar();
		repetition = 0;
		if (strlen(guest[Nummember].gender) > 3) {
			printf("�Է��� ������ �ʹ� ��ϴ�. �ٽ� �Է��ϼ���.\n");
			repetition = 1;
			fflush(stdin);
		}
	}
	printf("����� �ԷµǾ����ϴ�.\n\n");
	guest[Nummember].rentcount = 0; // �� ó���� �뿩�� ���� ������ 0�̱� ������ 0���� ������.
	Nummember++; // ������ �� �Է��� �Ǿ��ٸ� Nummember++�� ���ؼ� ������ �ø�.
	printf("ȸ�� ���� ���� �Ϸ�\n\n");
	membersave(); // ȸ�� ������ ������.
}

void videoadd() { //  ���� �߰� �Լ�
	if (firstvideomanager == 0) {
		printf("���� ������ ��尡 �ƴϱ� ������ �߰��� �� �� �����ϴ�.\n\n");
		return;
	}
	if (Numvideo >= videosize) { // ������ ȸ�� ���� �߰� �Լ����� ������ ����� ���� ������ �ڵ带 �ۼ���.
		videosize = videosize * 2;
		video* maxvod = (video*)realloc(vod, videosize * sizeof(video));
		if (maxvod == NULL) {
			printf("�޸� �Ҵ��� ���߽��ϴ�.\n");
			exit(1);
		}
		vod = maxvod;
	}
	
	int repetition = 1;
	char samevideo[100];

	randomvideonumber(vod[Numvideo].videonumber);
	while (repetition) {
		printf("���� ������ �Է��ϼ���: ");
		scanf("%s", vod[Numvideo].name);
		getchar();
		repetition = 0;

		if (strlen(vod[Numvideo].name) > 61) {
			printf("������ ������ �ʹ� ��ϴ�. �ٽ� �Է��ϼ���.\n");
			repetition = 1;
			fflush(stdin);
		}
	}
	printf("����� �ԷµǾ����ϴ�.\n\n");

	repetition = 1;
	while (repetition) {
		printf("������ �帣�� �Է��ϼ���: ");
		scanf("%s", vod[Numvideo].genre);
		getchar();
		repetition = 0;
		if (strlen(vod[Numvideo].genre) > 20) {
			printf("�Է��� ������ �帣�� �ʹ� ��ϴ�. �ٽ� �Է��ϼ���.\n");
			repetition = 1;
			fflush(stdin);
		}
	}
	printf("����� �ԷµǾ����ϴ�.\n\n");

	repetition = 1;
	while (repetition) {
		printf("������ ������ �Է��ϼ���: ");
		scanf("%s", vod[Numvideo].director);
		getchar();
		repetition = 0;
		if (strlen(vod[Numvideo].director) > 12) {
			printf("�Է��� ������ ������ �ʹ� ��ϴ�. �ٽ� �Է��ϼ���.\n\n");
			repetition = 1;
			fflush(stdin);
		}
	}

	strcpy(vod[Numvideo].rentmemberid, "����"); // ó���� ������ �߰��Ǿ��� �� �뿩�� ȸ���� �翬�� ����� �ϹǷ� �������� ���ڿ��� �����ؼ� �־��.
	vod[Numvideo].rental = 1; // �뿩 ���� ���θ� 1�� ����.

	printf("����� �ԷµǾ����ϴ�.\n\n");
	Numvideo++;
	printf("���� �����Ϸ�\n\n");
	videosave(); // ������ ������.
}

void randomid(char* id) { // ȸ�� ���� ������ �������� ����� �Լ�.
	int unique = 0;// �ߺ��� �˻��ϱ� ���� ����
	srand((unsigned)time(NULL)); // ���� �ʱ�ȭ

	while (!unique) {
		for (int i = 0; i < 2; i++) {
			id[i] = 'A' + rand() % 26; // 0���� 2���� �ݺ��ϸ鼭 2���� �빮�� ���ĺ��� ���� �� �ֵ��� �Ͽ����� �빮���� �� ������ 26�� �̹Ƿ� rand�Լ��� �̿��ؼ� ���� ��ȣ ����.
		}
		for (int i = 2; i < 4; i++) { // ������ 2���� ���ĺ��� ����� ���� ������ ���� 2���� �� �߰���.
			id[i] = '0' + rand() % 10;
		}
		id[4] = '\0'; // ���ڿ��� ���� �������� �ι��ڰ� ��.

		unique = 1;
		for (int i = 0; i < Nummember; i++) {
			if (strcmp(guest[i].id, id) == 0) {
				unique = 0;
				printf("���� ��ȣ�� ���� �� �����ϴ�.\n");
				break;
				// strcmp�� �̿��ؼ� �������� ���ϰ� ������ unique�� 0���� ���� 0�̸� ���� ���̱� ������ ���� �� ���ٰ� ��� ��. ���� ó�� ����.
			}
		}
	}
	printf("ȸ�� ���� id�� �ԷµǾ����ϴ�.\n\n");
}

void randomvideonumber(char* videonumber) { // ���� ������ȣ�� ����� �Լ�
	int unique = 0; // ȸ�� ���� ��ȣ�� ����� �Լ��� ���� ����
	srand((unsigned)time(NULL)); // ���� �ʱ�ȭ

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
				printf("���� ��ȣ�� ���� �� �����ϴ�.\n");
				break;
			}
		}
	}
	printf("���� ���� ��ȣ�� �ԷµǾ����ϴ�.\n\n");
}

void videosave() { // ���� ���� �Լ�.
	FILE* videobook; // ���� �����͸� videobook���� ����
	videobook = fopen("Video.txt", "w+"); // ���� ���丮�� �ִ� Video.txt�� ������ �ϰ� w+ �б�� ���� ���� ������ ���� �ϱ� ����.
	if (videobook == NULL) {
		printf("������ ���� ���߽��ϴ�.");	
		exit(1);// ���� videobook = NULL�̸� ������ �ȿ����� ���̹Ƿ� ����ó���� ��.
	}
	for (int i = 0; i < Numvideo; i++) {
		fprintf(videobook, " %s %s %s %s %s %d\n",
			vod[i].videonumber,
			vod[i].name,
			vod[i].genre,
			vod[i].director,
			vod[i].rentmemberid,
			vod[i].rental);
	} //fprintf�� ���Ͽ� ����� �ϴ� ���̱� ������ ���� ������ �ִ� videonumber, name, genre, director, rentmemberid, rental�� �� �ε����� �°� ���Ͼȿ� ����� �ϰ� ������ ��.
	fclose(videobook); // ������ ����.
	printf("������ ���Ͽ� ����Ǿ����ϴ�.\n\n");
}

void membersave() { // ���� ����� ���� ������ �ۼ���.
	FILE* memberbook; 
	memberbook = fopen("Member.txt", "w+"); 
	if (memberbook == NULL) {
		printf("������ ���� ���߽��ϴ�.");
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
	printf("ȸ�������� ���Ͽ� ����Ǿ����ϴ�.\n\n");
}

void videoload() { // ������ �ҷ����� �Լ�.
	FILE* videobook = fopen("Video.txt", "r+"); // videobook�� r+�� �б�� ���� ��尡 �����ϵ��� ������ ��
	if (videobook == NULL) { // videobook�� NULL�̸� ������ ���� ���Ѱ��̹Ƿ� ���� ó�� ����.
		printf("������ ���� ���߽��ϴ�.");
		exit(1);
	}

	while (fscanf(videobook, " %s %s %s %s %s %d\n",
		vod[Numvideo].videonumber,
		vod[Numvideo].name,
		vod[Numvideo].genre,
		vod[Numvideo].director,
		vod[Numvideo].rentmemberid,
		&vod[Numvideo].rental) == 6) {  // fscanf�� �̿��ؼ� ������ �а� 6���� ���������� �������� Ȯ����.

		Numvideo++; // ���� �� Numvideo�� �������� ����ó�� ������ �ø�

		// Numvideo�� videosize�� �ʰ��ϸ� ũ�⸦ �����ϰ� �޸𸮸� �� �Ҵ���.
		if (Numvideo >= videosize) {
			videosize = videosize * 2;  // ũ�⸦ �� ��� ����
			video* temp = (video*)realloc(vod, videosize * sizeof(video));
			if (temp == NULL) {  // temp�� NULL�̐� ���Ҵ��� ���� ���̹Ƿ� ���� ó�� ����.
				printf("�޸� ���Ҵ� ����\n");
				fclose(videobook); // ���� �ݱ�
				exit(1);
			}
			vod = temp; // ���Ҵ��� �����ϸ� temp�� vod�� ����.
		}
	}

	fclose(videobook); // ������ ����.
}


void memberload() { // ������ �ҷ����� �Լ��� ���� ����
	FILE* memberbook = fopen("Member.txt", "r+");
	if (memberbook == NULL) {
		printf("������ ���� ���߽��ϴ�.");
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
				printf("�޸� ���Ҵ� ����\n");
				fclose(memberbook); 
				exit(1);
			}
			guest = temp; 
		}
	}

	fclose(memberbook); 
}

void videoreturn() { // ������ �ݳ��ϴ� �Լ�
	char searchname[100]; // �̸��� �Է¹��� �� ����ϴ� �迭
	char returnvideo[100]; // �ݳ��� ������ ������ȣ�� �Է¹��� �� ����ϴ� ����
	char id[100]; // ���������� ������ �� ȸ���� ������ȣ�� �Է¹ޱ� ���� ����ϴ� ����
	int duplicate = 0; // ���������� ������ �� ó���ϱ� ���� ����
	int memberindex = -1; // memberindex�� -1�� ������ ������ 0���� �ϸ� 0���� �߸� ������ �� �ֱ� ����.
	int rentfound = 0; // �Է��� ȸ���� �뿩�� ������ ���� �� üũ�ϴ� ����
	printf("ȸ�� �̸��� �Է��ϼ���: ");
	scanf("%[^\n]", searchname);
	getchar();

	for (int i = 0; i < Nummember; i++) { // ���� �Է��� �̸��� ������ �̸��� ���ٸ� ������ �����.
		if (strcmp(guest[i].name, searchname) == 0) {
			printf("id: %s\n", guest[i].id);
			printf("�̸�: %s\n", guest[i].name);
			printf("��ȭ��ȣ: %s\n", guest[i].number);
			printf("����: %s\n", guest[i].gender);
			printf("�뿩�� ���� ����: %d\n\n", guest[i].rentcount);
			duplicate++; // duplicate�� �ø��鼭 ���������� ������ ã��.
			if (duplicate == 1) { // ���� duplicate�� 1�̶�� ���������� ���� ���̹Ƿ� memberindex�� i�� �����ϰ� ���ڿ��� �����ؼ� id�� �ش� ȸ���� id�� ����.
				memberindex = i;
				strcpy(id, guest[i].id);
			}
		}
	}
	if (duplicate == 0) { // ���� duplicate�� 0�̶�� �Է��� �̸��� �������� �ʴ� ���̹Ƿ� ���� ó�� ����.
		printf("�Է��� �̸��� �������� �ʽ��ϴ�.\n\n");
		return;
	}
	if (duplicate > 1) { // ���������� ���� �Ҷ�.
		printf("���� �̸��� ȸ���� �����մϴ�.\n");
		printf("ȸ���� id�� �Է��Ͽ� �ݳ��� �����ϰڽ��ϴ�.\n");
		printf("ȸ�� id�� �Է��ϼ���: ");
		scanf("%[^\n]", id);
		getchar();
		memberindex = -1;
		for (int i = 0; i < Nummember; i++) {
			if (strcmp(guest[i].id, id) == 0) {
				strcpy(id, guest[i].id);
				memberindex = i;
				break;
				// ���� �Է��� id�� ȸ�������� ���̵� ���ٸ� �Է��� ���̵� id�� ������ �� memberindex�� i�� �ٲ�.
			}
		}
		if (memberindex == -1) { // ���� memberindex�� -1�̸� �Է��� id�� ȸ���� �������� �ʴ� ���̹Ƿ� ���� ó�� ����.
			printf("�Է��� id�� ���� ȸ���� �������� �ʽ��ϴ�.\n\n");
			return;
		}
	}
	if (guest[memberindex].rentcount == 0) { // rentcount�� 0�̸� �뿩�� ������ ���� ���̹Ƿ� �ݳ��� �� ���� ����.
		printf("�뿩�� ������ �����ϴ�.\n\n");
		return;
	}
	printf("%s���̵��� ȸ���� �뿩 ���� ���� ���.\n\n", guest[memberindex]); // �Է��� ���̵��� ȸ���� �뿩���� ���� ����� ����Ͽ� ������ȣ�� Ȯ����.
	for (int i = 0; i < Numvideo; i++) {
		if (vod[i].rental == 0 && strcmp(vod[i].rentmemberid, id) == 0) {
			printf("������ȣ: %s\n", vod[i].videonumber);
			printf("�̸�: %s\n", vod[i].name);
			printf("�帣: %s\n", vod[i].genre);
			printf("����: %s\n", vod[i].director);
			printf("�뿩�� ȸ�� id: %s\n", vod[i].rentmemberid);
			printf("�뿩 ����(1: �뿩 ����, 0: �뿩��): %d\n\n", vod[i].rental);
			rentfound = 1;
			// rentfound�� 1�� ���� ã���� ���� ó����.
		}
	}
	if (rentfound == 0) { // ���� rentfound�� 0�̶�� �뿩���� ���� ����� ���� ���̹Ƿ� ���� ó�� ����.
		printf("�뿩 ���� ���� ����� �����ϴ�.\n\n");
		return;
	}
	printf("�ݳ��� ������ ������ȣ�� �Է��ϼ���: ");
	scanf("%[^\n]", returnvideo);
	getchar();

	int revideo = 0; // �Է��� ������ ������ȣ�� �����ϴ��� Ȯ���ϱ� ���� ����
	for (int i = 0; i < Numvideo; i++) {
		if (strcmp(vod[i].rentmemberid, id) == 0 && strcmp(vod[i].videonumber, returnvideo) == 0) {
			printf("%s���� ��ȣ�� ������ �ݳ��߽��ϴ�.\n", returnvideo);
			vod[i].rental = 1;
			strcpy(vod[i].rentmemberid, "����");
			guest[memberindex].rentcount--;
			revideo = 1;
			break;
			// ���� �Է��� ��ȣ�� ������ȣ�� �ݳ��� ������ ������ ���ٸ� �ݳ��� �����ϰ� �ٽ� ���� ȸ�� id�� �������� ����� rentcount�� �ϳ� ������ revideo�� 1�� ����.
		}
	}
	if (revideo == 0) { // ���� revideo�� 0�̶�� �Է��� ������ �������� �ʰų� �ݳ��� �� ���� ���̹Ƿ� ���� ó�� ����.
		printf("�Է��� ������ �������� �ʰų� �ݳ��� �� �����ϴ�.\n\n");
		return;
	}
}

void memberdelete() { // ȸ���� �����ϴ� �Լ�.
	if (firstmembermanager == 0) {
		printf("���� ������ ��尡 �ƴϱ� ������ ������ �� �� �����ϴ�.\n\n");
		return;
	}
	char deleteid[100]; // deleteid�� ������ ���̵� �Է¹��� �� ����ϴ� ����.
	char select[100]; // select��� ������ ���ڿ� �迭�� 100byte��ŭ�� ũ��� �޾Ƽ� ���� ��ȣ�� �Է��� �� ���ڸ��� �ƴ� ���ڷε� �Է��� �����ϰ� ��
	char really[100]; // ���� ���� ����
	while (1) {
		printf("1. ȸ�� ���� ��ü���� \n");
		printf("2. ȸ�� ���� ���û��� \n");
		printf("��ȣ�� �Է��ϼ���: ");
		scanf("%[^\n]", select);
		getchar();
		if (Nummember == 0) { // ���� Nummmember�� 0�̶�� ȸ�������� ���� ���̹Ƿ� ȸ�� ������ �������� �ʴ´ٴ� ������ ����ϰ� ��. ���� ó�� ����.
			printf("ȸ�������� �������� �ʽ��ϴ�.\n\n");
			return;
		}
		switch (select[0]) {
		case '1':
			for (int i = 0; i < Nummember; i++) {
				if (guest[i].rentcount > 0) {
					printf("%s�̸��� ȸ���� ������ �뿩���̹Ƿ� ��ü ������ �� �� �����ϴ�.\n\n", guest[i].name);
					return;
					// ���� ��ü ������ �ϴ��� �Ѹ��̶� ������ �뿩�ϰ� �ִٸ� ������ �Ǹ� �ȵǱ� ������ ��ü ������ �� �� ������ ��. ���� ó�� ����.
				}
			}
			printf("���� �����Ͻðڽ��ϱ�?(1�� ������ ���� 1�̿��� �ٸ� ����, ���� �Է½� ��������) ");
			scanf("%[^\n]", really);
			if (really[0] == '1') {
				Nummember = 0;
				printf("ȸ�� ������ ��ü �����Ǿ����ϴ�.\n\n");
				return;
				// 1�� �Է��ϸ� ��ü������ �ǰ� �� ���� ���ڸ� �Է��ϸ� �޴��� �Ѿ
			}
			else {
				printf("��ü������ ���� �ʾҽ��ϴ�.\n\n");
				return;
				// 1�� �Է����� �ʾҴٸ� ��ü������ ���� �ʰ� �޴��� �Ѿ.
			}
		case '2':
			memberprint(); // ���� ������ �ϱ� ���� ������ ȸ�� ������ id�� �˰� �־�� �ϹǷ� �̸� ȸ�� ������ �����.
			printf("������ ȸ�� ������ id�� �Է��ϼ���: ");
			scanf("%[^\n]", deleteid);
			getchar();
			int found = -1; //  found�� �ε����� ǥ���ϱ� ���ؼ� ����� ����.
			for (int i = 0; i < Nummember; i++) {
				if (strcmp(guest[i].id, deleteid) == 0) {
					found = i;
					break;
					// ���� ���� �Է��� id�� �����Ѵٸ� found�� i�� ����.
				}
			}
			if (found == -1) { // found�� -1�̶�� �Է��� ���̵� �������� �ʴ� ��. ���� ó�� ����.
				printf("�Է��� id�� �������� �ʽ��ϴ�.\n\n");
				return;
			}
			if (guest[found].rentcount > 0) { // ���� �Է��� ������ȣ�� rentcount�� 0 �̻��̶�� ���� �뿩���̱� ������ ������ ���ϰ� ��. ���� ó�� ����.
				printf("�Է��� ������ȣ�� �뿩���̹Ƿ� ������ �� �����ϴ�.\n\n");
				return;
			}
			printf("id: % s\n", guest[found].id);
			printf("�̸�: %s\n", guest[found].name);
			printf("��ȭ��ȣ: %s\n", guest[found].number);
			printf("����: %s\n\n", guest[found].gender);
			printf("���� �����Ͻðڽ��ϱ�?(1: ���� 1�̿��� �ٸ� ���ڿ�: ���� ����): ");
			scanf("%[^\n]", really);
			getchar();
			// ������ ������ ����ϰ� ���� ������ �Ұ������� �Է� ����.
			if (really[0] == '1') {
				for (int i = found; i < Nummember; i++) {
					guest[i] = guest[i + 1];
				}
				//really �迭���� ���� �տ� �ִ°��� ���ڿ� 1�̸� �ش� �ε����� �����ϰ� �迭�� ��� ������ �ڿ� �ִ� �迭�� ������ ä��
				printf("���� �Ϸ�.\n\n");
				Nummember--;
				return;
			}
			else {
				printf("�ش� ȸ�� ������ �������� �ʾҽ��ϴ�.\n\n");
				return;
			}
		default:
			printf("�ٽ� �Է��ϼ���.\n");
			return;
		}
	}
}

void videodelete() { // ȸ�� ������ ���� ������ �ڵ带 �ۼ���.
	if (firstvideomanager == 0) {
		printf("���� ������ ��尡 �ƴϱ� ������ ������ �� �� �����ϴ�.\n\n");
		return;
	}
	char deletenumber[100];
	char choice[100];
	char really[100];
	while (1) {
		printf("1. ���� ��ü ����\n");
		printf("2. ���� ���� ����\n");
		printf("��ȣ�� �Է��ϼ���: ");
		scanf("%[^\n]", choice);
		getchar();
		if (Numvideo == 0) {
			printf("������ �������� �ʽ��ϴ�.\n");
			return;
		}

		switch (choice[0]) {
		case '1':
			for (int i = 0; i < Numvideo; i++) {
				if (vod[i].rental == 0) {
					printf("%s������ ������ ���� �뿩���̹Ƿ� ������ �� �����ϴ�.\n\n", vod[i].name);
					return;
				}
			}
			printf("���� �����Ͻðڽ��ϱ�?(1�� ������ ���� 1�̿��� �ٸ� ����, ���� �Է½� ��������) ");
			scanf("%[^\n]", really);
			if (really[0] == '1') {
				Numvideo = 0;
				printf("������ ��ü�����Ǿ����ϴ�.\n\n");
				return;
				// 1�� �Է��ϸ� ��ü������ �ǰ� �� ���� ���ڸ� �Է��ϸ� �޴��� �Ѿ
			}
			else {
				printf("��ü������ ���� �ʾҽ��ϴ�.\n\n");
				return;
			}
		case '2':
			if (Numvideo > 0) {
				for (int i = 0; i < Numvideo; i++) {
					printf("�ε��� ��ȣ: %d\n", i);
					printf("������ȣ: %s\n", vod[i].videonumber);
					printf("����: %s\n", vod[i].name);
					printf("�帣: %s\n", vod[i].genre);
					printf("����: %s\n", vod[i].director);
					printf("�뿩�� ȸ�� id: %s\n", vod[i].rentmemberid);
					printf("�뿩����(1: �뿩 ����, 0: �뿩 ��): %d\n\n", vod[i].rental);
				}
			}
			else {
				printf("������ �������� �ʽ��ϴ�.\n\n");
			}
			printf("������ ������ ������ȣ�� �Է��ϼ���: ");
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
				printf("�ش� ������ �뿩���̹Ƿ� ������ �� �����ϴ�.\n\n");
				return;
			}
			if (found == -1) {
				printf("�Է��� ���� ��ȣ�� �������� �ʽ��ϴ�.\n\n");
				return;
			}
			printf("������ȣ: %s\n", vod[found].videonumber);
			printf("����: %s\n", vod[found].name);
			printf("�帣: %s\n", vod[found].genre);
			printf("����: %s\n", vod[found].director);
			printf("�뿩����(1: �뿩 ����, 0: �뿩 ��): %d\n\n", vod[found].rental);
			printf("���� �����Ͻðڽ��ϱ�?(1: ���� 1�̿��� �ٸ� ���ڿ�: ���� ����): ");
			scanf("%[^\n]", really);
			getchar();
			if (really[0] == '1') {
				for (int i = found; i < Numvideo; i++) {
					vod[i] = vod[i + 1];
				}
				//really �迭���� ���� �տ� �ִ°��� ���ڿ� 1�̸� �ش� �ε����� �����ϰ� �迭�� ��� ������ �ڿ� �ִ� �迭�� ������ ä��
				printf("�����Ϸ�.\n\n");
				Numvideo--;
				return;
			}
			else {
				printf("�ش� ������ ���������ʾҽ��ϴ�.\n\n");
				return;
			}
		default:
			printf("�ٽ� �Է��ϼ���.\n");
			return;
		}
	}
}

void videoedit() { // ���� �����ϴ� �Լ�
	if (firstvideomanager == 0) { // firstvideomanager�� ���� ������ ������ 0�� ���� ������ ��带 ������ �� ���� ������ ������ �����ؼ� ������ ��带 �����ϸ� 1, �ƴϸ� 0���� �ϰ� ��.
		printf("���� ������ ��尡 �ƴϱ� ������ ������ �� �� �����ϴ�.\n\n");
		return;
	}
	char videonumber[100]; // videonumber��� ������ 100byte�迭�� ������ ������ �Է��� ������ȣ�� ���� �����ε� � ���ڿ� ���ڰ� ���� �𸣱� ����
	int index = -1; // index��� ������ ������ ������ �ؿ��� �����ϴ��� Ȯ���� �� index = i�� �ϱ� ����.
	while (1) {
		for (int i = 0; i < Numvideo; i++) {
			printf("������ȣ: %s\n", vod[i].videonumber);
			printf("�̸�: %s\n", vod[i].name);
			printf("�帣: %s\n", vod[i].genre);
			printf("����: %s\n", vod[i].director);
			printf("�뿩�� ȸ�� id: %s\n", vod[i].rentmemberid);
			printf("�뿩 ����(1: �뿩 ����, 0: �뿩��): %d\n\n", vod[i].rental);
		}
		if (Numvideo == 0) {
			printf("���� ������ �������� �ʽ��ϴ�.\n");
			return;
		}
		// ���� ������ �����ϱ� ���� ���� ������ �ִ� ������ ������ ����Ͽ� ������ȣ�� �Է� ���� �� �ֵ��� ��.
		printf("������ ������ ������ȣ�� �Է��ϼ���: ");
		scanf("%s", videonumber);
		getchar();
		for (int i = 0; i < Numvideo; i++) {
			if (strcmp(vod[i].videonumber, videonumber) == 0) {
				index = i;
				break;
				// ���� ���� �����ȿ� ���� �Է��� ������ ������ȣ�� �����Ѵٸ� index = i�� �ٲ�.
			}
		}
		if (index == -1) {
			printf("�Է��� ������ȣ�� ������ �������� �ʽ��ϴ�.\n\n");
			return;
		}

		if (vod[index].rental == 1) {
			char editvideo[100]; // ��ȣ�� �Է¹��� �� ���� ����
			char editgenre[100]; // ���� �帣�� ������ �� ����ϴ� ����
			char editdirector[100]; // ���� ������ ������ �� ����ϴ� ����
			printf("������ȣ: %s\n", vod[index].videonumber);
			printf("�̸�: %s\n", vod[index].name);
			printf("�帣: %s\n", vod[index].genre);
			printf("����: %s\n", vod[index].director);
			printf("1. ���� ���� ����\n");
			printf("2. ���� �帣 ����\n");
			printf("3. ���� ���� ����\n");
			printf("4. ��ü ����\n");
			printf("��ȣ�� �Է��ϼ���: ");
			scanf("%s", editvideo);
			getchar();

			char editname[100];
			switch (editvideo[0]) { // editvideo[0]���� �� ������ �迭���� ���� �տ� �ִ� ���� ������ ����.
			case '1':
				printf("������ ���� ������ �Է��ϼ���: ");
				scanf("%s", editname);
				getchar();
				if (strlen(editname) > 61) {
					printf("�Է��� ������ ������ �ʹ� ��ϴ�. �ٽ� �Է��ϼ���.\n");
					fflush(stdin);
					return;
					// ���� ������ ũ�⺸�� ������ ��� �Ѵٸ� ���θ޴��� ���ư��� ��.
				}
				if (strcmp(vod[index].name, editname) == 0) {
					printf("������ ������ ������ ���� �� �����ϴ�. �ٽ� �Է��ϼ���.\n");
					fflush(stdin);
					return;
					// ������ ������ ������ ���� �ʰ� �� ������ �����̱� ������ ���� ���� ���� �� ���ٰ� �����߱� ����.
				}
				strcpy(vod[index].name, editname); // ������ ������ ������ �� �� ���� �״�� ������ �Ǿ������ ������ ������ �ϳ� ���� ���������� ������ �Ǿ��ٸ� �����ؼ� ������ ��.
				printf("�����Ϸ�.\n\n");
				printf("������ȣ: %s\n", vod[index].videonumber);
				printf("�̸�: %s\n", vod[index].name);
				printf("�帣: %s\n", vod[index].genre);
				printf("����: %s\n", vod[index].director);
				printf("�뿩�� ȸ�� id: %s\n", vod[index].rentmemberid);
				printf("�뿩 ����(1: �뿩 ����, 0: �뿩��): %d\n\n", vod[index].rental);
				return;
			case '2':
				printf("������ ���� �帣�� �Է��ϼ���: "); // ���� ���� �������� �ۼ��� �ڵ�
				scanf("%s", editgenre);
				getchar();
				if (strlen(editgenre) > 20) {
					printf("�Է��� ������ �帣�� �ʹ� ��ϴ�. �ٽ� �Է��ϼ���\n");
					fflush(stdin);
					return;
				}
				if (strcmp(vod[index].genre, editgenre) == 0) {
					printf("������ ������ �帣�� ���� �� �����ϴ�. �ٽ� �Է��ϼ���.\n");
					fflush(stdin);
					return;
				}
				strcpy(vod[index].genre, editgenre);
				printf("�����Ϸ�.\n\n");
				printf("������ȣ: %s\n", vod[index].videonumber);
				printf("�̸�: %s\n", vod[index].name);
				printf("�帣: %s\n", vod[index].genre);
				printf("����: %s\n", vod[index].director);
				printf("�뿩�� ȸ�� id: %s\n", vod[index].rentmemberid);
				printf("�뿩 ����(1: �뿩 ����, 0: �뿩��): %d\n\n", vod[index].rental);
				return;
			case '3':
				printf("������ ���� ������ �Է��ϼ���: "); // ���� ���� �������� �ۼ��� �ڵ�
				scanf("%s", editdirector);
				getchar();
				if (strlen(editdirector) > 12) {
					printf("�Է��� ������ ������ �ʹ� ��ϴ�. �ٽ� �Է��ϼ���.\n");
					fflush(stdin);
					return;
				}
				if (strcmp(vod[index].director, editdirector) == 0) {
					printf("������ ������ ������ ���� �� �����ϴ�. �ٽ� �Է��ϼ���.\n");
					fflush(stdin);
					return;
				}
				strcpy(vod[index].director, editdirector);
				printf("�����Ϸ�.\n\n");
				printf("������ȣ: %s\n", vod[index].videonumber);
				printf("�̸�: %s\n", vod[index].name);
				printf("�帣: %s\n", vod[index].genre);
				printf("����: %s\n", vod[index].director);
				printf("�뿩�� ȸ�� id: %s\n", vod[index].rentmemberid);
				printf("�뿩 ����(1: �뿩 ����, 0: �뿩��): %d\n\n", vod[index].rental);
				return;
			case '4':
				printf("������ ���� ������ �Է��ϼ���: ");
				scanf("%s", editname);
				getchar();
				if (strlen(editname) > 61) {
					printf("�Է��� ������ ������ �ʹ� ��ϴ�. �ٽ� �Է��ϼ���.\n");
					fflush(stdin);
					return;
					// ���� ������ ũ�⺸�� ������ ��� �Ѵٸ� ���θ޴��� ���ư��� ��.
				}
				if (strcmp(vod[index].name, editname) == 0) {
					printf("������ ������ ������ ���� �� �����ϴ�. �ٽ� �Է��ϼ���.\n");
					fflush(stdin);
					return;
					// ������ ������ ������ ���� �ʰ� �� ������ �����̱� ������ ���� ���� ���� �� ���ٰ� �����߱� ����.
				}
				strcpy(vod[index].name, editname); // ������ ������ ������ �� �� ���� �״�� ������ �Ǿ������ ������ ������ �ϳ� ���� ���������� ������ �Ǿ��ٸ� �����ؼ� ������ ��.
				printf("�����Ϸ�.\n\n");

				printf("������ ���� �帣�� �Է��ϼ���: "); // ���� ���� �������� �ۼ��� �ڵ�
				scanf("%s", editgenre);
				getchar();
				if (strlen(editgenre) > 20) {
					printf("�Է��� ������ �帣�� �ʹ� ��ϴ�. �ٽ� �Է��ϼ���\n");
					fflush(stdin);
					return;
				}
				if (strcmp(vod[index].genre, editgenre) == 0) {
					printf("������ ������ �帣�� ���� �� �����ϴ�. �ٽ� �Է��ϼ���.\n");
					fflush(stdin);
					return;
				}
				strcpy(vod[index].genre, editgenre);
				printf("�����Ϸ�.\n\n");
				printf("������ȣ: %s\n", vod[index].videonumber);

				printf("������ ���� ������ �Է��ϼ���: "); // ���� ���� �������� �ۼ��� �ڵ�
				scanf("%s", editdirector);
				getchar();
				if (strlen(editdirector) > 12) {
					printf("�Է��� ������ ������ �ʹ� ��ϴ�. �ٽ� �Է��ϼ���.\n");
					fflush(stdin);
					return;
				}
				if (strcmp(vod[index].director, editdirector) == 0) {
					printf("������ ������ ������ ���� �� �����ϴ�. �ٽ� �Է��ϼ���.\n");
					fflush(stdin);
					return;
				}
				strcpy(vod[index].director, editdirector);
				printf("�����Ϸ�.\n\n");
				printf("������ȣ: %s\n", vod[index].videonumber);
				printf("�̸�: %s\n", vod[index].name);
				printf("�帣: %s\n", vod[index].genre);
				printf("����: %s\n", vod[index].director);
				printf("�뿩�� ȸ�� id: %s\n", vod[index].rentmemberid);
				printf("�뿩 ����(1: �뿩 ����, 0: �뿩��): %d\n\n", vod[index].rental);
				return;
			default:
				printf("�ٽ� �Է��ϼ���.\n");
				return;
			}
		}
		else {
			printf("�ش� ������ ���� �뿩���̹Ƿ� ������ �� �����ϴ�.\n\n");
			return;
		}
		break;
	}
}


void memberedit() { // ������ § ���� ���� �Լ��� ���� ������ ����Ͽ� �ڵ带 «.
	if (firstvideomanager == 0) {
		printf("���� ������ ��尡 �ƴϱ� ������ ������ �� �� �����ϴ�.\n\n");
		return;
	}
	char memberid[100];
	int index = -1;
	while (1) {
		memberprint();
		printf("������ ȸ�������� ������ȣ�� �Է��ϼ���: ");
		scanf("%s", memberid);
		getchar();
		for (int i = 0; i < Nummember; i++) {
			if (strcmp(guest[i].id, memberid) == 0) {
				index = i;
				break;
			}
		}
		if (index == -1) {
			printf("�Է��� ������ȣ�� ȸ���� �������� �ʽ��ϴ�.\n\n");
			return;
		}

		if (guest[index].rentcount == 0) {
			printf("id: % s\n", guest[index].id);
			printf("�̸�: %s\n", guest[index].name);
			printf("��ȭ��ȣ: %s\n", guest[index].number);
			printf("����: %s\n\n", guest[index].gender);
			char editmember[100];
			printf("1. ȸ�� �̸� ����\n");
			printf("2. ȸ�� ��ȭ��ȣ ����\n");
			printf("3. ȸ�� ���� ����\n");
			printf("4. ��ü ����\n");
			printf("��ȣ�� �Է��ϼ���: ");
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
				printf("������ ȸ�� �̸��� �Է��ϼ���: ");
				scanf("%s", editname);
				getchar();
				for (int i = 0; i < Nummember; i++) {
					if (strcmp(guest[i].name, editname) == 0) {
						duplicate = 1;
						break;
					}
				}
				if (duplicate == 1) {
					printf("���� �̸��� ���� �ٸ� ����� �ֽ��ϴ�.\n");
					printf("���� �̸��� �ٸ� ������� �����Ͻðڽ��ϱ�?(1:�� 1�̿��� ���ڿ�:�ƴϿ�): ");
					scanf("%s", samename);
					getchar();
					if (samename[0] == '1') {
						printf("���� �̸��� �ٸ� ������� �����ϰڽ��ϴ�.\n");
					}
					else {
						printf("�������� �ʾҽ��ϴ�.\n\n");
						return;
					}
				}
				else {
					printf("�ش� �̸����� �����ϰڽ��ϴ�.\n");
				}
				if (strlen(editname) > 12) {
					printf("�Է��� �̸��� ���̰� �ʹ� ��ϴ�. �ٽ� �Է��ϼ���.\n");
					fflush(stdin);
					return;
				}
				if (strcmp(guest[index].name, editname) == 0) {
					printf("������ �̸��� ���� �� �����ϴ�. �ٽ� �Է��ϼ���.\n");
					fflush(stdin);
					return;
				}
				strcpy(guest[index].name, editname);
				printf("���� �Ϸ�.\n");
				printf("id: %s\n", guest[index].id);
				printf("�̸�: %s\n", guest[index].name);
				printf("��ȭ��ȣ: %s\n", guest[index].number);
				printf("����: %s\n", guest[index].gender);
				printf("�뿩�� ���� ����: %d\n\n", guest[index].rentcount);
				break;
			case '2':
				printf("������ ��ȭ��ȣ�� �Է��ϼ���: ");
				scanf("%s", editnumber);
				getchar();
				if (strlen(editnumber) > 14) {
					printf("�Է��� ��ȭ��ȣ�� �ʹ� ��ϴ�. �ٽ� �Է��ϼ���.\n");
					fflush(stdin);
					return;
				}
				for (int i = 0; i < Nummember; i++) {
					if (strcmp(guest[i].number, editnumber) == 0) {
						printf("������ ��ȭ��ȣ�� ���� �� �����ϴ�. �ٽ� �Է��ϼ���.\n");
						fflush(stdin);
						return;
					}
				}
				strcpy(guest[index].number, editnumber);
				printf("���� �Ϸ�.\n");
				printf("id: %s\n", guest[index].id);
				printf("�̸�: %s\n", guest[index].name);
				printf("��ȭ��ȣ: %s\n", guest[index].number);
				printf("����: %s\n", guest[index].gender);
				printf("�뿩�� ���� ����: %d\n\n", guest[index].rentcount);
				break;
			case '3':
				printf("������ ������ �Է��ϼ���: ");
				scanf("%s", editgender);
				getchar();
				if (strlen(editgender) > 3) {
					printf("�Է��� ������ �ʹ� ��ϴ�. �ٽ� �Է��ϼ���.\n");
					fflush(stdin);
					return;
				}
				for (int i = 0; i < Nummember; i++) {
					if (strcmp(guest[i].gender, editgender) == 0) {
						printf("������ ������ ���� �� �����ϴ�. �ٽ� �Է��ϼ���.\n");
						fflush(stdin);
						return;
					}
				}
				strcpy(guest[index].gender, editgender);
				printf("���� �Ϸ�.\n");
				printf("id: %s\n", guest[index].id);
				printf("�̸�: %s\n", guest[index].name);
				printf("��ȭ��ȣ: %s\n", guest[index].number);
				printf("����: %s\n", guest[index].gender);
				printf("�뿩�� ���� ����: %d\n\n", guest[index].rentcount);
				break;
			case '4':
				printf("������ ȸ�� �̸��� �Է��ϼ���: ");
				scanf("%s", editname);
				getchar();
				for (int i = 0; i < Nummember; i++) {
					if (strcmp(guest[i].name, editname) == 0) {
						duplicate = 1;
						break;
					}
				}
				if (duplicate == 1) {
					printf("���� �̸��� ���� �ٸ� ����� �ֽ��ϴ�.\n");
					printf("���� �̸��� �ٸ� ������� �����Ͻðڽ��ϱ�?(1:�� 1�̿��� ���ڿ�:�ƴϿ�): ");
					scanf("%s", samename);
					getchar();
					if (samename[0] == '1') {
						printf("���� �̸��� �ٸ� ������� �����ϰڽ��ϴ�.\n");
					}
					else {
						printf("�������� �ʾҽ��ϴ�.\n\n");
						return;
					}
				}
				else {
					printf("�ش� �̸����� �����ϰڽ��ϴ�.\n");
				}
				if (strlen(editname) > 12) {
					printf("�Է��� �̸��� ���̰� �ʹ� ��ϴ�. �ٽ� �Է��ϼ���.\n");
					fflush(stdin);
					return;
				}
				if (strcmp(guest[index].name, editname) == 0) {
					printf("������ �̸��� ���� �� �����ϴ�. �ٽ� �Է��ϼ���.\n");
					fflush(stdin);
					return;
				}
				strcpy(guest[index].name, editname);
				printf("���� �Ϸ�.\n");

				printf("������ ��ȭ��ȣ�� �Է��ϼ���: ");
				scanf("%s", editnumber);
				getchar();
				if (strlen(editnumber) > 14) {
					printf("�Է��� ��ȭ��ȣ�� �ʹ� ��ϴ�. �ٽ� �Է��ϼ���.\n");
					fflush(stdin);
					return;
				}
				for (int i = 0; i < Nummember; i++) {
					if (strcmp(guest[i].number, editnumber) == 0) {
						printf("������ ��ȭ��ȣ�� ���� �� �����ϴ�. �ٽ� �Է��ϼ���.\n");
						fflush(stdin);
						return;
					}
				}
				strcpy(guest[index].number, editnumber);
				printf("���� �Ϸ�.\n");

				printf("������ ������ �Է��ϼ���: ");
				scanf("%s", editgender);
				getchar();
				if (strlen(editgender) > 3) {
					printf("�Է��� ������ �ʹ� ��ϴ�. �ٽ� �Է��ϼ���.\n");
					fflush(stdin);
					return;
				}
				for (int i = 0; i < Nummember; i++) {
					if (strcmp(guest[i].gender, editgender) == 0) {
						printf("������ ������ ���� �� �����ϴ�. �ٽ� �Է��ϼ���.\n");
						fflush(stdin);
						return;
					}
				}
				strcpy(guest[index].gender, editgender);
				printf("���� �Ϸ�.\n");
				printf("id: %s\n", guest[index].id);
				printf("�̸�: %s\n", guest[index].name);
				printf("��ȭ��ȣ: %s\n", guest[index].number);
				printf("����: %s\n", guest[index].gender);
				printf("�뿩�� ���� ����: %d\n\n", guest[index].rentcount);
				break;
			default:
				printf("�ٽ� �Է��ϼ���.\n");
				return;
			}
		}
		else {
			printf("�ش� ȸ���� ���� �뿩���� ������ �־� ������ �� �����ϴ�.\n\n");
			return;
		}
		break;
	}
}