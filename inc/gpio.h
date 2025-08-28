/************************************************************************************************
Copyright (c) 2025, Lucas Kirschner <kirschnerlucas1@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
associated documentation files (the "Software"), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge, publish, distribute,
sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial
portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES
OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

SPDX-License-Identifier: MIT
*************************************************************************************************/

#ifndef GPIO_H
#define GPIO_H

/** @file    gpio.h
 ** @brief   API de manejo de GPIO (wrapper de HAL).
 **
 ** @defgroup gpio GPIO
 ** @brief    Abstracción simple de GPIO sobre la HAL
 ** @{ */

/* === Headers files inclusions ================================================================ */

/* === Cabecera C++ ============================================================================ */

#ifdef __cplusplus
extern "C" {
#endif

/* === Public macros definitions =============================================================== */

/* === Public data type declarations =========================================================== */

/** @brief Tipo opaco que representa un GPIO. */
typedef struct gpio_s * gpio_t;

/* === Public variable declarations ============================================================ */

/* === Public function declarations ============================================================ */

/**
 * @brief Crea una instancia de GPIO.
 * @param port  Número de puerto (definición propia de la HAL).
 * @param bit   Número de bit/pin dentro del puerto.
 * @return Instancia válida o `NULL` si no hay memoria.
 *
 * @pre  La HAL debe estar inicializada.
 * @post El GPIO es de entrada por defecto (`output == false`).
 * @note La instancia debe liberarse con ::gpioDestroy cuando ya no se use.
 */
gpio_t gpioCreate(uint8_t port, uint8_t bit);

/**
 * @brief Destruye una instancia de GPIO y libera sus recursos.
 * @param gpio Instancia a destruir (acepta `NULL`, no hace nada).
 */
void gpioDestroy(gpio_t gpio);

/**
 * @brief Configura la dirección del GPIO.
 * @param gpio   Instancia válida.
 * @param output `true` → salida; `false` → entrada.
 */
void gpioSetOutput(gpio_t gpio, bool output);

/**
 * @brief Escribe el estado de un GPIO configurado como salida.
 * @param gpio  Instancia válida.
 * @param state `true` → nivel alto; `false` → nivel bajo.
 */
void gpioSetState(gpio_t gpio, bool state);

/**
 * @brief Lee el estado actual del pin (línea física).
 * @param gpio Instancia válida.
 * @return `true` si la lectura es alto; `false` si es bajo.
 */
bool gpioGetState(gpio_t gpio);

/* === End of documentation ==================================================================== */

#ifdef __cplusplus
}
#endif

/** @} end of group gpio */

#endif /* GPIO_H */
