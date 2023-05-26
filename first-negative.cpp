// https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

vector<long long> printFirstNegativeInteger(long long int a[],long long int n, long long int k) 
{
    long long int i=0,j=-1,neg=0;
    vector<long long> v;
    queue<long long> q;
    
    while(j<n)
    {
        while(j-i+1<k)
        {
            j++;
            if(a[j]<0) 
            {
                q.push(a[j]);
                if(neg==0) 
                {
                    neg=a[j];
                    v.push_back(neg);
                }
            }
            
        }
        
        if(j-i+1==k)
        {
            i++;
            j++;
            if(a[i-1]<0 and q.front()==a[i-1])
            {
                q.pop();
                neg=0;
                
            }
            
            if(a[i]<0) q.push(a[i]);
            if(a[j]<0) q.push(a[j]);
            
            if(neg==0) 
            {
                if(!q.empty()) 
                {
                    neg=q.front();
                    v.push_back(neg);
                }
                else v.push_back(0);
            }
        }
    }
    
    return v;
}
