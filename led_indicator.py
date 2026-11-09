GPIO_PIN = 17

def set_led_status(exceeds_threshold):
    if exceeds_threshold:
        print(f"[ALERT] Threshold exceeded! LED ON (GPIO {GPIO_PIN})")
    else:
        print(f"[NORMAL] System stable. LED OFF (GPIO {GPIO_PIN})")

if __name__ == "__main__":
    print("LED Indicator helper module initialized.")
