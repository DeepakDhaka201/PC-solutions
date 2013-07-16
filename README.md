## Live Archive, Spoj and UVA Answers

In what seems like a long-time back, I used to be interested in  programming contests. This folder contains the source-code for my solutions at various Online Judges,

* LA - ACM Live Archive (https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_authorstats&userid=4967)

* Spoj - Sphere Online Judge (http://www.spoj.com/users/gcdart)

* UVA (http://uva.onlinejudge.org/)

Please do not copy-paste solutions into the Online Judge. 

P.S: Some solutions might be incomplete.

### Acknowledgement

At some point, I remember using someonelse's code for fast reading of integers. I dont know who, but here is that piece of code anyway,

        ```c
         #define ITYPE unsigned int
         #define GETCHAR getchar
         #define DIG( a ) ( ( ( a ) >= '0' ) && ( ( a ) <= '9' ) )

         ITYPE GETNUM ( void ){
           int i ;
           ITYPE j ;

           i = GETCHAR () ;
           while ( ! DIG( i ) )  i = GETCHAR () ;

           j = ( i - '0' ) ;

           i = GETCHAR () ;
           while ( DIG( i ) ) {
              j = ( ( j << 1 ) + ( j << 3 ) + ( i - '0' ) ) ;
              i = GETCHAR () ;
           }
           return ( j ) ;
         }
}        ```

