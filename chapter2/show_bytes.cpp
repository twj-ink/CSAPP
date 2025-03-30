#include <stdio.h>
#include <cstring>

typedef unsigned char* byte_pointer;

void show_bytes(byte_pointer start, size_t len){
	for (size_t i=0;i<len;i++){
		printf("%.2x",start[i]);
		printf("\n");
	}
	printf("\n");
}

void show_int(int x){
	show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x){
	show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x){
	show_bytes((byte_pointer) &x, sizeof(void *));
}

void tests(int val){
	int ival = val;
	float fval = (float) ival;
	int *pval = &ival;
	show_int(ival);
	show_float(fval);
	show_pointer(pval);
}

int main(){
	/* int s = 12345;
	tests(s);
	return 0; */

	/* int val = 0x87654321;
	byte_pointer valp = (byte_pointer)&val;
	show_bytes(valp,1);
	show_bytes(valp,2);
	show_bytes(valp,3);
	return 0; */

	const char * s = "12345";
	show_bytes((byte_pointer)s, strlen(s));
	printf("\n");
	int val = 0x12345;
	show_bytes((byte_pointer)&val, 3);
	return 0;
}

