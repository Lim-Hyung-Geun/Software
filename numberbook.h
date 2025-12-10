#pragma once // 헤더파일 중복 방지
#define _CRT_SECURE_NO_WARNINGS
#ifndef NUMBERBOOK_H // 헤더가드로써 오류를 방지함
#define NUMBERBOOK_H

#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 

typedef struct {
    char name[12];
    char age[3];
    char number[14];
    char gender[3];
} address;

// 전역 변수 선언에 타입 추가
extern int n;       // 연락처 개수
extern int size;     // 현재 배열 크기
extern address* telephone;  // 동적 메모리를 가리킬 포인터

// 함수 선언
void add();
void edit();
void deletenumber();
void search();
void print();
void save();
void load();

#endif