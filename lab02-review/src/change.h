#ifndef MESA_CISC187_LAB02_CHANGE_H
#define MESA_CISC187_LAB02_CHANGE_H

/**
 * A struct to hold the results of a purchase.
 * @funds the amount of money we hold
 * @items the number of items purchased
 */
struct purchase_t
{
  int funds = 100;
  int items = 0;
};

purchase_t buy_stuff();

#endif

