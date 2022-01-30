#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct bf_t {
	bool bitarray0[2000000];
    bool bitarray1[2000000];
    bool bitarray2[2000000];
    bool bitarray3[2000000];
    bool bitarray4[2000000];
    bool bitarray5[2000000];
    bool bitarray6[2000000];
    bool bitarray7[2000000];

    int x[8];
    int y[8];
    int p[8];
    
    int m;
};

bf_t *create_bf()
{
    struct bf_t* bf = (bf_t*)malloc(sizeof(struct bf_t));
    for (int i=0; i<2000000; i++)
    {
        bf->bitarray0[i]=false;
        bf->bitarray1[i]=false;
        bf->bitarray2[i]=false;
        bf->bitarray3[i]=false;
        bf->bitarray4[i]=false;
        bf->bitarray5[i]=false;
        bf->bitarray6[i]=false;
        bf->bitarray7[i]=false;
    }

    bf->m=2000000;
    for (int i=0; i<8; i++)
    {
        bf->x[i]=1+rand()%bf->m;
        bf->y[i]=rand()%bf->m;
    }
    bf->p[0]=2000003;
    bf->p[1]=5000011;
    bf->p[2]=10000019;
    bf->p[3]=7000003;
    bf->p[4]=14000029;
    bf->p[5]=45000017;
    bf->p[6]=61000001;
    bf->p[7]=2000113;
    
    

    return bf;
}

// hash 0
int universalhashfunction(bf_t *bf, char *s, int a, int b, int p, int c)
{
    ll int hash = b;
    ll int k=0;
    
    for (int i = 0; i < strlen(s); i++)
	{
        k = pow(((int)s[i]),i);
        hash += ((a*(k+128)+b))%p;
        a += c;
        b *= c+i;
        
    }
    
    return abs(hash%bf->m);
}



// loookup operation
int is_element(bf_t *bf, char *q)
{
	int a = universalhashfunction(bf,q, bf->x[0], bf->y[0], bf->p[0],1);
    int b = universalhashfunction(bf,q, bf->x[1], bf->y[1], bf->p[1],2);
    int c = universalhashfunction(bf,q, bf->x[2], bf->y[2], bf->p[2],3);
    int d = universalhashfunction(bf,q, bf->x[3], bf->y[3], bf->p[3],4);
    int e = universalhashfunction(bf,q, bf->x[4], bf->y[4], bf->p[4],5);
    int f = universalhashfunction(bf,q, bf->x[5], bf->y[5], bf->p[5],6);
    int g = universalhashfunction(bf,q, bf->x[6], bf->y[6], bf->p[6],7);
    int h = universalhashfunction(bf,q, bf->x[7], bf->y[7], bf->p[7],8);

	if (bf->bitarray0[a] && bf->bitarray1[b] && bf->bitarray2[c] && bf->bitarray3[d] && bf->bitarray4[e] && bf->bitarray5[f] && bf->bitarray6[g] && bf->bitarray7[h] )
		return 1;
	else
		return 0;
}

// insert operation
void insert_bf(bf_t *bf, char *s)
{

            int a = universalhashfunction(bf,s, bf->x[0], bf->y[0], bf->p[0],1);
            int b = universalhashfunction(bf,s, bf->x[1], bf->y[1], bf->p[1],2);
            int c = universalhashfunction(bf,s, bf->x[2], bf->y[2], bf->p[2],3);
            int d = universalhashfunction(bf,s, bf->x[3], bf->y[3], bf->p[3],4);
            int e = universalhashfunction(bf,s, bf->x[4], bf->y[4], bf->p[4],5);
            int f = universalhashfunction(bf,s, bf->x[5], bf->y[5], bf->p[5],6);
            int g = universalhashfunction(bf,s, bf->x[6], bf->y[6], bf->p[6],7);
            int h = universalhashfunction(bf,s, bf->x[7], bf->y[7], bf->p[7],8);
    
            bf->bitarray0[a] = true;
            bf->bitarray1[b] = true;
            bf->bitarray2[c] = true;
            bf->bitarray3[d] = true;
            bf->bitarray4[e] = true;
            bf->bitarray5[f] = true;
            bf->bitarray6[g] = true;
            bf->bitarray7[h] = true;

		// cout << s << " inserted" << endl;

}

void sample_string_A(char *s, long i)
{  s[0] = (char)(1 + (i%254));
   s[1] = (char)(1 + ((i/254)%254));
   s[2] = (char)(1 + (((i/254)/254)%254));
   s[3] = 'a';
   s[4] = 'b';
   s[5] = (char)(1 + ((i*(i-3)) %217));
   s[6] = (char)(1 + ((17*i+129)%233 ));
   s[7] = '\0';
}
void sample_string_B(char *s, long i)
{  s[0] = (char)(1 + (i%254));
   s[1] = (char)(1 + ((i/254)%254));
   s[2] = (char)(1 + (((i/254)/254)%254));
   s[3] = 'a';
   s[4] = (char)(1 + ((i*(i-3)) %217));
   s[5] = (char)(1 + ((17*i+129)%233 ));
   s[6] = '\0';
}
void sample_string_C(char *s, long i)
{  s[0] = (char)(1 + (i%254));
   s[1] = (char)(1 + ((i/254)%254));
   s[2] = 'a';
   s[3] = (char)(1 + ((i*(i-3)) %217));
   s[4] = (char)(1 + ((17*i+129)%233 ));
   s[5] = '\0';
}
void sample_string_D(char *s, long i)
{  s[0] = (char)(1 + (i%254));
   s[1] = (char)(1 + ((i/254)%254));
   s[2] = (char)(1 + (((i/254)/254)%254));
   s[3] = 'b';
   s[4] = 'b';
   s[5] = (char)(1 + ((i*(i-3)) %217));
   s[6] = (char)(1 + ((17*i+129)%233 ));
   s[7] = '\0';
}
void sample_string_E(char *s, long i)
{  s[0] = (char)(1 + (i%254));
   s[1] = (char)(1 + ((i/254)%254));
   s[2] = (char)(1 + (((i/254)/254)%254));
   s[3] = 'a';
   s[4] = (char)(2 + ((i*(i-3)) %217));
   s[5] = (char)(1 + ((17*i+129)%233 ));
   s[6] = '\0';
}

// Driver Code
int main()
{
    bf_t *b = create_bf();
    long i,j; 
   bf_t * bloom;
   bloom = create_bf();
   printf("Created Filter\n");
   for( i= 0; i< 1450000; i++ )
   {  char s[8];
      sample_string_A(s,i);
      insert_bf( bloom, s );
   }
   for( i= 0; i< 500000; i++ )
   {  char s[7];
      sample_string_B(s,i);
      insert_bf( bloom, s );
   }
   for( i= 0; i< 50000; i++ )
   {  char s[6];
      sample_string_C(s,i);
      insert_bf( bloom, s );
   }
   printf("inserted 2,000,000 strings of length 8,7,6.\n");
   
   for( i= 0; i< 1450000; i++ )
   {  char s[8];
      sample_string_A(s,i);
      if( is_element( bloom, s ) != 1 )
	{  printf("found negative error (1)\n"); exit(0); }
   }
   for( i= 0; i< 500000; i++ )
   {  char s[7];
      sample_string_B(s,i);
      if( is_element( bloom, s ) != 1 )
	{  printf("found negative error (2)\n"); exit(0); }
   }
   for( i= 0; i< 50000; i++ )
   {  char s[6];
      sample_string_C(s,i);
      if( is_element( bloom, s ) != 1 )
	{  printf("found negative error (3)\n"); exit(0); }
   }
   j = 0;
   for( i= 0; i< 500000; i++ )
   {  char s[8];
      sample_string_D(s,i);
      if( is_element( bloom, s ) != 0 )
	j+=1;
   }
   for( i= 0; i< 500000; i++ )
   {  char s[7];
      sample_string_E(s,i);
      if( is_element( bloom, s ) != 0 )
	j+=1;
   }
   printf("Found %d positive errors out of 1,000,000 tests.\n",j);
   printf("Positive error rate %f", (float)j/10000);
}