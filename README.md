# 🔐 SHA-256 Implementation

## 📝 Overview

This repository contains an implementation of the SHA-256 (Secure Hash Algorithm 256-bit) 
cryptographic hash function. SHA-256 is part of the SHA-2 family of hash functions, published by the 
National Security Agency (NSA) in 2001.

## 🔍 What is SHA-256?

SHA-256 is a cryptographic hash function that takes an input of arbitrary length and produces a 
fixed-size output of 256 bits (32 bytes). Key properties include:

- One-way function (cannot be reversed to find the original input)
- Deterministic (same input always yields the same output)
- Collision-resistant (extremely difficult to find different inputs with the same output)
- Avalanche effect (small changes in input create large changes in output)

## 🧪 Practice Implementation

This implementation is a practice exercise for understanding cryptographic hash functions 
and low-level bit manipulation. It serves as a learning tool rather than a production-ready library.

## 🚀 Future Plans

This project is intended to grow into a comprehensive SHA library that will include:

- SHA-1 (legacy)
- Other SHA-2 variants (SHA-224, SHA-384, SHA-512, SHA-512/224, SHA-512/256)
- SHA-3 family implementations

## ⚙️ Technical Details

SHA-256 processes messages in 512-bit blocks and utilizes a series of logical operations, including:

- Bitwise operations (AND, OR, XOR)
- Bit rotations
- Modular addition

The algorithm produces a 256-bit (32-byte) digest that is typically represented as a 64-character 
hexadecimal string.

## 🔗 Resources

For more information about SHA-256:
- [RFC 6234](https://datatracker.ietf.org/doc/html/rfc6234)
- [NIST Publication FIPS 180-4](https://nvlpubs.nist.gov/nistpubs/FIPS/NIST.FIPS.180-4.pdf)
- [Wikipedia: SHA-2](https://en.wikipedia.org/wiki/SHA-2)