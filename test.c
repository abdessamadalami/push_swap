// #include <stdio.h>
// #define ll long long
// void sortStack(int input[],int size) 
// { 
//   int tmpStack[size];
//   int top=-1;
//   while (size>=0) 
//   { 
//       int tmp = input[size]; 
//       size--; 
//       // while temporary stack is not empty and top 
//       // of stack is greater than temp 
//       while (top>=0 && tmpStack[top] < tmp) 
//       { 
//           // pop from temporary stack and push 
//           // it to the input stack 
//           input[++size]=tmpStack[top]; 
//           top--;
//       } 
//       // push temp in tempory of stack 
//       //
//       // sa sb
      
//       tmpStack[++top]=(tmp);
//   } 
//   while (top>=0) 
//   { 
//       printf("%d ",tmpStack[top]); 
//       top--;
//   } 
// } 

// int main()
// {  
//   int t;
//   scanf("%d",&t);
//   int a[t];
//   int i = 0;
//   int size = t;
//   while(t--)
//   {
//     int n,x;
//     scanf("%d",&n);
//      a[i]= n;
//      i++;
//     }
//   sortStack(a,size); 
//   return 0;
//  }