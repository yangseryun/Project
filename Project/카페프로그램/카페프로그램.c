//1)주문하기
//	1-1. 메뉴판 출력
//	1-2. 주문할 메뉴 번호 입력
//	1-3. 주문한 메뉴에 따라 전체 결제금액에 추가
//	1-4. 주문한 메뉴를 주문내역에 추가

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void order();
void cancel();
void pay();

char* menuList[5];	//5개의 메뉴 주문 가능
int orderIdx = 0;
int total = 0;

void main() {
	int sc;
	printf("	ㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁCafeㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁ\n");
	printf("\n");
	while (1) {
		
		if (orderIdx > 0) {
			
			for (int i = 0; i < orderIdx; i++) {
				printf("%S ", menuList[i]);
			}

			printf("\n		현재 결제금액 : %d원\n", total);
			printf("\n");
			printf("\n");
		}

		printf("			1. 주문하기\n");
		printf("			2. 취소하기\n");
		printf("			3. 결제하기\n");
		printf("			4. 끝내기\n");
		printf("		입력 : ");
		scanf("%d", &sc);
		printf("\n");

		if (sc == 1) { order(); }
		else if (sc == 2) { cancel(); }
		else if (sc == 3) { pay(); }
		else if (sc == 4) {
			printf("		프로그램종료");
			break;}
		else { printf("		잘못입력하셨습니다.\n"); }
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
	printf("		주문할 메뉴 번호 입력 : ");
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

//2) 취소하기
//	2-1. 주문내역 출력
//	2-2. 취소할 메뉴번호 입력
//	2-3. 취소한 메뉴의 금액을 전체 결제금액에서 제거
//	2-4. 취소한 메뉴를 주문내역에서 제거

void cancel() {
	int delIdx;
	int price;

	if (orderIdx > 0) {
		printf("		현재 주문 내역\n");

		for (int i = 0; i < orderIdx; i++) {
			printf("%d.%s\n", i + 1, menuList[i]);
		}

		printf("		삭제할 메뉴 번호 : ");
		scanf("%d", &delIdx);
		char* deletMenu = menuList[delIdx - 1];
		printf("\n");
		printf("		%s가 삭제되었습니다.\n",deletMenu);
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

//3) 결제하기
//	3-1. 전체 결제금액 출력
//	3-2. 결제할 금액 입력
//	3-3. 결제할 금액>전체결제금액 일때만 결제 완료
//	3-4. 거스름돈 출력후 전체 결제 금액 = 0
//	3-5. 주문내역 모두 없애기

void pay() {
	int money;

	printf("		전체 금액 : %d\n", total);
	printf("		지불한 금액 : ");
	scanf("%d", &money);

	if (total <= money) {
		printf("\n");
		printf("		결제완료 : 잔돈은 %d원\n", money - total);
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
		printf("		금액이 부족합니다.\n");
	}
}