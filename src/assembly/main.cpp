#include "string_graph.h"

int main(int argc, char* argv[])
{
  int c;
  char* olap_graph = (char*)malloc(sizeof(char)*100);
  char* fasta_read = (char*)malloc(sizeof(char)*100);

  //std::string graph_name = "", path_out = "", gff_name = "";
  while ((c = getopt(argc, argv, "g:r:")) >= 0)
  {
    if (c == 'g'){
        olap_graph = optarg;
    }
    else if(c == 'r') fasta_read = optarg;
    else std::cout<<"ERROR: Check input arguments! \n";
  }

  if(olap_graph == ""){
    std::cout<<"ERROR: Input overlap graph (from SGA) is missing (option -g). See usage options below \n";
  }
  else if(fasta_read == ""){
    std::cout<<"ERROR: Input fasta read (from SGA) is missing (option -g). See usage options below \n";
  }
  else{
  StrGraph* p_g = new StrGraph();
   //p_g->readFGSPredictions(fasta_read, gff_read);
   p_g->readAsqgFile(olap_graph);
   p_g->CondenseGraph();
   p_g->computeLocalComponents();
   p_g->writeGraph(olap_graph);


  delete p_g;
  }
  //free(graph_name);
  return 0;
}
