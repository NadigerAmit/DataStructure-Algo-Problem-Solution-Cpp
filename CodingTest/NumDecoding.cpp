#include <stdio.h>
 
int decode(char* message, int len) {
    int i, currentCount, TotalCount = 1, twoDigitCount = 0;
    for(i = 0, w; i < len; ++i) {
        currentCount = 0;
        if((i > 0) && ((message[i - 1] == '1') || (message[i - 1] == '2' && message[i] < '7'))) {
            currentCount += twoDigitCount;
        }
        if(message[i] > '0') {
            currentCount += TotalCount;
        }
//		printf("\nbefore ways[1] = %d ways[0] = %d ",ways[1],ways[0]);
        twoDigitCount = TotalCount;
        TotalCount= currentCount;
		printf("\ntwoDigitCount = %d SingleDigitCount = %d ",twoDigitCount,SingleDigitCount);
    }
    return TotalCount;
}
 
int main(void) {
	printf("----------0 --------------");
	printf("\n%d\n", decode("0", 1));
	printf("----------1 --------------");
	printf("\n%d\n", decode("1", 1));
	printf("----------10 --------------");
	printf("\n%d\n", decode("10", 2));
	printf("----------101 --------------");
	printf("\n%d\n", decode("101", 2));
	printf("----------1090 --------------");
    printf("\n%d\n", decode("1090", 4));
	printf("----------12321 --------------");
    printf("%d\n", decode("12321", 5));
	printf("----------12327 --------------");
    printf("%d\n", decode("12327", 5));
    return 0;
}