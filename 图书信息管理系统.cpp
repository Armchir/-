#include<iostream>
#include<string>
#include<fstream>
#include<windows.h>
using namespace std;
//����ͼ����Ϣ�е�ʱ�䵥����
struct Time
{
  int day;
  int month;
  int year;
};
//����ͼ����Ϣ�Ľṹ�嵥����
typedef struct Book
{
  int record;//��¼��
  char book_name[40];//ͼ����
  char write[20];//����
  char classify[10];//�����
  char publishing_unit[50];//���浥λ
  Time publishing_time;//����ʱ��
  int  price;
  struct Book* next;
}*SP;
bool eixtrecord(SP head,int record);//�жϵ�¼���Ƿ����
void menu();//�˵�
void fMenu();//�޸�ѡ�����
void mainfrom();//������
void appData();//¼������
void modData();//�޸�����
void delData();//ɾ������
void findData();//��ѯ����
void showData();//��ʾ����
void saveData();//��������
void intsData();//��������
void panduanDay(Book* p);//�ж�����
void panhan(Book* p);//�жϺ���
void classfiyJ(Book* p);//�жϷ����
void recordJ(Book* p);//�жϵ�¼��
void paiData();//��Ϣ����
void outSystem();//�˳�ϵͳ
void printLine();//����
void loading();//���ݼ��ر�־
void loadData();//��������
//ȫ������
  SP head=NULL,rear=NULL;
  ofstream myfile;
  fstream readmyfile;
 //������
int main()
{
 system("color E4");//���ý�����ɫ
 loading();//���ú����������ݣ�����ҳ��
 loadData();//����һ�α�������ݶ���
 mainfrom();//������ 	
 return 0;
}
//�˵�
void menu()
{
 system("CLS");
 cout<<"\n\n\n\n\n\n\n\n\n";
cout<<"                                     ������������������������������������������\n";
 cout<<"                                     ��      ��ӭ����ͼ����Ϣ����ϵͳ        ��\n";
 cout<<"                                     ��              1��Ϣ¼��               ��\n";
 cout<<"                                     ��              2��Ϣ����               ��\n";
 cout<<"                                     ��              3��Ϣ���               ��\n";
 cout<<"                                     ��              4��Ϣ��ѯ               ��\n";
 cout<<"                                     ��              5��Ϣ�޸�               ��\n";
 cout<<"                                     ��              6��Ϣɾ��               ��\n";
 cout<<"                                     ��              0�˳�ϵͳ               ��\n";
 cout<<"                                     ������������������������������������������"<<"         �����ˣ��װ�ΰ������\n";
 cout<<"                                           ����(0-6)��ѡ������Ҫ�Ĺ���:";
} 
void mainfrom()
{ 
  system("CLS");//����
  char con;//���ƽ�����صĹ���
  menu();//�˵�
  cin>>con;
  cin.clear();rewind(stdin);//��ջ�����
  switch(con)//���أ�������ع���
  {
  case '1':appData();break;
  case '2':saveData();break;
  case '3':showData();system("PAUSE");break;
  case '4':findData();system("PAUSE");break;
  case '5':modData();break;
  case '6':delData();system("PAUSE");break;
  case '0':outSystem();break;
  default:cout<<"�������ڹ涨��Χ�ڵġ�\n";system("PAUSE");system("CLS");menu();cout<<endl;cout<<"���������룺";mainfrom();
  }
  mainfrom();//������
}
//��Ϣ¼��
void appData()
{  system("CLS");//����
   SP book;
   string con="y";//����ѭ���Ƿ����
   cout<<"                  ����ͼ����Ϣ\n"; 
 do//����
 {
	book=new Book;
    cout<<"��¼��(4λ)��";
	recordJ(book);//�жϵ�¼�ŵĸ�ʽ�Ƿ���ȷ
	if(eixtrecord(head,book->record ))//�жϵ�¼���Ƿ����
	{
     cout<<"�õ�¼���Ѵ��ڡ�\n";
	}
    else  
	{   
		   cout<<"ͼ����:";cin>>book->book_name; //������Ϣ
		   cout<<"����:";
		   panhan(book);//�ж������Ƿ�Ϊ����
           cout<<"����š�A-Z��:";
           classfiyJ(book);//�жϵ�¼�ŵĸ�ʽ
     	   cout<<"���浥λ:";cin>>book->publishing_unit;//�������Ϣ
           cout<<"�۸�:";cin>>book->price;rewind(stdin);//�������Ϣ
           cout<<"����ʱ��:\n";panduanDay(book);//�ж�����
      	   book->next=NULL;//��ָ�븳��
	    if(head)//head��Ϊ��
		{
	      rear->next=book;//���������Ϣ����
	      rear=book;
		}
   	    else//headΪ��ʱ
		{
	      head=book;
	      rear=book;
		}
	
	    cout<<"�Ƿ�Ҫ��������(Y/y) ������������ز˵�:";
	    cin>>con;
        cin.clear();rewind(stdin);
	}

 }while(con=="y"||con=="Y");
}
//��Ϣ���
void showData()
{
	 system("CLS");
     SP p;
     p=head;
	 if(p)//�ж��Ƿ������ݣ�����ִ��
	 {
	     cout<<"              ����ͼ����Ϣ\n";
      while(p)//
	  {
        cout<<"��¼��:       ";cout<<p->record<<"          \n";       
	    cout<<"ͼ����:       ";cout<<p->book_name<<"       \n";     
    	cout<<"����:         ";cout<<p->write<<"           \n";
    	cout<<"�����(A-Z):";cout<<p->classify<<"        \n"; 
    	cout<<"���浥λ:     ";cout<<p->publishing_unit<<"  \n";
		cout<<"ͼ��۸�:     ";cout<<p->price<<"  \n";
	    cout<<"����ʱ��:     ";cout<<p->publishing_time.year
			<<"��"<<p->publishing_time.month<<"��"
			<<p->publishing_time.day<<"��"<<" \n";
     	cout<<endl;
     	cout<<"ͼ����Ϣ\n";
     	p=p->next;//ָ����һ��
	  }
	 }
	 system("PUASE");
}
//��Ϣ����
void saveData()
{
    myfile.open("book.dat",ios::out|ios::binary);
	if(!myfile)
	{
		cout<<"�ļ���ʧ�ܣ�"<<endl;
		system("pause");
		exit(1);//�������˳�
	}
	SP p=head;
	while(p) 
	{
		myfile.write((char*)p,sizeof(Book)-4);
		cout<<"����ɹ�"<<endl;
		printLine();//����
		system("pause");
		p=p->next;
	}
	myfile.close();//�ر��ļ�
}

//��Ϣ��ѯ
void findData()
{
  system("CLS");//����
  SP p;
  char book_name[50];//�����ַ����飬����ͼ����
  char write[10];//�����ַ����飬����ͼ����
  char con='y';//����Ҫ��ѯ��ѡ��
  p=head;//Ϊ����������׼��
  cout<<"���ǰ���¼�Ż���ͼ�������ǰ����(1.���ߣ�2.ͼ����)��";cin>>con;cin.clear();rewind(stdin);//��ջ�����
  if(con=='1')
   {
    cout<<"��Ҫ��ѯ�������ǣ�";
	cin>>write;
	printLine();//����
    do
	{
		while((p!=NULL)&&(strcmp(p->write,write)!=0))//ѯ�ҽڵ�
		{
		  p=p->next; 
		}
		if(!p)//���pΪNULLʱ
		{
		  cout<<"����Ϣ�����ڣ�"<<endl;
		}
	   else	if(strcmp(p->write,write)==0)
		{
		    cout<<"��¼��:       ";cout<<p->record<<"          \n";
			cout<<"ͼ����:       ";cout<<p->book_name<<"       \n";   
    		cout<<"����:         ";cout<<p->write<<"           \n";
    		cout<<"�����(A-Z):";cout<<p->classify<<"        \n";
    		cout<<"���浥λ:     ";cout<<p->publishing_unit<<"  \n";
			cout<<"����۸�    ";cout<<p->price<<"\n";
			cout<<"����ʱ��:     ";cout<<p->publishing_time.year<<"��"
				<<p->publishing_time.month<<"��"
				<<p->publishing_time.day<<"��"<<" \n";
			cout<<endl;
			p=p->next;
		}
	}while(p!=NULL);
  }
   if(con=='2')
   {
    cout<<"��Ҫ��ѯ��ͼ�����ǣ�";
	cin>>book_name;
	while((p!=NULL)&&strcmp(p->book_name,book_name)!=0)//Ѱ�ҽڵ�
	{
	  p=p->next; 
	}
	if(!p)//���pΪ��
	{
	  cout<<"����Ϣ�����ڣ�"<<endl;
	}
   else  if(strcmp(p->book_name,book_name)==0)
	{
    	cout<<"��¼��:       ";cout<<p->record<<"          \n";
	    cout<<"ͼ����:       ";cout<<p->book_name<<"       \n";
    	cout<<"����:         ";cout<<p->write<<"           \n";
    	cout<<"�����(A-Z):";cout<<p->classify<<"        \n";
    	cout<<"���浥λ:     ";cout<<p->publishing_unit<<"  \n";
		cout<<"����۸�    ";cout<<p->price<<"\n";
	    cout<<"����ʱ��:     ";cout<<p->publishing_time.year<<"��"
			<<p->publishing_time.month<<"��"
			<<p->publishing_time.day<<"��"<<" \n";
		cout<<endl;
	}
   }
}
//��Ϣ�޸�
void modData()
{
  system("CLS");//����
  SP p;
  int record;//��������
  p=new Book;//Ϊp�������ڴ�ռ�
  p=head;//Ϊ����������׼��
  cout<<"����Ҫ�޸�ͼ����Ϣ�ĵ�¼��:";
  cin>>record;
  cin.clear();rewind(stdin);//��ջ�����
  while((p!=NULL)&&(p->record!=record))//Ѱ�ҽڵ�
		{
		  p=p->next; 
		}
		if(!p)//���pΪNULL
		{
		  cout<<"����Ϣ�����ڣ�"<<endl;system("PUASE");
		}
  else 
  {
   char con1,con2;//���ƽ���
   do
   {
   fMenu();//�β˵�
   cin>>con1;
   rewind(stdin);//��ջ�����
     switch(con1)//���أ�����ѡ��
	 {
      case 'A':cout<<"ͼ����:";cin>>p->book_name;
		       cout<<" *******�޸ĺ�\n";
		       cout<<"ͼ����:";cout<<p->book_name;cout<<endl;system("PAUSE");break;
      case 'B':cout<<"����ţ�A-Z����";cin>>p->classify;rewind(stdin);
		       cout<<" *******�޸ĺ�\n";
		       cout<<"����ţ�A-Z����";cout<<p->classify;cout<<endl;system("PAUSE");break;
      case 'C':cout<<"����ʱ��:"; cout<<"�꣺";cin>>p->publishing_time.year;cout<<"�£�";cin>>p->publishing_time.month;cout<<"�գ�";cin>>p->publishing_time.day;rewind(stdin);
		       cout<<" *******�޸ĺ�\n";
		       cout<<"����ʱ��:"; cout<<p->publishing_time.year<<"��"<<p->publishing_time.month<<"��"<<p->publishing_time.day<<"��";cout<<endl;system("PAUSE");break;
      case 'D':cout<<"���浥λ:"; cin>>p->publishing_unit ;
		       cout<<" *******�޸ĺ�\n";
		       cout<<"���浥λ:"; cout<<p->publishing_unit ;cout<<endl; system("PAUSE");break;
      case 'E':cout<<"����:"; cin>>p->write;
	           cout<<" *******�޸ĺ�\n";
               cout<<"����:"; cout<<p->write ;cout<<endl;system("PAUSE");break;
	  case 'F':cout<<"����۸�";cin>>p->price;
		       cout<<" *******�޸ĺ�\n";
               cout<<"���浥λ:"; cout<<p->price;cout<<endl;system("PAUSE");break;
      default :cout<<" �����뷶Χ�ڵ�ѡ�\n";
	 }
	 cout<<" �Ƿ���Ҫ�޸ģ�Y/y�� �� ����������ز˵�:"; 
     cin>>con2;
	 rewind(stdin);
   }while(con2=='Y'||con2=='y');
  }
}
//��Ϣɾ��
void delData()
{
  system("CLS");
  SP p;//qΪ�м����
  int record;
  cout<<"������Ҫɾ���ĵ�¼�ţ�";
  cin>>record;cin.clear();rewind(stdin);
  p=head;
  if(p!=NULL)//���������Ϣ
  {
  while(record!=p->record&&p->next!=NULL)//Ѱ�ҽڵ�
  {
    rear=p;//����ϸ��ڵ�
	p=p->next;//ָ���¸��ڵ�
  }
  if(record==p->record)
  {  
	  rear->next=p->next;//���ϸ��ڵ������¸��ڵ�
	  cout<<"<--------����Ϣ��ɾ��--------->\n";
	  printLine();
	  cout<<"��ɾ������Ϣ���£�\n";

    	cout<<"��¼��:       ";cout<<p->record<<"          \n";
	    cout<<"ͼ����:       ";cout<<p->book_name<<"       \n";
    	cout<<"����:         ";cout<<p->write<<"           \n";
    	cout<<"�����(A-Z):";cout<<p->classify<<"        \n";
    	cout<<"���浥λ:     ";cout<<p->publishing_unit<<"  \n";
		cout<<"����۸�    ";cout<<p->price<<"  \n";
	    cout<<"����ʱ��:     ";cout<<p->publishing_time.year<<"��"
			<<p->publishing_time.month<<"��"
			<<p->publishing_time.day<<"��"<<" \n";

     	cout<<endl;
	 
  } 
   else if(record!=p->record)
   {  
     cout<<"��Ϣ�����ڣ�"<<endl;
   }
   if(p==head&&record==p->record)//���ɾ�����ǵ�һ���ڵ�
	  {  
	    head=head->next;//���ڶ����ڵ��ͷ�ڵ�
      cout<<"<--------����Ϣ��ɾ��--------->\n";
	  printLine();
	    cout<<"��ɾ������Ϣ���£�\n";
    	cout<<"��¼��:       ";cout<<p->record<<"          \n";
	    cout<<"ͼ����:       ";cout<<p->book_name<<"       \n";
    	cout<<"����:         ";cout<<p->write<<"           \n";
    	cout<<"����ţ�A-Z��:";cout<<p->classify<<"        \n";
    	cout<<"���浥λ:     ";cout<<p->publishing_unit<<"  \n";
        cout<<"����۸�    ";cout<<p->price<<"  \n";
	    cout<<"����ʱ��:     ";cout<<p->publishing_time.year<<"��"
			<<p->publishing_time.month<<"��"
			<<p->publishing_time.day<<"��"<<" \n";
     	cout<<endl;
	  }
   else cout<<"����Ϣ�����ڣ�"<<endl;
  }
  else cout<<"�㻹δ¼����Ϣ��"<<endl;	 
}
//�˳�ϵͳ
void outSystem()
{
  system("CLS");
  cout<<"<---------��лʹ�ã�--------->\n";
  exit(0);//�����˳�
}
void printLine()//����
{
	cout<<"--------------------------------\n";
}
bool eixtrecord(SP head,int record)//�жϵ�¼���Ƿ��Ѿ�����
{   
	system("CLS");
	SP p=head;
		while(p)
		{  
			if((p->record==record))
			{
				return true;//����ture
				break;//����ѭ��
			}
			p=p->next;//ָ���¸��ڵ�
		} 
	return false;//����false
}
void fMenu()//�β˵�
{
 system("CLS");
 cout<<"******************ͼ���޸�******************\n";
 
 cout<<"    A   �޸�ͼ����  \n";
 cout<<"    B   �޸ķ����  \n";
 cout<<"    C   �޸ĳ���ʱ��\n";
 cout<<"    D   �޸ĳ��浥λ\n";
 cout<<"    E   �޸�������  \n";
 cout<<"    F   �޸ļ۸�    \n";
 cout<<"  �����������޸ĵ���Ϣ:";
}
void loading()
{
      int i;
	  for(i=0;i<10;i++)//ѭ�����
	  {
	   cout<<"*****************************************************loading********************************************************\n";
	   cout<<"                                                       "<<i<<"0%";
	   Sleep(100);//ͣ0.01��
       system("cls");
	  }
}
void intsData()//��Ϣ����
{
 system("CLS");//����
 SP p;
 SP p1;//����ṹ�����
 p1=new Book;//�����ڴ�ռ�
 cout<<"@�������ݣ�"<<endl;
 cout<<"��¼�ţ�";cin>>p1->record;cin.clear();rewind(stdin);
 cout<<"ͼ������";cin>>p1->book_name;
 cout<<"���ߣ�";cin>>p1->write;
 cout<<"����ţ�A-Z����";cin>>p1->classify;
 cout<<"���浥λ��";cin>>p1->publishing_unit;
 cout<<"����۸�";cin>>p1->price;
 cout<<"����ʱ�䣺";
 cout<<"�꣺";cin>>p1->publishing_time.year;cin.clear();rewind(stdin);
 cout<<"\n�£�";cin>>p1->publishing_time.month;cin.clear();rewind(stdin);
 cout<<"\n�գ�";cin>>p1->publishing_time.day;cin.clear();rewind(stdin);
 p=head;//Ϊ����������׼��
  if(!eixtrecord(p,p1->record))//�жϵ�¼���Ƿ����
 {
 if(head==NULL)
 {
    head=p1;
    p1->next=NULL;
 }
 else
 {
     while(p1->record>p->record&&p->next!=NULL)//�жϵ�¼�ŵĴ�С
	 {
         rear=p;//����ϸ��ڵ�
         p=p->next;//ָ���ϸ��ڵ�
	 }
     if(p1->record<=p->record)
	 {
        rear->next=p1;//����һ���ڵ�ָ��p1
        p1->next=p;//��p1ָ������Ƚϵ�p
	 }
     else//�����Ϊ����
	 {
        p->next=p1;//�����������β
        p1->next=NULL;
	 } 
 }
 }
 else cout<<"��Ϣ�Ѿ������ˣ�"<<endl;
}
void paiData()//������ð������
{
  Book* p;//����ṹ�����
  Book* q;
 
  for(p=head;p!=NULL;p=p->next)//ð������
	  for(q=p->next;q!=NULL;q=q->next)
	  {   
	      if(p->record>q->record)//�����ڵ�����
		  { 
              Book* p2;
			  p2=new Book;
			  p2->record=p->record;
			  strcpy( p2->book_name,p->book_name);//ͨ��strcpy���������������ݸ���
              strcpy( p2->write ,p->write);
			  strcpy( p2->classify,p->classify);
              strcpy( p2->publishing_unit,p->publishing_unit);
			  p2->publishing_time.year=p->publishing_time.year;         
			  p2->publishing_time.month=p->publishing_time.month ;
			  p2->publishing_time.day=p->publishing_time.day;
		      p->record=q->record;
			  strcpy( p->book_name,q->book_name);
              strcpy( p->write ,q->write);
			  strcpy( p->classify,q->classify);
              strcpy( p->publishing_unit,q->publishing_unit);
			  p->publishing_time.year=q->publishing_time.year;         
			  p->publishing_time.month=q->publishing_time.month; 
			  p->publishing_time.day=q->publishing_time.day;
			  q->record=p2->record;
			  strcpy( q->book_name,p2->book_name);
              strcpy( q->write ,p2->write);
			  strcpy( q->classify,p2->classify);
              strcpy( q->publishing_unit,p2->publishing_unit);
			  q->publishing_time.year=p2->publishing_time.year;         
			  q->publishing_time.month=p2->publishing_time.month;
			  q->publishing_time.day=p2->publishing_time.day;
		  }
	  }
}
void panduanDay(Book* p)//�ж�����
{
 char m='2';//����ѭ��
 do
 {
   cout<<"�꣺";
   cin>>p->publishing_time.year;cin.clear();rewind(stdin);//�������ݲ���ջ�����
   if(p->publishing_time.year<1900||p->publishing_time.year>2021)
   {cout<<"�����1900-2021"<<endl; m='2';}
   else
   {
      do
	  {
	    cout<<"�£�";cin>>p->publishing_time.month;cin.clear();rewind(stdin);
		if(p->publishing_time.month<1||p->publishing_time.month>12)
		{
		   cout<<"�������������䣡�·�(1-12)"<<endl; m='3';
		}
		else
		{
		  do
		  {
		   cout<<"�գ�";cin>>p->publishing_time.day;cin.clear();rewind(stdin);
		   if(p->publishing_time.day>31||p->publishing_time.day<1)
		   {
		      cout<<"�������������䣡"<<endl; m='5';
		   }
		   else m='6';
		  }while(m=='5');
		  m='4';
		}
	  }while(m=='3');
	  m='0';
   }
 }while(m=='2');
}
//�ж������Ƿ�Ϊ����
void panhan(Book* p)//�����ж�
{
	int www;//�����жϣ��Ƿ��˳�ѭ��
	int d;
    do
	{
		www=0;
	    cin>>p->write;//���������з�
		d=getchar();//�ж����뻺�����Ƿ�Ϊ�գ�d��ȡ�����޶����ֵ
		if(d!=10)
		{
			www=1;
			cout<<"�����������";
			cout<<"�����������룺";
			cin.clear();//�����
			cin.sync();
		}
		else
		{
			int i=0,nlen=strlen(p->write);
			for(;i<nlen;i++)
			{
				if(p->write[i]>=0&&p->write[i]<=127)//�ж��Ƿ���ȫ���ַ�
				{
					www=1;
					cout<<"�����������";
					cout<<"�����������룺";
					cin.clear();//�����
					cin.sync();
					break;
				}
			}
		}
	}while(www);
}
void classfiyJ(Book* p)
{
	int n=0;
 	    do
		{  		 
	      cin>>p->classify;
    	  if(int a=p->classify[1])//����ڶ��������ݣ�����ʾ���󣬲�����
		  {
	         cout<<"�������������:";
		  }
	      else
		  {
		     if(p->classify[0]<'A'||p->classify[0]>'Z')
			 {
		        cout<<"��������������:";
			 }
		     else
			 {
		        n=1;
			 }
		  }
		}while(n!=1);
}
void recordJ(Book* p)//�жϵ�¼��
{  
	int n=0;
 	do
	{
		n=0;//��������ѭ������
		cin>>p->record;cin.clear();cin.sync();//�����¼�ţ���ջ�����
		if(p->record<1000||p->record>10000)//��������㣬�ͽ���
		{
		 cout<<"*��������������(4λ����):";n=2;	
		}
	}while(n==2);
}
void loadData()//��������
{
	SP p;
	readmyfile.open("book.dat",ios::in|ios::out|ios::app|ios::binary);//�Ѷ�д��ʽ���ļ�
   if(!readmyfile)
   {
      cout<<"���ļ�ʧ�ܣ�"<<endl;
      exit(1);//�������˳�
   }
     readmyfile.seekg(ios::beg);//�ļ�ָ��λ���ļ���ͷ
     while(!readmyfile.eof())//��û�г����ļ�βʱ��ִ��ѭ��
	{
	    p=new Book;//Ϊp��ֵ�µ��ڴ�ռ�
		if(readmyfile.read((char*)(p),sizeof(Book)-4))
		{
			p->next=NULL;
			if(head)//������ͷ�ڵ㲻Ϊ��ʱ
			{
				rear->next=p;//βָ����һ�ڵ�ָ��p
				rear=p;//����βָ��
			}
			else//������Ϊ��ʱ
			{
				head=p;//ͷָ��ָ��p
				rear=p;//βָ��ָ��tp
			}
		}
	 }
}
