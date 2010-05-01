#include <stdio.h>

#include <BWAPIClient\Source\BWAPIClient.h>
#include <BWAPI.h>

#include <windows.h>

#include <string>

using namespace BWAPI;

void reconnect()
{
  while(!BWAPIClient.connect())
  {
    Sleep(1000);
  }
}
int main(int argc, const char* argv[])
{
  BWAPI::BWAPI_init();
  printf("Connecting...");
  reconnect();

  while(true)
  {
    bool first=true;
    while(true)
    {
      if (first)
      {
        printf("in game!");
        first=false;
      }
      if (Broodwar->isInGame())
        Broodwar->printf("hello world! %d", Broodwar->getFrameCount());
      else
        printf("not in game\n");
      BWAPI::BWAPIClient.update();
      if (!BWAPI::BWAPIClient.isConnected())
      {
        printf("Reconnecting...\n");
        reconnect();
      }
    }
    printf("Game ended\n");
  }
  system("pause");
  return 0;
}
