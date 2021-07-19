//1)�ֹ��ϱ�
//	1-1. �޴��� ���
//	1-2. �ֹ��� �޴� ��ȣ �Է�
//	1-3. �ֹ��� �޴��� ���� ��ü �����ݾ׿� �߰�
//	1-4. �ֹ��� �޴��� �ֹ������� �߰�

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void order();
void cancel();
void pay();

char* menuList[5];	//5���� �޴� �ֹ� ����
int orderIdx = 0;
int total = 0;

void main() {
	int sc;
	printf("	��������������������Cafe����������������������\n");
	printf("\n");
	while (1) {
		
		if (orderIdx > 0) {
			
			for (int i = 0; i < orderIdx; i++) {
				printf("%S ", menuList[i]);
			}

			printf("\n		���� �����ݾ� : %d��\n", total);
			printf("\n");
			printf("\n");
		}

		printf("			1. �ֹ��ϱ�\n");
		printf("			2. ����ϱ�\n");
		printf("			3. �����ϱ�\n");
		printf("			4. ������\n");
		printf("		�Է� : ");
		scanf("%d", &sc);
		printf("\n");

		if (sc == 1) { order(); }
		else if (sc == 2) { cancel(); }
		else if (sc == 3) { pay(); }
		else if (sc == 4) {
			printf("		���α׷�����");
			break;}
		else { printf("		�߸��Է��ϼ̽��ϴ�.\n"); }
	}
}

void order() {

	int sc;
	char* orderMenu = { "" };
	orderMenu = (char*)malloc(sizeof(char) * 20);
	int price = 0;

	printf("		************Menu************\n");
	printf("		*   1. Americano - 3800    *\n");
	printf("		*   2. Espresso  - 2800    *\n");
	printf("		*   3. Cafelatte - 4800    *\n");
	printf("		****************************\n");
	printf("		�ֹ��� �޴� ��ȣ �Է� : ");
	scanf("%d", &sc);
	
	printf("\n");

	switch (sc) {
	case 1:
		orderMenu = "Americano";
		price = 3800;
		break;
	case 2:
		orderMenu = "Espresso";
		price = 2800;
		break;
	case 3:
		orderMenu = "Cafelatte";
		price = 4800;
		break;
	}

	menuList[orderIdx++] = orderMenu;
	total += price;
}

//2) ����ϱ�
//	2-1. �ֹ����� ���
//	2-2. ����� �޴���ȣ �Է�
//	2-3. ����� �޴��� �ݾ��� ��ü �����ݾ׿��� ����
//	2-4. ����� �޴��� �ֹ��������� ����

void cancel() {
	int delIdx;
	int price;

	if (orderIdx > 0) {
		printf("		���� �ֹ� ����\n");

		for (int i = 0; i < orderIdx; i++) {
			printf("%d.%s\n", i + 1, menuList[i]);
		}

		printf("		������ �޴� ��ȣ : ");
		scanf("%d", &delIdx);
		char* deletMenu = menuList[delIdx - 1];
		printf("\n");
		printf("		%s�� �����Ǿ����ϴ�.\n",deletMenu);
		printf("\n");

		if (strcmp(deletMenu, "Americano") == 0)
			price = 3800;
		else if(strcmp(deletMenu, "Espresso") == 0)
			price = 2800;
		else if (strcmp(deletMenu, "CafeLatte") == 0)
			price = 4800;

		total -= price;

		for (int i = delIdx; i <= 5; i++) {
			menuList[i - 1] = menuList[i];
		}

		orderIdx -= 1;
	}
}

//3) �����ϱ�
//	3-1. ��ü �����ݾ� ���
//	3-2. ������ �ݾ� �Է�
//	3-3. ������ �ݾ�>��ü�����ݾ� �϶��� ���� �Ϸ�
//	3-4. �Ž����� ����� ��ü ���� �ݾ� = 0
//	3-5. �ֹ����� ��� ���ֱ�

void pay() {
	int money;

	printf("		��ü �ݾ� : %d\n", total);
	printf("		������ �ݾ� : ");
	scanf("%d", &money);

	if (total <= money) {
		printf("\n");
		printf("		�����Ϸ� : �ܵ��� %d��\n", money - total);
		printf("\n");
		printf("\n");
		total = 0;

		for (int i = 0; i < orderIdx; i++) {
			menuList[i] = "";
		}
		orderIdx = 0;
	}
	else {
		printf("\n");
		printf("		�ݾ��� �����մϴ�.\n");
	}
}