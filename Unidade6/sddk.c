#include <stdio.h> //para entrada e saída
#include "pico/stdlib.h" //para acessar pinos de entrada e saída etc

const unit led_pin_red = 12; //pino12(led vermelho)
int main(){
    uint a = 100;
    gpio_init(led_pin_red); //configura o pino g12 como saída
    gpio_set_dir(led_pin_red, GPIO_OUT); //configura o pino g12 como saída
    stdio_init_all(); //para a configuração de entrada e saída de dados(incluindo a porta serial)
    while (true)
    {
        a++;
        if(a % 2)
            printf("Blinking!\r\n");
            gpio_put(led_pin_red, true); //acende o led
            sleep_ms(1000);//atraso
            gpio_put(led_pin_red, false) //apaga o led
            sleep_ms(1000); //atraso
    }
    
}