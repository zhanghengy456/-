#include<stdio.h>
 #include<stdlib.h>
#include<string.h>
#define Max 100
typedef struct pcb
{
	     char name[Max];  //������
	     int priority;    //���ȼ�
	     int arrtime;     //����ʱ��
	    int needtime;    //��Ҫ����ʱ��
	     int usedtime;    //����ʱ��
	     char state;      //����״̬
	 }PCB;
	 PCB pcb[Max];
	
		 int n = 1;
	 int pTime;  //ʱ��Ƭ
	 char SelectMenu();
	 void Input();
	 void Sort();
	 void Print();
	 void Attemper();
	
		 char SelectMenu()
		 {
	     char select;
		     printf("���ܲ˵���");
		     printf("\n    1.���Ӳ����Ƚ���");
		     printf("\n    2.��ӡ����");
		     printf("\n    3.�˳�");
		     printf("\n���������ѡ��(1--3):");
	   do{
			         select = getchar();
			
		} while (select != '1'&&select != '2'&&select != '3');
		     return select;
		 }
	
		 void main()
		 {
		     int choice;
		     n = 1;
		     printf("                       \n");
		     printf("\t\t��ӭʹ�ý��̵���ģ��\n\n");
		     choice = SelectMenu();
		     do{
			         if (choice == '1')
				         {
				             printf("                       \n");
				             printf("������ʱ��Ƭ�Ĵ�С:");
							 scanf_s("%d", &pTime);
				             Input();
				             Print();
				             Attemper();
				         }
			        if (choice == '2')
				         {
				             Print();
				         }
			         if (choice == '3')
				         {
				             return;
				         }
			         choice = SelectMenu();
			
		} while (1);
		 }
	
		 void Input()
		 {
		     do{
			         printf("\n---�������%d�����̽���---\n", n);
			         printf("\n������:");
			         scanf_s("%s", pcb[n].name);
			         printf("�������ȼ�:");
			         scanf_s("%d", &pcb[n].priority);
			         printf("������Ҫ��ʱ��:");
			         scanf_s("%d", &pcb[n].needtime);
			         pcb[n].arrtime = n;
			         pcb[n].usedtime = 0;
			         pcb[n].state = 'W';
			         n++;
			
		} while (n<5);
		 }
	
		 void Sort()
		 {
		     int i, j;
		     PCB temp;
		     for (i = 0; i<n - 1; i++)         //���յ���ʱ������
			     {
			         for (j = n - 2; j >= i; j--)
				         {
				             if (pcb[j + 1].arrtime<pcb[j].arrtime)
					             {
					                 temp = pcb[j];
					                 pcb[j] = pcb[j + 1];
					                 pcb[j + 1] = temp;
					             }
				         }
			     }
		
			     for (i = 0; i<n - 1; i++)      //�������ȼ�����
			     {
			         for (j = n - 2; j >= i; j--)
				         {
				             if (pcb[j + 1].priority>pcb[j].priority)
					             {
					                 temp = pcb[j];
					                 pcb[j] = pcb[j + 1];
					                 pcb[j + 1] = temp;
					             }
				         }
			     }
		    if (pcb[0].state != 'F')
			     {
			         pcb[0].state = 'R';
			     }
		 }
	
		 void Print()
		 {
		     int i;
		     Sort();
		     printf("\n   ������    ���ȼ�  ����ʱ��  ��Ҫʱ��    ����ʱ��   ����״̬ \n");
		     for (i = 0; i<n; i++)
			     {
			         printf("%8s%8d %8d %10d %10d %10c\n", pcb[i].name, pcb[i].priority, pcb[i].arrtime, pcb[i].needtime, pcb[i].usedtime, pcb[i].state);
			     }
		 }
	
		 void Attemper()
		 {
		     do{
			         if ((pcb[0].needtime - pcb[0].usedtime)>pTime)   //�жϽ���ʣ�������ʱ���Ƿ����ʱ��Ƭ
				         {
				             pcb[0].usedtime += pTime;
				             pcb[0].priority--;
				             pcb[0].state = 'W';
				        }
			        else                       //����ɵĽ���
				         {
				             pcb[0].usedtime = pcb[0].needtime;
				             pcb[0].priority = -1;
				             pcb[0].state = 'F';
				         }
			         Print();
			
		} while (pcb[0].state != 'F');
		 }