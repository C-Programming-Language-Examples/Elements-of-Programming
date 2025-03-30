//----------------------------------------------------------------------
// playthetune.c
//----------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <portaudio.h>

#define SPS 44100           // Samples per second
#define CONCERT_A 440.0     // Frequency of A4
#define NOTES_ON_SCALE 12.0 // Number of notes in an octave

// Audio stream callback function
static int playCallback(const void *inputBuffer, void *outputBuffer,
                        unsigned long framesPerBuffer, const PaStreamCallbackTimeInfo* timeInfo,
                        PaStreamCallbackFlags statusFlags, void *userData) {
    float *out = (float*)outputBuffer;
    float *note = (float*)userData;
    for (unsigned long i = 0; i < framesPerBuffer; i++) {
        *out++ = note[i];
    }
    return paComplete;
}

int main(void) {
    int pitch;
    float duration;

    Pa_Initialize();

    while (scanf("%d %f", &pitch, &duration) == 2) {
        double hz = CONCERT_A * pow(2.0, pitch / NOTES_ON_SCALE);
        int n = (int)(SPS * duration);

        // Generate the sound wave
        float *note = (float*)malloc((n + 1) * sizeof(float));
        for (int i = 0; i <= n; i++) {
            note[i] = (float)sin(2.0 * M_PI * i * hz / SPS);
        }

        // Open audio stream
        PaStream *stream;
        Pa_OpenDefaultStream(&stream, 0, 1, paFloat32, SPS, n + 1, playCallback, note);
        Pa_StartStream(stream);

        // Wait until the stream has finished
        Pa_Sleep((int)(duration * 1000));

        Pa_StopStream(stream);
        Pa_CloseStream(stream);

        free(note);
    }

    Pa_Terminate();

    return 0;
}

//----------------------------------------------------------------------

// Compile and run:
// gcc -o 27_playthetune 27_playthetune.c -lportaudio -lm
// cat elise.txt | ./27_playthetune
// cat ascale.txt | ./27_playthetune
// cat entertainer.txt | ./27_playthetune
// cat firstcut.txt | ./27_playthetune
// cat freebird.txt | ./27_playthetune
// cat looney.txt | ./27_playthetune
// cat stairwaytoheaven.txt | ./27_playthetune
