/*
 * my_menu_structure.h
 *
 *  Created on: Mar 6, 2024
 *      Author: brzan
 */

#ifndef INC_MY_MENU_STRUCTURE_H_
#define INC_MY_MENU_STRUCTURE_H_

#include "my_menu.h"

/* main menu */
menu_t MM1, MM2, MM3, MM4;

// TODO update menu init fucntion so MM2 MM3 and MM1 are not used? xd
#define ASSERT_ENUM_ALIASES(sarray, max) \
  typedef char assert_sizeof_##max[(sizeof(sarray)/sizeof(sarray[0]) == (max)) ? 1 : -1]

#endif /* INC_MY_MENU_STRUCTURE_H_ */
