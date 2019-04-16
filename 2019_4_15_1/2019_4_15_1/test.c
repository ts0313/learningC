//ͨѶ¼
//1. �����ϵ����Ϣ
//2. ɾ��ָ����ϵ����Ϣ
//3. ����ָ����ϵ����Ϣ
//4. �޸�ָ����ϵ����Ϣ
//5. ��ʾ������ϵ����Ϣ
//6. ���������ϵ��
//7. ����������������ϵ��
//8. ������ϵ�˵��ļ�
//9. ������ϵ��
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

void Init() {												//��ʼ��
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
	printf("�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
	printf("�U�T�T�T�T�T�T�T�T�T�T  ͨѶ¼  �T�T�T�T�T�T�T�T�T�T�U\n");
	printf("�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
	printf("�U    1. ������ϵ��             2. ɾ����ϵ��	    �U\n");
	printf("�U    3. ������ϵ��             4. ������ϵ��	    �U\n");
	printf("�U    5. ��ӡȫ����ϵ��         6. ������ϵ��	    �U\n");
	printf("�U    7. ���ȫ����ϵ��         0. �˳�		    �U\n");
	printf("�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");

	int choice = 0;
	scanf("%d", &choice);
	return choice;
}

void Empty() {

}

void AddPersonInfo() {
	printf("������ϵ��\n");
	if (g_address_book.size >= MAX_PERSONINFO_SIZE) {
		printf("������ϵ��ʧ��!\n");
		return;
	}
	PersonInfo* person_info = &g_address_book.persons[g_address_book.size];
	printf("������������ϵ������: ");
	scanf("%s", person_info->name);
	printf("��������ϵ���Ա�: ");
	scanf("%s", person_info->sex);
	printf("��������ϵ������: ");
	scanf("%s", person_info->age);
	printf("��������ϵ�˵绰: ");
	scanf("%s", person_info->phone);
	printf("��������ϵ�˵�ַ: ");
	scanf("%s", person_info->address);
	++g_address_book.size;
	printf("������ϵ�˳ɹ�!\n");
}

void DelPersonInfo() {
	printf("ɾ����ϵ��!\n");
	if (g_address_book.size <= 0) {
		printf("ɾ��ʧ��,ͨѶ¼Ϊ��!\n");
		return;
	}
	int id = 0;
	scanf("%d", &id);
	if (id < 0 || id >= g_address_book.size) {
		printf("ɾ��ʧ��,������������!\n");
		return;
	}
	g_address_book.persons[id] =
		g_address_book.persons[g_address_book.size - 1];
	--g_address_book.size;
	printf("ɾ����ϵ�˳ɹ�!\n");
}

void FindPersonInfo() {
	printf("������ϵ��!\n");
	if (g_address_book.size <= 0) {
		printf("����ʧ��,ͨѶ¼Ϊ��!\n");
		return;
	}
	printf("��������ϵ������: \n");
	char name[1024] = { 0 };
	scanf("%s", &name);
	for (int i = 0; i < g_address_book.size; ++i) {
		PersonInfo* info = &g_address_book.persons[i];
		if (strcmp(info->name, name) == 0) {
			printf("[%d] %s\t%s\t%s\t%s\t%s\n",
				i, info->name, info->sex, info->age, info->phone, info->address);
		}
	}
	printf("������ϵ�˳ɹ�!\n");
}

void UpdatePersonInfo() {
	printf("������ϵ��!\n");
	if (g_address_book.size <= 0) {
		printf("�޸�ʧ��,ͨѶ¼Ϊ��!\n");
		return;
	}
	int id = 0;
	scanf("%d", &id);
	if (id < 0 || id >= g_address_book.size) {
		printf("�޸�ʧ��,������������!\n");
		return;
	}
	PersonInfo* info = &g_address_book.persons[id];
	printf("�������µ�����: (%s)\n", info->name);
	char name[1024] = { 0 };
	scanf("%s", info->name);
	if (strcmp(name, "") != 0) {
		strcpy(info->name, name);
	}
	printf("�������µ��Ա�: (%s)\n", info->sex);
	char sex[1024] = { 0 };
	scanf("%s", info->sex);
	if (strcmp(sex, "") != 0) {
		strcpy(info->sex, sex);
	}
	printf("�������µ�����: (%s)\n", info->age);
	char age[1024] = { 0 };
	scanf("%s", info->age);
	if (strcmp(age, "") != 0) {
		strcpy(info->age, age);
	}
	printf("�������µĵ绰: (%s)\n", info->phone);
	char phone[1024] = { 0 };
	scanf("%s", info->phone);
	if (strcmp(phone, "") != 0) {
		strcpy(info->phone, phone);
	}
	printf("�������µĵ�ַ: (%s)\n", info->address);
	char address[1024] = { 0 };
	scanf("%s", info->address);
	if (strcmp(address, "") != 0) {
		strcpy(info->address, address);
	}
	printf("������ϵ�˳ɹ�!\n");
}

void PrintAllPersonInfo() {
	printf("��ӡȫ����ϵ��\n");
	for (int i = 0; i < g_address_book.size; ++i) {
		PersonInfo* info = &g_address_book.persons[i];
		printf("[%d] %s\t%s\t%s\t%s\t%s\n", i, info->name, info->sex,
			info->age, info->phone, info->address);
	}
	printf("����ӡ�� %d ������!\n", g_address_book.size);
	printf("��ӡȫ����ϵ�˳ɹ�!\n");
}

void SortPersonInfo() {
	printf("������ϵ��!\n");
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
	printf("������ϵ�˳ɹ�!\n");
}

void ClearAllPersonInfo() {
	printf("���ȫ������!\n");
	printf("ȷ�����ȫ������? Y/N\n");
	char choice[1024] = { 0 };
	scanf("%s", &choice);
	if (strcmp(choice, "Y") == 0) {
		g_address_book.size = 0;
		printf("���ȫ�����ݳɹ�!\n");
	}
	else {
		printf("��ղ���ȡ��!\n");
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
			printf("������������!\n");
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