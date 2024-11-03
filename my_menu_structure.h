/*
 * my_menu_structure.h
 *
 *  Created on: Mar 6, 2024
 *      Author: brzan
 */

#ifndef INC_MY_MENU_STRUCTURE_H_
#define INC_MY_MENU_STRUCTURE_H_

#include "my_menu.h"

// MAIN MENUs
menu_t MM1, MM2, MM3, MM4, MM5, MM6;

// MEASURE MAIN MENU DATA
m_data_t MD1, MD2, MD3;

// LED MENU
menu_t LM1, LM2, LM3, LM4, LM5, LM6, LM7, LM8;
// LED MENU DATA
m_data_t LD1, LD2, LD3, LD4, LD5, LD6, LD7;

// PLOT MENU (not implemented yet)
menu_t PM1, PM2, PM3, PM4, PM5, PM6, PM7, PM8;


// TODO update menu init fucntion so MM2 MM3 and MM1 are not used? xd
#define ASSERT_ENUM_ALIASES(sarray, max) \
  typedef char assert_sizeof_##max[(sizeof(sarray)/sizeof(sarray[0]) == (max)) ? 1 : -1]

#endif /* INC_MY_MENU_STRUCTURE_H_ */
