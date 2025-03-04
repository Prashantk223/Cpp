#pragma once

#include "commonAlgos.h"

void memcopy(void* dest, const void* src, size_t size)
{
	if (size != 0 && dest != NULL && src != NULL)
	{
		char* d = (char*)dest;
		const char* s = (const char*)src;
		for (size_t i = 0; i < size; i++)
		{
			d[i] = s[i];
		}
	}
}

void mystrcpy(char* dest, const char* src)
{
	if (dest == NULL || src == NULL)
	{
		return;
	}
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
}

int mystrlen(const char* src)
{
	size_t str_len = 0;
	if (src != NULL)
	{
		while (src != '\0')
		{
			str_len++;
			src++;
		}
	}
	return str_len;
}
