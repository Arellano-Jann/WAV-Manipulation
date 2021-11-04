// Name: Jann Arellano
#include "Processor.h"
#include <vector>

    void normalization(){
        //Algo: The largest sample value in the data is found, and 
        //then the data is scaled so that that value is the maximum possible value. 
        //This maximizes the amplitude of the final waveform.
        
        //Takes in a vector sample and normalizes it to max amplitude.
        //How do we output? Does this need to be a void?
        float max = 0;
        float scale = 0;
        int scaleMax = 255;
        for (int i = 0; i < sample.end(); i++){ // find max in data sample 
        // find absolute value of max (if this doesn't work)
        // find the value that's closest to 0 or 255. recode this.
            if (sample[i] > max){
                max = sample[i];
            }
        }
        scale = scaleMax/max; // finds scaleValue to normalize sample
        for (int i = 0; i < sample.end(); i++){ // scale data sample
            sample[i] *= scale;
        }
        //check if any value is above 255 or 0
    }
    
    void echo(float scale, int delay){
        //Algo: Samples are copied, scaled, and 
        //added to later locations in the sample buffer to create an echo effect.

        //Takes in a float scale and delay. Copies a vector and combines both vectors.
        std::vector<float> echo = sample;
        for (int i = 0; i < sample.end(); i++){ // creates scaled echo vector
            echo[i] = sample[i] * scale;
        }

        //how to implement the addition of the scales
        //push_back the front of echo by delay
        //add echo[i] to sample[i]
        for (int i = 0; i < delay; i++){ // adds 0 to the start of the array "delay" times
            echo.insert(echo.begin(), 0);
        }
       


        //an echo is usually quieter than original so maybe 
        //scale the scale so that it's lower than 1?
    }

    void gainAdjustment(float scale){
        
        //Algo: Samples are multiplied by a scaling factor that raises or lowers 
        //the overall amplitude of the wave file

        std::vector<float> echo = sample;
        for (int i = 0; i < sample.end(); i++){ // creates scaled echo vector
            echo[i] = sample[i] * scale;
        }
    }