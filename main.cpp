// Name:


#include "Wav.h"
int main()
{
    Wav w;
    if(!w.SetFile("one_small_step.wav"))
    {
        std::cout << "File doesn't exist or is not a .wav file.";
    }
    
    
    return 0;
}