#ifndef __STFT_H__
#define __STFT_H__

#include <complex>
#include <cmath>
#include <fftw3.h>

#include "../src/e3e_detection.h"

class STFT
{
  public:
    int fft_size;
    int n_frames;
    int frame_size;
    int channels;

    fftwf_plan *plans;

    int n_samples_per_in_frame;
    int n_samples_per_out_frame;
    int circ_in_buffer_size;
    int circ_out_buffer_size;

    float *circ_in_buffer;
    e3e_complex *circ_out_buffer;  // circular buffer pointer
    int current_frame = 0;

    STFT(int _fft_size, int _n_frames, int _channels);
    ~STFT();

    float *get_in_buffer();
    e3e_complex *get_out_buffer();
    e3e_complex *transform();

    e3e_complex get_fd_sample(int frame, int frequency, int channel);
    float get_td_sample(int frame, int index, int channel);

};


#endif // __STFT_H__
