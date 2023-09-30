#include"Contact.h"

void InitContact(Contact* pc) {
	assert(pc);
	pc->count = 0;
	memset(pc->data, 0, sizeof(pc->data));
	//��ͨѶ¼Ϊ��
}
void AddContact(Contact* pc) {
	assert(pc);
	if(pc->count == 100){
		printf("ͨѶ¼�������޷����");
		return;
	}
	printf("����������:>\n");
	scanf_s("%s", pc->data[pc->count].name,10);
	printf("����������:>\n");
	scanf_s("%s", pc->data[pc->count].age,10);
	printf("�������Ա�:>\n");
	scanf_s("%s", pc->data[pc->count].sex,10);
	printf("������绰:>\n");
	scanf_s("%s", pc->data[pc->count].tel,10);
	printf("�������ַ:>\n");
	scanf_s("%s", pc->data[pc->count].addr,10);
	pc->count++;
	printf("��ӳɹ�\n");




}
void ShowContact(const Contact* pc) {
	assert(pc);
	int i = 0;
	printf("%20s\t%5s\t%5s\t%12s\t%30s \n", "����", "����","�Ա�", "�绰", "��ַ");
	for (i = 0; i < pc->count; i++) {
		printf("%20s\t%5s\t%5s\t%12s\t%30s\n",
			pc->data[i].name,
			pc->data[i].age,
			pc->data[i].sex,
			pc->data[i].tel,
			pc->data[i].addr);

	}


}
static FindName(Contact* pc, char name[]) {
	assert(pc);
	int i = 0;
	for (i = 0; i < pc->count; i++) {
		if (0 == strcmp(pc->data[i].name, name)) {
			return i;
		}

	}


	return -1;
}
void DelContact( Contact* pc) {
	assert(pc);
	int i = 0;
	char name[40] = {0};
	printf("��ɾ������>");
		
	if (pc->count == 0) {

		printf("ɶҲû�У�\n");
		return;
	}
	scanf_s("%s",name,10);
	//����
	int pos=FindName(pc, name);
	if (pos == -1) {
		printf("������\n");
		return;
	}//ɾ��
	for (i = pos; i < pc->count-1; i++) {
		pc->data[i] = pc->data[i + 1];
	}
	pc->count--;
	printf("ɾ���ɹ�\n");

}
void SearchContact(Contact* pc) {
	assert(pc);
	
	char name[40] = { 0 };
	printf("���������>");
	scanf_s("%s",name,2);
	int pos = FindName(pc, name);
	if (pos == -1) {
		printf("���˲�����\n");
		return;
	}
		//��ӡ
	printf("%20s\t%5s\t%5s\t%12s\t%30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	printf("%20s\t%5s\t%5s\t%12s\t%30s\n",
			pc->data[pos].name,
			pc->data[pos].age,
			pc->data[pos].sex,
			pc->data[pos].tel,
			pc->data[pos].addr);

	

}
void  ModifyContact(Contact* pc) {
	assert(pc);

	char name[40] = { 0 };
	printf("���޸�����>");
	scanf_s("%s", name, 2);
	int pos = FindName(pc, name);
	if (pos == -1) {
		printf("���˲�����\n");
		return;
	}
	//�޸�
	printf("��ë���ҵ�����\n");
	printf("����������:>\n");
	scanf_s("%s", pc->data[pos].name, 10);
	printf("����������:>\n");
	scanf_s("%s", pc->data[pos].age, 10);
	printf("�������Ա�:>\n");
	scanf_s("%s", pc->data[pos].sex, 10);
	printf("������绰:>\n");
	scanf_s("%s", pc->data[pos].tel, 10);
	printf("�������ַ:>\n");
	scanf_s("%s", pc->data[pos].addr, 10);
	pc->count++;
	printf("�ް��ɹ�\n");


}

int cmp_age(const void* e1, const void* e2) {
	return strcmp(((People*)e1)->age, ((People*)e2)->age);

}
void SortContact(Contact* pc) {
	assert(pc);
	
	qsort(pc->data, pc->count, sizeof(People), cmp_age);
	printf("win\n");
}