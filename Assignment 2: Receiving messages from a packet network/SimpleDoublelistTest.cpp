#include <iostream>
#include <string>

#include "double_list.h"

int main(void){   // simple program to test the single_list implementation
	double_list *my_list = new double_list();
	d_list_elem *elem1, *elem2, *elem3, *elem4, *elem5, *elem6, *elem7, *elem8;
	
	elem1 = new d_list_elem(1,1,"Hana");
	elem2 = new d_list_elem(2,2,"Doo");
	elem3 = new d_list_elem(3,3,"Set");
	elem4 = new d_list_elem(4,4,"Net");
	elem5 = new d_list_elem(5,5,"Daseot");
	elem6 = new d_list_elem(6,6,"Yeoseot");
	elem7 = new d_list_elem(7,7,"Ilgop");
	elem8 = new d_list_elem(8,8,"Yeodeolp");
	
	my_list->d_list_insert_front(elem1);
	my_list->d_list_insert_before(elem1, elem2);
	my_list->d_list_insert_after(elem2, elem3);
	my_list->d_list_insert_after(elem1, elem4);
	my_list->d_list_insert_front(elem5);
	my_list->d_list_replace(elem1, elem6);
	my_list->d_list_insert_after(elem2, elem7);
	my_list->d_list_remove(elem3);
	std::cout << my_list->d_list_get_data1(elem2) << std::endl;
	std::cout << my_list->d_list_get_data2(elem6) << std::endl;
	
	d_list_elem* curr;
	curr =  my_list->d_list_head();	
	while(curr != NULL){
		std::cout << my_list->d_list_get_data1(curr) << std::endl;
		std::cout << my_list->d_list_get_data2(curr) << std::endl;
		std::cout << my_list->d_list_get_data3(curr) << std::endl;
		curr = my_list->d_list_next(curr);
	}
}
