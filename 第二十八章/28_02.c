#include <stdio.h>
#include <stdio.h>
#include <threads.h>
#include <stdatomic.h>

clock_t start_time, end_time;
double total_time;
_Atomic long piece_counter = 0;

int func_in_one(long long arg)
{
	long counter = 0;
	for(long long i = 0; i < arg; i++)
		{
			int judge = 0;
			long long temp = i;
			do{
				judge += temp%10;
			}while((temp /= 10) > 0);
			if(judge%2 != 0) counter++;
		}
	printf("Total counter by one function: %ld.\n",counter);
	return 0;
}
int func_in_piece(void* arg)
{
	for(long long i = (long long)arg; i < (long long)arg * 10; i++)
		{
			int judge = 0;
			long long temp = i;
			do{
				judge += temp % 10;
			}while((temp /=10 ) > 0);
			if(judge%2 != 0) piece_counter++;
		}
	return 0;
}
int main(void)
{
	start_time = clock();
	func_in_one(1000000000ll);
	end_time = clock();
	total_time = difftime(end_time, start_time);
	printf("Total time spend in one function: %lf.\n",total_time);

	thrd_t t0, t1, t2, t3, t4, t5, t6, t7, t8, t9;
	start_time = clock();
	thrd_create(&t0,func_in_piece,1);
	thrd_create(&t1,func_in_piece,10);
	thrd_create(&t2,func_in_piece,100);
	thrd_create(&t3,func_in_piece,1000);
	thrd_create(&t4,func_in_piece,10000);
	thrd_create(&t5,func_in_piece,100000);
	thrd_create(&t6,func_in_piece,100000);
	thrd_create(&t7,func_in_piece,1000000);
	thrd_create(&t8,func_in_piece,10000000);
	thrd_create(&t9,func_in_piece,100000000);
	thrd_join(t0, &(int){0});
	thrd_join(t1, &(int){0});
	thrd_join(t2, &(int){0});
	thrd_join(t3, &(int){0});
	thrd_join(t4, &(int){0});
	thrd_join(t5, &(int){0});
	thrd_join(t6, &(int){0});
	thrd_join(t7, &(int){0});
	thrd_join(t8, &(int){0});
	thrd_join(t9, &(int){0});
	end_time = clock();
	total_time = difftime(end_time, start_time);
	printf("Total counter by multi thread: %ld.\n",piece_counter);
	printf("Total time spend by multi threads: %lf.\n",total_time);

}}
