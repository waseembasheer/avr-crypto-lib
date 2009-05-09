/* hfal_blake_large.c */
/*
    This file is part of the AVR-Crypto-Lib.
    Copyright (C) 2008  Daniel Otte (daniel.otte@rub.de)

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
/**
 * \file     hfal_blake_large.c
 * \email    daniel.otte@rub.de
 * \author   Daniel Otte 
 * \date     2009-05-08
 * \license  GPLv3 or later
 * 
 */

#include <avr/pgmspace.h>
#include <stdlib.h>
#include "hashfunction_descriptor.h"
#include "blake_large.h"


static const char blake48_str[]   PROGMEM = "Blake-48";
static const char blake64_str[]   PROGMEM = "Blake-64";

const hfdesc_t blake48_desc PROGMEM = {
	HFDESC_TYPE_HASHFUNCTION,
	0,
	blake48_str,
	sizeof(blake48_ctx_t),
	BLAKE48_BLOCKSIZE,
	384,
	(hf_init_fpt)blake48_init,
	(hf_nextBlock_fpt)blake48_nextBlock,
	(hf_lastBlock_fpt)blake48_lastBlock,
	(hf_ctx2hash_fpt)blake48_ctx2hash,
	(hf_free_fpt)NULL,
	(hf_mem_fpt)blake48
};

const hfdesc_t blake64_desc PROGMEM = {
	HFDESC_TYPE_HASHFUNCTION,
	0,
	blake64_str,
	sizeof(blake64_ctx_t),
	BLAKE64_BLOCKSIZE,
	512,
	(hf_init_fpt)blake64_init,
	(hf_nextBlock_fpt)blake64_nextBlock,
	(hf_lastBlock_fpt)blake64_lastBlock,
	(hf_ctx2hash_fpt)blake64_ctx2hash,
	(hf_free_fpt)NULL,
	(hf_mem_fpt)blake64
};


