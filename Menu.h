#ifndef MENU_H
#define MENU_H
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<iterator>
#include<iomanip>
#include<stdlib.h>
#include<ctime>
#include<time.h>
#include<windows.h>
#include<cstdlib>

using namespace std; 
typedef struct{
	int id;   //the id of dishes 
	string name;  //the name of dishes
	double price;   //the price of dishes
	//bool ifdelete;  //flag of delete or not
}MenuItem;   //the define of the menu's item  

class Menu
{
private:
  	
public:
	vector<MenuItem> item;  //item vector 
  	void setMenu();  //set the menu when at the lunch of system
  	void printItem();  //display all the menu items
  	void insertItem();  //insert new items 
  	void deleteItem();  //delete the item that exist
   	void modifyItem();   //functions of modify item
  	void searchItem();  //function of searching
	double returnPrice(int id); //id return price
	friend ostream& operator<<(ostream& os,MenuItem &kk);
};

#endif
