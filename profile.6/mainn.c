#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int testa[2] = {1, 2};
int *g_testa[2] = {&testa[0], &testa[1]};

int * test(void)
{
	return g_testa[0];
}


int main()
{
    int  *& ptr = test();
    cout<<"ptr: "<<ptr<<", g_testa[0]:"<<g_testa[0]<<endl;
    ptr = nullptr;	 	 
    cout<<"ptr: "<<ptr<<", g_testa[0]:"<<g_testa[0]<<endl;
    return 0;
}
