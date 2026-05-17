# solemne-02

## Integrantes

- Renata De Los Ángeles Arévalo Urra / [arevalourra](<https://github.com/nicolasvaldesgreve/dis9079-2026-1/tree/main/06-arevalourra>)
- Isidora Andrea Pérez Maulén / [isipm08](<https://github.com/nicolasvaldesgreve/dis9079-2026-1/tree/main/21-isipm08>)
- Nicolás Elías Valdés Greve / [nicolasvaldesgreve](<https://github.com/nicolasvaldesgreve/dis9079-2026-1/tree/main/29-nicolasvaldesgreve>)

## Descripción textual del proyecto

## Materiales usados

| Componente | Valor Unidad | Cantidad | Link |
| --- | --- | --- | --- |
| Raspberry Pi Pico 2 W | $14.990 | 1 | <https://raspberrypi.cl/products/raspberry-pi-pico-2-w-con-headers> |
| Arduino UNO R4 WiFi | $38.990 | 1 | <https://arduino.cl/producto/arduino-uno-r4-wifi/?srsltid=AfmBOopyyargcSiTQeFlT3cTN5ide380bxZlQXRZVP4u_op0O-qJcENB> |
| Protoboard 400 puntos | $2.100 | 2 | <https://prodelab.cl/productos/didacticos/nivel-superior-y-ensenanza-media/robotica-y-programacion/accesorios-robotica-y-programacion/protoboard-breadboard-400-pines/> |
| Potenciómetro B20K | $495 | 1 | <https://altronics.cl/potenciometro-lineal-20k-b20k> |
| Cables Dupont (Pack 40 unidades) | $2.590 | 1 | <https://mcielectronics.cl/shop/product/cable-dupont-macho-macho-20cm-pack-40-unidades/> |
| Micro Servo Motor SG90 9g | $3.290 | 1 | <https://arduino.cl/producto/micro-servo-motor-sg90-9g/?srsltid=AfmBOoqZlsZtwx6MP23bWquVf5u5zZnS9a5CEJFEFpIcFrlUZCnyhxc5> |
| Botón Pulsador 4 pines | $570 | 1 | <https://www.victronics.cl/interruptores/boton-pcb-4-pines-spst-negro-redondo/> |

## Sensor usado

## Actuador usado

## Código usado para enviar

```cpp

import time
import board
import analogio
import digitalio
import wifi
import socketpool
import adafruit_minimqtt.adafruit_minimqtt as MQTT

# WiFi
wifi.radio.connect("si", "mailo6192")

# MQTT
pool = socketpool.SocketPool(wifi.radio)
mqtt = MQTT.MQTT(
    broker="io.adafruit.com",
    username="udpmontoyamoraga",
    password="keydeaarón",
    socket_pool=pool,
)

mqtt.connect()

# se configura el pin A0 como entrada para leer el potenciómetro
pot = analogio.AnalogIn(board.A0)

# se configura el pin GP0 para el botón,
# le dice a GP0 que es una entrada para que pueda leer datos
# se activa una resistencia interna que mantiene el pin en false cuando aún no presionamos el botón
button = digitalio.DigitalInOut(board.GP0)
button.direction = digitalio.Direction.INPUT
button.pull = digitalio.Pull.DOWN # aquí menciona que el botón funciona con el sistema pull down que menciona el video que está en nuestra bibliografía

while True:
    if button.value:  # solo envía si el botón fue presionado
        value = pot.value * 1023 // 65535
        print(f"Botón presionado - Enviando valor: {value}") # nos va a mencionar en putty cuando presionamos el botón, y el valor del potenciómetro

        mqtt.publish("udpmontoyamoraga/feeds/potenciometro-05", str(value))

        time.sleep(0.5)  # descanso pequeño jiji
```

## Código usado para recibir

## Imágenes del proyecto

## Animaciones del proyecto

## Bibliografía

+ <https://www.youtube.com/watch?v=d_odoKbEjgg&t=120s>, en donde nos enseñan cómo conectar un push button a una raspberry.
