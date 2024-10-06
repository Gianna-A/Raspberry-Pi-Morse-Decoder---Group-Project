/**
* The given template is a guideline for your coursework only.
* You are free to edit/create any functions and variables.
* You can add extra C files if required.
*/








#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "includes/seven_segment.h"
#include "hardware/gpio.h"
#include "hardware/timer.h"


#define BUTTON_PIN          16  // Pin 21 (GPIO 16)



// array where the morse code inputs have been stored
char * symbol[4];
// declare global variables e.g., the time when the button is pressed
int pressed ;




// --------------------------------------------------------------------
void decoder(){
  // if else chain to decode inputs into alphanumeric form and displays it onto seven segment display and outputs a descriptive message to the terminal 
     if (symbol[0] == '.'){
         
             if (symbol[1] == '.'){
















                 if (symbol[2] == '.'){
















                     if (symbol[3] == '.'){ // .... = H
                 
             printf("%s \n", "H");
             seven_segment_show(8);
             sleep_ms(1000);
             seven_segment_off();
                     }
                     else if (symbol[3] == '-'){ // ...- = V
             printf("%s \n", "V");
             seven_segment_show(22);
             sleep_ms(1000);
             seven_segment_off();
                     }
                     else{ // ... = S
             printf("%s \n", "S");
             seven_segment_show(19);
             sleep_ms(1000);
             seven_segment_off();
                     }
















                 }
             
                 else if (symbol[2] == '-'){
                     if (symbol[3] == '.'){ // ..-. = F
         printf("%s \n", "F");
         seven_segment_show(6);
         sleep_ms(1000);
         seven_segment_off();
                     }
                     else if (symbol[3] == '-'){ // ..--ERROR HERE (not part of language)
                         seven_segment_show(27);
                         printf("%s \n", "This is an error input ..--");
                         sleep_ms(1000);
                         seven_segment_off();








                     }
                     else{ // ..- = U
         seven_segment_show(21);
         printf("%s \n", "U");
         sleep_ms(1000);
         seven_segment_off();
                     }
                 }
             
                 else{ // .. = I
            seven_segment_show(9);
         printf("%s \n", "I");
         sleep_ms(1000);
         seven_segment_off();
                 }
             }
         
             else if (symbol[1] == '-'){
             
                 if (symbol[2] == '.'){
















                     if (symbol[3] == '.'){ // .-.. = L
            seven_segment_show(12);
         printf("%s \n", "L");
         sleep_ms(1000);
         seven_segment_off();
                     }
                     else if (symbol[3] == '-'){ // .-.- = ERROR (not part of language)
                         seven_segment_show(27);
                         printf("%s \n", "This is an error input .-.-");
                         sleep_ms(1000);
                         seven_segment_off();








                     }
                     else{ // .-. = R
            seven_segment_show(18);
         printf("%s \n", "R");
         sleep_ms(1000);
         seven_segment_off();
                     }
















                 }
             
                 else if (symbol[2] == '-'){
                     if (symbol[3] == '.'){ // .--. = P
            seven_segment_show(16);
         printf("%s \n", "P");
         sleep_ms(1000);
         seven_segment_off();
                     }
                     else if (symbol[3] == '-'){ // .--- = J
         seven_segment_show(10);
         printf("%s \n", "J");
         sleep_ms(1000);
         seven_segment_off();
                     }
                     else{ // .-- = W
                 seven_segment_show(23);
                 printf("%s \n", "W");
                 sleep_ms(1000);
         seven_segment_off();
                     }
                 }
             
                 else{ // .- = A
                 seven_segment_show(1);
             printf("%s \n", "A");
             sleep_ms(1000);
         seven_segment_off();
                 }
             }
             else{ // . = E
             printf("%s \n", "E");
             seven_segment_show(5);
             sleep_ms(1000);
             seven_segment_off();
             }
















         }
















         else if (symbol[0] == '-'){
             if (symbol[1] == '.'){
















                 if (symbol[2] == '.'){
















                     if (symbol[3] == '.'){ // -... = B
                     seven_segment_show(2);
                 printf("%s \n", "B");
                 sleep_ms(1000);
         seven_segment_off();
                     }
                     else if (symbol[3] == '-'){ // -..- = X
                 seven_segment_show(24);
                 printf("%s \n", "X");
                 sleep_ms(1000);
         seven_segment_off();
                     }
                     else{ // -.. = D
                         seven_segment_show(4);
                 printf("%s \n", "D");
                 sleep_ms(1000);
         seven_segment_off();
                     }
















                 }
             
                 else if (symbol[2] == '-'){
                     if (symbol[3] == '.'){ // -.-. = C
                 seven_segment_show(3);
                 printf("%s \n", "C");
                 sleep_ms(1000);
         seven_segment_off();
                     }
                     else if (symbol[3] == '-'){ // -.-- = Y
                 seven_segment_show(25);
                 printf("%s \n", "Y");
                 sleep_ms(1000);
         seven_segment_off();
                     }
                     else{ // -.- = K
                 seven_segment_show(11);
                 printf("%s \n", "K");
                 sleep_ms(1000);
         seven_segment_off();
                     }
                 }
             
                 else{ // -. = N
                 seven_segment_show(14);
             printf("%s \n", "N");
             sleep_ms(1000);
         seven_segment_off();
                 }
             }
             else if (symbol[1] == '-') {
             
                 if (symbol[2] == '.'){
















                     if (symbol[3] == '.'){ // --.. = Z
                     seven_segment_show(26);
                 printf("%s \n", "Z");
                 sleep_ms(1000);
         seven_segment_off();
                     }
                     else if (symbol[3] == '-'){ // --.- = Q
                 seven_segment_show(17);
                 printf("%s \n", "Q");
                 sleep_ms(1000);
         seven_segment_off();
                     }
                     else{ // --. = G
                     seven_segment_show(7);
                 printf("%s \n", "G");
                 sleep_ms(1000);
         seven_segment_off();
                     }
















                 }
             
                 else if (symbol[2] == '-'){
                     if (symbol[3] == '.'){ // ---. = ERROR (not part of language)
                         seven_segment_show(27);
                         printf("%s \n", "This is an error input ---.");
                         sleep_ms(1000);
                         seven_segment_off();








                     }
                     else if (symbol[3] == '-'){ // ---- = ERROR (not part of language)
                         seven_segment_show(27);
                         printf("%s \n", "This is an error input ----");
                         sleep_ms(1000);
                         seven_segment_off();
                     }
                     else{ // --- = O
                 seven_segment_show(15);
                 printf("%s \n", "O");
                 sleep_ms(1000);
         seven_segment_off();
                     }
                 }
             
                 else{ // -- = M
                 seven_segment_show(13);
             printf("%s \n", "M");
             sleep_ms(1000);
         seven_segment_off();
                 }
             }
















             else{ // - = T
             seven_segment_show(20);
             printf("%s \n", "T");
             sleep_ms(1000);
         seven_segment_off();
             }
         
         }
















         else{ //  = ERROR (empty list)
                 seven_segment_show(27);
                 printf("%s \n", "This is an error input, empty list");
                 sleep_ms(1000);
                 seven_segment_off();


          }
      }






int main() {
  stdio_init_all();
  // Outputs a welcome message into the terminal
  printf("%s \n", "Hello World!");

  // Initialise the seven segment display.
  seven_segment_init();

  // Turns on the middle segment of the seven segment display
  seven_segment_show(0); // 0 = 0b00000010 => include as the 0th index in the list of letters in seven_segment.h
  sleep_ms(1000);

  // Turn the seven segment display off when the program starts.
  seven_segment_off();

  // Initialize the button's GPIO pin.
  gpio_init(BUTTON_PIN);
  gpio_set_dir(BUTTON_PIN, GPIO_IN);
  gpio_pull_down(BUTTON_PIN); // Pull the button pin towards ground (with an internal pull-down resistor).
  int i = 0;
      while (1) {
      if (gpio_get(BUTTON_PIN)) {
          seven_segment_show(0);  //turns on middle segment when button is pressed
          printf("%s \n", "Button Pressed"); //displays message "Button Pressed" into serial monitor when button is pressed
          uint32_t start = time_us_32(); // Get start time in microseconds
          while (gpio_get(BUTTON_PIN)) {
          }
          //While loop stops when gpio_get(BUTTON_PIN) is not true then executes the lines below
          uint32_t end = time_us_32(); // Get end time in microseconds
          uint32_t pressedTime = (end - start) / 1000; // Convert to milliseconds
          //%signed decimal integer
          if (pressedTime > 0) {
              printf("Button was pressed for %d ms\n", pressedTime); //displays how long the button has been pressed for into serial monitor
              seven_segment_off();
            if(pressedTime < 250){
                //dot input
                   symbol[i] = '.';
                   i++;
                   printf("Inputted . \n");
               }
               else if(pressedTime < 700){
                   //dash input
                   symbol[i] = '-';
                   i++;
                   printf("Inputted - \n");
               }
               else {
                   //error if pressed time is >700ms
                   printf("Button pressed for longer than 700ms, error input \n");
                   seven_segment_show(27);
                   sleep_ms(1000);
                   seven_segment_off();
               }
               if (i >= 5) {
                    // error if button is pressed more than 4 times, resetting the array storing the input values
                   i = 0;
                   printf("Button pressed too many times, array reset \n");
                   for(int index = 0; index < 4; index++) {
                       symbol[index] = NULL;
                   }
                   seven_segment_show(27);
                   sleep_ms(1000);
                   seven_segment_off();
               }
                       }
                   }
                   else {
                       //morseGaps(notpressedTime);
                       //displays the amount of time the button has not been pressed for into the serial monitor
                           uint32_t start1 = time_us_32();
                           while (gpio_get(BUTTON_PIN) == false){
          
                           }
                           uint32_t end1 = time_us_32();
                           uint32_t notpressedTime = (end1 - start1) / 1000;
                           printf("Button was not pressed for %d ms\n", notpressedTime);
                            if (notpressedTime >= 400 && symbol[0] != NULL) {
                                //displays an output corresponding to the inputs if the button has not been pressed for 400ms and resets the array
                               decoder();
                               i = 0;
                               for(int index = 0; index < 4; index++) {
                               symbol[index] = NULL;
                           }
                           }
                          
                          
                       }
               }
               }


                 
              





