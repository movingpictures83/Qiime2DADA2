#!/usr/bin/env bash

if [ ! -f Miniconda3-latest-Linux-x86_64.sh ]; then
    curl -sSLO  https://repo.anaconda.com/miniconda/Miniconda3-latest-Linux-x86_64.sh
fi

sudo bash ./Miniconda3-latest-Linux-x86_64.sh -b -u -p /usr/local/share/miniconda

sudo ln -sf /usr/local/share/miniconda/bin/conda /usr/local/bin/miniconda

if [ ! -f qiime2-2021.11-py38-linux-conda.yml ]; then
    curl -sSLO https://data.qiime2.org/distro/core/qiime2-2021.11-py38-linux-conda.yml
fi

conda env create -n qiime2-2021.11 --file qiime2-2021.11-py38-linux-conda.yml