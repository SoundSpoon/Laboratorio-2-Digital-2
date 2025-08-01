# Laboratorio-2-Digital-2
Programación del laboratorio 2 de Electrónica digital 2
Para este laboratorio se utilizan dos librería 
#include <Arduino.h>
#include <stdint.h>
los cuales ayudan a definir las variables y nos da el formato de arduino 
Por otro lado se usa un esp32 con 2 botones y 4 leds junto con una palanca para definir el estado en el que se mantendrá el programa

Este programa cuenta con dos modos, uno para contar en binario al igual que otro para contar en decimales el cual es cambiado cuando se cambia el switch, un boton aumenta el número que se ve representado en las leds mientras que el otro retrocede los cuales cuentan con debounce y con programación para evitar que ambos botones se presionen al mismo tiempo.
