#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "Qiime2DADA2Plugin.h"

void Qiime2DADA2Plugin::input(std::string file) {
 inputfile = file;
 std::ifstream ifile(inputfile.c_str(), std::ios::in);
 while (!ifile.eof()) {
   std::string key, value;
   ifile >> key;
   ifile >> value;
   parameters[key] = value;
 }
}

void Qiime2DADA2Plugin::run() {

}

void Qiime2DADA2Plugin::output(std::string file) {
   std::string command = "export OLDPATH=${PATH}; ";
   command += "export PATH=${CONDA_HOME}/bin/:${PATH}; ";
   command += "eval \"$(conda shell.bash hook)\"; ";
   command += "conda activate qiime2-2021.4; ";
   command += "qiime dada2 denoise-paired --i-demultiplexed-seqs "+std::string(PluginManager::prefix())+"/"+parameters["inputfile"];
   if (parameters.count("threads") != 0)
	   command += " --p-n-threads "+parameters["threads"];
   if (parameters.count("forwardtruncate") != 0)
	   command += " --p-trunc-len-f "+parameters["forwardtruncate"];
   if (parameters.count("reversetruncate") != 0)
	   command += " --p-trunc-len-r "+parameters["reversetruncate"];
   if (parameters.count("forwardtrim") != 0)
	   command += " --p-trim-left-f "+parameters["forwardtrim"];
   if (parameters.count("reversetrim") != 0)
	   command += " --p-trim-left-r "+parameters["reversetrim"];
   if (parameters.count("q") != 0)
	   command += " --p-trunc-q "+parameters["q"];
   if (parameters.count("chimeramethod") != 0)
	   command += " --p-chimera-method "+parameters["chimeramethod"];
   if (parameters.count("forwardmaxee") != 0)
	   command += " --p-max-ee-f "+parameters["forwardmaxee"];
   if (parameters.count("reversemaxee") != 0)
	   command += " --p-max-ee-r "+parameters["reversemaxee"];
   if (parameters.count("minoverlap") != 0)
	   command += " --p-min-overlap "+parameters["minoverlap"];

   command += " --o-representative-sequences "+file+"-rep-seqs.qza --o-table "+file+"-table.qza --o-denoising-stats "+file+"-denoising-stats-dada.qza; ";
   command += "conda deactivate; ";
   command += "conda deactivate; ";
   command += "export PATH=${OLDPATH}";
 std::cout << command << std::endl;

 system(command.c_str());
}

PluginProxy<Qiime2DADA2Plugin> Qiime2DADA2PluginProxy = PluginProxy<Qiime2DADA2Plugin>("Qiime2DADA2", PluginManager::getInstance());
