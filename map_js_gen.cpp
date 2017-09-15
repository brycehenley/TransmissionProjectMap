#include <iostream>
using std::cout;
using std::endl;

#include <fstream>
using std::ifstream;

#include <cstring>

const int MAX_CHARS_PER_LINE = 512;
const int MAX_TOKENS_PER_LINE = 64;
const char* const DELIMITER = " ";
using namespace std;

int main(){
  ofstream myfile; //file output
  myfile.open ("markers.js");
  ifstream input; //file reading object
  input.open("input.txt"); //open input file
  // ifstream complete;
  // input.open("complete.txt");

  if (!input.good()){
    return 1; //exit if file is not found
  }
  // if (!complete.good()){
  //   return 1; //exit if file is not found
  // }

  myfile << "var jobmarkers = [ \n\n" << endl;

  while (!input.eof()){ //loop until eof
    // read an entire line into memory
    char buf[MAX_CHARS_PER_LINE];
    input.getline(buf, MAX_CHARS_PER_LINE);

    // parse the line into blank-delimited tokens
    int n = 0; // a for-loop index

    // array to store memory addresses of the tokens in buf
    const char* token[MAX_TOKENS_PER_LINE] = {}; // initialize to 0

    // parse the line
    token[0] = strtok(buf, DELIMITER); // first token
    if (token[0]) // zero if line is blank
    {
      for (n = 1; n < MAX_TOKENS_PER_LINE; n++)
      {
        token[n] = strtok(0, DELIMITER); // subsequent tokens
        if (!token[n]) break; // no more tokens
      }
    }
    // process (print) the tokens
    for (int i = 0; i < n; i++) // n = #of tokens


      //if start
      if (i == 0){
        //init
        myfile << "[\"";
        int j = 1;
        //project name
        while (j < 10 && j < n){
          myfile << token[j] << " ";
          j++;
        }
        //continue array
        myfile << "| Coordinates: \" +' <a href=\"https://insrpteams/sites/sdc/Pages/JobDashboard.aspx?jobnum=";
        myfile << token[i] << "\"> " << token[i] << "</a>',";
        myfile << " " << token[n-1] << ", " << token[n-2];

        //icon
        myfile << ",{icon: ";

        for (int l = 0; l < n; l++){
          if (strcmp("Design", token[l]) == 0){
            myfile << "green";
            l = n;
          }else if (strcmp("Construction", token[l]) ==0){
            myfile << "red";
            l = n;
          }else if (strcmp("Complete", token[l]) == 0){
            myfile << "pink";
            l = n;
          }
          if (l == n-1){
            myfile << "red";
            l = n;
          }
        }

        for (int k = 0; k < n; k++){

          if (strcmp("STARR:", token[k]) == 0){
            myfile << "Star";
            k = n;
          }else if (strcmp("NERC", token[k]) == 0){
            myfile << "Planning";
            k = n;
          }else if (strcmp("Customer", token[k]) == 0){
            myfile << "Customer";
            k = n;
          }else if (strcmp("Maintenance", token[k]) == 0){
            myfile << "Maintenance";
            k = n;
          }else if (strcmp("Improvements", token[k]) == 0 || strcmp("Improvement", token[k]) == 0){
            myfile << "Maintenance";
            k = n;
          }else if (strcmp("Requested", token[k]) == 0){
            myfile << "Customer";
            k = n;
          }else if (strcmp("SM", token[k]) == 0 && strcmp("202", token[k+1]) == 0){
            myfile << "Smf";
            k = n;
          }else if (strcmp("Storm", token[k]) == 0){
            myfile << "Storm";
            k = n;
          }else if (strcmp("storm", token[k]) == 0){
            myfile << "storm";
            k = n;
          }
          if (k == n-1){
            myfile << "Planning";
            k = n;
          }
        }
        myfile << "}],";
        myfile << endl;
      }
  }

  myfile << "]; \n" << endl;
  //jobmarkers array goes here
  //["name | coordinates" + '<a href> link</a>', 0.0, 0.0,{icon: iconType}]
  //file input
  //T# name - kv



  //generates for loop to add markers to map canvas
  myfile << "for (var i = 0; i < jobmarkers.length; i++) {\n";
  myfile << "marker = new L.marker([jobmarkers[i][1],jobmarkers[i][2]],jobmarkers[i][3])\n";
  myfile << ".bindPopup(jobmarkers[i][0])\n";
  myfile << ".addTo(map)\n";
  myfile << "}\n";
  myfile.close();
  return 0;
}
