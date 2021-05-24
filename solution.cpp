long minimumPasses(long m, long w, long p, long n) {
long max_days= (n/m/w)+1;
long day = 0;
//cout<<max_days;
long double candies = 0;
//cout<<ceil(1.5)<<endl;
while(day<max_days){
        long double stpass = ceil((p-candies)/(m*w));
        day+=stpass;
        candies += m*w*stpass;
        
        if(floor(candies/p)>abs(m-w)){
            candies -= abs(m-w)*p;
            m>w?w=m:m=w;
            long invest = floor(candies/p);
            if(invest%2==0){
                m=w=m+(invest/2);
            }
            else{
                m=w=m+(invest/2);
                m++;
            }
            candies-=invest*p;
        }
        else{
            long invest = floor(candies/p);
            if(m<w){
                m+=invest;
            }
            else{
                w+=invest;
            }
            candies-=invest*p;
        }
        long double minpass = ceil(ceil((n-candies)/m)/w);
        if(max_days>day+minpass){
            max_days = day+minpass;
        }
        cout<<max_days<<" "<<endl; 
}
return max_days;
}
