# 🔐 Smart Lock System with TOTP Authentication

## Project Overview
The **Smart Lock System with TOTP Authentication** is a secure access control project that demonstrates a **two-factor authentication (2FA) locking mechanism** using a **static PIN and Time-Based One-Time Password (TOTP)** compatible with authenticator applications such as **Google Authenticator** or **Microsoft Authenticator**.

This project is implemented in **C++ using OpenSSL cryptographic libraries** and showcases how modern authentication mechanisms can be integrated into smart lock systems for enhanced security.

The system generates OTPs using the **TOTP algorithm (RFC 6238)** and validates them locally without requiring any external server.

---

# 🚀 Features

- PIN based authentication
- Time-Based One-Time Password (TOTP)
- Compatible with Google Authenticator
- Secure OTP generation using HMAC-SHA1
- 30-second OTP validity window
- Debug output for learning purposes
- Demonstrates Two-Factor Authentication (2FA)
- Suitable for smart lock or embedded security systems

---

# 🛠 Technologies Used

- **Language:** C++
- **Compiler:** g++
- **Cryptography Library:** OpenSSL
- **OTP Standard:** RFC 6238 (TOTP)
- **Platform:** Linux / WSL / Raspberry Pi

---

# 📂 Project Structure
```
Smart-Lock-System-with-TOTP-Authentication

main.cpp # Main authentication logic
TOTP.h # TOTP class definition
TOTP.cpp # OTP generation algorithm
README.md # Project documentation
```

---

# ⚙️ Installation Guide

## Step 1: Install Dependencies

```bash
sudo apt update
sudo apt install build-essential libssl-dev -y
```
---
Step 2: Clone Repository
```
git clone https://github.com/aluval/Smart-Lock-System-with-TOTP-Authentication.git
cd Smart-Lock-System-with-TOTP-Authentication
```
---
Step 3: Compile the Project
```
g++ main.cpp TOTP.cpp -std=c++11 -lssl -lcrypto -o smartlock
```
---
Step 4: Run the Program
```
./smartlock
```
---
### 📱 Setup Google Authenticator
Open Google Authenticator and add a new account using:
```
Account Name: SmartLock
Key: JBSWY3DPEHPK3PXP
Type: Time-Based
```
The authenticator will generate a 6-digit OTP every 30 seconds.
---
### 🔐 Authentication Process

1 User enters a PIN
2 System validates PIN
3 System generates TOTP
4 User enters OTP from authenticator app
5 If OTP matches → Access Granted
---
### 📊 Example Output
```
🔐 Smart Lock System with OTP
Enter PIN: 1234

✅ Correct PIN!

\[DEBUG] Current UNIX Time: 1771486702
\[DEBUG] Time Step (30s): 59049556
\[DEBUG] OTP Generated: 347317

📲 Enter OTP (from authenticator app):

🔓 Access Granted - Door Unlocked!
```
---
###📚 Educational Purpose Notice

This project is created for educational and research purposes only to demonstrate secure authentication systems using TOTP.

Students and developers are free to study, learn, and experiment with the code.

However, proper credit must be given to the original developer.

⚠️ Ownership & Usage Policy

This project was developed by:

Aluvala Ediga Harsha Vardhan Goud

If you use this project for:

- Academic work
- Research
- Learning
- Demonstration
You must provide proper credit to the original developer.

Failure to provide attribution while using or distributing the code will be considered misrepresentation.

### 🚫 Unauthorized Commercial Use

Selling, redistributing, or commercially exploiting this project without proper permission from the author is strictly prohibited.

Any misuse, plagiarism, or misrepresentation of the code may result in legal or DMCA action.

### 📜 Patent & Intellectual Property Notice

This project concept and implementation may be used for academic demonstration, but unauthorized reproduction or commercialization without attribution may violate intellectual property rights.

If any individual or organization attempts to mislead users by claiming ownership of this code, appropriate legal and DMCA actions may be initiated.

### 📅 Project Declaration

Project Owner:
Aluvala Ediga Harsha Vardhan Goud

Project Creation Date:
12 March 2026

### 📧 Contact

For questions, collaboration, or permission requests:

### 📧 Email:
sunrisesharsha467@gmail.com

### 📄 License

This project is licensed under the Apache License 2.0.

You may obtain a copy of the License at:
```
http://www.apache.org/licenses/LICENSE-2.0
```
Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND.

### ⭐ Support

If you found this project useful:

⭐ Star the repository

🍴 Fork the project

📢 Share with others
