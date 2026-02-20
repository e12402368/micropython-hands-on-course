import array
import time
import deepcraft_model
from machine import I2C
import bmi270
import configuration as cfg
from lightbulb import MiLight

# --- Initialisierung ---
# Yeelight Instanz
bulb = MiLight(cfg.BULB_IP, cfg.BULB_PORT)

# DeepCraft AI Modell Setup
model = deepcraft_model.DEEPCRAFT()
model.init()
output_dim = model.get_model_output_dim()
output_buffer = array.array('f', [0.0] * output_dim)

# IMU (BMI270) Setup
i2c = I2C(scl=cfg.I2C_SCL, sda=cfg.I2C_SDA)
bmi = bmi270.BMI270(i2c)

# Timing Variablen
next_tick = time.ticks_ms()
last_action_time = 0

print("System gestartet. Warte auf Gesten...")

# --- Main Loop ---
while True:    
    # 1. Sensordaten lesen
    accel = bmi.accel() # liefert [x, y, z]
    gyro = bmi.gyro()   # liefert [x, y, z]
    sensor_data = list(accel) + list(gyro) # [ax, ay, az, gx, gy, gz]

    # 2. Modell mit Daten füttern
    model.enqueue(sensor_data)

    # 3. Prüfen, ob eine Vorhersage fertig ist
    if model.dequeue(output_buffer) == 0:
        score = max(output_buffer)
        max_idx = list(output_buffer).index(max_score)
        label = cfg.LABELS[max_idx]
        
        print(f"Label: {label:<12} Score: {score*100:.2f}%")


    # --- Timing (50Hz Steuerung) ---
    # SAMPLE_TIME ist in Sekunden angegeben
    sample_time_ms = int(cfg.SAMPLE_TIME * 1000)
    next_tick = time.ticks_add(next_tick, sample_time_ms)
    
    sleep_duration = time.ticks_diff(next_tick, time.ticks_ms())
    if sleep_duration > 0:
        time.sleep_ms(sleep_duration)
