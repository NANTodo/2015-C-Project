#include "결혼회사정보관리프로그램.h"
int main() {
	int bIterationFlag = TRUE;	// 사용자가 나가기 위해 EXIT로 커서를 이동하여 선택하기 전까지 반복문을 동작시키는 변수.(참값으로 초기화)
	int nSelectedMainMenu;	// 사용자가 선택한 메뉴의 번호를 저장하는 변수

	// 메뉴 선택 파트
	while(bIterationFlag) {
		nSelectedMainMenu = displayMainMenu();	/*displayMainMenu함수가 호출됨과 동시에 사용자는 메뉴 목록을 보며 선택할 수 있게 됨.
												이 때 keyshift로 커서를 이동하여 메뉴 번호를 받는데, 이것이 반환되어
												메인함수로 돌아옴으로써 각 메뉴와 관련된 함수가 실행됨.
												*/
		// 사용자가 원하는 메뉴 번호를 저장한 변수 nSelectedMainMenu를 분기로 하여 함수 실행.
		switch(nSelectedMainMenu) {
			case INSERT:	// 정보 입력을 원할 경우
				insertMenu();	//insertMenu() 호출
				break;
			
			case MANAGE:	// 정보 관리를 원할 경우
				manageMenu();	// manageMenu() 호출
				break;
				
			case OUTLINE:	// 관리중인 회원 정보 전체를 보고 싶을 때
				outlineMenu();	//outlineMenu() 호출
				break;
				
			case SEARCH:	// 특정한 조건을 가진 회원을 찾고 싶을 때
				searchMenu();	//searchMenu() 호출
				break;

			case INITIALIZE:	// 프로그램 상의 정보를 초기화하고 싶을 때
				initializeMenu();	//initializeMenu() 호출
				break;
				
			case SAVE:	// 프로그램 상의 회원정보들을 파일로 따로 저장하고 싶을 때
				outputFileMenu();	//outputFileMenu() 호출
				break;
				
			case LOAD:	// 파일에 저장 된 정보를 블러오고 싶을 때
				inputFileMenu();	//inputFileMenu() 호출
				break;
								
			case ABOUT:	// 제작자 정보를 보고싶을 경우
				about();	//about() 호출
				break;

			case EXIT:	// 프로그램을 종료하고 싶을 경우
				system("cls");
				printf("BYE-BYE\n");	//프로그램이 종료되었음을 알리는 메세지를 출력하고
				bIterationFlag = FALSE;		// 무한루프의 반복을 멈추며 프로그램 종료
				break;
		}//switch-case
	}//while

	return 0;
}//main()
int displayMainMenu() {
	int nMenu;		// 사용자가 선택한 메뉴값을 저장하는 변수. 후에 리턴되어 main함수로 향하고, 분기를 거쳐 각각의 메뉴에 해당하는 함수 호출.

	system("cls");		// 화면 지우기
	printf("==========================\n");
	printf(" 결혼회사정보관리프로그램 \n");
	printf("==========================\n");
	printf("   ○ 정보 입력\n");
	printf("   ○ 정보 관리\n");
	printf("   ○ 전체 보기\n");
	printf("   ○ 대상 검색\n");
	printf("   ○ 초기화\n");
	printf("   ○ 가져오기\n");
	printf("   ○ 내보내기\n");
	printf("   ○ 제작정보\n");
	printf("   ○ 나가기\n");
	printf("========================\n");		// 메뉴 목록, 기본 출력폼
	nMenu = key_shift(VERTICAL, 0, 3, 0, 11, 0, 1, 1);		/*메뉴 선택은 항상 key_shift를 기반으로 한 커서 이동방식으로 함.
															먼저, 수직으로만 이동할 것이므로 VERTICAL에 해당하는 상수를 파라미터로 보내고
															x최소좌표 0, y최소좌표 3, x최대좌표 0, y최대좌표 11, x이동 칸 수 0, y 이동 칸 수 1,
															시작 인덱스 1(보내주면 이것을 기반으로 해서 메뉴값등을 리턴)을 파라미터로 보냄.
															반환된 메뉴값이 사용자가 선택한 nMenu에 대입됨.*/

	return nMenu;	// nMenu가 반환되어 후에 main함수의 nSelectedMainMenu에 대입.
}// displayMainMenu()
void insertMenu() {
	ListNode *pData;	// 실질적인 회원 정보를 저장(동적 메모리 할당을 통해)하게 될 구조체 포인터 변수
	int nAnn_Inc, nAnn_Inc_big;		// 회원의 연봉 중 '억'에 해당하는 값을 저장하는 변수는 nAnn_Inc_big, '만'에 해당되는 숫자를 저장하는 것은 nAnn_Inc

	pData = (ListNode*)(malloc(sizeof(ListNode)));		// ListNode의 크기만큼 동적 메모리할당을 함으로써 우리는 pData를 구조체 취급하며 정보 입력 가능

	if(pData == NULL) {
		system("cls");
		printf("일시적 오류가 발생하였습니다.\n");
		printf("다시 시도해 주십시오.\n");
		getch();
		return;
	}	// 단, 동적 메모리 할당에 실패할 경우를 대비하여 if문으로 처리해 주었다.	
	pData->link = NULL;		// 현재 아무것도 가리키고 있지 않으므로 NULL을 대입.

	system("cls");
	printf("==========================\n");
	printf("       < 정보입력 >       \n");
	printf("==========================\n");
	printf("시작하려면 아무키나 누르세요...");	// 정보 입력을 시작하는 부분.
	getch();	// system("pause")의 역할을 하며, 사용자가 아무 키나 누르면 정보 입력을 시작함.
	fflush(stdin);	// 버퍼 클리어 (후에 이름을 입력할 때 오류가 생기지 않게 함)

	system("cls");
	printf("==========================\n");
	printf("         < 이름 >         \n");
	printf("==========================\n");	
	printf("-> \n");
	printf("==========================\n");		// 이름 입력을 시작하는 부분.
	gotoxy(3, 3);	// 커서를 ->의 뒤로 이동시킨다.
	scanf("%s", pData->strName);		// 관리하고자 하는 회원의 이름을 pData->strName에 저장
	fflush(stdin);

	system("cls");
	printf("==========================\n");
	printf("         < 성별 >         \n");
	printf("==========================\n");
	printf("   ○ 남자\n");
	printf("   ○ 여자\n");
	printf("==========================\n");		// 성별 입력을 받는 부분
	pData->nGender = key_shift(VERTICAL, 0, 3, 0, 4, 0, 1, 1);		/* 남, 여 중 하나를 고르는 것이므로 수직으로 이동하고,
																	y범위를 3~4로 주었으며, 시작 인덱스는 1. key_shift가 실행되고
																	사용자가 선택한 번호가 반환되어 pData->Gender에 대입됨으로써 정보가 입력됨.
																	후에 printData에서 각각의 경우에 대한 출력을 담당.*/
	fflush(stdin);
 
	system("cls");
	printf("==========================\n");
	printf("         < 나이 >         \n");
	printf("==========================\n");
	printf("-> \n");
	printf("==========================\n");		// 나이를 입력받는 부분
	gotoxy(3, 3);	//->뒤로 커서를 이동시킴
	scanf("%d", &(pData->nAge));		// pData->nAge에 관리하고자 하는 사람의 나이를 입력받음
	fflush(stdin);
   
	system("cls");
	printf("==========================\n");
	printf("       < 직업 >       \n");
	printf("==========================\n");
	printf("   ○ 법조인\n");
	printf("   ○ 의료인\n");
	printf("   ○ 언론인\n");
	printf("   ○ 증권인\n");
	printf("   ○ 교직원\n");
	printf("   ○ 공무원\n");
	printf("   ○ 공학자\n");
	printf("   ○ 조종사\n");
	printf("   ○ 사업가\n");
	printf("   ○ 그  외\n");
	printf("==========================\n");		// 직업을 입력 받는 부분(10가지의 직업으로 구성)
	pData->nJob = key_shift(VERTICAL, 0, 3, 0, 12, 0, 1, 1);	// Gender와 마찬가지의 방법으로 key_shift를 이용하여 직업을 입력받는다.
	fflush(stdin);

	system("cls");
	printf("==========================\n");
	printf("         < 연봉 >         \n");
	printf("==========================\n");
	printf("-> [    ]억[    ]만원\n");
	printf("==========================\n");		// 연봉 입력받는 부분. '억'부분과 '만'부분으로 나누어서 입력받도록 하고, 이를 통해 계산된다.
	gotoxy(4,3);	// 억 부분으로 커서를 이동
	scanf("%d",&nAnn_Inc_big);	// 억에 해당하는 숫자 입력받음
	fflush(stdin);
	gotoxy(12,3);	// 만원에 해당하는 부분으로 커서 이동
	scanf("%d",&nAnn_Inc);	// 만원에 해당하는 숫자 입력받음
	fflush(stdin);
	pData->nAnnualIncome = nAnn_Inc + nAnn_Inc_big*10000;	// 데이터 필드의 연봉 부분에 내가 입력했던 억부분과 만원 부분의 숫자를 토대로 연봉을 계산하여 대입.

	system("cls");
	printf("==========================\n");
	printf("         < 학력 >         \n");
	printf("==========================\n");
	printf("   ○ 고등학교 졸업\n");
	printf("   ○ 대학교   졸업\n");
	printf("   ○ 대학원   이상\n");
	printf("==========================\n");		// 학력을 입력받는 부분
	pData->nAcademicAbility = key_shift(VERTICAL, 0, 3, 0, 5, 0, 1, 1);		// Gender, Job과 마찬가지로 key_shift를 이용하여 학력을 입력받는다.
	fflush(stdin);
	
	insertData(pData);		// 정보를 입력했으니, 리스트에 삽입을 하기 위해 pData를 파라미터로 보내어 실질적인 리스트 삽입 역할을 해주는 insertData를 호출한다.

	system("cls");
	printf("==========================\n");
	printf("       < 정보입력 >       \n");
	printf("==========================\n");
	printf("정보입력이 완료되었습니다...");
	getch();
}//insertMenu()
void insertData(ListNode *pData) {		// 파라미터로 보내진 pData를 이용하여 실질적인 리스트 삽입을 담당하는 함수.
	ListNode *pVisited, *pPrev;		// 방문포인터 pVisited, 백업포인터 pPrev를 이용해서 리스트 삽입을 한다.
	/*

	Linking과정에서 경우의 수는 크게 4가지.
	1)pHeader에 아무것도 연결 안됐을 때<<첫 번째 실행, 첫 노드로서의 삽입>>
	: pHeader를 pData와 연결해주면 끝.
	2)pHeader에 연결은 된 상태<<이미 1)이 실행되어 pHeader가 노드와 연결 됨.>>

	**while문으로 pVisited의 위치를 찾고 pPrev로 뒤따라간다**

	2-1)이 때 pData->data가 제일 작아서 맨 앞의 노드로 삽입되어야 할 경우
	:1)하듯이 옮겨주면 됨.
	2-2)그렇지 않은 경우
	:pData->link=pPrev->link;
	pPrev->link=pData->link;


	*/
	if(pHeader == NULL) { 		// case 1) pHeader에 아무것도 연결 안 된 상태.
		pHeader = pData;		// 헤더 포인터가 pData를 가리키게 함으로써 연결.
	}else {						// case 2) pHeader에 무언가 연결되어 있는 경우
		pVisited = pHeader;		//pVisited에 pHeader를 대입함으로써 pVisited가 첫번째 노드를 가리키게 함.
		pPrev = NULL;	// 아직 아무것도 가리키고 있지 않기 때문에, pPrev를 NULL로 초기화
		
		while (pVisited != NULL && strcmp(pData->strName, pVisited->strName) > 0) {		// 위치 찾기 과정 >> 기준 - 이름순으로 ordered!
			// 만약 저 기준(pVisited가 끝까지 가지 않았고, pData의 이름이 pVisited가 가리키는 이름보다 더 클 때)에 합당하다면,
			pPrev = pVisited;	// pPrev로 백업시키고,
			pVisited = pVisited->link;		// pVisited는 전진!
		}//while

		if (pPrev == NULL) {		// case 2-1) 이름이 제일 앞에 와서 첫 번째에 삽입 되어야 할 경우 -> 백업 포인터가 움직이지 않았음.(위의 while 실행x)
			pData->link = pHeader;
			pHeader = pData;	// pData를 pHeader가 가리키고 있는 리스트의 첫 번째 노드로 삽입한다.
		}else {					// case 2-2) 중간이나 끝에 도달했을 때
			pData->link = pPrev->link;
			pPrev->link = pData;	// 평범하게 pVisited와 pPrev를 이용하여 연결해준다.
		}//if-else
	}//if-else
}//insertData()
void manageMenu() {
	ListNode *pVisited;		// 사용자가 관리하고자 하는 특정 이름의 회원이 있는 지를 체크해주기 위해 노드를 순회할 방문포인터를 선언.
	char strName[40];		// 관리하고자 하는 특정 회원의 이름을 받아주는 문자형 배열 
	int nCount = 0, nStart, nLast;		// 순서대로 노드의 갯수를 세어주는 변수(이것이 노드마다 붙여주는 인덱스가 됨.), 노드의 시작 인덱스, 노드의 마지막 인덱스 
	int nSelectedData, nSelectedMenu;	// 이름을 입력받고 해당 이름을 가진 회원을 모두 출력을 하면 keyshift를 이용하여 그 회원 중 하나를 선택할 수 있음. 그 데이타의 노드 넘버를 저장해주는 변수 nSelectedData 
										// 그리고 그것을 선택하게 되면 수정할 것인지 삭제할 것인지가 나오면서 사용자가 선택하게 되는데, 그 선택을 저장해 주는 변수 nSelectedMenu

	if(pHeader == NULL) {
		system("cls");
		printf("아직 관리할 정보가 없습니다.\n");
		printf("아무 키나 누르면 이전으로 돌아갑니다...\n");
		getch();
		return;
	}		// 프로그램 상에서 회원 정보가 없다면 관리할 필요가 없음. 따라서 pHeader가 NULL이라면 함수 실행을 하지 않음.

	pVisited = pHeader;		// 아닌 경우, pVisited가 첫 번째 노드를 가리키게 함.

	system("cls");
	printf("==========================\n");
	printf("       < 정보관리 >       \n");
	printf("==========================\n");
	printf("이름 입력 >> ");
	scanf("%s", strName);		// 관리할 회원의 정보를 입력하는 부분
	fflush(stdin);
	// 시작 인덱스 찾기..
	while((pVisited != NULL)){
		if(strcmp(pVisited->strName,strName) == SAME) break; 
		// pVisited가 순회를 시작하면, pVisited의 이름 부분과 사용자가 입력한 이름이 맞는지 아닌지를 비교하여 맞으면 탈출, 
		pVisited = pVisited->link;	// 아니면 한 칸 전진
		nCount++;		// 노드의 시작 값을 증가시킴.
	}//while
	
	system("cls");

	if (pVisited == NULL) {		// 만약, 입력한 이름과 일치하는 회원이 없어 도중에 멈추지 못하고 pVisited가 리스트의 끝까지 갔다면 
		printf("해당 이름을 가진 회원이 없습니다.\n");
		printf("아무 키나 누르면 이전으로 돌아갑니다...\n");		// 찾는 회원이 없다는 메세지를 출력하고,
		getch();
		return;		// 함수를 종료.
	}//if

	nStart = nCount;		// 처음으로 회원의 이름이 시작되는 경우를 시작 인덱스로 대입.
	nLast = nCount - 1;		// 마지막 인덱스는 일단 시작 인덱스에서 -1을 뺀 값에서 시작.

	printf("===================================================\n");
	printf("                     < 정보관리 >                  \n");
	printf("===================================================\n");
	printf("  | 이 름 | 성 별 | 나 이 | 직 업 | 연 봉 | 학 력 |\n");
	printf("===================================================\n");	// 정보 관리란의 기본 출력 폼
	
	while (pVisited != NULL) {		// 리스트의 끝에 다다를 때 까지
		if (strcmp(strName, pVisited->strName) == SAME) {	// 사용자가 입력해 준 이름과 pVisited가 순회하는 노드의 이름이 같으면,
			printf("   ");		// 출력 폼 맞추기 위해 공백문자 출력.
			printData(nCount);		// 출력할 때마다 노드의 position값 1개를 보내주면서 1개씩 출력하게 함. 
			nLast++;	//마지막 노드의 수를 1 증가시킨다.
		}//if
		pVisited = pVisited->link;		// 방문포인터 전진
		nCount++;		// 전진했으므로, 노드의 position값을 1 증가시킨다.
	}//while
	
	nSelectedData = key_shift(VERTICAL, 0, 5, 0, 5 + nLast - nStart, 0, 1, nStart);		// 출력된 데이터 값을 보면서 상하로 커서를 움직여 선택하게 함. + 선택된 회원의 위치를 저장한 값이 nSelectData로 대입됨.

	nSelectedMenu = askMenu();		// 관리할 대상이 선택되었으면 해당 회원의 정보를 수정할 지 수정하지 않을 지를 고르게 하는 함수 askMenu를 호출하면서, 사용자가 선택한 것을 변수에 저장하게 함.

	switch (nSelectedMenu) {		// 변수 nSelectedMenu를 분기로 하여 특정 기능을 수행할 함수들이 호출됨.
		case 1:		// 만약 1번, 정보 삭제를 선택했다면,
			deleteMenu(nSelectedData);		// 해당 노드의 번호를 전달하면서 노드를 삭제하는 함수를 호출.
			break;

		case 2:		// 만약 2번, 정보 수정을 선택했다면,
			modifyMenu(nSelectedData);		// 해당 노드의 번호를 전달하면서 노드의 데이터를 수정하는 함수를 호출.
			break;

		case 3:		// 만약 3번, 이전으로 돌아가기를 선택했다면,
			system("cls");
			printf("작업이 취소되었습니다.");
			printf("아무 키나 누르면 이전으로 돌아갑니다...\n");
			getch();
			return;		// 작업이 취소되었음을 출력하고 함수를 종료한다.
	}//switch-case	
}//manageMenu()
int askMenu() {		// 정보관리 메뉴에서 정보를 삭제할 것인지 수정할 것인지 묻는 메뉴
	int nMenu;		// 삭제메뉴나 수정메뉴 중에서 선택하기 위한 변수 선언
	
	system("cls");
	printf("==========================\n");
	printf("       < 정보관리 >       \n");
	printf("==========================\n");
	printf("   ○ 회원정보삭제\n");
	printf("   ○ 회원정보수정\n");
	printf("   ○ 취소\n");
	printf("==========================\n");
	
	nMenu = key_shift(VERTICAL, 0, 3, 0, 5, 0, 1, 1);		//nMenu값은 커서의 위치로 선택할 커서는 수직으로만 움직이며 x의 좌표는 0에서 고정, y좌표는 3~5 사이에서 한 번에 한 칸씩 이동한다

	return nMenu;	//nMenu를 manageMenu의 nSelectedMenu로 전해준다.
}//askMenu()
void deleteMenu(int nPosition) {		// 지울 노드의 위치값을 파라미터로 받아 해당 노드를 지우는 역할을 하는 deleteData를 호출하는 함수.
	int flag;		// 회원 정보의 삭제는 중요한 과정이기 때문에 한 번 더 실행 여부를 묻게 된다. 이 때 사용자의 의사를 저장하는 변수.

	system("cls");
	printf("==========================\n");
	printf("       < 정보삭제 >       \n");
	printf("==========================\n");
	printf("정말로 삭제하시겠습니까?  \n");
	printf("               YES |  NO  \n");
	printf("==========================\n");		// 정보 삭제의 기본 출력 폼.
	flag = key_shift(HORIZONTAL, 16, 4, 22, 4, 6, 0, 1);		// YES or NO 중 하나를 선택하는 것이므로 수평으로 주었고, YES(1)과 NO(2) 중 하나가 flag변수에 대입된다.

	system("cls");
	if (flag == YES) {		// 만약 사용자가 계속 지우기를 원했을 때는,
		deleteData(nPosition);		// 해당 노드를 지우는 함수 deleteData를 호출하면서 위치값도 함께 보낸다.
		printf("정보 삭제가 완료되었습니다.\n");
		printf("계속하시려면 아무키나 누르세요...\n");		// 정보 삭제가 완료되었다는 메세지 출력
	}else {		// 만약 사용자가 지우기를 원하지 않을 경우,
		printf("정보 삭제가 취소되었습니다.\n");
		printf("계속하시려면 아무키나 누르세요...\n");		// 정보 삭제가 취소되었다는 메세지를 출력하면서 함수가 끝남.
	}//if-else
	getch();
}//deleteMenu()
void deleteData(int nPosition) {	// 지울 노드의 위치값을 파라미터로 받아 해당 노드를 지우는 역할을 하는 함수.
	ListNode *pVisited, *pPrev;		// 위치값을 기반으로 위치를 찾을 때 사용되는 방문포인터 pVisited와 백업포인터 pPrev
	int i;		// 반복제어변수
	
	pVisited = pHeader;		// pVisited가 첫 번째 노드를 가리키게 함
	pPrev = NULL;		// 백업포인터는 현재 pVisited가 이동하지 않았으므로 NULL을 가리킴

	for (i = 0; i<nPosition; i++) {		//위치값에 따라 이동하여 삭제할 노드를 찾는 부분
		pPrev = pVisited;
		pVisited = pVisited->link;		// 해당 조건을 만족하면, pPrev는 pVisited의 구 위치를 저장하고, pVisited는 한 칸 전진함.
	}//for
	
	if (pPrev == NULL) {		// 만약 한 번도 움직이지 않았을 때 -> 첫 번째 노드가 지워질 때
		pHeader = pHeader->link;
		free(pVisited);	// pHeader가 다음노드를 가리키게 하고, 여전히 첫 번째 노드를 가리키고 있는 pVisited를 free 시킨다.
	}else {		// 중간 또는 끝 노드가 지워질 때
		pPrev->link = pVisited->link;
		free(pVisited);		//pPrev가 pVisited가 원래 가리키고 있던 노드의 다음 노드를 가리키게 한 뒤(연결 해제), pVisited를 free시킨다.
	}//if-else
}//deleteData()
void modifyMenu(int nPosition) {	// 사용자가 관리하고 싶은 회원정보의 위치값을 파라미터로 전달받아 그 위치를 찾고, 정보를 수정하게 하는 함수.
	ListNode *pData, *pVisited;		/*
									이름 순으로 ordered하는 방식으로 작성하였으므로, 이름 수정은 다른 방법으로 진행해야 함.
									이름을 바꿀 때, 바꾸기 전의 정보들을 백업하고 연결하기 위한 구조체 포인터 pData를 선언.
									또, 위치를 찾기 위한 방문 포인터 pVisited를 선언.
									*/
	char strName[40];		// 이름을 수정할 때, 수정하고 싶은 이름을 저장하는 문자형 배열.
	int nPart, i, flag;		/*
							nPart - 이름, 성별, 나이, 직업, 연봉, 학력, 뒤로 중 무엇을 선택할 지 커서를 움직이고 고르게 되는데, 이 때 실행하고자
							하는 것을 저장하는 변수.
							i - 파라미터로 전달받은 position값을 바탕으로 위치를 찾는데 사용되는 반복제어변수
							flag - 정보 수정을 계속 할 지 안 할 지를 저장하는 변수. 역시 커서를 움직여 고르게 됨.
							*/

	system("cls");
	printf("=========================================================\n");
	printf("                        < 정보수정 >                     \n");
	printf("=========================================================\n");
	printf("| 이 름 | 성 별 | 나 이 | 직 업 | 연 봉 | 학 력 | 뒤 로 |\n");
	printf("=========================================================\n");		// 기본 출력 폼
	printData(nPosition);		// 이미 manageMenu에서 수정할 딱 한명의 회원 정보만을 걸러냈기 때문에 위치값을 이용하여 회원의 정보 1개만 출력한다.

	nPart = key_shift(HORIZONTAL, 4, 3, 52, 3, 8, 0, 1);		// 여기서 이름~ 뒤로까지 선택할 수 있도록 수평으로 움직이도록 한다. 실행된 결과는 nPart에 대입된다.

	system("cls");
	if(nPart == QUIT) {
		printf("정보 수정이 취소되었습니다.\n");
		printf("계속하시려면 아무키나 누르세요...\n");
		getch();
		return;		// 정보 수정에서 '뒤로'에 커서를 옮겨 선택하면, 정보수정을 그만두고 메인메뉴로 나온다.
	}else {
		if(nPart == 1) {	// 이름순으로 ordered했기 때문에 정렬에 문제가 생기지 않게 하기 위해서는 삭제 후 삽입과정이 필요하다. 이는 다른 수정과정과 다르며 그래서 따로 분리한다.			
			pData = (ListNode*)malloc(sizeof(ListNode));	// pData에 동적 메모리 할당을 한다.
			pData->link = NULL;		// 현재 가리키는 게 아무것도 없으므로, NULL 대입
			pVisited = pHeader;	// pVisited가 첫 번째 노드를 가리키게 한다.

			for (i = 0; i<nPosition; i++) {	// 파라미터로 전달받은 위치값을 이용하여 수정할 노드를 찾는다.
				pVisited = pVisited->link;		// 찾을 때 까지 전진	
			}

			*pData = *pVisited;		// 찾았으면, pData의 구조체에 pVisited의 구조체 필드를 통째로 복사한다.

			system("cls");
			printf("==========================\n");
			printf("       < 이름수정 >       \n");
			printf("==========================\n");
			printf("-> \n");
			printf("==========================\n");		// 이름 수정을 받는 부분
			gotoxy(3, 3);	//		 -> 뒤로 이동시킨다.
			scanf("%s", strName);	// 수정할 이름을 받는다.

			gotoxy(0, 5);	// 커서를 이동
			printf("%s->%s 변경 맞습니까?\n", pVisited->strName, strName);		// 입력된 이름과 저장되어 있었던 이름을 출력하고, 바꿀 이름이 맞는 지 확인한다.
			printf("               YES |  NO  \n");
			printf("==========================\n");
			flag = key_shift(HORIZONTAL, 16, 6, 22, 6, 6, 0, 1);		// YES or NO 중 하나를 커서 이동을 통해 저장한다.

			if (flag == NO) {	// 만약 NO, 잘못 입력했음을 선택한다면
				system("cls");
				printf("정보 수정이 취소되었습니다.\n");
				printf("계속하시려면 아무키나 누르세요...\n");
				getch();
				return;		// 정보수정이 취소되었다는 출력과 함께 함수가 종료되며 메인메뉴로 나온다.
			}

			strcpy(pData->strName, strName);		// 만약 YES를 입력했다면, pData->strName에 입력한 strName을 대입한다. >> 수정할 노드 완성

			deleteData(nPosition);		// 먼저 있던 쓸모없어진 수정 전의 노드를 지우고
			insertData(pData);		// 수정된 노드를 리스트에 삽입한다.
		}
		else {		// 만약 이름 외의 것을 수정하고자 한다면,
			modifyData(nPosition, nPart);	// modifyData를 호출하면서 노드의 위치가 저장된 nPosition과 무엇을 수정할 지가 저장 된 nPart를 함께 파라미터로 보낸다.
		}//if-else
		system("cls");
		printf("정보 수정이 완료되었습니다.\n");
		printf("계속하시려면 아무키나 누르세요...\n");
		getch();
		return;		// 정보수정이 완료되었음을 알리며 함수 종료.
	}//if-else
}//modifyMenu()
void modifyData(int nPosition, int nCategory) {		// 이름 외의 다른 정보들을 수정할 경우 실행하는 함수
	ListNode *pVisited = pHeader;		// 포인터 선언, pVisited는 첫노드에 위치
	int i, flagGen, nAnn_Inc_big, nAnn_Inc;		/*
												for 반복문을 위한 변수 i 선언, 성별 수정 선택시 필요한 flgGen 변수 선언
												억과 만에 해당하는 변수 nAnn_Inc_big, nAnn_Inc
												*/

	for (i = 0; i<nPosition; i++) {		// 파라미터로 전달받은 위치값을 이용하여 수정할 노드를 찾는다.
		pVisited = pVisited->link;		// 찾을 때까지 pVisited 전진
		if (pVisited == NULL) break;		// pVisited가 가장 마지막 노드에 가면 break
	}

	system("cls");
	switch (nCategory) {		// 선택한 수정분야에 따라
		case GENDER:
			printf("==========================\n");
			printf("        < 성별수정 >      \n");
			printf("==========================\n");
			if (pVisited->nGender == MALE) {		// pVisited가 가르키는 구조체의 성별이 남성이었다면
				printf("남자->여자 변경 맞습니까?\n");
			}
			else if (pVisited->nGender == FEMALE) {		// pVisited가 가르키는 구조체의 성별이 여성이었다면
				printf("여자->남자 변경 맞습니까?\n");
			}
			printf("               YES |  NO  \n");
			printf("==========================\n");
			flagGen = key_shift(HORIZONTAL, 16, 4, 22, 4, 6, 0, 1);		// flaGen는 커서의 위치로 선택할 커서는 수평으로만 움직이며 x좌표는 16~22 사이에서 한 번에 6칸 씩 이동하고, y좌표는 4에서 고정한다.
			if (flagGen == YES && pVisited->nGender == MALE)		pVisited->nGender = FEMALE;		// YES를 선택했고 pVisited가 가르키던 성별이 MALE이었다면 FEMALE로 수정한다.	
			else if (flagGen == YES && pVisited->nGender == FEMALE)	pVisited->nGender = MALE;		// YES를 선택했고 pVisited가 가르키던 성별이 FEMALE이었다면 MALE로 수정한다.
			break;

		case AGE:	// 나이
			printf("==========================\n");
			printf("       < 나이수정 >       \n");
			printf("==========================\n");
			printf("-> [    ]\n");
			printf("==========================\n");
			gotoxy(4, 3);		// x,y좌표 (3,3)으로 커서이동
			scanf("%d", &(pVisited->nAge));		// pVisited에서 가르키는 구조체의 nAge, 즉 나이값 입력
			break;

		case JOB:	 // 직업
			printf("==========================\n");
			printf("       < 직업수정 >       \n");
			printf("==========================\n");
			printf("   ○ 법조인\n");
			printf("   ○ 의료인\n");
			printf("   ○ 언론인\n");
			printf("   ○ 증권인\n");
			printf("   ○ 교직원\n");
			printf("   ○ 공무원\n");
			printf("   ○ 공학자\n");
			printf("   ○ 조종사\n");
			printf("   ○ 사업가\n");
			printf("   ○ 그  외\n");
			printf("==========================\n");
			pVisited->nJob = key_shift(VERTICAL, 0, 3, 0, 12, 0, 1, 1);		// 수직으로만 움직이며, x좌표는 0으로 고정, y좌표는 3~6 사이에서 한번에 한 칸씩 이동하며, 그 값은 pVisited->nJob에 대입
			break;

		case ANN_INC:	 // 연봉
			printf("==========================\n");
			printf("       < 연봉수정 >       \n");
			printf("==========================\n");
			printf("-> [    ]억[    ]만원\n");
			printf("==========================\n");
			gotoxy(4,3);
			scanf("%d",&nAnn_Inc_big);
			fflush(stdin);
			gotoxy(12,3);
			scanf("%d",&nAnn_Inc);
			fflush(stdin);
			pVisited->nAnnualIncome = nAnn_Inc + nAnn_Inc_big*10000;	// 연봉을 몇억 몇만원으로 수정할 것인지를 받고, 계산하여 데이터 필드에 대입
			break;

		case ACD_ABL:		// 학력
			printf("==========================\n");
			printf("       < 학력수정 >       \n");
			printf("==========================\n");
			printf("   ○ 고등학교 졸업\n");
			printf("   ○ 대학교   졸업\n");
			printf("   ○ 대학원   이상\n");
			printf("==========================\n");
			pVisited->nAcademicAbility = key_shift(VERTICAL, 0, 3, 0, 5, 0, 1, 1);		// 수직으로만 움직이며 x좌표는 0에서 고정, y좌표는 3~5 사이에서 한 번에 한 칸씩 이동한다. 
																						// 이 값은 pVisited->nAcademicAbility에 저장
			break;
	}//switch-case
}//modifyData()
void printData(int nPosition) {		// 전체보기, 정보관리 등에서 사용될 입력된 회원정보를 출력하는 함수
	ListNode *pVisited;		// 노드의 위치를 찾기 위한 pVisited 포인터 선언
	char job;		// 직업 변수
	int i;		// for반복문 작성을 위한 변수 i 선언


	pVisited = pHeader;		// pVisited 포인터는 첫노드에 위치

	for (i = 0; i<nPosition; i++) {		// 위치값을 이용하여 노드를 찾는다.
		pVisited = pVisited->link;		// pVisited의 전진
	}

	//이름출력
	printf(" %-8s", pVisited->strName);

	//성별출력
	if (pVisited->nGender == MALE) {		// pVisited포인터가 가르키는 회원정보의 성별이 남성일 경우
		printf("   남   ");
	}else if (pVisited->nGender == FEMALE) {		// pVisited포인터가 가르키는 회원정보의 성별이 여성일 경우
		printf("   여   ");
	}

	//나이출력
	printf("  %3d   ", pVisited->nAge);

	//직업출력
	switch (pVisited->nJob) {		// pVisited포인터가 가르키는 회원정보의 직업에 따라
		case 1: printf("법조인"); break;
		case 2: printf("의료인"); break;
		case 3: printf("언론인"); break;
		case 4: printf("증권인"); break;
		case 5: printf("교직원"); break;
		case 6: printf("공무원"); break;
		case 7: printf("공학자"); break;
		case 8: printf("조종사"); break;
		case 9: printf("사업가"); break;
		case 10: printf("그  외"); break;
	}//switch-case


	//연봉출력
	if (pVisited->nAnnualIncome < 10000)	{	// pVisited포인터가 가르키는 회원정보의 연봉이 10000만(1억) 미만이라면
		printf("   %4d", pVisited->nAnnualIncome);
		printf("만");
	}else if (pVisited->nAnnualIncome < 100000000) {		// pVisited포인터가 가르키는 회원정보의 연봉이 1억 이상이지만 100000000만(1조) 미만이라면
		printf(" %6.1f", (float)(pVisited->nAnnualIncome) / 10000);	// 연봉(만 단위 이하는 뺀 수)을 10000으로 나누어 float형태로 표기. float로 하는 이유는 자리수 확장을 위해
		printf("억");
	}

	//학력출력
	if (pVisited->nAcademicAbility == 1) {		// pVisited포인터가 가르키는 학력이 1,첫번째 것이라면
		printf("  %-8s", "고졸");
	}else if (pVisited->nAcademicAbility == 2) {		// pVisited 포인터가 가르키는 학력이 2, 두번째 것이라면
		printf("  %-8s", "학사");
	}else if (pVisited->nAcademicAbility == 3) {	// pVisited 포인터가 가르키는 학력이 3, 세번째 것이라면
		printf("  %-8s", "석사이상");
	}
	
	printf("\n");
}//printData()
void outlineMenu() {		// 프로그램 내부에 있는 회원 정보들을 전체적으로 출력하는 함수
	ListNode *pVisited;		// 노드 하나하나 방문하면서 출력할 것이므로, 방문 포인터를 하나 선언
	int nCriteria = NAME, flag = NO;		/*	
												이름에 커서를 두면 이름 순으로, 나이, 연봉, 학력은 학력 순으로 정렬하여 출력하려고 하므로 그 실행을 저장하는 변수 nCriteria를 선언
												위의 이름, 성별, 나이, 연봉, 학력,직업을 선택했는지 아니면 끝내기를 선택했는지 저장해주는 flag.
												후에 arrnageData에서 처음 한 번 누르면 우리가 정해준 기준의 순서대로 되고 다시 한 번 누르면
												그의 역순으로 되는데, 끝내기를 누르면 arrangeData에서 리턴되어 flag에 저장되고 함수가 끝나게 됨.
											*/
	int nCount = 0, i;		/*
							nCount - 노드의 개수를 세어주는 변수
							nCountSave - 전체적인 노드의 개수를 임시 저장할 변수
							i - 반복제어변수
							*/

	system("cls");
	
	if (pHeader == NULL) {	// 리스트에 아무 정보도 없을 땐 함수를 실행할 필요가 없다.
		printf("아직 볼 수 있는 정보가 없습니다.\n");
		printf("아무 키나 누르면 이전으로 돌아갑니다...\n");		// 정보가 없다는 메세지를 출력하고 함수를 종료.
		getch();
		return;
	}//if

	pVisited = pHeader;		// pVisited가 첫 번째 노드를 가리키게 한다.
	while (pVisited != NULL) {		// pVisited가 끝에 다다르지 않을 때 까지 pVisited를 증가시키면서 동시에 nCount(노드 개수)의 값도 증가시킨다.
		pVisited = pVisited->link;	
		nCount++;
	}//while

	while(TRUE) {
		fflush(stdin);
		system("cls");
		gotoxy(0,0);
		printf("=========================================================\n");
		printf("                        < 전체보기 >                     \n");
		printf("=========================================================\n");
		printf("| 이 름 | 성 별 | 나 이 | 직 업 | 연 봉 | 학 력 | 뒤 로 |\n");
		printf("=========================================================\n");		// 전체보기 메뉴의 기본 출력폼
		nCount;
		for (i = 0; i<nCount; i++) {	// 노드의 끝에 다다를 때 까지 회원 정보를 출력하고 i를 1씩 증가시킨다.
			printData(i);		
		}//for

		nCriteria = key_shift(HORIZONTAL, 4, 3, 52, 3, 8, 0, 1);
		// 출력이 완료되고 원하면, 어떤 기준으로 재 정렬을 할 지 선택할 수 있게 된다. 역시 이름~뒤로까지 선택할 수 있다.

		if (nCriteria == QUIT) {		// 만약 사용자가 QUIT(7번, 뒤로)을 선택했다면 함수가 종료되어 메인메뉴로 나오게 되고,
			if (flag == YES)	arrangeData(NAME);	/*  
														이미 여러가지 정렬작업을 한 뒤 다시 나갔다면,
														전체보기 메뉴를 실행했을 때 이름 순으로 정렬되어 보여주지 않을 것이다. 처음은 무조건
														이름순이기 때문에, 끝내기 전 이름순으로 정렬하고 끝낸다.
													*/
			return;
		}//if
		
		flag = arrangeData(nCriteria);		// 그 경우가 아니라면 어떠한 기준으로 정렬할 지를 저장한 변수를 파라미터로 보내어 재정렬을 실행한다. arrangeData가 반환한 값은 QUIT인지 아닌지로 활용됨.
	}// while
}//outlineMenu()
int arrangeData(int flag) {		// 어떠한 기준으로 정렬할 지를 인수로 받고, 그에 따라 리스트 자체를 정렬해주는 함수.
	ListNode *pVisited, *pSaved, *pPrev, *pCompared;						/*
																				pVisited - 진행하면서 해당 노드를 재정렬 재삽입 하는 데 이용되는 포인터
																				pSaved - pVisited의 백업 포인터 (백업포인터 1로 지칭)
																				pPrev - pCompared의 백업포인터로 후에 pVisited가 pCompared가 가리키고 있는 노드의 앞의 어딘가 또는 뒤의 어딘가로 들어가야 할 때 , pHeader의 뒤로 들어가야 할 때 등에서 사용.
																				(백업포인터 2로 지칭하겠음.)
																				pCompared - 이동하면서 실질적으로 pVisited가 가리키는 노드와 데이터 값을 비교하여 pVisited를 pCompare가 가리키는 노드의 앞의 어딘가, 또는 뒤의 어딘가, pHeader 뒤로 들어가야 하는지 결정해줌
																			
																			*/
	int nPosition = 0, i, bIterationFlag = FALSE, bRearrangeflag = YES;		/*
																				nPosition - 비교 행위를 할 횟수
																				i - 반복 제어변수
																				bIterationFlag - 정렬을 멈추는지 계속 진행하는 지를 저장하는 변수
																				bRearrangeflag - 이름 순으로 재정렬을 해야하는 지 아닌 지를 받는 변수. outlineMenu로 반환되어 만약 bRearrangeflag==YES라면 현재 리스트가 이름순으로 재정렬이 필요하다는
																				의미이므로, 끝내기 전에 재정렬 하게 된다. 이름란에 다시 엔터를 쳐 정순정렬 되어있을 때는 그대로 종료. arrange할 필요가 없으므로
																				즉, 끝내는 경우 YES라면 outlineMenu으로 반환되어 정렬이 이름 순으로 다시 이뤄지고,
																				NO라면 그냥 종료함.
																		
																			*/
	static int prevflag[2] = {NONE,NAME};	/*
												프로그램에서 한 번 먼저 정해진 기준대로 정렬하고 나서 한 번 더 엔터를 치면 그의 역으로 재정렬이 된다.
												이 때 저번 실행과 저저번 실행을 저장하면서 함수가 끝나더라도 그 값을 그대로 가지고 있는 것이 필요하다는 것을
												알 수 있다. 따라서 static변수로 선언하였고, 저번 실행과 저저번 실행을 가지고 있을 수 있는 배열로 선언하였다. 
											*/

	while(TRUE) {		// 리스트를 사용자로 부터 받은 기준으로 재정렬 하는 과정.
		// 기본 세팅
		pSaved = pHeader;		// pSaved가 첫 번째 노드를 가리키게 함
		pPrev = NULL;		// 아직 출발하지 않았으므로 NULL
		pVisited = pHeader->link;	// pVisited가 두 번째 노드를 가리키게 함.
		pCompared = pHeader;	// pCompared가 첫 번째 노드를 가리킴.

		for(i=0; i<nPosition; i++) {		// (처음은, nPosition이 0이므로 이 부분을 건너 뛰게 됨. 후에 늘어나면 실행) 
			if(pVisited->link == NULL) {		// 마지막 노드라면,
				bIterationFlag = TRUE;		// bIterationFlag에 참값을 대입하고 for문을 탈출한다. >> 더이상 비교할 노드가 없다는 의미
				break;
			}//if
			pSaved = pVisited;	
			pVisited = pVisited->link;		// if조건에 해당되지 않는다면, 백업포인터 1과 pVisited를 전진시킨다.
		}
		if(bIterationFlag == TRUE)	break;		// 만약 마지막 노드여서 나왔다면, while문 자체도 빠져 나온다.

		pSaved->link = pVisited->link;		// 리스트와 pVisited가 가리키고 있는 노드를 분리한다. [pVisited가 가리키고 있는 그 다음 노드를 가리키면서...
	
		switch(flag) {		// outlinkMenu에서 전해준 인수 flag에 따라 분기됨.
			case NAME:		// 이름으로 재정렬
				if(flag != prevflag[0] && flag == prevflag[1]) {		// 전전에 실행한 것과 현재 실행할 것(NAME)이 같지 않고, 전에 실행한 것(NAME)과 현재 실행한 것(NAME)이 같다면 역순으로 출력하는 것.
					for(i=0; i<nPosition+1; i++) {
						if(strcmp(pVisited->strName,pCompared->strName) < 0) {		/* 
																						** pPrev==NULL일 경우 - 첫 번째 노드부터 사전순으로 앞에 있을 경우
																						   >> pVisited가 앞에 삽입되게 됨.
																						** 그 외의 경우 - 밑에 보면 알겠지만 pPrev가 가리키는 노드의 뒤로 삽입되게 됨.
																					   만약 pCompared의 이름이 사전순으로 뒤에 있고(하민지)
																					   pVisited가 사전순으로 앞에 있다면(김연아) >> 역순! >> pPrev와 pCompare가 이동하고,  pVisited가 pPrev가 가리키던 노드 뒤에 삽입되게 됨.
																					   아예 저 조건을 만족하지 않았다(pVisited가 있는 곳에서부터 그 전 노드까지 가나다 순이었다면) 반복문을 탈출하면서
																					   pVisited가 첫 번째로
																					   삽입 될 것이고 가다가 저 조건을 만족하는 순간이 있다면 pPrev뒤로 삽입되게 된다. 
																					*/
							pPrev = pCompared;
							pCompared = pCompared->link;		// pPrev와 pCompared를 전진시킴 
						}
						else	break;		// 예외가 발생할 경우(pCompared) 바로 멈춰서 pHeader뒤 첫 노드 또는 문제가 발생한 pCompared와 pPrev 사이에 삽입시키도록 한다.
					}//for
					bRearrangeflag = YES;	// 리스트가 흐트러졌으므로 종료 전 재정렬 필요!
				}else {		// 정순으로 정렬할 경우
					for(i=0; i<nPosition+1; i++) {
						if(strcmp(pVisited->strName,pCompared->strName) > 0) {		// 마찬가지로 사전순으로 pVisited가 뒤에 있고 pCompared가 뒤에 있다면 
							pPrev = pCompared;
							pCompared = pCompared->link;		// 다른 노드를 검사하기 위해 한 칸 더 움직여준다.
						}
						else	break;		// 예외가 발생할 경우(pCompared) 바로 멈춰서 pHeader뒤 첫 노드 또는 문제가 발생한 pCompared와 pPrev 사이에 삽입시키도록 한다.
					}//for
					bRearrangeflag = NO;		// 이름 오름차순으로 되어있기 때문에 재정렬이 필요 없다!
				}//if-else
				break;
				
			case GENDER:	// 성별로 재정렬
				if(flag != prevflag[0] && flag == prevflag[1]) {		// 전전에 실행한 것과 현재 실행할 것(Gender)이 같지 않고, 전에 실행한 것(Gender)과 현재 실행한 것(Gender)이 같다면 역순으로 출력하는 것.
					for(i=0; i<nPosition+1; i++) {
						if(pCompared->nGender > pVisited->nGender) {	/* 
																			프로그램 상에서 등록된 번호는 남자가 1번, 여자가 2번이었다.
																			그리고 다시 한 번 더 성별 탭에서 엔터를 눌러 재정렬 할 때의 실행이다.
																			해당 조건은 여자를 먼저 출력하고 남자를 그 뒤에 출력한다. 
																			만일 상대적으로 앞에 있는 노드를 가리키는 pCompared->Gender가 여자이고 뒤의 pVisited가 남자라면
																			그대로 진행시켜 pPrev가 가리키는 곳 뒤에 pVisited가 삽입되도록 처리한다.

																		*/
							pPrev = pCompared;
							pCompared = pCompared->link;	// pPrev와 pCompared를 한 칸 전진시킴
						}
						else	break;		// 예외가 발생할 경우(pCompared) 바로 멈춰서 pHeader뒤 첫 노드 또는 문제가 발생한 pCompared와 pPrev 사이에 삽입시키도록 한다.
					}	// for
				
				}else {		// 먼저 처음으로 성별탭에서 정렬을 요청하면 남-여 순으로 정렬됨.
					for(i=0; i<nPosition+1; i++) {
						if(pCompared->nGender < pVisited->nGender) {		// 남(1) - 여(2) 순이 된다면 pPrev와 pCompared를 전진시킨다.
							pPrev = pCompared;
							pCompared = pCompared->link;
						}
						else	break;		// 예외가 발생할 경우(pCompared) 바로 멈춰서 pHeader뒤 첫 노드 또는 문제가 발생한 pCompared와 pPrev 사이에 삽입시키도록 한다.
					}
			
				}
				bRearrangeflag = YES;	// 종료 전 재정렬 필요!
				break;
	
			case AGE:		// 나이로 재정렬
				if(flag != prevflag[0] && flag == prevflag[1]) {	// 전전에 실행된 것과 현재 실행된 것이 같지 않고 전에 실행된 것과 같을 경우
					for(i=0; i<nPosition+1; i++) {		
						if(pCompared->nAge > pVisited->nAge) {	// 한 번 더 나이 탭에 가서 엔터를 치면 나이가 많은 순 대로 리스트를 재구성
							pPrev = pCompared;
							pCompared = pCompared->link;
						}else	break;		// 예외가 발생할 경우(pCompared) 바로 멈춰서 pHeader뒤 첫 노드 또는 문제가 발생한 pCompared와 pPrev 사이에 삽입시키도록 한다.
					}
				
				}else {
					for(i=0; i<nPosition+1; i++) {
						if(pCompared->nAge < pVisited->nAge) {		// 가장 처음 나이 탭에서 엔터를 치면 나이가 적은 순 대로 리스트를 재구성
							pPrev = pCompared;
							pCompared = pCompared->link;
						}
						else	break;		// 예외가 발생할 경우(pCompared) 바로 멈춰서 pHeader뒤 첫 노드 또는 문제가 발생한 pCompared와 pPrev 사이에 삽입시키도록 한다.
					}
		
				}
				bRearrangeflag = YES;	// 종료 전 재정렬 필요!
				break;
			
			case JOB:	
				if(flag != prevflag[0] && flag == prevflag[1]) {
					for(i=0; i<nPosition+1; i++) {
						if(pCompared != NULL && pCompared->nJob < pVisited->nJob) {		// 한 번 더 직업 탭으로 가서 엔터를 치면 직업 등록 순으로 재정렬 (1번째, 법조인이 제일 먼저)
							pPrev = pCompared;
							pCompared = pCompared->link;
						}
						else	break;		// 예외가 발생할 경우(pCompared) 바로 멈춰서 pHeader뒤 첫 노드 또는 문제가 발생한 pCompared와 pPrev 사이에 삽입시키도록 한다.
					}
				
				}else {		
					for(i=0; i<nPosition+1; i++) {
						if(pCompared != NULL && pCompared->nJob > pVisited->nJob) {		// 가장 처음 직업탭으로 가서 엔터를 치면 직업 등록 역순으로 재정렬 (10번째, 그 외가 제일 먼저)
							pPrev = pCompared;
							pCompared = pCompared->link;
						}
						else	break;		// 예외가 발생할 경우(pCompared) 바로 멈춰서 pHeader뒤 첫 노드 또는 문제가 발생한 pCompared와 pPrev 사이에 삽입시키도록 한다.
					}
					
				}
				bRearrangeflag = YES;	// 종료 전 재정렬 필요!
				break;
			
			case ANN_INC:		// 연봉 순으로 재정렬
				if(flag != prevflag[0] && flag == prevflag[1]) {
					for(i=0; i<nPosition+1; i++) {
						if(pCompared != NULL && pCompared->nAnnualIncome < pVisited->nAnnualIncome) {		// 연봉이 적은 순서대로 출력
							pPrev = pCompared;
							pCompared = pCompared->link;
						}
						else	break;		// 예외가 발생할 경우(pCompared) 바로 멈춰서 pHeader뒤 첫 노드 또는 문제가 발생한 pCompared와 pPrev 사이에 삽입시키도록 한다.
					}
					
				}else {
					for(i=0; i<nPosition+1; i++) {
						if(pCompared != NULL && pCompared->nAnnualIncome > pVisited->nAnnualIncome) {		// 연봉이 많은 순서대로 출력
							pPrev = pCompared;
							pCompared = pCompared->link;
						}
						else	break;		// 예외가 발생할 경우(pCompared) 바로 멈춰서 pHeader뒤 첫 노드 또는 문제가 발생한 pCompared와 pPrev 사이에 삽입시키도록 한다.
					}
				
				}	
				bRearrangeflag = YES;	// 종료 전 재정렬 필요!
				break;
	
			case ACD_ABL:		// 학력 순으로 재정렬
				if(flag != prevflag[0] && flag == prevflag[1]) {
					for(i=0; i<nPosition+1; i++) {
						if(pCompared != NULL && pCompared->nAcademicAbility < pVisited->nAcademicAbility) {		// 그 뒤, 다시 탭을 학력에 놓고 재정렬을 하게 되면 낮은 순서대로 출력
							pPrev = pCompared;
							pCompared = pCompared->link;
						}
						else	break;		// 예외가 발생할 경우(pCompared) 바로 멈춰서 pHeader뒤 첫 노드 또는 문제가 발생한 pCompared와 pPrev 사이에 삽입시키도록 한다.
					}
					
				}else {
					for(i=0; i<nPosition+1; i++) {
						if(pCompared != NULL && pCompared->nAcademicAbility > pVisited->nAcademicAbility) {		// 학력 높은 순서대로 먼저 출력
							pPrev = pCompared;
							pCompared = pCompared->link;
						}
						else	break;		// 예외가 발생할 경우(pCompared) 바로 멈춰서 pHeader뒤 첫 노드 또는 문제가 발생한 pCompared와 pPrev 사이에 삽입시키도록 한다.
					}
					
				}
				bRearrangeflag = YES;	// 종료 전 재정렬 필요!
				break;
		}//switch-case
			
		if(pPrev == NULL) {
			pVisited->link = pHeader;
			pHeader = pVisited;
		}else {
			pVisited->link = pPrev->link;
			pPrev->link = pVisited;	
		}
		//	 노드를 리스트에 연결시켜주는 과정
		nPosition++;	// 진행시킬 횟수를 1회 증가시킨다.
	}// while

	
	if(prevflag[0] == prevflag[1] && flag == prevflag[1])	prevflag[0] = NONE;		/*
																					전에 실행한 것과 전전에 실행한 것이 같으며 현재 실행까지도 같다는 것은
																					똑같은 정렬이 홀수번 실행됐다는 의미이고 이는 맨 처음 특정 조건에 대한 정렬을 실시한 것과 같음
																					따라서 prevflag[0](전 전에 실행된 것)에 NONE을 대입해준다
																					*/
	else													prevflag[0] = prevflag[1];
	prevflag[1] = flag;		// 정렬 1번이 실행되고 나면 해당 정렬을 실행하게 만든 값을 '이전 실행'을 나타내는 배열원소 prevflag[1]에 대입한다

	return bRearrangeflag;		// 재정렬 되었는지 아닌지의 여부를 저장하는 bRearrangeflag를 반환해준다.
}//arrangeData()
void searchMenu() {
	Search Data;	//특정 조건을 검색하는 search메뉴를 구현하기 위한 구조체.각각의 기준이 될만한 변수들이 구조체 안에 필드로서 선언되어있음.
	int nSelectedJob, i, nAnn_Inc, nAnn_Inc_big;/*
														nSelectedJob - 사용자가 직업을 기준으로 구분하여 특정 직업에 해당하는 사람만 보고 싶을 때, 커서를 이동하여 선택하게 되는데
																		이 때 선택된 직업 정보를 저장하는 변수.
														i - 반복 제어변수
														nAnn_Inc - 최소 소득 이상 되는 사람만을 보고 싶을 때 만~억 단위로 받게 되는데, '만'에 해당하는 금액을 입력받는 변수. 후에 
																	'억'단위가 입력되면 계산되어 ,구조체 Data.nAnnualIncome에 대입됨.
														nAnn_Inc_bic - '억'에 해당되는 금액을 입력받는 변수.
													
													*/

	system("cls");
	
	if(pHeader == NULL) {
		printf("아직 찾을 수 있는 정보가 없습니다.\n");
		printf("아무 키나 누르면 이전으로 돌아갑니다...\n");
		getch();
		return;
	} 		// 리스트가 비어있을 땐 찾을 수 있는 정보가 없다는 메세지를 출력하며 함수 종료.

	printf("==========================\n");
	printf("       < 대상검색 >       \n");
	printf("==========================\n");
	printf("당신의 성별을 선택하세요.\n");
	printf("   ○ 남자\n");
	printf("   ○ 여자\n");
	printf("==========================\n");		// 사용자의 성별을 입력받아 원하는 타겟의 성별을 설정하는 부분. 나의 성별과 항상 반대. (by key_shift)
	if (key_shift(VERTICAL, 0, 4, 0, 5, 0, 1, 1) == MALE)	Data.nGender = FEMALE;		// 나의 성별이 남자라면 타겟은 여자		
	else													Data.nGender = MALE;		// 반대의 경우는 타겟이 남자.
	fflush(stdin);

	system("cls");
	printf("==========================\n");
	printf("       < 나이제한 >       \n");
	printf("==========================\n");
	printf("[  ]세 이상 [  ]세 이하\n");
	printf("==========================\n");		// 타겟의 나이 범위를 설정하는 부분
	gotoxy(1, 3);	// 커서 이동
	scanf("%d", &Data.nMinAge);		// 최소 나이를 받는다
	fflush(stdin);
	gotoxy(13, 3);		// 커서 이동
	scanf("%d", &Data.nMaxAge);		// 최대 나이를 받는다
	fflush(stdin);
   
	for(i=0; i<11; i++) {
		Data.nJob[i] = NONE;	// 법조인부터 상관 없음까지 11개의 선택지에서 선택 받은 것을 중복으로 저장하기 위해 배열로 선언. 이것을 초기화 해주는 과정.	
	}//for

	system("cls");
	printf("==========================\n");
	printf("       < 직업제한>        \n");
	printf("==========================\n");
	printf("중복 선택 가능/재선택 시 취소\n");
	printf("   ○ 법조인\n");
	printf("   ○ 의료인\n");
	printf("   ○ 언론인\n");
	printf("   ○ 증권인\n");
	printf("   ○ 교직원\n");
	printf("   ○ 공무원\n");
	printf("   ○ 공학자\n");
	printf("   ○ 조종사\n");
	printf("   ○ 사업가\n");
	printf("   ○ 그 외\n");
	printf("   ○ 상관 없음\n");
	printf("   ○ 선택 종료\n");
	printf("==========================\n");		// 타겟의 직업을 선택하는 부분

	while(TRUE) {
		nSelectedJob = key_shift(VERTICAL, 0, 4, 0, 15, 0, 1, 0);
		//nSelected = 0 ~ 11 (0~9=직업 10=상관없음 11=다음)
		
		if(nSelectedJob == 11) {	// 다음을 선택 했다.
			for(i=0; i<11; i++) {		// 0번부터 10번 인덱스까지 SELECTED된 것이 있으면 탈출하도록 한다.	(for)
				if(Data.nJob[i] == SELECTED)	break;
			}//for
			if(i != 11)	break;		// 0번부터 10번 사이에 하나라도 SELECTED된 것이 없다면 탈출(while) >> 다음으로 넘어간다.
		}//while
		//다음() 선택 시 확인 후 다음or재선택
		
		if(nSelectedJob == 10) {	// 상관 없음을 선택한 경우
			for(i=0; i<10; i++) {	
				Data.nJob[i] = NONE;	// 0번부터 9번 인덱스까지 모두 NONE으로 만든다.
				gotoxy(3,4+i);		// 또한 각각의 커서를 움직여서 0번부터 9번의 선택 란을
				printf("○");	// 빈칸으로 만들어서 상관없음과 다른 것이 중복되는 일이 없도록 한다.
			}//for
			gotoxy(3,14);	// 상관없음란으로 가서
			printf("●");	// 선택되었음을 의미하는 검정 동그라미를 출력하고
			Data.nJob[10] = SELECTED;	// 선택으로 저장한다.
		}else if(Data.nJob[nSelectedJob] == SELECTED) {		// 만약 여기서 내가 선택한 것이 이미 선택된 것이라면
			Data.nJob[nSelectedJob] = NONE;		// 해당 배열 원소를 NONE으로 변경하여 선택되지 않았음을 저장하고
			gotoxy(3,nSelectedJob+4);		// 해당하는 직업으로 들어가 
			printf("○");		// 빈칸으로 만들어서 선택이 취소됐음을 표시한다. 
		}else if(Data.nJob[nSelectedJob] == NONE) {		// 만약 내가 선택한 것이 선택되지 않은 것이라면,(인덱스 번호 10번 상관없음 제외, 위에서 체크해줌)
			Data.nJob[nSelectedJob] = SELECTED;		// 해당 인덱스를 선택되었다고 해주고,
			gotoxy(3,nSelectedJob+4);		// 그 인덱스의 것을 나타내는 곳으로 커서를 이동해서
			printf("●");		// 선택되었음을 의미하는 검정동그라미를 출력하고
			gotoxy(3,14);		// 아까 상관없음의 경우는 여기서 하지 않음을 의미하므로 상관없음을 나타내는 곳으로 가서
			printf("○");		// 선택되지 않았음을 알리는 흰 동그라미를 출력하며
			Data.nJob[10] = NONE;		// 상관없음의 배열원소를 NONE으로 초기화한다.
		}//if- else if
	}//while

	system("cls");
	printf("==========================\n");
	printf("       < 연봉제한 >       \n");
	printf("==========================\n");
	printf("'0'입력 시 '상관없음'\n");
	printf("[    ]억[    ]만원 이상\n");
	printf("==========================\n");		// 타겟의 최소 연봉을 받는 부분
	gotoxy(1, 4);	// 커서를 []억쪽으로 이동
	scanf("%d", &nAnn_Inc_big);		// 최소 연 평균 소득 중 '억'단위에 해당하는 것을 받는다.
	fflush(stdin);
	gotoxy(9, 4);	// 커서를 []만원 쪽으로 이동
	scanf("%d", &nAnn_Inc);		// 최소 연 평균 소득 중 '만원'단위에 해당하는 것을 받는다.
	fflush(stdin);

	Data.nAnnualIncome = nAnn_Inc + nAnn_Inc_big * 10000;		// 저장 된 nAnn_Inc_big과 nAnn_Inc를 이용하여 최소 연 평균 소득을 계산하여 Data.nAnnualIncome에 대입한다.

	system("cls");
	printf("==========================\n");
	printf("       < 학력제한 >       \n");
	printf("==========================\n");
	printf("   ○ 상관없음\n");
	printf("   ○ 대학교   졸업\n");
	printf("   ○ 대학원   졸업 이상\n");
	printf("==========================\n");		// 타켓의 최소 학력을 받는 부분
	fflush(stdin);
	Data.nAcademicAbility = key_shift(VERTICAL, 0, 3, 0, 5, 0, 1, 1);	/*
																			1번 고졸, 2번 대졸, 3번 대졸 이상으로 정해놨는데 상관없음이 1로 들어가면서 번호가 하나씩 밀린다.
																			이를 방지하기 위해 1을 빼주고 수직으로만 움직이기 때문에 VERTICAL을 인수로 준다.
																		*/
	
	checkCondition(Data);	// 타겟의 요구조건이 들어있는 구조체를 파라미터로 보내어 해당 조건에 맞는 회원을 출력하도록 함.
}//SearchData()
void checkCondition(Search Data) {		// 타겟의 조건이 들어있는 구조체 Data를 파라미터로 받아 해당하는 조건의 회원을 모두 출력하는 함수
	ListNode *pVisited;		// 노드를 방문하면서 주어진 조건과 비교하는 역할을 하는 방문포인터 pVisited
	int i = 0, nCount = 0, nObject = 0, nDifGender = 0;		/*
																i - 반복 제어변수
																nCount - 노드의 위치값을 저장하여 출력해주는데 이용되는 변수
																nObject - 사용자가 설정한 조건과 딱 맞아 떨어지는 사람 수를 저장하는 변수
																nDifGender - 사용자와 반대되는 성을 가진 사람의 수를 저장하는 변수
															*/
	float rate;		// 전체 회원 중 내 이상형의 성별과 맞는 사람과, 조건까지 충족하는 사람의 비율을 저장하는 변수

	system("cls");
	gotoxy(0,0);
	printf("=================================================\n");
	printf("                    < 대상검색 >                 \n");
	printf("=================================================\n");
	printf("| 이 름 | 성 별 | 나 이 | 직 업 | 연 봉 | 학 력 |\n");
	printf("=================================================\n");		// 대상 검색의 결과를 나타내는 기본 출력 폼

	pVisited = pHeader;		// pVisited가 첫 노드를 가리키게 함
		
	while(pVisited != NULL) {
		if(pVisited->nGender == Data.nGender) {		// 먼저 성별이 같은 경우
			nDifGender++;		// 비율 계산을 위한 사용자와 다른 성별의 회원의 수를 발견할 때 마다 1씩 늘려감
			if(pVisited->nAge >= Data.nMinAge && pVisited->nAge <= Data.nMaxAge) {		// 나이가 충족되는 경우
				if(Data.nJob[10] == SELECTED) {		// 위에서 직업 조건 중 상관 없음을 선택했을 경우
					i = 0;		// i를 0으로 초기화
				}else {		// 상관없음을 선택하지 않고, 무언가를 선택한 경우
					for(i=0; i<10; i++) {	// 0번 법조인부터 9번 그 외까지 순회하면서 해당 노드의 직업과 넘겨준 이상형의 직업값이 일치하는 지 비교
						if(Data.nJob[i] == SELECTED && pVisited->nJob == i+1)	break;
					}// for
				}// if-else
				if(i != 10) {	// else에서 원하는 사람을 찾지 못했을 경우, i==10이 된다. break가 실행되지 않은 것. 이 경우라면 그대로 나가고, 현재 아닌 경우니까 밑의 if실행
					if(Data.nAnnualIncome <= pVisited->nAnnualIncome) {		// 최소 연봉조건을 만족
						if(Data.nAcademicAbility <= pVisited->nAcademicAbility) {	// 최소 학력 조건까지 만족
							printData(nCount);		// 해당 노드값을 넘겨주어 해당 회원을 출력하게 함.
							nObject++;		// 목표를 100%충족하는 이상형의 수를 1 증가시킨다. rate구할 때 사용.
						}//if
					}//if
				}//if
			}//if
		}//if
		pVisited = pVisited->link;		// 한 칸 전진. 한 노드에 대해서 위의 것들을 다 실행
		nCount++;		// 노드의 position값도 하나 증가시킴
	}// while

	rate = (float)100*nObject/nDifGender;		// 이상형의 성별을 가지고 있는 사람 수 대비 성별 뿐만 아니라 다른 조건까지 모두 충족하는 이상형의 비율을 구하고 저장

	if(nObject != 0) {		// 이상형이 1명이라도 존재할 경우
		printf("=================================================\n");
		printf("당신의 이상형은 %d명의 이성 중 %d명이군요...\n", nDifGender, nObject);
		printf("비율은 %.2f％입니다...\n", rate);
		printf("=================================================\n");
		printf("나가시려면 아무 키나 누르세요...");		// 결과 출력
		getch();
	}else if(nObject == 0) {		// 터무니없는 조건을 제시하여 이상형의 숫자가 0일 경우의 결과창. 눈을 낮춰 조건보단 인간미를 보도록 하자 ^^.... 
		printf("찾으시는 회원이 없습니다...\n");
		printf("눈을 낮추지 않으면...평생...모쏠\n");	
		printf("=================================================\n");
		printf("나가시려면 아무 키나 누르세요...");
		getch();
	}//if-else if
}//checkCondition()
void initializeMenu() {
	ListNode *pVisited;		// 노드를 하나하나 초기화해주기 위해서 각 노드를 순회하며 초기화 해주는 역할을 하는 구조체 포인터 pVisited.
	int flag;		// 초기화 실행 여부를 저장하는 변수.

	system("cls");		// 화면 지우기
	if (pHeader == NULL) {
		printf("아직 초기화할 정보가 없습니다.\n");
		printf("아무 키나 누르면 이전으로 돌아갑니다...");
		getch();
		return;
	}	// pHeader == NULL, 즉 리스트에 아무 데이터도 존재하지 않는다면, initialize Menu 역시 실행할 필요가 없음. 따라서 이 경우 함수를 종료. 

	printf("==========================\n");
	printf("        < 초기화 >        \n");
	printf("==========================\n");
	printf("정말로 초기화하시겠습니까?\n");
	printf("               YES |  NO  \n");
	printf("==========================\n");		// 초기화 여부를 묻는 기본 출력폼.
	flag = key_shift(HORIZONTAL, 16, 4, 22, 4, 6, 0, 1);		// Yes or No의 경우이므로 HORIZONTAL을 인수로 보내고 출력폼에 맞게 x좌표와 y좌표를 설정해서 파라미터로 보냄. 시작인덱스는 1.

	system("cls");		// 화면 지우기
	if (flag == YES) {		// 사용자가 초기화 하고자 원한다면,
		while (pHeader != NULL) {
			pVisited = pHeader;		// 일단 pVisited가 첫 노드를 가리키게 한 뒤
			pHeader = pHeader->link;		// pHeader가 pHeader의 다음 노드를 가리키게 하면서 첫 노드와의 연결을 끊음.
			free(pVisited);		// 첫 노드는 pVisited가 가리키고 있을 테니 이를 free해주면 노드가 초기화 된다.
		}//while
		// 초기화 과정
		printf("초기화가 완료되었습니다.\n");
		printf("계속하시려면 아무키나 누르세요...");		// 초기화가 완료되었음을 출력
	}
	else {
		printf("초기화가 취소되었습니다.\n");
		printf("계속하시려면 아무키나 누르세요...");		// 사용자가 NO를 선택하여 초기화가 실행되지 않았음을 출력
	}
	getch();	// 아무 키나 입력받고, 다시 main함수로 돌아감.
}//initialize()

void outputFileMenu() {		// 외부에 저장한 파일을 불러오는 메뉴
	FILE *fp;		// 불러온 파일을 저장할 포인터
	char strFileName[40];	// 불러올 파일 명을 저장할 배열 선언
	int i, nodeCount = 0, nEOF, flag;	// for 반복문에서 쓸 변수 i, 노드개수를 세기 위한 카운트변수 선언 후 0으로 초기화, 마지막값 변수 선언, yes or no 선택을 위한 변수 선언
	ListNode *pData, *pVisited, *pPrev;

	system("cls");
	printf("==========================\n");
	printf("        < 가져오기 >        \n");
	printf("==========================\n");
	printf("파일명을 입력하세요.\n");
	printf("-> \n");
	printf("==========================\n");
	gotoxy(3, 4);
	scanf("%s", strFileName);		// 가져 올 파일명 입력

	fp = fopen(strFileName, "rb");		// read binary모드로 파일을 읽음. fp가 해당 바이너리 파일을 가리키게 됨

	if (fp == NULL) {	// 파일이 존재하지 않거나, 다른 이유에서 실패한 경우
		printf("%s 파일이 존재하지 않습니다.\n", strFileName);
		printf("나가시려면 아무 키나 누르세요...");
		getch();
		return;		// 파일을 열 수 없음을 출력하고 함수 종료
	}//if

	if (pHeader != NULL) {		// pHeader에 리스트가 연결 되어있는 경우, 즉 NULL이 아닐 때
		gotoxy(0, 6);	// 커서를 이동하고
		printf("기존의 데이터에 추가됩니다.\n");
		printf("파일을 불러오시겠습니까?\n");		// 프로그램 상에서 적재되어 연결된 데이터에 파일의 데이터가 추가됨을 경고하는 창 출력
		printf("               YES |  NO  \n");
		printf("==========================\n");
		flag = key_shift(HORIZONTAL, 16, 8, 22, 8, 6, 0, 1);		// key_shift함수를 통해 사용자의 의사를 받음

		if (flag == NO) {		// '아니오'를 선택했다면,
			gotoxy(0, 10);
			printf("파일 불러오기가 취소되었습니다.\n");
			printf("나가시려면 아무키나 누르세요...");		// 파일불러오기가 취소되었음을 출력하고
			getch();
			fclose(fp);
			return;		//함수 종료
		}// if
	}//if
	else flag = NO;		// 뒤에서 이 flag가 한 번 더 사용되므로, 다시 NO로 대입해준다.

	fseek(fp, 0, SEEK_END);		// 파일포인터 fp를 맨 마지막 위치로 보내기

	nEOF = ftell(fp);	// SEEK_SET부터 현재 마지막 SEEK_END까지 총 데이터의 용량을 nEOF에 저장. 후에 노드 개수 구하는 곳에서 이용.
	nodeCount = nEOF / sizeof(ListNode);	// 리스트의 총 용량을 구조체 크기로 나눠 노드 갯수를 구함
	rewind(fp);		// 다시 처음으로 돌려놓았음.

	for (i = 0; i<nodeCount; i++) {		// 받은 nodeCount, 노드의 갯수만큼
		pData = (ListNode*)malloc(sizeof(ListNode));	// pData 포인터의 동적 메모리할당
		fread(pData, sizeof(ListNode), 1, fp);			// pData에 연결된 파일에서 ListNode 구조체의 크기만큼의 데이터 읽어 시작주소에 저장후 블록 개수 반환하기
		pData->link = NULL;		// 아직 연결되지 않았으므로 pData의 링크필드를 NULL로 초기화

		if (pHeader == NULL)		// 노드가 없는 경우
			pHeader = pData;	// pHeader를 pData에 연결해준다.
		else{		// 노드가 하나라도 있는 경우
			pVisited = pHeader;		// pHeader가 첫 노드를 가리키게 함
			pPrev = NULL;		// 백업 포인터는 출발하지 않았으므로 NULL

			while (pVisited != NULL && strcmp(pData->strName, pVisited->strName) > 0) {		// 이름순으로 정렬하기 위해 위치찾기
				pPrev = pVisited;		
				pVisited = pVisited->link;		// pPrev와 pVisited가 전진
				if (pVisited == NULL) break;	// pVisited가 NULL이면 while문 탈출한다.
			}//while

			if (pPrev == NULL) {	// 위의 과정을 거치지 않았을 경우, 즉 처음으로 들어가야 할 경우
				pData->link = pHeader;		// pData의 링크필드를 pHeader가 가리키고 있는 첫 노드를 가리키게 하고
				pHeader = pData;		// pHeader가 pData를 가리키게 한다.
			}//if
			else {
				pData->link = pPrev->link;
				pPrev->link = pData;		// 이 외의 경우 연걸
			}//else
		}//else
	}//for

	if (flag == NO)	gotoxy(0, 6);
	else			gotoxy(0, 10);
	printf("파일을 불러오기가 완료되었습니다...\n");
	printf("나가시려면 아무 키나 누르세요...");		// 결과 출력
	getch();

	fclose(fp);		// 파일 닫기
}//outputFileMenu()
void inputFileMenu() {		// 입력한 내용을 외부파일로 저장하기
	FILE *fp;		// 저장할 파일을 가리킬 포인터
	ListNode *pVisited, *pData, *pPrev;
	char strFileName[40];		// 저장할 파일 명
	int i, nodeCount = 0, flag;		// for 반복문을 위한 변수 i, 노드의 갯수를 세기위한 변수 선언과 0으로 초기화, Yes or No 선택을 위한 변수선언

	system("cls");
	if (pHeader == NULL) {		// 입력된 정보가 없는 경우
		printf("아직 내보낼 정보가 없습니다.\n");
		printf("아무 키나 누르면 이전으로 돌아갑니다...");
		getch();
		return;
	}//if
	// 입력된 정보가 있는 경우
	printf("==========================\n");
	printf("       < 내보내기 >       \n");
	printf("==========================\n");
	printf("파일을 내보내시겠습니까?  \n");
	printf("               YES |  NO  \n");
	printf("==========================\n");
	flag = key_shift(HORIZONTAL, 16, 4, 22, 4, 6, 0, 1);		// 수평으로 움직이며, x좌표는 16~22 사이에서 한 번에 6칸씩 이동, y좌표는 4에서 고정된다, 이 값은 flag에 대입

	if(flag == NO) {   // 내보내고자 하지 않을 경우
		gotoxy(0, 6);	//x,y 좌표 (0,6)으로 커서 이동
		printf("파일 내보내기가 취소되었습니다.\n");
		printf("나가시려면 아무키나 누르세요...");
		getch();
		return;
	}//if

	system("cls");
	gotoxy(0, 0);	// x,y좌표 (0,0)으로 이동
	printf("==========================\n");
	printf("       < 내보내기 >       \n");
	printf("==========================\n");
	printf("파일명을 입력하세요.\n");
	printf("-> \n");
	printf("==========================\n");
	gotoxy(3, 4);	// x,y좌표 (3,4)로 커서 이동
	scanf("%s", strFileName);	// 파일 명을 입력받아 프로그램 상에 저장된 데이터를 저장할 파일을 만든다. 

	fp = fopen(strFileName, "wb");		//블록단위로 파일에 쓰기

	if (fp == NULL) {	// 파일포인터에 할당된 파일이 없음
		system("cls");
		printf("일시적 오류가 발생하였습니다.\n");
		printf("다시 시도해 주십시오.\n");
		getch();
		return;
	}//if

	if (strcmp("file.dat", strFileName) == 0) {		// 저장할 파일 명이 file.dat(회원정보가 저장된 메인파일) 일 경우
		gotoxy(0, 6);	// x,y좌표 (0,6)으로 커서 이동
		printf("이 파일은 메인 파일입니다.\n");
		printf("그래도 덮어 쓰시겠습니까?\n");
		printf("               YES |  NO  \n");
		printf("==========================\n");
		flag = key_shift(HORIZONTAL, 16, 8, 22, 8, 6, 0, 1);	// 수평으로만 이동, x좌표는 16~22 사이에서 한 번에 6칸 씩 이동하고 , y좌표는 8에서 고정, 이 값은 flag에 대입한다.
		if(flag == NO) {	// NO를 선택한 경우
			gotoxy(0, 10);	// x,y좌표 (0,10)으로 커서 이동
			printf("파일 내보내기가 취소되었습니다.\n");
			printf("나가시려면 아무키나 누르세요...");
			getch();
			return;
		}//if
	}//if

	pVisited = pHeader;		// pVisited가 맨 첫 번째 노드 가르킨다.
	while (pVisited != NULL) {		//pVisited가 가르키는 값이 없는 경우
		fwrite(pVisited, sizeof(ListNode), 1, fp);		//pVisited부터 저장된 ListNode 구조체의 크기 바이트의 데이터를 fp에 연결된 파일에 쓴다.
		pVisited = pVisited->link;		//pVisited 전진
	}//while
	gotoxy(0, 6);		// x,y좌표 (0,10)으로 커서 이동
	printf("파일을 내보내기가 완료되었습니다...\n");
	printf("나가시려면 아무 키나 누르세요...");
	getch();

	fclose(fp);
}//inputFileMenu()
void about() {
	system("cls");	
	printf("==========================\n");
	printf("       < 제작정보 >       \n");
	printf("==========================\n");
	printf("프로그램 : 결혼해듀오\n");
	printf("제작팀   : 2KJP\n\n");
	printf("버젼        : ver 5.2\n");
	printf("최종 수정일 : 2015 12 08\n");
	printf("==========================\n");		// 결혼정보회사 관리 프로그램을 제작한 팀원들의 제작 정보와 저작권 정보를 출력
	getch();
}//about()
int key_shift(int flag, int min_x, int min_y, int max_x, int max_y, int tab_x, int tab_y, int nIndex) {
	char chInput;		// 방향키도 곧 문자라고 할 수 있음. 방향키 정보를 저장해 줄 문자열 변수 chInput.
	int x = min_x, y = min_y;	// x좌표와 y좌표를 저장하는 변수 각각 x와 y. 각각 파라미터로 전달받은 최소값으로 초기화 됨.
	int row_size;	/*
					만약 x방향, y방향 모두 움직일 수 있게 된다면,
					y방향으로 움직일 때 인덱스는 차별화 되어야 할 것임. 가령, 가로는 1씩 증가하더라도
					세로는 다른 값으로 차별화를 주어 늘게 해야 현재 움직이고 있는 방향과 인덱스를 매칭할 수 있음.
					세로로 움직일 때 인덱스를 특정한 값만큼 새롭게 증가시키는 변수.
					*/

	row_size = max_x - min_x + 1;		// max_x와 min_x의 차에 1 더한 만큼 인덱스가 늘어났다 줄어났다 한다. (하지만 우리 프로그램에선 단방향만 사용함. 그래서 x든 y든 인덱스는 1씩 변화.)

	gotoxy(x, y);		// x의 최솟값과 y의 최솟값의 좌표로 커서를 이동시킨다.
	if (flag == VERTICAL) {		// 만약 수직으로만 움직이기로 했다면,
		printf("->");		// ->를 표시하여 현재 커서가 어디에 와있는지를 알 수 있게 한다.
		gotoxy(0, 0);		// (0,0)으로 커서 이동.
	}
	else if (flag == HORIZONTAL) {		// 만약 수평으로만 움직이기로 했다면,
		gotoxy(x - 3, y);		// 현재 x값의 3칸 뒤로 가서
		printf("[");	// [를 출력하고
		gotoxy(x + 3, y);		// x값의 3칸 앞으로 가서 
		printf("]");	// ]를 출력하는 식으로 표시하여 현재 커서가 어디에 와있는지를 알 수 있게 한다.
		gotoxy(0, 0);	// (0,0)으로 커서 이동
	}

	while (TRUE) {
		chInput = getch();		// 방향키 값을 getch()로 받음 (밑에 메세지 출력 없이 바로 받게 하는 함수)
		gotoxy(x, y);		// x좌표와 y좌표를 조합하여 커서 이동
		if (flag == VERTICAL) {		// 수직 이동의 경우
			gotoxy(x, y);
			printf("  ");	// 다른 곳으로 이동하게 되면, 위에 출력했던 ->표시 지우는 부분. 지우지 않는다면 계속해서 남게 되어 종국엔 내 커서가 어디있는지 알 수 없게 됨.
		}
		else if (flag == HORIZONTAL) {		// 수평 이동의 경우
			gotoxy(x - 3, y);
			printf(" ");
			gotoxy(x + 3, y);
			printf(" ");	// 마찬가지로 다른 곳으로 이동하게 되면 [ 와 ]를 지워 내 커서가 어느 부분에 있는지 확실하게 알게 한다.
		}
		switch (chInput) {		// 화살표로 받은 chInput을 분기로 하여 키보드의 움직임에 따라 특정 내용 수행.
		case ENTER:		// 해당 메뉴 또는 선택을 수행하고자 할 때
			return nIndex;		// Index값을 반환하면서 함수를 끝마침.
			break;
		case LEFT:		// 좌로 움직일 때
			if (flag == HORIZONTAL) {	// 좌, 우로 움직이는 경우는 HORIZOTAL 상수가 파라미터로 전해졌을 때. 따라서 이 때만 nIndex와 x좌표를 변경시키는 if문을 활용.
				x = x - tab_x;
				if (x < min_x)	x = min_x;		// x의 최소좌표보다 작아지게 되면 계속 커서를 최소값에 두고, nIndex값도 그대로 유지시킨다.
				else			nIndex--;		// 아니라면 인덱스 값을 감소 시킨다.
			}
			break;
		case RIGHT:
			if (flag == HORIZONTAL) {	// LEFT의 경우와 마찬가지.
				x = x + tab_x;
				if (x > max_x)	x = max_x;		// x의 최대좌표보다 커지게 되면 계속 커서를 최대값에 두고, nIndex값도 그대로 유지시킨다.
				else			nIndex++;		// 아니라면 인덱스 값을 증가 시킨다.
			}
			break;
		case UP:
			if (flag == VERTICAL) {		// 상, 하로 움직이는 경우는 VERTICAL 상수가 파라미터로 전해졌을 때. 따라서 이 때만 nIndex와 y좌표를 변경시키는 if문을 활용.
				y = y - tab_y;
				if (y < min_y)	y = min_y;		// y의 최소좌표보다 작아지게 되면 계속 커서를 최소값에 두고, nIndex도 그대로 유지
				else			nIndex -= row_size;		// 아니라면 인덱스 값을 감소 시킨다.
			}
			break;
		case DOWN:
			if (flag == VERTICAL) {		// UP의 경우와 마찬가지.
				y = y + tab_y;
				if (y > max_y)	y = max_y;		// y의 최대좌표보다 커지게 되면 계속 커서를 최대값에 두고, nIndex 값도 그대로 유지시킨다.
				else			nIndex += row_size;		// 아니라면 인덱스 값을 증가 시킨다.
			}
			break;
		}//switch-case
		gotoxy(x, y);	// switch문을 통해 변경된 x좌표와 y좌표를 반영하는 gotoxy. 
		if (flag == VERTICAL) {
			printf("->");
			gotoxy(0, 0);		// 수직으로 움직일 경우 ->로 커서가 바뀐 곳에 다시 출력
		}
		else if (flag == HORIZONTAL) {
			gotoxy(x - 3, y);
			printf("[");
			gotoxy(x + 3, y);
			printf("]");
			gotoxy(0, 0);		// 수평으로 움직일 경우 [ ]로 커서가 바뀐 곳에 다시 출력
		}
	}//while
}//key_shift()
void gotoxy(int x, int y) {
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}//gotoxy()
// 커서의 위치를 내가 지정한 x값과 y값으로 옮겨주는 함수 gotoxy. 파라미터로 보내 준 x, y로 커서를 옮김.