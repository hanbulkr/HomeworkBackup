#include "sem.h"

int main(void){
	int sid;
	
	//semaphore id
	sid = CreateSEM(0x777);

	printf("before\n");
	printf("%d\n",sid);
	p(sid);

	printf("Enter Critical Section\n");

	getchar();
	
	v(sid);

	printf("after\n");

	return 0;

}
