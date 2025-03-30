/* 

int bis(int x, int m);
int bic(int x, int m);

//bis实际上就是or操作：把m 的1 赋给x 上
//bic：把y 的 1位置在x 上变为0 == x & ~y

int bool_or(int x, int y){
	int result = bis(x,y);
	return result;
}

// x^y = (x & ~y) | (~x & y)
int bool_xor(int x, int y){
	int result = bis(bic(x,y), bic(y,x));
	return result;
}

*/

int main(){}
