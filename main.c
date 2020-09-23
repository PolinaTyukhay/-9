#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#define UNLEN 256
#define SIZE 1024

int main() {



	struct tm newtime;
	char am_pm[] = "AM";
	__time64_t long_time;
	char timebuf[26];
	errno_t err;

	// Get time as 64-bit integer.
	_time64(&long_time);
	// Convert to local time.
	err = _localtime64_s(&newtime, &long_time);
	if (err)
	{
		printf("Invalid argument to _localtime64_s.");
		exit(1);
	}
	
	char us_name[UNLEN ], comp_name[UNLEN]; // буфер
	DWORD us_size, comp_size; // размер 
	us_size = sizeof(us_name); // размер буфера
	GetUserNameA(us_name, &us_size);
	comp_size = sizeof(comp_name);
	GetComputerNameA(comp_name, &comp_size);
	printf("Username: %s\n", us_name);
	printf("Computer Name: %s\n", comp_name);
	printf("time:%02d:%02d\n", newtime.tm_hour, newtime.tm_min);
	printf("date:%4d-%02d-%02d\n", newtime.tm_year+1900, newtime.tm_mon+1, newtime.tm_mday);



}