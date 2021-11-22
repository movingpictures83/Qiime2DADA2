#ifndef QIIME2DADA2PLUGIN_H
#define QIIME2DADA2PLUGIN_H

#include "Plugin.h"
#include "PluginProxy.h"
#include <string>
#include <vector>

class Qiime2DADA2Plugin : public Plugin
{
public: 
 std::string toString() {return "Qiime2DADA2";}
 void input(std::string file);
 void run();
 void output(std::string file);

private: 
 std::string inputfile;
 std::string outputfile;
 std::map<std::string, std::string> parameters;

};

#endif
