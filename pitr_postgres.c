#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int n;

	//while() {
	printf("0 - Sair\n");
	printf("1 - Arquivar logs\n");
	printf("2 - Backup\n");
	printf("3 - Restaurar.\n");
	printf("4 - Dump\n");

	scanf("%d", &n);
	//if(n == 0) break;
	if(n == 1) {
		system("psql -c 'select pg_switch_wal();'");
	}
	else if(n == 2) {
		if(!system("find db_file_backup -type d -empty")) {
			printf("O backup já foi criado anteriormente.\n");
		}
		else {
			system("pg_basebackup -Ft -D /var/lib/postgresql/db_file_backup");
		}
	}
	else if(n == 3) {
		system("tar xvf /var/lib/postgresql/db_file_backup/base.tar -C /var/lib/postgresql/11/main/");
		system("tar xvf /var/lib/postgresql/db_file_backup/pg_wal.tar -C /var/lib/postgresql/11/main/pg_wal/");
	}
	else if(n == 4) {
		system("pg_dumpall > db.out");
	}

	//}

	return 0;
}
