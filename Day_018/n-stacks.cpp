class NStack
{
public:
        int *arr;
        int *top;
        int *next;
    int freespot;
    // Initialize your data structure.
    NStack(int N, int S)
    {
        arr = new int[S];
        top = new int[N];
        next = new int[S];
        freespot = 0;
        
        for(int i =0;i<N;i++)
        {
            top[i] = -1;
        }
        for(int i =0;i<S;i++)
        {
            next[i] = i+1;
        }
        next[S-1] =-1;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        if(freespot == -1)
        {
            return false;
        }
//         store nect freespot in index
        int index = freespot;
//         update freespot
        freespot = next[index];
//         insert element
        arr[index] = x;
//         update next array to store prev element of this array
        next[index] = top[m-1] ;
//          where m is the mth stack andd as we start indexing from zero so m-1
//          update top arr to store top of curr stack
        top[m-1] = index;
         return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        if(top[m-1] == -1)
        {
            return -1;
        }
//         Get the index from top for popping top of mth stack
        int index = top[m-1];
//         update top
        top[m-1] = next[index];
//         update next 
        next[index] = freespot;
//         update freespot
        freespot = index;
//         return popped element
        return arr[index];
        
    }
};