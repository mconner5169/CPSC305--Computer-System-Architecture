/**********************************************************************
* Filename    : blink.c
* Description : Make an led blinking.
* auther      : www.freenove.com
* modification: 2016/06/07
* Gusty's modification: Added Turnon/Turnoff Loop in front of Blink
**********************************************************************/
#include <wiringPi.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define  ledPin    0

int main(void)
{
    if(wiringPiSetup() == -1){ 
        printf("setup wiringPi failed !");
        return 1; 
    }
    printf("wiringPi initialize successfully, GPIO %d(wiringPi pin)\n",ledPin);     
    
    pinMode(ledPin, OUTPUT);

    char letter[100];
    
    while (1) {
        while (1) { // Turnon/Turnoff Loop
            printf("Enter: 1 turn on, 0 turn off, other goto Blink: ");
            scanf("%s", letter);
            if (strcmp("1", letter) == 0)
                digitalWrite(ledPin, HIGH);
            else if (strcmp("0", letter) == 0)
                digitalWrite(ledPin, LOW);
            else
                break;
        }
        while (1) { // Blink Loop from FreeNovePiBook
            digitalWrite(ledPin, HIGH);  //led on
            printf("led on...\n");
            delay(1000);
            digitalWrite(ledPin, LOW);  //led off
            printf("...led off\n");
            delay(1000);
        }
    }

    return 0;
}

