//Включение бибилиотек
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
//функция программы
int main(int argc, char *argv[], char *envp[]) {
	int result;
	//Запуск программы с аргументом otchet_16_04_2024.txt
	result = execle("/bin/cat", "/bin/cat", "otchet_16_04_2024.txt", 0, envp);
	//printf выполняется только в случае ошибки вызова
	printf("Ошибка при выполнении системного вызова execle()\n");
	exit(-1);
	return 0; //никогда не выполняется
}
