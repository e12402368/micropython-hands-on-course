import array
import time
import deepcraft_model
from machine import I2C
import bmi270
import configuration as cfg
from yeelight import MiLight

# --- Initialisierung ---
bulb = MiLight(cfg.BULB_IP, cfg.BULB_PORT)

model = deepcraft_model.DEEPCRAFT()
model.init()
output_dim = model.get_model_output_dim()
output_buffer = array.array('f', [0.0] * output_dim)

i2c = I2C(scl=cfg.I2C_SCL, sda=cfg.I2C_SDA)
bmi = bmi270.BMI270(i2c)

next_tick = time.ticks_ms()
last_action_time = 0

# --- Main Loop ---
while True:    
    # Sensordaten erfassen
    sensor_data = [bmi.accel(), bmi.gyro()]
    model.enqueue(sensor_data)

    # Prüfen, ob eine Vorhersage bereitsteht
    if model.dequeue(output_buffer) == 0:
        max_score = max(output_buffer)
        max_idx = list(output_buffer).index(max_score)
        label = cfg.LABELS[max_idx]

        current_time = time.ticks_ms()
        
        # Schwellenwert und Cooldown prüfen
        if max_score > cfg.GESTURE_THRESHOLD and (time.ticks_diff(current_time, last_action_time) > cfg.COOLDOWN_MS):
            
            # Mapping der Labels auf Aktionen
            match label:
                case "on":
                    bulb.turn_on()
                    last_action_time = current_time
                case "off":
                    bulb.turn_off()
                    last_action_time = current_time
                case "lighter":
                    bulb.brighten()
                    last_action_time = current_time
                case "dimmer":
                    bulb.dim()
                    last_action_time = current_time
                case "nothing":
                    pass 
            
    # Frequenzkontrolle (50Hz)
    # SAMPLE_TIME in ms umrechnen für genaues Timing
    sample_time_ms = int(cfg.SAMPLE_TIME * 1000)
    next_tick = time.ticks_add(next_tick, sample_time_ms)
    sleep_duration = time.ticks_diff(next_tick, time.ticks_ms())
    
    if sleep_duration > 0:
        time.sleep_ms(sleep_duration)