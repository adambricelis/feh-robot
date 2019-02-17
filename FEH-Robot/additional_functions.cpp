#include <FEHLCD.h>
#include <FEHIO.h>
#include <FEHUtility.h>
#include <FEHMotor.h>
#include <FEHServo.h>
#include "drive.h"
#include "objects_constants.h"
#include "additional_functions.h"

int detectColor(){
    int color = 0;

    if(cds.Value() >= RED_MIN && cds.Value() <= RED_MAX){
      color = 1;
      LCD.SetFontColor(RED);
      LCD.WriteLine(cds.Value() +  " = RED");
    }
    else if(cds.Value() >= BLUE_MIN && cds.Value() <= BLUE_MAX){
      color = 2;
      LCD.SetFontColor(BLUE);
      LCD.WriteLine(cds.Value() +  " = BLUE");
    }
    return color;
}

void waitToStart(){
    float x, y;
    while(LCD.Touch(&x, &y));
    while(!LCD.Touch(&x, &y));
    while(LCD.Touch(&x,&y));
    float timeStart = TimeNow();
    while(detectColor() != 1 && (TimeNow()-timeStart) < START_WAIT);
    LCD.SetFontColor(BLACK);
    LCD.WriteLine("starting now");
}
