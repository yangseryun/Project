//1)爽庚馬奄
//	1-1. 五敢毒 窒径
//	1-2. 爽庚拝 五敢 腰硲 脊径
//	1-3. 爽庚廃 五敢拭 魚虞 穿端 衣薦榎衝拭 蓄亜
//	1-4. 爽庚廃 五敢研 爽庚鎧蝕拭 蓄亜

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void order();
void cancel();
void pay();

char* menuList[5];	//5鯵税 五敢 爽庚 亜管
int orderIdx = 0;
int total = 0;

void main() {
	int sc;
	printf("	けけけけけけけけけけCafeけけけけけけけけけけけ\n");
	printf("\n");
	while (1) {
		
		if (orderIdx > 0) {
			
			for (int i = 0; i < orderIdx; i++) {
				printf("%S ", menuList[i]);
			}

			printf("\n		薄仙 衣薦榎衝 : %d据\n", total);
			printf("\n");
			printf("\n");
		}

		printf("			1. 爽庚馬奄\n");
		printf("			2. 昼社馬奄\n");
		printf("			3. 衣薦馬奄\n");
		printf("			4. 魁鎧奄\n");
		printf("		脊径 : ");
		scanf("%d", &sc);
		printf("\n");

		if (sc == 1) { order(); }
		else if (sc == 2) { cancel(); }
		else if (sc == 3) { pay(); }
		else if (sc == 4) {
			printf("		覗稽益轡曽戟");
			break;}
		else { printf("		設公脊径馬写柔艦陥.\n"); }
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
	printf("		爽庚拝 五敢 腰硲 脊径 : ");
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

//2) 昼社馬奄
//	2-1. 爽庚鎧蝕 窒径
//	2-2. 昼社拝 五敢腰硲 脊径
//	2-3. 昼社廃 五敢税 榎衝聖 穿端 衣薦榎衝拭辞 薦暗
//	2-4. 昼社廃 五敢研 爽庚鎧蝕拭辞 薦暗

void cancel() {
	int delIdx;
	int price;

	if (orderIdx > 0) {
		printf("		薄仙 爽庚 鎧蝕\n");

		for (int i = 0; i < orderIdx; i++) {
			printf("%d.%s\n", i + 1, menuList[i]);
		}

		printf("		肢薦拝 五敢 腰硲 : ");
		scanf("%d", &delIdx);
		char* deletMenu = menuList[delIdx - 1];
		printf("\n");
		printf("		%s亜 肢薦鞠醸柔艦陥.\n",deletMenu);
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

//3) 衣薦馬奄
//	3-1. 穿端 衣薦榎衝 窒径
//	3-2. 衣薦拝 榎衝 脊径
//	3-3. 衣薦拝 榎衝>穿端衣薦榎衝 析凶幻 衣薦 刃戟
//	3-4. 暗什硯儀 窒径板 穿端 衣薦 榎衝 = 0
//	3-5. 爽庚鎧蝕 乞砧 蒸蕉奄

void pay() {
	int money;

	printf("		穿端 榎衝 : %d\n", total);
	printf("		走災廃 榎衝 : ");
	scanf("%d", &money);

	if (total <= money) {
		printf("\n");
		printf("		衣薦刃戟 : 接儀精 %d据\n", money - total);
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
		printf("		榎衝戚 採膳杯艦陥.\n");
	}
}