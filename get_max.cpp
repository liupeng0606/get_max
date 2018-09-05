#include <iostream>
 using namespace std ; 
 const int x = 6 ;                             //cpu数目 
 const int y = 8 ;                             //内存数目 
 const int T = 5 ;                             //报价条数 
 
 int f[x+1][y+1] ;                       //定义二位数组，避免重复计算                                 
 int w[T] = {300,500,800,200,600};                       
 int a[T] = {1 , 2 , 4 , 2 , 3};            
 int b[T] = {2 , 3 , 5 , 1 , 4};
 int INF = -66536  ;
   
 int get_max()
 {
    for(int i = 1 ; i <= x ;i++) 
      for(int j = 1 ; j <= y ;j++)
      f[i][j] = INF ;    
      
      f[0][0] = 0 ; 
    
    for(int i = 0 ; i < T ; i++)
    {
      for(int u = x ; u >= a[i] ;u--) 
         {         
           for(int v = y ; v >= b[i] ;v--)                           
              f[u][v] = max(f[u-a[i]][v-b[i]] + w[i] , f[u][v])  ;
         }                 
    }
    return f[x][y] ;        
 }
 
 int main()
 {
      
   int temp = get_max() ;   
   cout<<temp<<endl     ;   
   return 0 ;    
 }
