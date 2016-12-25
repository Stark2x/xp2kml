#ifndef KMLCLIENT_H
#define KMLCLIENT_H
#include "XPLMDataAccess.h"
#include "XPLMUtilities.h"
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include <iomanip>

class KmlClient
{
public:
    explicit KmlClient();
    virtual ~KmlClient();

    void enable();
    void disable();
    float flightloop(float inElapsedSinceLastCall, float inElapsedTimeSinceLastFlightLoop, int inCounter, void * inRefcon);
    void start_recording();
    void stop_recording();
private:
    XPLMDataRef mCurrentLatitude,mCurrentLongitude, mCurrentTrack, mCurrentAltitude;
    std::ofstream handle;
    boolean enabled;
    const std::string get_current_date_time();

};

#endif // KMLCLIENT_H
