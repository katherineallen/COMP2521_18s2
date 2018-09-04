// assumes N = 2^k for some integer k > 0
// inFile is the name of the input file
//   - inFile contains sorted sequences of Items of length runLength
// outFile is the name of the output file
//   - outFile will contain sorted sequences of Items of length 2*runLength
// N is the total number of Items

void fileMerge(char* inFile, char* outFile, int runLength, int N)

void fileMerge(FILE* inFile, FILE* outFile, int runLength, int N)



fileMerge(inFile, outFile, runLength, N)
{

   FILE* inf2 = fdopen(inFile, "r");

   int in1 = 0; 
   int in2 = runLength;
   while (in1 < N) {
      int end1 = in1+runLength
      int end2 = in2+runLength
      fseek(inf1, in1, SEEK_SET);
      fread(&it1, sizeof(Item), 1, inf1);
      seek to position in2 in inf2
      it2 = read Item from inf2
      while (in1 < end1 && in2 < end2) {
         if (less(it1,it2)) {
            frwite(&it1, sizeof(Item), 1, outf);
            it1 = read Item from inf1
            in1++
         }
         else {
            write it2 to outf
            it2 = read Item from inf2
            in2++
         }
      }
      while (in1 < end1) {
         write it1 to outf
         it1 = read Item from inf1
         in1++
      }
      while (in2 < end2) {
         write it2 to outf
         it2 = read Item from inf2
         in2++
      }
      in1 += runLength; in2 += runLength
   }
   fclose(inf2);
}