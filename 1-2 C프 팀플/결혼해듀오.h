#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#pragma warning(disable:4996)
#define INSERT      1 //�����Է¸޴�
#define MANAGE      2 //�����޴�
#define OUTLINE      3 //��ü����
#define SEARCH      4 //�˻�
#define INITIALIZE   5 //�ʱ�ȭ
#define SAVE      6 //�ܺ����Ͽ� ����
#define LOAD      7 //�ܺ����Ͽ��� �ҷ�����
#define ABOUT      8 //����
#define EXIT      9

#define ARROW   1
#define NONE   0

#define LEFT   75
#define RIGHT   77
#define UP      72
#define DOWN   80
#define ENTER   13

#define YES   1
#define   NO   2

#define NAME   1
#define GENDER   2
#define AGE      3
#define JOB      4
#define ANN_INC   5
#define ACD_ABL   6
#define QUIT   7

typedef struct _ListNode {
	char strName[40];
	int nGender;
	int nAge;
	int nJob;
	int nAnnualIncome;
	int nAcademicAbility;
	struct _ListNode *link;
}ListNode;

ListNode *pHeader;

//==========================================
int displayMainMenu();

//1
void insertMenu();
void insertData(ListNode *pData);
//2
void manageMenu();
void deleteData(int nDelIndex);
void modifyData(int nModiIndex);
void askDelModi(int nDataAction);

void printData();
//3
void outlineMenu();
void arrangeData(int flag);
//4
void searchMenu();
void checkCondition();
//5
void initializeMenu();
//6
void outputFileMenu();
//7
void inputFileMenu();
//8
void about();

int key_shift(int flag, int min_x, int min_y, int max_x, int max_y, int tab_x, int tab_y);
void gotoxy(int x, int y);

