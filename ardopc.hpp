#ifndef ARDOPC_HPP
#define ARDOPC_HPP
#include <array>
#include <string>

class ardopc
{
public:
  ardopc();
  bool CheckValidCallsignSyntax(char *callsign);
  bool CheckGSSyntax(char *gridsquare);
private:
//  std::array<char, 10> callsign();
//  std::array<char, 9> gridsquare();
};

#endif // ARDOPC_HPP
