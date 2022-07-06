Class Solution{
    public:

		//sahil's code by using map
		string FirstNonRepeating(string A){

			//creating map to count char of a string
		    unordered_map<char,int> count;

			//creatinh queue
		    queue<int> q;

			// sting to store final answer
		    string ans = "";
		    
			// iterating over string
		    for(int i=0; i<A.length(); i++){

		        char ch = A[i];
		        count[ch]++;
		        q.push(ch);

		        while(!q.empty())
		        {
					//if element is repeatinh
		            if(count[q.front()]>1)
		                q.pop();
		               
		            else{
						//else element is non repeating 
		                ans.push_back(q.front());
		                break;
		            }
		        }
		      
			  //if queue is empty
		      if(q.empty())
		        ans.push_back('#');
		    
		    }
		    
		    return ans;
		}
};

// link of the problem -> https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1#




/***********************************************************/

//Aleternate solution by AUTHOR by using array

class Solution {
	public:
		string FirstNonRepeating(string A){
		    int n = A.size();
		    vector<int>f(26, 0);
		    vector<int>last(26, -1);
		    for(int i = 0; i < A.size(); i++){
		        if(last[A[i] - 'a'] == -1)
		            last[A[i] - 'a'] = i;
		    }
		    string ans="";
		    for(int i = 0; i < A.size(); i++){
		        f[A[i] - 'a']++;
		        char ch = '#';
		        int x = A.size() + 1;
		        for(int j = 0; j < 26; j++){
		            if(f[j] == 1 and x > last[j]){
		                ch = char(j + 'a');
		                x = last[j];
		            }
		        }
		        ans += ch;
		    }
		    return ans;
		}

};
