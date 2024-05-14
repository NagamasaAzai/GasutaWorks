#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>
int main() {
	int semid; //Иденфикатор ипс для массива семафоров
	char pathname[] = "forftok.ipc"; //файл, используемый для генерациии\ ипс-ключа
	key_t key; //ипс-ключ
	struct sembuf mybuf; //структура для задания операциии над семафором
	//генерация ипс-ключа
	if((key = ftok(pathname, 0)) < 0) {
		printf("Не удалось сгененрировать ipc-ключ\n");
		exit(-1);
	}
	//получение доступа к массиву семафоров по ипс-ключу
	if((semid = semget(key, 1, 0666 | IPC_CREAT)) < 0) {
		printf("Не удалось получить доступ к массиву семафоров\n");
		exit(-1);
	}
	//заполняем структуру mybuf кодами операции над семафором
	mybuf.sem_op = -1;
	mybuf.sem_flg = 0;
	mybuf.sem_num = 0;
	//выполнение операций
	if(semop(semid, &mybuf, 1) < 0) {
		printf("Не удалось выполнить операцию над семафором 0\n");
		exit(-1);
	}
	printf("Условие установлено\n");
	return 0;
}
