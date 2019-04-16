//通讯录
//1. 添加联系人信息
//2. 删除指定联系人信息
//3. 查找指定联系人信息
//4. 修改指定联系人信息
//5. 显示所有联系人信息
//6. 清空所有联系人
//7. 以名字排序所有联系人
//8. 保存联系人到文件
//9. 加载联系人
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_PERSONINFO_SIZE 1000

typedef struct PersonInfo {
	char name[1024];
	char sex[1024];
	char age[1024];
	char phone[1024];
	char address[1024];
} PersonInfo;

typedef struct AddressBook {
	PersonInfo persons[MAX_PERSONINFO_SIZE];
	int size;
} AddressBook;

AddressBook g_address_book;

void Init() {												//初始化
	g_address_book.size = 0;
	for (int i = 0; i < MAX_PERSONINFO_SIZE; ++i) {
		g_address_book.persons[i].name[0] = '\0';
		g_address_book.persons[i].sex[0] = '\0';
		g_address_book.persons[i].age[0] = '\0';
		g_address_book.persons[i].phone[0] = '\0';
		g_address_book.persons[i].address[0] = '\0';
	}
}

int Menu() {
	printf("╔═════════════════════════╗\n");
	printf("║══════════  通讯录  ══════════║\n");
	printf("╚═════════════════════════╝\n");
	printf("║    1. 新增联系人             2. 删除联系人	    ║\n");
	printf("║    3. 查找联系人             4. 更新联系人	    ║\n");
	printf("║    5. 打印全部联系人         6. 排序联系人	    ║\n");
	printf("║    7. 清空全部联系人         0. 退出		    ║\n");
	printf("╚═════════════════════════╝\n");

	int choice = 0;
	scanf("%d", &choice);
	return choice;
}

void Empty() {

}

void AddPersonInfo() {
	printf("新增联系人\n");
	if (g_address_book.size >= MAX_PERSONINFO_SIZE) {
		printf("新增联系人失败!\n");
		return;
	}
	PersonInfo* person_info = &g_address_book.persons[g_address_book.size];
	printf("请输入新增联系人姓名: ");
	scanf("%s", person_info->name);
	printf("请输入联系人性别: ");
	scanf("%s", person_info->sex);
	printf("请输入联系人年龄: ");
	scanf("%s", person_info->age);
	printf("请输入联系人电话: ");
	scanf("%s", person_info->phone);
	printf("请输入联系人地址: ");
	scanf("%s", person_info->address);
	++g_address_book.size;
	printf("新增联系人成功!\n");
}

void DelPersonInfo() {
	printf("删除联系人!\n");
	if (g_address_book.size <= 0) {
		printf("删除失败,通讯录为空!\n");
		return;
	}
	int id = 0;
	scanf("%d", &id);
	if (id < 0 || id >= g_address_book.size) {
		printf("删除失败,输入的序号有误!\n");
		return;
	}
	g_address_book.persons[id] =
		g_address_book.persons[g_address_book.size - 1];
	--g_address_book.size;
	printf("删除联系人成功!\n");
}

void FindPersonInfo() {
	printf("查找联系人!\n");
	if (g_address_book.size <= 0) {
		printf("查找失败,通讯录为空!\n");
		return;
	}
	printf("请输入联系人姓名: \n");
	char name[1024] = { 0 };
	scanf("%s", &name);
	for (int i = 0; i < g_address_book.size; ++i) {
		PersonInfo* info = &g_address_book.persons[i];
		if (strcmp(info->name, name) == 0) {
			printf("[%d] %s\t%s\t%s\t%s\t%s\n",
				i, info->name, info->sex, info->age, info->phone, info->address);
		}
	}
	printf("查找联系人成功!\n");
}

void UpdatePersonInfo() {
	printf("更新联系人!\n");
	if (g_address_book.size <= 0) {
		printf("修改失败,通讯录为空!\n");
		return;
	}
	int id = 0;
	scanf("%d", &id);
	if (id < 0 || id >= g_address_book.size) {
		printf("修改失败,输入的序号有误!\n");
		return;
	}
	PersonInfo* info = &g_address_book.persons[id];
	printf("请输入新的姓名: (%s)\n", info->name);
	char name[1024] = { 0 };
	scanf("%s", info->name);
	if (strcmp(name, "") != 0) {
		strcpy(info->name, name);
	}
	printf("请输入新的性别: (%s)\n", info->sex);
	char sex[1024] = { 0 };
	scanf("%s", info->sex);
	if (strcmp(sex, "") != 0) {
		strcpy(info->sex, sex);
	}
	printf("请输入新的年龄: (%s)\n", info->age);
	char age[1024] = { 0 };
	scanf("%s", info->age);
	if (strcmp(age, "") != 0) {
		strcpy(info->age, age);
	}
	printf("请输入新的电话: (%s)\n", info->phone);
	char phone[1024] = { 0 };
	scanf("%s", info->phone);
	if (strcmp(phone, "") != 0) {
		strcpy(info->phone, phone);
	}
	printf("请输入新的地址: (%s)\n", info->address);
	char address[1024] = { 0 };
	scanf("%s", info->address);
	if (strcmp(address, "") != 0) {
		strcpy(info->address, address);
	}
	printf("更新联系人成功!\n");
}

void PrintAllPersonInfo() {
	printf("打印全部联系人\n");
	for (int i = 0; i < g_address_book.size; ++i) {
		PersonInfo* info = &g_address_book.persons[i];
		printf("[%d] %s\t%s\t%s\t%s\t%s\n", i, info->name, info->sex,
			info->age, info->phone, info->address);
	}
	printf("共打印了 %d 条数据!\n", g_address_book.size);
	printf("打印全部联系人成功!\n");
}

void SortPersonInfo() {
	printf("排序联系人!\n");
	for (int i = 0; i < g_address_book.size; i++) {
		for (int j = 0; j < g_address_book.size - i - 1; j++) {
			if (strcmp(g_address_book.persons[j].name, g_address_book.persons[j + 1].name) > 0) {
				PersonInfo tmp;
				tmp = g_address_book.persons[j];
				g_address_book.persons[j] = g_address_book.persons[j + 1];
				g_address_book.persons[j + 1] = tmp;
			}
		}
	}
	printf("排序联系人成功!\n");
}

void ClearAllPersonInfo() {
	printf("清空全部数据!\n");
	printf("确认清空全部数据? Y/N\n");
	char choice[1024] = { 0 };
	scanf("%s", &choice);
	if (strcmp(choice, "Y") == 0) {
		g_address_book.size = 0;
		printf("清空全部数据成功!\n");
	}
	else {
		printf("清空操作取消!\n");
	}
}

typedef void(*Func)();

int main() {
	Func arr[] = {
		Empty,
		AddPersonInfo,
		DelPersonInfo,
		FindPersonInfo,
		UpdatePersonInfo,
		PrintAllPersonInfo,
		SortPersonInfo,
		ClearAllPersonInfo
	};

	Init();

	while (1) {
		int choice = Menu();
		if (choice < 0 || choice >= sizeof(arr) / sizeof(arr[0])) {
			printf("您的输入有误!\n");
			break;
		}
		if (choice == 0) {
			printf("Good Bye!\n");
			break;
		}
		arr[choice]();
	}
	system("pause");
	return 0;
}