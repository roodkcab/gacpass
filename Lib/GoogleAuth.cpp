#include "GoogleAuth.h"
#include "util.hpp"

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <openssl/hmac.h>
#include <openssl/evp.h>
#include <time.h>
#include <math.h>
#include <cstring>
#include <string>
#include <stdint.h>
#include <stdlib.h>

GoogleAuth::GoogleAuth(const ::vl::WString& key)
{
	size_t conv;
	wcstombs_s(&conv, this->key, key.Length() + 1, key.Buffer(), _TRUNCATE);
}

::vl::WString GoogleAuth::getCode()
{
	time_t utime = this->getTime();
	uint8_t* hash;
	uint32_t result;
	uint64_t offset;
	uint32_t truncH;

    uint8_t* key32 = (uint8_t*)this->key;
    size_t len = strlen(this->key);
    size_t key32_len = this->decode(&key32, len);
	hash = (uint8_t*)HMAC(EVP_sha1(), key32, key32_len, (const unsigned char*)&utime, sizeof(utime), NULL, 0);
	offset = hash[19] & 0x0f;
	truncH = (hash[offset] & 0x7f) << 24 | (hash[offset + 1] & 0xff) << 16 | (hash[offset + 2] & 0xff) << 8 | (hash[offset + 3] & 0xff);
	result = truncH % 1000000;
	char strNum[64];
	sprintf_s(strNum, 64, "%06d", result);
	return ::vl::WString(String2WString(strNum).c_str());
}

time_t GoogleAuth::getTime()
{
	time_t utime = (floor((unsigned long)time(NULL) / 30));
	uint32_t endian = 0xdeadbeef;

	if ((*(const uint8_t*)&endian) == 0xef) {
		utime = ((utime & 0x00000000ffffffff) << 32) | ((utime & 0xffffffff00000000) >> 32);
		utime = ((utime & 0x0000ffff0000ffff) << 16) | ((utime & 0xffff0000ffff0000) >> 16);
		utime = ((utime & 0x00ff00ff00ff00ff) << 8) | ((utime & 0xff00ff00ff00ff00) >> 8);
	};

	return utime;
}

size_t GoogleAuth::decode(uint8_t** key32, size_t len)
{
	size_t keylen;
	size_t pos;
	keylen = 0;
	for (pos = 0; pos <= (len - 8); pos += 8)
	{
		(*key32)[keylen + 0] = (this->base32_vals[(*key32)[pos + 0]] << 3) & 0xF8; // 5 MSB
		(*key32)[keylen + 0] |= (this->base32_vals[(*key32)[pos + 1]] >> 2) & 0x07; // 3 LSB
		if ((*key32)[pos + 2] == '=') {
			keylen += 1;
			break;
		}

		//byte 1
		(*key32)[keylen + 1] = (this->base32_vals[(*key32)[pos + 1]] << 6) & 0xC0; // 2 MSB
		(*key32)[keylen + 1] |= (this->base32_vals[(*key32)[pos + 2]] << 1) & 0x3E; // 5  MB
		(*key32)[keylen + 1] |= (this->base32_vals[(*key32)[pos + 3]] >> 4) & 0x01; // 1 LSB
		if ((*key32)[pos + 4] == '=') {
			keylen += 2;
			break;
		}

		//byte 2
		(*key32)[keylen + 2] = (this->base32_vals[(*key32)[pos + 3]] << 4) & 0xF0; // 4 MSB
		(*key32)[keylen + 2] |= (this->base32_vals[(*key32)[pos + 4]] >> 1) & 0x0F; // 4 LSB
		if ((*key32)[pos + 5] == '=') {
			keylen += 3;
			break;
		}

		//byte 3
		(*key32)[keylen + 3] = (this->base32_vals[(*key32)[pos + 4]] << 7) & 0x80; // 1 MSB
		(*key32)[keylen + 3] |= (this->base32_vals[(*key32)[pos + 5]] << 2) & 0x7C; // 5  MB
		(*key32)[keylen + 3] |= (this->base32_vals[(*key32)[pos + 6]] >> 3) & 0x03; // 2 LSB
		if ((*key32)[pos + 7] == '=') {
			keylen += 4;
			break;
		}

		//byte 4
		(*key32)[keylen + 4] = (this->base32_vals[(*key32)[pos + 6]] << 5) & 0xE0; // 3 MSB
		(*key32)[keylen + 4] |= (this->base32_vals[(*key32)[pos + 7]] >> 0) & 0x1F; // 5 LSB
		keylen += 5;
	}
	(*key32)[keylen] = 0;

	return keylen;
}
