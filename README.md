# Digital Signal Processing (DSP) Fundamentals
 ### This repository contains C scripts, MATLAB live scripts and data files. 
 The resources are summed up for the exploration of fundamental concepts in DSP using C code algorithms and Matlab live
    scripts for signal analysis and presentation.
 The examples include basic signal transformations, filtering techniques, and spectral analysis.

# Repository Structure
- All the C scripts included use a raw data signal array from waveforms.c, and each one contain Makefile including it. 
    Most folders has the file output from the script in .dat format using the general array in waveforms.c which has component 1hz and 15hz, sampled at 44100khz.
    The Makefile or waveforms.c can be modified, and use another values for the script consumption.
    
    
 :boom:_Check out my **wav2code-tool** which includes Matlab script for generating a raw data file from .wav file._:boom:
 
 :point_down:
          
          https://github.com/d3ssy23/wav2code-tool/tree/main
    
    
# Contents:   
The repository is organized into the following sections:

## 1. Complex DFT
- C script related to the Discrete Fourier Transform (DFT) for complex signals.
    Useful for analyzing the frequency components of complex-valued signals.
    Uses a ImX and ReX components.
    Creates two output files containing the real and imaginary part of the complex signal.
    
## 2. Convolution
- Demonstrates the convolution operation, a fundamental concept in signal processing for filtering and system response analysis.
    Uses a matlab generated impulse response from filterdesigner tool (filter_kernel.c) and the waveforms.c data signal array.
    Creates 3 data files containing the data of the filter kernel, the input signal and the output signal result after the convolution of the filter kernel and the input signal.
    ---NOTE: In matlab's filterdesigner tool the filter kernel can be exported directly as C header and then directly attached to the makefile, which generally simplify the process ---
    
## 3. DFT and IDFT
  - Demonstrating the DFT algorithm using raw data input signal, separating it to its real, imaginary part and the magnitude and then use the Imx and Rex for IDFT to return it to the
    original input signal state.  
  - Example include processing ECG signal.
    
## 4. Rectangular to Polar Transformation
  - Uses the Imx and Rex of the input signal and create output files with the Phase and Magnitude.
        
## 5. Statistical Analysis
  - CLI C-scripts for calculating:
    1.Mean
    2.Variance
    3.Standard Deviation
    --- Useful for signal characteristics and noise analysis ---
    
## 6. Windowed-Sinc Filters
   - Windowed-sinc BP filter: Implements a bandpass filter using the windowed-sinc method.
   - Windowed-sinc LP filter: Implements a lowpass filter using the same method.
     
## 7. Running Sum and First Difference
   - Demonstrate and apply the equation for the differentiation (Fisrt difference) and integration (Running sum) of discrete signals.
    
## 8. Moving avarage filter
   - Moving avarage filter algorithm designed in C contating the input and output data files, presented in Matlab .fig file.
   - The window size presented is 10steps and the total samples in the input signal in noisedsquare.c contains 100 samples.
    

## Clone the repository:
bash:

:point_down:
    
    git clone https://github.com/d3ssy23/DSP-in-C.git


