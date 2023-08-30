let stack={
    stack: [],
    top: 0
};
let paranthesis="{{[[(())]]}}";
let ptr=0;
let len=paranthesis.length;

stack.stack.push('$');
function checkParanthesisBalance(input){
    while(len--){
        if(input.charAt(ptr)=='(' &&( input.charAt(stack.stack[stack.top])=='$' || input.charAt(stack.stack[stack.top])=='(') || input.charAt(stack.stack[stack.top])=='{' || input.charAt(stack.stack[stack.top])=='['){
            stack.stack.push('(');
            ++stack.top;
            ++ptr;
            console.log(stack.stack);
            continue;
        }
        if(input.charAt(ptr)=='{' &&( input.charAt(stack.stack[stack.top])=='$' || input.charAt(stack.stack[stack.top])=='(') || input.charAt(stack.stack[stack.top])=='{' || input.charAt(stack.stack[stack.top])=='['){
            stack.stack.push('{');
            ++stack.top;
            ++ptr;
            console.log(stack.stack);
            continue;
        }
        if(input.charAt(ptr)=='[' &&( input.charAt(stack.stack[stack.top])=='$' || input.charAt(stack.stack[stack.top])=='(') || input.charAt(stack.stack[stack.top])=='{' || input.charAt(stack.stack[stack.top])=='['){
            stack.stack.push('[');
            ++stack.top;
            ++ptr;
            console.log(stack.stack);
            continue;
        }
        if(input.charAt(ptr)==')' && stack.stack[stack.top]=='('){
            stack.stack.pop();
            --stack.top;
            ++ptr;
            console.log(stack.stack);
            continue;
        }
        if(input.charAt(ptr)=='}' && stack.stack[stack.top]=='{'){
            stack.stack.pop();
            --stack.top;
            ++ptr;
            console.log(stack.stack);
            continue;
        }
        if(input.charAt(ptr)==']' && stack.stack[stack.top]=='['){
            stack.stack.pop();
            --stack.top;
            ++ptr;
            console.log(stack.stack);
            continue;
        }
    }
    if(stack.stack[stack.top]=='$'){
        return true;
    }
    else{
        return false;
    }
}

if(checkParanthesisBalance(paranthesis)){
    console.log("Balanced");
}
else{
    console.log("NB");
}
console.log(stack.stack);