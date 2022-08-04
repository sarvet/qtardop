#include "ardopc.hpp"
#include <cstring>
ardopc::ardopc()
{

}
/*
 * Function to check for valid callsign syntax
 */
bool ardopc::CheckValidCallsignSyntax(char *callsign)
{
  char *dash = strchr(callsign, '-');
  int call_len = static_cast<int>(strlen(callsign));
  char *ptr = callsign;
  int ssid;

  if(dash)
  {
     call_len = static_cast<int>(dash - callsign);
     ssid = atoi(dash + 1);
     if(ssid > 15)
       {
         return false;
       }
     if(static_cast<int>(strlen((dash + 1)) > 2))
       {
         return false;
       }
     if(!isalnum(*(dash + 1)))
       {
         return false;
       }
  }
  if (call_len > 7 || call_len < 3)
    {
      return false;
    }
  while (call_len--)
    {
      if(!isalnum(*(ptr++)))
        {
          return false;
        }
    }
  return true;
}
/*
 * Function to check for proper syntax of a 4, 6 or 8 character gridsquare
 */
bool ardopc::CheckGSSyntax(char *gridsquare)
{
  int length = static_cast<int>(strlen(gridsquare));
  //checks if gridsquare is 4, 6 or 8 chars long
  if( !(length == 4 || length == 6 || length == 8) )
    {
      return false;
    }
  //checks if 1st or 2nd character is not alphabetic
  if( !isalpha(gridsquare[0]) || !isalpha(gridsquare[1]) )
    {
      return false;
    }
  //checks if 3rd and 4th character is not a digit
  if( !isdigit(gridsquare[2]) || !isdigit(gridsquare[3]) )
    {
      return false;
    }
  if( length == 4 )
    {
      return true;
    }
  //checks if 5th or 6th character is not alphabetic
  if( !isalpha(gridsquare[4]) || !isalpha(gridsquare[5]) )
    {
      return false;
    }
  if( length == 6 )
    {
      return true;
    }
  //checks if 7th or 8th character is not a digit
  if( !isdigit(gridsquare[6]) || !isdigit(gridsquare[7]) )
    {
      return false;
    }
  //otherwise return true
  return true;
}

