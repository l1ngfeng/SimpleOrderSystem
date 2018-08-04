#include "Control.h"
#include"date.h"
void Control::Notice(){
	ifstream in("notice.txt");
	string str;

	if(in)  //have this txt
	{
		while (getline (in, str)) // line中不包括每行的换行符
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);  //set green 
			cout << str;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);  //set light white 
		}
	}
	else  //txt doesn't exist then report error
	{
		cout <<"系统找不到公告文件，请检查当前目录下是否存在notice.txt";
	}
}

void Control::modifyNotice(){ 
	string temp;
	ofstream fout;
	fout.open("notice.txt");
	cout<<"请在下面输入新的系统公告，回车键完成（不能含有空格和回车等特殊字符）"<<endl;
	cin>>temp;
	fout<<temp<<endl;
	fout.close();
	cout<<"修改完成！"<<endl; 
}

void Control::mainPrinter(){
	CDate timtemp;
	cout<<"----------------------------------------"<<endl;
	cout<<"|----今天是"<<timtemp.format("DDD")<<"，欢迎使用！---|"<<endl;
	cout<<"----------------------------------------"<<endl;
	cout<<"|  *会员所有类型订单享受八折优惠       |"<<endl;
	cout<<"|  *外卖送餐费为5元                    |"<<endl;
	cout<<"|  *会员免外送费                       |"<<endl;
	cout<<"----------------------------------------"<<endl;
	cout<<endl<<setw(4)<<"##";
	Notice();
	cout<<"##"<<endl<<endl;
}

void Control::countOrder(){
	double outsideorderNumb=0;
	double insideorderNumb=0;   //calculate % so use double
	CDate ctime;  //get time
	string strTime=ctime.format("ddd");  //define a new string as the name of .txt
	strTime=strTime+'o'+'u'+'t'+'.'+'t'+'x'+'t';  //finish string
	fstream fin(strTime.c_str(),ios::in); //only read 
	if(!fin){
		cout<<"今天还没有外卖订单呢，快去新增一个吧。"<<endl;
	}
	else {
	char c;
	while(fin.get(c)){	
		if(c=='\n')
		outsideorderNumb++;
	}
	//outsideorderNumb+=1;
	fin.close();
	}
	
	//insideorder count begin
	string strTime1=ctime.format("ddd");  //define a new string as the name of .txt
	strTime1=strTime1+'i'+'n'+'.'+'t'+'x'+'t';  //finish string
	fstream fin1(strTime1.c_str(),ios::in);  //only read 
	if(!fin1){
		cout<<"今天还没有堂食订单呢，快去新增一个吧。"<<endl;
	}
	else {
	char c1;
	while(fin1.get(c1)){	
		if(c1=='\n')
		insideorderNumb++;
	}
	//insideorderNumb+=1;
	fin1.close();
	}
	cout<<endl<<"  今天共有定单"<<outsideorderNumb+insideorderNumb<<"个，其中：\n    外卖订单共"<<outsideorderNumb<<"个，占比约"<<outsideorderNumb/(outsideorderNumb+insideorderNumb)*100<<"%"<<endl;
	cout<<"    堂食订单共"<<insideorderNumb<<"个，占比约"<<insideorderNumb/(outsideorderNumb+insideorderNumb)*100<<"%"<<endl<<"      继续加油喔！"<<endl; 
}

int Control::returnItemCount(){
	int count=1;
	fstream fin1("menu.txt",ios::in);  //only read 
	char c1;
	while(fin1.get(c1)){	
		if(c1=='\n')
		count++;
	}
	fin1.close();
	return count;
}
