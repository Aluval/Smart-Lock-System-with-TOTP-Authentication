#ifndef TOTP_H
#define TOTP_H

#include <string>
#include <vector>

class TOTP {
public:
    TOTP(const std::string& base32Key);
    std::string now();

private:
    std::vector<uint8_t> keyBytes;
    std::string generateOTP(unsigned long timestep);
    std::vector<uint8_t> base32ToBytes(const std::string& base32);
};

#endif
