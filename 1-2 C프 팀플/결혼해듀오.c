#include "결혼해듀오.h"
int main() {
	int bIterationFlag = TRUE;
	int nSelectedMainMenu;

	while (bIterationFlag) {
		nSelectedMainMenu = displayMainMenu();

		switch (nSelectedMainMenu) {
		case INSERT:
			insertMenu();
			break;
		case MANAGE:
			manageMenu();
			break;
		case OUTLINE:
			
			break;
		case SEARCH:
		
			break;
		case INITIALIZE:
			initializeMenu();
			break;
		case SAVE:
			
			break;
		case LOAD:
			
			break;
		case ABOUT:
			about();
			break;
		case EXIT:
			system("cls");
			printf("BYE-BYE\n");
			bIterationFlag = FALSE;
			break;
		}
	}

	return 0;
}
int displayMainMenu() {
	int nMenu;

	system("cls");
	printf("==========================\n");
	printf(" 결혼정보회사관리프로그램\n");
	printf("--------------------------\n");
	printf("  ○ 정보 입력\n");
	printf("  ○ 정보 검색\n");
	printf("  ○ 대상 찾기\n");
	printf("  ○ 초기화\n");
	printf("  ○ 가져오기\n");
	printf("  ○ 내보내기\n");
	printf("  ○ 제작정보\n");
	printf("  ○ 나가기\n");
	printf("========================\n");
	nMenu = key_shift(ARROW, 0, 3, 0, 10, 0, 1);

	return nMenu;
}

void insertMenu() {
	ListNode *pData;
	pData = (ListNode *)(malloc(sizeof(ListNode)));
	if (pData == NULL) {
		printf("\n일시적 오류가 발생하였습니다. 다시 시도해 주십시오.\n");
		return;
	}
	pData->link = NULL;
	system("cls");
	printf("=====================\n");
	printf("   < 사용자 이름 >\n ");
	printf("---------------------\n");
	scanf("%s", pData->strName);

	system("cls");
	printf("================\n");
	printf("   < 성별 >\n");
	printf("----------------\n");
	printf("  ○ 여자\n");
	printf("  ○ 남자\n");
	printf("----------------\n");
	pData->nGender = key_shift(ARROW, 0, 3, 0, 4, 0, 1);

	system("cls");
	printf("================\n");
	printf("  < 나이 >\n");
	printf("----------------\n");
	scanf("%d", &(pData->nAge));

	system("cls");
	printf("================\n");
	printf("   < 직업 >\n");
	printf("----------------\n");
	printf("  ○ 의사\n");
	printf("  ○ 변호사\n");
	printf("  ○ 판사\n");
	printf("  ○ 자영업자\n");
	printf("----------------\n");
	pData->nJob = key_shift(ARROW, 0, 3, 0, 6, 0, 1);


	system("cls");
	printf("================\n");
	printf("   < 연봉 >\n");
	printf("----------------\n");

	scanf("%d", &(pData->nAnnualIncome));

	system("cls");
	printf("===================\n");
	printf("    < 학력 >\n");
	printf("------------------\n");
	printf("  ○ 고등학교 졸업\n");
	printf("  ○ 대학교 졸업\n");
	printf("  ○ 대학원 이상\n");
	printf("------------------\n");
	pData->nAcademicAbility = key_shift(ARROW, 0, 3, 0, 5, 0, 1);
	insertData(pData);

}
void insertData(ListNode *pData) {

	ListNode *pVisited, *pPrev;

	if (pHeader == NULL) {
		pHeader = pData;
	}

	else {
		pVisited = pHeader;
		pPrev = NULL;

		while (strcmp(pData->strName, pVisited->strName)>0
			&& pVisited != NULL) {
			pPrev = pVisited;
			pVisited = pVisited->link;
			if (pVisited == NULL) break;
		}

		if (pPrev == NULL) {
			pData->link = pHeader;
			pHeader = pData;
		}

		else {

			pData->link = pPrev->link;
			pPrev->link = pData;

		}

	}




}

void printMenu() {
	ListNode *pVisited;
	pVisited = pHeader;
	system("cls");

	while (pVisited != NULL) {


		printf("%s\n", pVisited->strName);
		pVisited = pVisited->link;


	}

	system("pause");


}

int key_shift(int flag, int min_x, int min_y, int max_x, int max_y, int tab_x, int tab_y) {
	char chInput;
	int x = min_x, y = min_y;
	int row_size, nIndex = 1;

	row_size = max_x - min_x + 1;

	gotoxy(x, y);
	if (flag == ARROW) {
		printf("->");
		gotoxy(0, 13);
	}

	while (TRUE) {
		chInput = getch();
		gotoxy(x, y);
		printf("  ");
		switch (chInput) {
		case ENTER:
			return nIndex;
		case LEFT:
			x = x - tab_x;
			if (x < min_x)	x = min_x;
			else			nIndex--;
			break;
		case RIGHT:
			x = x + tab_x;
			if (x > max_x)	x = max_x;
			else			nIndex++;
			break;
		case UP:
			y = y - tab_y;
			if (y < min_y)	y = min_y;
			else			nIndex -= row_size;
			break;
		case DOWN:
			y = y + tab_y;
			if (y > max_y)	y = max_y;
			else			nIndex += row_size;
			break;
		}
		gotoxy(x, y);
		if (flag == ARROW) {
			printf("->");
			gotoxy(0, 13);
		}
	}
}
void gotoxy(int x, int y) {
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
} //

void manageMenu() {
	ListNode *pVisited;
	pVisited = pHeader;

	system("cls");
	printf("============================================================================\n");
	printf("                                 < 전체보기 >                      \n");
	printf("============================================================================\n");
	printf("  |  이 름  |  성 별  |  나 이  |  직 업  |  연 봉  |  학 력  |  나가기  |\n");
	printf("============================================================================\n");

	printData();

}
void printData() {
	ListNode *pVisited = pHeader;
	int position = 1;
	int Modi_or_Del_Index;
	if (pHeader == NULL) {

		printf("\t	   정보가 없어 해당 기능을 실행할 수 없습니다.\n");

	}
	else {
		while (pVisited != NULL) {

			printf("  %9s  ", pVisited->strName);

			if (pVisited->nGender == 1) {
				printf("    %s  ", "여");
			}
			else if (pVisited->nGender == 2) {
				printf("    %s  ", "남");
			}

			printf("     %3d    ", pVisited->nAge);

			if (pVisited->nJob == 1) {
				printf("%5s   ", "A");

			}
			else if (pVisited->nJob == 2) {
				printf("%5s   ", "B");

			}
			else if (pVisited->nJob == 3) {
				printf("%5s   ", "C");

			}
			else if (pVisited->nJob == 4) {
				printf("%5s   ", "D");

			}
			else if (pVisited->nJob == 5) {
				printf("%5s   ", "E");

			}
			else if (pVisited->nJob == 6) {
				printf("%5s   ", "F");

			}
			else if (pVisited->nJob == 7) {
				printf("%5s   ", "G");

			}
			else if (pVisited->nJob == 8) {
				printf("%5s   ", "H");

			}
			else if (pVisited->nJob == 9) {
				printf("%5s   ", "I");

			}
			else if (pVisited->nJob == 2) {
				printf("%5s   ", "J");

			}

			printf("   %4d", pVisited->nAnnualIncome);

			if (pVisited->nAcademicAbility == 1) {
				printf("  %10s    ", "고졸");

			}

			if (pVisited->nAcademicAbility == 2) {
				printf("  %10s    ", "대졸");

			}
			if (pVisited->nAcademicAbility == 3) {
				printf("  %10s     ", "대학원졸");
			}
			printf("\n");
			pVisited = pVisited->link;
			position++;
		}

	}

	Modi_or_Del_Index = key_shift(NONE, 2, 3, 70, position + 1, 10, 1);
	askDelModi(Modi_or_Del_Index);
}
void askDelModi(int nDataAction) {
	int nMenu;

	system("cls");
	printf("=======================\n");
	printf("      항목 관리\n");
	printf("=======================\n");
	printf("  ○ 회원정보삭제\n");
	printf("  ○ 회원정보수정\n");
	printf("  ○ 이전으로..\n");
	printf("-----------------------\n");

	nMenu = key_shift(ARROW, 0, 3, 0, 5, 0, 1);


	if (nMenu == 3) { return; }
	else if (nMenu == 1) {
		deleteData(nDataAction);
	}
	else if (nMenu == 2) {
		modifyData(nDataAction);
	}
}

void deleteData(int nDelIndex) {

	int i;
	system("cls");
	printf("=======================\n");
	printf("      회원정보삭제\n");
	printf("=======================\n");
	ListNode *pVisited, *pPrev;
	pVisited = pHeader;
	pPrev = NULL;
	if (nDelIndex / 69 == 0) {

		pHeader = pHeader->link;
		pVisited->link = NULL;
		printf(" %s회원의 정보 삭제완료!\n", pVisited->strName);
		system("pause");
		free(pVisited);

	}

	else {
		for (i = 0; i < nDelIndex / 69; i++) {
			pPrev = pVisited;
			pVisited = pVisited->link;
			if (pVisited == NULL) break;

			else {
				pPrev->link = pVisited->link;
				pVisited->link = NULL;
				printf(" %s회원의 정보 삭제완료!\n", pVisited->strName);
				system("cls");
				free(pVisited);

			}

		}
	}

}
void modifyData(int nModiIndex) {


}

void initializeMenu() {
	ListNode *pVisited;
	int flag;

	if (pHeader == NULL) {
		system("cls");
		printf("아직 초기화할 정보가 없습니다.\n");
		printf("아무 키나 누르면 이전으로 돌아갑니다...\n");
		getchar();
		return;
	}

	system("cls");
	printf("==========================\n");
	printf("        < 초기화 >        \n");
	printf("==========================\n");
	printf("정말로 초기화하시겠습니까?\n");
	printf("                [YES | NO]\n");
	printf("==========================\n");
	flag = key_shift(NONE, 18, 4, 23, 4, 5, 0);

	system("cls");
	printf("==========================\n");
	printf("        < 초기화 >        \n");
	printf("==========================\n");

	if (flag == YES) {
		while (pHeader != NULL) {
			pVisited = pHeader;
			pHeader = pHeader->link;
			free(pVisited);
		}
		printf("초기화가 완료되었습니다.\n");
		printf("계속하시려면 아무키나 누르세요...\n");
	}
	else {
		printf("초기화가 취소되었습니다.\n");
		printf("계속하시려면 아무키나 누르세요...\n");
	}
	printf("==========================\n");
	getchar();
}

void about() {
	system("cls");
	printf("\n\n");

	printf("\t===================================\n");
	printf("\t   결혼해 듀오 ver 1.0\n");
	printf("\n");
	printf("\t   Programmed by team 2KJP\n");
	printf("\n");
	printf("\t   Copyright@ team 2KJP\n");
	printf("\t===================================\n");
}
