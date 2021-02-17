#include "Google2FA.h"
#include <iostream>
#include <string>
#include <time.h>

extern "C" {
	#include "tiny2fa/tiny2fa.h"
}

int Google2FA::getKey(const WString& key)
{
	size_t conv;
	uint8_t sk[32];
	wcstombs_s(&conv, (char *)sk, key.Length() + 1, key.Buffer(), _TRUNCATE);
	//sk[key.Length()] = '\0';
	int code = t2_get_key(sk, time(NULL));
	return code;
}