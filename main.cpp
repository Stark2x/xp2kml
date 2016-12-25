#include "XPLMPlugin.h"
#include "XPLMDataAccess.h"
#include "XPLMUtilities.h"
#include "XPLMMenus.h"

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>

#include "kmlclient.h"

KmlClient *gKmlClient = NULL;
static void PluginsMenuHandler(void * mRef, void * iRef);

PLUGIN_API int XPluginStart(char *outName, char *outSig, char *outDesc) {
    strcpy(outName, "XP2KML");
    strcpy(outSig, "de.thknz.xp2kml");
    strcpy(outDesc, "Write KML file from flight data.");

    if (gKmlClient) {
        delete gKmlClient;
    }
    gKmlClient = new KmlClient();

    if (gKmlClient) {
        XPLMMenuID id;
        int item;

        item = XPLMAppendMenuItem(XPLMFindPluginsMenu(), "XP2KML", NULL, 1);

        id = XPLMCreateMenu("XP2KML", XPLMFindPluginsMenu(), item, PluginsMenuHandler, NULL);

        XPLMAppendMenuItem(id, "Start recording", (void *)"START_REC",1);
        XPLMAppendMenuItem(id, "Stop recording", (void *)"STOP_REC",1);

        return 1;
    }
    return 0;
}

PLUGIN_API void	XPluginStop(void) {
    if (gKmlClient) {
        delete gKmlClient;
    }
    gKmlClient = NULL;
}

PLUGIN_API void XPluginDisable(void) {

    if (gKmlClient) {
        gKmlClient->disable();
    }
}

PLUGIN_API int XPluginEnable(void) {

    if (gKmlClient) {
        gKmlClient->enable();
    }
    return 1;
}

int main(int argc, char *argv[]) {
    XPluginEnable();
    return 0;
}

void PluginsMenuHandler(void * mRef, void * iRef)
{

    if (!strcmp((char *) iRef, "START_REC"))
    {
        gKmlClient->start_recording();
    }

    if (!strcmp((char *) iRef, "STOP_REC"))
    {
        gKmlClient->stop_recording();
    }



}

PLUGIN_API void XPluginReceiveMessage(XPLMPluginID inFromWho, long inMessage, void *inParam) {

}
