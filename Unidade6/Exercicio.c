#include "pico/stdlib.h" //biblioteca para interagir com o hardware

#define LED_PIN 11 //pino do led
#define BTN_PIN 5 //pino do botão

int main(){
    gpio_init(LED_PIN); //configura o pino
    gpio_set_dir(LED_PIN, GPIO_OUT); //define se pino será de entrada/saída (nesse caso saída)
    gpio_init(BTN_PIN);//configura o pino
    gpio_set_dir(BTN_PIN, GPIO_IN); //define se pino será de entrada/saída (nesse caso entrada)
    while (1) //loop infinito
    {
        while(gpio_get(BIN_PIN)){ //condicional que verifica se o botão foi pressionado
            gpio_put(LED_PIN, 1); //liga o led
        }
        gpio_put(LED_PIN, 0); ///desliga o led
    }
    
}