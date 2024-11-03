/*
 * my_menu_structure.c
 *
 *  Created on: Mar 6, 2024
 *      Author: brzan
 */
#include "my_menu_structure.h"

/**************************************** STRUCTURE ****************************************/
/**
 * @brief			This is the place where you can define your menu structure by creating
 *					menu_t elements and assigning appropriate pointers to the structures.
 *
 *		menu_t {*name, *next, *prev, *goto, *data, (*menu_fcn)}
 *
 * @member	char *name		the text string that is displayed on screen 0-13 characters
 * @member	menu_t *next	pointer to the next menu_t element, one below the other, may be left NONE
 * @member	menu_t *prev	pointer to the previous menu_t element, may be left NONE
 *
 * @info					next three pointers: go_to, data, menu_fcn
 * 							shouldn't be initialized at once!
 * @member	menu_t *go_to	pointer to any menu_t element, preferably usage is about jumping to
 * 							next layer of menu or return from a higher layer to previous.
 * @member m_data_t *data	pointer to data structure
 * @member (void)(*function)
 *
 * @info			Remember to declare menu_t elements in my_menu_structure.h
 */

menu_t MM1 = {"A menu",			&MM2, NULL, NULL, NULL, NULL};
menu_t MM2 = {"B menu",			&MM3, &MM1, NULL, NULL, NULL};
menu_t MM3 = {"C menu",			&MM4, &MM2, NULL, NULL, NULL};
menu_t MM4 = {"RTC settings",	NULL, &MM3, &RTCS1, NULL, NULL};

menu_t RTCS1 = {"Return",				&RTCS2,	NULL, 	&MM4,	NULL,		NULL};
menu_t RTCS2 = {"new Hour",				&RTCS3,	&RTCS1,	NULL,	&RTCS2D,	NULL};
menu_t RTCS3 = {"new Min",				&RTCS4,	&RTCS2,	NULL,	&RTCS3D,	NULL};
menu_t RTCS4 = {"new Sec",				&RTCS5,	&RTCS3,	NULL,	&RTCS4D,	NULL};
menu_t RTCS5 = {"new Date",				&RTCS6,	&RTCS4,	NULL,	&RTCS5D,	NULL};
menu_t RTCS6 = {"new Month",			&RTCS7,	&RTCS5,	NULL,	&RTCS6D,	NULL};
menu_t RTCS7 = {"new Year",				&RTCS8,	&RTCS6,	NULL,	&RTCS7D,	NULL};
static void set_the_time_function(void);
menu_t RTCS8 = {"Apply new time -f",	NULL,	&RTCS7,	NULL,	NULL,		&set_the_time_function};

/**************************************** NUMERIC ****************************************/
/**
 *	@note 			This menu will work only with int data type for now,
 * 					int range is +/- 2,147,483,647 and it's sufficient.
 *	@brief
 *
 * m_data_t {*data, lower_bound, upper_bound, delta_per_step, * const * aliases}
 *
 * Example data with range [30 90] and increment rate 15:
extern int data;
m_data_t D = {&data, 30, 90, 15, NULL}
 */

static int newHour = 0;
static int newMinute = 0;
static int newSecond = 0;
static int newDate = 17;
static int newMonth = 4;
static int newYear = 2024;

m_data_t RTCS2D = {&newHour, 0, 23, 1, NULL};
m_data_t RTCS3D = {&newMinute, 0, 59, 1, NULL};
m_data_t RTCS4D = {&newSecond, 0, 59, 1, NULL};
m_data_t RTCS5D = {&newDate, 1, 31, 1, NULL};
m_data_t RTCS6D = {&newMonth, 1, 12, 1, NULL};
m_data_t RTCS7D = {&newYear, 2000, 2099, 1, NULL};

#include "my_utilities.h"
static void set_the_time_function(void)
{
	STM_RTC_set_time_and_date((uint8_t)newHour, (uint8_t)newMinute,
			(uint8_t)newSecond, (uint8_t)newMonth,
			(uint8_t)newDate, (uint8_t)(newYear - 2000));
}

/**************************************** ENUM ****************************************/
/**
 *	@brief			For enum it is almost the same as for the numeric data type, you just need
 *					to add aliases that will be displayed on screen, as shown below:
 *
 *	1. Enum should be defined whit aligned(4) attribute and padding:
 *	* __enum_t_padding__ is workaround to get enum stored on 4 bytes instead of 1,
 *	* __attribute__((aligned(4))) does not work, it just makes compiler warning free and happy :D

typedef enum {
	first_member = 0,
	second_member,
	third_member,

	enum_t_max_members,

	__enum_t_padding__ = 0xFFFFFFF0
} enum_t __attribute__((aligned(4)));

 *	2. You declare your enum instance:

(extern) enum_t enum_var_name;

 *	3. You create 'dictionary' that holds ALL enum - string pairs:

const char * const enum_t_aliases[] =
{
	[first_member] = "First member!",
	[second_member] = "Second!",
	[third_member] = "Last member",
};

 *	4. If your enum_t is 'continuus' (it takes all integer values in some range ex. [0 1 2]),
 *	and if your enum_t has additional, last member: enum_t_max_members (equals 3 in our example).
 *	And if you want to be shure that all members have aliases, then you can use:

ASSERT_ENUM_ALIASES(enum_t_aliases, enum_t_max_members)

 *	5. You can finally create m_data_t just like for numbers, just cast pointer to (int*) and
 *	initialize last member with enum_t_aliases, just as shown:

m_data_t m_enum_data = {(int*)&enum_var_name, 0, 2, 1, enum_t_aliases}

 *	6. Now you can pass pointer to m_enum_data to your menu_t element.
 *
 * Explanation of approach implemented: https://stackoverflow.com/a/58500930
 */


//extern hm_state_t hm_state;
//
//const char * const hm_state_aliases[] =
//{
//	[HM_ON] = "ON",
//	[HM_OFF] = "OFF",
//	[HM_AUTO]  = "AUTO",
//};
//ASSERT_ENUM_ALIASES(hm_state_aliases, HM_STATE_T_MAX);
//m_data_t D_E = {(int*)&hm_state, 0, 2, 1, hm_state_aliases};
/* ^ This line, can trigger a warning [-Waddress-of-packed-member] */


//extern AT_commands_t cATcmd;
//extern const char * const AT_commands[];
//
//m_data_t D_ATC = {(int*)&cATcmd, 0, 2, 1, AT_commands};


/**************************************** FUNCTION ****************************************/
/**
 * @brief			At first declare in my_menu_structure.h extern void foo(void);
 * 					and then just use it in initializer.

menu_t M = {"Foo invoke"		, NULL, NULL, NULL, NULL, foo};

 */



