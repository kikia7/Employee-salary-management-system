#include <iostream>
#include <string.h>
#include <iomanip>
#include <cstring>
#define MIND_LINE 15		//���־��д�ӡ������
#define MIND_SPACE 40		//���־��д�ӡ������
#define MAX_LINE   30		//����������ʾ����
using namespace std;
int Count=5;
struct Worker
{
	char name[20];
	char sex[20];
	char num[20];
    float salary;
};
Worker w[20]=
{ { "ZhangLi", "M", "2018100", 3000},
  {"Wangfang", "F", "2018101", 2500},
  {"zhaoqiang", "M","2018102", 5200},
  {"Xiaohong","F","2018103",3200},
  {"Zegui","M","2018104",4800}} ;
void setdata();
void PrintEnter(int Line);
void PrintSpace(int Space);
void WelcomeMenu();
void author(); 
void Menu();
void Back();
void Choose();
void Showdata1();
void change_salary (float a[],float b[]) ;      //����˰���Ӧ������
void sort(Worker,int n);                        //��Ա���������� 
void Showdata2(float a[],float b[]);
int main()
{
	//int Count=3;
	WelcomeMenu();
	author();
	Menu();
	Choose();
} 
void WelcomeMenu()
{
	PrintEnter(MIND_LINE);
	PrintSpace(MIND_SPACE);
    cout<<"��ӭ����Ա�����ʹ���ϵͳ��"<<endl;
	getchar(); 
}
void author()
{
	cout<<setw(40)<<"�����ˣ�"<<endl;
	cout<<setw(45)<<"����\t"<<"�༶\t"<<"ѧ��\t\t"<<"ʱ��\t"<<endl;
	cout<<setw(45)<<"��ٻٻ\t"<<"1806\t"<<"20181003057\t"<<"2018.12.28\t"<<endl;
	cout<<setw(45)<<"ʩ����\t"<<"1806\t"<<"20181003058\t"<<"2018.12.28\t"<<endl; 
	cout<<setw(45)<<"����Ө\t"<<"1806\t"<<"20181003059\t"<<"2018.12.28\t"<<endl;
	getchar(); 
}
void PrintEnter(int Line)
{
    for (int i = 0; i < Line; i++) cout<<endl;
}
void PrintSpace(int Space)
{
	for (int i = 0; i < Space; i++) cout<<" ";
}
void Menu()
{
	system("cls");
	PrintEnter(7);
	PrintSpace(30);
	cout << "**********************************************" << endl;
    cout << "                              ****    ��ӭʹ�ô�Ա�����ʹ���ϵͳ        ****" << endl;
    cout << "                              ****          1.�鿴��ǰԱ��              ****" << endl;
    cout << "                              ****          2.����µ�Ա��              ****" << endl;
    cout << "                              ****          3.�޸�Ա����Ϣ              ****" << endl;
    cout << "                              ****          4.ɾ��Ա����Ϣ              ****" << endl;
    cout << "                              ****          5.�����Ų�ѯԱ������        ****" << endl;
    cout << "                              ****          6.��������ѯԱ������        ****" << endl;
    cout << "                              ****          7.����������                ****" << endl;
    cout << "                              ****          8.�鿴��ʵ�����ʺ�ƽ������  ****" << endl;
    cout << "                              ****          9.�˳�ϵͳ                  ****" << endl;
    cout << "                              **********************************************" << endl;
}
void Back()
{
    cout << "��Enter���������˵�";
    getchar();
    Menu();
}
void Showdata1()
{
	int i=0;
    cout<<"-------------------------------------------------------------------------------\n";
    cout<<"                               *ְ��������Ϣ��*                               "<<endl;
    cout<<"-------------------------------------------------------------------------------\n";
    cout<<"   |�� ��|       |�Ա�|          |����|                |����|"<<endl;
    cout<<"-------------------------------------------------------------------------------\n";
    for(i=0;i<20;i++)
    cout<<setw(10)<<w[i].name<<setw(10)<<w[i].sex<<setw(20)<<w[i].num<<setw(20)<<w[i].salary<<endl;
    getchar();
}
void Showdata2(float a[],float b[])
{
	int i=0;
    cout<<"-------------------------------------------------------------------------------\n";
    cout<<"                               *ְ��������Ϣ��*                               "<<endl;
    cout<<"-------------------------------------------------------------------------------\n";
    cout<<"   |�� ��|       |�Ա�|          |����|                |����|"<<endl;
    cout<<"-------------------------------------------------------------------------------\n";
    for(i=0;i<20;i++)
    cout<<setw(10)<<w[i].name<<setw(10)<<w[i].sex<<setw(20)<<w[i].num<<setw(20)<<w[i].salary<<endl;
    getchar();
}
void add (float a[],float b[])                                    //����ͬ˰�ʼ���ʵ�����ʣ������� ��ʵ������ �� ƽ������ 
{
	float add=0;
    for(int i=0;i<Count;i++)
    {
        if(w[i].salary<1000)                           //����ͬ˰�ʼ���ʵ������
       {
            b[i] = 0 ;
            a[i] = w[i].salary ;
        }
        if( ( w[i].salary<4999) && ( w[i].salary>=1000) )
        {
            b[i] =  w[i].salary*0.05 ;
            a[i]=  w[i].salary - b[i] ;
        }
        if( w[i].salary>=5000)
        {
            b[i] =  w[i].salary*0.1 ;
            a[i] = w[i].salary- b[i] ;
        }
    }
    for(int i=0;i<Count;i++)
        add=add+a[i];
    cout<<"��ʵ������Ϊ��"<<add<<endl;
    cout<<"ƽ������Ϊ��"<<add/Count<<endl; 
}
void sort(Worker w[],int n)                   
{
	int i,j,t1;
	char t2[20],t3[20];
	char t4[20];
	for(i=0;i<n-1;i++)
	   for(j=0;j<n-1;j++)
	      if(w[j].salary>w[j+1].salary)
		  {
		  	t1=w[j].salary;
			strcpy(t2,w[j].name);
			strcpy(t3,w[j].num);
			strcpy(t4,w[j].sex);
		  	w[j].salary=w[j+1].salary;
			strcpy(w[j].name,w[j+1].name);
			strcpy(w[j].num,w[j+1].num);
			strcpy(w[j].sex,w[j+1].sex);
		  	w[j+1].salary=t1;
			strcpy(w[j+1].name,t2);
			strcpy(w[j+1].num,t3);
			strcpy(w[j+1].sex,t4);
		   } 
}
void Choose()
{

	int i,e;
	int h=1; 
	int Choose;
	char name1[10];
	char num1[10];
	char num2[10];
	char num3[10];
	float pay_out[20];
    float true_salary[20];
	while(h>0)
	{
		cout<<"����������鿴���������Ӧ�����֣�"; 
	    cin>>Choose;
	    switch(Choose)
	    {
		    case 1:
			    system("cls");                                  //�鿴��ǰ��Ϣ 
			    Showdata1();
			    Back();
			    break;
			    
		    case 2:                                               //���Ա����Ϣ 
		        system("cls");
		        i=0; 
		        while((w[i].name)[0]!='\0' && i<20)               //���б�յĵط�
		        {i++;}
	            if((w[i].name)[0]=='\0')                         //�ҵ��б�յĵط�
	            {
	            	cout<<"����������ӵ�Ա���������Ա𡢹��ź͹��ʣ�"<<endl;
	                cin>>name1;                                   //���Ա����Ϣ 
					cin>>w[i].sex;
				    cin>>num1;
				    cin>>w[i].salary;
					strcpy(w[i].name, name1);
					strcpy(w[i].num, num1);
				    cout<<"��ӳɹ���"<<endl;
				    Count++;
	                cout<<setw(10)<<w[i].name<<setw(10)<<w[i].sex<<setw(10)<<w[i].num<<setw(10)<<w[i].salary<<endl;
	            } 
	            else                                               // �������󶼲��ǿյģ�����Ա����
				cout<<"��Ա����"<<endl;
			    getchar();
                Back();
                break;       
				                        
			case 3:                                                    //�޸�Ա����Ϣ 
				system("cls");
				cout<<"������Ҫ�޸ĵ�Ա�����ţ�"<<endl;
				cin>> num2;
				for(i=0; i<20; i++)
					{					
				        if(strcmp(w[i].num, num2)==0)                   //����Ҫ�޸ĵ�Ա�� 
				        {
				        cout<<"�޸�Ա��  "<<endl;
					    cout<<setw(10)<<w[i].name<<setw(10)<<w[i].sex<<setw(20)<<w[i].num<<setw(20)<<w[i].salary<<endl;
					    cout<<"ȷ���޸��밴1,�������˵��밴�����"<<endl;                //ȷ���Ƿ��޸����� 
					    cin>> e;
					    if(e==1)                                  
				       	{
						cout<<"�����������µ��������Ա𡢹��š����ʣ�"<<endl;  //�޸���Ϣ 
						cin>>name1;
						cin>> w[i].sex;
						cin>>num1;
						cin>>w[i].salary;
						strcpy(w[i].name, name1);
			            strcpy(w[i].num, num1);
			            cout<<"�޸ĳɹ���"<<endl;
			            getchar();
			            Back();   
				       	}
				       	else Back(); 
						break;
						}
						if(i==19)                                      //���Ҳ�����Ӧ��Ա�� 
					    {
					    cout<<"���޴�Ա����"<<endl;
						getchar();
                        Back();
					    }
					}break;
					
			case 4:                                                  //ɾ��Ա����Ϣ 
				system("cls");
				cout<<"��������Ҫɾ����Ա�����ţ�"<<endl;
				cin>>num3;
				for(i=0; i<20; i++)
				{
				if(strcmp(w[i].num, num3)==0)                     //����Ҫɾ����Ա�� 
				{
				    cout<<"ɾ��Ա��  "<<endl;
					cout<<setw(10)<<w[i].name<<setw(10)<<w[i].sex<<setw(20)<<w[i].num<<setw(20)<<w[i].salary<<endl;
					cout<<"ȷ��ɾ���밴1,�������˵��밴�����"<<endl;              //ȷ���Ƿ�ɾ���� 
					cin>> e;
					if(e==1)                                  //ɾ����Ա�� 
					{
					memset(&w[i], 0, sizeof(w[i]));
					cout<<"ɾ���ɹ���"<<endl;
					getchar();
					Back();
					}
					else Back(); 
				    break;
				}
				if(i==19)                                        //���Ҳ�����Ӧ��Ա�� 
				{
				cout<<"���޴�Ա����"<<endl;
				getchar();
				Back();  
				}
				}break;
				    
			case 5:                                                   //��ְ���Ų�ѯԱ���Ĺ��� 
				{
			    system("cls");                                       
                int p=0 ;
                int i;
	            char number[20] ; 
                cout << "\n������Ҫ��ѯ��ְ����:" ;            
                cin>>number;
                for (i=0;i<Count;i++)                              
                {
					if((strncmp(number,w[i].num,20))==0)
                    {
					cout << "\n�ҵ���!\n" ;
                    cout<<number<<'\t'<<w[i].salary<<endl;
                    p=1;
                    getchar();
                    Back();
                    break; 
                    }
                }
                if(p==0)
                {
                cout << "\nû���������!\n" ;                     //���Ҳ�����Ӧ��Ա�� 
                getchar();Back();
                }
		        }break; 
		        
           case 6:                                                    //����������Ա���Ĺ��� 
				{
				system("cls");
				int p=0;
                int i;
                char find_name[20] ;
                cout << "\n������Ҫ��ѯ��ְ������:" ;
                cin>>find_name;
                for (i=0;i<Count;i++)
                {
					if((strncmp(find_name,w[i].name,20))==0)
                    {
					cout << "\n�ҵ���!\n" ;                     
                    cout<<find_name<<'\t'<<w[i].salary<<endl;
                    p=1;
                    getchar();
                    Back();
                    break;
                    }
                }
                if(p==0)
                {
				cout << "\nû�����Ա��!\n" ;                   //���Ҳ�����Ӧ��Ա�� 
                getchar();
                Back();
				}
			    }break;
			    
            case 7:                                                  //��Ա������������ ����չʾԱ����Ϣ 
            	system("cls");    
                sort(w,Count);
                Showdata2(true_salary,pay_out);
                getchar();
                Back();
                break; 
				
			case 8:                                                  //�鿴��ǰ����ʵ�����ʺ�ƽ������
			    system("cls");
				add(true_salary,pay_out);
			    getchar();
			    Back();
 			    break;
 			       
 		    case 9:
			    cout<<"�ѳɹ��˳�"<<endl;
				h=0;break;
				   
			default:
			    cout<<"�������ֲ���0~9��"<<endl;                                                //�˳�ϵͳ 
			    getchar();
			    Back();
		
 			    break;
       }
	}
} 
		

        
	


