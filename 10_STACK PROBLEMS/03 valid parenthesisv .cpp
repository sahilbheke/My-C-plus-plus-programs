bool isValidParenthesis(string expression)
{
    // Make an inbuilt stack to store opening brackets .
    stack<char>s;
    for(int i = 0; i<expression.length(); i++){
        char ch = expression[i];
        if(ch=='(' || ch == '{' || ch == '['){
            // Push the element in the stack .
            s.push(ch);
            continue;
        }
        /* 
            If current current character is not opening 
            bracket, then it must be closing. So stack 
            cannot be empty at this point. 
        */
        else{
            
            if(!s.empty()){
                char top = s.top();
                // Check for opening braces in stack of corresponding closing braces and poping opening bracket from s.
                if((ch == ')' && top == '(') || (ch == ']' && top == '[') || (ch == '}' && top == '{')){
                    s.pop();
                }
                else
                    return false;
            }
            else 
                return false;
        }
    }
    //checking stack empty or not .
    if(s.empty()) return true;
    else return false;
}

// problem link -> https://bit.ly/34kxPaq