/*
 * Timer0.c
 *
 * Created: 2/24/2023 1:35:06 PM
 *  Author: dell
 */ 

#include "Timer0_Interface.h"


CTC_callback_t CTC_callback_ptr = NULL;
static uint32 comp_count=0;
static uint32 number_of_compare_matches;
static uint64 OV_count0 = 0;

//sets Tmer0 configs (Mode, interrupt)