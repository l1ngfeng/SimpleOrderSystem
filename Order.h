#ifndef ORDER_H
#define ORDER_H
#include"Menu.h"
#include"date.h"
#include <map>
class order{
private:
	int orderNumb;   //number of the order		
	double totalPrice;   //the totalprice of this order
	bool vip;  //is vip or not 
public:
	map<int,int>dishnc; //number and copy of dishes 
	int SetOrderNumb(int n){
		orderNumb=n;
	}
	int GetOrderNumb(){
	   	return orderNumb;
	}
	double Gettotalprice(){
		return totalPrice;
	}
	bool setVip(int n){
	    if(n==1){
    	vip=true;
		}else{
		vip=false;
		}
	}
	bool getidentity(){
		if(vip){
		return true;
		}else{
		return false;
		}
	}
};

class insideOrder:public order{
private:
	int desknumb;  //the number of desk
	double deskfee;   //deskfee
public:
	void NewInsideOrder();  //new order
	void deleteInsideOrder(); //------------------------------- 
	void setDesknumb(){
		int desknumbtemp;
		cin>>desknumbtemp;
		desknumb=desknumbtemp;
	}
	void setDeskfee(){
		int Deskfeetemp;
		cin>>Deskfeetemp;
		deskfee=Deskfeetemp;
	}
	int getDesknumb(){
		return desknumb;
	}
	double getDeskfee(){
		return deskfee;
	}
};

class TakeOutOrder:public order{
private:
	string phoneNumb;
	string dtime;
	string location;		
public:
	void NewTakeOutOrder();  //new order
	void deleteTakeOutOrder(); //----------------------------------- 
	void setPhoneNumb(){
		string phonetemp;
		cin>>phonetemp;
		phoneNumb=phonetemp;
	}
	void setLocation(){
		string ltemp;
		cin>>ltemp;
		location=ltemp;
	}
	void setTime(){
		string timetemp;
		cin>>timetemp;
		dtime=timetemp;
	}
	string getTime(){
		return dtime;
	}
	string getLocation(){
		return location;
	}
	string getPhonenumb(){
		return phoneNumb;
	}
};
#endif
