#pragma once // 헤더파일 중복 방지
#define _CRT_SECURE_NO_WARNINGS
#ifndef VIDEO_H // 헤더가드로써 오류를 방지함
#define VIDEO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>

typedef struct {
	char videonumber[5];
	char name[61];
	char genre[20];
	char director[12];
	char rentmemberid[5];
	int rental;
} video;

typedef struct {
	char id[5];
	char name[12];
	char number[14];
	char gender[3];
	int rentcount;
} member;

extern int Nummember; // 현재 연락처 개수
extern int Numvideo; // 현재 비디오 개수
extern int membersize; // 현재 연락처 크기
extern int videosize; // 현재 비디오 크기
extern int firstmembermanager; // 회원 정보가 하나도 없을 때 관리자 모드를 관리하기 위한 변수
extern int firstvideomanager; // 위와 같은 이유
extern video* vod; // 동적 메모리를 가리킬 포인터
extern member* guest; 

void videosearch(); // 비디오 검색 함수
void membersearch(); // 회원 검색 함수
void rent(); // 대여 함수
void videoprint(); // 비디오 출력 함수
void memberprint(); // 회원 정보 출력 함수
void memberadd(); // 회원 정보 추가 함수
void videoadd(); // 비디오 추가 함수
void videosave(); // 비디오 저장 함수
void membersave(); // 회원 정보 저장 함수
void videoload(); // 비디오 정보 불러오는 함수
void memberload(); // 회원 정보 불러오는 함수
void randomid(char* id); // 회원 id랜덤하게 만드는 함수
void randomvideonumber(char* videonumber); // 비디오 고유번호 랜덤하게 만드는 함수
void memberdelete(); // 회원 정보 삭제함수
void videodelete(); // 비디오 정보 삭제함수
void videoreturn(); // 반납함수
void videoedit(); // 비디오 정보 수정함수
void memberedit(); // 회원 정보 수정함수

#endif