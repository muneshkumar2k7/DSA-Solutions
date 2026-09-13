#include <iostream>
using namespace std;

// activity selection or max disjoint interval
vector<pair<int,int>> activity_selection(vector<pair<int,int>> arr , int number_of_pairs){
  vector<pair<int,int>> selected_pair;
  
  // sort by finish time
  for(int i =0 ; i<number_of_pairs-1;i++){
  for(int j = 0; j<number_of_pairs-1-i ; j++){  

     if(arr[j].second > arr[j+1].second){
        swap(arr[j],arr[j+1]);
    }
    }
  }

  
  // take first activity time
  selected_pair.push_back(arr[0]);
  int start =1;
  int finish = 0;
  // check start > finish
  while(start < number_of_pairs){
   
    if(arr[start].first >= arr[finish].second){
        selected_pair.push_back(arr[start]);
        finish = start;
    }

    start++;
  }

  return selected_pair;
}


// Fractional Knapsnack
double Fractional_knap(vector<pair<int,int>> arr,int capacity,int number_of_pairs){
     double val = 0;
    // sorted by ratios
    for(int i = 0;i<number_of_pairs ;i++){
    for(int j=0;j<number_of_pairs-i-1; j++){
        if((float(arr[j].first)/arr[j].second) < (float(arr[j+1].first)/arr[j+1].second)){
            swap(arr[j],arr[j+1]);
        }
    }
    }

    int i = 0;

    while( i < number_of_pairs && capacity >= arr[i].second){
    capacity -= arr[i].second;
    val += arr[i].first;
    i++;
    }

    if(capacity == 0) return val;

    val += arr[i].first * (float(capacity)/arr[i].second);
    return val;
}

struct Node {
    char character;
    int frequency;
    Node * left = Null;
    Node * right = Null;
};

// Huffman coding 
string Find_Unique(string text,int len){
     string unique;
    // find unique
    for(int i=0;i<len;i++){

        bool alreadyFound = false;

        for(int j=0;j<i;j++){
            if(text[i] == text[j]){
                alreadyFound = true;
                break;
            }
        }

        if(!alreadyFound){
          unique += text[i];
        }
    }

    return unique;
}

int count(char letter, string word , int length){
    int num = 0;
    for(int i=0;i<length;i++){
        if(word[i]== letter) num++;
    }

    return num;
}

void sort(Node arr[] , int len){
    for(int i=0;i<len;i++){
        for(int j=0;j<len-i-1;j++){
            if(arr[j].frequency>arr[j+1].frequency){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

void delete_element(Node arr[], Node element , int len){
    for(int i=0;i<len;i++){
        if(arr[i].frequency == element.frequency  && arr[i].character == element.character){
            for(int j = i;j<len-1;j++){
                arr[j] = arr[j+1];
            }
            break;
        }

    } 

}
void insert_at_sorted(Node arr[], Node element , int len){
      int i = len-1;
      while(i>=0 && arr[i].frequency > element.frequency){
        arr[i+1] = arr[i];
        i--;
      }
      arr[i+1] = element; 
}

encoding(string s , int len){
     
    // find unique
    string unique = Find_Unique(s,len);
    currLen = unique.length();
    // find frequencies
    Node Freq_Nodes[currLen];
    
    for(int i=0;i<currLen;i++){
        Freq_Nodes[i].character = unique[i];
        Freq_Nodes[i].frequency = count(unique[i],s,len);
    }
    
    sort(Freq_Nodes , currLen);
    
    
while(currLen > 1) {
   Node newNode;
    
    newNode.left = &Freq_Nodes[0];
    newNode.right = &Freq_Nodes[1];
    newNode.character='\0';
    newNode.frequency = Freq_Nodes[0].frequency + Freq_Nodes[1].frequency;

    delete_element(Freq_Nodes,Freq_Nodes[0],currLen);
    currLen--;
    delete_element(Freq_Nodes,Freq_Nodes[0],currLen);
    currLen--;
    insert_at_sorted(Freq_Nodes , newNode , currLen);
    currLen++;
}
 
    
}



// Job schedule
struct Job{
    int JobID;
    double profit;
    int deadline;
}

void insertion_sorting_desc(Job arr[] , int len){

    for(int i=1;i<len;i++){
        Job temp = arr[i];
        
        int j = i-1;
        while(j >= 0 && arr[j].profit < temp.profit){
         arr[j+1] = arr[j];
         j--;
        }
        arr[j+1] = temp;
    }
}

int max_deadline(Job arr[], int Number_of_jobs){
    int deadline = 0;
    for(int i=0;i<Number_of_jobs;i++){
        if(arr[i].deadline > deadline) deadline = arr[i].deadline;
    }

    return deadline;
}

void JobScheduling(Job Jobs[], int Number_of_jobs , int & profit){

    insertion_sorting_desc(Jobs , Number_of_jobs);
    vector <Job> max_prof_jobs;
   
   
    
    int deadline = max_deadline(Jobs,Number_of_jobs);
    vector<bool> occupied(deadline + 1, false);
     max_prof_jobs.resize(deadline + 1);

    for(int i =0;i<Number_of_jobs;i++){
      int d = Jobs[i].deadline;

      while(d >= 1){

       if(!occupied[d]){
        max_prof_jobs[d] = Jobs[i];
        profit += Jobs[i].profit;
        occupied[d] = true;
        break;
       }else{
        d--;
       }
       
      }
    }
       
    
}
int main(){

}