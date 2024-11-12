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


menu_t CANDG1, CANDG2, CANDG3, CANDG4, CANDG5, CANDG6;

m_data_t CDD1;


menu_t SDDG1, SDDG2, SDDG3, SDDG4, SDDG5, SDDG6;


menu_t HX1, HX2, HX3, HX4, HX5;

m_data_t HXD1, HXD2, HXD3;


menu_t RTCS1, RTCS2, RTCS3, RTCS4, RTCS5, RTCS6, RTCS7, RTCS8;

m_data_t RTCS2D, RTCS3D, RTCS4D, RTCS5D, RTCS6D, RTCS7D;


// TODO update menu init fucntion so MM2 MM3 and MM1 are not used? xd
#define ASSERT_ENUM_ALIASES(sarray, max) \
  typedef char assert_sizeof_##max[(sizeof(sarray)/sizeof(sarray[0]) == (max)) ? 1 : -1]

#endif /* INC_MY_MENU_STRUCTURE_H_ */
