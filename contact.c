#include"Contact.h"

void InitContact(Contact* pc) {
	assert(pc);
	pc->count = 0;
	memset(pc->data, 0, sizeof(pc->data));
	//将通讯录为空
}
void AddContact(Contact* pc) {
	assert(pc);
	if(pc->count == 100){
		printf("通讯录已满，无法添加");
		return;
	}
	printf("请输入名字:>\n");
	scanf_s("%s", pc->data[pc->count].name,10);
	printf("请输入年龄:>\n");
	scanf_s("%s", pc->data[pc->count].age,10);
	printf("请输入性别:>\n");
	scanf_s("%s", pc->data[pc->count].sex,10);
	printf("请输入电话:>\n");
	scanf_s("%s", pc->data[pc->count].tel,10);
	printf("请输入地址:>\n");
	scanf_s("%s", pc->data[pc->count].addr,10);
	pc->count++;
	printf("添加成功\n");




}
void ShowContact(const Contact* pc) {
	assert(pc);
	int i = 0;
	printf("%20s\t%5s\t%5s\t%12s\t%30s \n", "名字", "年龄","性别", "电话", "地址");
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
	printf("请删除名字>");
		
	if (pc->count == 0) {

		printf("啥也没有，\n");
		return;
	}
	scanf_s("%s",name,10);
	//查找
	int pos=FindName(pc, name);
	if (pos == -1) {
		printf("不存在\n");
		return;
	}//删除
	for (i = pos; i < pc->count-1; i++) {
		pc->data[i] = pc->data[i + 1];
	}
	pc->count--;
	printf("删除成功\n");

}
void SearchContact(Contact* pc) {
	assert(pc);
	
	char name[40] = { 0 };
	printf("请查找名字>");
	scanf_s("%s",name,2);
	int pos = FindName(pc, name);
	if (pos == -1) {
		printf("此人不存在\n");
		return;
	}
		//打印
	printf("%20s\t%5s\t%5s\t%12s\t%30s\n", "名字", "年龄", "性别", "电话", "地址");
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
	printf("请修改名字>");
	scanf_s("%s", name, 2);
	int pos = FindName(pc, name);
	if (pos == -1) {
		printf("此人不存在\n");
		return;
	}
	//修改
	printf("吊毛，找到你了\n");
	printf("请输入名字:>\n");
	scanf_s("%s", pc->data[pos].name, 10);
	printf("请输入年龄:>\n");
	scanf_s("%s", pc->data[pos].age, 10);
	printf("请输入性别:>\n");
	scanf_s("%s", pc->data[pos].sex, 10);
	printf("请输入电话:>\n");
	scanf_s("%s", pc->data[pos].tel, 10);
	printf("请输入地址:>\n");
	scanf_s("%s", pc->data[pos].addr, 10);
	pc->count++;
	printf("修啊成功\n");


}

int cmp_age(const void* e1, const void* e2) {
	return strcmp(((People*)e1)->age, ((People*)e2)->age);

}
void SortContact(Contact* pc) {
	assert(pc);
	
	qsort(pc->data, pc->count, sizeof(People), cmp_age);
	printf("win\n");
}