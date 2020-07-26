#include <stdio.h>	//printf, scanf등 기본적인 함수를 사용하기 위해 추가한 stdio.h
#include <stdlib.h>	// system, exit함수등을 사용하기 위해 추가한 stdlib.h
#include <conio.h>	//getch함수를 사용하기 위해 추가한 conio.h
#include <Windows.h>	//gotoxy함수를 사용하기 위해 추가한 Windows.h
#include <string.h>		//strcmp함수를 사용하기 위해 추가한 string.h
#include <malloc.h>		//새로운 노드를 생성하고 연결해주기 위해선 먼저 동적메모리 할당을 해줘야 하는데, 이 때 사용되는 함수 malloc을 사용하기 위해 추가한 malloc.h
// DISPLAYMAIN MENU CONSTANT 
#define INSERT		1	//회원 정보 삽입메뉴 진입을 위한 상수 
#define MANAGE		2	//회원 정보 수정, 삭제를 위해 거쳐가는 정보관리로 진입하기 위한 상수
#define OUTLINE		3	//회원 정보 전체를 보고 정렬하기 위해 거쳐가는 전체보기로 진입하기 위한 상수
#define SEARCH		4	//특정한 조건에 부합하는 조건을 찾기 위해 거쳐가는 대상찾기로 진입하기 위한 상수
#define INITIALIZE	5	//회원 정보 전체를 초기화 시키는 초기화로 진입하기 위한 상수
#define SAVE		6	//회원 정보를 저장하기 위한 내보내기 메뉴로 진입하기 위한 상수
#define LOAD		7	//회원 정보를 프로그램 내부로 불러들이기 위한 메뉴로 진입하기 위한 상수 
#define ABOUT		8	//개발 정보로 진입하기 위한 상수
#define EXIT		9	//프로그램을 종료하기 위해 이용되는 상수

// KEY_SHIFT FUNCTION CONSTANT
#define VERTICAL	0	//방향키가 좌,우로만 움직일 때 
#define HORIZONTAL	1	//방향키가 위,아래로만 움직일 때 좌,우로 움직이면 인덱스가 

// DISPLAYMAIN MENU CONSTANT
#define TRUE	1	// 반복문 등에서 루프를 만드는 상수 
#define FALSE	0	// 반복문을 탈출하게 만드는 상수
// KEY_SHIFT CONSTANT
#define LEFT	75	//방향키가 왼쪽으로 움직일 때 아스키코드 값을 getch()를 통해 받아져서 변수에 저장되게 되는데 이 때 75란 아스키코드값의 숫자를 RIGHT라고 정의함
#define RIGHT	77	//방향키가 오른쪽으로 움직일 때 아스키코드 상수값 77을 RIGHT로 정의함
#define UP		72	//위쪽으로 움직일 때 아스키코드 상수값 72를 UP으로 정의함
#define DOWN	80	//아래쪽으로 움직일 때 아스키코드 상수값 80을 DOWN으로 정의함
#define ENTER	13	//메뉴에 진입하거나 선택을 하가 위해 엔터를 쳤을 때의 상수값 13을 ENTER로 정의함
// CHOICE CONSTANT - 각 메뉴에서 실행 여부를 재확인 할 때 사용되는 상수
#define YES	1	// 중요한 작업인 경우 실행 여부를 재확인 하는데, 계속 진행하기 원할 때를 1로 하고, 그것을 YES로 정의함. 
#define	NO	2	// 다시 돌아가고 싶을 때를 2로 하고, 그것을 NO로 정의함.
//	MANAGEMENT MENU CONSTANT
#define MALE	1	// 남자를 나타내는 1번을 MALE로 정의
#define FEMALE	2	// 여자를 나타내는 2번을 FEMALE로 정의

#define SAME	0	// 정보 관리를 위해 관리할 사용자의 이름을 먼저 받을 때 그 사용자와 이름이 같으면 관리하도록 한다. 이 때 사용되는 상수.
//	MODIFY MENU CONSTANT - 사용자의 정보를 수정할 때 인덱스 값을 받는데, 알아보기 쉽게 상수로 정의함.
#define NAME	1	// 이름 수정 시 사용되는 상수
#define GENDER	2	// 성별 수정 시 사용되는 상수 
#define AGE		3	// 나이 수정 시 사용되는 상수
#define JOB		4	// 작업 수정 시 사용되는 상수
#define ANN_INC	5	// 연봉 수정 시 사용되는 상수
#define ACD_ABL	6	// 학력 수정 시 사용되는 상수
#define QUIT	7	// MODIFYMENU를 벗어날 때 사용되는 상수

#define SELECTED	1
#define NONE		0

/*
	연결리스트 형태로 데이터를 만들어 줄 구조체를 선언하고 자기참조형 포인터 구조체를 필드에 두어
	리스트간 연결을 가능하게 했음.
	<<singly linked list>>

*/
typedef struct _ListNode{
	char strName[40];	//회원 이름 저장
	int nGender;	//회원 성별 저장, key_shift함수를 통해 커서를 움직여 int값으로 저장함
	int nAge;		//회원 나이 저장
	int nJob;		//회원 직업 저장, key_shift함수를 통해 커서를 움직여 int값으로 저장함
	int nAnnualIncome;		//회원 연평균 소득 저장
	int nAcademicAbility;	//회원 최종학력 저장, key_shift함수를 통해 커서를 움직여 int값으로 저장함
	struct _ListNode *link;	//노드간의 연결을 위한 자기참조 구조체 포인터
}ListNode;

ListNode *pHeader;	/*
					첫 번째 노드를 가리키는 헤더포인터를 Global Scope로 선언.
					이로써 어느 곳에서나 이 헤더포인터를 이용할 수 있고 첫번째 노드를 가리켜 연결리스트의
					시작을 알리는 단서가 됨.
					*/

/*
특정 조건을 검색하는 search메뉴를 구현하기 위한 구조체. 각각의 기준이 될만한 변수들이 구조체 안의
필드로서 선언되어있음. 이것을 기반으로 checkcondition 구현.
*/
typedef struct _Search{
	int nGender;	// 사용자가 원하는 상대방의 성별 정보 저장
	int nMinAge;	// 사용자가 원하는 상대방의 최소 나이 저장
	int nMaxAge;	// 사용자가 원하는 상대방의 최대 나이 저장
	int nJob[11];	//	사용자가 원하는 상대방의 직업 조건 저장
	int nAnnualIncome;		// 사용자가 원하는 상대방의 연 평균 소득의 최소값 저장
	int nAcademicAbility;	// 사용자가 원하는 상대방의 최소 학력 저장
}Search;



////////////////////DECLARATION OF FUNCTIONS///////////////////

int displayMainMenu();
/*
	function name >> displayMainMenu
	precondition >> none
	postcondition >> nMenu(return data type - int)
	 : displayMainMenu함수는 사용자에게 메인메뉴를 보여주는 함수로서,
	 사용자는 displayMainMenu에서 nMenu라는 변수에 사용자가 접근하고 싶은 메뉴번호를 keyshift함수를 이용해 저장함.
	 이것이 return 되어 main함수의 nSelectedMainMenu에 대입됨. nMenu가 대입된 nSelectedMainMenu를 통해
	 사용자가 선택한 메뉴와 관련된 함수를 호출함.

*/


//1
void insertMenu();
/*
	function name >> insertMenu
	precondition >> none
	postcondition >> none
	: 관리할 회원 정보를 입력받아 노드에 저장시켜주는 insertMenu함수이다. 이름, 성별, 나이, 직업, 연봉, 학력을 받는다.
*/
void insertData(ListNode *pData);
/*
	function name >> insertData
	precondition >> pData (data type - Listnode / pointer)
	postcondition >> none
	: 구조체 포인터 pData를 insertMenu로부터 파라미터로 전달받아서 "이름 순"으로 ordered로 정렬/연결해주는 함수.
	다른 함수에서도 이용하기 위해 기존의 pData를 동적메모리할당한 뒤 입력받은 내용을 insertMenu로 올렸다.

*/
//2
void manageMenu();
/*
	function name >> manageMenu
	precondition >> none
	postcondition >> none
	: 저장된 데이터를 기반으로하여 이름을 받고, 해당 이름을 가진 회원의 정보를 모두 출력하여 수정 또는 삭제를 
	하게 도와주는 함수이다. key_shift를 통해 중복되는 회원 간/ 또는 단일 회원 이동을 하고, 
	그 회원을 선택했을 때 수정과 삭제를 할 수 있다.

*/
int askMenu();
/*
	function name >> askMenu
	precondition >> none
	postcondition >> nMenu (data type - int) : 실행 메뉴의 번호를 저장하는 변수
	: manageMenu에서 관리할 회원 정보를 선택하면, 삭제할 것인지 수정할 것인지를 묻고 사용자가 선택한 작업을 하게 도와주는 함수.
	실행 번호를 다시 manageMenu로 보내 그 안에서 분기로서 switch 문으로 실행한다. (displayMainMenu와 main함수의 관계 처럼) 
*/
void deleteMenu(int nPosition);
/*
	function name >> deleteMenu
	precondition >> nPosition (data type - int) : 노드의 위치를 저장하는 변수
	postcondition >> none
	: 사용자에게 정말 정보삭제를 할 것인지대해 실행 여부를 다시 묻고, 
	진행하겠다고 하면 deleteData를 호출하여 원하는 회원 정보를 삭제할 수 있게 하는 함수.  
	이 때 deleteMenu에서 nPosition을 받는 것은 deleteData함수에 전달하기 위함.
*/
void deleteData(int nPosition);
/*
	function name >> deleteData
	precondition >> nPosition (data type - int) : 노드의 위치를 저장하는 변수
	postcondition >> none
	: deleteMenu에 의해서 호출 된 deleteData는 사용자가 삭제하길 원하는 정보에 접근하여 (위치값으로) 삭제하게 하는 함수이다.
*/
void modifyMenu(int nPosition);
/*	
	function name >> modifyMenu 
	precondition >> nPosition (data type - int) : 노드의 위치를 저장하는 변수
	postcondition >> none
	: 프로그램 상에 저장되어있는 정보를 수정할 수 있도록 도와주는 함수.
	기본적인 출력폼과 함께 파라미터로 받은 nPosition에 의해 수정하기로 선택했던 데이터 1개를 출력하고
	좌우로 움직일 수 있게 된다. 
	단, 이름수정은 우리가 처음에 ordered방식으로 삽입하였기 때문에 따로 처리하고 값이 달라져도 상관이 없는 나머지는 
	modifyData함수를 사용해서 넘긴다. 


*/
void modifyData(int nPosition, int nCategory);
/*
	function name >> modifyData
	precondition >> nPosition , nCategory (data type - int) : nPosition은 노드의 위치를 저장하는 변수
															  nCategory는 수정하고 싶은 항목을 저장하는 변수
	postcondition >> none
	: 이름을 제외한 나머지 정보를 수정하기 위해 사용하는 함수.
	파라미터로 받은 nPosition을 통해 수정할 노드를 찾고, nCategory를 통해 이름을 제외한 데이터 필드에서 
	수정하고 싶은 것만을 수정해줌.
*/


//3
void outlineMenu();
/*
	function name >> outlineMenu
	precondition >> none
	postcondition >> none
	: 프로그램 내에 저장된 회원들의 정보를 처음부터 끝까지 모두 출력하는 메뉴.
	위의 출력폼에 이름, 성별, 나이, 직업, 연봉, 학력, 나가기가 되어있는데,
	key_shift함수로 커서를 움직여서 원하는 기준으로 오름차순 정렬을 하도록 만듦. (arrangeData 호출) 

*/
int arrangeData(int flag);
/*
	function name >> arrangeData
	precondition >> flag (data type - int) : 이름, 성별, 나이, 직업, 연봉 등 정렬해서 보고 싶은 것의 인덱스를 저장하는 변수.
	postcondition >> bRearrangeflag (data type - int) : 현재 리스트가 이름순이 아닌 다른 순서로 정렬되어 다시 이름 오름차순으로 정렬이 필요함을
	                                                    저장하는 변수. 이것을 통해 outlineMenu에서 끝내기 전에 다시 이름 오름차순으로 정렬시켜줌.
	: 사용자가 SearchMenu에서 전달해준 flag를 기반으로 하여, 처음 선택하면 정순, 다시 선택하면 역순으로 리스트를 재정렬 하는 함수
*/

//4 
void searchMenu();
/*
	function name >> searchMenu
	precondition >> none
	postcondition >> none
	: 사용자가 조건에 해당하는 사람만을 출력하여 보기 위해서 원하는 사람의 자격 요건을 받는 함수.
	이 자격요건은 구조체 Data에 저장되어 checkCondition으로 전달되고, 실질적인 필터링은 checkCondition
	에서 이루어진다.
*/
void checkCondition(Search Data);
/*
function name >> checkCondition
precondition >> Data (data type - Search) : 사용자가 원하는 사람의 자격 요건을 저장하고 있는 구조체를 파라미터로 받음.
postcondition >> none
: 사용자가 원하는 사람의 자격 요건을 저장하고 있는 Data구조체를 Search함수로 부터 받은 뒤, 이를 기반으로 하여 조건을 만족하는
대상의 정보를 출력하는 함수.
*/


//5
void initializeMenu();
/*
	function name : initialize Menu
	precondition : none
	postcondition : none
	:프로그램(메모리)상에 저장되어있는 데이터를 초기화 해주는 함수.

*/


//6
void outputFileMenu();
/*
	function name >> outputFileName
	precondition >> none
	postcondition >> none
	: 파일형태로 저장되어있는 회원정보를 프로그램으로 불러오는 함수.
	저장된 회원정보로 수정, 삭제, 정렬 등의 관리를 할 수 있다.
	
*/

//7
void inputFileMenu();
/*
	function name >> inputFileMenu
	precondition >> none
	postcondition >> none
	: 프로그램 내부에 생성되어 있는 회원정보를 파일에 저장하기 위해 만든 함수
*/

//8
void about();
/*	
	function name >> about
	precondition >> none
	postcondition >> none
	: 제작자 정보와 프로그램 정보를 출력하는 함수.
*/
void printData(int nPosition);
/*
	function name >> printData
	precondition >> nPosition (data type - int) : 노드의 위치를 저장하는 변수
	postcondition >> none
	: 노드의 위치값(현재의 경우 0부터 시작)을 보내주어 그 위치값에 해당하는 노드 1개만
	출력해주는 함수 printData로, manageMenu, deleteData, updateData, outlineMenu 등
	여러 함수에서 사용된다.
	다른 함수에서 이것을 호출할 땐 반복문을 통해 position값을 하나씩 증가시키면서 호출한다.

*/

int key_shift(int flag, int min_x, int min_y, int max_x, int max_y, int tab_x, int tab_y, int nIndex);
/*
	function name >> key_shift
	precondition >> flag	- flag엔 두 종류가 있음
							1.HORIZONTAL 좌, 우로만 움직이고 커서 표시 방법이 [    ] 
							2.VERTICAL 수직으로만 움직이고 커서 표시 방법이 ->
							* 좌, 우로만 움직이거나 수직으로만 움직여야 할 경우 각각 수직, 좌우로 방향키를 움직였을 때 nIndex가 변하는 현상을 이것으로 보완*
					min_x	- x좌표의 최소값
					min_y	- y좌표의 최소값
					max_x	- x좌표의 최대값
					max_y	- y좌표의 최대값
					tab_x	- x방향으로 이동 시 이동하는 커서의 간격
					tab_y	- y방향으로 이동 시 이동하는 커서의 간격
					nIndex	- 시작하는 인덱스의 숫자
								(modifyMenu에서 사용. 우리는 modifyMenu에서 수정, 삭제할 사용자의 이름을 받고 그 사용자가 있는 노드를 출력해주어야 한다.
								노드의 출력방식을 위치값을 받아 해야하는데, 만약 이주연, 정예지, 정예지, 정예지를 입력했다고 생각해보자.
								이 때 정예지를 치면 1번 인덱스부터 3번 인덱스까지 (우리 프로그램에서 첫노드의 인덱스는 0번으로 정했다.)출력이 되고
								여기서 삭제, 수정을 담당하는 함수에 포지션을 전달하게 된다. 이 포지션은 key_shift함수에서 리턴되는 인덱스 값인데, 
								문제는 내가 만약 정예지를 검색해서 3명 중 맨 위의 정예지를 골랐다고 치면 key_shift는 1을 반환하게 된다. 이게 수정, 삭제
								함수로 전달되고 거기서 printData를 또 호출하여 그 값을 전달하는데 그렇게 되면 
								삭제나 수정과정에서 이민주가 출력되어 오류가 생긴다. 애초에 key_shift함수는 인덱스의 시작을 1로 설정하였기 때문에
								발생하는 오류다. 따라서 이 오류를 수정하기 위해 파라미터로 시작 인덱스를 받아주었다.

					** data type - 모두 int **




	postcondition >> nIndex 
	(return data type - int) : 어떠한 작업을 수행할 때 이 수행되는 번호가 nIndex에 저장.
								커서를 움직일 때 마다 증감연산자로 계산.
								이것이 리턴되면 nIndex에 따라서 작업 수행

	: 기존의 프로그램이 메뉴의 숫자번호를 받아 메뉴에 진입했던 것과는 달리, 우리는 key_shift함수를 이용하여 프로그램의 모든 제어를 할 계획이다.
	 방향키의 움직임에 따라 커서를 조정시켜 메뉴의 실행을 도와주는 함수이다.

*/
void gotoxy(int x, int y);
/*
	function name >> gotoxy
	precondition >> x, y (data type - int) : 이동할 x, y좌표값을 저장하는 변수
	postcondition >> none
	: key_shift함수에서 누른 방향키에 따라 커서가 움직이는데, 이 때 커서의 위치를 바꿔주는 함수이다.

*/