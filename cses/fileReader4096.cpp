#include <bits/stdc++.h>
using namespace std;

#define mxnum 100


class BlockReader { 
   public: 
      // Reads the next 4096 bytes from a file, into the 
      // given buffer. 
      // 
      // Returns the actual number of bytes read. This will 
      // equal 4096 except when it has reached the end-of-file. 
      int Read4096(char* buf) {
         int i = 0, limit = mxnum;
         while(limit -- ) {           
            if ( scanf("%c", buf + i)  == EOF) {
               break;
            }
            i ++;
         }
         return i;
      } 
}; 


class ArbitraryReader { 
private:
   void append(char * buf, char * buffer, int * idx, int res) {
      for (int i = 0; i < res; i ++) {
         buf[(*idx) ++] = buffer[i];
      }
   }

public: 
 // Returns the actual number of bytes read. 
  int Read(char* buf, int bytes_to_read) { // <-- implement this 
    BlockReader br;
    int far_read = 0, idx = 0;
    while(true) {
      char * buffer = (char*) malloc(mxnum);
      int res = br.Read4096(buffer);
      buffer[res] = '\0';
      cout << buffer << endl;
      far_read += res;
      if (far_read <= bytes_to_read) {
         append(buf, buffer, &idx, res);      
      } else {
         far_read -= bytes_to_read;
         res = bytes_to_read - far_read;
         far_read = bytes_to_read;
         append(buf, buffer, &idx, res);   
      }
      free(buffer);
      if (res < mxnum || far_read == bytes_to_read) {
         break;
      }
    }
    return far_read;
  }
};


signed main() {
   freopen("in", "r", stdin);

   while(true) {
   char * buf = (char *) malloc(4096);
   ArbitraryReader ar;
   int answer = ar.Read(buf, 4096);
   cout << answer << endl;
   buf[answer] = '\0';
   cout << buf << endl;

   

   free (buf);
  }
 
   return 0; 
}
