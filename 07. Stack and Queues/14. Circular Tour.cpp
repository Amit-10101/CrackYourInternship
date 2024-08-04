class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       //Your code here
        int extra = 0;
        int start = 0;
        int lack = 0;
        
        for (int i = 0; i < n; i++) {
           extra += (p[i].petrol - p[i].distance);
           
            if (extra < 0) {
                start = i + 1;
                lack += extra;
                extra = 0;
            } 
        }
        
        if (extra + lack >= 0) return start;
        
        return -1;
    }
};