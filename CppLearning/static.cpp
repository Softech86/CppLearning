#include <cstdio>
#include <cstdlib>

int fun() {
	static int count = 10; //�־û��洢
	return count--;
}

int c = 1;

int main() {
	for (int c = 1; c <= 5; ++c)
		printf("%d %d\n", c, fun());
	system("pause");
	return 0;
}