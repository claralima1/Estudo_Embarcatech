#include <stdio.h>
#include <pico/stdlib.h>

//Define os pinos das colunas do teclado
const uint8_t COL_PINS[] = {1, 2, 3, 4};
const uint8_t ROW_PINS[] = {5, 6, 7, 8};

//Mapas teclas
const char KEY_MAP[4][4] = {
    {'D','#', '0', '*'},
    {'C', '9', '8', '7'},
    {'B', '6', '5','4'},
    {'A', '3','2','1'}
};

//Função para ler uma tecla do teclado 
char read_keypad(uint8_t *cols, uint8_t *rows){
    for(int i =0; i<4; i++){
        gpio_put(rows[i], 0); //Define o pino linha como baixo
        uint8_t result = 0;
        for (int j = 0; j<4; j++){
            results |= gpio_get(cols[j]); //Lê os estados dos pinos das colunas
        }
        if (result == 0){ //Verifica se alguma coluna está baixa
            //Obtém a tecla usando a posição do bit menos significativo
            char key = KEY_MAP[i][__builtin_ctz(result)];
            gpio_put(rows[i], 1); //Define o pino da linha como alto (debounce)
            return key;
        }
        gpio_put(rows[i], 1); // Define o pino da linha como alto
    }
    return 0; // Nenhuma tecla pressionada
}