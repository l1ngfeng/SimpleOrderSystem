#include"order.h"
#include "Control.h"
void TakeOutOrder::NewTakeOutOrder(){
	Menu mtemp;
	Control tem;
	srand((unsigned)time(NULL));  //��ʱ��Ϊ��
	SetOrderNumb(rand()%(9999-1000+1)+10000);  //��ʱ��Ϊ��������ɶ������ 
	int choice;
	int n=1;
	cout<<"���������룺"<<endl;
		cout<<"�Ƿ�Ϊ��Ա��������1�ǣ������������ǣ�";
		cin>>choice;
		setVip(choice);
    	cout<<"�ֻ��ţ�";
		setPhoneNumb();
		cout<<"�Ͳ�ʱ�䣺";
		setTime();
		cout<<"�Ͳ͵�ַ��";
		setLocation();
		mtemp.setMenu();
		mtemp.printItem();
		cout<<"�˵����ϣ���Ҫ���Ʒ�������š�������" <<endl;
		for(;n!=0;){
			int n1,c1;
			cin>>n1>>c1;
			if (n1>tem.returnItemCount()||n1<1){
				cout<<"û�������ŵĲ�Ʒ��"<<endl; 
			}
			else {
				dishnc.insert(pair<int,int>(n1,c1));
			}
			cout<<"��Ҫ��������𣿣�����1����/0������ͣ�"; 
			cin>>n;
		}
		CDate ctime;  //get time
		string strTime=ctime.format("ddd");  //define a new string as the name of .txt
		strTime=strTime+'o'+'u'+'t'+'.'+'t'+'x'+'t';  //finish string
		//ifstream insidefile(strTime.c_str());
		ofstream takeoutfile;
			/*���ڴ�������д�����txt�ļ���*/ 
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
       		cout<<"  �˶��������ɹ����Żݺ��ܼ�Ϊ"<<temprice<<"Ԫ"<<endl<<endl;
}

void TakeOutOrder::deleteTakeOutOrder(){
	CDate ctime;  //get time
	string strTime=ctime.format("ddd");  //define a new string as the name of .txt
	strTime=strTime+'o'+'u'+'t'+'.'+'t'+'x'+'t';  //finish string
	
	fstream printfile(strTime.c_str(),ios::in|ios::out);
    string line;
    if(printfile.fail()){
    cerr<<"�Ҳ������������ļ���"<<endl;
    }
    else 
	{
		cout<<"���������������£�"<<endl; 
		while(getline(printfile,line))
    	cout<<line<<endl;
		printfile.close(); 
		
    	
		ifstream file(strTime.c_str());
    	
    	int n, count = 0;
    	ofstream outfile("temp.txt", ios::out | ios::trunc);
    	cout << "������Ҫɾ������������:" << endl;
    	cin >> n;
    	while (!file.eof()) {
        	getline(file, line);
        	if (count != n - 1)  //Ҫ�޸����ݾ������޸�line������,�ٴ浽�ļ��о�����
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
    	system("del temp.txt");//ɾ���м��ļ�
    	cout<<"ɾ���ɹ���"<<endl;
   	}
}

void insideOrder::NewInsideOrder(){
	Menu mtemp;
	Control tem;
	srand((unsigned)time(NULL));  //��ʱ��Ϊ��
	SetOrderNumb(rand()%(9999-1000+1)+10000);  //��ʱ��Ϊ��������ɶ������ 
	int choice;
	int n=1;
	cout<<"���������룺"<<endl;
		cout<<"�Ƿ�Ϊ��Ա��������1�ǣ������������ǣ�";
		cin>>choice;
		setVip(choice);
    	cout<<"���ţ�";
		setDesknumb();
		cout<<"����ѣ�";
		setDeskfee();
		mtemp.setMenu();
		mtemp.printItem();
		cout<<"�˵����ϣ���Ҫ���Ʒ�������š�������" <<endl;
		for(;n!=0;){
			int n1,c1;
			cin>>n1>>c1;
			if (n1>tem.returnItemCount()||n1<1){
				cout<<"û�������ŵĲ�Ʒ��"<<endl; 
			}
			else {
				dishnc.insert(pair<int,int>(n1,c1));
			}
			cout<<"��Ҫ��������𣿣�����1����/0������ͣ�"; 
			cin>>n;
		}
		CDate ctime;  //get time
		string strTime=ctime.format("ddd");  //define a new string as the name of .txt
		strTime=strTime+'i'+'n'+'.'+'t'+'x'+'t';  //finish string
		//ifstream takeoutfile(strTime.c_str());
		ofstream insidefile;
			/*���ڴ�������д�����txt�ļ���*/ 
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
       		cout<<"  ����ʳ���������ɹ����Żݺ��ܼ�Ϊ"<<temprice<<"Ԫ"<<endl<<endl;
}

void insideOrder::deleteInsideOrder(){
	CDate ctime;  //get time
	string strTime=ctime.format("ddd");  //define a new string as the name of .txt
	strTime=strTime+'i'+'n'+'.'+'t'+'x'+'t';  //finish string
	
	fstream printfile(strTime.c_str(),ios::in|ios::out);
    string line;
    if(printfile.fail()){
    cerr<<"�Ҳ�����ʳ�����ļ���"<<endl;
    }
    else 
	{
		cout<<"������ʳ�������£�"<<endl; 
		cout<<"���  ��Ʒ������	����	�����	�ܼ�"<<endl; 
		while(getline(printfile,line))
    	cout<<line<<endl;
		printfile.close(); 
		
    	
		ifstream file(strTime.c_str());
    	
    	int n, count = 0;
    	ofstream outfile("temp.txt", ios::out | ios::trunc);
    	cout << "������Ҫɾ������������:" << endl;
    	cin >> n;
    	while (!file.eof()) {
        	getline(file, line);
        	if (count != n - 1)  //Ҫ�޸����ݾ������޸�line������,�ٴ浽�ļ��о�����
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
    	system("del temp.txt");//ɾ���м��ļ�
    	cout<<"ɾ���ɹ���"<<endl;
   	}
}

