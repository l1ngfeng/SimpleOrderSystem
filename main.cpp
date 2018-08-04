#include"Control.h"
using namespace std;
int main() {
	Control P;
	P.mainPrinter();
	int choice;
	Menu a;
	a.setMenu();  //set menu while start 
	P.countOrder(); 
	TakeOutOrder o1;
	insideOrder o2; 
	for(;;){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_BLUE);//set light blue 
		cout<<"\n  #############餐厅管理系统##############"<<endl;
		cout<<"  #                                     #"<<endl;
		cout<<"  #**************菜单管理***************#"<<endl;
		cout<<"  #                                     #"<<endl;
		cout<<"  #     1.查看菜单       2.添加菜品     #"<<endl;
		cout<<"  #     3.删除菜品       4.修改菜品     #"<<endl;
		cout<<"  #                                     #"<<endl;
		cout<<"  #**************订单管理***************#"<<endl;
		cout<<"  #                                     #"<<endl;
		cout<<"  #        5.统计今日所有订单           #"<<endl;
		cout<<"  #                                     #"<<endl;
		cout<<"  #--------------外卖订单---------------#"<<endl;
		cout<<"  #                                     #"<<endl;
		cout<<"  #   6.新增外卖订单   7.删除外卖订单   #"<<endl;
		cout<<"  #                                     #"<<endl;
		cout<<"  #--------------堂食订单---------------#"<<endl;
		cout<<"  #                                     #"<<endl;
		cout<<"  #   8.新增堂食订单   9.删除堂食订单   #"<<endl;
		cout<<"  #                                     #"<<endl;
		cout<<"  #**************公告管理***************#"<<endl;
		cout<<"  #                                     #"<<endl;
		cout<<"  #    10.修改公告       11.显示公告    #"<<endl;
		cout<<"  #                                     #"<<endl;
		cout<<"  #-------------------------------------#"<<endl;
		cout<<"  #                                     #"<<endl;
		cout<<"  #            0.退出系统               #"<<endl;
		cout<<"  #######################################"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);//set light white
		cin>>choice;
		switch(choice){
			case 1:
				a.printItem();
				break;
			case 2:
				a.insertItem(); 
				break;
			case 3:
				a.deleteItem();
				break;
			case 4:
				a.modifyItem(); 
				break;
			case 5:
				P.countOrder();		
				break;
			case 6:
				o1.NewTakeOutOrder();		
				break;;
			case 7:
				o1.deleteTakeOutOrder();
				break;
			case 8:
				o2.NewInsideOrder();
				break;
			case 9:
				o2.deleteInsideOrder();
				break;
			case 10:
				P.modifyNotice(); 
				break;
			case 11:
				P.Notice();
				cout<<endl;
				break;
			case 0:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);  //set red
				cout<<"  谢谢您的使用！"<<endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);//set light white
				Sleep(1000); 
				exit(0);
			default:
				cout<<"选项输入错误！请重新输入!"<<endl;
		}
	} 
	return 0;
}
