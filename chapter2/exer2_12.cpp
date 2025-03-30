//实现任意输入字长w的整数
//sizeof(x)计算x的字节数，*8得到位数，最后/4得到十六进制数字的个数

#include <stdio.h>

int main(){
	unsigned x;
	scanf("%x",&x);

	int w = sizeof(x) * 8;
	//A
	unsigned A = x & 0xFF;
	printf("0x%0*X\n", w / 4, A);
	//B
	unsigned B = ((~(x & 0xFFFFFF00)) | (x & 0xFF));
	printf("0x%0*X\n", w / 4, B);
	//C
	unsigned C = (x | 0xFF);
	printf("0x%0*X\n", w / 4, C);
	return 0;
}
