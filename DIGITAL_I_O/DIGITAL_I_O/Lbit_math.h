/**
 * @file    Lbit_math.h
 * @author  mohy eldean  (mohyeldean@gmail.com)
 * @brief   This header file contains required mathematical operations over bits, (Bit manipulation).
 * @version 1.0
 * @date    6-7-2021
 *
 * @copyright Copyright (c) 2021
 *
 */



#ifndef _Lbit_math_h_
#define _Lbit_math_h_


/*setting the required bit to 1*/

#define SET_BIT(REG,BIT) REG|= (1<<BIT)

/*clearing the required bit*/

#define CLEAR_BIT(REG,BIT)  REG&= ~(1<<BIT)

/*Get the required bit value*/
#define GET_BIT(REG,BIT)    ((REG >> BIT)&1)  //please use a external variable to assign the value inside it

/*Toggle the required bit value*/
#define TOGGLE_BIT(REG,BIT)   REG ^= (1<<BIT)

#endif