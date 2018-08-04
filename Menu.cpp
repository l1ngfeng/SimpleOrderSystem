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
        cout<<"  菜单读取成功！"<<endl<<endl;
	}
	else  //txt doesn't exist report error
	{
		cout <<"  初始化失败，系统找不到菜单文件，请检查当前目录下是否存在menu.txt，系统将会在8s后自动退出"<<endl;
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
	cout<<setiosflags(ios::left)<<setw(10)<<"编号"<<setw(10)<<"菜名"<<resetiosflags(ios::left)<<setw(10)<<"单品价格"<<endl;
	for(int i=0;i<item.size();i++){
		cout<<item[i]<<endl;
	}
}

void Menu::insertItem(){
	MenuItem k;
	cout<<"请输入依次输入菜品的序号、名称、单价"<<endl;
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
	int k=0; //是否修改菜品序号的标记
	cout<<"请输入您要删除的菜品序号"<<endl;
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
	cout<<"请输入要修改的菜品序号:"<<endl;
	cin>>ID;
	vector<MenuItem>::iterator flag=item.begin();
	for(int i=0;i<item.size();i++){
		if(item[i].id==ID){
			cout<<"请输入修改后菜品名称、单价"<<endl;
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
			cout<<"找不到编号为"<<id<<"的菜品！" <<endl;
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
	

