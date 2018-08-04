#include "Control.h"
#include"date.h"
void Control::Notice(){
	ifstream in("notice.txt");
	string str;

	if(in)  //have this txt
	{
		while (getline (in, str)) // line�в�����ÿ�еĻ��з�
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);  //set green 
			cout << str;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);  //set light white 
		}
	}
	else  //txt doesn't exist then report error
	{
		cout <<"ϵͳ�Ҳ��������ļ������鵱ǰĿ¼���Ƿ����notice.txt";
	}
}

void Control::modifyNotice(){ 
	string temp;
	ofstream fout;
	fout.open("notice.txt");
	cout<<"�������������µ�ϵͳ���棬�س�����ɣ����ܺ��пո�ͻس��������ַ���"<<endl;
	cin>>temp;
	fout<<temp<<endl;
	fout.close();
	cout<<"�޸���ɣ�"<<endl; 
}

void Control::mainPrinter(){
	CDate timtemp;
	cout<<"----------------------------------------"<<endl;
	cout<<"|----������"<<timtemp.format("DDD")<<"����ӭʹ�ã�---|"<<endl;
	cout<<"----------------------------------------"<<endl;
	cout<<"|  *��Ա�������Ͷ������ܰ����Ż�       |"<<endl;
	cout<<"|  *�����Ͳͷ�Ϊ5Ԫ                    |"<<endl;
	cout<<"|  *��Ա�����ͷ�                       |"<<endl;
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
		cout<<"���컹û�����������أ���ȥ����һ���ɡ�"<<endl;
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
		cout<<"���컹û����ʳ�����أ���ȥ����һ���ɡ�"<<endl;
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
	cout<<endl<<"  ���칲�ж���"<<outsideorderNumb+insideorderNumb<<"�������У�\n    ����������"<<outsideorderNumb<<"����ռ��Լ"<<outsideorderNumb/(outsideorderNumb+insideorderNumb)*100<<"%"<<endl;
	cout<<"    ��ʳ������"<<insideorderNumb<<"����ռ��Լ"<<insideorderNumb/(outsideorderNumb+insideorderNumb)*100<<"%"<<endl<<"      ��������ร�"<<endl; 
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
