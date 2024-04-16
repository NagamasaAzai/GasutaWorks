//Включение бибилиотек
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
//функция программы
int main(int argc, char *argv[], char *envp[]) {
//обьявление переменных
	 int result1;
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
	 result1 = execle("/bin/cat", "/bin/cat", "otchet_16_04_2024.txt", 0, envp);
         //printf выполняется только в случае ошибки вызова
         printf("Ошибка при выполнении системного вызова execle()\n");
         exit(-1);
	}
	else {
		a = a + 555;
	 	procid = getpid(); //получение идентификатора тек.процесса
         	parentid = getppid(); //получение иентификатора род.процесса
         	printf("Идентификатор процесса: %d, Ид.родителя: %dб значение переменной a: %d\n",procid, parentid, a);
	}
         return 0;
}
