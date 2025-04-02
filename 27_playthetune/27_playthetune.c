//----------------------------------------------------------------------
// 27_playthetune.c
//----------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <portaudio.h>

#define SPS 44100           // Samples per second
#define CONCERT_A 440.0     // Frequency of A4
#define NOTES_ON_SCALE 12.0 // Number of notes in an octave

static float* generateSoundWave(const double hz, const int n) {
    float *note = (float*)malloc((n + 1) * sizeof(float));
    for (int i = 0; i <= n; i++) {
        note[i] = (float)sin(2.0 * M_PI * i * hz / SPS);
    }
    return note;
}

static int playCallback(const void *inputBuffer, void *outputBuffer,
                        unsigned long framesPerBuffer, const PaStreamCallbackTimeInfo* timeInfo,
                        PaStreamCallbackFlags statusFlags, void *userData) {
    float *out = (float*)outputBuffer;
    const float *note = (const float*)userData;
    for (unsigned long i = 0; i < framesPerBuffer; i++) {
        *out++ = note[i];
    }
    return paComplete;
}

static void playSound(float *const note, const int n, const float duration) {
    PaStream *stream;
    Pa_OpenDefaultStream(&stream, 0, 1, paFloat32, SPS, n + 1, playCallback, note);
    Pa_StartStream(stream);
    Pa_Sleep((int)(duration * 1000));  // Sleep while the sound is playing
    Pa_StopStream(stream);
    Pa_CloseStream(stream);
}

static void initializePortAudio(void) {
    Pa_Initialize();
}

static void terminatePortAudio(void) {
    Pa_Terminate();
}

int main(void) {
    int pitch;
    float duration;

    initializePortAudio();

    while (scanf("%d %f", &pitch, &duration) == 2) {
        const double hz = CONCERT_A * pow(2.0, pitch / NOTES_ON_SCALE);
        const int n = (int)(SPS * duration);

        float *note = generateSoundWave(hz, n);
        playSound(note, n, duration);

        free(note);
    }

    terminatePortAudio();
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
