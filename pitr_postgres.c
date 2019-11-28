#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int n;
	int i = 0;

	//while() {
	printf("0 - Sair\n");
	printf("1 - Backup\n");
	printf("2 - Restaurar.\n");
	printf("3 - Dump\n");

	scanf("%d", &n);
	//if(n == 0) break;
	if(n == 1) {
		if(!system("find db_file_backup -type d -empty")) {
			printf("O backup já foi criado anteriormente.\n");
		}
		else {
			system("pg_basebackup -Ft -D /var/lib/postgresql/db_file_backup");
		}
	}
	else if(n == 2) {
		system("tar xvf /var/lib/postgresql/db_file_backup/base.tar -C /var/lib/postgresql/11/main/");
		system("tar xvf /var/lib/postgresql/db_file_backup/pg_wal.tar -C /var/lib/postgresql/11/main/pg_wal/");
	}
	else if(n == 3) {
		while(n == 3) {
			system("pg_dumpall > db.out");
			printf("Realizando dumpall.\n");
			system("sleep 1");
			i += 1;
			if(i == 10) {
				printf("Ctrl + C para pausar e digite qualquer valor para finalizar.\n");
				system("PAUSE");
				//system("sleep 5") && 
				scanf("%d", &n);
				i = 0;
			}
		}
	}

	//}

	return 0;
}
