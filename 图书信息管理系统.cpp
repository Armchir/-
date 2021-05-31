#include<iostream>
#include<string>
#include<fstream>
#include<windows.h>
using namespace std;
//创建图书信息中的时间单链表
struct Time
{
  int day;
  int month;
  int year;
};
//创建图书信息的结构体单链表
typedef struct Book
{
  int record;//登录号
  char book_name[40];//图书名
  char write[20];//作者
  char classify[10];//分类号
  char publishing_unit[50];//出版单位
  Time publishing_time;//出版时间
  int  price;
  struct Book* next;
}*SP;
bool eixtrecord(SP head,int record);//判断登录号是否存在
void menu();//菜单
void fMenu();//修改选项界面
void mainfrom();//主界面
void appData();//录入数据
void modData();//修改数据
void delData();//删除数据
void findData();//查询数据
void showData();//显示数据
void saveData();//保存数据
void intsData();//插入数据
void panduanDay(Book* p);//判断日期
void panhan(Book* p);//判断汉字
void classfiyJ(Book* p);//判断分类号
void recordJ(Book* p);//判断登录号
void paiData();//信息排序
void outSystem();//退出系统
void printLine();//划线
void loading();//数据加载标志
void loadData();//导入数据
//全局声明
  SP head=NULL,rear=NULL;
  ofstream myfile;
  fstream readmyfile;
 //主函数
int main()
{
 system("color E4");//设置界面颜色
 loading();//调用函数加载数据，进入页面
 loadData();//将上一次保存的数据读入
 mainfrom();//主界面 	
 return 0;
}
//菜单
void menu()
{
 system("CLS");
 cout<<"\n\n\n\n\n\n\n\n\n";
cout<<"                                     ※※※※※※※※※※※※※※※※※※※※※\n";
 cout<<"                                     ※      欢迎来到图书信息管理系统        ※\n";
 cout<<"                                     ※              1信息录入               ※\n";
 cout<<"                                     ※              2信息保存               ※\n";
 cout<<"                                     ※              3信息浏览               ※\n";
 cout<<"                                     ※              4信息查询               ※\n";
 cout<<"                                     ※              5信息修改               ※\n";
 cout<<"                                     ※              6信息删除               ※\n";
 cout<<"                                     ※              0退出系统               ※\n";
 cout<<"                                     ※※※※※※※※※※※※※※※※※※※※※"<<"         制作人：雷安伟、尚夏\n";
 cout<<"                                           请在(0-6)中选择你需要的功能:";
} 
void mainfrom()
{ 
  system("CLS");//清屏
  char con;//控制进入相关的功能
  menu();//菜单
  cin>>con;
  cin.clear();rewind(stdin);//清空缓冲区
  switch(con)//开关，进入相关功能
  {
  case '1':appData();break;
  case '2':saveData();break;
  case '3':showData();system("PAUSE");break;
  case '4':findData();system("PAUSE");break;
  case '5':modData();break;
  case '6':delData();system("PAUSE");break;
  case '0':outSystem();break;
  default:cout<<"请输入在规定范围内的。\n";system("PAUSE");system("CLS");menu();cout<<endl;cout<<"请重新输入：";mainfrom();
  }
  mainfrom();//主界面
}
//信息录入
void appData()
{  system("CLS");//清屏
   SP book;
   string con="y";//控制循环是否继续
   cout<<"                  输入图书信息\n"; 
 do//整体
 {
	book=new Book;
    cout<<"登录号(4位)：";
	recordJ(book);//判断登录号的格式是否正确
	if(eixtrecord(head,book->record ))//判断登录号是否存在
	{
     cout<<"该登录号已存在。\n";
	}
    else  
	{   
		   cout<<"图书名:";cin>>book->book_name; //输入信息
		   cout<<"作者:";
		   panhan(book);//判断作者是否为汉字
           cout<<"分类号【A-Z】:";
           classfiyJ(book);//判断登录号的格式
     	   cout<<"出版单位:";cin>>book->publishing_unit;//输入的信息
           cout<<"价格:";cin>>book->price;rewind(stdin);//输入的信息
           cout<<"出版时间:\n";panduanDay(book);//判断日期
      	   book->next=NULL;//将指针赋空
	    if(head)//head不为空
		{
	      rear->next=book;//将输入的信息连在
	      rear=book;
		}
   	    else//head为空时
		{
	      head=book;
	      rear=book;
		}
	
	    cout<<"是否要继续输入(Y/y) ，按任意键返回菜单:";
	    cin>>con;
        cin.clear();rewind(stdin);
	}

 }while(con=="y"||con=="Y");
}
//信息浏览
void showData()
{
	 system("CLS");
     SP p;
     p=head;
	 if(p)//判断是否有数据，有则执行
	 {
	     cout<<"              已有图书信息\n";
      while(p)//
	  {
        cout<<"登录号:       ";cout<<p->record<<"          \n";       
	    cout<<"图书名:       ";cout<<p->book_name<<"       \n";     
    	cout<<"作者:         ";cout<<p->write<<"           \n";
    	cout<<"分类号(A-Z):";cout<<p->classify<<"        \n"; 
    	cout<<"出版单位:     ";cout<<p->publishing_unit<<"  \n";
		cout<<"图书价格:     ";cout<<p->price<<"  \n";
	    cout<<"出版时间:     ";cout<<p->publishing_time.year
			<<"年"<<p->publishing_time.month<<"月"
			<<p->publishing_time.day<<"日"<<" \n";
     	cout<<endl;
     	cout<<"图书信息\n";
     	p=p->next;//指向下一个
	  }
	 }
	 system("PUASE");
}
//信息保存
void saveData()
{
    myfile.open("book.dat",ios::out|ios::binary);
	if(!myfile)
	{
		cout<<"文件打开失败！"<<endl;
		system("pause");
		exit(1);//非正常退出
	}
	SP p=head;
	while(p) 
	{
		myfile.write((char*)p,sizeof(Book)-4);
		cout<<"保存成功"<<endl;
		printLine();//画线
		system("pause");
		p=p->next;
	}
	myfile.close();//关闭文件
}

//信息查询
void findData()
{
  system("CLS");//清屏
  SP p;
  char book_name[50];//定义字符数组，输入图书名
  char write[10];//定义字符数组，输入图书名
  char con='y';//控制要查询的选项
  p=head;//为访问链表做准备
  cout<<"你是按登录号还是图书名还是按组合(1.作者：2.图书名)：";cin>>con;cin.clear();rewind(stdin);//清空缓冲区
  if(con=='1')
   {
    cout<<"你要查询的作者是：";
	cin>>write;
	printLine();//画线
    do
	{
		while((p!=NULL)&&(strcmp(p->write,write)!=0))//询找节点
		{
		  p=p->next; 
		}
		if(!p)//如果p为NULL时
		{
		  cout<<"此信息不存在！"<<endl;
		}
	   else	if(strcmp(p->write,write)==0)
		{
		    cout<<"登录号:       ";cout<<p->record<<"          \n";
			cout<<"图书名:       ";cout<<p->book_name<<"       \n";   
    		cout<<"作者:         ";cout<<p->write<<"           \n";
    		cout<<"分类号(A-Z):";cout<<p->classify<<"        \n";
    		cout<<"出版单位:     ";cout<<p->publishing_unit<<"  \n";
			cout<<"出版价格：    ";cout<<p->price<<"\n";
			cout<<"出版时间:     ";cout<<p->publishing_time.year<<"年"
				<<p->publishing_time.month<<"月"
				<<p->publishing_time.day<<"日"<<" \n";
			cout<<endl;
			p=p->next;
		}
	}while(p!=NULL);
  }
   if(con=='2')
   {
    cout<<"你要查询的图书名是：";
	cin>>book_name;
	while((p!=NULL)&&strcmp(p->book_name,book_name)!=0)//寻找节点
	{
	  p=p->next; 
	}
	if(!p)//如果p为空
	{
	  cout<<"此信息不存在！"<<endl;
	}
   else  if(strcmp(p->book_name,book_name)==0)
	{
    	cout<<"登录号:       ";cout<<p->record<<"          \n";
	    cout<<"图书名:       ";cout<<p->book_name<<"       \n";
    	cout<<"作者:         ";cout<<p->write<<"           \n";
    	cout<<"分类号(A-Z):";cout<<p->classify<<"        \n";
    	cout<<"出版单位:     ";cout<<p->publishing_unit<<"  \n";
		cout<<"出版价格：    ";cout<<p->price<<"\n";
	    cout<<"出版时间:     ";cout<<p->publishing_time.year<<"年"
			<<p->publishing_time.month<<"月"
			<<p->publishing_time.day<<"日"<<" \n";
		cout<<endl;
	}
   }
}
//信息修改
void modData()
{
  system("CLS");//清屏
  SP p;
  int record;//定义整型
  p=new Book;//为p分配新内存空间
  p=head;//为访问链表做准备
  cout<<"你需要修改图书信息的登录号:";
  cin>>record;
  cin.clear();rewind(stdin);//清空缓冲区
  while((p!=NULL)&&(p->record!=record))//寻找节点
		{
		  p=p->next; 
		}
		if(!p)//如果p为NULL
		{
		  cout<<"此信息不存在！"<<endl;system("PUASE");
		}
  else 
  {
   char con1,con2;//控制进出
   do
   {
   fMenu();//次菜单
   cin>>con1;
   rewind(stdin);//清空缓冲区
     switch(con1)//开关，控制选项
	 {
      case 'A':cout<<"图书名:";cin>>p->book_name;
		       cout<<" *******修改后：\n";
		       cout<<"图书名:";cout<<p->book_name;cout<<endl;system("PAUSE");break;
      case 'B':cout<<"分类号（A-Z）：";cin>>p->classify;rewind(stdin);
		       cout<<" *******修改后：\n";
		       cout<<"分类号（A-Z）：";cout<<p->classify;cout<<endl;system("PAUSE");break;
      case 'C':cout<<"出版时间:"; cout<<"年：";cin>>p->publishing_time.year;cout<<"月：";cin>>p->publishing_time.month;cout<<"日：";cin>>p->publishing_time.day;rewind(stdin);
		       cout<<" *******修改后：\n";
		       cout<<"出版时间:"; cout<<p->publishing_time.year<<"年"<<p->publishing_time.month<<"月"<<p->publishing_time.day<<"日";cout<<endl;system("PAUSE");break;
      case 'D':cout<<"出版单位:"; cin>>p->publishing_unit ;
		       cout<<" *******修改后：\n";
		       cout<<"出版单位:"; cout<<p->publishing_unit ;cout<<endl; system("PAUSE");break;
      case 'E':cout<<"作者:"; cin>>p->write;
	           cout<<" *******修改后：\n";
               cout<<"作者:"; cout<<p->write ;cout<<endl;system("PAUSE");break;
	  case 'F':cout<<"出版价格";cin>>p->price;
		       cout<<" *******修改后：\n";
               cout<<"出版单位:"; cout<<p->price;cout<<endl;system("PAUSE");break;
      default :cout<<" 请输入范围内的选项。\n";
	 }
	 cout<<" 是否还需要修改（Y/y） ， 按任意键返回菜单:"; 
     cin>>con2;
	 rewind(stdin);
   }while(con2=='Y'||con2=='y');
  }
}
//信息删除
void delData()
{
  system("CLS");
  SP p;//q为中间变量
  int record;
  cout<<"请输入要删除的登录号：";
  cin>>record;cin.clear();rewind(stdin);
  p=head;
  if(p!=NULL)//如果以有信息
  {
  while(record!=p->record&&p->next!=NULL)//寻找节点
  {
    rear=p;//存放上个节点
	p=p->next;//指向下个节点
  }
  if(record==p->record)
  {  
	  rear->next=p->next;//将上个节点连接下个节点
	  cout<<"<--------此信息已删除--------->\n";
	  printLine();
	  cout<<"已删除的信息如下：\n";

    	cout<<"登录号:       ";cout<<p->record<<"          \n";
	    cout<<"图书名:       ";cout<<p->book_name<<"       \n";
    	cout<<"作者:         ";cout<<p->write<<"           \n";
    	cout<<"分类号(A-Z):";cout<<p->classify<<"        \n";
    	cout<<"出版单位:     ";cout<<p->publishing_unit<<"  \n";
		cout<<"出版价格：    ";cout<<p->price<<"  \n";
	    cout<<"出版时间:     ";cout<<p->publishing_time.year<<"年"
			<<p->publishing_time.month<<"月"
			<<p->publishing_time.day<<"日"<<" \n";

     	cout<<endl;
	 
  } 
   else if(record!=p->record)
   {  
     cout<<"信息不存在！"<<endl;
   }
   if(p==head&&record==p->record)//如果删除的是第一个节点
	  {  
	    head=head->next;//将第二个节点给头节点
      cout<<"<--------此信息已删除--------->\n";
	  printLine();
	    cout<<"已删除的信息如下：\n";
    	cout<<"登录号:       ";cout<<p->record<<"          \n";
	    cout<<"图书名:       ";cout<<p->book_name<<"       \n";
    	cout<<"作者:         ";cout<<p->write<<"           \n";
    	cout<<"分类号（A-Z）:";cout<<p->classify<<"        \n";
    	cout<<"出版单位:     ";cout<<p->publishing_unit<<"  \n";
        cout<<"出版价格：    ";cout<<p->price<<"  \n";
	    cout<<"出版时间:     ";cout<<p->publishing_time.year<<"年"
			<<p->publishing_time.month<<"月"
			<<p->publishing_time.day<<"日"<<" \n";
     	cout<<endl;
	  }
   else cout<<"此信息不存在！"<<endl;
  }
  else cout<<"你还未录入信息！"<<endl;	 
}
//退出系统
void outSystem()
{
  system("CLS");
  cout<<"<---------感谢使用！--------->\n";
  exit(0);//正常退出
}
void printLine()//划线
{
	cout<<"--------------------------------\n";
}
bool eixtrecord(SP head,int record)//判断登录号是否已经存在
{   
	system("CLS");
	SP p=head;
		while(p)
		{  
			if((p->record==record))
			{
				return true;//返回ture
				break;//跳出循环
			}
			p=p->next;//指向下个节点
		} 
	return false;//返回false
}
void fMenu()//次菜单
{
 system("CLS");
 cout<<"******************图书修改******************\n";
 
 cout<<"    A   修改图书名  \n";
 cout<<"    B   修改分类号  \n";
 cout<<"    C   修改出版时间\n";
 cout<<"    D   修改出版单位\n";
 cout<<"    E   修改作者名  \n";
 cout<<"    F   修改价格    \n";
 cout<<"  请输入你想修改的信息:";
}
void loading()
{
      int i;
	  for(i=0;i<10;i++)//循环输出
	  {
	   cout<<"*****************************************************loading********************************************************\n";
	   cout<<"                                                       "<<i<<"0%";
	   Sleep(100);//停0.01秒
       system("cls");
	  }
}
void intsData()//信息插入
{
 system("CLS");//清屏
 SP p;
 SP p1;//定义结构体变量
 p1=new Book;//分配内存空间
 cout<<"@插入数据："<<endl;
 cout<<"登录号：";cin>>p1->record;cin.clear();rewind(stdin);
 cout<<"图书名：";cin>>p1->book_name;
 cout<<"作者：";cin>>p1->write;
 cout<<"分类号（A-Z）：";cin>>p1->classify;
 cout<<"出版单位：";cin>>p1->publishing_unit;
 cout<<"出版价格：";cin>>p1->price;
 cout<<"出版时间：";
 cout<<"年：";cin>>p1->publishing_time.year;cin.clear();rewind(stdin);
 cout<<"\n月：";cin>>p1->publishing_time.month;cin.clear();rewind(stdin);
 cout<<"\n日：";cin>>p1->publishing_time.day;cin.clear();rewind(stdin);
 p=head;//为访问链表做准备
  if(!eixtrecord(p,p1->record))//判断登录号是否存在
 {
 if(head==NULL)
 {
    head=p1;
    p1->next=NULL;
 }
 else
 {
     while(p1->record>p->record&&p->next!=NULL)//判断登录号的大小
	 {
         rear=p;//存放上个节点
         p=p->next;//指向上个节点
	 }
     if(p1->record<=p->record)
	 {
        rear->next=p1;//将上一个节点指向p1
        p1->next=p;//将p1指向与其比较的p
	 }
     else//如果他为最大的
	 {
        p->next=p1;//将其放入链表尾
        p1->next=NULL;
	 } 
 }
 }
 else cout<<"信息已经存在了！"<<endl;
}
void paiData()//排序，用冒泡排序法
{
  Book* p;//定义结构体变量
  Book* q;
 
  for(p=head;p!=NULL;p=p->next)//冒泡排序法
	  for(q=p->next;q!=NULL;q=q->next)
	  {   
	      if(p->record>q->record)//交换节点数据
		  { 
              Book* p2;
			  p2=new Book;
			  p2->record=p->record;
			  strcpy( p2->book_name,p->book_name);//通过strcpy（）函数将其数据复制
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
void panduanDay(Book* p)//判断日期
{
 char m='2';//控制循环
 do
 {
   cout<<"年：";
   cin>>p->publishing_time.year;cin.clear();rewind(stdin);//输入数据并清空缓冲区
   if(p->publishing_time.year<1900||p->publishing_time.year>2021)
   {cout<<"年份在1900-2021"<<endl; m='2';}
   else
   {
      do
	  {
	    cout<<"月：";cin>>p->publishing_time.month;cin.clear();rewind(stdin);
		if(p->publishing_time.month<1||p->publishing_time.month>12)
		{
		   cout<<"输入有误！请重输！月份(1-12)"<<endl; m='3';
		}
		else
		{
		  do
		  {
		   cout<<"日：";cin>>p->publishing_time.day;cin.clear();rewind(stdin);
		   if(p->publishing_time.day>31||p->publishing_time.day<1)
		   {
		      cout<<"输入有误！请重输！"<<endl; m='5';
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
//判断作者是否为汉字
void panhan(Book* p)//汉字判断
{
	int www;//辅助判断，是否退出循环
	int d;
    do
	{
		www=0;
	    cin>>p->write;//不抛弃换行符
		d=getchar();//判断输入缓存区是否为空，d获取的是无定义的值
		if(d!=10)
		{
			www=1;
			cout<<"您的输入错误！";
			cout<<"请您重新输入：";
			cin.clear();//清空流
			cin.sync();
		}
		else
		{
			int i=0,nlen=strlen(p->write);
			for(;i<nlen;i++)
			{
				if(p->write[i]>=0&&p->write[i]<=127)//判断是否是全角字符
				{
					www=1;
					cout<<"您的输入错误！";
					cout<<"请您重新输入：";
					cin.clear();//清空流
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
    	  if(int a=p->classify[1])//如果第二个有数据，就提示错误，并重输
		  {
	         cout<<"输入错误，请重输:";
		  }
	      else
		  {
		     if(p->classify[0]<'A'||p->classify[0]>'Z')
			 {
		        cout<<"输入有误，请重输:";
			 }
		     else
			 {
		        n=1;
			 }
		  }
		}while(n!=1);
}
void recordJ(Book* p)//判断登录号
{  
	int n=0;
 	do
	{
		n=0;//用来控制循环条件
		cin>>p->record;cin.clear();cin.sync();//输入登录号，清空缓冲区
		if(p->record<1000||p->record>10000)//如果不满足，就进入
		{
		 cout<<"*输入有误！请重输(4位数字):";n=2;	
		}
	}while(n==2);
}
void loadData()//导入数据
{
	SP p;
	readmyfile.open("book.dat",ios::in|ios::out|ios::app|ios::binary);//已读写方式打开文件
   if(!readmyfile)
   {
      cout<<"打开文件失败！"<<endl;
      exit(1);//非正常退出
   }
     readmyfile.seekg(ios::beg);//文件指针位于文件开头
     while(!readmyfile.eof())//当没有超过文件尾时，执行循环
	{
	    p=new Book;//为p赋值新的内存空间
		if(readmyfile.read((char*)(p),sizeof(Book)-4))
		{
			p->next=NULL;
			if(head)//单链表头节点不为空时
			{
				rear->next=p;//尾指针下一节点指向p
				rear=p;//更新尾指针
			}
			else//单链表不为空时
			{
				head=p;//头指针指向p
				rear=p;//尾指针指向tp
			}
		}
	 }
}
