// incluir bibliotecas
#include <stdio.h>
#include "pico/stdlib.h"

const char *grupos[] = {
    "aaron",
    "grupo-01",
    "grupo-02",
    "grupo-03",
    "grupo-04",
    "grupo-05",
    "grupo-06",
    "grupo-07",
    "grupo-08",
    "grupo-09",
    "grupo-10",
    "grupo-11",
    "mateo",
};

const char *arduinos[] = {
    "arduinoAaron",
    "arduino01",
    "arduino02",
    "arduino03",
    "arduino04",
    "arduino05",
    "arduino06",
    "arduino07",
    "arduino08",
    "arduino09",
    "arduino10",
    "arduino11",
    "arduinoMateo",
};

const char *raspicos[] = {
    "raspicoAaron",
    "raspico01",
    "raspico02",
    "raspico03",
    "raspico04",
    "raspico05",
    "raspico06",
    "raspico07",
    "raspico08",
    "raspico09",
    "raspico10",
    "raspico11",
    "raspicoMateo",
};

// mensajes
const char *mensajes[] = {
    "hola ",
    "dis9079",
    "2026",
    "primer semestre",
    "lunes marzo 23"};

// numero de mensajes en la lista
int total = sizeof(mensajes) / sizeof(mensajes[0]);

// inicializar contador
int i = 0;

// funcion principal main()
// es tipo int, porque retorna un valor entero
int main()
{
    // inicializar la comunicacion serial
    stdio_init_all();

    // bucle infinito
    while (true)
    {
        // imprimir el mensaje actual
        printf("%s\n", mensajes[i]);

        // esperar 1 segundo
        sleep_ms(1000);

        // incrementar el contador
        i = i + 1;

        // reiniciar el contador cuando llega a 0
        i = i % total;
    }
}
