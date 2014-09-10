QBlowfish
=========

Simple blowfish encryption implementation in Qt with QByteArray support

This source is result of the following article: http://morf.lv

Sample usage:
```
QBlowfish *blowfish = new QBlowFish("At least 4 char ASCII key");

blowfish->calcSubKey("Or lets set another key");

QByteArray encryptedData = blowfish->encrypt(raw_data);

QByteArray decryptedData = blowfish->decrypt(encryptedData);
```

Enjoy
