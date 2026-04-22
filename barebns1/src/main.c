#include <stdio.h>
#include <crocon.h>

int main() {
	
	CROCVERSION crocon_ver;
	int crocon_result;
	
	crocon_result = crocon_getver(&crocon_ver);
	
	printf("\r\nCrocon Test Application\r\n");
	printf(
		"Version: %d.%d.%d\r\n\r\n", 
		crocon_ver.major, crocon_ver.minor, crocon_ver.patch
	);
	
	crocon_initscr();
	crocon_settitle("Crocon Test Application");
	return 0;
}
