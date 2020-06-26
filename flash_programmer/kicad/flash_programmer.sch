EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Memory_Flash:SST39SF010 U1
U 1 1 5EF63161
P 8550 3150
F 0 "U1" H 8550 4631 50  0000 C CNN
F 1 "SST39SF010" H 8550 4540 50  0000 C CNN
F 2 "" H 8550 3450 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/25022B.pdf" H 8550 3450 50  0001 C CNN
	1    8550 3150
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC595 U2
U 1 1 5EF672A6
P 5900 2350
F 0 "U2" H 5650 3100 50  0000 C CNN
F 1 "74HC595" H 5650 3000 50  0000 C CNN
F 2 "" H 5900 2350 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74hc595.pdf" H 5900 2350 50  0001 C CNN
	1    5900 2350
	1    0    0    -1  
$EndComp
Wire Wire Line
	6300 1950 7950 1950
Wire Wire Line
	7950 2050 6300 2050
Wire Wire Line
	6300 2150 7950 2150
Wire Wire Line
	7950 2250 6300 2250
Wire Wire Line
	6300 2350 7950 2350
Wire Wire Line
	6300 2450 7950 2450
Wire Wire Line
	6300 2550 7950 2550
Wire Wire Line
	6300 2650 6450 2650
Wire Wire Line
	6650 2750 7950 2750
Wire Wire Line
	7950 2850 6750 2850
Wire Wire Line
	6750 4050 6300 4050
Wire Wire Line
	6300 4150 6850 4150
Wire Wire Line
	6850 2950 7950 2950
Wire Wire Line
	6300 4250 6950 4250
Wire Wire Line
	6950 3050 7950 3050
Wire Wire Line
	7950 3150 7050 3150
Wire Wire Line
	7050 4350 6300 4350
Wire Wire Line
	6300 4450 7150 4450
Wire Wire Line
	7150 3250 7950 3250
Wire Wire Line
	6300 4550 7250 4550
Wire Wire Line
	7250 3350 7950 3350
Wire Wire Line
	6300 4650 7350 4650
Wire Wire Line
	7350 3450 7950 3450
$Comp
L Device:R_Small_US 1k
U 1 1 5EF6F11A
P 7850 3550
F 0 "1k" V 7900 3650 50  0001 C CNN
F 1 "1k" V 7900 3650 50  0000 C CNN
F 2 "" H 7850 3550 50  0001 C CNN
F 3 "~" H 7850 3550 50  0001 C CNN
	1    7850 3550
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5EF72597
P 7750 3550
F 0 "#PWR?" H 7750 3300 50  0001 C CNN
F 1 "GND" H 7755 3377 50  0000 C CNN
F 2 "" H 7750 3550 50  0001 C CNN
F 3 "" H 7750 3550 50  0001 C CNN
	1    7750 3550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5EF72DAB
P 5900 3050
F 0 "#PWR?" H 5900 2800 50  0001 C CNN
F 1 "GND" H 5905 2877 50  0000 C CNN
F 2 "" H 5900 3050 50  0001 C CNN
F 3 "" H 5900 3050 50  0001 C CNN
	1    5900 3050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5EF73415
P 5900 5050
F 0 "#PWR?" H 5900 4800 50  0001 C CNN
F 1 "GND" H 5905 4877 50  0000 C CNN
F 2 "" H 5900 5050 50  0001 C CNN
F 3 "" H 5900 5050 50  0001 C CNN
	1    5900 5050
	1    0    0    -1  
$EndComp
Wire Wire Line
	6650 2750 6650 3950
Wire Wire Line
	6750 2850 6750 4050
Wire Wire Line
	6850 2950 6850 4150
Wire Wire Line
	6950 3050 6950 4250
Wire Wire Line
	7050 3150 7050 4350
Wire Wire Line
	7150 3250 7150 4450
Wire Wire Line
	7250 3350 7250 4550
Wire Wire Line
	7350 3450 7350 4650
$Comp
L power:+5V #PWR?
U 1 1 5EF78098
P 5900 3750
F 0 "#PWR?" H 5900 3600 50  0001 C CNN
F 1 "+5V" H 5915 3923 50  0000 C CNN
F 2 "" H 5900 3750 50  0001 C CNN
F 3 "" H 5900 3750 50  0001 C CNN
	1    5900 3750
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 5EF79D97
P 5900 1750
F 0 "#PWR?" H 5900 1600 50  0001 C CNN
F 1 "+5V" H 5915 1923 50  0000 C CNN
F 2 "" H 5900 1750 50  0001 C CNN
F 3 "" H 5900 1750 50  0001 C CNN
	1    5900 1750
	1    0    0    -1  
$EndComp
NoConn ~ 6300 2850
Wire Wire Line
	6450 2650 6450 3400
Wire Wire Line
	6450 3400 5450 3400
Wire Wire Line
	5450 3400 5450 3950
Wire Wire Line
	5450 3950 5500 3950
Connection ~ 6450 2650
Wire Wire Line
	6450 2650 7950 2650
Wire Wire Line
	6300 3950 6650 3950
NoConn ~ 6300 4850
Entry Wire Line
	9200 2050 9300 2150
Entry Wire Line
	9200 2150 9300 2250
Entry Wire Line
	9200 2250 9300 2350
Entry Wire Line
	9200 2350 9300 2450
Entry Wire Line
	9200 2450 9300 2550
Entry Wire Line
	9200 2550 9300 2650
Entry Wire Line
	9200 2650 9300 2750
Entry Wire Line
	9200 1950 9300 2050
Wire Wire Line
	9200 1950 9150 1950
Wire Wire Line
	9200 2050 9150 2050
Wire Wire Line
	9150 2150 9200 2150
Wire Wire Line
	9200 2250 9150 2250
Wire Wire Line
	9150 2350 9200 2350
Wire Wire Line
	9200 2450 9150 2450
Wire Wire Line
	9150 2550 9200 2550
Wire Wire Line
	9200 2650 9150 2650
Wire Wire Line
	2950 2550 2800 2550
Wire Wire Line
	2950 2650 2800 2650
Wire Wire Line
	2950 2750 2800 2750
Wire Wire Line
	2950 2850 2800 2850
Wire Wire Line
	2950 2950 2800 2950
Wire Wire Line
	2950 3050 2800 3050
Wire Wire Line
	2950 3150 2800 3150
Wire Wire Line
	2950 3250 2800 3250
Entry Wire Line
	2700 2450 2800 2550
Entry Wire Line
	2700 2550 2800 2650
Entry Wire Line
	2700 2650 2800 2750
Entry Wire Line
	2700 2750 2800 2850
Entry Wire Line
	2700 2850 2800 2950
Entry Wire Line
	2700 2950 2800 3050
Entry Wire Line
	2700 3050 2800 3150
Entry Wire Line
	2700 3150 2800 3250
Wire Bus Line
	2700 1400 9300 1400
$Comp
L MCU_Module:Arduino_UNO_R3 A1
U 1 1 5EF6174D
P 3450 2950
F 0 "A1" H 3450 4131 50  0000 C CNN
F 1 "Arduino_UNO_R3" H 3450 4040 50  0000 C CNN
F 2 "Module:Arduino_UNO_R3" H 3450 2950 50  0001 C CIN
F 3 "https://www.arduino.cc/en/Main/arduinoBoardUno" H 3450 2950 50  0001 C CNN
	1    3450 2950
	1    0    0    -1  
$EndComp
NoConn ~ 2950 2350
NoConn ~ 2950 2450
$Comp
L power:GND #PWR?
U 1 1 5EF9C932
P 3450 4100
F 0 "#PWR?" H 3450 3850 50  0001 C CNN
F 1 "GND" H 3455 3927 50  0000 C CNN
F 2 "" H 3450 4100 50  0001 C CNN
F 3 "" H 3450 4100 50  0001 C CNN
	1    3450 4100
	1    0    0    -1  
$EndComp
Wire Wire Line
	3450 4100 3450 4050
Wire Wire Line
	3350 4050 3450 4050
Connection ~ 3450 4050
Wire Wire Line
	3450 4050 3550 4050
Wire Wire Line
	2950 3450 2700 3450
Wire Wire Line
	4900 4150 4900 4500
Wire Wire Line
	4900 4500 2700 4500
Wire Wire Line
	2700 3450 2700 4500
Wire Wire Line
	4900 4150 5500 4150
Wire Wire Line
	2950 3350 2600 3350
Wire Wire Line
	2600 3350 2600 4600
Wire Wire Line
	2600 4600 5000 4600
Wire Wire Line
	5000 4600 5000 4450
$Comp
L 74xx:74HC595 U3
U 1 1 5EF68D78
P 5900 4350
F 0 "U3" H 5700 5100 50  0000 C CNN
F 1 "74HC595" H 5700 5000 50  0000 C CNN
F 2 "" H 5900 4350 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74hc595.pdf" H 5900 4350 50  0001 C CNN
	1    5900 4350
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small_US R1
U 1 1 5EFB7548
P 5400 4550
F 0 "R1" V 5500 4650 50  0001 C CNN
F 1 "1k" V 5300 4500 50  0000 C CNN
F 2 "" H 5400 4550 50  0001 C CNN
F 3 "~" H 5400 4550 50  0001 C CNN
	1    5400 4550
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5EFB754E
P 5300 4550
F 0 "#PWR?" H 5300 4300 50  0001 C CNN
F 1 "GND" H 5305 4377 50  0000 C CNN
F 2 "" H 5300 4550 50  0001 C CNN
F 3 "" H 5300 4550 50  0001 C CNN
	1    5300 4550
	1    0    0    -1  
$EndComp
Wire Wire Line
	5500 4450 5000 4450
Wire Bus Line
	2700 1400 2700 3150
Wire Bus Line
	9300 1400 9300 2750
$EndSCHEMATC
