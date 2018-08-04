#include "Menu.h"
ostream& operator<<(ostream& os,MenuItem &kk){
	os<<setiosflags(ios::left)<<setw(10)<<kk.id<<setw(10)<<kk.name<<resetiosflags(ios::left)<<setw(10)<<kk.price;
}

void Menu::setMenu(){
	ifstream m("menu.txt");
	if(m)  //have this txt
	{
		while(!m.eof()){
		MenuItem k;
		m>>k.id>>k.name>>k.price;
		item.push_back(k);
	    }
	    m.close();
        cout<<"  �˵���ȡ�ɹ���"<<endl<<endl;
	}
	else  //txt doesn't exist report error
	{
		cout <<"  ��ʼ��ʧ�ܣ�ϵͳ�Ҳ����˵��ļ������鵱ǰĿ¼���Ƿ����menu.txt��ϵͳ������8s���Զ��˳�"<<endl;
		//Sleep(8000);
		cout<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);  //set red
		cout<<"   8";  //Count down start
		Sleep(1000);
		cout<<"\b   7";
		Sleep(1000);
		cout<<"\b   6";
		Sleep(1000);
		cout<<"\b   5";
		Sleep(1000);
		cout<<"\b   4";
		Sleep(1000);
		cout<<"\b   3";
		Sleep(1000);
		cout<<"\b   2";
		Sleep(1000);
		cout<<"\b   1";
		Sleep(1000);  //Count down end		
		exit(0);

	}
	
}

void Menu::printItem(){
	cout<<setiosflags(ios::left)<<setw(10)<<"���"<<setw(10)<<"����"<<resetiosflags(ios::left)<<setw(10)<<"��Ʒ�۸�"<<endl;
	for(int i=0;i<item.size();i++){
		cout<<item[i]<<endl;
	}
}

void Menu::insertItem(){
	MenuItem k;
	cout<<"���������������Ʒ����š����ơ�����"<<endl;
	cin>>k.id>>k.name>>k.price; 
	if(k.id>=item.size()){
		k.id=item.size()+1;
		item.push_back(k);
	}
	else{
		vector<MenuItem>::iterator it=item.begin();
		it=it+k.id;
		item.insert(it-1,k);
		for(int i=k.id;i<item.size();i++){
			item[i].id++;
		}
	}
	ofstream file("menu.txt");
	file.clear();
	for(int i=0;i<item.size();i++){
		file<<item[i];
		if (i!=item.size()-1) file<<endl;
	} 
	file.close();
}
void Menu::deleteItem(){
	printItem();   //print the menu before delete
	int n;
	int k=0; //�Ƿ��޸Ĳ�Ʒ��ŵı��
	cout<<"��������Ҫɾ���Ĳ�Ʒ���"<<endl;
	cin>>n;
	vector<MenuItem>::iterator it=item.begin();
	for(int i=0;i<item.size();i++){
		if(item[i].id==n){
			item.erase(it+i);
			i=i--;
			k++;
		}
		if(k!=0){
			item[i].id--;
		}
	}
	ofstream file("menu.txt");
	file.clear();
	for(int i=0;i<item.size();i++){
		file<<item[i];
		if (i!=item.size()-1) file<<endl;
	} 
	file.close();
}
void Menu::modifyItem(){
	int ID;
	printItem();   //print the menu before modify 
	cout<<"������Ҫ�޸ĵĲ�Ʒ���:"<<endl;
	cin>>ID;
	vector<MenuItem>::iterator flag=item.begin();
	for(int i=0;i<item.size();i++){
		if(item[i].id==ID){
			cout<<"�������޸ĺ��Ʒ���ơ�����"<<endl;
			cin>>item[i].name>>item[i].price;
		}
	}
	ofstream file("menu.txt");
	file.clear();
	for(int i=0;i<item.size();i++){
		file<<item[i];
		if (i!=item.size()-1) file<<endl;
	} 
	file.close();
}
void Menu::searchItem(){
	int id;
	cin>>id;
	for(int i=0;i<item.size();i++){
		if (item[i].id==id) {
			cout<<item[i]<<endl;
		}
		else {
			cout<<"�Ҳ������Ϊ"<<id<<"�Ĳ�Ʒ��" <<endl;
		}
	}
}
	
double Menu::returnPrice(int dishid){
	for(int i=0;i<item.size();i++){
		if (item[i].id==dishid) {
			return item[i].price;
		}
	}
}
	

