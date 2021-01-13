//
// Created by oem on 02.01.2021.
//

#include "Recipe1.h"

void Recipe1::start() {
    for(currentState = 0; currentState<statesCount; currentState++)
    {
        while (states[currentState].action())
        {
            //delay(0);
        }
    }
}

void Recipe1::stop()  {
    currentState = 0;

}

void Recipe1::pause()  {


}
