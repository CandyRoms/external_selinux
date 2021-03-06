/* Copyright (C) 2005 Red Hat, Inc. */

struct semanage_bool;
struct semanage_bool_key;
typedef struct semanage_bool_key record_key_t;
typedef struct semanage_bool record_t;
#define DBASE_RECORD_DEFINED

#include "boolean_internal.h"
#include "handle.h"
#include "database.h"

int semanage_bool_set_active(semanage_handle_t * handle,
			     const semanage_bool_key_t * key,
			     const semanage_bool_t * data)
{

	dbase_config_t *dconfig = semanage_bool_dbase_active(handle);
	return dbase_set(handle, dconfig, key, data);
}

int semanage_bool_query_active(semanage_handle_t * handle,
			       const semanage_bool_key_t * key,
			       semanage_bool_t ** response)
{

	dbase_config_t *dconfig = semanage_bool_dbase_active(handle);
	return dbase_query(handle, dconfig, key, response);
}

int semanage_bool_exists_active(semanage_handle_t * handle,
				const semanage_bool_key_t * key, int *response)
{

	dbase_config_t *dconfig = semanage_bool_dbase_active(handle);
	return dbase_exists(handle, dconfig, key, response);
}

int semanage_bool_count_active(semanage_handle_t * handle,
			       unsigned int *response)
{

	dbase_config_t *dconfig = semanage_bool_dbase_active(handle);
	return dbase_count(handle, dconfig, response);
}

int semanage_bool_iterate_active(semanage_handle_t * handle,
				 int (*handler) (const semanage_bool_t * record,
						 void *varg), void *handler_arg)
{

	dbase_config_t *dconfig = semanage_bool_dbase_active(handle);
	return dbase_iterate(handle, dconfig, handler, handler_arg);
}

int semanage_bool_list_active(semanage_handle_t * handle,
			      semanage_bool_t *** records, unsigned int *count)
{

	dbase_config_t *dconfig = semanage_bool_dbase_active(handle);
	return dbase_list(handle, dconfig, records, count);
}
