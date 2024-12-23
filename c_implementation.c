#include <stddef.h>

int add_array(int * array_1, int * array_2 , int * result, int len){
	if(array_1 == NULL || array_2 == NULL || result == NULL)
		return -1; 
	if(len <= 0)
		return len; 
	
	int * end = array_1 + len; 
	while(array_1 != end){
		*result++ = (*array_1 ++) + (*array_2 ++); 
	}
	return len; 
}

int main(void){
	int array_1[4] = {1,2,3,4};
	int array_2[4] = {4,3,2,1}; 
	int result[4] = {0,0,0,0}; 
	add_array(array_1, array_2, result, 4);  
}
