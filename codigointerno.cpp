#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

using namespace std;

int main () {
	time_t tempo_real;
	tempo_real = time( (time_t *) 0);

	cout << "0" << endl;
	sleep(14);
	pid_t filhoUm;
	filhoUm = fork();
	switch(filhoUm) {
	case -1:
		return 0;
		break;
	case 0:
		cout << "1" << endl;
		sleep(12);
		pid_t netoUm;
		netoUm = fork();
		switch(netoUm) {
		case -1:
			return 0;
			break;
		case 0:
			cout << "3" << endl;
			sleep(12);
			cout << "8" << endl;
			return 0;
			break;
		default:
			break;
		}
		sleep(18);
		cout << "6" << endl;
		return 0;
		break;
	default:
		sleep(2);
		pid_t filhoDois;
		filhoDois = fork();
		switch(filhoDois) {
		case -1:
			return 0;
			break;
		case 0:
			cout << "2" << endl;
			sleep(14);
			pid_t netoDois;
			netoDois = fork();
			switch(netoDois) {
			case -1:
				return 0;
				break;
			case 0:
				cout << "4" << endl;
				sleep(18);
				cout << "9" << endl;
				return 0;
				break;
			default:
				break;
			}
			sleep(16);
			cout << "7" << endl;
			return 0;
			break;
		default:
			break;
		}
		sleep(44);
		cout << "5" << endl;
		break;
	}
}
