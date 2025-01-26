#include <BLEDevice.h>

void setup() {
  Serial.begin(115200);
  Serial.println("Starting BLE scan...");

  // Initialize BLE
  BLEDevice::init("ESP32_BLE_Scanner"); // Optional: Set a custom device name
  
  // Start BLE scan
  BLEScan* pBLEScan = BLEDevice::getScan();
  pBLEScan->setActiveScan(true); // Active scan retrieves more details
  BLEScanResults* foundDevices = pBLEScan->start(5); // Scan for 5 seconds

  // Display scan results
  Serial.println("Devices found:");
  for (int i = 0; i < foundDevices->getCount(); i++) {
    BLEAdvertisedDevice device = foundDevices->getDevice(i);
    
    // Print device information
    Serial.print("Device ");
    Serial.print(i + 1);
    Serial.print(": MAC Address: ");
    Serial.print(device.getAddress().toString().c_str());
    Serial.print(", RSSI: ");
    Serial.print(device.getRSSI());
    if (device.getName().length() > 0) {
      Serial.print(", Name: ");
      Serial.print(device.getName().c_str());
    }
    Serial.println();
  }

  // Free memory used by the scan results
  pBLEScan->clearResults();
}

void loop() {
  // The loop is left empty in this example.
  // If you want periodic scanning, reinitialize the scan here.
}