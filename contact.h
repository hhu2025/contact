#pragma once
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
#define MAX 100;
//类型的声明
 typedef struct People {
	char name[40];
	char age[4];
	char sex[20];
	char addr[20];
	char tel[30];
}People;
  typedef struct Contact {
	 People data[100];
	 int count;//记录信息次数

 }Contact;
  //初始化通讯录
  void InitContact(Contact* pc);
  //增加
  void AddContact(Contact* pc);
// 删除
  void DelContact( Contact* pc);
  //显示通讯录信息
  void ShowContact(const  Contact* pc);
  //查找

   void SearchContact(Contact* pc);
   //修改
   void  ModifyContact(Contact* pc);
    void SortContact(Contact* pc);