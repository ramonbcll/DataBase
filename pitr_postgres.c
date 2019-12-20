#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;

	while(1) {
		printf("0 - Sair\n");
		printf("1 - Arquivar logs\n");
		printf("2 - Backup full\n");
		printf("3 - Dump\n");

		scanf("%d", &n);
		if(n == 0) break;
		else if(n == 1) {
			system("sudo cp -rfv /var/lib/postgresql/pg_log_archive /home/nti/Documents");
			system("rm /var/lib/postgresql/pg_log_archive/* -r");
			system("psql -c 'select pg_switch_wal();'");
		}
		else if(n == 2) {
			system("rm /var/lib/postgresql/db_file_backup/* -r");
			system("pg_basebackup -Ft -D /var/lib/postgresql/db_file_backup");
			printf("Backup realizado\n");
		}
		else if(n == 3) {
			system("pg_dumpall > db.out");
		}
	}

	return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main() {
	//system("sudo chmod -R 777 /var/lib/postgresql/");
	system("sudo su - postgres");

	return 0;
}
