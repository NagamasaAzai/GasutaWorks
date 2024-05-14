#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
int a = 0;  //инициализация глобальной стат.переменной, доступной из каждого thread'a
//функция, выполняющаяся в рамках второго thread'a 
void *mythread(void *dummy){
	pthread_t mythid; //идентификатор thread'a для каждого имеет свое значение 
	mythid = pthread_self(); //вызов для создания thread'a 
	a = a+1;
	printf("Thread %ld, Результат вычисления a = %d\n", mythid, a); //печать идентификатора текущего thread'a и значения результатов глобальной переменной
	return NULL;
}

int main() {
	pthread_t thid, mythid;
	int result;
	result = pthread_create(&thid, (pthread_attr_t *)NULL, mythread, NULL); //создание нового thread'a  при помощи вызова функции mythread 
	if(result != 0) {
		printf("Ошибка при создании нового thread\'a, возвращенное значение = %d\n", result);
		exit(-1);
	}
	printf("thread создан, thid = %ld\n", thid);
	mythid = pthread_self(); //сохраняем в переменной mythid индентификатор главного thread'a
	a = a+1;
	printf("Thread %ld, Результат вычисления а = %d\n", mythid, a);
	pthread_join(thid, (void **)NULL); //ожидание завершения порожденного thread'a 
	return 0;
}

