#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;

	//while() {
	printf("0 - Sair\n");
	printf("1 - Arquivar logs\n");
	printf("2 - Backup full\n");
	printf("3 - Dump\n");

	scanf("%d", &n);
	//if(n == 0) break;
	if(n == 1) {
		system("sudo cp -Rfv /var/lib/postgresql/11/main/pg_wal/archive_status /Documents");
		system("psql -c 'select pg_switch_wal();'");
	}
	else if(n == 2) {
		system("rm /var/lib/postgresql/db_file_backup/* -r");
		//system("pg_basebackup -Ft -D /var/lib/postgresql/db_file_backup");
		system("pg_basebackup -Ft -D /var/lib/postgresql/backup");
	}
	else if(n == 3) {
		system("pg_dumpall > db.out");
	}

	//}

	return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main() {
	system("sudo chmod -R 750 /var/lib/postgresql/");
	system("sudo su - postgres");

	return 0;
}
