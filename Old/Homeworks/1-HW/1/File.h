#pragma once
#include "Date.h"
#include "constants.h"

struct File {
	size_t size;
	Date createdTime;
	Date mtime;
	char name[NAME_LENGHT];
	char content[CONTENT_LENGHT];
	char perms[PERMS_LENGHT];
};