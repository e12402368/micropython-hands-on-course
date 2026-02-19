import h5py
import json
import numpy as np

def inspect_h5(filename):
    print(f"\n--- ANALYSE: {filename} ---")
    try:
        with h5py.File(filename, 'r') as f:
            # Keras speichert die Struktur oft in 'model_config'
            if 'model_config' not in f.attrs:
                print("FEHLER: Keine 'model_config' im File gefunden.")
                return

            config_str = f.attrs.get('model_config')
            # Manchmal ist es bytes, manchmal string
            if isinstance(config_str, bytes):
                config_str = config_str.decode('utf-8')
            
            model_config = json.loads(config_str)
            
            # Versuche, Input-Shape zu finden
            input_shape = "Unbekannt"
            
            # Fall 1: Functional API (häufig bei komplexen Modellen)
            if 'config' in model_config and 'input_layers' in model_config['config']:
                print("Typ: Functional API")
                # Sucht den ersten Layer, auf den der Input zeigt
                input_layer_name = model_config['config']['input_layers'][0][0]
                # Suche diesen Layer in der Layer-Liste
                for layer in model_config['config']['layers']:
                    if layer['name'] == input_layer_name:
                        input_shape = layer['config'].get('batch_input_shape')
                        break
            
            # Fall 2: Sequential API
            elif 'config' in model_config and 'layers' in model_config['config']:
                print("Typ: Sequential API")
                first_layer = model_config['config']['layers'][0]
                input_shape = first_layer['config'].get('batch_input_shape')
            
            print(f"INPUT SHAPE: {input_shape}")
            
    except Exception as e:
        print(f"Konnte Datei nicht lesen: {e}")

# Pfade zu deinen Dateien (ggf. anpassen)
inspect_h5("conv2d-medium-balanced-0/conv2d-medium-balanced-0.h5")
inspect_h5("conv2d-medium-balanced-1/conv2d-medium-balanced-1.h5")