#include "��ȥ�ص��.h"
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
	printf(" ��ȥ����ȸ��������α׷�\n");
	printf("--------------------------\n");
	printf("  �� ���� �Է�\n");
	printf("  �� ���� �˻�\n");
	printf("  �� ��� ã��\n");
	printf("  �� �ʱ�ȭ\n");
	printf("  �� ��������\n");
	printf("  �� ��������\n");
	printf("  �� ��������\n");
	printf("  �� ������\n");
	printf("========================\n");
	nMenu = key_shift(ARROW, 0, 3, 0, 10, 0, 1);

	return nMenu;
}

void insertMenu() {
	ListNode *pData;
	pData = (ListNode *)(malloc(sizeof(ListNode)));
	if (pData == NULL) {
		printf("\n�Ͻ��� ������ �߻��Ͽ����ϴ�. �ٽ� �õ��� �ֽʽÿ�.\n");
		return;
	}
	pData->link = NULL;
	system("cls");
	printf("=====================\n");
	printf("   < ����� �̸� >\n ");
	printf("---------------------\n");
	scanf("%s", pData->strName);

	system("cls");
	printf("================\n");
	printf("   < ���� >\n");
	printf("----------------\n");
	printf("  �� ����\n");
	printf("  �� ����\n");
	printf("----------------\n");
	pData->nGender = key_shift(ARROW, 0, 3, 0, 4, 0, 1);

	system("cls");
	printf("================\n");
	printf("  < ���� >\n");
	printf("----------------\n");
	scanf("%d", &(pData->nAge));

	system("cls");
	printf("================\n");
	printf("   < ���� >\n");
	printf("----------------\n");
	printf("  �� �ǻ�\n");
	printf("  �� ��ȣ��\n");
	printf("  �� �ǻ�\n");
	printf("  �� �ڿ�����\n");
	printf("----------------\n");
	pData->nJob = key_shift(ARROW, 0, 3, 0, 6, 0, 1);


	system("cls");
	printf("================\n");
	printf("   < ���� >\n");
	printf("----------------\n");

	scanf("%d", &(pData->nAnnualIncome));

	system("cls");
	printf("===================\n");
	printf("    < �з� >\n");
	printf("------------------\n");
	printf("  �� ����б� ����\n");
	printf("  �� ���б� ����\n");
	printf("  �� ���п� �̻�\n");
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
	printf("                                 < ��ü���� >                      \n");
	printf("============================================================================\n");
	printf("  |  �� ��  |  �� ��  |  �� ��  |  �� ��  |  �� ��  |  �� ��  |  ������  |\n");
	printf("============================================================================\n");

	printData();

}
void printData() {
	ListNode *pVisited = pHeader;
	int position = 1;
	int Modi_or_Del_Index;
	if (pHeader == NULL) {

		printf("\t	   ������ ���� �ش� ����� ������ �� �����ϴ�.\n");

	}
	else {
		while (pVisited != NULL) {

			printf("  %9s  ", pVisited->strName);

			if (pVisited->nGender == 1) {
				printf("    %s  ", "��");
			}
			else if (pVisited->nGender == 2) {
				printf("    %s  ", "��");
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
				printf("  %10s    ", "����");

			}

			if (pVisited->nAcademicAbility == 2) {
				printf("  %10s    ", "����");

			}
			if (pVisited->nAcademicAbility == 3) {
				printf("  %10s     ", "���п���");
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
	printf("      �׸� ����\n");
	printf("=======================\n");
	printf("  �� ȸ����������\n");
	printf("  �� ȸ����������\n");
	printf("  �� ��������..\n");
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
	printf("      ȸ����������\n");
	printf("=======================\n");
	ListNode *pVisited, *pPrev;
	pVisited = pHeader;
	pPrev = NULL;
	if (nDelIndex / 69 == 0) {

		pHeader = pHeader->link;
		pVisited->link = NULL;
		printf(" %sȸ���� ���� �����Ϸ�!\n", pVisited->strName);
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
				printf(" %sȸ���� ���� �����Ϸ�!\n", pVisited->strName);
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
		printf("���� �ʱ�ȭ�� ������ �����ϴ�.\n");
		printf("�ƹ� Ű�� ������ �������� ���ư��ϴ�...\n");
		getchar();
		return;
	}

	system("cls");
	printf("==========================\n");
	printf("        < �ʱ�ȭ >        \n");
	printf("==========================\n");
	printf("������ �ʱ�ȭ�Ͻðڽ��ϱ�?\n");
	printf("                [YES | NO]\n");
	printf("==========================\n");
	flag = key_shift(NONE, 18, 4, 23, 4, 5, 0);

	system("cls");
	printf("==========================\n");
	printf("        < �ʱ�ȭ >        \n");
	printf("==========================\n");

	if (flag == YES) {
		while (pHeader != NULL) {
			pVisited = pHeader;
			pHeader = pHeader->link;
			free(pVisited);
		}
		printf("�ʱ�ȭ�� �Ϸ�Ǿ����ϴ�.\n");
		printf("����Ͻ÷��� �ƹ�Ű�� ��������...\n");
	}
	else {
		printf("�ʱ�ȭ�� ��ҵǾ����ϴ�.\n");
		printf("����Ͻ÷��� �ƹ�Ű�� ��������...\n");
	}
	printf("==========================\n");
	getchar();
}

void about() {
	system("cls");
	printf("\n\n");

	printf("\t===================================\n");
	printf("\t   ��ȥ�� ��� ver 1.0\n");
	printf("\n");
	printf("\t   Programmed by team 2KJP\n");
	printf("\n");
	printf("\t   Copyright@ team 2KJP\n");
	printf("\t===================================\n");
}
