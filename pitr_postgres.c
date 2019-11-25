#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;

	//while() {
	printf("0 - Sair\n");
	printf("1 - Fazer backup do cluster\n");

	scanf("%d", &n);
	//if(n == 0) break;
	if(n == 1){
		if(!system("find db_file_backup -type d -empty")) {
			printf("O backup já foi criado anteriormente\n");
		}
		else {
			system("pg_basebackup -Ft -D /var/lib/postgresql/db_file_backup");
		}
	}
	else if(n == 2)

	//}

	return 0;
}
