#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/timers.h"

// Define el pin del LED
#define LED_PIN 2

// Define el periodo del estado del LED en milisegundos
#define LED_TOGGLE_PERIOD_MS 500

// Enumeración de estados del LED
typedef enum {
    LED_OFF,
    LED_ON
} led_state_t;

// Variable global para almacenar el estado del LED
led_state_t current_state = LED_OFF;

// Declaración de funciones
esp_err_t init_led(void);
void led_state_machine(TimerHandle_t xTimerHandle);

// Manejador del temporizador
TimerHandle_t xTimer = NULL;

// Función principal del programa
void app_main(void)
{
    // Inicializa el LED
    if (init_led() != ESP_OK) {
        printf("Failed to initialize the LED\n");
        return;
    }

    // Crear el temporizador de software
    xTimer = xTimerCreate("LED Timer", pdMS_TO_TICKS(LED_TOGGLE_PERIOD_MS), pdTRUE, NULL, led_state_machine);

    // Iniciar el temporizador de software
    if (xTimer != NULL) {
        xTimerStart(xTimer, 0);
    } else {
        printf("Failed to create the timer\n");
    }
}

// Función para inicializar el pin del LED
esp_err_t init_led(void)
{
    // Resetea la configuración del pin del LED
    gpio_reset_pin(LED_PIN);
    // Establece el pin del LED como salida
    if (gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT) != ESP_OK) {
        return ESP_FAIL;
    }
    return ESP_OK;
}

// Máquina de estado del LED
void led_state_machine(TimerHandle_t xTimerHandle)
{
    switch (current_state)
    {
        case LED_OFF:
            // Cambia el estado a encendido
            current_state = LED_ON;
            gpio_set_level(LED_PIN, 1);
            printf("LED is now ON\n");
            break;
        case LED_ON:
            // Cambia el estado a apagado
            current_state = LED_OFF;
            gpio_set_level(LED_PIN, 0);
            printf("LED is now OFF\n");
            break;
        default:
            // Manejo de estados desconocidos (aunque no debería ocurrir)
            printf("Unknown state\n");
            break;
    }
}
