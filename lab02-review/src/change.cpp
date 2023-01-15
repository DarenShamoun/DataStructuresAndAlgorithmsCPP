#include "change.h"
#include <cmath>
#include <cstdlib>

purchase_t buy_stuff () 
{
  purchase_t purchase;

  for (int price = 10; purchase.funds >= price; price += 10) 
  {
    purchase.funds -= price;
    purchase.items += 1;
  }

  return purchase;
}