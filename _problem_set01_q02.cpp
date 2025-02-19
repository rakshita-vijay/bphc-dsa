#include <iostream>
#include <string>
using namespace std;

class Transformer {
  protected:
    // ???
    int shiftValue;
    string inputString;

  public:
    Transformer(int shift, const string& input) : shiftValue(shift), inputString(input) {}

    virtual string transform() const = 0;

    virtual ~Transformer() {}
};

class Encrypter : public Transformer { // Encrypter inherits Transformer
  public:
    Encrypter(int shift, const string& input) : Transformer(shift, input) {}

    string transform() const override {
      // ???
      // return ???;

      string encryptedString = inputString;

      for (int index = 0; index < encryptedString.length(); index++) {
        if (isalpha(inputString[index])) {
          char base = isupper(inputString[index]) ? 'A' : 'a';
          encryptedString[index] = (inputString[index] - base + shiftValue) % 26 + base;
        }
      }
      return encryptedString;
    }
};

class Decrypter : public Transformer { // Decrypter inherits Transformer
  public:
    // ???

    Decrypter(int shift, const string& input) : Transformer(shift, input) {}

    string transform() const override {
        string decryptedString = inputString;

        for (int index = 0; index < decryptedString.length(); index++) {
            if (isalpha(decryptedString[index])) {
                char base = isupper(decryptedString[index]) ? 'A' : 'a';
                decryptedString[index] = (decryptedString[index] - base - shiftValue + 26) % 26 + base;
            }
        }
        return decryptedString;
    }
};

int main() {
  string input;
  int shift;

  cout << "Enter a string to encrypt: ";
  getline(cin, input);
  cout << "Enter shift value: ";
  cin >> shift;

  // ???

  Encrypter encrypter(shift, input);
  string encrypted = encrypter.transform();
  cout << "Encrypted string: " << encrypted << endl;

  Decrypter decrypter(shift, encrypted);
  string decrypted = decrypter.transform();
  cout << "Decrypted string: " << decrypted << endl;

  return 0;
}
