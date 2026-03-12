#include <iostream>
#include <string>
#include "TOTP.h"

using namespace std;

string correctPin = "1234";
string secret = "JBSWY3DPEHPK3PXP"; // Same one used in Google Authenticator

void unlockDoor() {
    cout << "\n🔓 Access Granted - Door Unlocked!\n";
}

int main() {
    string pin;
    cout << "🔐 Smart Lock System with OTP\n";
    cout << "Enter PIN: ";
    cin >> pin;

    if (pin != correctPin) {
        cout << "❌ Wrong PIN. Access Denied!\n";
        return 0;
    }

    cout << "✅ Correct PIN!\n";

    TOTP totp(secret);
    string generated = totp.now();

    cout << "📲 Enter OTP (from authenticator app): ";
    string inputOtp;
    cin >> inputOtp;

    if (inputOtp == generated) {
        unlockDoor();
    } else {
        cout << "❌ Invalid OTP. Access Denied!\n";
    }

    return 0;
}
