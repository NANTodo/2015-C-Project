#include <stdio.h>	//printf, scanf�� �⺻���� �Լ��� ����ϱ� ���� �߰��� stdio.h
#include <stdlib.h>	// system, exit�Լ����� ����ϱ� ���� �߰��� stdlib.h
#include <conio.h>	//getch�Լ��� ����ϱ� ���� �߰��� conio.h
#include <Windows.h>	//gotoxy�Լ��� ����ϱ� ���� �߰��� Windows.h
#include <string.h>		//strcmp�Լ��� ����ϱ� ���� �߰��� string.h
#include <malloc.h>		//���ο� ��带 �����ϰ� �������ֱ� ���ؼ� ���� �����޸� �Ҵ��� ����� �ϴµ�, �� �� ���Ǵ� �Լ� malloc�� ����ϱ� ���� �߰��� malloc.h
// DISPLAYMAIN MENU CONSTANT 
#define INSERT		1	//ȸ�� ���� ���Ը޴� ������ ���� ��� 
#define MANAGE		2	//ȸ�� ���� ����, ������ ���� ���İ��� ���������� �����ϱ� ���� ���
#define OUTLINE		3	//ȸ�� ���� ��ü�� ���� �����ϱ� ���� ���İ��� ��ü����� �����ϱ� ���� ���
#define SEARCH		4	//Ư���� ���ǿ� �����ϴ� ������ ã�� ���� ���İ��� ���ã��� �����ϱ� ���� ���
#define INITIALIZE	5	//ȸ�� ���� ��ü�� �ʱ�ȭ ��Ű�� �ʱ�ȭ�� �����ϱ� ���� ���
#define SAVE		6	//ȸ�� ������ �����ϱ� ���� �������� �޴��� �����ϱ� ���� ���
#define LOAD		7	//ȸ�� ������ ���α׷� ���η� �ҷ����̱� ���� �޴��� �����ϱ� ���� ��� 
#define ABOUT		8	//���� ������ �����ϱ� ���� ���
#define EXIT		9	//���α׷��� �����ϱ� ���� �̿�Ǵ� ���

// KEY_SHIFT FUNCTION CONSTANT
#define VERTICAL	0	//����Ű�� ��,��θ� ������ �� 
#define HORIZONTAL	1	//����Ű�� ��,�Ʒ��θ� ������ �� ��,��� �����̸� �ε����� 

// DISPLAYMAIN MENU CONSTANT
#define TRUE	1	// �ݺ��� ��� ������ ����� ��� 
#define FALSE	0	// �ݺ����� Ż���ϰ� ����� ���
// KEY_SHIFT CONSTANT
#define LEFT	75	//����Ű�� �������� ������ �� �ƽ�Ű�ڵ� ���� getch()�� ���� �޾����� ������ ����ǰ� �Ǵµ� �� �� 75�� �ƽ�Ű�ڵ尪�� ���ڸ� RIGHT��� ������
#define RIGHT	77	//����Ű�� ���������� ������ �� �ƽ�Ű�ڵ� ����� 77�� RIGHT�� ������
#define UP		72	//�������� ������ �� �ƽ�Ű�ڵ� ����� 72�� UP���� ������
#define DOWN	80	//�Ʒ������� ������ �� �ƽ�Ű�ڵ� ����� 80�� DOWN���� ������
#define ENTER	13	//�޴��� �����ϰų� ������ �ϰ� ���� ���͸� ���� ���� ����� 13�� ENTER�� ������
// CHOICE CONSTANT - �� �޴����� ���� ���θ� ��Ȯ�� �� �� ���Ǵ� ���
#define YES	1	// �߿��� �۾��� ��� ���� ���θ� ��Ȯ�� �ϴµ�, ��� �����ϱ� ���� ���� 1�� �ϰ�, �װ��� YES�� ������. 
#define	NO	2	// �ٽ� ���ư��� ���� ���� 2�� �ϰ�, �װ��� NO�� ������.
//	MANAGEMENT MENU CONSTANT
#define MALE	1	// ���ڸ� ��Ÿ���� 1���� MALE�� ����
#define FEMALE	2	// ���ڸ� ��Ÿ���� 2���� FEMALE�� ����

#define SAME	0	// ���� ������ ���� ������ ������� �̸��� ���� ���� �� �� ����ڿ� �̸��� ������ �����ϵ��� �Ѵ�. �� �� ���Ǵ� ���.
//	MODIFY MENU CONSTANT - ������� ������ ������ �� �ε��� ���� �޴µ�, �˾ƺ��� ���� ����� ������.
#define NAME	1	// �̸� ���� �� ���Ǵ� ���
#define GENDER	2	// ���� ���� �� ���Ǵ� ��� 
#define AGE		3	// ���� ���� �� ���Ǵ� ���
#define JOB		4	// �۾� ���� �� ���Ǵ� ���
#define ANN_INC	5	// ���� ���� �� ���Ǵ� ���
#define ACD_ABL	6	// �з� ���� �� ���Ǵ� ���
#define QUIT	7	// MODIFYMENU�� ��� �� ���Ǵ� ���

#define SELECTED	1
#define NONE		0

/*
	���Ḯ��Ʈ ���·� �����͸� ����� �� ����ü�� �����ϰ� �ڱ������� ������ ����ü�� �ʵ忡 �ξ�
	����Ʈ�� ������ �����ϰ� ����.
	<<singly linked list>>

*/
typedef struct _ListNode{
	char strName[40];	//ȸ�� �̸� ����
	int nGender;	//ȸ�� ���� ����, key_shift�Լ��� ���� Ŀ���� ������ int������ ������
	int nAge;		//ȸ�� ���� ����
	int nJob;		//ȸ�� ���� ����, key_shift�Լ��� ���� Ŀ���� ������ int������ ������
	int nAnnualIncome;		//ȸ�� ����� �ҵ� ����
	int nAcademicAbility;	//ȸ�� �����з� ����, key_shift�Լ��� ���� Ŀ���� ������ int������ ������
	struct _ListNode *link;	//��尣�� ������ ���� �ڱ����� ����ü ������
}ListNode;

ListNode *pHeader;	/*
					ù ��° ��带 ����Ű�� ��������͸� Global Scope�� ����.
					�̷ν� ��� �������� �� ��������͸� �̿��� �� �ְ� ù��° ��带 ������ ���Ḯ��Ʈ��
					������ �˸��� �ܼ��� ��.
					*/

/*
Ư�� ������ �˻��ϴ� search�޴��� �����ϱ� ���� ����ü. ������ ������ �ɸ��� �������� ����ü ����
�ʵ�μ� ����Ǿ�����. �̰��� ������� checkcondition ����.
*/
typedef struct _Search{
	int nGender;	// ����ڰ� ���ϴ� ������ ���� ���� ����
	int nMinAge;	// ����ڰ� ���ϴ� ������ �ּ� ���� ����
	int nMaxAge;	// ����ڰ� ���ϴ� ������ �ִ� ���� ����
	int nJob[11];	//	����ڰ� ���ϴ� ������ ���� ���� ����
	int nAnnualIncome;		// ����ڰ� ���ϴ� ������ �� ��� �ҵ��� �ּҰ� ����
	int nAcademicAbility;	// ����ڰ� ���ϴ� ������ �ּ� �з� ����
}Search;



////////////////////DECLARATION OF FUNCTIONS///////////////////

int displayMainMenu();
/*
	function name >> displayMainMenu
	precondition >> none
	postcondition >> nMenu(return data type - int)
	 : displayMainMenu�Լ��� ����ڿ��� ���θ޴��� �����ִ� �Լ��μ�,
	 ����ڴ� displayMainMenu���� nMenu��� ������ ����ڰ� �����ϰ� ���� �޴���ȣ�� keyshift�Լ��� �̿��� ������.
	 �̰��� return �Ǿ� main�Լ��� nSelectedMainMenu�� ���Ե�. nMenu�� ���Ե� nSelectedMainMenu�� ����
	 ����ڰ� ������ �޴��� ���õ� �Լ��� ȣ����.

*/


//1
void insertMenu();
/*
	function name >> insertMenu
	precondition >> none
	postcondition >> none
	: ������ ȸ�� ������ �Է¹޾� ��忡 ��������ִ� insertMenu�Լ��̴�. �̸�, ����, ����, ����, ����, �з��� �޴´�.
*/
void insertData(ListNode *pData);
/*
	function name >> insertData
	precondition >> pData (data type - Listnode / pointer)
	postcondition >> none
	: ����ü ������ pData�� insertMenu�κ��� �Ķ���ͷ� ���޹޾Ƽ� "�̸� ��"���� ordered�� ����/�������ִ� �Լ�.
	�ٸ� �Լ������� �̿��ϱ� ���� ������ pData�� �����޸��Ҵ��� �� �Է¹��� ������ insertMenu�� �÷ȴ�.

*/
//2
void manageMenu();
/*
	function name >> manageMenu
	precondition >> none
	postcondition >> none
	: ����� �����͸� ��������Ͽ� �̸��� �ް�, �ش� �̸��� ���� ȸ���� ������ ��� ����Ͽ� ���� �Ǵ� ������ 
	�ϰ� �����ִ� �Լ��̴�. key_shift�� ���� �ߺ��Ǵ� ȸ�� ��/ �Ǵ� ���� ȸ�� �̵��� �ϰ�, 
	�� ȸ���� �������� �� ������ ������ �� �� �ִ�.

*/
int askMenu();
/*
	function name >> askMenu
	precondition >> none
	postcondition >> nMenu (data type - int) : ���� �޴��� ��ȣ�� �����ϴ� ����
	: manageMenu���� ������ ȸ�� ������ �����ϸ�, ������ ������ ������ �������� ���� ����ڰ� ������ �۾��� �ϰ� �����ִ� �Լ�.
	���� ��ȣ�� �ٽ� manageMenu�� ���� �� �ȿ��� �б�μ� switch ������ �����Ѵ�. (displayMainMenu�� main�Լ��� ���� ó��) 
*/
void deleteMenu(int nPosition);
/*
	function name >> deleteMenu
	precondition >> nPosition (data type - int) : ����� ��ġ�� �����ϴ� ����
	postcondition >> none
	: ����ڿ��� ���� ���������� �� ���������� ���� ���θ� �ٽ� ����, 
	�����ϰڴٰ� �ϸ� deleteData�� ȣ���Ͽ� ���ϴ� ȸ�� ������ ������ �� �ְ� �ϴ� �Լ�.  
	�� �� deleteMenu���� nPosition�� �޴� ���� deleteData�Լ��� �����ϱ� ����.
*/
void deleteData(int nPosition);
/*
	function name >> deleteData
	precondition >> nPosition (data type - int) : ����� ��ġ�� �����ϴ� ����
	postcondition >> none
	: deleteMenu�� ���ؼ� ȣ�� �� deleteData�� ����ڰ� �����ϱ� ���ϴ� ������ �����Ͽ� (��ġ������) �����ϰ� �ϴ� �Լ��̴�.
*/
void modifyMenu(int nPosition);
/*	
	function name >> modifyMenu 
	precondition >> nPosition (data type - int) : ����� ��ġ�� �����ϴ� ����
	postcondition >> none
	: ���α׷� �� ����Ǿ��ִ� ������ ������ �� �ֵ��� �����ִ� �Լ�.
	�⺻���� ������� �Բ� �Ķ���ͷ� ���� nPosition�� ���� �����ϱ�� �����ߴ� ������ 1���� ����ϰ�
	�¿�� ������ �� �ְ� �ȴ�. 
	��, �̸������� �츮�� ó���� ordered������� �����Ͽ��� ������ ���� ó���ϰ� ���� �޶����� ����� ���� �������� 
	modifyData�Լ��� ����ؼ� �ѱ��. 


*/
void modifyData(int nPosition, int nCategory);
/*
	function name >> modifyData
	precondition >> nPosition , nCategory (data type - int) : nPosition�� ����� ��ġ�� �����ϴ� ����
															  nCategory�� �����ϰ� ���� �׸��� �����ϴ� ����
	postcondition >> none
	: �̸��� ������ ������ ������ �����ϱ� ���� ����ϴ� �Լ�.
	�Ķ���ͷ� ���� nPosition�� ���� ������ ��带 ã��, nCategory�� ���� �̸��� ������ ������ �ʵ忡�� 
	�����ϰ� ���� �͸��� ��������.
*/


//3
void outlineMenu();
/*
	function name >> outlineMenu
	precondition >> none
	postcondition >> none
	: ���α׷� ���� ����� ȸ������ ������ ó������ ������ ��� ����ϴ� �޴�.
	���� ������� �̸�, ����, ����, ����, ����, �з�, �����Ⱑ �Ǿ��ִµ�,
	key_shift�Լ��� Ŀ���� �������� ���ϴ� �������� �������� ������ �ϵ��� ����. (arrangeData ȣ��) 

*/
int arrangeData(int flag);
/*
	function name >> arrangeData
	precondition >> flag (data type - int) : �̸�, ����, ����, ����, ���� �� �����ؼ� ���� ���� ���� �ε����� �����ϴ� ����.
	postcondition >> bRearrangeflag (data type - int) : ���� ����Ʈ�� �̸����� �ƴ� �ٸ� ������ ���ĵǾ� �ٽ� �̸� ������������ ������ �ʿ�����
	                                                    �����ϴ� ����. �̰��� ���� outlineMenu���� ������ ���� �ٽ� �̸� ������������ ���Ľ�����.
	: ����ڰ� SearchMenu���� �������� flag�� ������� �Ͽ�, ó�� �����ϸ� ����, �ٽ� �����ϸ� �������� ����Ʈ�� ������ �ϴ� �Լ�
*/

//4 
void searchMenu();
/*
	function name >> searchMenu
	precondition >> none
	postcondition >> none
	: ����ڰ� ���ǿ� �ش��ϴ� ������� ����Ͽ� ���� ���ؼ� ���ϴ� ����� �ڰ� ����� �޴� �Լ�.
	�� �ڰݿ���� ����ü Data�� ����Ǿ� checkCondition���� ���޵ǰ�, �������� ���͸��� checkCondition
	���� �̷������.
*/
void checkCondition(Search Data);
/*
function name >> checkCondition
precondition >> Data (data type - Search) : ����ڰ� ���ϴ� ����� �ڰ� ����� �����ϰ� �ִ� ����ü�� �Ķ���ͷ� ����.
postcondition >> none
: ����ڰ� ���ϴ� ����� �ڰ� ����� �����ϰ� �ִ� Data����ü�� Search�Լ��� ���� ���� ��, �̸� ������� �Ͽ� ������ �����ϴ�
����� ������ ����ϴ� �Լ�.
*/


//5
void initializeMenu();
/*
	function name : initialize Menu
	precondition : none
	postcondition : none
	:���α׷�(�޸�)�� ����Ǿ��ִ� �����͸� �ʱ�ȭ ���ִ� �Լ�.

*/


//6
void outputFileMenu();
/*
	function name >> outputFileName
	precondition >> none
	postcondition >> none
	: �������·� ����Ǿ��ִ� ȸ�������� ���α׷����� �ҷ����� �Լ�.
	����� ȸ�������� ����, ����, ���� ���� ������ �� �� �ִ�.
	
*/

//7
void inputFileMenu();
/*
	function name >> inputFileMenu
	precondition >> none
	postcondition >> none
	: ���α׷� ���ο� �����Ǿ� �ִ� ȸ�������� ���Ͽ� �����ϱ� ���� ���� �Լ�
*/

//8
void about();
/*	
	function name >> about
	precondition >> none
	postcondition >> none
	: ������ ������ ���α׷� ������ ����ϴ� �Լ�.
*/
void printData(int nPosition);
/*
	function name >> printData
	precondition >> nPosition (data type - int) : ����� ��ġ�� �����ϴ� ����
	postcondition >> none
	: ����� ��ġ��(������ ��� 0���� ����)�� �����־� �� ��ġ���� �ش��ϴ� ��� 1����
	������ִ� �Լ� printData��, manageMenu, deleteData, updateData, outlineMenu ��
	���� �Լ����� ���ȴ�.
	�ٸ� �Լ����� �̰��� ȣ���� �� �ݺ����� ���� position���� �ϳ��� ������Ű�鼭 ȣ���Ѵ�.

*/

int key_shift(int flag, int min_x, int min_y, int max_x, int max_y, int tab_x, int tab_y, int nIndex);
/*
	function name >> key_shift
	precondition >> flag	- flag�� �� ������ ����
							1.HORIZONTAL ��, ��θ� �����̰� Ŀ�� ǥ�� ����� [    ] 
							2.VERTICAL �������θ� �����̰� Ŀ�� ǥ�� ����� ->
							* ��, ��θ� �����̰ų� �������θ� �������� �� ��� ���� ����, �¿�� ����Ű�� �������� �� nIndex�� ���ϴ� ������ �̰����� ����*
					min_x	- x��ǥ�� �ּҰ�
					min_y	- y��ǥ�� �ּҰ�
					max_x	- x��ǥ�� �ִ밪
					max_y	- y��ǥ�� �ִ밪
					tab_x	- x�������� �̵� �� �̵��ϴ� Ŀ���� ����
					tab_y	- y�������� �̵� �� �̵��ϴ� Ŀ���� ����
					nIndex	- �����ϴ� �ε����� ����
								(modifyMenu���� ���. �츮�� modifyMenu���� ����, ������ ������� �̸��� �ް� �� ����ڰ� �ִ� ��带 ������־�� �Ѵ�.
								����� ��¹���� ��ġ���� �޾� �ؾ��ϴµ�, ���� ���ֿ�, ������, ������, �������� �Է��ߴٰ� �����غ���.
								�� �� �������� ġ�� 1�� �ε������� 3�� �ε������� (�츮 ���α׷����� ù����� �ε����� 0������ ���ߴ�.)����� �ǰ�
								���⼭ ����, ������ ����ϴ� �Լ��� �������� �����ϰ� �ȴ�. �� �������� key_shift�Լ����� ���ϵǴ� �ε��� ���ε�, 
								������ ���� ���� �������� �˻��ؼ� 3�� �� �� ���� �������� ����ٰ� ġ�� key_shift�� 1�� ��ȯ�ϰ� �ȴ�. �̰� ����, ����
								�Լ��� ���޵ǰ� �ű⼭ printData�� �� ȣ���Ͽ� �� ���� �����ϴµ� �׷��� �Ǹ� 
								������ ������������ �̹��ְ� ��µǾ� ������ �����. ���ʿ� key_shift�Լ��� �ε����� ������ 1�� �����Ͽ��� ������
								�߻��ϴ� ������. ���� �� ������ �����ϱ� ���� �Ķ���ͷ� ���� �ε����� �޾��־���.

					** data type - ��� int **




	postcondition >> nIndex 
	(return data type - int) : ��� �۾��� ������ �� �� ����Ǵ� ��ȣ�� nIndex�� ����.
								Ŀ���� ������ �� ���� ���������ڷ� ���.
								�̰��� ���ϵǸ� nIndex�� ���� �۾� ����

	: ������ ���α׷��� �޴��� ���ڹ�ȣ�� �޾� �޴��� �����ߴ� �Ͱ��� �޸�, �츮�� key_shift�Լ��� �̿��Ͽ� ���α׷��� ��� ��� �� ��ȹ�̴�.
	 ����Ű�� �����ӿ� ���� Ŀ���� �������� �޴��� ������ �����ִ� �Լ��̴�.

*/
void gotoxy(int x, int y);
/*
	function name >> gotoxy
	precondition >> x, y (data type - int) : �̵��� x, y��ǥ���� �����ϴ� ����
	postcondition >> none
	: key_shift�Լ����� ���� ����Ű�� ���� Ŀ���� �����̴µ�, �� �� Ŀ���� ��ġ�� �ٲ��ִ� �Լ��̴�.

*/