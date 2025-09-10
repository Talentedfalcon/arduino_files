import serial
from time import sleep

arduino=serial.Serial("COM7",baudrate=9600,timeout=1)
sleep(2)

def wait_for_ready():
    while True:
        line=arduino.readline().decode().strip()
        if line=="READY":
            return

def send_note(note):
    arduino.write(note.encode('utf-8'))
    sleep(0.09)

with open('sheet_modified.txt','r') as sheet:
    for note in sheet:
        wait_for_ready()
        print(note.strip())
        send_note(note)
    send_note('z')