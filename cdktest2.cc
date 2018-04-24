// William Truong wxt160130
#include <iostream>
#include "cdk.h"
#include<iomanip>
#include<fstream>
#include<stdint.h> 
#include<sstream>
#include<string>
#include<string.h> 

#define MATRIX_WIDTH 3
#define MATRIX_HEIGHT 5
#define BOX_WIDTH 20
#define MATRIX_NAME_STRING "Test Matrix"

using namespace std;

class BinaryFileHeader
{
public: 
  uint32_t magicNumber ; 
  uint32_t versionNumber ; 
  uint64_t numRecords ; 

} ;

const int maxRecordStringLength = 25 ; 

class BinaryFileRecord{

public: 
  uint8_t strLength ; 
  char stringBuffer[maxRecordStringLength] ;

  uint8_t strLength2 ;
  char stringBuffer2[maxRecordStringLength] ; 

  uint8_t strLength3 ; 
  char stringBuffer3[maxRecordStringLength] ; 

  uint8_t strLength4 ; 
  char stringBuffer4[maxRecordStringLength] ;

} ;



int main()
{
   
  
  WINDOW    *window;
  CDKSCREEN  *cdkscreen;
  CDKMATRIX  *myMatrix;           // CDK Screen Matrix

  const char *rowTitles[] = {"R0", "R1", "R2", "R3","R4","R5"};
  const char *columnTitles[] = {"C0", "C1", "C2", "C3","C4","C5"};
  int boxWidths[] = {BOX_WIDTH, BOX_WIDTH, BOX_WIDTH, BOX_WIDTH,BOX_WIDTH,BOX_WIDTH};
  int boxTypes[] = {vMIXED, vMIXED, vMIXED, vMIXED,vMIXED,vMIXED,vMIXED};

  /*
   * Initialize the Cdk screen.
   *
   * Make sure the putty terminal is large enough
   */
  window = initscr();
  cdkscreen = initCDKScreen(window);

  /* Start CDK Colors */
  initCDKColor();

  /*
   * Create the matrix.  Need to manually cast (const char**) to (char **)
   */
  myMatrix = newCDKMatrix(cdkscreen, CENTER, CENTER, MATRIX_HEIGHT,MATRIX_WIDTH, MATRIX_HEIGHT, MATRIX_WIDTH, MATRIX_NAME_STRING, (char **) rowTitles, (char **) columnTitles, boxWidths,
			  boxTypes, 1, 1, ' ', ROW, true, true, false);

  if (myMatrix ==NULL)
    {
      printf("Error creating Matrix\n");
      _exit(1);
    }

  /* Display the Matrix */
  drawCDKMatrix(myMatrix, true);

  /*
   * Dipslay a message
   */
  // setCDKMatrixCell(myMatrix, 2, 2, "Test Message");

  BinaryFileHeader *myHeader = new BinaryFileHeader() ; 
  
  BinaryFileRecord *myRecord = new BinaryFileRecord() ; // new records 

  ifstream binInFile("cs3377.bin",ios::in|ios::binary) ; // open binary file 

  // binInFile.read((char *)myRecord,sizeof(BinaryFileRecord)) ; // reading in of the record 

  binInFile.read((char *)myHeader,sizeof(BinaryFileHeader)) ; // read iint he records
  binInFile.read((char *)myRecord,sizeof(BinaryFileRecord)) ;  
  // setCDKMatrixCell(myMatrix,1,1,myHeader->magicNumber) ;
  // setCDKMatrixCell(myMatrix,1,2,myHeader->versionNumber);
  // setCDKMatrixCell(myMatrix,1,3,myHeader->numRecords) ;

  stringstream ss ; 

  ss << "Magic: 0x " << std::hex << myHeader->magicNumber ;  
  
  string s1 = ss.str() ; 

  const char *ch= s1.c_str() ;
  setCDKMatrixCell(myMatrix,1,1,ch) ; 
  
  ss.str("") ; 
  // cout << " Version Number " << s1 << endl ; 
  
  ss <<"Version Number:" << myHeader->versionNumber ;

  string s2 = ss.str() ;

  const char *ch2 = s2.c_str() ;

  setCDKMatrixCell(myMatrix,1,2,ch2) ; 

  ss.str("") ;
  
  ss <<" Num Records " << hex <<  myHeader->numRecords ; 

  string s3 = ss.str() ; 

  const char* ch3 = s3.c_str() ; 

  setCDKMatrixCell(myMatrix,1,3,ch3) ; 

  // setCDKMatrixCell(myMatrix,1,1,ch) ;
  // setCDKMatrixCell(myMatrix,1,2,ch2) ; 
  //setCDKMatrixCell(myMatrix,1,3,ch3) 

  stringstream ss2 ;
  
  ss2 << myRecord->stringBuffer ;

  string str2 = ss2.str() ; 

  const char* buf2 = str2.c_str() ; 

  setCDKMatrixCell(myMatrix,2,2,buf2) ;

  int size1 = strlen(buf2) ; 

  ss2.str("") ;

   ss2<< "strlen : " << size1 ; 

  string sizeStr1 = ss2.str() ; 

  const char *strbuf1 = sizeStr1.c_str() ; 

  setCDKMatrixCell(myMatrix,2,1,strbuf1) ; 

  ss2.str("") ; 


  ss2 << myRecord->stringBuffer2 ; 
  
  string str3 = ss2.str() ; 

  const char *buf3 = str3.c_str() ; 

  setCDKMatrixCell(myMatrix,3,2,buf3) ;
  
  int size2 = strlen(buf3) ; 

  ss2.str("") ; 

   ss2 << "strlen :" << size2 ; 

  string sizeStr2 = ss2.str() ; 

  const char *sizebuf2 = sizeStr2.c_str() ; 

  setCDKMatrixCell(myMatrix,3,1,sizebuf2) ; 

  ss2.str("") ; 

  ss2 << myRecord-> stringBuffer3 ; 

  string s5 = ss2.str() ; 

  const char *buf5 = s5.c_str() ; 

  int strlen3 = strlen(buf5) ; 

  setCDKMatrixCell(myMatrix,4,2,buf5) ; 

  ss2.str("") ;

  ss2 <<"str len: "<< strlen3 ; 
 
  string s6 = ss2.str() ; 

  const char *buf6 = s6.c_str() ; 

  setCDKMatrixCell(myMatrix,4,1,buf6) ; 

  ss2.str("")  ;

  ss2 << myRecord-> stringBuffer4 ;

  string str4 = ss2.str() ; 

  const char *bufferfin = str4.c_str() ; 

  int size4 = strlen(bufferfin) ; 

  setCDKMatrixCell(myMatrix,5,2,bufferfin) ; 

  ss2.str("") ;

  ss2 << "str len : " << size4 ; 

  string sizeStr4 = ss2.str() ; 

  const char *bufSize4 = sizeStr4.c_str() ; 

  setCDKMatrixCell(myMatrix,5,1,bufSize4) ; 

  ss2.str(""); 
 
  // ss.setf(std::ios_base::hex, std::ios_base::basefield) ;
  
  // s1 = ss ; 

  drawCDKMatrix(myMatrix, true);    /* required  */
  
  unsigned char x ; 

  cin >> x ; 
  // Cleanup screen
  binInFile.close() ; 
  endCDK();
}
