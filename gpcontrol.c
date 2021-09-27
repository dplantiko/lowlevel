#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"

#define GPIO_ON 1
#define GPIO_OFF 0

#define MAX_PIN 6

//Printstate shows if Pins are set on or off
void printState(short int state[])
{
  int i=0;
  for(i=0;i<=MAX_PIN;i++)
  {
    printf("state[%u] = %u\n",i,state[i]);
  }
}

int main()
{

//Initialise I/O
  stdio_init_all();

//state[] array: 0 is OFF, 1 is ON
  short int state[(MAX_PIN+1)];
  char userin[12];
  int i,num;

//Initialize all the pins
  for(i=0;i<=MAX_PIN;i++)
  {
    gpio_init(i);
  }

//Set all the pins to OUT
  for(i=0;i<=MAX_PIN;i++)
  {
    gpio_set_dir(i, GPIO_OUT);
    gpio_put(i, GPIO_OFF);
    state[i]=0;
  }

  while(1)
  {
    printf("Enter pin number:\n");
    sleep_ms(100);

//getchar() to get user input
//Sadly, scanf() gives you weird results on minicom
    userin[0] = getchar();
    fflush(stdin);
    sleep_ms(100);

    if(userin[0]=='s')
    {
      printState(state);
      sleep_ms(100);
      continue;
    }

    num = atoi(userin);

    if(num <= MAX_PIN)
    {
      if(state[num]==0)
      {
        gpio_put(num,GPIO_ON);
        state[num] = 1;
        printf("GPIO %d ON\n",num);
      }
      else
      {
        gpio_put(num,GPIO_OFF);
        state[num] = 0;
        printf("GPIO %d OFF\n",num);
      }
    }
    sleep_ms(100);
  }

  return 0;
}
