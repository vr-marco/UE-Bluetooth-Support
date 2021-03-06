/**
* !Created By Taha HICHRI
* @project    Bluetooth Support for UNREAL engine.
* @author     Taha HICHRI <hishri.taha@gmail.com>
* @see        https://github.com/hishriTaha
* Copyright (c) 2018 hishri.com
*/


#include "BluetoothDevice.h"

FString     address;
int32       rssi;

// Returned with API > 26
int32       periodicAdvertisingInterval;
int32       txPower;

int32		lastDiscovery;
bool        isConnectable;

void UBluetoothDevice::InitDevice(FString stringifiedDeviceInformation)
{
	// Split stringified information
	// "address|rssi|periodicAdvertisingInterval|txPower|isConnectable"

	TArray<FString> DeviceInfoArr = {};
	stringifiedDeviceInformation.ParseIntoArray(DeviceInfoArr, TEXT("|"), true);

	address	= DeviceInfoArr[0];
	rssi = FCString::Atoi(*DeviceInfoArr[1]) ;
	periodicAdvertisingInterval = FCString::Atoi(*DeviceInfoArr[2]);
	txPower = FCString::Atoi(*DeviceInfoArr[3]);
	isConnectable = DeviceInfoArr[4] == "true" ? true : false;
	lastDiscovery = FCString::Atoi(*DeviceInfoArr[5]) ;
}




FString UBluetoothDevice::GetAddress()
{
	return address;
}


int32 UBluetoothDevice::GetRssi()
{
	return rssi;
}

int32 UBluetoothDevice::GetPeriodicAdvertisingInterval()
{
	return periodicAdvertisingInterval;
}

int32 UBluetoothDevice::GetTxPower()
{
	return txPower;
}

int32 UBluetoothDevice::GetLastSeen()
{
	return lastDiscovery;
}

bool UBluetoothDevice::IsConnectable()
{
	return isConnectable;
}


