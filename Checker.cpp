#include <assert.h>
#include <iostream>
using namespace std;

bool CheckTempRange(float val)
{
    if (0 < val && val < 45)
        return true;
    return false;  
}

bool CheckSocRange(float val)
{
    if (20 < val && val < 80)
        return true;
    return false;  
}

bool CheckchargeRateRange(float val)
{
    if (val < 0.8)
        return true;
    return false;  
}

bool BatteryIsOk(float Temp, float Soc, float CR)
{
    bool TempOk = CheckTempRange(Temp);
    bool SocOk = CheckSocRange(Soc);
    bool chargeRate = CheckchargeRateRange(CR);
    return TempOk && SocOk && chargeRate;
}

int main() 
{
    assert(BatteryIsOk(25, 70, 0.7) == true);
    assert(BatteryIsOk(50, 85, 0) == false);
}
