#pragma once
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
#define MAX 100;
//���͵�����
 typedef struct People {
	char name[40];
	char age[4];
	char sex[20];
	char addr[20];
	char tel[30];
}People;
  typedef struct Contact {
	 People data[100];
	 int count;//��¼��Ϣ����

 }Contact;
  //��ʼ��ͨѶ¼
  void InitContact(Contact* pc);
  //����
  void AddContact(Contact* pc);
// ɾ��
  void DelContact( Contact* pc);
  //��ʾͨѶ¼��Ϣ
  void ShowContact(const  Contact* pc);
  //����

   void SearchContact(Contact* pc);
   //�޸�
   void  ModifyContact(Contact* pc);
    void SortContact(Contact* pc);