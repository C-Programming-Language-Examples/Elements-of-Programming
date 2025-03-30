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

    // Initialize PortAudio
    Pa_Initialize();

    while (scanf("%d %f", &pitch, &duration) == 2) {
        // Calculate frequency and sample count
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

        // Close the stream
        Pa_StopStream(stream);
        Pa_CloseStream(stream);

        // Free the sound wave memory
        free(note);
    }

    // Terminate PortAudio
    Pa_Terminate();

    return 0;
}

//----------------------------------------------------------------------

// Compile and run:
// gcc -o playthattune playthattune.c -lportaudio -lm
// cat elise.txt | ./playthattune
// cat ascale.txt | ./playthattune
// cat entertainer.txt | ./playthattune
// cat firstcut.txt | ./playthattune
// cat freebird.txt | ./playthattune
// cat looney.txt | ./playthattune
// cat stairwaytoheaven.txt | ./playthattune
