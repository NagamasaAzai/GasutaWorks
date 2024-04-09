//программа для иллюстрации одинаковой работы процесса родителя и процессов ребенка

//подключение библиотек
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
//функция программы
int main() {
//обьявление переменных
         pid_t procid, parentid; //идентфикаторы процессов
         pid_t result; //результат системного вызова
         int a = 0; //переменная для проверки работы процесса-родителя и ребенка
         result = fork();
	if (result < 0) {
		printf("Error in fork()\n");
		exit(-1);
	}
	else if (result == 0) {
         a = a+1;
	 procid = getpid(); //получение идентификатора тек.процесса
	 parentid = getppid(); //получение иентификатора род.процесса
	 printf("Идентификатор процесса: %d, Ид.родителя: %dб значение переменной a: %d\n",procid, parentid, a);
	}
	else {
		a = a + 555;
	 	procid = getpid(); //получение идентификатора тек.процесса
         	parentid = getppid(); //получение иентификатора род.процесса
         	printf("Идентификатор процесса: %d, Ид.родителя: %dб значение переменной a: %d\n",procid, parentid, a);
	}
         return 0;
}
