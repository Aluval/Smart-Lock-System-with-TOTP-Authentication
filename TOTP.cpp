#include "TOTP.h"
#include <ctime>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <bitset>
#include <openssl/hmac.h>
#include <openssl/evp.h>

TOTP::TOTP(const std::string& base32Key) {
    this->keyBytes = base32ToBytes(base32Key);
}

std::string TOTP::now() {
    unsigned long timeNow = std::time(nullptr);
    unsigned long timeStep = timeNow / 30;

    std::cout << "[DEBUG] Current UNIX Time: " << timeNow << std::endl;
    std::cout << "[DEBUG] Time Step (30s): " << timeStep << std::endl;

    return generateOTP(timeStep);
}

std::string TOTP::generateOTP(unsigned long timestep) {
    unsigned char data[8];
    for (int i = 7; i >= 0; --i) {
        data[i] = timestep & 0xFF;
        timestep >>= 8;
    }

    unsigned int len;
    unsigned char hmacResult[EVP_MAX_MD_SIZE];

    HMAC(EVP_sha1(), keyBytes.data(), keyBytes.size(), data, 8, hmacResult, &len);

    int offset = hmacResult[len - 1] & 0x0F;
    int binary =
        ((hmacResult[offset] & 0x7f) << 24) |
        ((hmacResult[offset + 1] & 0xff) << 16) |
        ((hmacResult[offset + 2] & 0xff) << 8) |
        (hmacResult[offset + 3] & 0xff);

    int otp = binary % 1000000;

    std::ostringstream result;
    result << std::setw(6) << std::setfill('0') << otp;

    std::cout << "[DEBUG] OTP Generated: " << result.str() << std::endl;
    return result.str();
}

std::vector<uint8_t> TOTP::base32ToBytes(const std::string& base32) {
    const std::string base32Chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ234567";
    std::string bits;
    std::vector<uint8_t> bytes;

    for (char c : base32) {
        int val = base32Chars.find(toupper(c));
        if (val == std::string::npos) continue;
        bits += std::bitset<5>(val).to_string();
    }

    for (size_t i = 0; i + 8 <= bits.length(); i += 8) {
        std::bitset<8> byte(bits.substr(i, 8));
        bytes.push_back(static_cast<uint8_t>(byte.to_ulong()));
    }

    return bytes;
}
