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
		cout<<"\n  #############��������ϵͳ##############"<<endl;
		cout<<"  #                                     #"<<endl;
		cout<<"  #**************�˵�����***************#"<<endl;
		cout<<"  #                                     #"<<endl;
		cout<<"  #     1.�鿴�˵�       2.��Ӳ�Ʒ     #"<<endl;
		cout<<"  #     3.ɾ����Ʒ       4.�޸Ĳ�Ʒ     #"<<endl;
		cout<<"  #                                     #"<<endl;
		cout<<"  #**************��������***************#"<<endl;
		cout<<"  #                                     #"<<endl;
		cout<<"  #        5.ͳ�ƽ������ж���           #"<<endl;
		cout<<"  #                                     #"<<endl;
		cout<<"  #--------------��������---------------#"<<endl;
		cout<<"  #                                     #"<<endl;
		cout<<"  #   6.������������   7.ɾ����������   #"<<endl;
		cout<<"  #                                     #"<<endl;
		cout<<"  #--------------��ʳ����---------------#"<<endl;
		cout<<"  #                                     #"<<endl;
		cout<<"  #   8.������ʳ����   9.ɾ����ʳ����   #"<<endl;
		cout<<"  #                                     #"<<endl;
		cout<<"  #**************�������***************#"<<endl;
		cout<<"  #                                     #"<<endl;
		cout<<"  #    10.�޸Ĺ���       11.��ʾ����    #"<<endl;
		cout<<"  #                                     #"<<endl;
		cout<<"  #-------------------------------------#"<<endl;
		cout<<"  #                                     #"<<endl;
		cout<<"  #            0.�˳�ϵͳ               #"<<endl;
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
				cout<<"  лл����ʹ�ã�"<<endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);//set light white
				Sleep(1000); 
				exit(0);
			default:
				cout<<"ѡ�������������������!"<<endl;
		}
	} 
	return 0;
}
