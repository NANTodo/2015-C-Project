#include "��ȥȸ�������������α׷�.h"
int main() {
	int bIterationFlag = TRUE;	// ����ڰ� ������ ���� EXIT�� Ŀ���� �̵��Ͽ� �����ϱ� ������ �ݺ����� ���۽�Ű�� ����.(�������� �ʱ�ȭ)
	int nSelectedMainMenu;	// ����ڰ� ������ �޴��� ��ȣ�� �����ϴ� ����

	// �޴� ���� ��Ʈ
	while(bIterationFlag) {
		nSelectedMainMenu = displayMainMenu();	/*displayMainMenu�Լ��� ȣ��ʰ� ���ÿ� ����ڴ� �޴� ����� ���� ������ �� �ְ� ��.
												�� �� keyshift�� Ŀ���� �̵��Ͽ� �޴� ��ȣ�� �޴µ�, �̰��� ��ȯ�Ǿ�
												�����Լ��� ���ƿ����ν� �� �޴��� ���õ� �Լ��� �����.
												*/
		// ����ڰ� ���ϴ� �޴� ��ȣ�� ������ ���� nSelectedMainMenu�� �б�� �Ͽ� �Լ� ����.
		switch(nSelectedMainMenu) {
			case INSERT:	// ���� �Է��� ���� ���
				insertMenu();	//insertMenu() ȣ��
				break;
			
			case MANAGE:	// ���� ������ ���� ���
				manageMenu();	// manageMenu() ȣ��
				break;
				
			case OUTLINE:	// �������� ȸ�� ���� ��ü�� ���� ���� ��
				outlineMenu();	//outlineMenu() ȣ��
				break;
				
			case SEARCH:	// Ư���� ������ ���� ȸ���� ã�� ���� ��
				searchMenu();	//searchMenu() ȣ��
				break;

			case INITIALIZE:	// ���α׷� ���� ������ �ʱ�ȭ�ϰ� ���� ��
				initializeMenu();	//initializeMenu() ȣ��
				break;
				
			case SAVE:	// ���α׷� ���� ȸ���������� ���Ϸ� ���� �����ϰ� ���� ��
				outputFileMenu();	//outputFileMenu() ȣ��
				break;
				
			case LOAD:	// ���Ͽ� ���� �� ������ ������ ���� ��
				inputFileMenu();	//inputFileMenu() ȣ��
				break;
								
			case ABOUT:	// ������ ������ ������� ���
				about();	//about() ȣ��
				break;

			case EXIT:	// ���α׷��� �����ϰ� ���� ���
				system("cls");
				printf("BYE-BYE\n");	//���α׷��� ����Ǿ����� �˸��� �޼����� ����ϰ�
				bIterationFlag = FALSE;		// ���ѷ����� �ݺ��� ���߸� ���α׷� ����
				break;
		}//switch-case
	}//while

	return 0;
}//main()
int displayMainMenu() {
	int nMenu;		// ����ڰ� ������ �޴����� �����ϴ� ����. �Ŀ� ���ϵǾ� main�Լ��� ���ϰ�, �б⸦ ���� ������ �޴��� �ش��ϴ� �Լ� ȣ��.

	system("cls");		// ȭ�� �����
	printf("==========================\n");
	printf(" ��ȥȸ�������������α׷� \n");
	printf("==========================\n");
	printf("   �� ���� �Է�\n");
	printf("   �� ���� ����\n");
	printf("   �� ��ü ����\n");
	printf("   �� ��� �˻�\n");
	printf("   �� �ʱ�ȭ\n");
	printf("   �� ��������\n");
	printf("   �� ��������\n");
	printf("   �� ��������\n");
	printf("   �� ������\n");
	printf("========================\n");		// �޴� ���, �⺻ �����
	nMenu = key_shift(VERTICAL, 0, 3, 0, 11, 0, 1, 1);		/*�޴� ������ �׻� key_shift�� ������� �� Ŀ�� �̵�������� ��.
															����, �������θ� �̵��� ���̹Ƿ� VERTICAL�� �ش��ϴ� ����� �Ķ���ͷ� ������
															x�ּ���ǥ 0, y�ּ���ǥ 3, x�ִ���ǥ 0, y�ִ���ǥ 11, x�̵� ĭ �� 0, y �̵� ĭ �� 1,
															���� �ε��� 1(�����ָ� �̰��� ������� �ؼ� �޴������� ����)�� �Ķ���ͷ� ����.
															��ȯ�� �޴����� ����ڰ� ������ nMenu�� ���Ե�.*/

	return nMenu;	// nMenu�� ��ȯ�Ǿ� �Ŀ� main�Լ��� nSelectedMainMenu�� ����.
}// displayMainMenu()
void insertMenu() {
	ListNode *pData;	// �������� ȸ�� ������ ����(���� �޸� �Ҵ��� ����)�ϰ� �� ����ü ������ ����
	int nAnn_Inc, nAnn_Inc_big;		// ȸ���� ���� �� '��'�� �ش��ϴ� ���� �����ϴ� ������ nAnn_Inc_big, '��'�� �ش�Ǵ� ���ڸ� �����ϴ� ���� nAnn_Inc

	pData = (ListNode*)(malloc(sizeof(ListNode)));		// ListNode�� ũ�⸸ŭ ���� �޸��Ҵ��� �����ν� �츮�� pData�� ����ü ����ϸ� ���� �Է� ����

	if(pData == NULL) {
		system("cls");
		printf("�Ͻ��� ������ �߻��Ͽ����ϴ�.\n");
		printf("�ٽ� �õ��� �ֽʽÿ�.\n");
		getch();
		return;
	}	// ��, ���� �޸� �Ҵ翡 ������ ��츦 ����Ͽ� if������ ó���� �־���.	
	pData->link = NULL;		// ���� �ƹ��͵� ����Ű�� ���� �����Ƿ� NULL�� ����.

	system("cls");
	printf("==========================\n");
	printf("       < �����Է� >       \n");
	printf("==========================\n");
	printf("�����Ϸ��� �ƹ�Ű�� ��������...");	// ���� �Է��� �����ϴ� �κ�.
	getch();	// system("pause")�� ������ �ϸ�, ����ڰ� �ƹ� Ű�� ������ ���� �Է��� ������.
	fflush(stdin);	// ���� Ŭ���� (�Ŀ� �̸��� �Է��� �� ������ ������ �ʰ� ��)

	system("cls");
	printf("==========================\n");
	printf("         < �̸� >         \n");
	printf("==========================\n");	
	printf("-> \n");
	printf("==========================\n");		// �̸� �Է��� �����ϴ� �κ�.
	gotoxy(3, 3);	// Ŀ���� ->�� �ڷ� �̵���Ų��.
	scanf("%s", pData->strName);		// �����ϰ��� �ϴ� ȸ���� �̸��� pData->strName�� ����
	fflush(stdin);

	system("cls");
	printf("==========================\n");
	printf("         < ���� >         \n");
	printf("==========================\n");
	printf("   �� ����\n");
	printf("   �� ����\n");
	printf("==========================\n");		// ���� �Է��� �޴� �κ�
	pData->nGender = key_shift(VERTICAL, 0, 3, 0, 4, 0, 1, 1);		/* ��, �� �� �ϳ��� ���� ���̹Ƿ� �������� �̵��ϰ�,
																	y������ 3~4�� �־�����, ���� �ε����� 1. key_shift�� ����ǰ�
																	����ڰ� ������ ��ȣ�� ��ȯ�Ǿ� pData->Gender�� ���Ե����ν� ������ �Էµ�.
																	�Ŀ� printData���� ������ ��쿡 ���� ����� ���.*/
	fflush(stdin);
 
	system("cls");
	printf("==========================\n");
	printf("         < ���� >         \n");
	printf("==========================\n");
	printf("-> \n");
	printf("==========================\n");		// ���̸� �Է¹޴� �κ�
	gotoxy(3, 3);	//->�ڷ� Ŀ���� �̵���Ŵ
	scanf("%d", &(pData->nAge));		// pData->nAge�� �����ϰ��� �ϴ� ����� ���̸� �Է¹���
	fflush(stdin);
   
	system("cls");
	printf("==========================\n");
	printf("       < ���� >       \n");
	printf("==========================\n");
	printf("   �� ������\n");
	printf("   �� �Ƿ���\n");
	printf("   �� �����\n");
	printf("   �� ������\n");
	printf("   �� ������\n");
	printf("   �� ������\n");
	printf("   �� ������\n");
	printf("   �� ������\n");
	printf("   �� �����\n");
	printf("   �� ��  ��\n");
	printf("==========================\n");		// ������ �Է� �޴� �κ�(10������ �������� ����)
	pData->nJob = key_shift(VERTICAL, 0, 3, 0, 12, 0, 1, 1);	// Gender�� ���������� ������� key_shift�� �̿��Ͽ� ������ �Է¹޴´�.
	fflush(stdin);

	system("cls");
	printf("==========================\n");
	printf("         < ���� >         \n");
	printf("==========================\n");
	printf("-> [    ]��[    ]����\n");
	printf("==========================\n");		// ���� �Է¹޴� �κ�. '��'�κа� '��'�κ����� ����� �Է¹޵��� �ϰ�, �̸� ���� ���ȴ�.
	gotoxy(4,3);	// �� �κ����� Ŀ���� �̵�
	scanf("%d",&nAnn_Inc_big);	// �￡ �ش��ϴ� ���� �Է¹���
	fflush(stdin);
	gotoxy(12,3);	// ������ �ش��ϴ� �κ����� Ŀ�� �̵�
	scanf("%d",&nAnn_Inc);	// ������ �ش��ϴ� ���� �Է¹���
	fflush(stdin);
	pData->nAnnualIncome = nAnn_Inc + nAnn_Inc_big*10000;	// ������ �ʵ��� ���� �κп� ���� �Է��ߴ� ��κа� ���� �κ��� ���ڸ� ���� ������ ����Ͽ� ����.

	system("cls");
	printf("==========================\n");
	printf("         < �з� >         \n");
	printf("==========================\n");
	printf("   �� ����б� ����\n");
	printf("   �� ���б�   ����\n");
	printf("   �� ���п�   �̻�\n");
	printf("==========================\n");		// �з��� �Է¹޴� �κ�
	pData->nAcademicAbility = key_shift(VERTICAL, 0, 3, 0, 5, 0, 1, 1);		// Gender, Job�� ���������� key_shift�� �̿��Ͽ� �з��� �Է¹޴´�.
	fflush(stdin);
	
	insertData(pData);		// ������ �Է�������, ����Ʈ�� ������ �ϱ� ���� pData�� �Ķ���ͷ� ������ �������� ����Ʈ ���� ������ ���ִ� insertData�� ȣ���Ѵ�.

	system("cls");
	printf("==========================\n");
	printf("       < �����Է� >       \n");
	printf("==========================\n");
	printf("�����Է��� �Ϸ�Ǿ����ϴ�...");
	getch();
}//insertMenu()
void insertData(ListNode *pData) {		// �Ķ���ͷ� ������ pData�� �̿��Ͽ� �������� ����Ʈ ������ ����ϴ� �Լ�.
	ListNode *pVisited, *pPrev;		// �湮������ pVisited, ��������� pPrev�� �̿��ؼ� ����Ʈ ������ �Ѵ�.
	/*

	Linking�������� ����� ���� ũ�� 4����.
	1)pHeader�� �ƹ��͵� ���� �ȵ��� ��<<ù ��° ����, ù ���μ��� ����>>
	: pHeader�� pData�� �������ָ� ��.
	2)pHeader�� ������ �� ����<<�̹� 1)�� ����Ǿ� pHeader�� ���� ���� ��.>>

	**while������ pVisited�� ��ġ�� ã�� pPrev�� �ڵ��󰣴�**

	2-1)�� �� pData->data�� ���� �۾Ƽ� �� ���� ���� ���ԵǾ�� �� ���
	:1)�ϵ��� �Ű��ָ� ��.
	2-2)�׷��� ���� ���
	:pData->link=pPrev->link;
	pPrev->link=pData->link;


	*/
	if(pHeader == NULL) { 		// case 1) pHeader�� �ƹ��͵� ���� �� �� ����.
		pHeader = pData;		// ��� �����Ͱ� pData�� ����Ű�� �����ν� ����.
	}else {						// case 2) pHeader�� ���� ����Ǿ� �ִ� ���
		pVisited = pHeader;		//pVisited�� pHeader�� ���������ν� pVisited�� ù��° ��带 ����Ű�� ��.
		pPrev = NULL;	// ���� �ƹ��͵� ����Ű�� ���� �ʱ� ������, pPrev�� NULL�� �ʱ�ȭ
		
		while (pVisited != NULL && strcmp(pData->strName, pVisited->strName) > 0) {		// ��ġ ã�� ���� >> ���� - �̸������� ordered!
			// ���� �� ����(pVisited�� ������ ���� �ʾҰ�, pData�� �̸��� pVisited�� ����Ű�� �̸����� �� Ŭ ��)�� �մ��ϴٸ�,
			pPrev = pVisited;	// pPrev�� �����Ű��,
			pVisited = pVisited->link;		// pVisited�� ����!
		}//while

		if (pPrev == NULL) {		// case 2-1) �̸��� ���� �տ� �ͼ� ù ��°�� ���� �Ǿ�� �� ��� -> ��� �����Ͱ� �������� �ʾ���.(���� while ����x)
			pData->link = pHeader;
			pHeader = pData;	// pData�� pHeader�� ����Ű�� �ִ� ����Ʈ�� ù ��° ���� �����Ѵ�.
		}else {					// case 2-2) �߰��̳� ���� �������� ��
			pData->link = pPrev->link;
			pPrev->link = pData;	// ����ϰ� pVisited�� pPrev�� �̿��Ͽ� �������ش�.
		}//if-else
	}//if-else
}//insertData()
void manageMenu() {
	ListNode *pVisited;		// ����ڰ� �����ϰ��� �ϴ� Ư�� �̸��� ȸ���� �ִ� ���� üũ���ֱ� ���� ��带 ��ȸ�� �湮�����͸� ����.
	char strName[40];		// �����ϰ��� �ϴ� Ư�� ȸ���� �̸��� �޾��ִ� ������ �迭 
	int nCount = 0, nStart, nLast;		// ������� ����� ������ �����ִ� ����(�̰��� ��帶�� �ٿ��ִ� �ε����� ��.), ����� ���� �ε���, ����� ������ �ε��� 
	int nSelectedData, nSelectedMenu;	// �̸��� �Է¹ް� �ش� �̸��� ���� ȸ���� ��� ����� �ϸ� keyshift�� �̿��Ͽ� �� ȸ�� �� �ϳ��� ������ �� ����. �� ����Ÿ�� ��� �ѹ��� �������ִ� ���� nSelectedData 
										// �׸��� �װ��� �����ϰ� �Ǹ� ������ ������ ������ �������� �����鼭 ����ڰ� �����ϰ� �Ǵµ�, �� ������ ������ �ִ� ���� nSelectedMenu

	if(pHeader == NULL) {
		system("cls");
		printf("���� ������ ������ �����ϴ�.\n");
		printf("�ƹ� Ű�� ������ �������� ���ư��ϴ�...\n");
		getch();
		return;
	}		// ���α׷� �󿡼� ȸ�� ������ ���ٸ� ������ �ʿ䰡 ����. ���� pHeader�� NULL�̶�� �Լ� ������ ���� ����.

	pVisited = pHeader;		// �ƴ� ���, pVisited�� ù ��° ��带 ����Ű�� ��.

	system("cls");
	printf("==========================\n");
	printf("       < �������� >       \n");
	printf("==========================\n");
	printf("�̸� �Է� >> ");
	scanf("%s", strName);		// ������ ȸ���� ������ �Է��ϴ� �κ�
	fflush(stdin);
	// ���� �ε��� ã��..
	while((pVisited != NULL)){
		if(strcmp(pVisited->strName,strName) == SAME) break; 
		// pVisited�� ��ȸ�� �����ϸ�, pVisited�� �̸� �κа� ����ڰ� �Է��� �̸��� �´��� �ƴ����� ���Ͽ� ������ Ż��, 
		pVisited = pVisited->link;	// �ƴϸ� �� ĭ ����
		nCount++;		// ����� ���� ���� ������Ŵ.
	}//while
	
	system("cls");

	if (pVisited == NULL) {		// ����, �Է��� �̸��� ��ġ�ϴ� ȸ���� ���� ���߿� ������ ���ϰ� pVisited�� ����Ʈ�� ������ ���ٸ� 
		printf("�ش� �̸��� ���� ȸ���� �����ϴ�.\n");
		printf("�ƹ� Ű�� ������ �������� ���ư��ϴ�...\n");		// ã�� ȸ���� ���ٴ� �޼����� ����ϰ�,
		getch();
		return;		// �Լ��� ����.
	}//if

	nStart = nCount;		// ó������ ȸ���� �̸��� ���۵Ǵ� ��츦 ���� �ε����� ����.
	nLast = nCount - 1;		// ������ �ε����� �ϴ� ���� �ε������� -1�� �� ������ ����.

	printf("===================================================\n");
	printf("                     < �������� >                  \n");
	printf("===================================================\n");
	printf("  | �� �� | �� �� | �� �� | �� �� | �� �� | �� �� |\n");
	printf("===================================================\n");	// ���� �������� �⺻ ��� ��
	
	while (pVisited != NULL) {		// ����Ʈ�� ���� �ٴٸ� �� ����
		if (strcmp(strName, pVisited->strName) == SAME) {	// ����ڰ� �Է��� �� �̸��� pVisited�� ��ȸ�ϴ� ����� �̸��� ������,
			printf("   ");		// ��� �� ���߱� ���� ���鹮�� ���.
			printData(nCount);		// ����� ������ ����� position�� 1���� �����ָ鼭 1���� ����ϰ� ��. 
			nLast++;	//������ ����� ���� 1 ������Ų��.
		}//if
		pVisited = pVisited->link;		// �湮������ ����
		nCount++;		// ���������Ƿ�, ����� position���� 1 ������Ų��.
	}//while
	
	nSelectedData = key_shift(VERTICAL, 0, 5, 0, 5 + nLast - nStart, 0, 1, nStart);		// ��µ� ������ ���� ���鼭 ���Ϸ� Ŀ���� ������ �����ϰ� ��. + ���õ� ȸ���� ��ġ�� ������ ���� nSelectData�� ���Ե�.

	nSelectedMenu = askMenu();		// ������ ����� ���õǾ����� �ش� ȸ���� ������ ������ �� �������� ���� ���� ���� �ϴ� �Լ� askMenu�� ȣ���ϸ鼭, ����ڰ� ������ ���� ������ �����ϰ� ��.

	switch (nSelectedMenu) {		// ���� nSelectedMenu�� �б�� �Ͽ� Ư�� ����� ������ �Լ����� ȣ���.
		case 1:		// ���� 1��, ���� ������ �����ߴٸ�,
			deleteMenu(nSelectedData);		// �ش� ����� ��ȣ�� �����ϸ鼭 ��带 �����ϴ� �Լ��� ȣ��.
			break;

		case 2:		// ���� 2��, ���� ������ �����ߴٸ�,
			modifyMenu(nSelectedData);		// �ش� ����� ��ȣ�� �����ϸ鼭 ����� �����͸� �����ϴ� �Լ��� ȣ��.
			break;

		case 3:		// ���� 3��, �������� ���ư��⸦ �����ߴٸ�,
			system("cls");
			printf("�۾��� ��ҵǾ����ϴ�.");
			printf("�ƹ� Ű�� ������ �������� ���ư��ϴ�...\n");
			getch();
			return;		// �۾��� ��ҵǾ����� ����ϰ� �Լ��� �����Ѵ�.
	}//switch-case	
}//manageMenu()
int askMenu() {		// �������� �޴����� ������ ������ ������ ������ ������ ���� �޴�
	int nMenu;		// �����޴��� �����޴� �߿��� �����ϱ� ���� ���� ����
	
	system("cls");
	printf("==========================\n");
	printf("       < �������� >       \n");
	printf("==========================\n");
	printf("   �� ȸ����������\n");
	printf("   �� ȸ����������\n");
	printf("   �� ���\n");
	printf("==========================\n");
	
	nMenu = key_shift(VERTICAL, 0, 3, 0, 5, 0, 1, 1);		//nMenu���� Ŀ���� ��ġ�� ������ Ŀ���� �������θ� �����̸� x�� ��ǥ�� 0���� ����, y��ǥ�� 3~5 ���̿��� �� ���� �� ĭ�� �̵��Ѵ�

	return nMenu;	//nMenu�� manageMenu�� nSelectedMenu�� �����ش�.
}//askMenu()
void deleteMenu(int nPosition) {		// ���� ����� ��ġ���� �Ķ���ͷ� �޾� �ش� ��带 ����� ������ �ϴ� deleteData�� ȣ���ϴ� �Լ�.
	int flag;		// ȸ�� ������ ������ �߿��� �����̱� ������ �� �� �� ���� ���θ� ���� �ȴ�. �� �� ������� �ǻ縦 �����ϴ� ����.

	system("cls");
	printf("==========================\n");
	printf("       < �������� >       \n");
	printf("==========================\n");
	printf("������ �����Ͻðڽ��ϱ�?  \n");
	printf("               YES |  NO  \n");
	printf("==========================\n");		// ���� ������ �⺻ ��� ��.
	flag = key_shift(HORIZONTAL, 16, 4, 22, 4, 6, 0, 1);		// YES or NO �� �ϳ��� �����ϴ� ���̹Ƿ� �������� �־���, YES(1)�� NO(2) �� �ϳ��� flag������ ���Եȴ�.

	system("cls");
	if (flag == YES) {		// ���� ����ڰ� ��� ����⸦ ������ ����,
		deleteData(nPosition);		// �ش� ��带 ����� �Լ� deleteData�� ȣ���ϸ鼭 ��ġ���� �Բ� ������.
		printf("���� ������ �Ϸ�Ǿ����ϴ�.\n");
		printf("����Ͻ÷��� �ƹ�Ű�� ��������...\n");		// ���� ������ �Ϸ�Ǿ��ٴ� �޼��� ���
	}else {		// ���� ����ڰ� ����⸦ ������ ���� ���,
		printf("���� ������ ��ҵǾ����ϴ�.\n");
		printf("����Ͻ÷��� �ƹ�Ű�� ��������...\n");		// ���� ������ ��ҵǾ��ٴ� �޼����� ����ϸ鼭 �Լ��� ����.
	}//if-else
	getch();
}//deleteMenu()
void deleteData(int nPosition) {	// ���� ����� ��ġ���� �Ķ���ͷ� �޾� �ش� ��带 ����� ������ �ϴ� �Լ�.
	ListNode *pVisited, *pPrev;		// ��ġ���� ������� ��ġ�� ã�� �� ���Ǵ� �湮������ pVisited�� ��������� pPrev
	int i;		// �ݺ������
	
	pVisited = pHeader;		// pVisited�� ù ��° ��带 ����Ű�� ��
	pPrev = NULL;		// ��������ʹ� ���� pVisited�� �̵����� �ʾ����Ƿ� NULL�� ����Ŵ

	for (i = 0; i<nPosition; i++) {		//��ġ���� ���� �̵��Ͽ� ������ ��带 ã�� �κ�
		pPrev = pVisited;
		pVisited = pVisited->link;		// �ش� ������ �����ϸ�, pPrev�� pVisited�� �� ��ġ�� �����ϰ�, pVisited�� �� ĭ ������.
	}//for
	
	if (pPrev == NULL) {		// ���� �� ���� �������� �ʾ��� �� -> ù ��° ��尡 ������ ��
		pHeader = pHeader->link;
		free(pVisited);	// pHeader�� ������带 ����Ű�� �ϰ�, ������ ù ��° ��带 ����Ű�� �ִ� pVisited�� free ��Ų��.
	}else {		// �߰� �Ǵ� �� ��尡 ������ ��
		pPrev->link = pVisited->link;
		free(pVisited);		//pPrev�� pVisited�� ���� ����Ű�� �ִ� ����� ���� ��带 ����Ű�� �� ��(���� ����), pVisited�� free��Ų��.
	}//if-else
}//deleteData()
void modifyMenu(int nPosition) {	// ����ڰ� �����ϰ� ���� ȸ�������� ��ġ���� �Ķ���ͷ� ���޹޾� �� ��ġ�� ã��, ������ �����ϰ� �ϴ� �Լ�.
	ListNode *pData, *pVisited;		/*
									�̸� ������ ordered�ϴ� ������� �ۼ��Ͽ����Ƿ�, �̸� ������ �ٸ� ������� �����ؾ� ��.
									�̸��� �ٲ� ��, �ٲٱ� ���� �������� ����ϰ� �����ϱ� ���� ����ü ������ pData�� ����.
									��, ��ġ�� ã�� ���� �湮 ������ pVisited�� ����.
									*/
	char strName[40];		// �̸��� ������ ��, �����ϰ� ���� �̸��� �����ϴ� ������ �迭.
	int nPart, i, flag;		/*
							nPart - �̸�, ����, ����, ����, ����, �з�, �ڷ� �� ������ ������ �� Ŀ���� �����̰� ���� �Ǵµ�, �� �� �����ϰ���
							�ϴ� ���� �����ϴ� ����.
							i - �Ķ���ͷ� ���޹��� position���� �������� ��ġ�� ã�µ� ���Ǵ� �ݺ������
							flag - ���� ������ ��� �� �� �� �� ���� �����ϴ� ����. ���� Ŀ���� ������ ���� ��.
							*/

	system("cls");
	printf("=========================================================\n");
	printf("                        < �������� >                     \n");
	printf("=========================================================\n");
	printf("| �� �� | �� �� | �� �� | �� �� | �� �� | �� �� | �� �� |\n");
	printf("=========================================================\n");		// �⺻ ��� ��
	printData(nPosition);		// �̹� manageMenu���� ������ �� �Ѹ��� ȸ�� �������� �ɷ��±� ������ ��ġ���� �̿��Ͽ� ȸ���� ���� 1���� ����Ѵ�.

	nPart = key_shift(HORIZONTAL, 4, 3, 52, 3, 8, 0, 1);		// ���⼭ �̸�~ �ڷα��� ������ �� �ֵ��� �������� �����̵��� �Ѵ�. ����� ����� nPart�� ���Եȴ�.

	system("cls");
	if(nPart == QUIT) {
		printf("���� ������ ��ҵǾ����ϴ�.\n");
		printf("����Ͻ÷��� �ƹ�Ű�� ��������...\n");
		getch();
		return;		// ���� �������� '�ڷ�'�� Ŀ���� �Ű� �����ϸ�, ���������� �׸��ΰ� ���θ޴��� ���´�.
	}else {
		if(nPart == 1) {	// �̸������� ordered�߱� ������ ���Ŀ� ������ ������ �ʰ� �ϱ� ���ؼ��� ���� �� ���԰����� �ʿ��ϴ�. �̴� �ٸ� ���������� �ٸ��� �׷��� ���� �и��Ѵ�.			
			pData = (ListNode*)malloc(sizeof(ListNode));	// pData�� ���� �޸� �Ҵ��� �Ѵ�.
			pData->link = NULL;		// ���� ����Ű�� �� �ƹ��͵� �����Ƿ�, NULL ����
			pVisited = pHeader;	// pVisited�� ù ��° ��带 ����Ű�� �Ѵ�.

			for (i = 0; i<nPosition; i++) {	// �Ķ���ͷ� ���޹��� ��ġ���� �̿��Ͽ� ������ ��带 ã�´�.
				pVisited = pVisited->link;		// ã�� �� ���� ����	
			}

			*pData = *pVisited;		// ã������, pData�� ����ü�� pVisited�� ����ü �ʵ带 ��°�� �����Ѵ�.

			system("cls");
			printf("==========================\n");
			printf("       < �̸����� >       \n");
			printf("==========================\n");
			printf("-> \n");
			printf("==========================\n");		// �̸� ������ �޴� �κ�
			gotoxy(3, 3);	//		 -> �ڷ� �̵���Ų��.
			scanf("%s", strName);	// ������ �̸��� �޴´�.

			gotoxy(0, 5);	// Ŀ���� �̵�
			printf("%s->%s ���� �½��ϱ�?\n", pVisited->strName, strName);		// �Էµ� �̸��� ����Ǿ� �־��� �̸��� ����ϰ�, �ٲ� �̸��� �´� �� Ȯ���Ѵ�.
			printf("               YES |  NO  \n");
			printf("==========================\n");
			flag = key_shift(HORIZONTAL, 16, 6, 22, 6, 6, 0, 1);		// YES or NO �� �ϳ��� Ŀ�� �̵��� ���� �����Ѵ�.

			if (flag == NO) {	// ���� NO, �߸� �Է������� �����Ѵٸ�
				system("cls");
				printf("���� ������ ��ҵǾ����ϴ�.\n");
				printf("����Ͻ÷��� �ƹ�Ű�� ��������...\n");
				getch();
				return;		// ���������� ��ҵǾ��ٴ� ��°� �Բ� �Լ��� ����Ǹ� ���θ޴��� ���´�.
			}

			strcpy(pData->strName, strName);		// ���� YES�� �Է��ߴٸ�, pData->strName�� �Է��� strName�� �����Ѵ�. >> ������ ��� �ϼ�

			deleteData(nPosition);		// ���� �ִ� ��������� ���� ���� ��带 �����
			insertData(pData);		// ������ ��带 ����Ʈ�� �����Ѵ�.
		}
		else {		// ���� �̸� ���� ���� �����ϰ��� �Ѵٸ�,
			modifyData(nPosition, nPart);	// modifyData�� ȣ���ϸ鼭 ����� ��ġ�� ����� nPosition�� ������ ������ ���� ���� �� nPart�� �Բ� �Ķ���ͷ� ������.
		}//if-else
		system("cls");
		printf("���� ������ �Ϸ�Ǿ����ϴ�.\n");
		printf("����Ͻ÷��� �ƹ�Ű�� ��������...\n");
		getch();
		return;		// ���������� �Ϸ�Ǿ����� �˸��� �Լ� ����.
	}//if-else
}//modifyMenu()
void modifyData(int nPosition, int nCategory) {		// �̸� ���� �ٸ� �������� ������ ��� �����ϴ� �Լ�
	ListNode *pVisited = pHeader;		// ������ ����, pVisited�� ù��忡 ��ġ
	int i, flagGen, nAnn_Inc_big, nAnn_Inc;		/*
												for �ݺ����� ���� ���� i ����, ���� ���� ���ý� �ʿ��� flgGen ���� ����
												��� ���� �ش��ϴ� ���� nAnn_Inc_big, nAnn_Inc
												*/

	for (i = 0; i<nPosition; i++) {		// �Ķ���ͷ� ���޹��� ��ġ���� �̿��Ͽ� ������ ��带 ã�´�.
		pVisited = pVisited->link;		// ã�� ������ pVisited ����
		if (pVisited == NULL) break;		// pVisited�� ���� ������ ��忡 ���� break
	}

	system("cls");
	switch (nCategory) {		// ������ �����о߿� ����
		case GENDER:
			printf("==========================\n");
			printf("        < �������� >      \n");
			printf("==========================\n");
			if (pVisited->nGender == MALE) {		// pVisited�� ����Ű�� ����ü�� ������ �����̾��ٸ�
				printf("����->���� ���� �½��ϱ�?\n");
			}
			else if (pVisited->nGender == FEMALE) {		// pVisited�� ����Ű�� ����ü�� ������ �����̾��ٸ�
				printf("����->���� ���� �½��ϱ�?\n");
			}
			printf("               YES |  NO  \n");
			printf("==========================\n");
			flagGen = key_shift(HORIZONTAL, 16, 4, 22, 4, 6, 0, 1);		// flaGen�� Ŀ���� ��ġ�� ������ Ŀ���� �������θ� �����̸� x��ǥ�� 16~22 ���̿��� �� ���� 6ĭ �� �̵��ϰ�, y��ǥ�� 4���� �����Ѵ�.
			if (flagGen == YES && pVisited->nGender == MALE)		pVisited->nGender = FEMALE;		// YES�� �����߰� pVisited�� ����Ű�� ������ MALE�̾��ٸ� FEMALE�� �����Ѵ�.	
			else if (flagGen == YES && pVisited->nGender == FEMALE)	pVisited->nGender = MALE;		// YES�� �����߰� pVisited�� ����Ű�� ������ FEMALE�̾��ٸ� MALE�� �����Ѵ�.
			break;

		case AGE:	// ����
			printf("==========================\n");
			printf("       < ���̼��� >       \n");
			printf("==========================\n");
			printf("-> [    ]\n");
			printf("==========================\n");
			gotoxy(4, 3);		// x,y��ǥ (3,3)���� Ŀ���̵�
			scanf("%d", &(pVisited->nAge));		// pVisited���� ����Ű�� ����ü�� nAge, �� ���̰� �Է�
			break;

		case JOB:	 // ����
			printf("==========================\n");
			printf("       < �������� >       \n");
			printf("==========================\n");
			printf("   �� ������\n");
			printf("   �� �Ƿ���\n");
			printf("   �� �����\n");
			printf("   �� ������\n");
			printf("   �� ������\n");
			printf("   �� ������\n");
			printf("   �� ������\n");
			printf("   �� ������\n");
			printf("   �� �����\n");
			printf("   �� ��  ��\n");
			printf("==========================\n");
			pVisited->nJob = key_shift(VERTICAL, 0, 3, 0, 12, 0, 1, 1);		// �������θ� �����̸�, x��ǥ�� 0���� ����, y��ǥ�� 3~6 ���̿��� �ѹ��� �� ĭ�� �̵��ϸ�, �� ���� pVisited->nJob�� ����
			break;

		case ANN_INC:	 // ����
			printf("==========================\n");
			printf("       < �������� >       \n");
			printf("==========================\n");
			printf("-> [    ]��[    ]����\n");
			printf("==========================\n");
			gotoxy(4,3);
			scanf("%d",&nAnn_Inc_big);
			fflush(stdin);
			gotoxy(12,3);
			scanf("%d",&nAnn_Inc);
			fflush(stdin);
			pVisited->nAnnualIncome = nAnn_Inc + nAnn_Inc_big*10000;	// ������ ��� ������� ������ �������� �ް�, ����Ͽ� ������ �ʵ忡 ����
			break;

		case ACD_ABL:		// �з�
			printf("==========================\n");
			printf("       < �з¼��� >       \n");
			printf("==========================\n");
			printf("   �� ����б� ����\n");
			printf("   �� ���б�   ����\n");
			printf("   �� ���п�   �̻�\n");
			printf("==========================\n");
			pVisited->nAcademicAbility = key_shift(VERTICAL, 0, 3, 0, 5, 0, 1, 1);		// �������θ� �����̸� x��ǥ�� 0���� ����, y��ǥ�� 3~5 ���̿��� �� ���� �� ĭ�� �̵��Ѵ�. 
																						// �� ���� pVisited->nAcademicAbility�� ����
			break;
	}//switch-case
}//modifyData()
void printData(int nPosition) {		// ��ü����, �������� ��� ���� �Էµ� ȸ�������� ����ϴ� �Լ�
	ListNode *pVisited;		// ����� ��ġ�� ã�� ���� pVisited ������ ����
	char job;		// ���� ����
	int i;		// for�ݺ��� �ۼ��� ���� ���� i ����


	pVisited = pHeader;		// pVisited �����ʹ� ù��忡 ��ġ

	for (i = 0; i<nPosition; i++) {		// ��ġ���� �̿��Ͽ� ��带 ã�´�.
		pVisited = pVisited->link;		// pVisited�� ����
	}

	//�̸����
	printf(" %-8s", pVisited->strName);

	//�������
	if (pVisited->nGender == MALE) {		// pVisited�����Ͱ� ����Ű�� ȸ�������� ������ ������ ���
		printf("   ��   ");
	}else if (pVisited->nGender == FEMALE) {		// pVisited�����Ͱ� ����Ű�� ȸ�������� ������ ������ ���
		printf("   ��   ");
	}

	//�������
	printf("  %3d   ", pVisited->nAge);

	//�������
	switch (pVisited->nJob) {		// pVisited�����Ͱ� ����Ű�� ȸ�������� ������ ����
		case 1: printf("������"); break;
		case 2: printf("�Ƿ���"); break;
		case 3: printf("�����"); break;
		case 4: printf("������"); break;
		case 5: printf("������"); break;
		case 6: printf("������"); break;
		case 7: printf("������"); break;
		case 8: printf("������"); break;
		case 9: printf("�����"); break;
		case 10: printf("��  ��"); break;
	}//switch-case


	//�������
	if (pVisited->nAnnualIncome < 10000)	{	// pVisited�����Ͱ� ����Ű�� ȸ�������� ������ 10000��(1��) �̸��̶��
		printf("   %4d", pVisited->nAnnualIncome);
		printf("��");
	}else if (pVisited->nAnnualIncome < 100000000) {		// pVisited�����Ͱ� ����Ű�� ȸ�������� ������ 1�� �̻������� 100000000��(1��) �̸��̶��
		printf(" %6.1f", (float)(pVisited->nAnnualIncome) / 10000);	// ����(�� ���� ���ϴ� �� ��)�� 10000���� ������ float���·� ǥ��. float�� �ϴ� ������ �ڸ��� Ȯ���� ����
		printf("��");
	}

	//�з����
	if (pVisited->nAcademicAbility == 1) {		// pVisited�����Ͱ� ����Ű�� �з��� 1,ù��° ���̶��
		printf("  %-8s", "����");
	}else if (pVisited->nAcademicAbility == 2) {		// pVisited �����Ͱ� ����Ű�� �з��� 2, �ι�° ���̶��
		printf("  %-8s", "�л�");
	}else if (pVisited->nAcademicAbility == 3) {	// pVisited �����Ͱ� ����Ű�� �з��� 3, ����° ���̶��
		printf("  %-8s", "�����̻�");
	}
	
	printf("\n");
}//printData()
void outlineMenu() {		// ���α׷� ���ο� �ִ� ȸ�� �������� ��ü������ ����ϴ� �Լ�
	ListNode *pVisited;		// ��� �ϳ��ϳ� �湮�ϸ鼭 ����� ���̹Ƿ�, �湮 �����͸� �ϳ� ����
	int nCriteria = NAME, flag = NO;		/*	
												�̸��� Ŀ���� �θ� �̸� ������, ����, ����, �з��� �з� ������ �����Ͽ� ����Ϸ��� �ϹǷ� �� ������ �����ϴ� ���� nCriteria�� ����
												���� �̸�, ����, ����, ����, �з�,������ �����ߴ��� �ƴϸ� �����⸦ �����ߴ��� �������ִ� flag.
												�Ŀ� arrnageData���� ó�� �� �� ������ �츮�� ������ ������ ������� �ǰ� �ٽ� �� �� ������
												���� �������� �Ǵµ�, �����⸦ ������ arrangeData���� ���ϵǾ� flag�� ����ǰ� �Լ��� ������ ��.
											*/
	int nCount = 0, i;		/*
							nCount - ����� ������ �����ִ� ����
							nCountSave - ��ü���� ����� ������ �ӽ� ������ ����
							i - �ݺ������
							*/

	system("cls");
	
	if (pHeader == NULL) {	// ����Ʈ�� �ƹ� ������ ���� �� �Լ��� ������ �ʿ䰡 ����.
		printf("���� �� �� �ִ� ������ �����ϴ�.\n");
		printf("�ƹ� Ű�� ������ �������� ���ư��ϴ�...\n");		// ������ ���ٴ� �޼����� ����ϰ� �Լ��� ����.
		getch();
		return;
	}//if

	pVisited = pHeader;		// pVisited�� ù ��° ��带 ����Ű�� �Ѵ�.
	while (pVisited != NULL) {		// pVisited�� ���� �ٴٸ��� ���� �� ���� pVisited�� ������Ű�鼭 ���ÿ� nCount(��� ����)�� ���� ������Ų��.
		pVisited = pVisited->link;	
		nCount++;
	}//while

	while(TRUE) {
		fflush(stdin);
		system("cls");
		gotoxy(0,0);
		printf("=========================================================\n");
		printf("                        < ��ü���� >                     \n");
		printf("=========================================================\n");
		printf("| �� �� | �� �� | �� �� | �� �� | �� �� | �� �� | �� �� |\n");
		printf("=========================================================\n");		// ��ü���� �޴��� �⺻ �����
		nCount;
		for (i = 0; i<nCount; i++) {	// ����� ���� �ٴٸ� �� ���� ȸ�� ������ ����ϰ� i�� 1�� ������Ų��.
			printData(i);		
		}//for

		nCriteria = key_shift(HORIZONTAL, 4, 3, 52, 3, 8, 0, 1);
		// ����� �Ϸ�ǰ� ���ϸ�, � �������� �� ������ �� �� ������ �� �ְ� �ȴ�. ���� �̸�~�ڷα��� ������ �� �ִ�.

		if (nCriteria == QUIT) {		// ���� ����ڰ� QUIT(7��, �ڷ�)�� �����ߴٸ� �Լ��� ����Ǿ� ���θ޴��� ������ �ǰ�,
			if (flag == YES)	arrangeData(NAME);	/*  
														�̹� �������� �����۾��� �� �� �ٽ� �����ٸ�,
														��ü���� �޴��� �������� �� �̸� ������ ���ĵǾ� �������� ���� ���̴�. ó���� ������
														�̸����̱� ������, ������ �� �̸������� �����ϰ� ������.
													*/
			return;
		}//if
		
		flag = arrangeData(nCriteria);		// �� ��찡 �ƴ϶�� ��� �������� ������ ���� ������ ������ �Ķ���ͷ� ������ �������� �����Ѵ�. arrangeData�� ��ȯ�� ���� QUIT���� �ƴ����� Ȱ���.
	}// while
}//outlineMenu()
int arrangeData(int flag) {		// ��� �������� ������ ���� �μ��� �ް�, �׿� ���� ����Ʈ ��ü�� �������ִ� �Լ�.
	ListNode *pVisited, *pSaved, *pPrev, *pCompared;						/*
																				pVisited - �����ϸ鼭 �ش� ��带 ������ ����� �ϴ� �� �̿�Ǵ� ������
																				pSaved - pVisited�� ��� ������ (��������� 1�� ��Ī)
																				pPrev - pCompared�� ��������ͷ� �Ŀ� pVisited�� pCompared�� ����Ű�� �ִ� ����� ���� ��� �Ǵ� ���� ��򰡷� ���� �� �� , pHeader�� �ڷ� ���� �� �� ��� ���.
																				(��������� 2�� ��Ī�ϰ���.)
																				pCompared - �̵��ϸ鼭 ���������� pVisited�� ����Ű�� ���� ������ ���� ���Ͽ� pVisited�� pCompare�� ����Ű�� ����� ���� ���, �Ǵ� ���� ���, pHeader �ڷ� ���� �ϴ��� ��������
																			
																			*/
	int nPosition = 0, i, bIterationFlag = FALSE, bRearrangeflag = YES;		/*
																				nPosition - �� ������ �� Ƚ��
																				i - �ݺ� �����
																				bIterationFlag - ������ ���ߴ��� ��� �����ϴ� ���� �����ϴ� ����
																				bRearrangeflag - �̸� ������ �������� �ؾ��ϴ� �� �ƴ� ���� �޴� ����. outlineMenu�� ��ȯ�Ǿ� ���� bRearrangeflag==YES��� ���� ����Ʈ�� �̸������� �������� �ʿ��ϴٴ�
																				�ǹ��̹Ƿ�, ������ ���� ������ �ϰ� �ȴ�. �̸����� �ٽ� ���͸� �� �������� �Ǿ����� ���� �״�� ����. arrange�� �ʿ䰡 �����Ƿ�
																				��, ������ ��� YES��� outlineMenu���� ��ȯ�Ǿ� ������ �̸� ������ �ٽ� �̷�����,
																				NO��� �׳� ������.
																		
																			*/
	static int prevflag[2] = {NONE,NAME};	/*
												���α׷����� �� �� ���� ������ ���ش�� �����ϰ� ���� �� �� �� ���͸� ġ�� ���� ������ �������� �ȴ�.
												�� �� ���� ����� ������ ������ �����ϸ鼭 �Լ��� �������� �� ���� �״�� ������ �ִ� ���� �ʿ��ϴٴ� ����
												�� �� �ִ�. ���� static������ �����Ͽ���, ���� ����� ������ ������ ������ ���� �� �ִ� �迭�� �����Ͽ���. 
											*/

	while(TRUE) {		// ����Ʈ�� ����ڷ� ���� ���� �������� ������ �ϴ� ����.
		// �⺻ ����
		pSaved = pHeader;		// pSaved�� ù ��° ��带 ����Ű�� ��
		pPrev = NULL;		// ���� ������� �ʾ����Ƿ� NULL
		pVisited = pHeader->link;	// pVisited�� �� ��° ��带 ����Ű�� ��.
		pCompared = pHeader;	// pCompared�� ù ��° ��带 ����Ŵ.

		for(i=0; i<nPosition; i++) {		// (ó����, nPosition�� 0�̹Ƿ� �� �κ��� �ǳ� �ٰ� ��. �Ŀ� �þ�� ����) 
			if(pVisited->link == NULL) {		// ������ �����,
				bIterationFlag = TRUE;		// bIterationFlag�� ������ �����ϰ� for���� Ż���Ѵ�. >> ���̻� ���� ��尡 ���ٴ� �ǹ�
				break;
			}//if
			pSaved = pVisited;	
			pVisited = pVisited->link;		// if���ǿ� �ش���� �ʴ´ٸ�, ��������� 1�� pVisited�� ������Ų��.
		}
		if(bIterationFlag == TRUE)	break;		// ���� ������ ��忩�� ���Դٸ�, while�� ��ü�� ���� ���´�.

		pSaved->link = pVisited->link;		// ����Ʈ�� pVisited�� ����Ű�� �ִ� ��带 �и��Ѵ�. [pVisited�� ����Ű�� �ִ� �� ���� ��带 ����Ű�鼭...
	
		switch(flag) {		// outlinkMenu���� ������ �μ� flag�� ���� �б��.
			case NAME:		// �̸����� ������
				if(flag != prevflag[0] && flag == prevflag[1]) {		// ������ ������ �Ͱ� ���� ������ ��(NAME)�� ���� �ʰ�, ���� ������ ��(NAME)�� ���� ������ ��(NAME)�� ���ٸ� �������� ����ϴ� ��.
					for(i=0; i<nPosition+1; i++) {
						if(strcmp(pVisited->strName,pCompared->strName) < 0) {		/* 
																						** pPrev==NULL�� ��� - ù ��° ������ ���������� �տ� ���� ���
																						   >> pVisited�� �տ� ���Եǰ� ��.
																						** �� ���� ��� - �ؿ� ���� �˰����� pPrev�� ����Ű�� ����� �ڷ� ���Եǰ� ��.
																					   ���� pCompared�� �̸��� ���������� �ڿ� �ְ�(�Ϲ���)
																					   pVisited�� ���������� �տ� �ִٸ�(�迬��) >> ����! >> pPrev�� pCompare�� �̵��ϰ�,  pVisited�� pPrev�� ����Ű�� ��� �ڿ� ���Եǰ� ��.
																					   �ƿ� �� ������ �������� �ʾҴ�(pVisited�� �ִ� ���������� �� �� ������ ������ ���̾��ٸ�) �ݺ����� Ż���ϸ鼭
																					   pVisited�� ù ��°��
																					   ���� �� ���̰� ���ٰ� �� ������ �����ϴ� ������ �ִٸ� pPrev�ڷ� ���Եǰ� �ȴ�. 
																					*/
							pPrev = pCompared;
							pCompared = pCompared->link;		// pPrev�� pCompared�� ������Ŵ 
						}
						else	break;		// ���ܰ� �߻��� ���(pCompared) �ٷ� ���缭 pHeader�� ù ��� �Ǵ� ������ �߻��� pCompared�� pPrev ���̿� ���Խ�Ű���� �Ѵ�.
					}//for
					bRearrangeflag = YES;	// ����Ʈ�� ��Ʈ�������Ƿ� ���� �� ������ �ʿ�!
				}else {		// �������� ������ ���
					for(i=0; i<nPosition+1; i++) {
						if(strcmp(pVisited->strName,pCompared->strName) > 0) {		// ���������� ���������� pVisited�� �ڿ� �ְ� pCompared�� �ڿ� �ִٸ� 
							pPrev = pCompared;
							pCompared = pCompared->link;		// �ٸ� ��带 �˻��ϱ� ���� �� ĭ �� �������ش�.
						}
						else	break;		// ���ܰ� �߻��� ���(pCompared) �ٷ� ���缭 pHeader�� ù ��� �Ǵ� ������ �߻��� pCompared�� pPrev ���̿� ���Խ�Ű���� �Ѵ�.
					}//for
					bRearrangeflag = NO;		// �̸� ������������ �Ǿ��ֱ� ������ �������� �ʿ� ����!
				}//if-else
				break;
				
			case GENDER:	// ������ ������
				if(flag != prevflag[0] && flag == prevflag[1]) {		// ������ ������ �Ͱ� ���� ������ ��(Gender)�� ���� �ʰ�, ���� ������ ��(Gender)�� ���� ������ ��(Gender)�� ���ٸ� �������� ����ϴ� ��.
					for(i=0; i<nPosition+1; i++) {
						if(pCompared->nGender > pVisited->nGender) {	/* 
																			���α׷� �󿡼� ��ϵ� ��ȣ�� ���ڰ� 1��, ���ڰ� 2���̾���.
																			�׸��� �ٽ� �� �� �� ���� �ǿ��� ���͸� ���� ������ �� ���� �����̴�.
																			�ش� ������ ���ڸ� ���� ����ϰ� ���ڸ� �� �ڿ� ����Ѵ�. 
																			���� ��������� �տ� �ִ� ��带 ����Ű�� pCompared->Gender�� �����̰� ���� pVisited�� ���ڶ��
																			�״�� ������� pPrev�� ����Ű�� �� �ڿ� pVisited�� ���Եǵ��� ó���Ѵ�.

																		*/
							pPrev = pCompared;
							pCompared = pCompared->link;	// pPrev�� pCompared�� �� ĭ ������Ŵ
						}
						else	break;		// ���ܰ� �߻��� ���(pCompared) �ٷ� ���缭 pHeader�� ù ��� �Ǵ� ������ �߻��� pCompared�� pPrev ���̿� ���Խ�Ű���� �Ѵ�.
					}	// for
				
				}else {		// ���� ó������ �����ǿ��� ������ ��û�ϸ� ��-�� ������ ���ĵ�.
					for(i=0; i<nPosition+1; i++) {
						if(pCompared->nGender < pVisited->nGender) {		// ��(1) - ��(2) ���� �ȴٸ� pPrev�� pCompared�� ������Ų��.
							pPrev = pCompared;
							pCompared = pCompared->link;
						}
						else	break;		// ���ܰ� �߻��� ���(pCompared) �ٷ� ���缭 pHeader�� ù ��� �Ǵ� ������ �߻��� pCompared�� pPrev ���̿� ���Խ�Ű���� �Ѵ�.
					}
			
				}
				bRearrangeflag = YES;	// ���� �� ������ �ʿ�!
				break;
	
			case AGE:		// ���̷� ������
				if(flag != prevflag[0] && flag == prevflag[1]) {	// ������ ����� �Ͱ� ���� ����� ���� ���� �ʰ� ���� ����� �Ͱ� ���� ���
					for(i=0; i<nPosition+1; i++) {		
						if(pCompared->nAge > pVisited->nAge) {	// �� �� �� ���� �ǿ� ���� ���͸� ġ�� ���̰� ���� �� ��� ����Ʈ�� �籸��
							pPrev = pCompared;
							pCompared = pCompared->link;
						}else	break;		// ���ܰ� �߻��� ���(pCompared) �ٷ� ���缭 pHeader�� ù ��� �Ǵ� ������ �߻��� pCompared�� pPrev ���̿� ���Խ�Ű���� �Ѵ�.
					}
				
				}else {
					for(i=0; i<nPosition+1; i++) {
						if(pCompared->nAge < pVisited->nAge) {		// ���� ó�� ���� �ǿ��� ���͸� ġ�� ���̰� ���� �� ��� ����Ʈ�� �籸��
							pPrev = pCompared;
							pCompared = pCompared->link;
						}
						else	break;		// ���ܰ� �߻��� ���(pCompared) �ٷ� ���缭 pHeader�� ù ��� �Ǵ� ������ �߻��� pCompared�� pPrev ���̿� ���Խ�Ű���� �Ѵ�.
					}
		
				}
				bRearrangeflag = YES;	// ���� �� ������ �ʿ�!
				break;
			
			case JOB:	
				if(flag != prevflag[0] && flag == prevflag[1]) {
					for(i=0; i<nPosition+1; i++) {
						if(pCompared != NULL && pCompared->nJob < pVisited->nJob) {		// �� �� �� ���� ������ ���� ���͸� ġ�� ���� ��� ������ ������ (1��°, �������� ���� ����)
							pPrev = pCompared;
							pCompared = pCompared->link;
						}
						else	break;		// ���ܰ� �߻��� ���(pCompared) �ٷ� ���缭 pHeader�� ù ��� �Ǵ� ������ �߻��� pCompared�� pPrev ���̿� ���Խ�Ű���� �Ѵ�.
					}
				
				}else {		
					for(i=0; i<nPosition+1; i++) {
						if(pCompared != NULL && pCompared->nJob > pVisited->nJob) {		// ���� ó�� ���������� ���� ���͸� ġ�� ���� ��� �������� ������ (10��°, �� �ܰ� ���� ����)
							pPrev = pCompared;
							pCompared = pCompared->link;
						}
						else	break;		// ���ܰ� �߻��� ���(pCompared) �ٷ� ���缭 pHeader�� ù ��� �Ǵ� ������ �߻��� pCompared�� pPrev ���̿� ���Խ�Ű���� �Ѵ�.
					}
					
				}
				bRearrangeflag = YES;	// ���� �� ������ �ʿ�!
				break;
			
			case ANN_INC:		// ���� ������ ������
				if(flag != prevflag[0] && flag == prevflag[1]) {
					for(i=0; i<nPosition+1; i++) {
						if(pCompared != NULL && pCompared->nAnnualIncome < pVisited->nAnnualIncome) {		// ������ ���� ������� ���
							pPrev = pCompared;
							pCompared = pCompared->link;
						}
						else	break;		// ���ܰ� �߻��� ���(pCompared) �ٷ� ���缭 pHeader�� ù ��� �Ǵ� ������ �߻��� pCompared�� pPrev ���̿� ���Խ�Ű���� �Ѵ�.
					}
					
				}else {
					for(i=0; i<nPosition+1; i++) {
						if(pCompared != NULL && pCompared->nAnnualIncome > pVisited->nAnnualIncome) {		// ������ ���� ������� ���
							pPrev = pCompared;
							pCompared = pCompared->link;
						}
						else	break;		// ���ܰ� �߻��� ���(pCompared) �ٷ� ���缭 pHeader�� ù ��� �Ǵ� ������ �߻��� pCompared�� pPrev ���̿� ���Խ�Ű���� �Ѵ�.
					}
				
				}	
				bRearrangeflag = YES;	// ���� �� ������ �ʿ�!
				break;
	
			case ACD_ABL:		// �з� ������ ������
				if(flag != prevflag[0] && flag == prevflag[1]) {
					for(i=0; i<nPosition+1; i++) {
						if(pCompared != NULL && pCompared->nAcademicAbility < pVisited->nAcademicAbility) {		// �� ��, �ٽ� ���� �з¿� ���� �������� �ϰ� �Ǹ� ���� ������� ���
							pPrev = pCompared;
							pCompared = pCompared->link;
						}
						else	break;		// ���ܰ� �߻��� ���(pCompared) �ٷ� ���缭 pHeader�� ù ��� �Ǵ� ������ �߻��� pCompared�� pPrev ���̿� ���Խ�Ű���� �Ѵ�.
					}
					
				}else {
					for(i=0; i<nPosition+1; i++) {
						if(pCompared != NULL && pCompared->nAcademicAbility > pVisited->nAcademicAbility) {		// �з� ���� ������� ���� ���
							pPrev = pCompared;
							pCompared = pCompared->link;
						}
						else	break;		// ���ܰ� �߻��� ���(pCompared) �ٷ� ���缭 pHeader�� ù ��� �Ǵ� ������ �߻��� pCompared�� pPrev ���̿� ���Խ�Ű���� �Ѵ�.
					}
					
				}
				bRearrangeflag = YES;	// ���� �� ������ �ʿ�!
				break;
		}//switch-case
			
		if(pPrev == NULL) {
			pVisited->link = pHeader;
			pHeader = pVisited;
		}else {
			pVisited->link = pPrev->link;
			pPrev->link = pVisited;	
		}
		//	 ��带 ����Ʈ�� ��������ִ� ����
		nPosition++;	// �����ų Ƚ���� 1ȸ ������Ų��.
	}// while

	
	if(prevflag[0] == prevflag[1] && flag == prevflag[1])	prevflag[0] = NONE;		/*
																					���� ������ �Ͱ� ������ ������ ���� ������ ���� ��������� ���ٴ� ����
																					�Ȱ��� ������ Ȧ���� ����ƴٴ� �ǹ��̰� �̴� �� ó�� Ư�� ���ǿ� ���� ������ �ǽ��� �Ͱ� ����
																					���� prevflag[0](�� ���� ����� ��)�� NONE�� �������ش�
																					*/
	else													prevflag[0] = prevflag[1];
	prevflag[1] = flag;		// ���� 1���� ����ǰ� ���� �ش� ������ �����ϰ� ���� ���� '���� ����'�� ��Ÿ���� �迭���� prevflag[1]�� �����Ѵ�

	return bRearrangeflag;		// ������ �Ǿ����� �ƴ����� ���θ� �����ϴ� bRearrangeflag�� ��ȯ���ش�.
}//arrangeData()
void searchMenu() {
	Search Data;	//Ư�� ������ �˻��ϴ� search�޴��� �����ϱ� ���� ����ü.������ ������ �ɸ��� �������� ����ü �ȿ� �ʵ�μ� ����Ǿ�����.
	int nSelectedJob, i, nAnn_Inc, nAnn_Inc_big;/*
														nSelectedJob - ����ڰ� ������ �������� �����Ͽ� Ư�� ������ �ش��ϴ� ����� ���� ���� ��, Ŀ���� �̵��Ͽ� �����ϰ� �Ǵµ�
																		�� �� ���õ� ���� ������ �����ϴ� ����.
														i - �ݺ� �����
														nAnn_Inc - �ּ� �ҵ� �̻� �Ǵ� ������� ���� ���� �� ��~�� ������ �ް� �Ǵµ�, '��'�� �ش��ϴ� �ݾ��� �Է¹޴� ����. �Ŀ� 
																	'��'������ �ԷµǸ� ���Ǿ� ,����ü Data.nAnnualIncome�� ���Ե�.
														nAnn_Inc_bic - '��'�� �ش�Ǵ� �ݾ��� �Է¹޴� ����.
													
													*/

	system("cls");
	
	if(pHeader == NULL) {
		printf("���� ã�� �� �ִ� ������ �����ϴ�.\n");
		printf("�ƹ� Ű�� ������ �������� ���ư��ϴ�...\n");
		getch();
		return;
	} 		// ����Ʈ�� ������� �� ã�� �� �ִ� ������ ���ٴ� �޼����� ����ϸ� �Լ� ����.

	printf("==========================\n");
	printf("       < ���˻� >       \n");
	printf("==========================\n");
	printf("����� ������ �����ϼ���.\n");
	printf("   �� ����\n");
	printf("   �� ����\n");
	printf("==========================\n");		// ������� ������ �Է¹޾� ���ϴ� Ÿ���� ������ �����ϴ� �κ�. ���� ������ �׻� �ݴ�. (by key_shift)
	if (key_shift(VERTICAL, 0, 4, 0, 5, 0, 1, 1) == MALE)	Data.nGender = FEMALE;		// ���� ������ ���ڶ�� Ÿ���� ����		
	else													Data.nGender = MALE;		// �ݴ��� ���� Ÿ���� ����.
	fflush(stdin);

	system("cls");
	printf("==========================\n");
	printf("       < �������� >       \n");
	printf("==========================\n");
	printf("[  ]�� �̻� [  ]�� ����\n");
	printf("==========================\n");		// Ÿ���� ���� ������ �����ϴ� �κ�
	gotoxy(1, 3);	// Ŀ�� �̵�
	scanf("%d", &Data.nMinAge);		// �ּ� ���̸� �޴´�
	fflush(stdin);
	gotoxy(13, 3);		// Ŀ�� �̵�
	scanf("%d", &Data.nMaxAge);		// �ִ� ���̸� �޴´�
	fflush(stdin);
   
	for(i=0; i<11; i++) {
		Data.nJob[i] = NONE;	// �����κ��� ��� �������� 11���� ���������� ���� ���� ���� �ߺ����� �����ϱ� ���� �迭�� ����. �̰��� �ʱ�ȭ ���ִ� ����.	
	}//for

	system("cls");
	printf("==========================\n");
	printf("       < ��������>        \n");
	printf("==========================\n");
	printf("�ߺ� ���� ����/�缱�� �� ���\n");
	printf("   �� ������\n");
	printf("   �� �Ƿ���\n");
	printf("   �� �����\n");
	printf("   �� ������\n");
	printf("   �� ������\n");
	printf("   �� ������\n");
	printf("   �� ������\n");
	printf("   �� ������\n");
	printf("   �� �����\n");
	printf("   �� �� ��\n");
	printf("   �� ��� ����\n");
	printf("   �� ���� ����\n");
	printf("==========================\n");		// Ÿ���� ������ �����ϴ� �κ�

	while(TRUE) {
		nSelectedJob = key_shift(VERTICAL, 0, 4, 0, 15, 0, 1, 0);
		//nSelected = 0 ~ 11 (0~9=���� 10=������� 11=����)
		
		if(nSelectedJob == 11) {	// ������ ���� �ߴ�.
			for(i=0; i<11; i++) {		// 0������ 10�� �ε������� SELECTED�� ���� ������ Ż���ϵ��� �Ѵ�.	(for)
				if(Data.nJob[i] == SELECTED)	break;
			}//for
			if(i != 11)	break;		// 0������ 10�� ���̿� �ϳ��� SELECTED�� ���� ���ٸ� Ż��(while) >> �������� �Ѿ��.
		}//while
		//����() ���� �� Ȯ�� �� ����or�缱��
		
		if(nSelectedJob == 10) {	// ��� ������ ������ ���
			for(i=0; i<10; i++) {	
				Data.nJob[i] = NONE;	// 0������ 9�� �ε������� ��� NONE���� �����.
				gotoxy(3,4+i);		// ���� ������ Ŀ���� �������� 0������ 9���� ���� ����
				printf("��");	// ��ĭ���� ���� ��������� �ٸ� ���� �ߺ��Ǵ� ���� ������ �Ѵ�.
			}//for
			gotoxy(3,14);	// ������������� ����
			printf("��");	// ���õǾ����� �ǹ��ϴ� ���� ���׶�̸� ����ϰ�
			Data.nJob[10] = SELECTED;	// �������� �����Ѵ�.
		}else if(Data.nJob[nSelectedJob] == SELECTED) {		// ���� ���⼭ ���� ������ ���� �̹� ���õ� ���̶��
			Data.nJob[nSelectedJob] = NONE;		// �ش� �迭 ���Ҹ� NONE���� �����Ͽ� ���õ��� �ʾ����� �����ϰ�
			gotoxy(3,nSelectedJob+4);		// �ش��ϴ� �������� �� 
			printf("��");		// ��ĭ���� ���� ������ ��ҵ����� ǥ���Ѵ�. 
		}else if(Data.nJob[nSelectedJob] == NONE) {		// ���� ���� ������ ���� ���õ��� ���� ���̶��,(�ε��� ��ȣ 10�� ������� ����, ������ üũ����)
			Data.nJob[nSelectedJob] = SELECTED;		// �ش� �ε����� ���õǾ��ٰ� ���ְ�,
			gotoxy(3,nSelectedJob+4);		// �� �ε����� ���� ��Ÿ���� ������ Ŀ���� �̵��ؼ�
			printf("��");		// ���õǾ����� �ǹ��ϴ� �������׶�̸� ����ϰ�
			gotoxy(3,14);		// �Ʊ� ��������� ���� ���⼭ ���� ������ �ǹ��ϹǷ� ��������� ��Ÿ���� ������ ����
			printf("��");		// ���õ��� �ʾ����� �˸��� �� ���׶�̸� ����ϸ�
			Data.nJob[10] = NONE;		// ��������� �迭���Ҹ� NONE���� �ʱ�ȭ�Ѵ�.
		}//if- else if
	}//while

	system("cls");
	printf("==========================\n");
	printf("       < �������� >       \n");
	printf("==========================\n");
	printf("'0'�Է� �� '�������'\n");
	printf("[    ]��[    ]���� �̻�\n");
	printf("==========================\n");		// Ÿ���� �ּ� ������ �޴� �κ�
	gotoxy(1, 4);	// Ŀ���� []�������� �̵�
	scanf("%d", &nAnn_Inc_big);		// �ּ� �� ��� �ҵ� �� '��'������ �ش��ϴ� ���� �޴´�.
	fflush(stdin);
	gotoxy(9, 4);	// Ŀ���� []���� ������ �̵�
	scanf("%d", &nAnn_Inc);		// �ּ� �� ��� �ҵ� �� '����'������ �ش��ϴ� ���� �޴´�.
	fflush(stdin);

	Data.nAnnualIncome = nAnn_Inc + nAnn_Inc_big * 10000;		// ���� �� nAnn_Inc_big�� nAnn_Inc�� �̿��Ͽ� �ּ� �� ��� �ҵ��� ����Ͽ� Data.nAnnualIncome�� �����Ѵ�.

	system("cls");
	printf("==========================\n");
	printf("       < �з����� >       \n");
	printf("==========================\n");
	printf("   �� �������\n");
	printf("   �� ���б�   ����\n");
	printf("   �� ���п�   ���� �̻�\n");
	printf("==========================\n");		// Ÿ���� �ּ� �з��� �޴� �κ�
	fflush(stdin);
	Data.nAcademicAbility = key_shift(VERTICAL, 0, 3, 0, 5, 0, 1, 1);	/*
																			1�� ����, 2�� ����, 3�� ���� �̻����� ���س��µ� ��������� 1�� ���鼭 ��ȣ�� �ϳ��� �и���.
																			�̸� �����ϱ� ���� 1�� ���ְ� �������θ� �����̱� ������ VERTICAL�� �μ��� �ش�.
																		*/
	
	checkCondition(Data);	// Ÿ���� �䱸������ ����ִ� ����ü�� �Ķ���ͷ� ������ �ش� ���ǿ� �´� ȸ���� ����ϵ��� ��.
}//SearchData()
void checkCondition(Search Data) {		// Ÿ���� ������ ����ִ� ����ü Data�� �Ķ���ͷ� �޾� �ش��ϴ� ������ ȸ���� ��� ����ϴ� �Լ�
	ListNode *pVisited;		// ��带 �湮�ϸ鼭 �־��� ���ǰ� ���ϴ� ������ �ϴ� �湮������ pVisited
	int i = 0, nCount = 0, nObject = 0, nDifGender = 0;		/*
																i - �ݺ� �����
																nCount - ����� ��ġ���� �����Ͽ� ������ִµ� �̿�Ǵ� ����
																nObject - ����ڰ� ������ ���ǰ� �� �¾� �������� ��� ���� �����ϴ� ����
																nDifGender - ����ڿ� �ݴ�Ǵ� ���� ���� ����� ���� �����ϴ� ����
															*/
	float rate;		// ��ü ȸ�� �� �� �̻����� ������ �´� �����, ���Ǳ��� �����ϴ� ����� ������ �����ϴ� ����

	system("cls");
	gotoxy(0,0);
	printf("=================================================\n");
	printf("                    < ���˻� >                 \n");
	printf("=================================================\n");
	printf("| �� �� | �� �� | �� �� | �� �� | �� �� | �� �� |\n");
	printf("=================================================\n");		// ��� �˻��� ����� ��Ÿ���� �⺻ ��� ��

	pVisited = pHeader;		// pVisited�� ù ��带 ����Ű�� ��
		
	while(pVisited != NULL) {
		if(pVisited->nGender == Data.nGender) {		// ���� ������ ���� ���
			nDifGender++;		// ���� ����� ���� ����ڿ� �ٸ� ������ ȸ���� ���� �߰��� �� ���� 1�� �÷���
			if(pVisited->nAge >= Data.nMinAge && pVisited->nAge <= Data.nMaxAge) {		// ���̰� �����Ǵ� ���
				if(Data.nJob[10] == SELECTED) {		// ������ ���� ���� �� ��� ������ �������� ���
					i = 0;		// i�� 0���� �ʱ�ȭ
				}else {		// ��������� �������� �ʰ�, ���𰡸� ������ ���
					for(i=0; i<10; i++) {	// 0�� �����κ��� 9�� �� �ܱ��� ��ȸ�ϸ鼭 �ش� ����� ������ �Ѱ��� �̻����� �������� ��ġ�ϴ� �� ��
						if(Data.nJob[i] == SELECTED && pVisited->nJob == i+1)	break;
					}// for
				}// if-else
				if(i != 10) {	// else���� ���ϴ� ����� ã�� ������ ���, i==10�� �ȴ�. break�� ������� ���� ��. �� ����� �״�� ������, ���� �ƴ� ���ϱ� ���� if����
					if(Data.nAnnualIncome <= pVisited->nAnnualIncome) {		// �ּ� ���������� ����
						if(Data.nAcademicAbility <= pVisited->nAcademicAbility) {	// �ּ� �з� ���Ǳ��� ����
							printData(nCount);		// �ش� ��尪�� �Ѱ��־� �ش� ȸ���� ����ϰ� ��.
							nObject++;		// ��ǥ�� 100%�����ϴ� �̻����� ���� 1 ������Ų��. rate���� �� ���.
						}//if
					}//if
				}//if
			}//if
		}//if
		pVisited = pVisited->link;		// �� ĭ ����. �� ��忡 ���ؼ� ���� �͵��� �� ����
		nCount++;		// ����� position���� �ϳ� ������Ŵ
	}// while

	rate = (float)100*nObject/nDifGender;		// �̻����� ������ ������ �ִ� ��� �� ��� ���� �Ӹ� �ƴ϶� �ٸ� ���Ǳ��� ��� �����ϴ� �̻����� ������ ���ϰ� ����

	if(nObject != 0) {		// �̻����� 1���̶� ������ ���
		printf("=================================================\n");
		printf("����� �̻����� %d���� �̼� �� %d���̱���...\n", nDifGender, nObject);
		printf("������ %.2f���Դϴ�...\n", rate);
		printf("=================================================\n");
		printf("�����÷��� �ƹ� Ű�� ��������...");		// ��� ���
		getch();
	}else if(nObject == 0) {		// �͹��Ͼ��� ������ �����Ͽ� �̻����� ���ڰ� 0�� ����� ���â. ���� ���� ���Ǻ��� �ΰ��̸� ������ ���� ^^.... 
		printf("ã���ô� ȸ���� �����ϴ�...\n");
		printf("���� ������ ������...���...���\n");	
		printf("=================================================\n");
		printf("�����÷��� �ƹ� Ű�� ��������...");
		getch();
	}//if-else if
}//checkCondition()
void initializeMenu() {
	ListNode *pVisited;		// ��带 �ϳ��ϳ� �ʱ�ȭ���ֱ� ���ؼ� �� ��带 ��ȸ�ϸ� �ʱ�ȭ ���ִ� ������ �ϴ� ����ü ������ pVisited.
	int flag;		// �ʱ�ȭ ���� ���θ� �����ϴ� ����.

	system("cls");		// ȭ�� �����
	if (pHeader == NULL) {
		printf("���� �ʱ�ȭ�� ������ �����ϴ�.\n");
		printf("�ƹ� Ű�� ������ �������� ���ư��ϴ�...");
		getch();
		return;
	}	// pHeader == NULL, �� ����Ʈ�� �ƹ� �����͵� �������� �ʴ´ٸ�, initialize Menu ���� ������ �ʿ䰡 ����. ���� �� ��� �Լ��� ����. 

	printf("==========================\n");
	printf("        < �ʱ�ȭ >        \n");
	printf("==========================\n");
	printf("������ �ʱ�ȭ�Ͻðڽ��ϱ�?\n");
	printf("               YES |  NO  \n");
	printf("==========================\n");		// �ʱ�ȭ ���θ� ���� �⺻ �����.
	flag = key_shift(HORIZONTAL, 16, 4, 22, 4, 6, 0, 1);		// Yes or No�� ����̹Ƿ� HORIZONTAL�� �μ��� ������ ������� �°� x��ǥ�� y��ǥ�� �����ؼ� �Ķ���ͷ� ����. �����ε����� 1.

	system("cls");		// ȭ�� �����
	if (flag == YES) {		// ����ڰ� �ʱ�ȭ �ϰ��� ���Ѵٸ�,
		while (pHeader != NULL) {
			pVisited = pHeader;		// �ϴ� pVisited�� ù ��带 ����Ű�� �� ��
			pHeader = pHeader->link;		// pHeader�� pHeader�� ���� ��带 ����Ű�� �ϸ鼭 ù ������ ������ ����.
			free(pVisited);		// ù ���� pVisited�� ����Ű�� ���� �״� �̸� free���ָ� ��尡 �ʱ�ȭ �ȴ�.
		}//while
		// �ʱ�ȭ ����
		printf("�ʱ�ȭ�� �Ϸ�Ǿ����ϴ�.\n");
		printf("����Ͻ÷��� �ƹ�Ű�� ��������...");		// �ʱ�ȭ�� �Ϸ�Ǿ����� ���
	}
	else {
		printf("�ʱ�ȭ�� ��ҵǾ����ϴ�.\n");
		printf("����Ͻ÷��� �ƹ�Ű�� ��������...");		// ����ڰ� NO�� �����Ͽ� �ʱ�ȭ�� ������� �ʾ����� ���
	}
	getch();	// �ƹ� Ű�� �Է¹ް�, �ٽ� main�Լ��� ���ư�.
}//initialize()

void outputFileMenu() {		// �ܺο� ������ ������ �ҷ����� �޴�
	FILE *fp;		// �ҷ��� ������ ������ ������
	char strFileName[40];	// �ҷ��� ���� ���� ������ �迭 ����
	int i, nodeCount = 0, nEOF, flag;	// for �ݺ������� �� ���� i, ��尳���� ���� ���� ī��Ʈ���� ���� �� 0���� �ʱ�ȭ, �������� ���� ����, yes or no ������ ���� ���� ����
	ListNode *pData, *pVisited, *pPrev;

	system("cls");
	printf("==========================\n");
	printf("        < �������� >        \n");
	printf("==========================\n");
	printf("���ϸ��� �Է��ϼ���.\n");
	printf("-> \n");
	printf("==========================\n");
	gotoxy(3, 4);
	scanf("%s", strFileName);		// ���� �� ���ϸ� �Է�

	fp = fopen(strFileName, "rb");		// read binary���� ������ ����. fp�� �ش� ���̳ʸ� ������ ����Ű�� ��

	if (fp == NULL) {	// ������ �������� �ʰų�, �ٸ� �������� ������ ���
		printf("%s ������ �������� �ʽ��ϴ�.\n", strFileName);
		printf("�����÷��� �ƹ� Ű�� ��������...");
		getch();
		return;		// ������ �� �� ������ ����ϰ� �Լ� ����
	}//if

	if (pHeader != NULL) {		// pHeader�� ����Ʈ�� ���� �Ǿ��ִ� ���, �� NULL�� �ƴ� ��
		gotoxy(0, 6);	// Ŀ���� �̵��ϰ�
		printf("������ �����Ϳ� �߰��˴ϴ�.\n");
		printf("������ �ҷ����ðڽ��ϱ�?\n");		// ���α׷� �󿡼� ����Ǿ� ����� �����Ϳ� ������ �����Ͱ� �߰����� ����ϴ� â ���
		printf("               YES |  NO  \n");
		printf("==========================\n");
		flag = key_shift(HORIZONTAL, 16, 8, 22, 8, 6, 0, 1);		// key_shift�Լ��� ���� ������� �ǻ縦 ����

		if (flag == NO) {		// '�ƴϿ�'�� �����ߴٸ�,
			gotoxy(0, 10);
			printf("���� �ҷ����Ⱑ ��ҵǾ����ϴ�.\n");
			printf("�����÷��� �ƹ�Ű�� ��������...");		// ���Ϻҷ����Ⱑ ��ҵǾ����� ����ϰ�
			getch();
			fclose(fp);
			return;		//�Լ� ����
		}// if
	}//if
	else flag = NO;		// �ڿ��� �� flag�� �� �� �� ���ǹǷ�, �ٽ� NO�� �������ش�.

	fseek(fp, 0, SEEK_END);		// ���������� fp�� �� ������ ��ġ�� ������

	nEOF = ftell(fp);	// SEEK_SET���� ���� ������ SEEK_END���� �� �������� �뷮�� nEOF�� ����. �Ŀ� ��� ���� ���ϴ� ������ �̿�.
	nodeCount = nEOF / sizeof(ListNode);	// ����Ʈ�� �� �뷮�� ����ü ũ��� ���� ��� ������ ����
	rewind(fp);		// �ٽ� ó������ ����������.

	for (i = 0; i<nodeCount; i++) {		// ���� nodeCount, ����� ������ŭ
		pData = (ListNode*)malloc(sizeof(ListNode));	// pData �������� ���� �޸��Ҵ�
		fread(pData, sizeof(ListNode), 1, fp);			// pData�� ����� ���Ͽ��� ListNode ����ü�� ũ�⸸ŭ�� ������ �о� �����ּҿ� ������ ��� ���� ��ȯ�ϱ�
		pData->link = NULL;		// ���� ������� �ʾ����Ƿ� pData�� ��ũ�ʵ带 NULL�� �ʱ�ȭ

		if (pHeader == NULL)		// ��尡 ���� ���
			pHeader = pData;	// pHeader�� pData�� �������ش�.
		else{		// ��尡 �ϳ��� �ִ� ���
			pVisited = pHeader;		// pHeader�� ù ��带 ����Ű�� ��
			pPrev = NULL;		// ��� �����ʹ� ������� �ʾ����Ƿ� NULL

			while (pVisited != NULL && strcmp(pData->strName, pVisited->strName) > 0) {		// �̸������� �����ϱ� ���� ��ġã��
				pPrev = pVisited;		
				pVisited = pVisited->link;		// pPrev�� pVisited�� ����
				if (pVisited == NULL) break;	// pVisited�� NULL�̸� while�� Ż���Ѵ�.
			}//while

			if (pPrev == NULL) {	// ���� ������ ��ġ�� �ʾ��� ���, �� ó������ ���� �� ���
				pData->link = pHeader;		// pData�� ��ũ�ʵ带 pHeader�� ����Ű�� �ִ� ù ��带 ����Ű�� �ϰ�
				pHeader = pData;		// pHeader�� pData�� ����Ű�� �Ѵ�.
			}//if
			else {
				pData->link = pPrev->link;
				pPrev->link = pData;		// �� ���� ��� ����
			}//else
		}//else
	}//for

	if (flag == NO)	gotoxy(0, 6);
	else			gotoxy(0, 10);
	printf("������ �ҷ����Ⱑ �Ϸ�Ǿ����ϴ�...\n");
	printf("�����÷��� �ƹ� Ű�� ��������...");		// ��� ���
	getch();

	fclose(fp);		// ���� �ݱ�
}//outputFileMenu()
void inputFileMenu() {		// �Է��� ������ �ܺ����Ϸ� �����ϱ�
	FILE *fp;		// ������ ������ ����ų ������
	ListNode *pVisited, *pData, *pPrev;
	char strFileName[40];		// ������ ���� ��
	int i, nodeCount = 0, flag;		// for �ݺ����� ���� ���� i, ����� ������ �������� ���� ����� 0���� �ʱ�ȭ, Yes or No ������ ���� ��������

	system("cls");
	if (pHeader == NULL) {		// �Էµ� ������ ���� ���
		printf("���� ������ ������ �����ϴ�.\n");
		printf("�ƹ� Ű�� ������ �������� ���ư��ϴ�...");
		getch();
		return;
	}//if
	// �Էµ� ������ �ִ� ���
	printf("==========================\n");
	printf("       < �������� >       \n");
	printf("==========================\n");
	printf("������ �������ðڽ��ϱ�?  \n");
	printf("               YES |  NO  \n");
	printf("==========================\n");
	flag = key_shift(HORIZONTAL, 16, 4, 22, 4, 6, 0, 1);		// �������� �����̸�, x��ǥ�� 16~22 ���̿��� �� ���� 6ĭ�� �̵�, y��ǥ�� 4���� �����ȴ�, �� ���� flag�� ����

	if(flag == NO) {   // ���������� ���� ���� ���
		gotoxy(0, 6);	//x,y ��ǥ (0,6)���� Ŀ�� �̵�
		printf("���� �������Ⱑ ��ҵǾ����ϴ�.\n");
		printf("�����÷��� �ƹ�Ű�� ��������...");
		getch();
		return;
	}//if

	system("cls");
	gotoxy(0, 0);	// x,y��ǥ (0,0)���� �̵�
	printf("==========================\n");
	printf("       < �������� >       \n");
	printf("==========================\n");
	printf("���ϸ��� �Է��ϼ���.\n");
	printf("-> \n");
	printf("==========================\n");
	gotoxy(3, 4);	// x,y��ǥ (3,4)�� Ŀ�� �̵�
	scanf("%s", strFileName);	// ���� ���� �Է¹޾� ���α׷� �� ����� �����͸� ������ ������ �����. 

	fp = fopen(strFileName, "wb");		//��ϴ����� ���Ͽ� ����

	if (fp == NULL) {	// ���������Ϳ� �Ҵ�� ������ ����
		system("cls");
		printf("�Ͻ��� ������ �߻��Ͽ����ϴ�.\n");
		printf("�ٽ� �õ��� �ֽʽÿ�.\n");
		getch();
		return;
	}//if

	if (strcmp("file.dat", strFileName) == 0) {		// ������ ���� ���� file.dat(ȸ�������� ����� ��������) �� ���
		gotoxy(0, 6);	// x,y��ǥ (0,6)���� Ŀ�� �̵�
		printf("�� ������ ���� �����Դϴ�.\n");
		printf("�׷��� ���� ���ðڽ��ϱ�?\n");
		printf("               YES |  NO  \n");
		printf("==========================\n");
		flag = key_shift(HORIZONTAL, 16, 8, 22, 8, 6, 0, 1);	// �������θ� �̵�, x��ǥ�� 16~22 ���̿��� �� ���� 6ĭ �� �̵��ϰ� , y��ǥ�� 8���� ����, �� ���� flag�� �����Ѵ�.
		if(flag == NO) {	// NO�� ������ ���
			gotoxy(0, 10);	// x,y��ǥ (0,10)���� Ŀ�� �̵�
			printf("���� �������Ⱑ ��ҵǾ����ϴ�.\n");
			printf("�����÷��� �ƹ�Ű�� ��������...");
			getch();
			return;
		}//if
	}//if

	pVisited = pHeader;		// pVisited�� �� ù ��° ��� ����Ų��.
	while (pVisited != NULL) {		//pVisited�� ����Ű�� ���� ���� ���
		fwrite(pVisited, sizeof(ListNode), 1, fp);		//pVisited���� ����� ListNode ����ü�� ũ�� ����Ʈ�� �����͸� fp�� ����� ���Ͽ� ����.
		pVisited = pVisited->link;		//pVisited ����
	}//while
	gotoxy(0, 6);		// x,y��ǥ (0,10)���� Ŀ�� �̵�
	printf("������ �������Ⱑ �Ϸ�Ǿ����ϴ�...\n");
	printf("�����÷��� �ƹ� Ű�� ��������...");
	getch();

	fclose(fp);
}//inputFileMenu()
void about() {
	system("cls");	
	printf("==========================\n");
	printf("       < �������� >       \n");
	printf("==========================\n");
	printf("���α׷� : ��ȥ�ص��\n");
	printf("������   : 2KJP\n\n");
	printf("����        : ver 5.2\n");
	printf("���� ������ : 2015 12 08\n");
	printf("==========================\n");		// ��ȥ����ȸ�� ���� ���α׷��� ������ �������� ���� ������ ���۱� ������ ���
	getch();
}//about()
int key_shift(int flag, int min_x, int min_y, int max_x, int max_y, int tab_x, int tab_y, int nIndex) {
	char chInput;		// ����Ű�� �� ���ڶ�� �� �� ����. ����Ű ������ ������ �� ���ڿ� ���� chInput.
	int x = min_x, y = min_y;	// x��ǥ�� y��ǥ�� �����ϴ� ���� ���� x�� y. ���� �Ķ���ͷ� ���޹��� �ּҰ����� �ʱ�ȭ ��.
	int row_size;	/*
					���� x����, y���� ��� ������ �� �ְ� �ȴٸ�,
					y�������� ������ �� �ε����� ����ȭ �Ǿ�� �� ����. ����, ���δ� 1�� �����ϴ���
					���δ� �ٸ� ������ ����ȭ�� �־� �ð� �ؾ� ���� �����̰� �ִ� ����� �ε����� ��Ī�� �� ����.
					���η� ������ �� �ε����� Ư���� ����ŭ ���Ӱ� ������Ű�� ����.
					*/

	row_size = max_x - min_x + 1;		// max_x�� min_x�� ���� 1 ���� ��ŭ �ε����� �þ�� �پ�� �Ѵ�. (������ �츮 ���α׷����� �ܹ��⸸ �����. �׷��� x�� y�� �ε����� 1�� ��ȭ.)

	gotoxy(x, y);		// x�� �ּڰ��� y�� �ּڰ��� ��ǥ�� Ŀ���� �̵���Ų��.
	if (flag == VERTICAL) {		// ���� �������θ� �����̱�� �ߴٸ�,
		printf("->");		// ->�� ǥ���Ͽ� ���� Ŀ���� ��� ���ִ����� �� �� �ְ� �Ѵ�.
		gotoxy(0, 0);		// (0,0)���� Ŀ�� �̵�.
	}
	else if (flag == HORIZONTAL) {		// ���� �������θ� �����̱�� �ߴٸ�,
		gotoxy(x - 3, y);		// ���� x���� 3ĭ �ڷ� ����
		printf("[");	// [�� ����ϰ�
		gotoxy(x + 3, y);		// x���� 3ĭ ������ ���� 
		printf("]");	// ]�� ����ϴ� ������ ǥ���Ͽ� ���� Ŀ���� ��� ���ִ����� �� �� �ְ� �Ѵ�.
		gotoxy(0, 0);	// (0,0)���� Ŀ�� �̵�
	}

	while (TRUE) {
		chInput = getch();		// ����Ű ���� getch()�� ���� (�ؿ� �޼��� ��� ���� �ٷ� �ް� �ϴ� �Լ�)
		gotoxy(x, y);		// x��ǥ�� y��ǥ�� �����Ͽ� Ŀ�� �̵�
		if (flag == VERTICAL) {		// ���� �̵��� ���
			gotoxy(x, y);
			printf("  ");	// �ٸ� ������ �̵��ϰ� �Ǹ�, ���� ����ߴ� ->ǥ�� ����� �κ�. ������ �ʴ´ٸ� ����ؼ� ���� �Ǿ� ������ �� Ŀ���� ����ִ��� �� �� ���� ��.
		}
		else if (flag == HORIZONTAL) {		// ���� �̵��� ���
			gotoxy(x - 3, y);
			printf(" ");
			gotoxy(x + 3, y);
			printf(" ");	// ���������� �ٸ� ������ �̵��ϰ� �Ǹ� [ �� ]�� ���� �� Ŀ���� ��� �κп� �ִ��� Ȯ���ϰ� �˰� �Ѵ�.
		}
		switch (chInput) {		// ȭ��ǥ�� ���� chInput�� �б�� �Ͽ� Ű������ �����ӿ� ���� Ư�� ���� ����.
		case ENTER:		// �ش� �޴� �Ǵ� ������ �����ϰ��� �� ��
			return nIndex;		// Index���� ��ȯ�ϸ鼭 �Լ��� ����ħ.
			break;
		case LEFT:		// �·� ������ ��
			if (flag == HORIZONTAL) {	// ��, ��� �����̴� ���� HORIZOTAL ����� �Ķ���ͷ� �������� ��. ���� �� ���� nIndex�� x��ǥ�� �����Ű�� if���� Ȱ��.
				x = x - tab_x;
				if (x < min_x)	x = min_x;		// x�� �ּ���ǥ���� �۾����� �Ǹ� ��� Ŀ���� �ּҰ��� �ΰ�, nIndex���� �״�� ������Ų��.
				else			nIndex--;		// �ƴ϶�� �ε��� ���� ���� ��Ų��.
			}
			break;
		case RIGHT:
			if (flag == HORIZONTAL) {	// LEFT�� ���� ��������.
				x = x + tab_x;
				if (x > max_x)	x = max_x;		// x�� �ִ���ǥ���� Ŀ���� �Ǹ� ��� Ŀ���� �ִ밪�� �ΰ�, nIndex���� �״�� ������Ų��.
				else			nIndex++;		// �ƴ϶�� �ε��� ���� ���� ��Ų��.
			}
			break;
		case UP:
			if (flag == VERTICAL) {		// ��, �Ϸ� �����̴� ���� VERTICAL ����� �Ķ���ͷ� �������� ��. ���� �� ���� nIndex�� y��ǥ�� �����Ű�� if���� Ȱ��.
				y = y - tab_y;
				if (y < min_y)	y = min_y;		// y�� �ּ���ǥ���� �۾����� �Ǹ� ��� Ŀ���� �ּҰ��� �ΰ�, nIndex�� �״�� ����
				else			nIndex -= row_size;		// �ƴ϶�� �ε��� ���� ���� ��Ų��.
			}
			break;
		case DOWN:
			if (flag == VERTICAL) {		// UP�� ���� ��������.
				y = y + tab_y;
				if (y > max_y)	y = max_y;		// y�� �ִ���ǥ���� Ŀ���� �Ǹ� ��� Ŀ���� �ִ밪�� �ΰ�, nIndex ���� �״�� ������Ų��.
				else			nIndex += row_size;		// �ƴ϶�� �ε��� ���� ���� ��Ų��.
			}
			break;
		}//switch-case
		gotoxy(x, y);	// switch���� ���� ����� x��ǥ�� y��ǥ�� �ݿ��ϴ� gotoxy. 
		if (flag == VERTICAL) {
			printf("->");
			gotoxy(0, 0);		// �������� ������ ��� ->�� Ŀ���� �ٲ� ���� �ٽ� ���
		}
		else if (flag == HORIZONTAL) {
			gotoxy(x - 3, y);
			printf("[");
			gotoxy(x + 3, y);
			printf("]");
			gotoxy(0, 0);		// �������� ������ ��� [ ]�� Ŀ���� �ٲ� ���� �ٽ� ���
		}
	}//while
}//key_shift()
void gotoxy(int x, int y) {
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}//gotoxy()
// Ŀ���� ��ġ�� ���� ������ x���� y������ �Ű��ִ� �Լ� gotoxy. �Ķ���ͷ� ���� �� x, y�� Ŀ���� �ű�.