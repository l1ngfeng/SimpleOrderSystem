#include"order.h"
#include "Control.h"
void TakeOutOrder::NewTakeOutOrder(){
	Menu mtemp;
	Control tem;
	srand((unsigned)time(NULL));  //以时间为种
	SetOrderNumb(rand()%(9999-1000+1)+10000);  //以时间为种随机生成订单编号 
	int choice;
	int n=1;
	cout<<"请依次输入："<<endl;
		cout<<"是否为会员：（输入1是，输入其他则不是）";
		cin>>choice;
		setVip(choice);
    	cout<<"手机号：";
		setPhoneNumb();
		cout<<"送餐时间：";
		setTime();
		cout<<"送餐地址：";
		setLocation();
		mtemp.setMenu();
		mtemp.printItem();
		cout<<"菜单如上，请要点菜品的输入编号、份数。" <<endl;
		for(;n!=0;){
			int n1,c1;
			cin>>n1>>c1;
			if (n1>tem.returnItemCount()||n1<1){
				cout<<"没有这个编号的菜品！"<<endl; 
			}
			else {
				dishnc.insert(pair<int,int>(n1,c1));
			}
			cout<<"还要继续点菜吗？（输入1继续/0结束点餐）"; 
			cin>>n;
		}
		CDate ctime;  //get time
		string strTime=ctime.format("ddd");  //define a new string as the name of .txt
		strTime=strTime+'o'+'u'+'t'+'.'+'t'+'x'+'t';  //finish string
		//ifstream insidefile(strTime.c_str());
		ofstream takeoutfile;
			/*将内存中数据写入磁盘txt文件中*/ 
			takeoutfile.open(strTime.c_str(),ios::app); 
			takeoutfile<<GetOrderNumb()<<"	";  //output number of order 
			map<int,int>::iterator it;  //iterator
			double temprice=0;  //price of this order
			for (it=dishnc.begin();it!=dishnc.end();it++){
				takeoutfile<<it->first;   //number of dish
				takeoutfile<<",";
				takeoutfile<<it->second;  //copy of dish
				takeoutfile<<" ";
			}
			takeoutfile<<"	";
			takeoutfile<<getPhonenumb()<<"	";  //phonenumb
			takeoutfile<<getTime()<<"	";  //dtime
			takeoutfile<<getLocation()<<"	";  //location
			for (it=dishnc.begin();it!=dishnc.end();it++){
				for (int i=1;i<tem.returnItemCount();i++){
					if(it->first==i){
						temprice+=(it->second)*mtemp.returnPrice(i);   //copy*price 
					}
				}
			}
			
			if (getidentity()){
				temprice*=0.8;
				takeoutfile<<temprice;  //discount if is vip
			}
			else {
				temprice+=5;
				takeoutfile<<temprice;  //plus deliver fee if isn't vip
			}
			takeoutfile<<endl;
	   		takeoutfile.close();
       		cout<<"  此订单创建成功！优惠后总价为"<<temprice<<"元"<<endl<<endl;
}

void TakeOutOrder::deleteTakeOutOrder(){
	CDate ctime;  //get time
	string strTime=ctime.format("ddd");  //define a new string as the name of .txt
	strTime=strTime+'o'+'u'+'t'+'.'+'t'+'x'+'t';  //finish string
	
	fstream printfile(strTime.c_str(),ios::in|ios::out);
    string line;
    if(printfile.fail()){
    cerr<<"找不到外卖订单文件！"<<endl;
    }
    else 
	{
		cout<<"今日外卖订单如下："<<endl; 
		while(getline(printfile,line))
    	cout<<line<<endl;
		printfile.close(); 
		
    	
		ifstream file(strTime.c_str());
    	
    	int n, count = 0;
    	ofstream outfile("temp.txt", ios::out | ios::trunc);
    	cout << "请输入要删除订单的行数:" << endl;
    	cin >> n;
    	while (!file.eof()) {
        	getline(file, line);
        	if (count != n - 1)  //要修改内容就在这修改line的内容,再存到文件中就行了
            	outfile << line << endl;
        	count++;
    	}
    	outfile.close();
    	file.close();
    	ofstream outfile1(strTime.c_str(), ios::out | ios::trunc);
    	fstream file1("temp.txt");
    	while (!file1.eof()) {
        	getline(file1, line);
        	outfile1 << line <<endl;
    	}
       	outfile1.close();
    	file1.close();
    	system("del temp.txt");//删除中间文件
    	cout<<"删除成功！"<<endl;
   	}
}

void insideOrder::NewInsideOrder(){
	Menu mtemp;
	Control tem;
	srand((unsigned)time(NULL));  //以时间为种
	SetOrderNumb(rand()%(9999-1000+1)+10000);  //以时间为种随机生成订单编号 
	int choice;
	int n=1;
	cout<<"请依次输入："<<endl;
		cout<<"是否为会员：（输入1是，输入其他则不是）";
		cin>>choice;
		setVip(choice);
    	cout<<"桌号：";
		setDesknumb();
		cout<<"包厢费：";
		setDeskfee();
		mtemp.setMenu();
		mtemp.printItem();
		cout<<"菜单如上，请要点菜品的输入编号、份数。" <<endl;
		for(;n!=0;){
			int n1,c1;
			cin>>n1>>c1;
			if (n1>tem.returnItemCount()||n1<1){
				cout<<"没有这个编号的菜品！"<<endl; 
			}
			else {
				dishnc.insert(pair<int,int>(n1,c1));
			}
			cout<<"还要继续点菜吗？（输入1继续/0结束点餐）"; 
			cin>>n;
		}
		CDate ctime;  //get time
		string strTime=ctime.format("ddd");  //define a new string as the name of .txt
		strTime=strTime+'i'+'n'+'.'+'t'+'x'+'t';  //finish string
		//ifstream takeoutfile(strTime.c_str());
		ofstream insidefile;
			/*将内存中数据写入磁盘txt文件中*/ 
			insidefile.open(strTime.c_str(),ios::app);   
			insidefile<<GetOrderNumb()<<"	";  //output number of order 
			map<int,int>::iterator it;  //iterator
			double temprice=0;  //price of this order
			for (it=dishnc.begin();it!=dishnc.end();it++){
				insidefile<<it->first;   //number of dish
				insidefile<<",";
				insidefile<<it->second;  //copy of dish
				insidefile<<" ";
			}
			insidefile<<"	";
			insidefile<<getDesknumb()<<"	";  //Desknumb
			insidefile<<getDeskfee()<<"	";  //Deskfee
			for (it=dishnc.begin();it!=dishnc.end();it++){
				for (int i=1;i<tem.returnItemCount();i++){
					if(it->first==i){
						temprice+=(it->second)*mtemp.returnPrice(i);   //copy*price 
					}
				}
			}
			
			if (getidentity()){
				temprice*=0.8;
				temprice+=getDeskfee();
				insidefile<<temprice;  //discount if is vip
			}
			else {
				temprice+=getDeskfee();
				insidefile<<temprice;  //isn't vip
			}
			insidefile<<endl;
	   		insidefile.close();
       		cout<<"  此堂食订单创建成功！优惠后总价为"<<temprice<<"元"<<endl<<endl;
}

void insideOrder::deleteInsideOrder(){
	CDate ctime;  //get time
	string strTime=ctime.format("ddd");  //define a new string as the name of .txt
	strTime=strTime+'i'+'n'+'.'+'t'+'x'+'t';  //finish string
	
	fstream printfile(strTime.c_str(),ios::in|ios::out);
    string line;
    if(printfile.fail()){
    cerr<<"找不到堂食订单文件！"<<endl;
    }
    else 
	{
		cout<<"今日堂食订单如下："<<endl; 
		cout<<"编号  菜品及份数	桌号	包厢费	总价"<<endl; 
		while(getline(printfile,line))
    	cout<<line<<endl;
		printfile.close(); 
		
    	
		ifstream file(strTime.c_str());
    	
    	int n, count = 0;
    	ofstream outfile("temp.txt", ios::out | ios::trunc);
    	cout << "请输入要删除订单的行数:" << endl;
    	cin >> n;
    	while (!file.eof()) {
        	getline(file, line);
        	if (count != n - 1)  //要修改内容就在这修改line的内容,再存到文件中就行了
            	outfile << line << endl;
        	count++;
    	}
    	outfile.close();
    	file.close();
    	ofstream outfile1(strTime.c_str(), ios::out | ios::trunc);
    	fstream file1("temp.txt");
    	while (!file1.eof()) {
        	getline(file1, line);
           	outfile1 << line <<endl;
        
    	}
       	outfile1.close();
    	file1.close();
    	system("del temp.txt");//删除中间文件
    	cout<<"删除成功！"<<endl;
   	}
}

