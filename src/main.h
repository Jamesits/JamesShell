#pragma once
#ifndef __MAIN_H__
#define __MAIN_H__

typedef struct shared_config {
	FILE *f_in;
	FILE *f_out;
	FILE *f_err;
	bool shuttingdown;
	int last_return_value;
} shared_config;

extern shared_config config;

#endif /* end of include guard: __MAIN_H__ */
