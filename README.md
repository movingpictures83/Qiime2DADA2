# Qiime2DADA2
# Language: C++
# Input: TXT
# Output: PREFIX
# Tested with: PluMA 1.1, GCC 4.8.4
# Dependency: Qiime 2 2020.11, Conda 4.9.2

Qiime 2 (Bolyan et al, 2019) DADA2 denoiser.

The plugin accepts as input a TXT file of keyword-value pairs:
inputfile: QZA file of paired end sequences
threads: Number of threads
forwardtruncate: Length to truncate forward sequence
reversetruncate: Length to truncate reverse sequence
forwardtrim: Length to trim forward sequence
reversetrim: Length to trim reverse sequence
q: Quality score
chimeramethod: Algorithm to use for chimera removal
forwardmaxee: Maximum expected error (forward sequence)
reversemaxee: Maximum expected error (reverse sequence)
minoverlap: Minimum forward/reverse overlap


The plugin will output three files:
PREFIX-dada.qza
PREFIX-rep-seqs.qza
PREFIX-table.qza

