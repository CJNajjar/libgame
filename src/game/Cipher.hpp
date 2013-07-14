#ifndef _GAME_CIPHER_HPP
#define _GAME_CIPHER_HPP
#include "CryptoPP/algparam.h"

class KeyAgreement {
  protected:
    CryptoPP::SecByteBlock shared_;
  public:
    KeyAgreement();
    ~KeyAgreement();
    virtual size_t Prepare(void *, size_t *);
    virtual bool Agree(size_t, const void *, size_t);
    const CryptoPP::SecByteBlock & shared(void) const;
};

class Cipher {
  private:
    bool activated_;
    CryptoPP::SymmetricCipher *encoder_;
    CryptoPP::SymmetricCipher *decoder_;
    KeyAgreement *key_agreement_;

  public:
    Cipher();
    ~Cipher();
    void CleanUp(void);
    size_t Prepare(void *, size_t *);
    bool Activate(bool, size_t, const void *, size_t);
    void Encrypt(void *, size_t);
    void Decrypt(void *, size_t);
    bool activated(void) const;
    bool IsKeyPrepared(void);
  private:
    bool SetUp(bool);
};

#endif // _GAME_CIPHER_HPP
