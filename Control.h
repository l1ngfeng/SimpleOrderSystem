#ifndef CONTROL_H
#define CONTROL_H
#include"Order.h"
#include <iostream>
using namespace std; 
class Control
{
public:
  	void Notice();  //the function of disply system notice
  	void mainPrinter();  //the printer which display in the beginning of system
  	void modifyNotice();  //modify notice
	void countOrder();  //count all orders
  	int returnItemCount();  //return count of dish/item
  	//int deleteBlankLine(string file);  //from  https://blog.csdn.net/u014546553/article/details/53469447 
private:
  	
};
#endif
