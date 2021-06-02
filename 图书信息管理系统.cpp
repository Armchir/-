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
typedef struct Book//ͼ����Ϣ�ṹ��
{
  char ISBN[14];//ISBN
  char book_name[40];//ͼ����
  char write[20];//����
  char classify[10];//�����
  char publishing_unit[50];//���浥λ
  Time publishing_time;//����ʱ��
  int  price;//�۸�
  int stock;//�����
  int extant;//�ִ���
  struct Book* next;//������βָ��
}*SP;
typedef struct Man//��������Ϣ�ṹ��
{
	char name[20];//����������
	int book_num;//��������֤��
	char book_name[40];//����ͼ����
	char write[20];//����
	Time back_time;//�黹ʱ��
	struct Man* next;//������βָ��
}*M;
bool eixtrecord(SP head,char ISBN[14]);//�жϵ�¼���Ƿ����
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
void addExtant();//�黹ͼ��
void delExtant();//����ͼ��
void panduanDay(Book* p);//�ж�����
void panduanDay(Man* m);//�ж�����
void panhan(char write[]);//�жϺ���
void classfiyJ(Book* p);//�жϷ����
void recordJ(Book* p);//�жϵ�¼��
int panduanInt();//����Ϊ����
void paiData();//��Ϣ����
void outSystem();//�˳�ϵͳ
void printLine();//����
void loading();//���ݼ��ر�־
void loadData();//��������
//ȫ������
SP head = NULL, rear = NULL;
M headM = NULL, rearM = NULL;
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
 system("cls");
 cout<<"\n\n\n\n\n\n\n\n\n";
 cout<<"                                     ������������������������������������������\n";
 cout<<"                                     ��      ��ӭ����ͼ����Ϣ����ϵͳ        ��\n";
 cout<<"                                     ��              1ͼ��¼��               ��\n";
 cout<<"                                     ��              2��Ϣ����               ��\n";
 cout<<"                                     ��              3ͼ�����               ��\n";
 cout<<"                                     ��              4ͼ���ѯ               ��\n";
 cout<<"                                     ��              5ͼ���޸�               ��\n";
 cout<<"                                     ��              6ͼ��ɾ��               ��\n";
 cout<<"                                     ��              7����ͼ��               ��\n";
 cout<<"                                     ��              8�黹ͼ��               ��\n";
 cout<<"                                     ��              0�˳�ϵͳ               ��\n";
 cout<<"                                     ������������������������������������������"<<"         �����ˣ��װ�ΰ������\n";
 cout<<"                                           ����(0-8)��ѡ������Ҫ�Ĺ���:";
} 
void mainfrom()
{ 
  system("cls");//����
  char con;//���ƽ�����صĹ���
  menu();//�˵�
  cin>>con;
  cin.clear();rewind(stdin);//��ջ�����
  switch(con)//���أ�������ع���
  {
  case '1':appData();break;
  case '2':saveData();break;
  case '3':showData();system("pause");break;
  case '4':findData();system("pause");break;
  case '5':modData();break;
  case '6':delData();system("pause");break;
  case '7':delExtant(); break;
  case '8':addExtant(); system("pause"); break;
  case '0':outSystem();break;
  default:cout<<"�������ڹ涨��Χ�ڵġ�\n";system("pause");system("cls");menu();cout<<endl;cout<<"���������룺";mainfrom();
  }
  mainfrom();//������
}
//��Ϣ¼��
void appData()
{
	system("CLS");//����
	SP book;
	string con="y";//����ѭ���Ƿ����
	cout<<"                  ����ͼ����Ϣ\n"; 
	do//����
	{
		book=new Book;
		cout<<"ISBN(13λ)��";
		recordJ(book);//�ж�ISBN�ĸ�ʽ�Ƿ���ȷ
		if(eixtrecord(head,book->ISBN))//�ж�ISBN�Ƿ����
		{
			cout<<"��ͼ���Ѵ��ڣ����������޸Ŀ������\n";
			Sleep(2000);
			modData();
		}
		else
		{
			cout << "ISBN��" << book->ISBN << endl;
			cout << "ͼ����:"; cin >> book->book_name; //������Ϣ
			cout << "����:";
			panhan(book->write);//�ж������Ƿ�Ϊ����
			cout << "����š�A-Z��:";
			classfiyJ(book);//�жϷ���ŵĸ�ʽ
			cout << "���浥λ:"; cin >> book->publishing_unit;//�������Ϣ
			cout << "�۸�:"; book->price = panduanInt(); //�ж��Ƿ�Ϊ����
			cout << "����ʱ��:\n"; panduanDay(book);//�ж�����
			cout << "�����(�����ٱ���):"; book->stock = panduanInt();//����Ŀ����(�����ٱ���)
			cout << "�ִ���:"; book->extant = panduanInt();//������ִ���
			book->next = NULL;//��ָ�븳��
			if (head)//head��Ϊ��
			{
				rear->next = book;//���������Ϣ����
				rear = book;
			}
			else//headΪ��ʱ
			{
				head = book;
				rear = book;
			}
		}
		cout << "�Ƿ�Ҫ����¼��ͼ��(Y/y) ������������ز˵�:";
		cin >> con;
		cin.clear(); rewind(stdin);
	}while(con=="y"||con=="Y");
}
//��Ϣ���
void showData()
{
	system("CLS");
	SP p;
	p=head;
	if (p)//�ж��Ƿ������ݣ�����ִ��
	{
		cout << "              ����ͼ����Ϣ\n";
		while (p)
		{
			cout << "ISBN:       "; cout << p->ISBN << "          \n";
			cout << "ͼ����:       "; cout << p->book_name << "       \n";
			cout << "����:         "; cout << p->write << "           \n";
			cout << "�����(A-Z):"; cout << p->classify << "        \n";
			cout << "���浥λ:     "; cout << p->publishing_unit << "  \n";
			cout << "ͼ��۸�:     "; cout << p->price << "  \n";
			cout << "����ʱ��:     "; cout << p->publishing_time.year
				<< "��" << p->publishing_time.month << "��"
				<< p->publishing_time.day << "��" << " \n";
			cout << "�������" << p->stock << endl;
			cout << "�ִ�����" << p->extant << endl;
			cout << endl;
			cout << "ͼ����Ϣ\n";
			p = p->next;//ָ����һ��
		}
	}
}
//��Ϣ����
void saveData()
{
	bool key = false;
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
		key = true;
		p=p->next;
	}
	if (key == true)
	{
		cout << "����ɹ�" << endl;
		printLine();//����
		system("pause");
	}
	myfile.close();//�ر��ļ�
}
//��Ϣ��ѯ
void findData()
{
	system("CLS");//����
	SP p;
	char book_name[50];//�����ַ����飬����ͼ����
	char write[10];//�����ַ����飬��������
	char con = 'y';//����Ҫ��ѯ��ѡ��
	p = head;//Ϊ����������׼��
	cout << "��������ͨ�������������һ���ͨ��ͼ��������(1.���ߣ�2.ͼ����)��"; cin >> con; cin.clear(); rewind(stdin);//��ջ�����
	if (con == '1')
	{
		cout << "��Ҫ��ѯ�������ǣ�";
		cin >> write;
		printLine();//����
		while ((p != NULL) && (strcmp(p->write, write) != 0))//Ѱ�ҽڵ�
		{
			p = p->next;
		}
		if (!p)
		{
			cout << "����Ϣ�����ڣ�" << endl;
		}
		else if (strcmp(p->write, write) == 0)
		{
			cout << "��¼��:       "; cout << p->ISBN << "          \n";
			cout << "ͼ����:       "; cout << p->book_name << "       \n";
			cout << "����:         "; cout << p->write << "           \n";
			cout << "�����(A-Z):"; cout << p->classify << "        \n";
			cout << "���浥λ:     "; cout << p->publishing_unit << "  \n";
			cout << "����۸�    "; cout << p->price << "\n";
			cout << "����ʱ��:     "; cout << p->publishing_time.year << "��"
				<< p->publishing_time.month << "��"
				<< p->publishing_time.day << "��" << " \n";
			cout << "�������" << p->stock << endl;
			cout << "�ִ�����" << p->extant << endl;
			cout << endl;
			p = p->next;
		}
	}
	if (con == '2')
	{
		cout << "��Ҫ��ѯ��ͼ�����ǣ�";
		cin >> book_name;
		while ((p != NULL) && strcmp(p->book_name, book_name) != 0)//Ѱ�ҽڵ�
		{
			p = p->next;
		}
		if (!p)//���pΪ��
		{
			cout << "����Ϣ�����ڣ�" << endl;
		}
		else if (strcmp(p->book_name, book_name) == 0)
		{
			cout << "ISBN:       "; cout << p->ISBN << "          \n";
			cout << "ͼ����:       "; cout << p->book_name << "       \n";
			cout << "����:         "; cout << p->write << "           \n";
			cout << "�����(A-Z):"; cout << p->classify << "        \n";
			cout << "���浥λ:     "; cout << p->publishing_unit << "  \n";
			cout << "����۸�    "; cout << p->price << "\n";
			cout << "����ʱ��:     "; cout << p->publishing_time.year << "��"
				<< p->publishing_time.month << "��"
				<< p->publishing_time.day << "��" << " \n";
			cout << "�������" << p->stock << endl;
			cout << "�ִ�����" << p->extant << endl;
			cout << endl;
		}
	}
}
//��Ϣ�޸�
void modData()
{
	system("CLS");//����
	SP p;
	char ISBN[14];//���Ҫ�޸ĵ�ISBN
	char book_name[40];//���Ҫ�޸ĵ�ͼ����
	char con = 'y';//����Ҫ��ѯ��ѡ��
	p=new Book;//Ϊp�������ڴ�ռ�
	p=head;//Ϊ����������׼��
	cout << "��������ͨ��ISBN���һ���ͨ��ͼ��������(1.ISBN��2.ͼ����)��";
	cin >> con;
	if (con == '1')
	{
		cout << "������ISBN:";
		cin >> ISBN;
		cin.clear(); rewind(stdin);//��ջ�����
		while ((p != NULL) && ((strcmp(p->ISBN, ISBN))))//Ѱ�ҽڵ�
		{
			p = p->next;
		}
	}
	if (con == '2')
	{
		cout << "������ͼ����:";
		cin >> book_name;
		cin.clear(); rewind(stdin);//��ջ�����
		while ((p != NULL) && ((strcmp(p->book_name, book_name))))//Ѱ�ҽڵ�
		{
			p = p->next;
		}
	}
	if (!p)//���pΪNULL
	{
		cout << "����Ϣ�����ڣ�" << endl; system("PUASE");
	}
	else
	{
		char con1, con2;//���ƽ���
		int stock;//���������
		do
		{
			fMenu();//�β˵�
			cin >> con1; rewind(stdin);//��ջ�����
			switch (con1)//���أ�����ѡ��
			{
			case 'A':cout << "ͼ����:"; cin >> p->book_name;
				cout << " *******�޸ĺ�\n";
				cout << "ͼ����:"; cout << p->book_name; cout << endl; system("PAUSE"); break;
			case 'B':cout << "����ţ�A-Z����"; cin >> p->classify; rewind(stdin);
				cout << " *******�޸ĺ�\n";
				cout << "����ţ�A-Z����"; cout << p->classify; cout << endl; system("PAUSE"); break;
			case 'C':cout << "����ʱ��:"; cout << "�꣺"; cin >> p->publishing_time.year; cout << "�£�"; cin >> p->publishing_time.month; cout << "�գ�"; cin >> p->publishing_time.day; rewind(stdin);
				cout << " *******�޸ĺ�\n";
				cout << "����ʱ��:"; cout << p->publishing_time.year << "��" << p->publishing_time.month << "��" << p->publishing_time.day << "��"; cout << endl; system("PAUSE"); break;
			case 'D':cout << "���浥λ:"; cin >> p->publishing_unit;
				cout << " *******�޸ĺ�\n";
				cout << "���浥λ:"; cout << p->publishing_unit; cout << endl; system("PAUSE"); break;
			case 'E':cout << "����:"; cin >> p->write;
				cout << " *******�޸ĺ�\n";
				cout << "����:"; cout << p->write; cout << endl; system("PAUSE"); break;
			case 'F':cout << "����۸�"; cin >> p->price;
				cout << " *******�޸ĺ�\n";
				cout << "����۸�:"; cout << p->price; cout << endl; system("PAUSE"); break;
			case 'G':cout << "��Ҫ���ӵĿ������"; cin >> stock; p->stock = p->stock + stock;
				cout << " *******�޸ĺ�\n";
				cout << "�������"; cout << p->stock; cout << endl; system("PAUSE"); break;
			default:cout << " �����뷶Χ�ڵ�ѡ�\n";
			}
			cout << " �Ƿ���Ҫ�޸ģ�Y/y�� �� ����������ز˵�:";
			cin >> con2;
			rewind(stdin);
		} while (con2 == 'Y' || con2 == 'y');
	}
}
//��Ϣɾ��
void delData()
{
	system("CLS");
	SP p;//qΪ�м����
	char ISBN[14];
	cout << "������Ҫɾ��ͼ���ISBN��";
	cin >> ISBN; cin.clear(); rewind(stdin);
	p = head;//Ϊ���ʵ�������׼��
	if (p != NULL)//���������Ϣ
	{
		if (head == p && strcmp(ISBN, p->ISBN) == 0)//���ɾ�����ǵ�һ���ڵ�
		{
			head = head->next;//���ڶ����ڵ��ͷ�ڵ�
			cout << "<--------����Ϣ��ɾ��--------->\n";
			printLine();
			cout << "��ɾ������Ϣ���£�\n";
			cout << "ISBN:       "; cout << p->ISBN << "          \n";
			cout << "ͼ����:       "; cout << p->book_name << "       \n";
			cout << "����:         "; cout << p->write << "           \n";
			cout << "����ţ�A-Z��:"; cout << p->classify << "        \n";
			cout << "���浥λ:     "; cout << p->publishing_unit << "  \n";
			cout << "����۸�    "; cout << p->price << "  \n";
			cout << "����ʱ��:     "; cout << p->publishing_time.year << "��"
				<< p->publishing_time.month << "��"
				<< p->publishing_time.day << "��" << " \n";
			cout << "�������" << p->stock << endl;
			cout << "�ִ�����" << p->extant << endl;
			cout << endl;
		}
		else
		{
			while ((strcmp(ISBN, p->ISBN) != 0) && (p->next != NULL))//Ѱ�ҽڵ�
			{
				rear = p;//����ϸ��ڵ�
				p = p->next;//ָ���¸��ڵ�
			}
			if (strcmp(ISBN, p->ISBN) == 0)
			{
				rear->next = p->next;//���ϸ��ڵ������¸��ڵ�
				cout << "<--------����Ϣ��ɾ��--------->\n";
				printLine();
				cout << "��ɾ������Ϣ���£�\n";

				cout << "ISBN:       "; cout << p->ISBN << "          \n";
				cout << "ͼ����:       "; cout << p->book_name << "       \n";
				cout << "����:         "; cout << p->write << "           \n";
				cout << "�����(A-Z):"; cout << p->classify << "        \n";
				cout << "���浥λ:     "; cout << p->publishing_unit << "  \n";
				cout << "����۸�    "; cout << p->price << "  \n";
				cout << "����ʱ��:     "; cout << p->publishing_time.year << "��"
					<< p->publishing_time.month << "��"
					<< p->publishing_time.day << "��" << " \n";
				cout << "�������" << p->stock << endl;
				cout << "�ִ�����" << p->extant << endl;
				cout << endl;

			}
			else if (strcmp(ISBN, p->ISBN) != 0)
			{
				cout << "��Ϣ�����ڣ�" << endl;
			}
		}
	}
	else cout << "�㻹δ¼�����Ϣ��" << endl;
}
//����ͼ��
void delExtant()
{
	system("CLS");//����
	SP p;
	char book_name[50];//�����ַ����飬����ͼ����
	string con = "y";//����ѭ���Ƿ����
	do//����
	{
		p = head;//Ϊ����������׼��
		bool find = false;//�ж��Ƿ��ҵ�
		cout << "��Ҫ���ĵ�ͼ�����ǣ�";
		cin >> book_name;
		printLine();//����
		while ((p != NULL) && strcmp(p->book_name, book_name) != 0)//Ѱ�ҽڵ�
		{
			p = p->next;
		}
		if (!p)//���pΪ��
		{
			cout << "����Ϣ�����ڣ�" << endl; find = false;
		}
		else  if (strcmp(p->book_name, book_name) == 0)
		{
			cout << "ISBN:       "; cout << p->ISBN << "          \n";
			cout << "ͼ����:       "; cout << p->book_name << "       \n";
			cout << "����:         "; cout << p->write << "           \n";
			cout << "�����(A-Z):"; cout << p->classify << "        \n";
			cout << "���浥λ:     "; cout << p->publishing_unit << "  \n";
			cout << "����۸�    "; cout << p->price << "\n";
			cout << "����ʱ��:     "; cout << p->publishing_time.year << "��"
				<< p->publishing_time.month << "��"
				<< p->publishing_time.day << "��" << " \n";
			cout << "�������" << p->stock << endl;
			cout << "�ִ�����" << p->extant << endl;
			cout << endl;
			find = true;
		}
		/*-------------------------������Ҫ���ĵ��鼮��������ʼ����-------------------*/
		if (find == true)
		{
			if (p->extant == 0)
			{
				cout << "��Ǹ����ͼ���Ѿ���ȫ�����ģ�Ŀǰ�޷����ġ�\n";
			}
			else
			{
				M m = new Man;
				char name[20];//��Ž���������
				int book_num;//��Ž�������֤��
				m = headM;//Ϊ���ʵ�������׼��
				cout << "�����������������";
				panhan(name);//�жϽ������Ƿ�Ϊ����
				cin.clear(); rewind(stdin);
				cout << "����������˵���֤�ţ�";
				book_num = panduanInt();
				m = new Man;
				strcpy(m->name, name);//��д����������
				m->book_num = book_num;
				strcpy(m->book_name, p->book_name);//��д�����鼮��
				strcpy(m->write, p->write);//��д�����鼮����
				cout << "������黹���ڣ�\n"; panduanDay(m);//�жϹ黹����
				p->extant--;//�ִ�������һ
				m->next = NULL;//��ָ�븳��
				if (headM)//headM��Ϊ��
				{
					rearM->next = m;//���������Ϣ����
					rearM = m;
				}
				else//headMΪ��ʱ
				{
					headM = m;
					rearM = m;
				}
			}
		}
		cout << "�Ƿ�Ҫ���������鼮(Y/y) ������������ز˵�:";
		cin >> con;
		cin.clear(); rewind(stdin);
	} while (con == "y" || con == "Y");
}
//�黹ͼ��
void addExtant()
{
	system("CLS");//����
	M m; SP p;
	char book_name[40];//��Ž����鼮��
	char name[20];//��Ž���������
	cout << "��������Ҫ�黹��ͼ������";
	cin >> book_name; cin.clear(); rewind(stdin);
	cout << "����������˵�������";
	panhan(name);//�жϽ������Ƿ�Ϊ����
	cin.clear(); rewind(stdin);
	m = headM; p = head;//Ϊ���ʵ�������׼��
	if (m != NULL)//���������Ϣ
	{
		if ((headM == m) && (strcmp(book_name, m->book_name) == 0)&&(strcmp(name,m->name) == 0))//���ɾ���ǵ�һ��
		{
			headM = headM->next;//���ڶ����ڵ��ͷ�ڵ�
			cout << "<--------����Ϣ��ɾ��--------->\n";
			printLine();
			cout << "@" << m->name << "@" << "�����ĵ��鼮��Ϣ���£�\n";
			cout << m->name << "����֤��Ϊ��" << m->book_num << "\n";
			cout << "ͼ������"; cout << m->book_name << "\n";
			cout << "���ߣ�"; cout << m->write << "\n";
			cout << "�黹ʱ�䣺"; cout << m->back_time.year << "��"
				<< m->back_time.month << "��"
				<< m->back_time.day << "��" << " \n";
			while ((strcmp(book_name, p->book_name) != 0) && (p->next != NULL))//�ڵ�����book���ҵ���ͼ��ڵ�
			{
				p = p->next;
			}
			p->extant++;//��ͼ��ڵ��ִ�����һ
			cout << endl;
		}
		else
		{
			while ((strcmp(book_name, m->book_name) != 0) && (m->next != NULL) && (strcmp(name, m->name) != 0))//Ѱ�ҽڵ�
			{
				rearM = m;//����ϸ��ڵ�
				m = m->next;//ָ���¸��ڵ�
			}
			if ((strcmp(book_name, m->book_name) == 0) && (strcmp(name, m->name)==0))
			{
				rearM->next = m->next;//���ϸ��ڵ������¸��ڵ�
				cout << "<--------����Ϣ��ɾ��--------->\n";
				printLine();
				cout << "@" << m->name << "@" << "�����ĵ��鼮��Ϣ���£�\n";
				cout << m->name << "����֤��Ϊ��" << m->book_num << "\n";
				cout << "ͼ������"; cout << m->book_name << "\n";
				cout << "���ߣ�"; cout << m->write << "\n";
				cout << "�黹ʱ�䣺"; cout << m->back_time.year << "��"
					<< m->back_time.month << "��"
					<< m->back_time.day << "��" << " \n";
				while ((strcmp(book_name, p->book_name) != 0) && (p->next != NULL))//�ڵ�����book���ҵ���ͼ��ڵ�
				{
					p = p->next;
				}
				p->extant++;//��ͼ��ڵ��ִ�����һ
				cout << endl;
			}
			else if ((strcmp(book_name, m->book_name) != 0) && (strcmp(name, m->name) == 0))
			{
				cout << "δ���ҵ��ý�����Ϣ���������������Ϣ�Ƿ�����" << endl;
			}
		}
	}
	else cout << "δ���ҵ��ý�����Ϣ��" << endl;
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
bool eixtrecord(SP head,char ISBN[14])//�ж�ISBN�Ƿ��Ѿ�����
{   
	system("CLS");
	SP p=head;
	while(p)
	{  
		if(strcmp(p->ISBN,ISBN)==0)
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
	cout << "******************ͼ���޸�******************\n";

	cout << "    A   �޸�ͼ����  \n";
	cout << "    B   �޸ķ����  \n";
	cout << "    C   �޸ĳ���ʱ��\n";
	cout << "    D   �޸ĳ��浥λ\n";
	cout << "    E   �޸�������  \n";
	cout << "    F   �޸ļ۸�    \n";
	cout << "    G   �޸Ŀ����  \n";
	cout << "  �����������޸ĵ���Ϣ:";
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
 cout<<"��¼�ţ�";cin>>p1->ISBN;cin.clear();rewind(stdin);
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
  if(!eixtrecord(p,p1->ISBN))//�жϵ�¼���Ƿ����
 {
 if(head==NULL)
 {
    head=p1;
    p1->next=NULL;
 }
 else
 {
     while(p1->ISBN>p->ISBN&&p->next!=NULL)//�жϵ�¼�ŵĴ�С
	 {
         rear=p;//����ϸ��ڵ�
         p=p->next;//ָ���ϸ��ڵ�
	 }
     if(p1->ISBN<=p->ISBN)
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
	      if(p->ISBN>q->ISBN)//�����ڵ�����
		  { 
              Book* p2;
			  p2=new Book;
			  strcpy(p2->ISBN,p->ISBN);
			  strcpy( p2->book_name,p->book_name);//ͨ��strcpy���������������ݸ���
              strcpy( p2->write ,p->write);
			  strcpy( p2->classify,p->classify);
              strcpy( p2->publishing_unit,p->publishing_unit);
			  p2->publishing_time.year=p->publishing_time.year;         
			  p2->publishing_time.month=p->publishing_time.month ;
			  p2->publishing_time.day=p->publishing_time.day;
			  strcpy(p->ISBN, q->ISBN);
			  strcpy( p->book_name,q->book_name);
              strcpy( p->write ,q->write);
			  strcpy( p->classify,q->classify);
              strcpy( p->publishing_unit,q->publishing_unit);
			  p->publishing_time.year=q->publishing_time.year;         
			  p->publishing_time.month=q->publishing_time.month; 
			  p->publishing_time.day=q->publishing_time.day;
			  strcpy(q->ISBN, p2->ISBN);
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
//�ж�book���ںϷ���
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
//�ж�Man���ںϷ���
void panduanDay(Man* m)//�ж�����
{
	char con = '2';//����ѭ��
	do
	{
		cout << "�꣺";
		cin >> m->back_time.year; cin.clear(); rewind(stdin);//�������ݲ���ջ�����
		if (m->back_time.year < 1900 || m->back_time.year>2021)
		{
			cout << "�����1900-2021" << endl; con = '2';
		}
		else
		{
			do
			{
				cout << "�£�"; cin >> m->back_time.month; cin.clear(); rewind(stdin);
				if (m->back_time.month < 1 || m->back_time.month>12)
				{
					cout << "�������������䣡�·�(1-12)" << endl; con = '3';
				}
				else
				{
					do
					{
						cout << "�գ�"; cin >> m->back_time.day; cin.clear(); rewind(stdin);
						if (m->back_time.day > 31 || m->back_time.day < 1)
						{
							cout << "�������������䣡" << endl; con = '5';
						}
						else con = '6';
					} while (con == '5');
					con = '4';
				}
			} while (con == '3');
			con = '0';
		}
	} while (con == '2');
}
//�ж�Book�ṹ�������Ƿ�Ϊ����
void panhan(char write[])//�����ж�
{
	int www;//�����жϣ��Ƿ��˳�ѭ��
	int d;
    do
	{
		www=0;
	    cin>>write;//���������з�
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
			int i=0,nlen=strlen(write);
			for(;i<nlen;i++)
			{
				if(write[i]>=0&&write[i]<=127)//�ж��Ƿ���ȫ���ַ�
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
void classfiyJ(Book* p)//�жϷ����
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
void recordJ(Book* p)//�ж�ISBN
{  
	int n;
	do
	{
		n = 0;
		cin >> p->ISBN; cin.clear(); cin.sync();//����ISBN����ջ�����
		if (sizeof(p->ISBN) != 14)
		{
			cout << "*������������������(13λ����)��"; n = 2;
			cin.clear();//�����
			cin.sync();
		}
		for (int i = 0; i < 13; i++)
		{
			if (p->ISBN[i] < '0' || p->ISBN[i]>'9')
			{
				cout << "*������������������(13λ����)��"; n = 2;
				cin.clear();//�����
				cin.sync();
				break;
			}
		}
	} while (n == 2);
}
int panduanInt()//����Ϊ����
{
	int num = 0;
	do
	{
		string str;
		cin >> str;
		num = 0;
		num = atoi(str.c_str());
		if (num == 0)
		{
			cout << "�����������������(��������)��";
		}
	} while (num == 0);
	return num;
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
