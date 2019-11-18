#include <stdio.h>
#include "Sig_Creat.c"
	
int main(int argc, char *arg[]){
	uint8_t URL_Str[] = {"b2cgosuncndevicehub.azure-devices.net%2Fdevices%2F860788040858523\n1888127374"};
	uint8_t *URL_String = URL_Str;
	size_t URL_len = strlen(URL_Str);
	printf ("URL_String length is %d\n", URL_len);
	
	uint8_t SAK_Str[] = {"i709gJXkfpzGinJR0JXZL7OGRhhalztBGjOXWPNLTp0="};
	uint8_t *SAK = SAK_Str;
	size_t SAK_len = strlen(SAK_Str);
	printf ("SAK_String length is %d\n", SAK_len);
	
	uint8_t Sig[64] = {""};
	
	Creat_Sig(URL_String, URL_len, SAK, SAK_len, Sig);
	size_t Sig_len = strlen(Sig);
	printf ("Sig_len is %d\n", Sig_len);
	printf("Sig is---->\n%s\n", Sig);
	return 0;
}
