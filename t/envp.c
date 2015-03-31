#include <rt0/syscall.h>

void println( const char* string )
{
   write( 1, string, str_len( string ) );
   write( 1, "\n", 1 );
}

int main( int argc, char** argv, char** envp )
{
   println( "-- Environment --" );

   while( *envp )
   {
      println( *envp );
      envp++;
   }

   println( "-- Environment --" );

   return( 0 );
}

int write( int f, char* d, int l )
{
   int ret = syscall3( SYS_write, f, ( long )( d ), l );

   return( ret );
}

int str_len( const char *string )
{
   int length = 0;
   while( *string ) { string++; length++; }
   return length;
}
