#include <stdio.h>
#include "base64.c"
#include "hmac_sha256.c"
#include "URL_en.c"

void Creat_Sig(uint8_t *URL_String, size_t URL_len, uint8_t *SAK, size_t SAK_len, uint8_t Sig[]){
	size_t SAK_base64_size;
	if((SAK_len%3)==0){
		SAK_base64_size = (SAK_len/3)*4;
	} else {
		SAK_base64_size = (SAK_len/3+1)*4;
	}
	
	uint8_t SAK_base64[SAK_base64_size];
	size_t SAK_base64_len = base64_decode(SAK, SAK_base64, strlen(SAK));
 	
 	uint8_t Sig_base64[32];
 	hmac_sha256 (Sig_base64, URL_String, URL_len, SAK_base64, SAK_base64_len);
 	
 	size_t Sig_len;
 	Sig_len = base64_encode(Sig_base64, Sig, 32, 1);

 	urlencode(Sig);
}

