#include <iostream>
#include <vector>
using namespace std;

// (prefix function/LPS)

vector <int> LPS_func(string str){
int n = str.length();

vector <int> lps(n,0);


lps[0]=0;

// ="ABABC"
// str = AB 
//lps[1] =0 Lps[2] =1 lps[3]=2
// len =0 i =2
// len =1  i=3
// len = 2 i =4
// lps[4] = lps[1]= 0;

int len = 0;
int i=1;

while(i < n){
if(str[i] == str[len]){
    len++;
    lps[i] = len;
    i++;
}else{

    if(len!=0){
      len = lps[len-1];
    }else{
        lps[i]=0;
        i++;
    }

}


} 
return lps;   
};


// rabin karp hashing

int hash_func(string str){
int length = str.length();
int ans = 0;
for(int i=0;i<length;i++){
   int num = str[i] - 96;
   ans *= 31;
   ans += num;
};

    return ans;
};


// rabin karp rolling 
int rolling_func(char add,char rem , int length,int hash_cal ){
    int num =1;
    int first= rem -96;
    int last = add - 96;

for(int i=0;i<length-1;i++){
    num *= 31;
} 

 int after_sub = hash_cal - (first * num);
 after_sub *= 31;
 after_sub += last;
  
 return after_sub;
};

//123

int main(){
    string s = "HELLO";


// Forward Traversal  
    for(int i=0;i<s.length();i++){
        cout << s[i] ;
    }


// Backward Traversal
  for(int i=s.length(); i>=0; i--){
    cout << s[i];
  }

// Range-Based Traversal
  for(char c:s){
    cout << c ;
  }

// Index-Based Traversal
for (int i = 0; i < s.size(); i++) {
    cout << "Index " << i << " = " << s[i] << endl;
}


//Conditional Traversal
for (char c : s) {
    if (isupper(c))
        cout << c;
}
cout <<endl;

// Bidirectional or Two pointer  palindrome check 
int l = 0;
int r = s.length()-1;

while (l <r)
{
     if (s[l] != s[r])
        break;

   
    l++;
    r--;
}


int k =2;
for (int i = 0; i <= s.length() - k; i++) {
    cout << s.substr(i, k) << endl;
}


// prefix

for(int i=0;i<s.length();i++){
      cout << s.substr(0, k) << endl;
}

// Prefix Traversal
for(int i=0;i<s.length();i++){
      cout << s.substr(0, i+1) << endl;
}

// Suffix Traversal 
for(int i=0;i<s.length();i++){
      cout << s.substr(i) << endl;
}



// Circular Traversal 
for (int i = 0; i < 10; i++) {
    cout << s[i % s.length()];
}

// Zig Zag Traversal
for (int i = 0; i < s.length(); i += 2)
    cout << s[i];


// Fast and Slow pointer traversal
// Example 1 ; Remove Spaces from a String




cout <<endl;

string str = "a b  c d";

int slow = 0;

for (int fast = 0; fast < s.length(); fast++) {
    if (str[fast] != ' ') {
        str[slow] = str[fast];
        slow++;
    }
}

str.resize(slow);
cout << str;


// Frequency Traversal

int freq[26] = {0};

for (char c : s)
    freq[c - 'a']++;



// Expand Around Center
// Check palindrome odd formula (left == right) ==> length +1/2   and even == length/2 it is for left 

string alpha = "abba";
int centre;
int left;
int right;


if(alpha.length()  %2 ==0 ){
 centre = alpha.length()/2;
  left  = centre - 1 ;
  right = centre;  

}else{
    centre = (alpha.length() -1 ) /2;

     left  = centre;
  right = centre ;  
}
// detect palindrome from string 

while(left >= 0  && right < alpha.length() && alpha[left] == alpha[right] ){
    
    left--;
    right++;
}

left++;
right--;

cout << s.substr(left, right - left + 1);




// Advanced pattern matching problems


// Naive Pattern Matching (understand the problem)
string Text    = "ababcabcabababd";
string Pattern = "ababd";

int n = Text.length();
int m = Pattern.length();


for(int i=0 ;i<=n-m ; i++){
  
    int j= 0;
    
    while(j<m && Pattern[j] == Text[i+j]){
    j++;
    if(j==m){
        cout <<"Found at index = "<<i<<endl;
    }
    
    }
};





// Rabin–Karp (hashing)

int pattern_hash = hash_func(Pattern); 

for(int i=0 ;i<=n-m ; i++){
 
    int win_hash = hash_func(Text.substr(i,m));

    if(win_hash == pattern_hash){
      cout<<"found at index"<< i <<endl;
       break;
    }
    
}

// KMP (Knuth–Morris–Pratt) (prefix function/LPS)
string txt = "ABABDABABC";
string ptn = "ABABC";


vector <int> lps = LPS_func(ptn);

// Checking values by printing 
// for(auto j : lps){
//     cout << j << endl;
// }

int a=0;
int b=0;

while( a< txt.length()){

    if(txt[a] == ptn[b]){
        a++;
        b++;
    }
    
    if(b == ptn.length()){

    cout << "found at index ="<< a - b <<endl;
        b =lps[b-1];

    }else if(a < txt.length() && txt[a] != ptn[b]){
      
        if(b!=0){
        b = lps[b-1];
        }else{
          a++;
        }
    }
}






// Z Algorithm (Z-array)

    return 0;
}