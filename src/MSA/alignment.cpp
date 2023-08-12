#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <boost/graph/adjacency_matrix.hpp>


using namespace std;

void process_file(unordered_map<string, string> &seq_map)
{
    string filename;
    ifstream myinputfile;
    cout << "Enter filename: " << endl;
    cin >> filename;

    // initilizations
    string line;
    string delim = ">";

    myinputfile.open(filename);
    
    if (myinputfile.is_open())
    {
    	while (myinputfile)
	    {
            myinputfile >> line;
            if (line.rfind(delim) == 0)
            {
                string seq;
                myinputfile >> seq;
                line.erase(0, 1);
                seq_map[line] = seq;
            }
	    }
    }
    
    cout << "closing file" << endl;
    myinputfile.close();

    // printing the sequences
    // int index = 0;
    // for (auto const& i : seqlst)
    // {	        
    //     cout << index << ". " << i << endl;;
    //     index++;
    // }
}


int score_pair(string key1, string key2, unordered_map<string, string> seq_map)
{
    string seq1 = seq_map[key1];
    string seq2 = seq_map[key2];

    int i = 0;
    int seq_score = 0;
    while (i < seq1.length() && i < seq2.length())
    {
        seq_score += scoring_matrix(seq1[i], seq2[i]);
        i++; // increment i so the loop actually terminates lol
    }

    // cout << score << endl;
    return (seq_score);
}

// add similarity matrix to this function
// the idea is to have this function encapsulate producing positional scores
int scoring_matrix(char A, char B)
{
    // current, very basic similiarity matrix
    if (A == B) // if the aligned parts match
    { 
        if (A = '-') { return 0; } // in the case that two gaps are alligned, the score should not be affected
        return 1;  // increment score by 1 if the characters match
    }  
    else  // in the case of an indel
    {
        return -1; // decrement the score by 1
    }
}

// void pairwise_alignment(string seq1, string seq2)
// {
//     typedef boost::adjacency_matrix<boost::undirectedS> Graph;
    
//     const char N;
//     Graph(N)
//     for (char& a: seq1)
//     {
//         for (char& b: seq2)
//         {

//         }
//     }
// }

int main()
{
    // vector<string> seqlst;


    // unordered_map<string, string> seq_map;
    
    // process_file(seq_map);

    // for (auto& x: seq_map) {
    // cout << x.first << ": " << x.second << std::endl;
    // }

    cout << __cplusplus << endl;

    return 0;
}
